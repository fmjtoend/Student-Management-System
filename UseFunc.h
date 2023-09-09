#pragma once
#include"vectors.h"
class UseFunc {
public:
	UseFunc() {

	}
	~UseFunc() {

	}
	//UseInfor infors;//使用学生信息功能性方法

	void static UseMainMnue(vectors* v);// 对主菜单功能的调用
	void static UseInputMenu(vectors* v);// 对数据录入菜单功能的调用
	void static UseAlterMenu(vectors* v);// 对数据修改菜单功能的调用
	void static UseCXMenu(vectors* v);// 对数据查询菜单功能的调用
	void static UseAnaMenu(vectors* v);// 对数据分析菜单功能的调用
};

