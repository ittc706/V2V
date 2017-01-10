#pragma once

class vue;

class system_control {
	/*------------------˽���ֶ�------------------*/
private:
	vue* m_vue_array = nullptr;

	/*----------------�������Ƴ�Ա----------------*/
public:
	/*
	* Ĭ�Ϲ��캯������������ʵ��ָ��ĳ�ʼ��
	*/
	system_control();

	/*
	* ��������������������Դ
	*/
	~system_control();

	/*
	* ���������캯������Ϊɾ��
	*/
	system_control(const system_control& t_system_control) = delete;

	/*
	* ���ƶ����캯������Ϊɾ��
	*/
	system_control(system_control&& t_system_control) = delete;

	/*
	* ��������ֵ���������Ϊɾ��
	*/
	system_control& operator=(const system_control& t_system_control) = delete;

	/*
	* ���ƶ���ֵ���������Ϊɾ��
	*/
	system_control& operator=(system_control&& t_system_control) = delete;
};