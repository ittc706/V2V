/*
* =====================================================================================
*
*       Filename:  gtt_urban.cpp
*
*    Description:  ������ʵ��
*
*        Version:  1.0
*        Created:
*       Revision:
*       Compiler:  VS_2015
*
*         Author:  WYB
*            LIB:  ITTC
*
* =====================================================================================
*/

#include<fstream>
#include<utility>
#include<random>
#include"context.h"
#include"config.h"
#include"gtt_urban.h"
#include"vue.h"
#include"vue_physics.h"
#include"imta.h"
#include"function.h"
#include<memory.h>


using namespace std;

void gtt_urban::initialize() {
	gtt_urban_config* __config = get_precise_config();
	int* m_pupr = new int[__config->get_road_num()];//ÿ��·�ϵĳ�����
	
	int tempVeUENum = 0;
	int Lambda = static_cast<int>((__config->get_road_length_ew() + __config->get_road_length_sn()) * 2 * 3.6 / (2.5 * __config->get_speed()));
	for (int temp = 0; temp != __config->get_road_num(); ++temp)
	{
		int k = 0;
		long double p = 1.0;
		long double l = exp(-Lambda);  /* Ϊ�˾��ȣ��Ŷ���Ϊlong double�ģ�exp(-Lambda)�ǽӽ�0��С��*/
		while (p >= l)
		{
			double u = (double)(rand() % 10000)*0.0001f;
			p *= u;
			k++;
		}
		m_pupr[temp] = k - 1;
		tempVeUENum = tempVeUENum + k - 1;
	}

	//���г���������
	context::get_context()->set_vue_array(new vue[tempVeUENum]);
	cout << "vuenum: " << tempVeUENum << endl;

	int vue_id = 0;
	double DistanceFromBottomLeft = 0;

	ofstream vue_coordinate;

	vue_coordinate.open("log/vue_coordinate.txt");

	default_random_engine e(0);
	uniform_real_distribution<double> u(0, 2 * (__config->get_road_length_ew() + __config->get_road_length_sn()));

	for (int RoadIdx = 0; RoadIdx != __config->get_road_num(); RoadIdx++) {
		for (int uprIdx = 0; uprIdx != m_pupr[RoadIdx]; uprIdx++) {
			auto p = context::get_context()->get_vue_array()[vue_id++].get_physics_level();
			DistanceFromBottomLeft = u(e);
			if (DistanceFromBottomLeft <= __config->get_road_length_ew()) {
				p->m_relx = -(__config->get_road_length_sn() + __config->get_road_width()) / 2;
				p->m_rely = DistanceFromBottomLeft - __config->get_road_length_ew() / 2;
				p->m_vangle = 90;
			}
			else if (DistanceFromBottomLeft > __config->get_road_length_ew() && DistanceFromBottomLeft <= (__config->get_road_length_ew() + __config->get_road_length_sn())) {
				p->m_relx = DistanceFromBottomLeft - __config->get_road_length_ew() - __config->get_road_length_sn() / 2;
				p->m_rely = (__config->get_road_length_ew() + __config->get_road_width()) / 2;
				p->m_vangle = 0;
			}
			else if (DistanceFromBottomLeft > (__config->get_road_length_ew() + __config->get_road_length_sn()) && DistanceFromBottomLeft < (__config->get_road_length_ew() * 2 + __config->get_road_length_sn())) {
				p->m_relx = (__config->get_road_length_sn() + __config->get_road_width()) / 2;
				p->m_rely = __config->get_road_length_ew() / 2 - (DistanceFromBottomLeft - (__config->get_road_length_ew() + __config->get_road_length_sn()));
				p->m_vangle = -90;
			}
			else {
				p->m_relx = __config->get_road_length_sn() / 2 - (DistanceFromBottomLeft - (__config->get_road_length_ew() * 2 + __config->get_road_length_sn()));
				p->m_rely = -(__config->get_road_length_ew() + __config->get_road_width()) / 2;
				p->m_vangle = -180;
			}
			p->m_road_id = RoadIdx;
			p->m_absx = __config->get_road_topo_ratio()[RoadIdx * 2 + 0] * (__config->get_road_length_sn() + 2 * __config->get_road_width()) + p->m_relx;
			p->m_absy = __config->get_road_topo_ratio()[RoadIdx * 2 + 1] * (__config->get_road_length_ew() + 2 * __config->get_road_width()) + p->m_rely;
			p->m_speed = __config->get_speed()/3.6;
			//�����������������txt�ļ�
			vue_coordinate << p->m_absx << " ";
			vue_coordinate << p->m_absy << " ";
			vue_coordinate << endl;

			//��ʼ��patternռ�����������ȫΪfalse����δ��ռ��״̬
			p->m_pattern_occupied = new bool[context::get_context()->get_rrm_config()->get_pattern_num()];
			memset(p->m_pattern_occupied, false, sizeof(p->m_pattern_occupied));
		}
	}
	memory_clean::safe_delete(m_pupr, true);

	vue_coordinate.close();

	vue_physics::s_pl_all.assign(get_vue_num(), std::vector<double>(get_vue_num(), 0));
	vue_physics::s_distance_all.assign(get_vue_num(), std::vector<double>(get_vue_num(), 0));


	double x_unit = __config->get_road_length_sn() / 2 + __config->get_road_width();
	double y_unit = __config->get_road_length_ew() / 2 + __config->get_road_width();
	// ��һ��
	m_crossroads[0][0] = -4 * x_unit;
	m_crossroads[0][1] = 3 * y_unit;

	m_crossroads[1][0] = -2 * x_unit;
	m_crossroads[1][1] = 3 * y_unit;

	m_crossroads[2][0] = 0 * x_unit;
	m_crossroads[2][1] = 3 * y_unit;

	m_crossroads[3][0] = 2 * x_unit;
	m_crossroads[3][1] = 3 * y_unit;

	m_crossroads[4][0] = 4 * x_unit;
	m_crossroads[4][1] = 3 * y_unit;

	// �ڶ���

	m_crossroads[5][0] = -6 * x_unit;
	m_crossroads[5][1] = 1 * y_unit;

	m_crossroads[6][0] = -4 * x_unit;
	m_crossroads[6][1] = 1 * y_unit;

	m_crossroads[7][0] = -2 * x_unit;
	m_crossroads[7][1] = 1 * y_unit;

	m_crossroads[8][0] = 0 * x_unit;
	m_crossroads[8][1] = 1 * y_unit;

	m_crossroads[9][0] = 2 * x_unit;
	m_crossroads[9][1] = 1 * y_unit;

	m_crossroads[10][0] = 4 * x_unit;
	m_crossroads[10][1] = 1 * y_unit;

	m_crossroads[11][0] = 6 * x_unit;
	m_crossroads[11][1] = 1 * y_unit;

	// ������

	m_crossroads[12][0] = -6 * x_unit;
	m_crossroads[12][1] = -1 * y_unit;

	m_crossroads[13][0] = -4 * x_unit;
	m_crossroads[13][1] = -1 * y_unit;

	m_crossroads[14][0] = -2 * x_unit;
	m_crossroads[14][1] = -1 * y_unit;

	m_crossroads[15][0] = 0 * x_unit;
	m_crossroads[15][1] = -1 * y_unit;

	m_crossroads[16][0] = 2 * x_unit;
	m_crossroads[16][1] = -1 * y_unit;

	m_crossroads[17][0] = 4 * x_unit;
	m_crossroads[17][1] = -1 * y_unit;

	m_crossroads[18][0] = 6 * x_unit;
	m_crossroads[18][1] = -1 * y_unit;

	// ������

	m_crossroads[19][0] = -4 * x_unit;
	m_crossroads[19][1] = -3 * y_unit;

	m_crossroads[20][0] = -2 * x_unit;
	m_crossroads[20][1] = -3 * y_unit;

	m_crossroads[21][0] = 0 * x_unit;
	m_crossroads[21][1] = -3 * y_unit;

	m_crossroads[22][0] = 2 * x_unit;
	m_crossroads[22][1] = -3 * y_unit;

	m_crossroads[23][0] = 4 * x_unit;
	m_crossroads[23][1] = -3 * y_unit;

	for (int i = 0; i < 24; i++) {
		center_coordinate << m_crossroads[i][0] << " " << m_crossroads[i][1] << endl;
	}

	double road_width = __config->get_road_width();

	m_buildings[0][0][0] = m_crossroads[0][0] + road_width;
	m_buildings[0][0][1] = m_crossroads[0][1] - road_width;
	m_buildings[0][1][0] = m_crossroads[1][0] - road_width;
	m_buildings[0][1][1] = m_crossroads[1][1] - road_width;

	m_buildings[1][0][0] = m_crossroads[1][0] + road_width;
	m_buildings[1][0][1] = m_crossroads[1][1] - road_width;
	m_buildings[1][1][0] = m_crossroads[2][0] - road_width;
	m_buildings[1][1][1] = m_crossroads[2][1] - road_width;

	m_buildings[2][0][0] = m_crossroads[2][0] + road_width;
	m_buildings[2][0][1] = m_crossroads[2][1] - road_width;
	m_buildings[2][1][0] = m_crossroads[3][0] - road_width;
	m_buildings[2][1][1] = m_crossroads[3][1] - road_width;

	m_buildings[3][0][0] = m_crossroads[3][0] + road_width;
	m_buildings[3][0][1] = m_crossroads[3][1] - road_width;
	m_buildings[3][1][0] = m_crossroads[4][0] - road_width;
	m_buildings[3][1][1] = m_crossroads[4][1] - road_width;



	m_buildings[4][0][0] = m_crossroads[0][0] + road_width;
	m_buildings[4][0][1] = m_crossroads[0][1] - road_width;
	m_buildings[4][1][0] = m_crossroads[6][0] + road_width;
	m_buildings[4][1][1] = m_crossroads[6][1] + road_width;

	m_buildings[5][0][0] = m_crossroads[1][0] - road_width;
	m_buildings[5][0][1] = m_crossroads[1][1] - road_width;
	m_buildings[5][1][0] = m_crossroads[7][0] - road_width;
	m_buildings[5][1][1] = m_crossroads[7][1] + road_width;

	m_buildings[6][0][0] = m_crossroads[1][0] + road_width;
	m_buildings[6][0][1] = m_crossroads[1][1] - road_width;
	m_buildings[6][1][0] = m_crossroads[7][0] + road_width;
	m_buildings[6][1][1] = m_crossroads[7][1] + road_width;

	m_buildings[7][0][0] = m_crossroads[2][0] - road_width;
	m_buildings[7][0][1] = m_crossroads[2][1] - road_width;
	m_buildings[7][1][0] = m_crossroads[8][0] - road_width;
	m_buildings[7][1][1] = m_crossroads[8][1] + road_width;

	m_buildings[8][0][0] = m_crossroads[2][0] + road_width;
	m_buildings[8][0][1] = m_crossroads[2][1] - road_width;
	m_buildings[8][1][0] = m_crossroads[8][0] + road_width;
	m_buildings[8][1][1] = m_crossroads[8][1] + road_width;

	m_buildings[9][0][0] = m_crossroads[3][0] - road_width;
	m_buildings[9][0][1] = m_crossroads[3][1] - road_width;
	m_buildings[9][1][0] = m_crossroads[9][0] - road_width;
	m_buildings[9][1][1] = m_crossroads[9][1] + road_width;

	m_buildings[10][0][0] = m_crossroads[3][0] + road_width;
	m_buildings[10][0][1] = m_crossroads[3][1] - road_width;
	m_buildings[10][1][0] = m_crossroads[9][0] + road_width;
	m_buildings[10][1][1] = m_crossroads[9][1] + road_width;

	m_buildings[11][0][0] = m_crossroads[4][0] - road_width;
	m_buildings[11][0][1] = m_crossroads[4][1] - road_width;
	m_buildings[11][1][0] = m_crossroads[10][0] - road_width;
	m_buildings[11][1][1] = m_crossroads[10][1] + road_width;



	m_buildings[12][0][0] = m_crossroads[6][0] + road_width;
	m_buildings[12][0][1] = m_crossroads[6][1] + road_width;
	m_buildings[12][1][0] = m_crossroads[7][0] - road_width;
	m_buildings[12][1][1] = m_crossroads[7][1] + road_width;

	m_buildings[13][0][0] = m_crossroads[7][0] + road_width;
	m_buildings[13][0][1] = m_crossroads[7][1] + road_width;
	m_buildings[13][1][0] = m_crossroads[8][0] - road_width;
	m_buildings[13][1][1] = m_crossroads[8][1] + road_width;

	m_buildings[14][0][0] = m_crossroads[8][0] + road_width;
	m_buildings[14][0][1] = m_crossroads[8][1] + road_width;
	m_buildings[14][1][0] = m_crossroads[9][0] - road_width;
	m_buildings[14][1][1] = m_crossroads[9][1] + road_width;

	m_buildings[15][0][0] = m_crossroads[9][0] + road_width;
	m_buildings[15][0][1] = m_crossroads[9][1] + road_width;
	m_buildings[15][1][0] = m_crossroads[10][0] - road_width;
	m_buildings[15][1][1] = m_crossroads[10][1] + road_width;



	m_buildings[16][0][0] = m_crossroads[5][0] + road_width;
	m_buildings[16][0][1] = m_crossroads[5][1] - road_width;
	m_buildings[16][1][0] = m_crossroads[6][0] - road_width;
	m_buildings[16][1][1] = m_crossroads[6][1] - road_width;

	m_buildings[17][0][0] = m_crossroads[6][0] + road_width;
	m_buildings[17][0][1] = m_crossroads[6][1] - road_width;
	m_buildings[17][1][0] = m_crossroads[7][0] - road_width;
	m_buildings[17][1][1] = m_crossroads[7][1] - road_width;

	m_buildings[18][0][0] = m_crossroads[7][0] + road_width;
	m_buildings[18][0][1] = m_crossroads[7][1] - road_width;
	m_buildings[18][1][0] = m_crossroads[8][0] - road_width;
	m_buildings[18][1][1] = m_crossroads[8][1] - road_width;

	m_buildings[19][0][0] = m_crossroads[8][0] + road_width;
	m_buildings[19][0][1] = m_crossroads[8][1] - road_width;
	m_buildings[19][1][0] = m_crossroads[9][0] - road_width;
	m_buildings[19][1][1] = m_crossroads[9][1] - road_width;

	m_buildings[20][0][0] = m_crossroads[9][0] + road_width;
	m_buildings[20][0][1] = m_crossroads[9][1] - road_width;
	m_buildings[20][1][0] = m_crossroads[10][0] - road_width;
	m_buildings[20][1][1] = m_crossroads[10][1] - road_width;

	m_buildings[21][0][0] = m_crossroads[10][0] + road_width;
	m_buildings[21][0][1] = m_crossroads[10][1] - road_width;
	m_buildings[21][1][0] = m_crossroads[11][0] - road_width;
	m_buildings[21][1][1] = m_crossroads[11][1] - road_width;



	m_buildings[22][0][0] = m_crossroads[5][0] + road_width;
	m_buildings[22][0][1] = m_crossroads[5][1] - road_width;
	m_buildings[22][1][0] = m_crossroads[12][0] + road_width;
	m_buildings[22][1][1] = m_crossroads[12][1] + road_width;

	m_buildings[23][0][0] = m_crossroads[6][0] - road_width;
	m_buildings[23][0][1] = m_crossroads[6][1] - road_width;
	m_buildings[23][1][0] = m_crossroads[13][0] - road_width;
	m_buildings[23][1][1] = m_crossroads[13][1] + road_width;

	m_buildings[24][0][0] = m_crossroads[6][0] + road_width;
	m_buildings[24][0][1] = m_crossroads[6][1] - road_width;
	m_buildings[24][1][0] = m_crossroads[13][0] + road_width;
	m_buildings[24][1][1] = m_crossroads[13][1] + road_width;

	m_buildings[25][0][0] = m_crossroads[7][0] - road_width;
	m_buildings[25][0][1] = m_crossroads[7][1] - road_width;
	m_buildings[25][1][0] = m_crossroads[14][0] - road_width;
	m_buildings[25][1][1] = m_crossroads[14][1] + road_width;

	m_buildings[26][0][0] = m_crossroads[7][0] + road_width;
	m_buildings[26][0][1] = m_crossroads[7][1] - road_width;
	m_buildings[26][1][0] = m_crossroads[14][0] + road_width;
	m_buildings[26][1][1] = m_crossroads[14][1] + road_width;

	m_buildings[27][0][0] = m_crossroads[8][0] - road_width;
	m_buildings[27][0][1] = m_crossroads[8][1] - road_width;
	m_buildings[27][1][0] = m_crossroads[15][0] - road_width;
	m_buildings[27][1][1] = m_crossroads[15][1] + road_width;

	m_buildings[28][0][0] = m_crossroads[8][0] + road_width;
	m_buildings[28][0][1] = m_crossroads[8][1] - road_width;
	m_buildings[28][1][0] = m_crossroads[15][0] + road_width;
	m_buildings[28][1][1] = m_crossroads[15][1] + road_width;

	m_buildings[29][0][0] = m_crossroads[9][0] - road_width;
	m_buildings[29][0][1] = m_crossroads[9][1] - road_width;
	m_buildings[29][1][0] = m_crossroads[16][0] - road_width;
	m_buildings[29][1][1] = m_crossroads[16][1] + road_width;

	m_buildings[30][0][0] = m_crossroads[9][0] + road_width;
	m_buildings[30][0][1] = m_crossroads[9][1] - road_width;
	m_buildings[30][1][0] = m_crossroads[16][0] + road_width;
	m_buildings[30][1][1] = m_crossroads[16][1] + road_width;

	m_buildings[31][0][0] = m_crossroads[10][0] - road_width;
	m_buildings[31][0][1] = m_crossroads[10][1] - road_width;
	m_buildings[31][1][0] = m_crossroads[17][0] - road_width;
	m_buildings[31][1][1] = m_crossroads[17][1] + road_width;

	m_buildings[32][0][0] = m_crossroads[10][0] + road_width;
	m_buildings[32][0][1] = m_crossroads[10][1] - road_width;
	m_buildings[32][1][0] = m_crossroads[17][0] + road_width;
	m_buildings[32][1][1] = m_crossroads[17][1] + road_width;

	m_buildings[33][0][0] = m_crossroads[11][0] - road_width;
	m_buildings[33][0][1] = m_crossroads[11][1] - road_width;
	m_buildings[33][1][0] = m_crossroads[18][0] - road_width;
	m_buildings[33][1][1] = m_crossroads[18][1] + road_width;



	m_buildings[34][0][0] = m_crossroads[12][0] + road_width;
	m_buildings[34][0][1] = m_crossroads[12][1] + road_width;
	m_buildings[34][1][0] = m_crossroads[13][0] - road_width;
	m_buildings[34][1][1] = m_crossroads[13][1] + road_width;

	m_buildings[35][0][0] = m_crossroads[13][0] + road_width;
	m_buildings[35][0][1] = m_crossroads[13][1] + road_width;
	m_buildings[35][1][0] = m_crossroads[14][0] - road_width;
	m_buildings[35][1][1] = m_crossroads[14][1] + road_width;

	m_buildings[36][0][0] = m_crossroads[14][0] + road_width;
	m_buildings[36][0][1] = m_crossroads[14][1] + road_width;
	m_buildings[36][1][0] = m_crossroads[15][0] - road_width;
	m_buildings[36][1][1] = m_crossroads[15][1] + road_width;

	m_buildings[37][0][0] = m_crossroads[15][0] + road_width;
	m_buildings[37][0][1] = m_crossroads[15][1] + road_width;
	m_buildings[37][1][0] = m_crossroads[16][0] - road_width;
	m_buildings[37][1][1] = m_crossroads[16][1] + road_width;

	m_buildings[38][0][0] = m_crossroads[16][0] + road_width;
	m_buildings[38][0][1] = m_crossroads[16][1] + road_width;
	m_buildings[38][1][0] = m_crossroads[17][0] - road_width;
	m_buildings[38][1][1] = m_crossroads[17][1] + road_width;

	m_buildings[39][0][0] = m_crossroads[17][0] + road_width;
	m_buildings[39][0][1] = m_crossroads[17][1] + road_width;
	m_buildings[39][1][0] = m_crossroads[18][0] - road_width;
	m_buildings[39][1][1] = m_crossroads[18][1] + road_width;

	m_buildings[40][0][0] = m_crossroads[13][0] + road_width;
	m_buildings[40][0][1] = m_crossroads[13][1] - road_width;
	m_buildings[40][1][0] = m_crossroads[14][0] - road_width;
	m_buildings[40][1][1] = m_crossroads[14][1] - road_width;

	m_buildings[41][0][0] = m_crossroads[14][0] + road_width;
	m_buildings[41][0][1] = m_crossroads[14][1] - road_width;
	m_buildings[41][1][0] = m_crossroads[15][0] - road_width;
	m_buildings[41][1][1] = m_crossroads[15][1] - road_width;

	m_buildings[42][0][0] = m_crossroads[15][0] + road_width;
	m_buildings[42][0][1] = m_crossroads[15][1] - road_width;
	m_buildings[42][1][0] = m_crossroads[16][0] - road_width;
	m_buildings[42][1][1] = m_crossroads[16][1] - road_width;

	m_buildings[43][0][0] = m_crossroads[16][0] + road_width;
	m_buildings[43][0][1] = m_crossroads[16][1] - road_width;
	m_buildings[43][1][0] = m_crossroads[17][0] - road_width;
	m_buildings[43][1][1] = m_crossroads[17][1] - road_width;



	m_buildings[44][0][0] = m_crossroads[13][0] + road_width;
	m_buildings[44][0][1] = m_crossroads[13][1] - road_width;
	m_buildings[44][1][0] = m_crossroads[19][0] + road_width;
	m_buildings[44][1][1] = m_crossroads[19][1] + road_width;

	m_buildings[45][0][0] = m_crossroads[14][0] - road_width;
	m_buildings[45][0][1] = m_crossroads[14][1] - road_width;
	m_buildings[45][1][0] = m_crossroads[20][0] - road_width;
	m_buildings[45][1][1] = m_crossroads[20][1] + road_width;

	m_buildings[46][0][0] = m_crossroads[14][0] + road_width;
	m_buildings[46][0][1] = m_crossroads[14][1] - road_width;
	m_buildings[46][1][0] = m_crossroads[20][0] + road_width;
	m_buildings[46][1][1] = m_crossroads[20][1] + road_width;

	m_buildings[47][0][0] = m_crossroads[15][0] - road_width;
	m_buildings[47][0][1] = m_crossroads[15][1] - road_width;
	m_buildings[47][1][0] = m_crossroads[21][0] - road_width;
	m_buildings[47][1][1] = m_crossroads[21][1] + road_width;

	m_buildings[48][0][0] = m_crossroads[15][0] + road_width;
	m_buildings[48][0][1] = m_crossroads[15][1] - road_width;
	m_buildings[48][1][0] = m_crossroads[21][0] + road_width;
	m_buildings[48][1][1] = m_crossroads[21][1] + road_width;

	m_buildings[49][0][0] = m_crossroads[16][0] - road_width;
	m_buildings[49][0][1] = m_crossroads[16][1] - road_width;
	m_buildings[49][1][0] = m_crossroads[22][0] - road_width;
	m_buildings[49][1][1] = m_crossroads[22][1] + road_width;

	m_buildings[50][0][0] = m_crossroads[16][0] + road_width;
	m_buildings[50][0][1] = m_crossroads[16][1] - road_width;
	m_buildings[50][1][0] = m_crossroads[22][0] + road_width;
	m_buildings[50][1][1] = m_crossroads[22][1] + road_width;

	m_buildings[51][0][0] = m_crossroads[17][0] - road_width;
	m_buildings[51][0][1] = m_crossroads[17][1] - road_width;
	m_buildings[51][1][0] = m_crossroads[23][0] - road_width;
	m_buildings[51][1][1] = m_crossroads[23][1] + road_width;



	m_buildings[52][0][0] = m_crossroads[19][0] + road_width;
	m_buildings[52][0][1] = m_crossroads[19][1] + road_width;
	m_buildings[52][1][0] = m_crossroads[20][0] - road_width;
	m_buildings[52][1][1] = m_crossroads[20][1] + road_width;

	m_buildings[53][0][0] = m_crossroads[20][0] + road_width;
	m_buildings[53][0][1] = m_crossroads[20][1] + road_width;
	m_buildings[53][1][0] = m_crossroads[21][0] - road_width;
	m_buildings[53][1][1] = m_crossroads[21][1] + road_width;

	m_buildings[54][0][0] = m_crossroads[21][0] + road_width;
	m_buildings[54][0][1] = m_crossroads[21][1] + road_width;
	m_buildings[54][1][0] = m_crossroads[22][0] - road_width;
	m_buildings[54][1][1] = m_crossroads[22][1] + road_width;

	m_buildings[55][0][0] = m_crossroads[22][0] + road_width;
	m_buildings[55][0][1] = m_crossroads[22][1] + road_width;
	m_buildings[55][1][0] = m_crossroads[23][0] - road_width;
	m_buildings[55][1][1] = m_crossroads[23][1] + road_width;
}

