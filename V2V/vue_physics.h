#pragma once

#include<vector>
#include<random>
#include<list>

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
	* 车辆总数
	*/
	static int s_vue_count;

	/*
	* 车辆之间的小尺度衰落
	* 前两层下标为车辆id，例如s_channel_all[i][j],且i<j
	*/
	static std::vector<std::vector<double*>> s_channel_all;

	/*
	* 车辆之间的大尺度衰落
	* 前两层下标为车辆id，例如s_pl_all[i][j],且i<j
	*/
	static std::vector<std::vector<double>> s_pl_all;

public:
	/*
	* 取车辆i,j之间的小尺度衰落
	*/
	static double* get_channel(int i, int j);

	/*
	* 存车辆i,j之间的小尺度衰落
	*/
	static void set_channel(int i, int j, double*);

	/*
	* 取车辆i,j之间的大尺度衰落
	*/
	static double get_pl(int i, int j);

	/*
	* 存车辆i,j之间的大尺度衰落
	*/
	static void set_pl(int i, int j, double);
	/*
	* 产生车辆i,j之间的信道
	*/
	static void channel_generator();

	
	/*------------------私有字段------------------*/
public:
	/*
	* 车辆编号
	*/
	double m_id = s_vue_count++;

	/*
	* 车速，km/h
	*/
	double m_speed = 0;

	/*
	* 速度方向,0代表向东，180代表向西
	*/
	double m_vangle = 0;

	/*
	* 绝对横坐标，单位m
	*/
	double m_absx = 0;

	/*
	* 绝对纵坐标，单位m
	*/
	double m_absy = 0;

	/*
	*相对横坐标，单位m
	*/
	double m_relx = 0;

	/*
	* 相对纵坐标，单位m
	*/
	double m_rely = 0;
	/*----------------访问与编辑器----------------*/
public:

	/*--------------------方法--------------------*/
public:
	void update_location();
};