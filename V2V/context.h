#pragma once

class vue;

class context {
	/*------------------静态成员字段------------------*/
private:
	/*
	* 单例模式下，唯一实体的指针
	*/
	static context* s_singleton_context;

public:
	/*
	* 单例模式下，获取唯一实体的指针
	*/
	static context* get_context();

private:
	/*
	* 单例模式下，设置唯一实体的指针
	*/
	static void set_context(context* t_singleton_context);

public:
	/*
	* 单例模式下，生成唯一实体
	*/
	static void context_factory();

	/*----------------拷贝控制成员----------------*/
private:
	/*
	* 默认构造函数
	*/
	context();

public:
	/*
	* 析构函数，负责清理资源
	*/
	~context();

	/*
	* 将拷贝构造函数定义为删除
	*/
	context(const context& t_context) = delete;

	/*
	* 将移动构造函数定义为删除
	*/
	context(context&& t_context) = delete;

	/*
	* 将拷贝赋值运算符定义为删除
	*/
	context& operator=(const context& t_context) = delete;

	/*
	* 将移动赋值运算符定义为删除
	*/
	context& operator=(context&& t_context) = delete;

	/*------------------容器成员------------------*/
	/*
	* 车辆类数组指针、编辑器、访问器
	*/
private:
	vue* m_vue_array = nullptr;
public:
	void set_vue_array(vue* t_vue_array);
	vue* get_vue_array();
};