/*
* =====================================================================================
*
*       Filename:  event.cpp
*
*    Description:  事件类实现
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

#include<iostream>
#include"context.h"
#include"event.h"
#include"config.h"
#include"vue.h"
#include"vue_physics.h"
#include"vue_link.h"
#include"vue_network.h"
#include"wt.h"

using namespace std;

int sender_event::s_event_count = 0;

sender_event::sender_event(int t_tti) {
	m_package_num = context::get_context()->get_tmc_config()->get_package_num();
	m_remaining_transmission_time_per_package = context::get_context()->get_tmc_config()->get_tti_per_package();
	m_start_time = t_tti;
}

sender_event::~sender_event() {

}

int sender_event::get_event_id() {
	return m_event_id;
}

void sender_event::add_receiver_event_vec(receiver_event* t_receiver_event) {
	m_receiver_event_vec.push_back(t_receiver_event);
}

const std::vector<receiver_event*>& sender_event::get_receiver_event_vec() {
	return m_receiver_event_vec;
}


void sender_event::set_sender_vue(vue* t_sender_vue) {
	m_sender_vue = t_sender_vue;
}

vue* sender_event::get_sender_vue() {
	return m_sender_vue;
}

int sender_event::get_sender_vue_id() {
	return m_sender_vue->get_physics_level()->get_vue_id();
}

void sender_event::set_center_idx(int t_center_idx) {
	m_center_idx = t_center_idx;
}

int sender_event::get_center_idx() {
	return m_center_idx;
}

void sender_event::set_time_slot_idx(int t_time_slot_idx) {
	m_time_slot_idx = t_time_slot_idx;
}

int sender_event::get_time_slot_idx() {
	return m_time_slot_idx;
}

void sender_event::set_pattern_idx(int t_pattern_idx) {
	m_pattern_idx = t_pattern_idx;
}

int sender_event::get_pattern_idx() {
	return m_pattern_idx;
}

int sender_event::get_package_idx() {
	return m_package_idx;
}

bool sender_event::get_is_finished() {
	return m_is_finished;
}

int sender_event::get_start_time() {
	return m_start_time;
}

int sender_event::get_end_time() {
	return m_end_time;
}

void sender_event::set_end_time(int t_tti) {
	m_end_time = t_tti;
}

void sender_event::transimit() {
	context* __context = context::get_context();
	int tti = __context->get_tti();
	//当该事件所对应的发送车辆不在该时隙传输时，continue
	if (!is_transmit_time_slot(tti)) 
		return;

	//当前正在传输的package序号
	int cur_transimiting_package_idx = get_package_idx();
	
	//更新sender_event状态
	update();

	bool cur_is_finished = get_is_finished();

	//所有车辆进行接收
	for (receiver_event *__receiver_event : m_receiver_event_vec) {
		__receiver_event->receive(cur_transimiting_package_idx, cur_is_finished);
	}
}

bool sender_event::is_transmit_time_slot(int t_tti) {
	int granularity = context::get_context()->get_rrm_config()->get_time_division_granularity();
	return t_tti% granularity == m_time_slot_idx;
}

void sender_event::update() {
	if (--m_remaining_transmission_time_per_package[m_package_idx] == 0) {
		if (++m_package_idx == m_package_num) {
			set_end_time(context::get_context()->get_tti());
			vue_network::s_temp_finished_sender_event_per_pattern[get_pattern_idx()].insert(this);
			m_is_finished = true;
		}
		else{//当还有包需要传送时，将其再次添加到对应vue的发送列表中进行再次的pattern选择
			int sender_vue_id = m_sender_vue->get_physics_level()->get_vue_id();
		}
	}
}

int receiver_event::s_event_count = 0;

receiver_event::receiver_event(sender_event* t_sender_event, vue* t_receiver_vue) {
	set_sender_event(t_sender_event);
	set_sender_vue(t_sender_event->get_sender_vue());
	set_receiver_vue(t_receiver_vue);

	m_package_loss.assign(context::get_context()->get_tmc_config()->get_package_num(), false);

	set_distance(vue_physics::get_distance(get_sendr_vue_id(), get_receiver_vue_id()));
}

receiver_event::~receiver_event() {

}

int receiver_event::get_event_id() {
	return m_event_id;
}

void receiver_event::set_sender_event(sender_event * t_sender_event) {
	m_sender_event = t_sender_event;
}

sender_event* receiver_event::get_sender_event() {
	return m_sender_event;
}

void receiver_event::set_sender_vue(vue *t_sender_vue) {
	m_sender_vue = t_sender_vue;
}

vue* receiver_event::get_sender_vue() {
	return m_sender_vue;
}

int receiver_event::get_sendr_vue_id() {
	return m_sender_vue->get_physics_level()->get_vue_id();
}

void receiver_event::set_receiver_vue(vue *t_receiver_vue) {
	m_receiver_vue = t_receiver_vue;
}

vue* receiver_event::get_receiver_vue() {
	return m_receiver_vue;
}

int receiver_event::get_receiver_vue_id() {
	return m_receiver_vue->get_physics_level()->get_vue_id();
}

void receiver_event::set_distance(double t_distance) {
	m_distance = t_distance;
}

double receiver_event::get_distance() {
	return m_distance;
}

int receiver_event::get_pattern_idx() {
	return m_sender_event->get_pattern_idx();
}

void receiver_event::set_package_loss(int t_package_loss) {
	m_package_loss[t_package_loss] = true;
	m_is_loss = true;
}

const vector<bool>& receiver_event::get_package_loss() {
	return m_package_loss;
}

bool receiver_event::get_is_loss() {
	return m_is_loss;
}

void receiver_event::receive(int t_package_idx,bool t_is_finished) {
	context* __context = context::get_context();
	int tti = __context->get_tti();

	//计算SINR
	wt* __wt = __context->get_wt();

	double sinr = 0;
	int vue_send_id = get_sendr_vue_id();
	int vue_receive_id = get_receiver_vue_id();
	int pattern_idx = get_pattern_idx();

	//当前pattern下，发送车辆的id，为什么用set，因为可能同一个频段上，同一个车辆触发了不同的事件，但是只需要统计车辆id，因此用set
	set<int> sending_vue_id_vec;
	for (sender_event *__sender_event : vue_network::s_sender_event_per_pattern[pattern_idx]) {
		if (__sender_event->is_transmit_time_slot(tti))
			sending_vue_id_vec.insert(__sender_event->get_sender_vue_id());
	}

	sinr = __wt->calculate_sinr(
		vue_send_id,
		vue_receive_id,
		get_pattern_idx(),
		sending_vue_id_vec
	);

	auto p = __context->get_vue_array()[vue_receive_id].get_physics_level();

	if (sinr < __context->get_rrm_config()->get_drop_sinr_boundary()) {
		set_package_loss(t_package_idx);//记录丢包
	}
	else {
		p->m_pattern_occupied[pattern_idx] = true;
	}

	if (t_is_finished) {
		if (get_is_loss()) {
			get_receiver_vue()->get_link_level()->m_loss_event_list.push_back(this);
		}
		else {
			get_receiver_vue()->get_link_level()->m_success_event_list.push_back(this);
		}
	}
}


