#pragma once


enum event_type {
	PERIOD
};


class sender_event {
	/*------------------友元声明------------------*/
	/*
	* 将tmc设为友元，事件相关的字段需要通过tmc对象来配置
	*/
	friend class tmc;
	/*------------------静态成员------------------*/
private:
	static int s_event_count;

	/*----------------拷贝控制成员----------------*/
public:
	/*
	* 默认构造函数
	*/
	sender_event();

	/*
	* 析构函数，负责清理资源
	*/
	~sender_event();

	/*
	* 将拷贝构造函数定义为删除
	*/
	sender_event(const sender_event& t_sender_event) = delete;

	/*
	* 将移动构造函数定义为删除
	*/
	sender_event(sender_event&& t_sender_event) = delete;

	/*
	* 将拷贝赋值运算符定义为删除
	*/
	sender_event& operator=(const sender_event& t_sender_event) = delete;

	/*
	* 将移动赋值运算符定义为删除
	*/
	sender_event& operator=(sender_event&& t_sender_event) = delete;
	
	/*--------------------字段--------------------*/
	/*
	* 事件id
	*/
private:
	int m_event_id = s_event_count++;
public:
	int get_event_id();

	/*
	* 车辆id
	*/
private:
	int m_vue_id;
	void set_vue_id(int t_vue_id);
public:
	int get_vue_id();


	/*--------------------方法--------------------*/
};


class receiver_event {
	/*----------------拷贝控制成员----------------*/
public:
	/*
	* 默认构造函数
	*/
	receiver_event() = delete;

	/*
	* 构造函数
	*/
	receiver_event(sender_event* t_sender_event);

	/*
	* 析构函数，负责清理资源
	*/
	~receiver_event();

	/*
	* 将拷贝构造函数定义为删除
	*/
	receiver_event(const receiver_event& t_receiver_event) = delete;

	/*
	* 将移动构造函数定义为删除
	*/
	receiver_event(receiver_event&& t_receiver_event) = delete;

	/*
	* 将拷贝赋值运算符定义为删除
	*/
	receiver_event& operator=(const receiver_event& t_receiver_event) = delete;

	/*
	* 将移动赋值运算符定义为删除
	*/
	receiver_event& operator=(receiver_event&& t_receiver_event) = delete;

	/*--------------------字段--------------------*/
	/*
	* 事件id，与发送事件相同
	*/
private:
	int m_event_id;
public:
	void set_event_id(int t_event_id);
	int get_event_id();

	/*
	* 发送车辆id
	*/
private:
	int m_from_vue_id;
public:
	void set_from_vue_id(int t_from_vue_id);
	int get_from_vue_id();

	/*
	* 接收车辆id
	*/
private:
	int m_to_vue_id;
public:
	void set_to_vue_id(int t_to_vue_id);
	int get_to_vue_id();
};