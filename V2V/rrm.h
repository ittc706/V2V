#pragma once

#include<fstream>

class rrm_config;

class rrm {
	/*------------------��Ԫ����------------------*/
	/*
	* ��context��Ϊ��Ԫ������ҪΪ��ע��������
	*/
	friend class context;

	/*------------------��̬��Ա------------------*/


	/*----------------�������Ƴ�Ա----------------*/
public:
	/*
	* Ĭ�Ϲ��캯��
	*/
	rrm();

	/*
	* ��������������������Դ
	*/
	~rrm();

	/*
	* ���������캯������Ϊɾ��
	*/
	rrm(const rrm& t_rrm) = delete;

	/*
	* ���ƶ����캯������Ϊɾ��
	*/
	rrm(rrm&& t_rrm) = delete;

	/*
	* ��������ֵ���������Ϊɾ��
	*/
	rrm& operator=(const rrm& t_rrm) = delete;

	/*
	* ���ƶ���ֵ���������Ϊɾ��
	*/
	rrm& operator=(rrm&& t_rrm) = delete;

	/*--------------------�ֶ�--------------------*/
	/*
	* �������ò�������
	*/
private:
	rrm_config* m_config;
	void set_config(rrm_config* t_config);
public:
	rrm_config* get_config();

	std::ofstream pattern_vue_coordinate;

	/*--------------------����--------------------*/
public:
	/*
	* ��ʼ������
	*/
	void initialize();

	/*
	* ����
	*/
	void schedule();
};