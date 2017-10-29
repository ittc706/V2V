#pragma once

#include"gtt.h"

class gtt_urban_config;
class vue_physics;

class gtt_urban :public gtt {
	/*--------------------½Ó¿Ú--------------------*/
public:
	void initialize() override;

	int get_vue_num() override;

	void fresh_location() override;

	void calculate_pl(int t_vue_id1, int t_vue_id2) override;

	gtt_urban_config* get_precise_config();

private:
	int calculate_slot_time_idx(vue_physics* t_pv, int t_granularity);

private:
	double m_crossroads[24][2];
}; 
