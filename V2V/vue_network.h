#pragma once


class vue_network {
	/*------------------��Ԫ����------------------*/
	/*
	* ��vue��Ϊvue_network����Ԫ������vue_network�Ĺ��캯����Ϊ˽�У�������vue������
	*/
	friend class vue;

	/*----------------�������Ƴ�Ա----------------*/
private:
	/*
	* Ĭ�Ϲ��캯��
	* ��Ϊ˽�У����ʼ����ȫ����vue����ɣ���ֹ���ɸ����͵�ʵ��
	*/
	vue_network();

public:
	/*
	* ��������������������Դ
	*/
	~vue_network();

	/*
	* ���������캯������Ϊɾ��
	*/
	vue_network(const vue_network& t_vue_network) = delete;

	/*
	* ���ƶ����캯������Ϊɾ��
	*/
	vue_network(vue_network&& t_vue_network) = delete;

	/*
	* ��������ֵ���������Ϊɾ��
	*/
	vue_network& operator=(const vue_network& t_vue_network) = delete;

	/*
	* ���ƶ���ֵ���������Ϊɾ��
	*/
	vue_network& operator=(vue_network&& t_vue_network) = delete;
};