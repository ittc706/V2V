#pragma once

#include<random>
#include<vector>
#include<list>
#include<set>

class sender_event;

class vue_network {
	/*------------------友元声明------------------*/
	/*
	* 将vue设为友元，由于vue_network的构造函数设为私有，但可由vue来调用
	*/
	friend class vue;

	/*
	* 将tmc设为友元，事件相关的字段需要通过tmc对象来配置
	*/
	friend class tmc;

	/*
	* 将rrm设为友元，事件相关的字段需要通过rrm对象来配置
	*/
	friend class rrm;

	/*
	* 将vue_link设为友元
	*/
	friend class vue_link;

	/*
	* 将sender/receiver_event设为友元
	*/
	friend class sender_event;
	friend class receiver_event;

	/*------------------静态成员------------------*/
private:
	/*
	* 随机数引擎
	*/
	static std::default_random_engine s_engine;

	/*
	* 正在传输的发送事件
	* 外层下标为pattern编号
	*/
	static std::vector<std::set<sender_event*>> s_sender_event_per_pattern;

	static std::vector<std::set<sender_event*>> s_temp_finished_sender_event_per_pattern;

	/*
	* 传输完毕的发送事件集合
	*/
	static std::vector<sender_event*> s_finished_sender_event;

	/*
	* 外层center编号，中层time_slot编号，内层pattern编号
	*/
	static std::vector<std::vector<std::vector<bool>>> s_is_pattern_occupied;

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

private:
	/*
	* 发送事件列表
	*/
	std::list<sender_event*> m_sender_event_list;
	void add_sender_event(sender_event* t_sender_event);

	/*--------------------接口--------------------*/
public:
	/*
	* 收发车辆进行连接(程序意义上的连接)
	*/
	void send_connection();

	/*--------------------实现--------------------*/
private:
	/*
	* 选择占用的资源块编号
	*/
	int select_pattern();

	/*
	* 选择占用的资源块编号
	*/
	int select1();

	/*
	* 监听每个Pattern的功率，选择功率最低的Pattern
	*/
	int select2();

	/*
	* 监听每个Pattern的功率，依据功率大小分配给每个Pattern一个概率，最终随机选择，但是选择的结果与每个Pattern功率大小相关
	*/
	int select3();

	/*
	* 时分方式
	*/
	int select4();
};