int gtt_urban::get_vue_num() {
	return vue_physics::get_vue_num();
}

void gtt_urban::fresh_location() {
	//<Warn>:���ŵ�ˢ��ʱ���λ��ˢ��ʱ��ֿ�
	if (context::get_context()->get_tti() % get_precise_config()->get_freshtime() != 0) {
		return;
	}

	for (int vue_id = 0; vue_id < get_vue_num(); vue_id++) {
		context::get_context()->get_vue_array()[vue_id].get_physics_level()->update_location_urban();

		//ÿ�θ��³���λ��ʱ�����жϳ������ڵ�zone_idx
		auto p = context::get_context()->get_vue_array()[vue_id].get_physics_level();
		int granularity = context::get_context()->get_rrm_config()->get_time_division_granularity();
		p->m_slot_time_idx = calculate_slot_time_idx(p, granularity);

		if (context::get_context()->get_tti() == 0) {
			if (p->m_slot_time_idx == 0) {
				time_slot_0 << p->m_absx << " " << p->m_absy << endl;
			}
			else if(p->m_slot_time_idx == 1){
				time_slot_1 << p->m_absx << " " << p->m_absy << endl;
			}
			else if (p->m_slot_time_idx == 2) {
				time_slot_2 << p->m_absx << " " << p->m_absy << endl;
			}
			else if (p->m_slot_time_idx == 3) {
				time_slot_3 << p->m_absx << " " << p->m_absy << endl;
			}
		}
	}


	for (int vue_id1 = 0; vue_id1 < get_vue_num(); vue_id1++) {
		for (int vue_id2 = 0; vue_id2 < vue_id1; vue_id2++) {
			auto vuei = context::get_context()->get_vue_array()[vue_id1].get_physics_level();
			auto vuej = context::get_context()->get_vue_array()[vue_id2].get_physics_level();
			vue_physics::set_distance(vue_id2, vue_id1, sqrt(pow((vuei->m_absx - vuej->m_absx), 2.0f) + pow((vuei->m_absy - vuej->m_absy), 2.0f)));
			calculate_pl(vue_id1, vue_id2);

			if (context::get_context()->get_tti() == 0) {
				distance_pl << vue_physics::get_distance(vue_id2, vue_id1) << " " << vue_physics::get_pl(vue_id1, vue_id2) << endl;
			}
		}
	}
}

