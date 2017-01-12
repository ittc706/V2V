#pragma once
#include<vector>
#include<list>

class config_loader;
class global_control_config;
class gtt_config;
class tmc_config;
class gtt;
class tmc;
class wt;
class vue;
class v2v_event;

class context {
	/*------------------友元声明------------------*/
	/*
	* 将system_control设为context的友元，提供其构造容器类唯一实例的权限
	*/
	friend class system_control;
	friend class gtt_highspeed;
	friend class tmc;
	/*------------------静态成员字段------------------*/
private:
	/*
	* 单例模式下，唯一实体的指针
	*/
	static context* s_singleton_context;

public:
	/*
	* 单例模式下，获取唯一实体的指针
	*/
	static context* get_context();

private:
	/*
	* 单例模式下，设置唯一实体的指针
	*/
	static void set_context(context* t_singleton_context);

private:
	/*
	* 单例模式下，生成唯一实体
	*/
	static void context_factory();

	/*----------------拷贝控制成员----------------*/
private:
	/*
	* 默认构造函数
	*/
	context();

public:
	/*
	* 析构函数，负责清理资源
	*/
	~context();

	/*
	* 将拷贝构造函数定义为删除
	*/
	context(const context& t_context) = delete;

	/*
	* 将移动构造函数定义为删除
	*/
	context(context&& t_context) = delete;

	/*
	* 将拷贝赋值运算符定义为删除
	*/
	context& operator=(const context& t_context) = delete;

	/*
	* 将移动赋值运算符定义为删除
	*/
	context& operator=(context&& t_context) = delete;

	/*------------------容器成员------------------*/
	/*
	* 配置文件加载对象、编辑器、访问器
	*/
private:
	config_loader* m_config_loader = nullptr;
	void set_config_loader(config_loader* t_config_loader);
public:
	config_loader* get_config_loader();

	/*
	* 全局控制配置参数对象
	*/
private:
	global_control_config* m_global_control_config = nullptr;
	void set_global_control_config(global_control_config* t_global_control_config);
public:
	global_control_config* get_global_control_config();

	/*
	* 地理拓扑与传播单元配置对象
	*/
private:
	gtt_config* m_gtt_config = nullptr;
	void set_gtt_config(gtt_config* t_gtt_config);
public:
	gtt_config* get_gtt_config();

	/*
	* 业务模型与控制单元配置对象
	*/
private:
	tmc_config* m_tmc_config = nullptr;
	void set_tmc_config(tmc_config* t_tmc_config);
public:
	tmc_config* get_tmc_config();

	/*
	* tti,仿真时刻
	*/
private:
	int m_tti = 0;
public:
	void increase_tti();
	int get_tti();

	/*
	* 场景类实体指针
	*/
private:
	gtt* m_gtt = nullptr;
	void set_gtt(gtt* t_gtt);
public:
	gtt* get_gtt();

	/*
	* tmc类实体指针
	*/
private:
	tmc* m_tmc = nullptr;
	void set_tmc(tmc* t_tmc);
public:
	tmc* get_tmc();

	/*
	* wt对象，为非单例模式，可以请求数个wt类型的对象
	*/
private:
	void wt_initialize();
public:
	wt* get_wt();

	/*
	* 车辆类数组指针
	*/
private:
	vue* m_vue_array = nullptr;
	void set_vue_array(vue* t_vue_array);
public:
	vue* get_vue_array();

	/*
	* 事件类数组
	*/
private:
	std::vector<v2v_event*> m_event_array;
	void event_array_initialize();
public:
	std::vector<v2v_event*>& get_event_array();

	/*
	* tti事件数组，
	* 外层下标代表tti时刻
	*/
private:
	std::vector<std::list<int>> m_tti_event_list;
	void initialize_tti_event_list();
public:
	std::vector<std::list<int>>& get_tti_event_list();

	/*--------------------实现--------------------*/
private:
	/*
	* 为容器的成员注入依赖项，并执行相应的初始化动作
	*/
	void dependency_injecte();
};

