#pragma once


class tmc {
	/*------------------��Ԫ����------------------*/

	/*------------------��̬��Ա------------------*/


	/*----------------�������Ƴ�Ա----------------*/
public:
	/*
	* Ĭ�Ϲ��캯��
	*/
	tmc();

	/*
	* ��������������������Դ
	*/
	~tmc();

	/*
	* ���������캯������Ϊɾ��
	*/
	tmc(const tmc& t_tmc) = delete;

	/*
	* ���ƶ����캯������Ϊɾ��
	*/
	tmc(tmc&& t_tmc) = delete;

	/*
	* ��������ֵ���������Ϊɾ��
	*/
	tmc& operator=(const tmc& t_tmc) = delete;

	/*
	* ���ƶ���ֵ���������Ϊɾ��
	*/
	tmc& operator=(tmc&& t_tmc) = delete;

	/*--------------------�ֶ�--------------------*/
	/*
	* �����¼����ڡ��༭����������
	*/
private:
	int m_period_of_period_event;
	void set_period_of_period_event(int t_period_of_period_event);
public:
	int get_period_of_period_event();

	/*--------------------����--------------------*/
public:
	/*
	* ��ʼ��������Ϊÿһ��������ʵ�����ò���
	*/
	void preparate();

	/*
	* �¼��������������ÿ������ͬ����������ά������context�е��¼���Ա
	*/
	void event_trigger();
};