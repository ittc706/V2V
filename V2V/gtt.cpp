 

#include"gtt.h"
#include"gtt_highspeed.h"
#include"gtt_urban.h"

using namespace std;

gtt::gtt() {
	distance_pl.open("log/distance_pl.txt");
	distance_los.open("log/distance_los.txt");
	distance_nlos.open("log/distance_nlos.txt");
	time_slot_0.open("log/time_slot_0.txt");
	time_slot_1.open("log/time_slot_1.txt");
	time_slot_2.open("log/time_slot_2.txt");
	time_slot_3.open("log/time_slot_3.txt");
	center_coordinate.open("log/center_coordinate.txt");
}

gtt::~gtt() {
	distance_pl.close();
	distance_los.close();
	distance_nlos.close();
	time_slot_0.close();
	time_slot_1.close();
	time_slot_2.close();
	time_slot_3.close();
	center_coordinate.close();
}

gtt* gtt::gtt_bind_by_mode(gtt_mode t_mode) {
	if (t_mode == HIGHSPEED) {
		return new gtt_highspeed();
	}
	else {
		return new gtt_urban();
	}
}

void gtt::set_config(gtt_config* t_config) {
	m_config = t_config;
}

gtt_config* gtt::get_config() {
	return m_config;
}