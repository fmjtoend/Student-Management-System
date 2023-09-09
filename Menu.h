#pragma once


class Menu
{
public:
	Menu() {

	}
	~Menu() {

	}
	void static mainMenu(); // 显示主菜单
	void static inputMenu();// 数据录入菜单
	void static alterMenu();// 数据修改菜单
	void static cxMenu();// 数据查询菜单
	void static AnaMenu();// 数据统计分析菜单
	void static OutMenu();// 退出系统
};