int gtt_urban::calculate_slot_time_idx(vue_physics* t_pv, int t_granularity) {
	if (t_granularity == 1) {
		return 0;
	}
	if (t_granularity == 2) {
		if (t_pv->m_vangle == -180 || t_pv->m_vangle == 0 || t_pv->m_vangle == 180) {
			return 0;
		}
		else {
			return 1;
		}
	}
	else if (t_granularity==4) {
		gtt_urban_config* __config = get_precise_config();
		int center_idx = -1;
		double min_distance = 0x3f3f3f3f;
		double temp;
		for (int i = 0; i < 24; i++) {
			if ((temp = pow(abs(t_pv->m_absx - m_crossroads[i][0]), 2) + pow(abs(t_pv->m_absy - m_crossroads[i][1]), 2)) < min_distance) {
				min_distance = temp;
				center_idx = i;
			}
		}

		if (t_pv->m_absx - m_crossroads[center_idx][0]>__config->get_road_width()) {
			return 0;
		}
		else if (t_pv->m_absy - m_crossroads[center_idx][1] > __config->get_road_width()) {
			return 1;
		}
		else if (m_crossroads[center_idx][0] - t_pv->m_absx>__config->get_road_width()) {
			return 2;
		}
		else {
			return 3;
		}
	}
	else {
		throw logic_error("t_granularity config error");
	}
}

