#pragma once

#include<string>
#include<fstream>
#include<utility>
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
	std::ofstream time_slot_0;
	std::ofstream time_slot_1;
	std::ofstream time_slot_2;
	std::ofstream time_slot_3;
	std::ofstream center_coordinate;

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

	/*
	* �ж������߶��Ƿ��ཻ
	*/
	bool is_interact(std::pair<double, double> p1, std::pair<double, double> p2, std::pair<double, double> p3, std::pair<double, double> p4);
};