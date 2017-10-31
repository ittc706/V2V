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
	void set_slot_time_idx_for_vue(vue_physics* t_pv);

	bool is_interact_with_buildings(double t_x1, double t_y1, double t_x2, double t_y2);

private:
	double m_crossroads[24][2];
	double m_buildings[56][2][2];

	void initialize_crossroads();
	void initialize_buildings();
}; 
