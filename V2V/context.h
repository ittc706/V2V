#pragma once

class vue;

class context {
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

public:
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
	* ����������ָ�롢�༭����������
	*/
private:
	vue* m_vue_array = nullptr;
public:
	void set_vue_array(vue* t_vue_array);
	vue* get_vue_array();
};