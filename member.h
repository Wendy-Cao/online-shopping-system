#ifndef MEMBER
#define MEMBER
#include<string.h>
#include<iostream>
class Member
{
	public:
	int m_id;
	char m_name[20];
	char m_passwd[20];
	char m_lev[20];
	char m_tel[20];
	char m_adress[40];
	char m_time[40];
	Member();
	Member(int id,char *name,char *passwd,char *lev,char *tel,char *adress,char *time);
};
#endif
