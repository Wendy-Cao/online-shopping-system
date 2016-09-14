#include "ui.h"
#include<stdlib.h>
#include "adm.h"
extern adm m;
vector<Member>::iterator mbr;
int id;
int Login_mainUI::show()
{
	system("clear");
	cout<<"\n\n\n\n";
	cout<<"==========欢迎登录网购图书系统==========\n";
	cout<<"========================================\n";
	cout<<"=       1.管理员登录                   =\n";
	cout<<"=       2.用户登录                     =\n";
	cout<<"=       0.退出                         =\n";
	cout<<"========================================\n";
	cout<<"\n请输入您的选择:";
	int choice = 0;	
	cin>>choice;
	if(choice==1 || choice==2)
		return choice+1;
	else
		return 0;
}
void DelayUI::delay()
{
	int i;
	for(i=5;i>=0;i--)
	{
		system("clear");
		cout<<"\n\n\n\n\n\n\n\n\n\t\t\t\t\t------------------------------------------------------\n\n";
		cout<<"\t\t\t\t\t\t三次输入错误，请等待5s";
		cout<<"\n\n\n";
		cout<<"\t\t\t\t\t\t还剩"<<i<<"s\n\n";
		cout<<"\t\t\t\t\t------------------------------------------------------\n\n";
		sleep(1);
	}

}
int Admin_loginUI::show()
{
	int i=1;
	while(i<=3)
	{
		char name[10]="admin";
		char passwd[10]="123";
		char name1[10];
		char passwd1[10];
		cout<<"请输入用户名:";
		cin>>name1;
		cout<<"请输入密码:";
		cout<<"\033[8m";
		cin>>passwd1;
		cout<<"\033[0m";
		if(strcmp(name1,name)==0 && strcmp(passwd,passwd1)==0)
		{
			return 4;
		}
		i++;
		cout<<"你的输入有误，请重新输入..."<<endl;	
	}
	system("clear");
	DelayUI().delay();
	return 1;
}
int Admin_mainUI::show()
{
	system("clear");
	cout<<"\n\n\n\n";
	cout<<"=============欢迎 admin 登录============\n";
	cout<<"========================================\n";
	cout<<"=        1.查看所有图书                =\n";
	cout<<"=        2.查找图书                    =\n";
	cout<<"=        3.添加图书                    =\n";
	cout<<"=        4.删除图书                    =\n";
	cout<<"=        5.修改图书信息                =\n";
	cout<<"=        6.添加会员                    =\n";
	cout<<"=        7.查看所有会员                =\n";
	cout<<"=        8.查看所有会员购书记录        =\n";
	cout<<"=        9.查找会员购书记录            =\n";
	cout<<"=        0.退出                        =\n";
	cout<<"========================================\n";
	cout<<"\n请输入您的选择:";
	int choice = 0;
	cin>>choice;
	if(choice >= 1 && choice <= 9)
		return choice+5;
	else
		return choice;
}
int Add_bookUI::show()
{
	system("clear");
	cout<<"\n\n\n\n";
	cout<<"添加图书-->\n";
	cout<<"=========================================================================\n";
	m.add_lib();
	cout<<"=========================================================================\n";
	return SW_Admin_mainUI;
}
int Delete_bookUI::show()
{
	system("clear");
	cout<<"\n\n\n\n";
	cout<<"删除图书-->\n";
	cout<<"=========================================================================\n";
	m.del_lib();
	cout<<"=========================================================================\n";
	return SW_Admin_mainUI;
}
int Show_book1UI::show()
{
	system("clear");
	cout<<"\n\n\n\n";
	cout<<"查看所有图书-->\n";
	cout<<"=========================================================================\n";
	m.show_lib();
	cout<<"=========================================================================\n";
	cout<<"请按任意见继续...";
	getchar();
	getchar();
	return SW_Admin_mainUI;
}
int Change_bookUI::show()
{
	system("clear");
	cout<<"\n\n\n\n";
	cout<<"修改图书-->\n";
	cout<<"=========================================================================\n";
	m.change_lib();
	cout<<"=========================================================================\n";
	return SW_Admin_mainUI;
}
int Search_bookUI::show()
{
	system("clear");
	cout<<"\n\n\n\n";
	cout<<"查找图书-->\n";
	cout<<"=========================================================================\n";
	m.select_lib();
	cout<<"=========================================================================\n";
	cout<<"按任意继续...";
	getchar();
	getchar();
	return SW_Admin_mainUI;
}
int Add_memberUI::show()
{
	system("clear");
	cout<<"\n\n\n\n";
	cout<<"添加会员-->\n";
	cout<<"=========================================================================\n";
	m.add_member();
	cout<<"=========================================================================\n";
	return SW_Admin_mainUI;
}
int Show_memberUI::show()
{
	system("clear");
	cout<<"\n\n\n\n";
	cout<<"显示所有会员-->\n";
	cout<<"=========================================================================\n";
	m.show_member();
	cout<<"=========================================================================\n";
	cout<<"请按任意见继续...";
	getchar();
	getchar();
	return SW_Admin_mainUI;
}
int Show_recordUI::show()
{
	system("clear");
	cout<<"\n\n\n\n";
	cout<<"显示所有会员购书记录-->\n";
	cout<<"=========================================================================\n";
	m.show_record();
	cout<<"=========================================================================\n";
	cout<<"请按任意见继续...";
	getchar();
	getchar();
	return SW_Admin_mainUI;
}
int Show_one_recordUI::show()
{
	system("clear");
	cout<<"\n\n\n\n";
	cout<<"查找会员购书记录-->\n";
	cout<<"=========================================================================\n";
	m.show_one_record();
	cout<<"=========================================================================\n";
	cout<<"请按任意见继续...";
	getchar();
	getchar();
	return SW_Admin_mainUI;
}
int User_loginUI::show()
{
	int i=1;
	while(i<=3)
	{
		char passwd[10];
		cout<<"请输入账号:";
		cin>>id;
		cout<<"请输入密码:";
		cout<<"\033[8m";	
		cin>>passwd;
		cout<<"\033[0m";
		vector<Member>::iterator iter = m.v2.begin();
		while(iter != m.v2.end())
		{
			if((iter->m_id==id) && strcmp(passwd,iter->m_passwd)==0)
			{
				mbr=iter;
				return 5;
			}
			iter++;
		}
		i++;
		cout<<"你的输入有误，请重新输入..."<<endl;	
	}
	system("clear");
	DelayUI().delay();
	return 1;
}
int User_mainUI::show()
{
	system("clear");
	cout<<"\n\n\n\n";
	cout<<"=============欢迎 "<<mbr->m_name<<" 登录=============\n\n";
	cout<<"您上次的登录时间是"<<mbr->m_time<<endl<<endl;
	cout<<"========================================\n";
	cout<<"=        1.查看图书                    =\n";
	cout<<"=        2.购买图书                    =\n";
	cout<<"=        3.退货                        =\n";
	cout<<"=        4.查看订单                    =\n";
	cout<<"=        0.退出                        =\n";
	cout<<"========================================\n";
	cout<<"\n请输入您的选择:";
	int choice = 0;
	cin>>choice;
	if(choice>=1 && choice<=4 )
		return choice+14;
	else
		return choice;
}
int Show_book2UI::show()
{
	system("clear");
	cout<<"\n\n\n\n";
	cout<<"查看所有图书-->\n";
	cout<<"=========================================================================\n";
	m.show_lib();
	cout<<"=========================================================================\n";
	cout<<"请按任意见继续:";
	getchar();
	getchar();
	return 5;
}
int Shop_bookUI::show()
{
	system("clear");
	cout<<"\n\n\n\n";
	cout<<"购买图书-->\n";
	cout<<"=========================================================================\n";
	m.shop_book(mbr);
	cout<<"=========================================================================\n";
	cout<<"按任意继续...";
	getchar();
	getchar();
	return SW_User_mainUI;
}
int Back_bookUI::show()
{
	system("clear");
	cout<<"\n\n\n\n";
	cout<<"退货-->\n";
	cout<<"=========================================================================\n";
	m.member_back();
	cout<<"=========================================================================\n";
	cout<<"按任意继续...";
	getchar();
	getchar();
	return SW_User_mainUI;
}
int Show_shop_recordUI::show()
{
	system("clear");
	cout<<"\n\n\n\n";
	cout<<"购书记录-->\n";
	cout<<"=========================================================================\n";
	m.member_select_record(mbr);
	cout<<"=========================================================================\n";
	cout<<"按任意继续...";
	getchar();
	getchar();

	return SW_User_mainUI;
}
int ExitUI::show()
{
	system("clear");
	cout<<"\n\n\n\n";
	cout<<"===========退出系统===========\n";
	cout<<"=         欢迎下次登录       =\n";
	cout<<"==============================\n";
	return X_END;
}
