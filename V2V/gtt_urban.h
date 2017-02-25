#pragma once

#include"gtt.h"

class gtt_urban_config;

class gtt_urban :public gtt {
	/*--------------------½Ó¿Ú--------------------*/
public:
	void initialize() override;

	int get_vue_num() override;

	void update_channel() override;

	gtt_urban_config* get_precise_config();
}; 
