#ifndef LIB
#define LIB
#include<string.h>
class lib
{
	public:
		char   m_name[20];
		char   m_author[20];
		char   m_publish[40];
		double m_price;
		int m_amount;
		lib();
		lib(char *name,char *author,char *publish,double price,int amount);
};
#endif
