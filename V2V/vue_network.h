#pragma once


class vue_network {
	/*------------------友元声明------------------*/
	/*
	* 将vue设为vue_network的友元，由于vue_network的构造函数设为私有，但可由vue来调用
	*/
	friend class vue;

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
};