bool gtt_urban::is_interact_with_buildings(double t_x1, double t_y1, double t_x2, double t_y2) {

}

void gtt_urban::calculate_pl(int t_vue_id1, int t_vue_id2) {

	location _location;
	_location.eNBAntH = 5;
	_location.VeUEAntH = 1.5;
	_location.RSUAntH = 5;
	_location.locationType = None;
	_location.distance = 0;
	_location.distance1 = 0;
	_location.distance2 = 0;

	antenna _antenna;
	_antenna.antGain = 3;
	_antenna.byTxAntNum = 1;
	_antenna.byRxAntNum = 2;

	imta* __imta = new imta();

	auto vuei = context::get_context()->get_vue_array()[t_vue_id1].get_physics_level();
	auto vuej = context::get_context()->get_vue_array()[t_vue_id2].get_physics_level();

	//�жϳ����˶������Ƕ����������ϱ�����true����������false�����ϱ�����
	bool v_diri, v_dirj;
	if (vuei->m_vangle == 0 || vuei->m_vangle == 180) {
		v_diri = true;
	}
	else {
		v_diri = false;
	}

	if (vuej->m_vangle == 0 || vuej->m_vangle == 180) {
		v_dirj = true;
	}
	else {
		v_dirj = false;
	}

	//�����������ľ��Ժ�������ľ���
	double x_between = abs(vuei->m_absx - vuej->m_absx);
	double y_between = abs(vuei->m_absy - vuej->m_absy);

	//�ж��������Ƿ��н������ڵ����Ӷ�ȷ����Nlos����Los,�����NLos�����ж��Ƿ��������ٽֽ�ģ��
	if ((v_diri == true && v_dirj == true && y_between < 20)
		|| (v_diri == false && v_dirj == false && x_between < 20
			|| vue_physics::get_distance(t_vue_id1, t_vue_id2)<20)) {
		_location.locationType = Los;
	}
	else {
		_location.locationType = Nlos;
		if (v_diri == v_dirj) {
			_location.manhattan = false;
		}
		else {
			_location.manhattan = true;
		}
	}

	if (context::get_context()->get_tti() == 0) {
		if (_location.locationType == Los) {
			distance_los << vue_physics::get_distance(t_vue_id1, t_vue_id2) << endl;
		}
		else {
			distance_nlos << vue_physics::get_distance(t_vue_id1, t_vue_id2) << endl;
		}
	}

	double angle = 0;

	_location.distance = vue_physics::get_distance(t_vue_id1, t_vue_id2);
	_location.distance1 = x_between;
	_location.distance2 = y_between;

	angle = atan2(vuei->m_absy - vuej->m_absy, vuei->m_absx - vuej->m_absx) / imta::s_DEGREE_TO_PI;

	imta::randomGaussian(_location.posCor, 5, 0.0f, 1.0f);//������˹�������Ϊ�����ŵ�ϵ��ʹ��

	double m_FantennaAnglei;
	double m_FantennaAnglej;

	imta::randomUniform(&m_FantennaAnglei, 1, 180.0f, -180.0f, false);
	imta::randomUniform(&m_FantennaAnglej, 1, 180.0f, -180.0f, false);

	_antenna.TxAngle = angle - m_FantennaAnglei;
	_antenna.RxAngle = angle - m_FantennaAnglej;
	_antenna.TxSlantAngle = new double[_antenna.byTxAntNum];
	_antenna.TxAntSpacing = new double[_antenna.byTxAntNum];
	_antenna.RxSlantAngle = new double[_antenna.byRxAntNum];
	_antenna.RxAntSpacing = new double[_antenna.byRxAntNum];
	_antenna.TxSlantAngle[0] = 90.0f;
	_antenna.TxAntSpacing[0] = 0.0f;
	_antenna.RxSlantAngle[0] = 90.0f;
	_antenna.RxSlantAngle[1] = 90.0f;
	_antenna.RxAntSpacing[0] = 0.0f;
	_antenna.RxAntSpacing[1] = 0.5f;

	double t_Pl = 0;

	__imta->build(&t_Pl, imta::s_FC, _location, _antenna, vuei->m_speed, vuej->m_speed, vuei->m_vangle, vuej->m_vangle);//�����˽�������ŵ�ģ�ͼ���UE֮���ŵ�ϵ��

	vue_physics::set_pl(t_vue_id1, t_vue_id2, t_Pl);

	memory_clean::safe_delete(_antenna.TxSlantAngle, true);
	memory_clean::safe_delete(_antenna.TxAntSpacing, true);
	memory_clean::safe_delete(_antenna.RxSlantAngle, true);
	memory_clean::safe_delete(_antenna.RxAntSpacing, true);

	memory_clean::safe_delete(__imta);
	
}

gtt_urban_config* gtt_urban::get_precise_config() {
	return (gtt_urban_config*)get_config();
}
