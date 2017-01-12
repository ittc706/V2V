#pragma once

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
public:
	/*
	* 道路数量
	*/
	const int m_road_num = 6;

	/*
	* 路长,单位m
	*/
	double m_road_length = 3464;

	/*
	* 路宽，单位m
	*/
	double m_road_width = 4;

	/*
	* 车速,km/h
	*/
	double m_speed = 140;

	/*
	* 道路拓扑位置
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
	* 车辆位置刷新时间,单位s
	*/
	double m_freshtime = 0.1;

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