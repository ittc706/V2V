#pragma once


class vue_physics {
	/*------------------��Ԫ����------------------*/
	/*
	* ��vue��Ϊvue_physics����Ԫ������vue_physics�Ĺ��캯����Ϊ˽�У�������vue������
	*/
	friend class vue;

	/*----------------�������Ƴ�Ա----------------*/
private:
	/*
	* Ĭ�Ϲ��캯��
	* ��Ϊ˽�У����ʼ����ȫ����vue����ɣ���ֹ���ɸ����͵�ʵ��
	*/
	vue_physics();

public:
	/*
	* ��������������������Դ
	*/
	~vue_physics();

	/*
	* ���������캯������Ϊɾ��
	*/
	vue_physics(const vue_physics& t_vue_physics) = delete;

	/*
	* ���ƶ����캯������Ϊɾ��
	*/
	vue_physics(vue_physics&& t_vue_physics) = delete;

	/*
	* ��������ֵ���������Ϊɾ��
	*/
	vue_physics& operator=(const vue_physics& t_vue_physics) = delete;

	/*
	* ���ƶ���ֵ���������Ϊɾ��
	*/
	vue_physics& operator=(vue_physics&& t_vue_physics) = delete;

	/*------------------˽���ֶ�------------------*/
private:
	/*
	* ����
	*/
	double m_speed = 0;

	/*
	* ������
	*/
	double m_x = 0;

	/*
	* ������
	*/
	double m_y = 0;

	/*----------------������༭��----------------*/
public:
	
};