/*
* =====================================================================================
*
*       Filename:  system_control.cpp
*
*    Description:  ϵͳ��ʵ��
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
	initialize();//��ʼ��
}


void system_control::initialize() {
	//��������Ψһ����
	context::context_factory();

	//Ϊ��Ա������ֵ
	m_context = context::get_context();

	//gtt��Ԫ��ʼ������
	m_context->get_gtt()->initialize();

	//tmc��Ԫ��ʼ������
	m_context->get_tmc()->initialize();
}

