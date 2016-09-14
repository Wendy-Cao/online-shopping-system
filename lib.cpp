#include"lib.h"
lib::lib()
{
};
lib::lib(char *name,char *author,char *publish,double price,int amount)
{
	strcpy(m_name,name);
	strcpy(m_author,author);
	strcpy(m_publish,publish);
        m_price=price;
	m_amount=amount;
}
