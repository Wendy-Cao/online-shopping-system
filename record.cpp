#include"record.h"
Record::Record()
{
}

Record::Record(int num,char *name,char *author,int amount,double dst,double postage,double total,int id,char *remark)
{
	m_num=num;
	strcpy(m_name,name);
	strcpy(m_author,author);
	m_amount=amount;
	m_dst=dst;
	m_postage=postage;
	m_total=total;
	m_id=id;
	strcpy(m_remark,remark);
}
