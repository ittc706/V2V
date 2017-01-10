/*
* =====================================================================================
*
*       Filename:  vue_physics.cpp
*
*    Description:  车辆类的物理层部分实现
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

#include"vue_physics.h"

using namespace std;

int vue_physics::s_vue_count = 0;

std::vector<std::vector<double*>> vue_physics::s_channel_all(0);

double* vue_physics::get_channel(int i, int j) {
	if (i < j) {
		return s_channel_all[i][j];
	}
	else {
		return s_channel_all[j][i];
	}
}


void vue_physics::set_channel(int i, int j, double* t_channel) {
	if (i < j) {
		s_channel_all[i][j] = t_channel;
	}
	else {
		s_channel_all[j][i] = t_channel;
	}
}


vue_physics::vue_physics() {

}


vue_physics::~vue_physics() {
	
}


void vue_physics::update_location() {

}