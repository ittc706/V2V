#pragma once

#include<vector>

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

public:
	/*
	* 析构函数，负责清理资源
	*/
	~vue_physics();

	/*
	* 将拷贝构造函数定义为删除
	*/
	vue_physics(const vue_physics& t_vue_physics) = delete;

	/*
	* 将移动构造函数定义为删除
	*/
	vue_physics(vue_physics&& t_vue_physics) = delete;

	/*
	* 将拷贝赋值运算符定义为删除
	*/
	vue_physics& operator=(const vue_physics& t_vue_physics) = delete;

	/*
	* 将移动赋值运算符定义为删除
	*/
	vue_physics& operator=(vue_physics&& t_vue_physics) = delete;

	/*------------------静态成员------------------*/
private:
	/*
	* 车辆计数
	*/
	static int s_vue_count;

	/*
	* 车辆之间的信道
	* 前两层下标为车辆id，例如s_channel_all[i][j],且i<j
	*/
	static std::vector<std::vector<double*>> s_channel_all;

	/*
	* 取车辆ij之间的信道
	*/
	static double* get_channel_all(int i, int j);

	/*
	* 存车辆ij之间的信道
	*/
	static void set_channel_all(int i, int j, double*);

	/*
	* 撒点
	*/
	static void drop_vue();

	/*------------------私有字段------------------*/
private:
	/*
	* 车辆编号
	*/
	double m_id = -1;

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

	/*--------------------方法--------------------*/
public:
	void update_location();
};