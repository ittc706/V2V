#pragma once
#include<vector>
#include<list>

class config_loader;
class global_control_config;
class gtt_config;
class tmc_config;
class gtt;
class tmc;
class wt;
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
	* �����ļ����ض��󡢱༭����������
	*/
private:
	config_loader* m_config_loader = nullptr;
	void set_config_loader(config_loader* t_config_loader);
public:
	config_loader* get_config_loader();

	/*
	* ȫ�ֿ������ò�������
	*/
private:
	global_control_config* m_global_control_config = nullptr;
	void set_global_control_config(global_control_config* t_global_control_config);
public:
	global_control_config* get_global_control_config();

	/*
	* ���������봫����Ԫ���ö���
	*/
private:
	gtt_config* m_gtt_config = nullptr;
	void set_gtt_config(gtt_config* t_gtt_config);
public:
	gtt_config* get_gtt_config();

	/*
	* ҵ��ģ������Ƶ�Ԫ���ö���
	*/
private:
	tmc_config* m_tmc_config = nullptr;
	void set_tmc_config(tmc_config* t_tmc_config);
public:
	tmc_config* get_tmc_config();

	/*
	* tti,����ʱ��
	*/
private:
	int m_tti = 0;
public:
	void increase_tti();
	int get_tti();

	/*
	* ������ʵ��ָ��
	*/
private:
	gtt* m_gtt = nullptr;
	void set_gtt(gtt* t_gtt);
public:
	gtt* get_gtt();

	/*
	* tmc��ʵ��ָ��
	*/
private:
	tmc* m_tmc = nullptr;
	void set_tmc(tmc* t_tmc);
public:
	tmc* get_tmc();

	/*
	* wt����Ϊ�ǵ���ģʽ��������������wt���͵Ķ���
	*/
private:
	void wt_initialize();
public:
	wt* get_wt();

	/*
	* ����������ָ��
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
	void event_array_initialize();
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

	/*--------------------ʵ��--------------------*/
private:
	/*
	* Ϊ�����ĳ�Աע���������ִ����Ӧ�ĳ�ʼ������
	*/
	void dependency_injecte();
};

