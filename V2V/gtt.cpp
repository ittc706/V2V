 

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


bool OnSegment(pair<double, double> p1, pair<double, double> p2, pair<double, double> p3) {
	double x_min, x_max, y_min, y_max;
	if (p1.first<p2.first) {
		x_min = p1.first;
		x_max = p2.first;
	}
	else {
		x_min = p2.first;
		x_max = p1.first;
	}
	if (p1.second<p2.second) {
		y_min = p1.second;
		y_max = p2.second;
	}
	else {
		y_min = p2.second;
		y_max = p1.second;
	}
	if (p3.first<x_min || p3.first>x_max || p3.second<y_min || p3.second>y_max)
		return false;
	else
		return true;
}

double direction(pair<double, double> p1, pair<double, double> p2, pair<double, double> p3) {
	pair<double, double> d1 = make_pair(p3.first - p1.first, p3.second - p1.second);
	pair<double, double> d2 = make_pair(p2.first - p1.first, p2.second - p1.second);
	return d1.first*d2.second - d1.second*d2.first;
}

bool gtt::is_interact(pair<double, double> p1, pair<double, double> p2, pair<double, double> p3, pair<double, double> p4) {
	double d1 = direction(p3, p4, p1);
	double d2 = direction(p3, p4, p2);
	double d3 = direction(p1, p2, p3);
	double d4 = direction(p1, p2, p4);

	if (d1*d2<0 && d3*d4<0)
		return true;
	else if (d1 == 0 && OnSegment(p3, p4, p1))
		return true;
	else if (d2 == 0 && OnSegment(p3, p4, p2))
		return true;
	else if (d3 == 0 && OnSegment(p1, p2, p3))
		return true;
	else if (d4 == 0 && OnSegment(p1, p2, p4))
		return true;
	else
		return false;
}

