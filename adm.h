#ifndef ADM
#define ADM
#include<vector>
#include"lib.h"
#include"member.h"
#include"record.h"
#include<stdio.h>
#include<time.h>

using namespace std;
class adm
{
	public:
		vector<lib>v1;
		vector<Member>v2;
		vector<Record>v3;
		
		void show_lib();
		void add_lib();
		void del_lib();
		void del_book_lib();
		void select_lib();
		void select_book_lib();
		void select_author_lib();
		void change_lib();
		void change_book_lib();

		void show_member();
		void add_member();

		void show_record();
		void show_one_record();
        
		void shop_book(vector<Member>::iterator t);
		void squre_book(vector<lib>::iterator it,int a,vector<Member>::iterator t);
 		void squre_book_VIP(vector<lib>::iterator it,int a,vector<Member>::iterator t);
		
		void member_vip(vector<Member>::iterator t);
		void member_select_record(vector<Member>::iterator iter);
		void member_back();
};
#endif
