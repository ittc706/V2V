#pragma once

#include<string>
#include<fstream>
#include<utility>
#include"enumeration.h"

class gtt_config;

class gtt {
	/*------------------友元声明------------------*/
	/*
	* 将context设为友元，容器要为其注入依赖项
	*/
	friend class context;

	/*--------------------静态--------------------*/
public:
	/*
	* 根据gtt模式来生成gtt组件对象
	*/
	static gtt* gtt_bind_by_mode(gtt_mode t_mode);

	/*--------------------字段--------------------*/
	/*
	* 场景配置参数对象
	*/
private:
	gtt_config* m_config;
	void set_config(gtt_config* t_config);
public:
	gtt_config* get_config();

protected:
	std::ofstream distance_pl;
	std::ofstream distance_los;
	std::ofstream distance_nlos;
	std::ofstream time_slot_0;
	std::ofstream time_slot_1;
	std::ofstream time_slot_2;
	std::ofstream time_slot_3;
	std::ofstream center_coordinate;
	std::ofstream building_coordinate;

	/*--------------------接口--------------------*/

public:
	gtt();
	~gtt();

	virtual void initialize() = 0;

	virtual int get_vue_num() = 0;

	/*
	* 用于更新车辆位置
	*/
	virtual void fresh_location() = 0;

	/*
	* 用于计算指定信道响应矩阵
	*/
	virtual void calculate_pl(int t_vue_id1, int t_vue_id2) = 0;

	/*
	* 判断两条线段是否相交
	*/
	bool is_interact(std::pair<double, double> p1, std::pair<double, double> p2, std::pair<double, double> p3, std::pair<double, double> p4);
};