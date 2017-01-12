/*
* =====================================================================================
*
*       Filename:  vue_link.cpp
*
*    Description:  车辆类的链路层部分实现
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

#include"vue_link.h"

using namespace std;

vue_link::vue_link() {

}

vue_link::~vue_link() {

}

void vue_link::initialize_period_event_next_trigger_tti(int t_congestion_level_num){
	m_period_event_next_trigger_tti.assign(t_congestion_level_num,0);
}

const std::vector<int>& vue_link::get_period_event_next_trigger_tti() {
	return m_period_event_next_trigger_tti;
}
