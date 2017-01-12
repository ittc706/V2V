#pragma once
#include<vector>
#include<list>

class gtt;
class tmc;
class vue;
class v2v_event;

class context {
	/*------------------��Ԫ����------------------*/
	/*
	* ��system_control��Ϊcontext����Ԫ���ṩ�乹��������Ψһʵ����Ȩ��
	*/
	friend class system_control;
	friend class gtt_highspeed;
	friend class tmc;
	/*------------------��̬��Ա�ֶ�------------------*/
private:
	/*
	* ����ģʽ�£�Ψһʵ���ָ��
	*/
	static context* s_singleton_context;

public:
	/*
	* ����ģʽ�£���ȡΨһʵ���ָ��
	*/
	static context* get_context();

private:
	/*
	* ����ģʽ�£�����Ψһʵ���ָ��
	*/
	static void set_context(context* t_singleton_context);

private:
	/*
	* ����ģʽ�£�����Ψһʵ��
	*/
	static void context_factory();

	/*----------------�������Ƴ�Ա----------------*/
private:
	/*
	* Ĭ�Ϲ��캯��
	*/
	context();

public:
	/*
	* ��������������������Դ
	*/
	~context();

	/*
	* ���������캯������Ϊɾ��
	*/
	context(const context& t_context) = delete;

	/*
	* ���ƶ����캯������Ϊɾ��
	*/
	context(context&& t_context) = delete;

	/*
	* ��������ֵ���������Ϊɾ��
	*/
	context& operator=(const context& t_context) = delete;

	/*
	* ���ƶ���ֵ���������Ϊɾ��
	*/
	context& operator=(context&& t_context) = delete;

	/*------------------������Ա------------------*/
	/*
	* tti���༭����������
	*/
private:
	int m_tti = 0;
public:
	void increase_tti();
	int get_tti();

	/*
	* ������ʵ��ָ�롢�༭����������
	*/
private:
	gtt* m_gtt = nullptr;
	void set_gtt(gtt* t_gtt);
public:
	gtt* get_gtt();

	/*
	* tmc��ʵ��ָ�롢�༭����������
	*/
private:
	tmc* m_tmc = nullptr;
	void set_tmc(tmc* t_tmc);
public:
	tmc* get_tmc();

	/*
	* ����������ָ�롢�༭����������
	*/
private:
	vue* m_vue_array = nullptr;
	void set_vue_array(vue* t_vue_array);
public:
	vue* get_vue_array();

	/*
	* �¼�������
	*/
private:
	std::vector<v2v_event*> m_event_array;
public:
	std::vector<v2v_event*>& get_event_array();

	/*
	* tti�¼����飬
	* ����±����ttiʱ��
	*/
private:
	std::vector<std::list<int>> m_tti_event_list;
	void initialize_tti_event_list();
public:
	std::vector<std::list<int>>& get_tti_event_list();
};

