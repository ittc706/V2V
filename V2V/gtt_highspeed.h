#pragma once

#include"gtt.h"

class gtt_highspeed:public gtt{
public:

	/*
	* 道路数量
	*/
	const int m_road_num = 6;

	/*
	* 路长,单位m
	*/
	double m_road_length = 3464;

	/*
	* 路宽，单位m
	*/
	double m_road_width=4;

	/*
	* 车速,km/h
	*/
	double m_speed = 140;

	/*
	* 道路拓扑位置
	*/
	const double m_road_topo_ratio[6 * 2]{
		0.0f, -2.5f,
		0.0f, -1.5f,
		0.0f, -0.5f,
		0.0f, 0.5f,
		0.0f, 1.5f,
		0.0f, 2.5f,
	};

	/*
	* 车辆位置刷新时间,单位s
	*/
	double m_freshtime=0.1;

public:
	void drop_vue() override;

	double get_freshtime() override;

	double get_road_length() override;

};