#pragma once

#include<string>
#include"enumeration.h"

class gtt_config;

class gtt {
	/*------------------��Ԫ����------------------*/
	/*
	* ��context��Ϊ��Ԫ������ҪΪ��ע��������
	*/
	friend class context;

	/*--------------------��̬--------------------*/
public:
	/*
	* ����gttģʽ������gtt�������
	*/
	static gtt* gtt_bind_by_mode(gtt_mode t_mode);

	/*--------------------�ֶ�--------------------*/
	/*
	* �������ò�������
	*/
private:
	gtt_config* m_config;
	void set_config(gtt_config* t_config);
public:
	gtt_config* get_config();

	/*--------------------�ӿ�--------------------*/

	virtual void initialize() = 0;

	virtual int get_vue_num() = 0;

	virtual void update_channel() = 0;
};