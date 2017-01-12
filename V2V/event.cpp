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

int v2v_event::s_event_count = 0;

v2v_event::v2v_event() {

}

v2v_event::~v2v_event() {

}

int v2v_event::get_send_delay() {
	return m_send_delay;
}

void v2v_event::increase_send_delay() {
	++m_send_delay;
}

