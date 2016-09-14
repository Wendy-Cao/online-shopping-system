#include"member.h"
Member::Member()
{
}
Member::Member(int id,char *name,char *passwd,char *lev,char *tel,char *adress,char *time)
{
	m_id=id;
	strcpy(m_name,name);
	strcpy(m_passwd,passwd);
	strcpy(m_lev,lev);
	strcpy(m_tel,tel);
	strcpy(m_adress,adress);
	strcpy(m_time,time);
}

