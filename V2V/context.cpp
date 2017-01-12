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
#include"config_loader.h"
#include"config.h"
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
	//初始化容器成员
	initialize();

	//为容器成员注入依赖项
	dependency_injecte();
}

context::~context() {
	memory_clean::safe_delete(m_vue_array, true);
}

void context::set_config_loader(config_loader* t_config_loader) {
	m_config_loader = t_config_loader;
}

config_loader* context::get_config_loader() {
	return m_config_loader;
}

void context::set_global_control_config(global_control_config* t_global_control_config) {
	m_global_control_config = t_global_control_config;
}

global_control_config* context::get_global_control_config() {
	return m_global_control_config;
}

void context::set_gtt_config(gtt_config* t_gtt_config) {
	m_gtt_config = t_gtt_config;
}

gtt_config* context::get_gtt_config() {
	return m_gtt_config;
}

void context::set_tmc_config(tmc_config* t_tmc_config) {
	m_tmc_config = t_tmc_config;
}

tmc_config* context::get_tmc_config() {
	return m_tmc_config;
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

void context::initialize() {
	/* 容器成员在这里完成初始化 */

	//初始化类加载器
	set_config_loader(new config_loader());

	//初始化配置参数对象
	set_global_control_config(new global_control_config());
	set_gtt_config(new gtt_highspeed_config());
	set_tmc_config(new tmc_config());

	//初始化地理拓扑与运动模型单元对象
	set_gtt(new gtt_highspeed());

	//初始化业务模型与控制单元对象
	set_tmc(new tmc());
}

void context::dependency_injecte() {
	get_global_control_config()->set_config_loader(get_config_loader());
	get_global_control_config()->load();
	get_gtt_config()->set_config_loader(get_config_loader());
	get_tmc_config()->set_config_loader(get_config_loader());

	get_gtt()->set_config(get_gtt_config());

}