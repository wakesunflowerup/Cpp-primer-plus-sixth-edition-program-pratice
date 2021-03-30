#ifndef ACCOUNT_H
#define ACCOUNT_H
#include <string>
using namespace std;
class Account{
private:
	string m_name;//姓名 
	string m_account;//账户 
	long long m_storage;//存款 
public:
	Account();//默认姓名账户存款（unknow，unknow（这里应该可以搞一个库分配账户），0） 
	Account(string & name,string & account,const int storage);//输入的姓名账户存款 
	~Account();//析构函数 
	void show();//显示储户姓名，账号和存款 
	void in(const int num);//存入指定的钱 
	void out(const int num);//取出指定的钱 
};

#endif
