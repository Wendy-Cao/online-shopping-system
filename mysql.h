#ifndef _MYSQL_H
#define _MYSQL_H
#define DB_HOST	    "127.0.0.1"
#define DB_USER     "root"
#define DB_PASS     "123456"
#define DB_NAME     "qwe"
#include<mysql/mysql.h>
class OprDB
{
	static MYSQL *m_mysql;   // 数据库句柄
	public:	
	static void initDB();	 // 1.初始化连接
	static void destroyDB(); // 2.断开连接	
	static void mysqltov();
	static void vtomysql();
};
#endif
