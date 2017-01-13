/*
* =====================================================================================
*
*       Filename:  rrm.cpp
*
*    Description:  无限资源管理类实现
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

#include"rrm.h"

using namespace std;

rrm::rrm() {

}

rrm::~rrm() {

}

void rrm::set_config(rrm_config* t_config) {
	m_config = t_config;
}

rrm_config* rrm::get_config() {
	return m_config;
}