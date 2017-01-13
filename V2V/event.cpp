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

#include"context.h"
#include"event.h"
#include"config.h"

using namespace std;

int sender_event::s_event_count = 0;

sender_event::sender_event() {

}

sender_event::~sender_event() {

}

int sender_event::get_event_id() {
	return m_event_id;
}

void sender_event::set_vue_id(int t_vue_id) {
	m_vue_id = t_vue_id;
}

int sender_event::get_vue_id() {
	return m_vue_id;
}

receiver_event::receiver_event(sender_event* t_sender_event, int t_receiver_vue_id) {
	set_event_id(t_sender_event->get_event_id());
	set_from_vue_id(t_sender_event->get_vue_id());
	set_to_vue_id(t_receiver_vue_id);

	m_package_num = context::get_context()->get_tmc_config()->get_package_num();
	m_bit_num_per_package = context::get_context()->get_tmc_config()->get_bit_num_per_package();

	m_remain_bit_num = m_bit_num_per_package[0];
}

receiver_event::~receiver_event() {

}

void receiver_event::set_event_id(int t_event_id) {
	m_event_id = t_event_id;
}

int receiver_event::get_event_id() {
	return m_event_id;
}

void receiver_event::set_from_vue_id(int t_from_vue_id) {
	m_from_vue_id = t_from_vue_id;
}

int receiver_event::get_from_vue_id() {
	return m_from_vue_id;
}

void receiver_event::set_to_vue_id(int t_to_vue_id) {
	m_to_vue_id = t_to_vue_id;
}

int receiver_event::get_to_vue_id() {
	return m_to_vue_id;
}

bool receiver_event::get_is_finished() {
	return m_is_finished;
}

bool receiver_event::get_is_loss() {
	return m_is_loss;
}

void receiver_event::transimit(int t_transimit_max_bit_num) {
	if (t_transimit_max_bit_num >= m_remain_bit_num) {
		if (++m_package_idx == m_package_num) {
			m_remain_bit_num = 0;
			m_is_finished = true;
		}
		else {
			m_remain_bit_num = m_bit_num_per_package[m_package_idx];
		}
	}
	else {
		m_remain_bit_num -= t_transimit_max_bit_num;
	}
}

