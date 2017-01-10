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
}


void system_control::drop_vue() {

}

