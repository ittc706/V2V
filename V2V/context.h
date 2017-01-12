#pragma once

class vue;
class gtt;

class context {
	/*------------------友元声明------------------*/
	/*
	* 将system_control设为context的友元，提供其构造容器类唯一实例的权限
	*/
	friend class system_control;
	friend class gtt_highspeed;
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

private:
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
	void set_vue_array(vue* t_vue_array);
public:
	vue* get_vue_array();

	/*
	* 场景类实体指针、编辑器、访问器
	*/
private:
	gtt* m_gtt = nullptr;
	void set_gtt(gtt* t_gtt);
public:
	gtt* get_gtt();
};

