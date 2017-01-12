#pragma once

enum platform{
	Windows,
	Linux
};

class config_loader;

class global_control_config {
	/*------------------友元声明------------------*/
	/*
	* 将context设为友元，容器要为其注入依赖项
	*/
	friend class context;

	/*--------------------字段--------------------*/
	/*
	* 类加载器对象
	*/
private:
	config_loader* m_config_loader;
	void set_config_loader(config_loader* t_config_loader);
public:
	config_loader* get_config_loader();

	/*
	* 平台
	*/
private:
	platform m_platform;
	void set_platform(platform t_platform);
public:
	platform get_platform();
	
	/*
	* 平台
	*/
private:
	int m_ntti;
	void set_ntti(int t_ntti);
public:
	int get_ntti();

	/*--------------------接口--------------------*/
public:
	void load();
};


class gtt_config {
	/*------------------友元声明------------------*/
	/*
	* 将context设为友元，容器要为其注入依赖项
	*/
	friend class context;

	/*--------------------字段--------------------*/
	/*
	* 类加载器对象
	*/
private:
	config_loader* m_config_loader;
	void set_config_loader(config_loader* t_config_loader);
public:
	config_loader* get_config_loader();

	/*--------------------接口--------------------*/
public:
	virtual void load() = 0;
};


class gtt_highspeed_config :public gtt_config {
	/*--------------------字段--------------------*/
	/*
	* 道路数量
	*/
private:
	const int m_road_num = 6;
public:
	int get_road_num();

	/*
	* 路长,单位m
	*/
private:
	double m_road_length = 3464;
	void set_road_length(double t_road_length);
public:
	double get_road_length();

	/*
	* 路宽，单位m
	*/
private:
	double m_road_width = 4;
	void set_road_width(double t_road_width);
public:
	double get_road_width();

	/*
	* 车速,km/h
	*/
private:
	double m_speed = 140;
	void set_speed(double t_speed);
public:
	double get_speed();

	/*
	* 道路拓扑位置
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
	* 车辆位置刷新时间,单位s
	*/
private:
	double m_freshtime = 0.1;
	void set_freshtime(double t_freshtime);
public:
	double get_freshtime();

	/*--------------------接口--------------------*/
public:
	void load() override;
};


class gtt_urban_config :public gtt_config {
	/*--------------------接口--------------------*/
public:
	void load() override;
};


class tmc_config {
	/*------------------友元声明------------------*/
	/*
	* 将context设为友元，容器要为其注入依赖项
	*/
	friend class context;

	/*--------------------字段--------------------*/
	/*
	* 类加载器对象
	*/
private:
	config_loader* m_config_loader;
	void set_config_loader(config_loader* t_config_loader);
public:
	config_loader* get_config_loader();

	/*--------------------接口--------------------*/
public:
	void load();
};