#pragma once


class vue_link {
	/*------------------友元声明------------------*/
	/*
	* 将vue设为vue_link的友元，由于vue_link的构造函数设为私有，但可由vue来调用
	*/
	friend class vue;

	/*----------------拷贝控制成员----------------*/
private:
	/*
	* 默认构造函数
	* 设为私有，其初始化完全交给vue来完成，禁止生成该类型的实例
	*/
	vue_link();

public:
	/*
	* 析构函数，负责清理资源
	*/
	~vue_link();

	/*
	* 将拷贝构造函数定义为删除
	*/
	vue_link(const vue_link& t_vue_link) = delete;

	/*
	* 将移动构造函数定义为删除
	*/
	vue_link(vue_link&& t_vue_link) = delete;

	/*
	* 将拷贝赋值运算符定义为删除
	*/
	vue_link& operator=(const vue_link& t_vue_link) = delete;

	/*
	* 将移动赋值运算符定义为删除
	*/
	vue_link& operator=(vue_link&& t_vue_link) = delete;
};