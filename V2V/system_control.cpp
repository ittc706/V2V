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
#include"vue.h"
#include"gtt.h"
#include"gtt_highspeed.h"


using namespace std;

system_control::system_control() {

}

system_control::~system_control() {
	memory_clean::safe_delete(m_context);
}

void system_control::process() {
	initialize();//初始化

	drop_vue();//车辆撒点
}


void system_control::initialize() {
	//调用容器context的静态工厂方法生成单例模式下唯一对象
	context::context_factory();

	//为成员变量赋值
	m_context = context::get_context();

	//<Warn>
	m_context->set_gtt(new gtt_highspeed());
}


void system_control::drop_vue() {
	m_context->get_gtt()->drop_vue();
}


void system_control::update_channel() {

}

