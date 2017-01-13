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
}


void system_control::initialize() {
	//产生容器唯一单例
	context::context_factory();

	//为成员变量赋值
	m_context = context::get_context();

	//gtt单元初始化工作
	m_context->get_gtt()->initialize();

	//tmc单元初始化工作
	m_context->get_tmc()->initialize();
}

