/*
* =====================================================================================
*
*       Filename:  system_control.cpp
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

#include"system_control.h"
#include"function.h"
#include"context.h"
#include"gtt.h"
#include"gtt_highspeed.h"
#include"tmc.h"
#include"vue.h"

using namespace std;

system_control::system_control() {

}

system_control::~system_control() {
	memory_clean::safe_delete(m_context);
}

void system_control::process() {
	initialize();//初始化

	gtt_initialize();//车辆撒点
}


void system_control::initialize() {
	//调用容器context的静态工厂方法生成单例模式下唯一对象
	context::context_factory();

	//为成员变量赋值
	m_context = context::get_context();

	//gtt单元初始化工作
	gtt_initialize();

	//tmc单元初始化工作
	tmc_initialize();
}


void system_control::gtt_initialize() {
	m_context->get_gtt()->drop_vue();
}

void system_control::tmc_initialize() {
	m_context->get_tmc()->preparate();
}

void system_control::update_channel() {

}

void system_control::event_trigger() {
	m_context->get_tmc()->event_trigger();
}

