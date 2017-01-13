/*
* =====================================================================================
*
*       Filename:  vue_network.cpp
*
*    Description:  车辆类的网络层部分实现
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

#include"context.h"
#include"config.h"
#include"gtt.h"
#include"vue.h"
#include"vue_link.h"
#include"vue_network.h"
#include"event.h"

using namespace std;

std::default_random_engine vue_network::s_engine(0);

vue_network::vue_network() {

}

vue_network::~vue_network() {

}

void vue_network::set_superior_level(vue* t_superior_level) {
	m_superior_level = t_superior_level;
}

vue* vue_network::get_superior_level() {
	return m_superior_level;
}

void vue_network::set_periodic_event_next_trigger_tti(int t_congestion_level_num) {
	m_periodic_event_next_trigger_tti.assign(t_congestion_level_num, 0);
}

const std::vector<int>& vue_network::get_periodic_event_next_trigger_tti() {
	return m_periodic_event_next_trigger_tti;
}

void vue_network::add_sender_event(sender_event* t_sender_event) {
	m_sender_event_list.push_back(t_sender_event);
}

void vue_network::send_connection() {
	context* __context = context::get_context();
	vue* vue_ary = __context->get_vue_array();

	list<sender_event*>::iterator it = m_sender_event_list.begin();
	while (it != m_sender_event_list.end()) {
		sender_event* __sender_event = *it;

		//选择发送频段
		__sender_event->set_pattern_idx(select_pattern());

		for (int vue_id = 0; vue_id < __context->get_gtt()->get_vue_num(); vue_id++) {
			if (vue_id == __sender_event->get_vue_id()) continue;
			vue_ary[vue_id].get_link_level()->receive_connection(__sender_event);
		}
		it = m_sender_event_list.erase(it);
	}
}

int vue_network::select_pattern() {
	uniform_int_distribution<int> u(0, context::get_context()->get_rrm_config()->get_pattern_num());
	return u(s_engine);
}