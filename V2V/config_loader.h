#pragma once
#include<regex>
#include<string>
#include<fstream>
#include<map>

class config_loader {
	/*------------------��̬------------------*/
public:
	/*
	* ��stringתΪint
	*/
	static int string_to_int(std::string t_string);

	/*
	* ��stringתΪdouble
	*/
	static double string_to_double(std::string t_string);
private:
	/*
	* �����ļ��ַ���
	*/
	std::string m_content;

	/*
	* [��ǩ-ֵ]��
	*/
	std::map<std::string, std::string> m_tag_content_map;

	/*------------------����------------------*/
public:
	/*
	* Ĭ�Ϲ��캯��
	*/
	config_loader() {}

	/*
	* �����ļ����Ĺ��캯��
	*/
	void resolv_config_file(std::string t_file);

	/*
	* ��m_tag_content_map���ݱ�ǩ��ȡ��ֵ
	*/
	std::string get_param(std::string t_param);
};