#pragma once


enum event_type {
	PERIOD
};


class v2v_event {
	/*------------------静态成员------------------*/
private:
	static int s_event_count;

	/*----------------拷贝控制成员----------------*/
public:
	/*
	* 默认构造函数
	*/
	v2v_event();

	/*
	* 析构函数，负责清理资源
	*/
	~v2v_event();

	/*
	* 将拷贝构造函数定义为删除
	*/
	v2v_event(const v2v_event& t_v2v_event) = delete;

	/*
	* 将移动构造函数定义为删除
	*/
	v2v_event(v2v_event&& t_v2v_event) = delete;

	/*
	* 将拷贝赋值运算符定义为删除
	*/
	v2v_event& operator=(const v2v_event& t_v2v_event) = delete;

	/*
	* 将移动赋值运算符定义为删除
	*/
	v2v_event& operator=(v2v_event&& t_v2v_event) = delete;
	
	/*--------------------字段--------------------*/
private:
	int m_send_delay = 0;

	int get_send_delay();

	/*--------------------方法--------------------*/

	void increase_send_delay();
};