#ifndef RECORD
#define RECORD
#include<string.h>
class Record
{
	public:
		int m_num;
		char m_name[20];
		char m_author[20];
		int m_amount;
		double m_dst;
		double m_postage;
		double m_total;
		int m_id;
		char m_remark[100];
		Record();
		Record(int num,char *name,char *author,int amount,double dst,double postage,double total,int id,char *remark);
};
#endif
