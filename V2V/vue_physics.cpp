/*
* =====================================================================================
*
*       Filename:  vue_physics.cpp
*
*    Description:  车辆类的物理层部分实现
*
*        Version:  1.0
*        Created:
*       Revision:
*       Compiler:  VS_2015
*
*         Author:  HCF
*            LIB:  ITTC
*
* =====================================================================================
*/

#include"vue.h"
#include"vue_physics.h"
#include"context.h"
#include"gtt.h"
#include"IMTA.h"
#include"function.h"

using namespace std;

int vue_physics::s_vue_count = 0;


std::vector<std::vector<double*>> vue_physics::s_channel_all(0);
std::vector<std::vector<double>> vue_physics::s_pl_all(0);

double* vue_physics::get_channel(int i, int j) {
	if (i < j) {
		return s_channel_all[i][j];
	}
	else {
		return s_channel_all[j][i];
	}
}

double vue_physics::get_pl(int i, int j) {
	if (i < j) {
		return s_pl_all[i][j];
	}
	else {
		return s_pl_all[j][i];
	}
}

void vue_physics::set_channel(int i, int j, double* t_channel) {
	if (i < j) {
		memory_clean::safe_delete(s_channel_all[i][j], true);
		s_channel_all[i][j] = t_channel;
	}
	else {
		memory_clean::safe_delete(s_channel_all[j][i], true);
		s_channel_all[j][i] = t_channel;
	}
}

void vue_physics::set_pl(int i, int j, double t_pl) {
	if (i < j) {
		s_pl_all[i][j] = t_pl;
	}
	else {
		s_pl_all[j][i] = t_pl;
	}
}


vue_physics::vue_physics() {

}


vue_physics::~vue_physics() {
	
}


void vue_physics::update_location() {
	auto p = context::get_context()->get_gtt();
	if (m_vangle == 0)
	{
		if ((m_absx + p->get_freshtime()*m_speed)>(p->get_road_length() / 2))
		{
			m_absx = (m_absx + p->get_freshtime()*m_speed) - p->get_road_length();
			m_relx = m_absx;
		}
		else
		{
			m_absx = m_absx + p->get_freshtime()*m_speed;
			m_relx = m_absx;
		}
	}
	else
	{
		if ((m_absx - p->get_freshtime()*m_speed)<(-p->get_road_length() / 2))
		{
			m_absx = m_absx - p->get_freshtime()*m_speed + p->get_road_length();
			m_relx = m_absx;
		}
		else
		{
			m_absx = m_absx - p->get_freshtime()*m_speed;
			m_relx = m_absx;
		}
	}
}

void vue_physics::channel_generator() {
	Location location;
	location.eNBAntH = 5;
	location.VeUEAntH = 1.5;
	location.RSUAntH = 5;
	location.locationType = None;
	location.distance = 0;
	location.distance1 = 0;
	location.distance2 = 0;

	Antenna antenna;
	antenna.antGain = 3;
	antenna.byTxAntNum = 1;
	antenna.byRxAntNum = 2;

	IMTA* imta = new IMTA[s_vue_count*(s_vue_count-1)/2];
	int imtaId = 0;
	for (int vueIdi = 0; vueIdi < s_vue_count; vueIdi++) {
		for (int vueIdj = vueIdi + 1; vueIdj < s_vue_count; vueIdj++) {
			auto vuei = context::get_context()->get_vue_array()[vueIdi].get_physics_level();
			auto vuej = context::get_context()->get_vue_array()[vueIdj].get_physics_level();

			location.locationType = Los;
			location.manhattan = false;

			double angle = 0;

			location.distance = sqrt(pow((vuei->m_absx - vuej->m_absx), 2.0f) + pow((vuei->m_absy - vuej->m_absy), 2.0f));

			angle = atan2(vuei->m_absy - vuej->m_absy, vuei->m_absx - vuej->m_absx) / IMTA::s_DEGREE_TO_PI;

			IMTA::randomGaussian(location.posCor, 5, 0.0f, 1.0f);//产生高斯随机数，为后面信道系数使用

			double m_FantennaAnglei;
			double m_FantennaAnglej;

			IMTA::randomUniform(&m_FantennaAnglei, 1, 180.0f, -180.0f, false);
			IMTA::randomUniform(&m_FantennaAnglej, 1, 180.0f, -180.0f, false);

			antenna.TxAngle = angle - m_FantennaAnglei;
			antenna.RxAngle = angle - m_FantennaAnglej;
			antenna.TxSlantAngle = new double[antenna.byTxAntNum];
			antenna.TxAntSpacing = new double[antenna.byTxAntNum];
			antenna.RxSlantAngle = new double[antenna.byRxAntNum];
			antenna.RxAntSpacing = new double[antenna.byRxAntNum];
			antenna.TxSlantAngle[0] = 90.0f;
			antenna.TxAntSpacing[0] = 0.0f;
			antenna.RxSlantAngle[0] = 90.0f;
			antenna.RxSlantAngle[1] = 90.0f;
			antenna.RxAntSpacing[0] = 0.0f;
			antenna.RxAntSpacing[1] = 0.5f;

			double t_Pl = 0;

			imta[imtaId].build(&t_Pl, IMTA::s_FC, location, antenna, vuei->m_speed, vuej->m_speed,vuei->m_vangle,vuej->m_vangle);//计算了结果代入信道模型计算UE之间信道系数

			set_pl(vueIdi,vueIdj,t_Pl);

			bool *flag = new bool();
			*flag = true;
			imta[imtaId].enable(flag);

			double *H = new double[1 * 2 * 19 * 2];
			double *FFT = new double[1 * 2 * 1024 * 2];
			double *ch_buffer = new double[1 * 2 * 19 * 20];
			double *ch_sin = new double[1 * 2 * 19 * 20];
			double *ch_cos = new double[1 * 2 * 19 * 20];

			double *t_HAfterFFT = new double[2 * 1024 * 2];

			imta[imtaId].calculate(t_HAfterFFT, 0.01f, ch_buffer, ch_sin, ch_cos, H, FFT);
			set_channel(vueIdi, vueIdj, t_HAfterFFT);

			memory_clean::safe_delete(flag);
			memory_clean::safe_delete(H, true);
			memory_clean::safe_delete(ch_buffer, true);
			memory_clean::safe_delete(ch_sin, true);
			memory_clean::safe_delete(ch_cos, true);
			memory_clean::safe_delete(antenna.TxSlantAngle, true);
			memory_clean::safe_delete(antenna.TxAntSpacing, true);
			memory_clean::safe_delete(antenna.RxSlantAngle, true);
			memory_clean::safe_delete(antenna.RxAntSpacing, true);
			memory_clean::safe_delete(FFT, true);
		}
	}
	memory_clean::safe_delete(imta, true);
}