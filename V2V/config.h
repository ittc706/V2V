#pragma once

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
	* ƽ̨
	*/
private:
	int m_ntti;
	void set_ntti(int t_ntti);
public:
	int get_ntti();

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
	double m_road_length = 3464;
	void set_road_length(double t_road_length);
public:
	double get_road_length();

	/*
	* ·����λm
	*/
private:
	double m_road_width = 4;
	void set_road_width(double t_road_width);
public:
	double get_road_width();

	/*
	* ����,km/h
	*/
private:
	double m_speed = 140;
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
	double m_freshtime = 0.1;
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

	/*--------------------�ӿ�--------------------*/
public:
	void load();
};