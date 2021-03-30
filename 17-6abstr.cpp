#include "17-6abstr.h"

//前面两个快写吐了,再简化我就要GG了,全给你复制粘贴过来 
//别改需求！！！改动老代码的接口比直接写新的麻烦多了 
void abstr_emp::ShowAll() const        // labels and shows all data
{
	cout<<"Firstname: "<<fname<<"\nLastname: "<<lname<<"\nJob: "<<job<<endl;
}
void abstr_emp::SetAll()                 // prompts user for values
{
	cout<<"Enter Firstname: ";
	getline(cin,fname);
	cout<<"Enter Lastname: ";
	getline(cin,lname);
	cout<<"Enter job: ";
	getline(cin,job);
}
void abstr_emp::WriteAll(ofstream & fout) const
{
	fout<<fname<<endl<<lname<<endl<<job<<endl;
}
void abstr_emp::GetAll(ifstream & fin)
{
	getline(fin,fname);
	getline(fin,lname);
	getline(fin,job); 
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
void employee::WriteAll(ofstream & fout) const
{
	fout<<Employee<<endl;
	abstr_emp::WriteAll(fout);
}
void employee::GetAll(ifstream & fin)
{
	abstr_emp::GetAll(fin);
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
void manager::WriteAll(ofstream & fout) const
{
	fout<<Manager<<endl;
	abstr_emp::WriteAll(fout);
	fout<<inchargeof<<endl;
}
void manager::GetAll(ifstream & fin)
{
	abstr_emp::GetAll(fin);
	fin>>inchargeof;
	fin.get();
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
void fink::WriteAll(ofstream & fout) const
{
	fout<<Fink<<endl;
	abstr_emp::WriteAll(fout);
	fout<<reportsto<<endl;
}
void fink::GetAll(ifstream & fin)
{
	abstr_emp::GetAll(fin);
	getline(fin,reportsto);
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
	cin>>InChargeOf();
	cin.get();
	cout<<"Enter reports to: ";
	getline(cin,ReportsTo());
}
void highfink::WriteAll(ofstream & fout) const
{
	fout<<Highfink<<endl;
	abstr_emp::WriteAll(fout);
	fout<<manager::InChargeOf()<<endl<<ReportsTo()<<endl;
	
}
void highfink::GetAll(ifstream & fin)
{
	abstr_emp::GetAll(fin);
	fin>>InChargeOf();
	fin.get();
	getline(fin,ReportsTo());
}
