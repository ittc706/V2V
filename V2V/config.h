#pragma once

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
public:
	/*
	* ��·����
	*/
	const int m_road_num = 6;

	/*
	* ·��,��λm
	*/
	double m_road_length = 3464;

	/*
	* ·����λm
	*/
	double m_road_width = 4;

	/*
	* ����,km/h
	*/
	double m_speed = 140;

	/*
	* ��·����λ��
	*/
	const double m_road_topo_ratio[6 * 2]{
		0.0f, -2.5f,
		0.0f, -1.5f,
		0.0f, -0.5f,
		0.0f, 0.5f,
		0.0f, 1.5f,
		0.0f, 2.5f,
	};

	/*
	* ����λ��ˢ��ʱ��,��λs
	*/
	double m_freshtime = 0.1;

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