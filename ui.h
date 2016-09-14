#ifndef _UI_H
#define _UI_H
#include <stdlib.h>
#include<iostream>

using namespace std;
enum
{
	SW_EXIT=0,
	SW_MAIN,
	SW_ADMIN,
	SW_USER,
	SW_Admin_mainUI,
	SW_User_mainUI,
	SW_show_book1UI,
	SW_search_bookUI,
	SW_add_bookUI,
	SW_delete_bookUI,
	SW_change_bookUI,
	SW_add_memberUI,
	SW_show_memberUI,
	SW_show_recordUI,
	SW_show_one_recordUI,
	SW_show_book2UI,
	SW_shop_bookUI,
	SW_back_bookUI,
	SW_show_shop_recordUI,
	X_END
};
//基础界面类
class BasicUI
{
	public:
		static int code;
		virtual int show() = 0;
};
class DelayUI
{
	public:
		void delay();
};
//登录主界面类
class Login_mainUI:public BasicUI
{
	public:
		int show();
};
//管理员登录界面
class Admin_loginUI:public BasicUI
{
	public:
		int show();
};
//管理员操作界面
class Admin_mainUI:public BasicUI
{
	public:
		int show();
};
//会员登录界面
class User_loginUI:public BasicUI
{
	public:
		int show();
};
//会员操作界面
class User_mainUI:public BasicUI
{
	public:
		int show();
};
//退出显示界面
class ExitUI:public BasicUI
{
	public:
		int show();
};
//管理员操作功能界面,添加图书
class Add_bookUI:public BasicUI
{
	public:
		int show();
};
//管理员操作功能界面,删除图书
class Delete_bookUI:public BasicUI
{
	public:
		int show();
};
//管理员操作功能界面,查看所有图书
class Show_book1UI:public BasicUI
{
	public:
		int show();
};
//管理员操作功能界面,查找图书
class Search_bookUI:public BasicUI
{
	public:
		int show();
};
//管理员操作功能界面,修改图书
class Change_bookUI:public BasicUI
{
	public:
		int show();
};
//管理员操作功能界面,添加会员
class Add_memberUI:public BasicUI
{
	public:
		int show();
};
//管理员操作功能界面,显示会员
class Show_memberUI:public BasicUI
{
	public:
		int show();
};
//管理员操作功能界面,显示所有购书记录
class Show_recordUI:public BasicUI
{
	public:
		int show();
};
//管理员操作功能界面,显示某一个会员的购书记录
class Show_one_recordUI:public BasicUI
{
	public:
		int show();
};
//会员操作功能界面，购买图书
class Shop_bookUI:public BasicUI
{
	public:
		int show();
};
//会员退书功能界面

class Back_bookUI:public BasicUI
{
	public:
		int show();
};
//会员操作功能界面，查看所有图书
class Show_book2UI:public BasicUI
{
	public:
		int show();
};
//会员操作功能界面，查看自己的购书记录
class Show_shop_recordUI:public BasicUI
{
	public:
		int show();
};
#endif
