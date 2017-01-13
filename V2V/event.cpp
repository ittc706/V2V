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


#include"event.h"

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

receiver_event::receiver_event(sender_event* t_sender_event) {
	set_event_id(t_sender_event->get_event_id());
	set_from_vue_id(t_sender_event->get_vue_id());
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


