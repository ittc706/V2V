#pragma once


class vue_link {
	/*------------------��Ԫ����------------------*/
	/*
	* ��vue��Ϊvue_link����Ԫ������vue_link�Ĺ��캯����Ϊ˽�У�������vue������
	*/
	friend class vue;

	/*----------------�������Ƴ�Ա----------------*/
private:
	/*
	* Ĭ�Ϲ��캯��
	* ��Ϊ˽�У����ʼ����ȫ����vue����ɣ���ֹ���ɸ����͵�ʵ��
	*/
	vue_link();

public:
	/*
	* ��������������������Դ
	*/
	~vue_link();

	/*
	* ���������캯������Ϊɾ��
	*/
	vue_link(const vue_link& t_vue_link) = delete;

	/*
	* ���ƶ����캯������Ϊɾ��
	*/
	vue_link(vue_link&& t_vue_link) = delete;

	/*
	* ��������ֵ���������Ϊɾ��
	*/
	vue_link& operator=(const vue_link& t_vue_link) = delete;

	/*
	* ���ƶ���ֵ���������Ϊɾ��
	*/
	vue_link& operator=(vue_link&& t_vue_link) = delete;
};