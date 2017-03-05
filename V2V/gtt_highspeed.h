#pragma once

#include"gtt.h"

class gtt_highspeed_config;

class gtt_highspeed:public gtt{
	/*--------------------�ӿ�--------------------*/
public:
	void initialize() override;

	int get_vue_num() override;

	void fresh_location() override;

	void clean_channel() override;

	void calculate_channel(int t_vue_id1, int t_vue_id2, int t_pattern_idx) override;

	gtt_highspeed_config* get_precise_config();
};