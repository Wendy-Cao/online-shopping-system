//#include"adm.h"
#include"mysql.h"
#include"ui.h"
#include"adm.h"
adm m;
BasicUI * arrUI[]=
{
new ExitUI,
new Login_mainUI,
new Admin_loginUI,
new User_loginUI,
new Admin_mainUI,
new User_mainUI,
new Show_book1UI,
new Search_bookUI,
new Add_bookUI,
new Delete_bookUI,
new Change_bookUI,
new Add_memberUI,
new Show_memberUI,
new Show_recordUI,
new Show_one_recordUI,
new Show_book2UI,
new Shop_bookUI,
new Back_bookUI,
new Show_shop_recordUI
};
//4红色，5紫色，6黄色，7背景色，3天蓝色
int main()
{	
	OprDB().mysqltov();
	int index = SW_MAIN;
	while(index != X_END)
	index = arrUI[index]->show();
	OprDB().vtomysql();
	return 0;
}
