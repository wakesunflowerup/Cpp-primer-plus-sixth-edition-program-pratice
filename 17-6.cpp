#include <iostream>
#include "17-6abstr.h"
#include <cstdlib>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
 
const char * file="17-6job.txt";
const int MAX=10;

void eatline()
{
	while(cin.get()!='\n')
		continue;
}

int main(int argc, char** argv) {
	
	ofstream fout;
	ifstream fin;
	abstr_emp * pc[MAX]; 
	int classtype;
	char ch;
	int n=0;
	
	fin.open(file);
	if(fin.is_open())
	{
		cout<<"Here are the current contents of the "<<file<<" file.\n";
		while((fin>>classtype).get(ch))
		{
			switch(classtype){
				case Employee:	pc[n]=new employee;
								break;
				case Manager:	pc[n]=new manager; 
								break;
				case Fink:		pc[n]=new fink;
								break;
				case Highfink:	pc[n]=new highfink;
								break;
			}
			pc[n]->GetAll(fin);
			pc[n++]->ShowAll();
			cout<<endl; 
		}
		cout<<"There are: "<<n<<" employee.\n";
	}
	fin.close();
	
	fout.open(file,ios_base::out|ios_base::app);
	if(!fout.is_open())
	{
		cerr<<"Can`t open "<<file<<" file for output.\n";
		exit(EXIT_FAILURE);
	}
	
	cout<<"Do you want to add data? <y\\n>.\n";
	while(cin.get()=='y')
	{
		if(n==MAX)
		{
			cout<<"\nToo many!\nTerminated\n";
			break;
		}
		eatline();
		cout<<"What job?\n"
			"1.Employee   2.Manager   3.Fink   4.Highfink\n";
		(cin>>classtype).get();
		switch(classtype){
			case Employee:	pc[n]=new employee;
							break;
			case Manager:	pc[n]=new manager;
							break;
			case Fink:		pc[n]=new fink;
							break;
			case Highfink:	pc[n]=new highfink;
							break;
		}
		pc[n]->SetAll();
		pc[n++]->WriteAll(fout);

		cout<<"Do you want to add data? <y\\n>.\n";
	}
	fout.close();
	
	fin.clear();
	fin.open(file);
	n=0;
	if(fin.is_open())
	{
		cout<<"Here are the new contents of the "<<file<<" file.\n";
		while((fin>>classtype).get(ch))
		{
			switch(classtype){
				case Employee:	pc[n]=new employee;
								break;
				case Manager:	pc[n]=new manager; 
								break;
				case Fink:		pc[n]=new fink;
								break;
				case Highfink:	pc[n]=new highfink;
								break;
			}
			pc[n]->GetAll(fin);
			pc[n++]->ShowAll(); 
			cout<<endl;
		}
		cout<<"There are "<<n<<" employee.\n";
	}
	fin.close();
	
	return 0;
}
