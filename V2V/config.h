#pragma once

#include<vector>

#define INVALID -1

enum platform{
	Windows,
	Linux
};

class config_loader;

class global_control_config {
	/*------------------��Ԫ����------------------*/
	/*
	* ��context��Ϊ��Ԫ������ҪΪ��ע��������
	*/
	friend class context;

	/*--------------------�ֶ�--------------------*/
	/*
	* �����������
	*/
private:
	config_loader* m_config_loader;
	void set_config_loader(config_loader* t_config_loader);
public:
	config_loader* get_config_loader();

	/*
	* ƽ̨
	*/
private:
	platform m_platform;
	void set_platform(platform t_platform);
public:
	platform get_platform();
	
	/*
	* ����ʱ��
	*/
private:
	int m_ntti;
	void set_ntti(int t_ntti);
public:
	int get_ntti();

	/*
	* �ŵ�ˢ������
	*/
private:
	int m_fresh_period;
	void set_fresh_period(int t_fresh_period);
public:
	int get_fresh_period();

	/*--------------------�ӿ�--------------------*/
public:
	void load();
};


class gtt_config {
	/*------------------��Ԫ����------------------*/
	/*
	* ��context��Ϊ��Ԫ������ҪΪ��ע��������
	*/
	friend class context;

	/*--------------------�ֶ�--------------------*/
	/*
	* �����������
	*/
private:
	config_loader* m_config_loader;
	void set_config_loader(config_loader* t_config_loader);
public:
	config_loader* get_config_loader();

	/*--------------------�ӿ�--------------------*/
public:
	virtual void load() = 0;
};


class gtt_highspeed_config :public gtt_config {
	/*--------------------�ֶ�--------------------*/
	/*
	* ��·����
	*/
private:
	const int m_road_num = 6;
public:
	int get_road_num();

	/*
	* ·��,��λm
	*/
private:
	double m_road_length = INVALID;
	void set_road_length(double t_road_length);
public:
	double get_road_length();

	/*
	* ·����λm
	*/
private:
	double m_road_width = INVALID;
	void set_road_width(double t_road_width);
public:
	double get_road_width();

	/*
	* ����,km/h
	*/
private:
	double m_speed = INVALID;
	void set_speed(double t_speed);
public:
	double get_speed();

	/*
	* ��·����λ��
	*/
private:
	const double m_road_topo_ratio[6 * 2]{
		0.0f, -2.5f,
		0.0f, -1.5f,
		0.0f, -0.5f,
		0.0f, 0.5f,
		0.0f, 1.5f,
		0.0f, 2.5f,
	};
public:
	const double* get_road_topo_ratio();

	/*
	* ����λ��ˢ��ʱ��,��λs
	*/
private:
	double m_freshtime = INVALID;
	void set_freshtime(double t_freshtime);
public:
	double get_freshtime();

	/*--------------------�ӿ�--------------------*/
public:
	void load() override;

};


class gtt_urban_config :public gtt_config {
	/*--------------------�ӿ�--------------------*/
public:
	void load() override;
	/*
	* ��������
	*/
private:
	const int m_road_num = 14;
public:
	int get_road_num();

	/*
	* ·������Ϊ��������ϱ���,��λm
	*/
private:
	double m_road_length_ew = INVALID;
	double m_road_length_sn = INVALID;
	void set_road_length_ew(double t_road_length_ew);
	void set_road_length_sn(double t_road_length_sn);
public:
	double get_road_length_ew();
	double get_road_length_sn();

	/*
	* ·����λm
	*/
private:
	double m_road_width = INVALID;
	void set_road_width(double t_road_width);
public:
	double get_road_width();

	/*
	* ����,km/h
	*/
private:
	double m_speed = INVALID;
	void set_speed(double t_speed);
public:
	double get_speed();

