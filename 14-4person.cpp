#include <iostream>
#include "14-4person.h"

void Person::Data() const
{
	cout<<"Firstname: "<<fname<<"\nLastname: "<<lname<<endl;
}
void Person::Get()
{
	cout<<"Enter Firstname: ";
	getline(cin,fname);
	cout<<"Enter Lastname: ";
	getline(cin,lname);
}

void Gunslinger::Data() const
{
	cout<<"Scores: "<<scores<<"\nTimes: "<<times<<endl;
}
void Gunslinger::Get()
{
	cout<<"Enter scores: ";
	cin>>scores;
	cout<<"Enter times: ";
	cin>>times;
}
void Gunslinger::Set()
{
	Person::Get();
	Get();
}
void Gunslinger::Show() const
{
	Person::Data();
	Data();
}

void PokerPlayer::Data() const
{
	cout<<"Poker: "<<num<<endl;
}
void PokerPlayer::Get()
{
	cout<<"Enter Poker: ";
	cin>>num;
}
void PokerPlayer::Set()
{
	Person::Get();
	Get();
}
void PokerPlayer::Show() const
{
	Person::Data();
	Data();
}

void BadDude::Data() const
{
	Gunslinger::Data();
	PokerPlayer::Data();
}
void BadDude::Get()
{
	Gunslinger::Get();
	PokerPlayer::Get();
}
void BadDude::Set()
{
	Person::Get();
	Get();
}
void BadDude::Show() const
{
	Person::Data();
	Data();
}
