#pragma once


class vue_physics {
	/*------------------友元声明------------------*/
	/*
	* 将vue设为vue_physics的友元，由于vue_physics的构造函数设为私有，但可由vue来调用
	*/
	friend class vue;

	/*----------------拷贝控制成员----------------*/
private:
	/*
	* 默认构造函数
	* 设为私有，其初始化完全交给vue来完成，禁止生成该类型的实例
	*/
	vue_physics();

	/*------------------私有字段------------------*/
private:
	/*
	* 车速
	*/
	double m_speed = 0;

	/*
	* 横坐标
	*/
	double m_x = 0;

	/*
	* 纵坐标
	*/
	double m_y = 0;

	/*----------------访问与编辑器----------------*/
public:
	
};