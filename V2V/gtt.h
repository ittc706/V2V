#pragma once

class gtt_config;

class gtt {
	/*------------------��Ԫ����------------------*/
	/*
	* ��context��Ϊ��Ԫ������ҪΪ��ע��������
	*/
	friend class context;

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

	virtual void drop_vue() = 0;

	virtual double get_freshtime() = 0;

	virtual double get_road_length() = 0;

	virtual int get_vue_num() = 0;
};