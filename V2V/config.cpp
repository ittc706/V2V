

#include"config.h"

using namespace std;

void global_control_config::set_config_loader(config_loader* t_config_loader) {
	m_config_loader = t_config_loader;
}

config_loader* global_control_config::get_config_loader() {
	return m_config_loader;
}

void global_control_config::load() {

}

void gtt_config::set_config_loader(config_loader* t_config_loader) {
	m_config_loader = t_config_loader;
}

config_loader* gtt_config::get_config_loader() {
	return m_config_loader;
}

void gtt_highspeed_config::load() {

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