#include "14-3workermi.h"
#include <iostream>
Worker::~Worker() {}

void Worker::Data() const
{
	cout<<"Name: "<<fullname<<"\nEmployee ID: "<<id<<endl;
}
void Worker::Get()
{
//	cout<<"Enter worker`s fullname: "
	getline(cin,fullname);
	cout<<"Enter Worker`s ID: ";
	cin>>id;
	while(cin.get()!='\n')
		continue;
}

void Waiter::Data() const
{
	cout<<"Panache rating: "<<panache<<endl;
}
void Waiter::Get()
{
	cout<<"Enter waiter`s panache rating: ";
	cin>>panache;
	while(cin.get()!='\n')
		continue;
}

void Waiter::Set()
{
	cout<<"Enter waiter`s name: ";
	Worker::Get();
	Get();
}
void Waiter::Show() const
{
	cout<<"Category: waiter\n";
	Worker::Data();
	Data();
}

void Singer::Data() const
{
	cout<<"Vocal range: "<<pv[voice]<<endl;
}
void Singer::Get()
{
	cout<<"Enter number for singer`s vocal range:\n";
	int i;
	for(i=0;i<Vtypes;i++)
	{
		cout<<i<<": "<<pv[i]<<"\t";
		if(i%4==3)
			cout<<"\n";
	}
	if(i%4!=0)
		cout<<"\n";
	cin>>voice;
	while(cin.get()!='\n')
		continue;	
}

char * Singer::pv[Singer::Vtypes]={"other ","alto ","contralto ","soprano ","bass ","baritone ","tenor "};	

void Singer::Set()
{
	cout<<"Enter singer`s name: ";
	Worker::Get();
	Get();
}
void Singer::Show() const
{
	cout<<"Category: singer\n";
	Worker::Data();
	Data();
}

void SingingWaiter::Data() const
{
	Waiter::Data(); 
	Singer::Data();
}
void SingingWaiter::Get()
{
	Waiter::Get(); 
	Singer::Get();
}

void SingingWaiter::Set()
{
	cout<<"Enter singing waiter`s name: ";
	Worker::Get();
	Get();
}
void SingingWaiter::Show() const
{
	cout<<"Category: singing waiter\n";
	Worker::Data();
	Data();
}
