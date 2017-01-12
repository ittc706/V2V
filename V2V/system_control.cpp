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

	gtt_initialize();//��������
}


void system_control::initialize() {
	//��������context�ľ�̬�����������ɵ���ģʽ��Ψһ����
	context::context_factory();

	//Ϊ��Ա������ֵ
	m_context = context::get_context();

	//gtt��Ԫ��ʼ������
	gtt_initialize();

	//tmc��Ԫ��ʼ������
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

