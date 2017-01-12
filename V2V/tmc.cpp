/*
* =====================================================================================
*
*       Filename:  tmc.cpp
*
*    Description:  业务模型与控制类实现
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

#include<random>
#include"context.h"
#include"gtt.h"
#include"tmc.h"
#include"vue.h"
#include"vue_link.h"
#include"event.h"

using namespace std;

tmc::tmc() {
	//<Warn>
	set_period_of_period_event(500);

}

tmc::~tmc() {

}

void tmc::set_period_of_period_event(int t_period_of_period_event) {
	m_period_of_period_event = t_period_of_period_event;
}

int tmc::get_period_of_period_event() {
	return m_period_of_period_event;
}

void tmc::preparate() {
	context* __context = context::get_context();

	__context->initialize_tti_event_list();//初始化tti_event_list成员

	default_random_engine e;
	uniform_int_distribution<int> u(0, get_period_of_period_event());
	for (int vue_id = 0; vue_id < __context->get_gtt()->get_vue_num(); vue_id++) {
		//为每辆车配置初始化事件触发时刻
		__context->get_vue_array()[vue_id].get_link_level()->set_period_event_next_trigger_tti(u(e));
	}
}

void tmc::event_trigger() {
	context* __context = context::get_context();
	for (int vue_id = 0; vue_id < __context->get_gtt()->get_vue_num(); vue_id++) {
		if (__context->get_vue_array()[vue_id].get_link_level()->get_period_event_next_trigger_tti() != __context->get_tti())continue;
		__context->get_event_array().push_back(new v2v_event());
	}
}