#pragma once


class gtt {
public:
	virtual void drop_vue() = 0;

	virtual double get_freshtime() = 0;

	virtual double get_road_length() = 0;

	virtual int get_vue_num() = 0;
};