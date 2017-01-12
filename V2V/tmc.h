#pragma once


class tmc {
	/*------------------友元声明------------------*/

	/*------------------静态成员------------------*/


	/*----------------拷贝控制成员----------------*/
public:
	/*
	* 默认构造函数
	*/
	tmc();

	/*
	* 析构函数，负责清理资源
	*/
	~tmc();

	/*
	* 将拷贝构造函数定义为删除
	*/
	tmc(const tmc& t_tmc) = delete;

	/*
	* 将移动构造函数定义为删除
	*/
	tmc(tmc&& t_tmc) = delete;

	/*
	* 将拷贝赋值运算符定义为删除
	*/
	tmc& operator=(const tmc& t_tmc) = delete;

	/*
	* 将移动赋值运算符定义为删除
	*/
	tmc& operator=(tmc&& t_tmc) = delete;

	/*--------------------字段--------------------*/
	/*
	* 周期事件周期、编辑器、访问器
	*/
private:
	int m_period_of_period_event;
	void set_period_of_period_event(int t_period_of_period_event);
public:
	int get_period_of_period_event();

	/*--------------------方法--------------------*/
public:
	/*
	* 初始化工作，为每一个车辆类实体配置参数
	*/
	void preparate();

	/*
	* 事件触发，负责调用每辆车的同名方法，并维护容器context中的事件成员
	*/
	void event_trigger();
};