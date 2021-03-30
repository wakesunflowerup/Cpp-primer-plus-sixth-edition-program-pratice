#include "14-5abstr.h"
using namespace std;
//ǰ��������д����,�ټ��Ҿ�ҪGG��,ȫ���㸴��ճ������ 
//������󣡣����Ķ��ϴ���Ľӿ�����ĸ���ճ����������ʵ���︴��ճ����Ҫ�Ĵ����� 
void abstr_emp::ShowAll() const        // labels and shows all data
{
	cout<<"Firstname: "<<fname<<"\nLastname: "<<lname<<"\nJob: "<<job<<endl;
}
void abstr_emp::SetAll()                 // prompts user for values
{
	while(cin.get()!='\n')
		continue;
	cout<<"Enter Firstname: ";
	getline(cin,fname);
	cout<<"Enter Lastname: ";
	getline(cin,lname);
	cout<<"Enter job: ";
	getline(cin,job);
}
ostream & operator<<(std::ostream & os, const abstr_emp &e)// just displays first and last name
{
	os<<"Firstname: "<<e.fname<<"\nLastname: "<<e.lname<<"\nJob: "<<e.job<<endl;
	return os; 
}
 
abstr_emp::~abstr_emp() {}

void employee::ShowAll() const
{
	abstr_emp::ShowAll();
}
void employee::SetAll()
{
	abstr_emp::SetAll();
}

void manager::ShowAll() const
{
	abstr_emp::ShowAll();
	cout<<"In charge of: "<<inchargeof<<endl;
}
void manager::SetAll()
{
	abstr_emp::SetAll();
	cout<<"Enter in charge of: ";
	cin>>inchargeof;
	cin.get();
}

void fink::ShowAll() const
{
	abstr_emp::ShowAll();
	cout<<"Reports to: "<<reportsto<<endl;
}
void fink::SetAll()
{
	abstr_emp::SetAll();
	cout<<"Enter reports to: ";
	getline(cin,reportsto);
}

void highfink::ShowAll() const
{
	abstr_emp::ShowAll();
	cout<<"In charge of: "<<InChargeOf()<<"\nReports to: "<<ReportsTo()<<endl;
}
void highfink::SetAll()
{
	abstr_emp::SetAll();
	cout<<"Enter in charge of: ";
	cin>>manager::InChargeOf();
	cin.get();
	cout<<"Enter reports to: ";
	getline(cin,fink::ReportsTo());
}

