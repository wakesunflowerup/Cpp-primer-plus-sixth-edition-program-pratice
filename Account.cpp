#include <iostream>
 
#include "Account.h"
//using namespace std;

Account::Account()
{
	cout<<"Caution:defult account is established.\n";
	m_name="defult";
	m_account="defult";
	m_storage=0;
}
Account::Account(string & name,string & account,const int storage)
{
	cout<<"���������Ĺ��캯��������\n";
	m_name=name;
	m_account=account;
	if(storage<0)
	{
		cout<<"number of storage can`t be begative;"<<m_name<<" storage set to 0.\n";
		m_storage=0;
	}
	else
		m_storage=storage;
}
Account::~Account()
{
	cout<<"��������������\n";
}
void Account::show()
{
	cout<<"name: "<<m_name;
	cout<<"\naccount: "<<m_account;
	cout<<"\nstorage: "<<m_storage<<endl;
}
void Account::in(const int num)
{
	if(num<0)
	{
		cout<<"number of storage in can`t be begative.Transcation is aborted.\n";
	}
	else
		m_storage+=num;
	
}
void Account::out(const int num)
{
	if(num<0)
	{
		cout<<"number of storage out can`t be begative.Transcation is aborted.\n";
	}
	else
		m_storage-=num;
}
