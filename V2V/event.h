#pragma once


enum event_type {
	PERIOD
};


class sender_event {
	/*------------------��Ԫ����------------------*/
	/*
	* ��tmc��Ϊ��Ԫ���¼���ص��ֶ���Ҫͨ��tmc����������
	*/
	friend class tmc;
	/*------------------��̬��Ա------------------*/
private:
	static int s_event_count;

	/*----------------�������Ƴ�Ա----------------*/
public:
	/*
	* Ĭ�Ϲ��캯��
	*/
	sender_event();

	/*
	* ��������������������Դ
	*/
	~sender_event();

	/*
	* ���������캯������Ϊɾ��
	*/
	sender_event(const sender_event& t_sender_event) = delete;

	/*
	* ���ƶ����캯������Ϊɾ��
	*/
	sender_event(sender_event&& t_sender_event) = delete;

	/*
	* ��������ֵ���������Ϊɾ��
	*/
	sender_event& operator=(const sender_event& t_sender_event) = delete;

	/*
	* ���ƶ���ֵ���������Ϊɾ��
	*/
	sender_event& operator=(sender_event&& t_sender_event) = delete;
	
	/*--------------------�ֶ�--------------------*/
	/*
	* �¼�id
	*/
private:
	int m_event_id = s_event_count++;
public:
	int get_event_id();

	/*
	* ����id
	*/
private:
	int m_vue_id;
	void set_vue_id(int t_vue_id);
public:
	int get_vue_id();


	/*--------------------����--------------------*/
};


class receiver_event {
	/*----------------�������Ƴ�Ա----------------*/
public:
	/*
	* Ĭ�Ϲ��캯��
	*/
	receiver_event() = delete;

	/*
	* ���캯��
	*/
	receiver_event(sender_event* t_sender_event);

	/*
	* ��������������������Դ
	*/
	~receiver_event();

	/*
	* ���������캯������Ϊɾ��
	*/
	receiver_event(const receiver_event& t_receiver_event) = delete;

	/*
	* ���ƶ����캯������Ϊɾ��
	*/
	receiver_event(receiver_event&& t_receiver_event) = delete;

	/*
	* ��������ֵ���������Ϊɾ��
	*/
	receiver_event& operator=(const receiver_event& t_receiver_event) = delete;

	/*
	* ���ƶ���ֵ���������Ϊɾ��
	*/
	receiver_event& operator=(receiver_event&& t_receiver_event) = delete;

	/*--------------------�ֶ�--------------------*/
	/*
	* �¼�id���뷢���¼���ͬ
	*/
private:
	int m_event_id;
public:
	void set_event_id(int t_event_id);
	int get_event_id();

	/*
	* ���ͳ���id
	*/
private:
	int m_from_vue_id;
public:
	void set_from_vue_id(int t_from_vue_id);
	int get_from_vue_id();

	/*
	* ���ճ���id
	*/
private:
	int m_to_vue_id;
public:
	void set_to_vue_id(int t_to_vue_id);
	int get_to_vue_id();
};