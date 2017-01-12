#pragma once


enum event_type {
	PERIOD
};


class v2v_event {
	/*------------------��̬��Ա------------------*/
private:
	static int s_event_count;

	/*----------------�������Ƴ�Ա----------------*/
public:
	/*
	* Ĭ�Ϲ��캯��
	*/
	v2v_event();

	/*
	* ��������������������Դ
	*/
	~v2v_event();

	/*
	* ���������캯������Ϊɾ��
	*/
	v2v_event(const v2v_event& t_v2v_event) = delete;

	/*
	* ���ƶ����캯������Ϊɾ��
	*/
	v2v_event(v2v_event&& t_v2v_event) = delete;

	/*
	* ��������ֵ���������Ϊɾ��
	*/
	v2v_event& operator=(const v2v_event& t_v2v_event) = delete;

	/*
	* ���ƶ���ֵ���������Ϊɾ��
	*/
	v2v_event& operator=(v2v_event&& t_v2v_event) = delete;
	
	/*--------------------�ֶ�--------------------*/
private:
	int m_send_delay = 0;

	int get_send_delay();

	/*--------------------����--------------------*/

	void increase_send_delay();
};