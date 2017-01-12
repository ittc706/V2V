/*
* =====================================================================================
*
*       Filename:  容器类.cpp
*
*    Description:  系统类实现
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
#include"function.h"
#include"gtt_highspeed.h"
#include"vue.h"
#include"tmc.h"

using namespace std;

context* context::s_singleton_context = nullptr;

context* context::get_context() {
	return s_singleton_context;
}

void context::set_context(context* t_singleton_context) {
	memory_clean::safe_delete(s_singleton_context);
	s_singleton_context = t_singleton_context;
}

void context::context_factory() {
	context* __context = new context();
	set_context(__context);
}

context::context() {
	/* 容器成员在这里完成初始化 */
	//<Warn>
	set_gtt(new gtt_highspeed());

	set_tmc(new tmc());
}

context::~context() {
	memory_clean::safe_delete(m_vue_array, true);
}

void context::increase_tti() {
	++m_tti;
}

int context::get_tti() {
	return m_tti;
}

void context::set_vue_array(vue* t_vue_array) {
	m_vue_array = t_vue_array;
}

vue* context::get_vue_array() {
	return m_vue_array;
}

void context::set_gtt(gtt* t_gtt) {
	m_gtt = t_gtt;
}

gtt* context::get_gtt() {
	return m_gtt;
}

void context::set_tmc(tmc* t_tmc) {
	m_tmc = t_tmc;
}

tmc* context::get_tmc() {
	return m_tmc;
}

vector<v2v_event*>& context::get_event_array() {
	return m_event_array;
}

void context::initialize_tti_event_list() {
	//<Warn>
	m_tti_event_list = vector<list<int>>(100);
}

vector<std::list<int>>& context::get_tti_event_list() {
	return m_tti_event_list;
}