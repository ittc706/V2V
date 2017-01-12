#pragma once

#include<vector>
#include<random>
#include<list>

class vue_physics {
	/*------------------��Ԫ����------------------*/
	/*
	* ��vue��Ϊvue_physics����Ԫ������vue_physics�Ĺ��캯����Ϊ˽�У�������vue������
	*/
	friend class vue;

	/*----------------�������Ƴ�Ա----------------*/
private:
	/*
	* Ĭ�Ϲ��캯��
	* ��Ϊ˽�У����ʼ����ȫ����vue����ɣ���ֹ���ɸ����͵�ʵ��
	*/
	vue_physics();

public:
	/*
	* ��������������������Դ
	*/
	~vue_physics();

	/*
	* ���������캯������Ϊɾ��
	*/
	vue_physics(const vue_physics& t_vue_physics) = delete;

	/*
	* ���ƶ����캯������Ϊɾ��
	*/
	vue_physics(vue_physics&& t_vue_physics) = delete;

	/*
	* ��������ֵ���������Ϊɾ��
	*/
	vue_physics& operator=(const vue_physics& t_vue_physics) = delete;

	/*
	* ���ƶ���ֵ���������Ϊɾ��
	*/
	vue_physics& operator=(vue_physics&& t_vue_physics) = delete;

	/*------------------��̬��Ա------------------*/
private:
	/*
	* ��������
	*/
	static int s_vue_count;

	/*
	* ����֮���С�߶�˥��
	* ǰ�����±�Ϊ����id������s_channel_all[i][j],��i<j
	*/
	static std::vector<std::vector<double*>> s_channel_all;

	/*
	* ����֮��Ĵ�߶�˥��
	* ǰ�����±�Ϊ����id������s_pl_all[i][j],��i<j
	*/
	static std::vector<std::vector<double>> s_pl_all;

public:
	/*
	* ȡ����i,j֮���С�߶�˥��
	*/
	static double* get_channel(int i, int j);

	/*
	* �泵��i,j֮���С�߶�˥��
	*/
	static void set_channel(int i, int j, double*);

	/*
	* ȡ����i,j֮��Ĵ�߶�˥��
	*/
	static double get_pl(int i, int j);

	/*
	* �泵��i,j֮��Ĵ�߶�˥��
	*/
	static void set_pl(int i, int j, double);
	/*
	* ��������i,j֮����ŵ�
	*/
	static void channel_generator();

	
	/*------------------˽���ֶ�------------------*/
public:
	/*
	* �������
	*/
	double m_id = s_vue_count++;

	/*
	* ���٣�km/h
	*/
	double m_speed = 0;

	/*
	* �ٶȷ���,0�����򶫣�180��������
	*/
	double m_vangle = 0;

	/*
	* ���Ժ����꣬��λm
	*/
	double m_absx = 0;

	/*
	* ���������꣬��λm
	*/
	double m_absy = 0;

	/*
	*��Ժ����꣬��λm
	*/
	double m_relx = 0;

	/*
	* ��������꣬��λm
	*/
	double m_rely = 0;
	/*----------------������༭��----------------*/
public:

	/*--------------------����--------------------*/
public:
	void update_location();
};