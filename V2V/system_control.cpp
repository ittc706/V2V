/*
* =====================================================================================
*
*       Filename:  system_control.cpp
*
*    Description:  ϵͳ��ʵ��
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

#include"system_control.h"
#include"function.h"
#include"vue.h"

using namespace std;

system_control::system_control() {

}


system_control::~system_control() {
	memory_clean::safe_delete(m_vue_array,true);
}