#ifndef ACCOUNT_H
#define ACCOUNT_H
#include <string>
using namespace std;
class Account{
private:
	string m_name;//���� 
	string m_account;//�˻� 
	long long m_storage;//��� 
public:
	Account();//Ĭ�������˻���unknow��unknow������Ӧ�ÿ��Ը�һ��������˻�����0�� 
	Account(string & name,string & account,const int storage);//����������˻���� 
	~Account();//�������� 
	void show();//��ʾ�����������˺źʹ�� 
	void in(const int num);//����ָ����Ǯ 
	void out(const int num);//ȡ��ָ����Ǯ 
};

#endif
