/*
* =====================================================================================
*
*       Filename:  config.cpp
*
*    Description:  配置文件类
*
*        Version:  1.0
*        Created:
*       Revision:
*       Compiler:  VS_2015
*
*         Author:  HCF
*            LIB:  ITTC
*
* =====================================================================================
*/

#include<iostream>
#include<fstream>
#include<sstream>
#include"config.h"
#include"context.h"
#include"config_loader.h"

using namespace std;

void global_control_config::set_config_loader(config_loader* t_config_loader) {
	m_config_loader = t_config_loader;
}

config_loader* global_control_config::get_config_loader() {
	return m_config_loader;
}

void global_control_config::set_platform(platform t_platform) {
	m_platform = t_platform;
}

platform global_control_config::get_platform() {
	return m_platform;
}

void global_control_config::set_ntti(int t_ntti) {
	m_ntti = t_ntti;
}

int global_control_config::get_ntti() {
	return m_ntti;
}

void global_control_config::load() {
	//首先先判断当前的平台，利用路径的表示在两个平台下的差异来判断
	ifstream inPlatformWindows("config\\global_control_config.xml"),
		inPlatformLinux("config/global_control_config.xml");

	if (inPlatformWindows.is_open()) {
		set_platform(Windows);
		cout << "您当前的平台为：Windows" << endl;
	}
	else if (inPlatformLinux.is_open()) {
		set_platform(Linux);
		cout << "您当前的平台为：Linux" << endl;
	}
	else
		throw logic_error("PlatformError");


	//开始解析配置文件
	switch (get_platform()) {
	case Windows:
		get_config_loader()->resolv_config_file("config\\global_control_config.xml");
		break;
	case Linux:
		get_config_loader()->resolv_config_file("config/global_control_config.xml");
		break;
	default:
		throw logic_error("Platform Config Error!");
	}

	stringstream ss;

	const string nullString("");
	string temp;

	if ((temp = get_config_loader()->get_param("ntti")) != nullString) {
		ss << temp;
		int t_ntti;
		ss >> t_ntti;
		set_ntti(t_ntti);
		ss.clear();//清除标志位
		ss.str("");
	}
	else
		throw logic_error("ConfigLoaderError");

	cout << "ntti: " << get_ntti() << endl;
}

void gtt_config::set_config_loader(config_loader* t_config_loader) {
	m_config_loader = t_config_loader;
}

config_loader* gtt_config::get_config_loader() {
	return m_config_loader;
}

int gtt_highspeed_config::get_road_num() {
	return m_road_num;
}

void gtt_highspeed_config::set_road_length(double t_road_length) {
	m_road_length = t_road_length;
}

double gtt_highspeed_config::get_road_length() {
	return m_road_length;
}

void gtt_highspeed_config::set_road_width(double t_road_width) {
	m_road_width = t_road_width;
}

double gtt_highspeed_config::get_road_width() {
	return m_road_width;
}

void gtt_highspeed_config::set_speed(double t_speed) {
	m_speed = t_speed;
}

double gtt_highspeed_config::get_speed() {
	return m_speed;
}

const double* gtt_highspeed_config::get_road_topo_ratio() {
	return m_road_topo_ratio;
}

void gtt_highspeed_config::set_freshtime(double t_freshtime) {
	m_freshtime = t_freshtime;
}

double gtt_highspeed_config::get_freshtime() {
	return m_freshtime;
}

void gtt_highspeed_config::load() {

	//开始解析系统配置文件
	switch (context::get_context()->get_global_control_config()->get_platform()) {
	case Windows:
		get_config_loader()->resolv_config_file("config\\gtt_highspeed_config.xml");
		break;
	case Linux:
		get_config_loader()->resolv_config_file("config/gtt_highspeed_config.xml");
		break;
	default:
		throw logic_error("Platform Config Error!");
	}

	stringstream ss;

	const string nullString("");
	string temp;

	if ((temp = get_config_loader()->get_param("road_length")) != nullString) {
		ss << temp;
		double t_road_length;
		ss >> t_road_length;
		set_road_length(t_road_length);
		ss.clear();//清除标志位
		ss.str("");
	}
	else
		throw logic_error("ConfigLoaderError");


	if ((temp = get_config_loader()->get_param("road_width")) != nullString) {
		ss << temp;
		double t_road_width;
		ss >> t_road_width;
		set_road_width(t_road_width);
		ss.clear();//清除标志位
		ss.str("");
	}
	else
		throw logic_error("ConfigLoaderError");

	if ((temp = get_config_loader()->get_param("speed")) != nullString) {
		ss << temp;
		double t_speed;
		ss >> t_speed;
		set_speed(t_speed);
		ss.clear();//清除标志位
		ss.str("");
	}
	else
		throw logic_error("ConfigLoaderError");

	cout << "road_length: " << get_road_length() << endl;
	cout << "road_width: " << get_road_width() << endl;
	cout << "speed: " << get_speed() << endl;
}

void gtt_urban_config::load() {

}

void tmc_config::set_config_loader(config_loader* t_config_loader) {
	m_config_loader = t_config_loader;
}

config_loader* tmc_config::get_config_loader() {
	return m_config_loader;
}

void tmc_config::load() {

}