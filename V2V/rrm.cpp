/*
* =====================================================================================
*
*       Filename:  rrm.cpp
*
*    Description:  无限资源管理类实现
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
#include"event.h"
#include"gtt.h"
#include"rrm.h"
#include"vue.h"
#include"vue_physics.h"
#include"vue_link.h"
#include"vue_network.h"
#include<iostream>

using namespace std;

rrm::rrm() {
	pattern_vue_coordinate.open("log/pattern_vue_coordinate.txt");
}

rrm::~rrm() {
	pattern_vue_coordinate.close();
}

void rrm::set_config(rrm_config* t_config) {
	m_config = t_config;
}

rrm_config* rrm::get_config() {
	return m_config;
}

void rrm::initialize() {
	vue_network::s_sender_event_per_pattern.assign(m_config->get_pattern_num(), set<sender_event*>());
	vue_network::s_temp_finished_sender_event_per_pattern.assign(m_config->get_pattern_num(), set<sender_event*>());

	if (context::get_context()->get_global_control_config()->get_gtt_mode() == URBAN) {
		vue_network::s_is_pattern_occupied.assign(24, vector<vector<bool>>(m_config->get_time_division_granularity(), vector<bool>(m_config->get_pattern_num(), false)));
	}
	else {
		vue_network::s_is_pattern_occupied.assign(10, vector<vector<bool>>(m_config->get_time_division_granularity(), vector<bool>(m_config->get_pattern_num(), false)));
	}
}
void rrm::schedule() {
	context* __context = context::get_context();

	//首先，将当前时刻触发的事件，建立与接收车辆的关联
	for (int vue_id = 0; vue_id < __context->get_gtt()->get_vue_num(); vue_id++) {
		__context->get_vue_array()[vue_id].get_network_level()->send_connection();
	}

	//进行传输
	for (int pattern_idx = 0; pattern_idx < __context->get_rrm_config()->get_pattern_num(); pattern_idx++) {
		for (sender_event *__sender_event : vue_network::s_sender_event_per_pattern[pattern_idx]) {
			__sender_event->transimit();
			if (__sender_event->is_transmit_time_slot(__context->get_tti())) {
				pattern_vue_coordinate
					<< __sender_event->get_sender_vue()->get_physics_level()->m_absx
					<< " "
					<< __sender_event->get_sender_vue()->get_physics_level()->m_absy
					<< " ";
			}
		}
		pattern_vue_coordinate << endl;
	}

	// 后续处理
	for (int pattern_idx = 0; pattern_idx < __context->get_rrm_config()->get_pattern_num(); pattern_idx++) {
		for (sender_event *__finished_sender_event : vue_network::s_temp_finished_sender_event_per_pattern[pattern_idx]) {
			vue_network::s_sender_event_per_pattern[pattern_idx].erase(__finished_sender_event);
			vue_network::s_finished_sender_event.push_back(__finished_sender_event);

			if (__context->get_rrm_config()->is_time_difision()) {
				vue* pv = __finished_sender_event->get_sender_vue();
				int center_idx = pv->get_physics_level()->get_center_idx();
				int slot_idx = pv->get_physics_level()->get_slot_time_idx();
				if (!vue_network::s_is_pattern_occupied[center_idx][slot_idx][pattern_idx]) {
					throw logic_error("pattern select error");
				}
				vue_network::s_is_pattern_occupied[center_idx][slot_idx][pattern_idx] = false;
			}
		}
		vue_network::s_temp_finished_sender_event_per_pattern[pattern_idx].clear();
	}
}