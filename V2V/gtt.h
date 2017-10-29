#pragma once

#include<string>
#include<fstream>
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

protected:
	std::ofstream distance_pl;
	std::ofstream distance_los;
	std::ofstream distance_nlos;

	/*--------------------�ӿ�--------------------*/

public:
	gtt();
	~gtt();

	virtual void initialize() = 0;

	virtual int get_vue_num() = 0;

	/*
	* ���ڸ��³���λ��
	*/
	virtual void fresh_location() = 0;

	/*
	* ���ڼ���ָ���ŵ���Ӧ����
	*/
	virtual void calculate_pl(int t_vue_id1, int t_vue_id2) = 0;
};