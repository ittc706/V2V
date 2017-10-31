#pragma once

#include"gtt.h"

class gtt_highspeed_config;
class vue_physics;

class gtt_highspeed:public gtt{
	/*--------------------½Ó¿Ú--------------------*/
public:
	void initialize() override;

	int get_vue_num() override;

	void fresh_location() override;

	void calculate_pl(int t_vue_id1, int t_vue_id2) override;

	gtt_highspeed_config* get_precise_config();

private:
	void set_slot_time_idx_for_vue(vue_physics* t_pv);
};