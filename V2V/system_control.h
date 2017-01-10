#pragma once

class vue;

class system_control {
	/*------------------私有字段------------------*/
private:
	vue* m_vue_array = nullptr;

	/*----------------拷贝控制成员----------------*/
public:
	/*
	* 默认构造函数，控制三层实体指针的初始化
	*/
	system_control();

	/*
	* 析构函数，负责清理资源
	*/
	~system_control();

	/*
	* 将拷贝构造函数定义为删除
	*/
	system_control(const system_control& t_system_control) = delete;

	/*
	* 将移动构造函数定义为删除
	*/
	system_control(system_control&& t_system_control) = delete;

	/*
	* 将拷贝赋值运算符定义为删除
	*/
	system_control& operator=(const system_control& t_system_control) = delete;

	/*
	* 将移动赋值运算符定义为删除
	*/
	system_control& operator=(system_control&& t_system_control) = delete;
};