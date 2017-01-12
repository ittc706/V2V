#pragma once

#include"gtt.h"

class gtt_highspeed:public gtt{
public:

	/*
	* ��·����
	*/
	const int m_road_num = 6;

	/*
	* ·��,��λm
	*/
	double m_road_length = 3464;

	/*
	* ·����λm
	*/
	double m_road_width=4;

	/*
	* ����,km/h
	*/
	double m_speed = 140;

	/*
	* ��·����λ��
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
	* ����λ��ˢ��ʱ��,��λs
	*/
	double m_freshtime=0.1;

public:
	void drop_vue() override;

	double get_freshtime() override;

	double get_road_length() override;

};