	/*
	* ��·����λ��
	*/
private:
	const double m_road_topo_ratio[14 * 2] = {
		-1.5f, 1.0f,
		-0.5f, 1.0f,
		0.5f, 1.0f,
		1.5f, 1.0f,
		-2.5f, 0.0f,
		-1.5f, 0.0f,
		-0.5f, 0.0f,
		0.5f, 0.0f,
		1.5f, 0.0f,
		2.5f, 0.0f,
		-1.5f,-1.0f,
		-0.5f,-1.0f,
		0.5f,-1.0f,
		1.5f,-1.0f
	};

private:
	const int m_wrap_around_road[14][9] = {
		{ 0,1,6,5,4,13,8,9,10 },
		{ 1,2,7,6,5,0,9,10,11 },
		{ 2,3,8,7,6,1,10,11,12 },
		{ 3,4,9,8,7,2,11,12,13 },
		{ 4,5,10,9,8,3,12,13,0 },
		{ 5,6,11,10,9,4,13,0,1 },
		{ 6,7,12,11,10,5,0,1,2 },
		{ 7,8,13,12,11,6,1,2,3 },
		{ 8,9,0,13,12,7,2,3,4 },
		{ 9,10,1,0,13,8,3,4,5 },
		{ 10,11,2,1,0,9,4,5,6 },
		{ 11,12,3,2,1,10,5,6,7 },
		{ 12,13,4,3,2,11,6,7,8 },
		{ 13,0,5,4,3,12,7,8,9 }
	};

public:
	const double* get_road_topo_ratio();
	const int(*get_wrap_around_road())[9];
	/*
	* ����λ��ˢ��ʱ��,��λs
	*/
private:
	double m_freshtime = INVALID;
	void set_freshtime(double t_freshtime);
public:
	double get_freshtime();

};


class rrm_config {
	/*------------------��Ԫ����------------------*/
	/*
	* ��context��Ϊ��Ԫ������ҪΪ��ע��������
	*/
	friend class context;

	/*------------------��̬��Ա------------------*/
public:
	/*
	* ÿ��RB�Ĵ���(Hz)
	*/
	static const int s_BANDWIDTH_OF_RB = 12 * 1000 * 15;

	/*
	* ��λ(��),����RB����Ϊ180kHz��TTIΪ1ms����˵�λTTI��λRB����ı�����Ϊ180k*1ms=180
	*/
	static const int s_BIT_NUM_PER_RB = 180;

	/*--------------------�ֶ�--------------------*/
	/*
	* �����������
	*/
private:
	config_loader* m_config_loader;
	void set_config_loader(config_loader* t_config_loader);
public:
	config_loader* get_config_loader();

	/*
	* �ܴ���
	*/
private:
	int m_total_bandwidth;
	void set_total_bandwidth(int t_total_bandwidth);
public:
	int get_total_bandwidth();

	/*
	* һ��������Դ���rb����
	*/
private:
	int m_rb_num_per_pattern;
	void set_rb_num_per_pattern(int t_rb_num_per_pattern);
public:
	int get_rb_num_per_pattern();

	/*
	* pattern����
	*/
private:
	int m_pattern_num;
	void set_pattern_num();
public:
	int get_pattern_num();


	/*
	* ���Ʒ�ʽ
	* 2:QOSK
	* 4:16QAM
	* 6:64QAM
	*/
private:
	int m_modulation_type;
	void set_modulation_type(int t_modulation_type);
public:
	int get_modulation_type();

	/*
	* �ŵ���������
	*/
private:
	double m_code_rate;
	void set_code_rate(double t_code_rate);
public:
	double get_code_rate();

	/*
	* �����ٽ�sinr
	*/
private:
	double m_drop_sinr_boundary;
	void set_drop_sinr_boundary(double t_drop_sinr_boundary);
public:
	double get_drop_sinr_boundary();
	/*--------------------�ӿ�--------------------*/
public:
	void load();
};


class tmc_config {
	/*------------------��Ԫ����------------------*/
	/*
	* ��context��Ϊ��Ԫ������ҪΪ��ע��������
	*/
	friend class context;

	/*--------------------�ֶ�--------------------*/
	/*
	* �����������
	*/
private:
	config_loader* m_config_loader;
	void set_config_loader(config_loader* t_config_loader);
public:
	config_loader* get_config_loader();

	/*
	* ӵ���ȼ�����
	*/
private:
	int m_congestion_level_num;
	void set_congestion_level_num(int t_congestion_level_num);
public:
	int get_congestion_level_num();

	/*
	* ��Ӧӵ���ȼ��������¼�����
	*/
private:
	std::vector<int> m_periodic_event_period;
public:
	const std::vector<int>& get_periodic_event_period();

	/*
	* �����¼�����
	*/
private:
	int m_package_num;
	void set_package_num(int t_package_num);
public:
	int get_package_num();

	/*
	* �����¼�ÿ������Ӧ��bit����
	*/
private:
	std::vector<int> m_bit_num_per_package;
public:
	const std::vector<int>& get_bit_num_per_package();
	/*--------------------�ӿ�--------------------*/
public:
	void load();
};