#pragma once

#include"gtt.h"

class gtt_highspeed_config;

class gtt_highspeed:public gtt{
	/*--------------------½Ó¿Ú--------------------*/
public:
	void drop_vue() override;

	int get_vue_num() override;

	gtt_highspeed_config* get_precise_config();
};