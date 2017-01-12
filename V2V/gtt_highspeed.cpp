/*
* =====================================================================================
*
*       Filename:  gtt_highspeed.cpp
*
*    Description:  高速场景类实现
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


#include"gtt_highspeed.h"
#include"vue_physics.h"
#include"context.h"
#include"vue.h"
#include"function.h"

using namespace std;

void gtt_highspeed::drop_vue() {
	int* m_pupr = new int[m_road_num];//每条路上的车辆数
	double* TotalTime = new double[m_road_num];//每条道路初始泊松撒点过程中所有车辆都已撒进区域内所用的总时间
	std::list<double>* possion = new std::list<double>[m_road_num];//每条道路初始泊松撒点的车辆到达时间间隔list，单位s

	//生成负指数分布的车辆到达间隔
	int tempVeUENum = 0;
	double lambda = 1 / 2.5;//均值为1/lambda，依照协议车辆到达时间间隔的均值为2.5s
	for (int roadId = 0; roadId != m_road_num; roadId++) {
		TotalTime[roadId] = 0;
		while (TotalTime[roadId] * (m_speed / 3.6) < m_road_length) {
			double pV = 0.0;
			while (true)
			{
				pV = (double)rand() / (double)RAND_MAX;
				if (pV != 1)
				{
					break;
				}
			}
			pV = (-1.0 / lambda)*log(1 - pV);
			possion[roadId].push_back(pV);
			TotalTime[roadId] += pV;
			double check = TotalTime[roadId];
		}
		m_pupr[roadId] = possion[roadId].size();//完成当前道路下总车辆数的赋值
		tempVeUENum += m_pupr[roadId];
	}

	//进行车辆的撒点
	context::get_context()->set_vue_array(new vue[tempVeUENum]);
	int VeUEId = 0;

	for (int roadId = 0; roadId != m_road_num; roadId++) {
		for (int uprIdx = 0; uprIdx != m_pupr[roadId]; uprIdx++) {
			auto p = context::get_context()->get_vue_array()[VeUEId].get_physics_level();
		    p->m_absx = -1732 + (TotalTime[roadId] - possion[roadId].back())*(p->m_speed / 3.6);
			p->m_absy = m_road_topo_ratio[roadId * 2 + 1]* m_road_width;
			p->m_speed = m_speed;
			TotalTime[roadId] = TotalTime[roadId] - possion[roadId].back();
			possion[roadId].pop_back();
		}
	}
	memory_clean::safe_delete(m_pupr, true);
	memory_clean::safe_delete(TotalTime, true);
	memory_clean::safe_delete(possion, true);
}


double gtt_highspeed::get_freshtime() {
	return m_freshtime;
}

double gtt_highspeed::get_road_length() {
	return m_road_length;
}
