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

void vue_link::set_period_event_next_trigger_tti(int t_period_event_next_trigger_tti) {
	m_period_event_next_trigger_tti = t_period_event_next_trigger_tti;
}

int vue_link::get_period_event_next_trigger_tti() {
	return m_period_event_next_trigger_tti;
}
