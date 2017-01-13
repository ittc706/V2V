#pragma once

#include<random>
#include<vector>

class sender_event;

class vue_network {
	/*------------------友元声明------------------*/
	/*
	* 将vue设为友元，由于vue_network的构造函数设为私有，但可由vue来调用
	*/
	friend class vue;

	/*
	* 将tmc设为vue_link的友元，事件相关的字段需要通过tmc对象来配置
	*/
	friend class tmc;

	/*------------------静态成员------------------*/
private:
	static std::default_random_engine s_engine;

	/*----------------拷贝控制成员----------------*/
private:
	/*
	* 默认构造函数
	* 设为私有，其初始化完全交给vue来完成，禁止生成该类型的实例
	*/
	vue_network();

public:
	/*
	* 析构函数，负责清理资源
	*/
	~vue_network();

	/*
	* 将拷贝构造函数定义为删除
	*/
	vue_network(const vue_network& t_vue_network) = delete;

	/*
	* 将移动构造函数定义为删除
	*/
	vue_network(vue_network&& t_vue_network) = delete;

	/*
	* 将拷贝赋值运算符定义为删除
	*/
	vue_network& operator=(const vue_network& t_vue_network) = delete;

	/*
	* 将移动赋值运算符定义为删除
	*/
	vue_network& operator=(vue_network&& t_vue_network) = delete;

	/*--------------------字段--------------------*/
	/*
	* 指向上层的指针
	*/
private:
	vue* m_superior_level;
	void set_superior_level(vue* t_superior_level);
public:
	vue* get_superior_level();

	/*
	* 周期事件下一次触发时刻
	*/
private:
	std::vector<int> m_periodic_event_next_trigger_tti;
	void set_periodic_event_next_trigger_tti(int t_congestion_level_num);
public:
	const std::vector<int>& get_periodic_event_next_trigger_tti();

	/*
	* 标记是否有待发事件
	*/
private:
	/*
	* 发送事件列表
	*/
	std::list<sender_event*> m_sender_event_list;
	void add_sender_event(sender_event* t_sender_event);

	/*--------------------接口--------------------*/
public:
	void send_connection();

	/*--------------------实现--------------------*/
private:
	/*
	* 选择占用的资源块编号
	*/
	int select_pattern();
};