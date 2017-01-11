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
	initialize();//��ʼ��

	drop_vue();//��������
}


void system_control::initialize() {
	//��������context�ľ�̬�����������ɵ���ģʽ��Ψһ����
	context::context_factory();

	//Ϊ��Ա������ֵ
	m_context = context::get_context();

	//<Warn>
	m_context->set_gtt(new gtt_highspeed());
}


void system_control::drop_vue() {
	m_context->get_gtt()->drop_vue();
}


void system_control::update_channel() {

}

