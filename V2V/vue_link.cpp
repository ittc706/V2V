/*
* =====================================================================================
*
*       Filename:  vue_link.cpp
*
*    Description:  ���������·�㲿��ʵ��
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

#include"vue.h"
#include"vue_physics.h"
#include"vue_link.h"
#include"event.h"

using namespace std;

vue_link::vue_link() {

}

vue_link::~vue_link() {

}

void vue_link::set_superior_level(vue* t_superior_level) {
	m_superior_level = t_superior_level;
}

vue* vue_link::get_superior_level() {
	return m_superior_level;
}

void vue_link::receive_connection(sender_event* t_sender_event) {
	int vue_id = get_superior_level()->get_physics_level()->get_vue_id();
	receiver_event* __receiver_event = new receiver_event(t_sender_event);
	__receiver_event->set_to_vue_id(vue_id);

	m_receiver_events_list.push_back(__receiver_event);
}