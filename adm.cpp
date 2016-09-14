#include"adm.h"
#include<iostream>
#include<string.h>
using namespace std;
extern adm m;
extern vector<Member>::iterator mbr;
//管理员查看所有图书
void adm::show_lib()
{
	vector<lib>::iterator iter = m.v1.begin();
	cout<<"  书名\t\t作者\t\t出版社\t\t价格\t\t数量\n"<<endl;
	while(iter!=m.v1.end())
	{	
		cout<<"《"<<iter->m_name<<"》\t"<<iter->m_author<<"\t\t"<<iter->m_publish<<"\t\t"<<iter->m_price<<"\t\t"<<iter->m_amount<<endl;
		iter++;
	}
}
//管理员添加图书
void adm::add_lib()
{
	while(1)
	{
		getchar();
		cout<<"是否添加书籍(y/n):";
		char ch[5];
		cin>>ch;
		if(strcmp(ch,"n")==0)
			break;
		else
		{
			char name[20];
			char author[20];
			char publish[40];
			double price;
			int amount;
			cout<<"请输入书名:";
			cin>>name;
			cout<<"请输入作者:";
			cin>>author;
			cout<<"请输入出版社:";
			cin>>publish;
			cout<<"请输入价格:";
			cin>>price;
			cout<<"请输入数量:";
			cin>>amount;
			cout<<"添加成功！"<<endl;
			cout<<"请按任意键继续..."<<endl;
			getchar();
			lib book(name,author,publish,price,amount);
			m.v1.push_back(book);
		}
	}
}
//管理员选择删除图书方式
void adm::del_lib()
{
	while(1)
	{			
		getchar();
		cout<<"是否要删除书籍(y/n):";
		char ch[5];
		cin>>ch;
		if(strcmp(ch,"n")==0)
			break;
		else
		{
			cout<<"按书名删除请按1"<<endl;
			cout<<"按作者删除请按2\n"<<endl;
			cout<<"请输入您的选择:";
			int a;
			cin>>a;
			if(a==1)
			{
				adm::select_book_lib();
				adm::del_book_lib();
			}
			else
			{
				adm::select_author_lib();
				adm::del_book_lib();
			}
		}

	}
}
//管理员删除图书
	void adm::del_book_lib()
{	while(1)
	{
		cout<<"请输入您要删除的书名和作者:"<<endl;
		char name[20];
		char author[20];
		cout<<"请输入书名:";
		cin>>name;
		cout<<"请输入作者:";
		cin>>author;
		int a=0;
		vector<lib>::iterator iter = v1.begin();
		while(iter!=v1.end())
		{
			if(strcmp(iter->m_name,name)==0 && strcmp(iter->m_author,author)==0)
			{
				a=1;
				cout<<"书名\t\t\t作者\t\t出版社\t\t价格\t\t数量\n"<<endl;
				cout<<"《"<<iter->m_name<<"》\t\t"<<iter->m_author<<"\t\t"<<iter->m_publish<<"\t\t"<<iter->m_price<<"\t\t"<<iter->m_amount<<endl;
				cout<<"是否确认删除?(y/n):";
				char ch1[1];
				cin>>ch1;
				if(strcmp(ch1,"y")==0)
				{
					iter=v1.erase(iter);
					cout<<"删除成功！"<<endl;
				}
				else
				{
					cout<<"您已放弃删除"<<endl;
					break;
				}
			}
			else
				iter++;
			//getchar();
		}
		if(a==0)
		{cout<<"您输入的书籍不存在"<<endl;}
		cout<<"是否继续删除(y/n)?:";
		char ch2;
		cin>>ch2;
		if(ch2=='n')
			break;
	}
}
//管理员选择查找图书方式
void adm::select_lib()
{
	while(1)
	{
		cout<<"按书名查找请按1\t\t按作者查找请按2\t\t退出请按0"<<endl;
		cout<<"请输入您的选择:";
		int a;
		cin>>a;
		if(a==1)
			adm::select_book_lib();
		else
			if(a==2)
				adm::select_author_lib();
			else
				break;
		getchar();
		cout<<"是否继续查找书籍(y/n):";
		char ch[5];
		cin>>ch;
		if(strcmp(ch,"n")==0)
			break;
	}

}
//管理员按书名查找图书
void adm::select_book_lib()
{
	while(1)
	{
		cout<<"请输入书名:";
		char name[20];
		cin>>name;
		int a=0;
		vector<lib>::iterator iter = v1.begin();
		cout<<"书名\t\t\t作者\t\t出版社\t\t价格\t\t数量"<<endl;
		while(iter!=v1.end())
		{
			if(strcmp(iter->m_name,name)==0)
			{
				a=1;
				cout<<"《"<<iter->m_name<<"》\t\t"<<iter->m_author<<"\t\t"<<iter->m_publish<<"\t\t"<<iter->m_price<<"\t\t"<<iter->m_amount<<endl;
				iter++;
			}
			else
				iter++;
		}
		if(a==1)
			break;
		if(a==0)
		{
			cout<<"您输入的书籍不存在！"<<endl;
			cout<<"是否重新查找(y/n)?:";
			char ch2;
			cin>>ch2;
			if(ch2=='n')
				break;
		}
	}
}
//管理员按作者查找图书
void adm::select_author_lib()
{
	while(1)
	{
		cout<<"请输入作者名字:";
		char author[20];		
		cin>>author;
		int a=0;
		vector<lib>::iterator iter = v1.begin();
		cout<<"书名\t\t\t作者\t\t出版社\t\t价格\t\t数量"<<endl;
		while(iter!=v1.end())
		{
			if(strcmp(iter->m_author,author)==0)
			{
				a=1;
				cout<<"《"<<iter->m_name<<"》\t\t"<<iter->m_author<<"\t\t"<<iter->m_publish<<"\t\t"<<iter->m_price<<"\t\t"<<iter->m_amount<<endl;
				iter++;
			}
			else
				iter++;
		}
		if(a==1)
			break;
		if(a==0)
		{
			cout<<"您输入的作者不存在！"<<endl;
			cout<<"是否重新查找(y/n)?:";
			char ch2;
			cin>>ch2;
			if(ch2=='n')
				break;
		}
	}
}
//管理员选择修改图书方式
void adm::change_lib()
{
	while(1)
	{
		cout<<"是否要修改书籍(y/n):";
		char ch[5];
		cin>>ch;
		if(strcmp(ch,"n")==0)
			break;
		else
		{
			cout<<"按书名修改请按1"<<endl;
			cout<<"按作者修改请按2"<<endl;
			cout<<"请输入您的选择:";
			int a;
			cin>>a;
			if(a==1)
			{
				adm::select_book_lib();
				adm::change_book_lib();
			}
			else
			{
				adm::select_author_lib();
				adm::change_book_lib();
			}
		}
		//		getchar();
	}
}
//管理员修改图书
void adm::change_book_lib()
{
	while(1)
	{
		cout<<"请输入您要修改的书名和作者:"<<endl;
		char name[20];
		char author[20];
		cout<<"请输入书名:";
		cin>>name;
		cout<<"请输入作者:";
		cin>>author;
		vector<lib>::iterator iter = v1.begin();
		int a=0;
		while(iter!=v1.end())
		{
			if(strcmp(iter->m_name,name)==0 && strcmp(iter->m_author,author)==0)
			{	
				a=1;
				cout<<" 书名\t\t\t作者\t\t出版社\t\t价格\t\t数量"<<endl;
				cout<<"《"<<iter->m_name<<"》\t\t"<<iter->m_author<<"\t\t"<<iter->m_publish<<"\t\t"<<iter->m_price<<"\t\t"<<iter->m_amount<<endl;
				cout<<"请输入您要修改的内容(书名/作者/出版社/价格):"<<endl;
				char name1[20];
				char author1[20];
				char publish1[40];
				double price1;
				int amount;
				cout<<"请输入书名:";
				cin>>name1;
				cout<<"请输入作者:";
				cin>>author1;
				cout<<"请输入出版社:";
				cin>>publish1;
				cout<<"请输入价格:";
				cin>>price1;
				cout<<"请输入数量:";
				cin>>amount;
				cout<<"是否保存修改?(y/n):";	
				char ch2;
				cin>>ch2;
				if(ch2=='y')
				{
					strcpy(iter->m_name,name1);
					strcpy(iter->m_author,author1);
					strcpy(iter->m_publish,publish1);
					iter->m_price=price1;
					iter->m_amount=amount;
					cout<<"修改成功！"<<endl;
					break;
				}
				else
				{
					cout<<"您已放弃修改！"<<endl;
					break;
				}
			}
			else
				iter++;
		}
		if(a==0)
		{
			cout<<"您输入的书籍不存在!"<<endl;
			break;
		}
		getchar();	
		char ch3;
		cout<<"是否继续修改(y/n)?:";
		cin>>ch3;
		if(ch3=='n')
			break;
	}
}
//显示会员
void adm::show_member()
{
	vector<Member>::iterator iter = m.v2.begin();
	cout<<"ID\t姓名\t级别\t电话\t地址\t上次登录时间"<<endl;
	while(iter!=m.v2.end())
	{
		cout<<iter->m_id<<"\t"<<iter->m_name<<"\t"<<iter->m_lev<<"\t"<<iter->m_tel<<"\t"<<iter->m_adress<<"\t"<<iter->m_time<<endl;
		iter++;
	}
}
//管理员添加会员
void adm::add_member()
{
	while(1)
	{
		getchar();
		cout<<"是否添加会员(y/n):";
		char ch[5];
		cin>>ch;
		if(strcmp(ch,"n")==0)
			break;
		else
		{

			char name[20];
			char passwd[20]="1111";
			char lev[20]="普通会员";
			char tel[20];
			char adress[40];


			cout<<"请输入姓名:";
			cin>>name;
			cout<<"请输入电话:";
			cin>>tel;
			cout<<"请输入地址:";
			cin>>adress;
			getchar();
			char e[10]="null";
	vector<Member>::iterator tor=m.v2.begin();
	while(tor!=m.v2.end())
	{
		tor++;
	}
	tor--;
			Member temp(tor->m_id+1,name,passwd,lev,tel,adress,e);
			m.v2.push_back(temp);
		}
	}
}
//显示会员购书记录
void adm::show_record()
{
	vector<Record>::iterator iter=m.v3.begin();
	cout<<"订单号\t书籍\t作者\t数量\t折扣\t邮费\t总额\tID\t备注"<<endl;
	while(iter!=m.v3.end())
	{
		cout<<iter->m_num<<"\t"<<iter->m_name<<"\t"<<iter->m_author<<"\t"<<iter->m_amount<<"\t"<<iter->m_dst<<"\t"<<iter->m_postage<<"\t"<<iter->m_total<<"\t"<<iter->m_id<<"\t"<<iter->m_remark<<endl;
		iter++;
	}
}
//查找某个会员的购书记录
void adm::show_one_record()
{
	while(1)
	{
		cout<<"请输入您要查看的会员的id:";
		int id;
		cin>>id;
		vector<Record>::iterator iter=m.v3.begin();
		cout<<"订单号\t书籍\t作者\t数量\t折扣\t邮费\t总额\tID\t备注"<<endl;
		while(iter!=m.v3.end())
		{
			if(iter->m_id==id)
			{
				cout<<iter->m_num<<"\t"<<iter->m_name<<"\t"<<iter->m_author<<"\t"<<iter->m_amount<<"\t"<<iter->m_dst<<"\t"<<iter->m_postage<<"\t"<<iter->m_total<<"\t"<<iter->m_id<<"\t"<<iter->m_remark<<endl;
				break;
			}
			else
				iter++;
		}
		cout<<"是否继续查看会员购书记录(y/n):";
		char ch[5];
		cin>>ch;
		if(strcmp(ch,"n")==0)
			break;
	}
}
//会员买书
void adm::shop_book(vector<Member>::iterator t)
{
	while(1)
	{
		cout<<"查看全部图书请按1/按书籍名称查找请按2/按作者查找请按3:";
		int a;
		char ch1;
		cin>>a;
		if(a==1)
			adm::show_lib();
		else
			if(a==2)
				adm::select_book_lib();
			else
				adm::select_author_lib();
		cout<<"请输入您要购买的书籍名称和作者:"<<endl;
		char name[20];
		char author[20];
		cout<<"书名:";
		cin>>name;
		cout<<"作者:";
		cin>>author;
		int b;
		vector<lib>::iterator iter = v1.begin();
		while(iter!=v1.end())
		{
			if((strcmp(iter->m_name,name)==0) && (strcmp(iter->m_author,author)==0))
			{
				if(iter->m_amount>0)
				{
					cout<<"是否将《"<<iter->m_name<<"》加入购物车(y/n)?";

					cin>>ch1;
					if(ch1=='y')
					{
						cout<<"请输入购买数量:";
						cin>>b;
						if(b!=0)
							cout<<"您已将《"<<iter->m_name<<"》加入购物车\t\t价格:"<<((iter->m_price) * b)<<"\t\t数量:"<<b<<endl;
						else
							cout<<"放弃购买..."<<endl;
						break;
					}
					else
					{
						cout<<"放弃将《"<<iter->m_name<<"》加入购物车..."<<endl;
						break;

					}
				}
				else
				{
					cout<<"《"<<iter->m_name<<"》"<<"库存不足..."<<endl;
					break;
				}
			}
			iter++;
			if(iter==v1.end())
				cout<<"您输入的书籍不存在..."<<endl;	

		}


		if(strcmp(t->m_lev,"普通会员")==0 && iter->m_amount > 0 && iter!=v1.end() && b!=0 && ch1!='n')
		{
			//cout<<"普通会员"<<endl;
			adm::squre_book(iter,b,t);
			m.member_vip(t);
		}
		else
			if(strcmp(t->m_lev,"VIP会员")==0 && iter->m_amount > 0 && iter!=v1.end() && b!=0 && ch1!='n')
			{		
				//cout<<"VIP会员"<<endl;
				adm::squre_book_VIP(iter,b,t);
				adm::member_vip(t);
			}
		cout<<"是否继续购书(y/n):";
		char ch[5];
		cin>>ch;
		if(strcmp(ch,"n")==0)
			break;
	}
}
//普通会员结算
void adm::squre_book(vector<lib>::iterator it,int a,vector<Member>::iterator t)
{
	cout<<"是否结算(y/n)?:";
	char ch;
	cin>>ch;
	double fee;
	double dst;
	double postage;
	if(ch=='y')
	{
		if((it->m_price * a) < 100)
		{
			fee=it->m_price * a + 10;
			cout<<"本次购书费用:"<<fee<<endl;
			dst=0;
			postage=10;
			//Record r(it->m_name,0,10,fee,t->m_id);
			//m.v3.push_back(r);
			//it->m_amount=(it->m_amount)-a;
		}
		if((it->m_price * a)>=100 && (it->m_price * a)<150)
		{
			fee=(it->m_price * a * 0.95) + 10;
			cout<<"本次购书费用:"<<fee<<endl;
			dst=0.95;
			postage=10;
			//Record r(it->m_name,0.95,10,fee,t->m_id);
			//m.v3.push_back(r);
			//it->m_amount=(it->m_amount)-a;
		}
		if((it->m_price * a)>=150)
		{
			fee=(it->m_price * a * 0.95);
			cout<<"本次购书费用:"<<fee<<endl;
			dst=0.95;
			postage=0;
			//Record r(it->m_name,0.95,0,fee,t->m_id);
			//m.v3.push_back(r);
			//it->m_amount=(it->m_amount)-a;
		}
	}
	cout<<"按任意键进行付款..."<<endl;
	getchar();
	getchar();
	cout<<"付款成功！订单详情-->"<<endl;
	cout<<" 书名 \t作者\t\t数量\t\t费用\t\t地址\t\t电话\n";
	cout<<"《"<<it->m_name<<"》\t"<<it->m_author<<"\t"<<a<<"\t"<<fee<<"\t"<<t->m_adress<<"\t"<<t->m_tel<<endl;
	char t1[10]="无";
	char *t2=t1;
	vector<Record>::iterator tor=m.v3.begin();
	while(tor!=m.v3.end())
	{
		tor++;
	}
	tor--;
	Record r(tor->m_num+1,it->m_name,it->m_author,a,0,10,fee,t->m_id,t2);
	m.v3.push_back(r);
	it->m_amount=(it->m_amount)-a;
}
//VIP会员结算
void adm::squre_book_VIP(vector<lib>::iterator it,int a,vector<Member>::iterator t)
{ 
	cout<<"是否结算(y/n)?:";
	char ch;
	cin>>ch;
	double fee;
	double postage;
	if(ch=='y')
	{
		if((it->m_price * a) >=100)
		{
			fee=(it->m_price * a * 0.95);
			cout<<"本次购书费用:"<<fee<<endl;
			//Record r(it->m_name,0.95,0,fee,t->m_id);
			//m.v3.push_back(r);
			//it->m_amount=(it->m_amount)-a;
			postage=0;

		}
		if((it->m_price * a) < 100)
		{
			fee=(it->m_price * a * 0.95)+10;
			cout<<"本次购书费用:"<<fee<<endl;
			postage=10;
			//Record r(it->m_name,0.95,10,fee,t->m_id);
			//m.v3.push_back(r);
			//it->m_amount=(it->m_amount)-a;
		}

	}
	cout<<"按任意键进行付款..."<<endl;
	getchar();
	getchar();
	cout<<"付款成功！订单详情-->"<<endl;
	cout<<" 书名\t作者\t数量\t费用\t地址\t电话\n";
	cout<<it->m_name<<"\t"<<it->m_author<<"\t"<<a<<"\t"<<fee<<"\t"<<t->m_adress<<"\t"<<t->m_tel<<endl;
	cout<<"请对此次购买做出备注:";
	char remark[100];
	cin>>remark;
	vector<Record>::iterator tor=m.v3.begin();
	while(tor!=m.v3.end())
	{
		tor++;
	}
	tor--;
	Record r(tor->m_num+1,it->m_name,it->m_author,a,0.95,postage,fee,t->m_id,remark);
	m.v3.push_back(r);
	it->m_amount=(it->m_amount)-a;
}
//普通会员升级为VIP会员
void adm::member_vip( vector<Member>::iterator t)
{

	vector<Record>::iterator iter = m.v3.begin();
	double sum=0;
	if(strcmp(t->m_lev,"普通会员")==0)
	{
		while(iter != m.v3.end() )
		{
			if(iter->m_id == t->m_id)
			{
				sum=sum+iter->m_total;
			}
			iter++;
		}
		if(sum >= 1000)
		{
			cout<<"111"<<endl;
			strcpy(t->m_lev,"VIP会员");
			cout<<"购书总额已经超过1000，恭喜您升级为会员！"<<endl;
		}
	}
	if(strcmp(t->m_lev,"VIP会员")==0)
	{
		while(iter != m.v3.end() )
		{
			if(iter->m_id == t->m_id)
			{
				sum=sum+iter->m_total;
			}
			iter++;
		}
		if(sum >= 1000)
		{
			strcpy(t->m_lev,"VIP会员");
			cout<<"您现在的级别：VIP用户！"<<endl;
		}
		else
		{	strcpy(t->m_lev,"普通会员");
			cout<<"您现在的级别：普通会员！"<<endl;
		}
	}
}
//会员查看自己的购书记录
void adm::member_select_record(vector<Member>::iterator iter)
{
	vector<Record>::iterator it = m.v3.begin();
	cout<<"订单号\t书籍\t作者\t数量\t折扣\t邮费\t总额\tID\t备注"<<endl;
	while(it != m.v3.end())
	{
		if(it->m_id==iter->m_id)
		{
			cout<<it->m_num<<"\t"<<it->m_name<<"\t"<<it->m_author<<"\t"<<it->m_amount<<"\t"<<it->m_dst<<"\t"<<it->m_postage<<"\t"<<it->m_total<<"\t"<<it->m_id<<"\t"<<it->m_remark<<endl;
		}
		it++;
	}
}
void adm::member_back()
{
	cout<<"请输入订单号:";
	int num;
	cin>>num;
	vector<Record>::iterator tor=m.v3.begin();
	while(tor!=m.v3.end())
	{
		if(tor->m_num==num)
		{		
			vector<lib>::iterator ra=m.v1.begin();
			while(ra!=m.v1.end())
			{
				if(strcmp(tor->m_name,ra->m_name)==0 && strcmp(tor->m_author,ra->m_author)==0)
				{
					ra->m_amount=ra->m_amount+tor->m_amount;
					v3.erase(tor);
					cout<<"退货成功"<<endl;
					adm::member_vip(mbr);
					return ;
				}
				ra++;
			}
		}
		tor++;
	}
	cout<<"订单不存在"<<endl;
}
