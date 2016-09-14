#include<mysql/mysql.h>
#include<iostream>
#include<string>
#include"adm.h"
#include<stdlib.h>
#include<stdio.h>
#include"mysql.h"
#include<vector>
using namespace std;
extern adm m;
extern int id;
//静态成员初始化
MYSQL* OprDB::m_mysql=NULL;
// 1.初始化连接
void OprDB::initDB()
{
	m_mysql=mysql_init(NULL);
	if(!mysql_real_connect(m_mysql,DB_HOST,DB_USER,DB_PASS,DB_NAME,0,NULL,0))
	{
		cout<<"connect error"<<endl;
		return ;
	}
} 
// 2.断开连接
void OprDB::destroyDB()
{
	mysql_close(m_mysql);
	m_mysql= NULL;
	return ;
}

void OprDB::mysqltov()
{
	MYSQL_RES *res1,*res2,*res3;
	MYSQL_ROW row1,row2,row3;
	initDB();
	mysql_set_character_set(m_mysql,"utf8");//设置字符集
	if(mysql_query(m_mysql,"select *from lib"))
	{	
		cout<<"query error"<<endl;
		return ;
	}
	res1=mysql_use_result(m_mysql);//获得结果集,一条一条拿，只能顺序拿
	while((row1=mysql_fetch_row(res1))!=NULL)
	{
	//	cout<<row1[0]<<" "<<row1[1]<<" "<<row1[2]<<" "<<row1[3]<<" "<<row1[4]<<endl;
		lib temp1(row1[0],row1[1],row1[2],atof(row1[3]),atoi(row1[4]));
		m.v1.push_back(temp1);
	}
	mysql_free_result(res1);
	destroyDB();
	initDB();
	mysql_set_character_set(m_mysql,"utf8");//设置字符集
	if(mysql_query(m_mysql,"select *from member"))
	{
		cout<<"query error"<<endl;
		return ;
	}
	res2=mysql_use_result(m_mysql);//获得结果集,一条一条拿，只能顺序拿
	while((row2=mysql_fetch_row(res2))!=NULL)
	{
		//cout<<row2[0]<<" "<<row2[1]<<" "<<row2[2]<<" "<<row2[3]<<" "<<row2[4]<<" "<<row2[5]<<" "<<row2[6]<<endl;
		Member temp2(atoi(row2[0]),row2[1],row2[2],row2[3],row2[4],row2[5],row2[6]);
		m.v2.push_back(temp2);
	}
	mysql_free_result(res2);//
	destroyDB();
	initDB();
	mysql_set_character_set(m_mysql,"utf8");//设置字符集
	if(mysql_query(m_mysql,"select *from record"))
	{
		cout<<"query error"<<endl;
		return ;
	}

	res3=mysql_use_result(m_mysql);//获得结果集,一条一条拿，只能顺序拿
	while((row3=mysql_fetch_row(res3))!=NULL)
	{
		//cout<<row1[0]<<" "<<row1[1]<<" "<<row1[2]<<" "<<row1[3]<<endl;
		Record temp3(atoi(row3[0]),row3[1],row3[2],atoi(row3[3]),atof(row3[4]),atof(row3[5]),atof(row3[6]),atoi(row3[7]),row3[8]);
		m.v3.push_back(temp3);
	}
	mysql_free_result(res3);//
	destroyDB();
	return ;
}
void OprDB::vtomysql()
{
	initDB();
	mysql_set_character_set(m_mysql,"utf8");
	if(mysql_query(m_mysql,"delete from lib"))
	{
		cout<<"query delete error"<<endl;
		return ;
	}
	char buf1[100]={0};
	char buf2[50]="insert into lib values(";
	vector<lib>::iterator iter1 = m.v1.begin();
	while(iter1!=m.v1.end() && iter1->m_amount !=0)
	{
		sprintf(buf1,"%s'%s','%s','%s',%lf,%d)",buf2,iter1->m_name,iter1->m_author,iter1->m_publish,iter1->m_price,iter1->m_amount);
		mysql_query(m_mysql,buf1);
//		cout<<buf1<<endl;
		iter1++;
	}
	destroyDB();


	initDB();
	mysql_set_character_set(m_mysql,"utf8");
	if(mysql_query(m_mysql,"delete from member"))
	{

		cout<<" query delete error"<<endl;
		return ;
	}
	char buf3[200]={0};
	char buf4[100]="insert into member values(";
	char buf7[200];
	char buf8[100]="update member set 上次登录时间=now() where ID=";
	vector<Member>::iterator iter2 = m.v2.begin();
	while(iter2!=m.v2.end())
	{		
		sprintf(buf3,"%s%d,'%s','%s','%s','%s','%s','%s')",buf4,iter2->m_id,iter2->m_name,iter2->m_passwd,iter2->m_lev,iter2->m_tel,iter2->m_adress,iter2->m_time);
		mysql_query(m_mysql,buf3);
	sprintf(buf7,"%s%d",buf8,id);
	mysql_query(m_mysql,buf7);
//		cout<<buf3<<endl;
		iter2++;
	}
	


	destroyDB();


	initDB();
	mysql_set_character_set(m_mysql,"utf8");
	if(mysql_query(m_mysql,"delete from record"))
	{
		cout<<"query delete error"<<endl;
		return ;
	}
	char buf5[200]={0};
	char buf6[100]="insert into record values(";
	vector<Record>::iterator iter3 = m.v3.begin();
	while(iter3!=m.v3.end())
	{
		sprintf(buf5,"%s%d,'%s','%s',%d,%lf,%lf,%lf,%d,'%s')",buf6,iter3->m_num,iter3->m_name,iter3->m_author,iter3->m_amount,iter3->m_dst,iter3->m_postage,iter3->m_total,iter3->m_id,iter3->m_remark);
		mysql_query(m_mysql,buf5);
//		cout<<buf1<<endl;
		iter3++;
	}
	destroyDB();
}
