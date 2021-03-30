#ifndef PERSON_H
#define PERSON_H

#include <string>
using namespace std;

class Person{
private:	
	string fname;
	string lname;
protected:
	virtual void Data() const;
	virtual void Get();
public:
	Person():fname("sunflower"),lname("wakeyp") {}
	Person(const string &s1,const string &s2):fname(s1),lname(s2) {}
	virtual ~Person() {}
	virtual void Set()=0;
	virtual void Show() const =0;		
};

class Gunslinger:virtual public Person{
private:
	int scores;
	double times;
protected:
	void Data() const;
	void Get();
public:	
	Gunslinger():Person(),scores(0),times(0.0) {}
	Gunslinger(const string &s1,const string &s2,int s=0,double t=0):Person(s1,s2),scores(s),times(t) {}
	Gunslinger(const Person &p,int s=0,double t=0):Person(p),scores(s),times(t) {}
	double Draw() const {return times;}
	void Set();
	void Show() const;
};
 
class PokerPlayer:virtual public Person{
private:
	int num;
protected:
	void Data() const;
	void Get();
public:	
	PokerPlayer():Person(),num(0) {}
	PokerPlayer(const string &s1,const string &s2,int n=0):Person(s1,s2),num(n) {}
	PokerPlayer(const Person &p,int n=0):Person(p),num(n) {}
	int Draw() const {return num%52+1;}
	void Set();
	void Show() const;
};

class BadDude:public Gunslinger,public PokerPlayer{
protected:
	void Data() const;
	void Get();	
public:
	BadDude() {}
	BadDude(const string &s1,const string &s2,int s=0,double t=0,int n=0):Person(s1,s2),Gunslinger(s1,s2,s,t),PokerPlayer(s1,s2,n) {}
	BadDude(const Person &p,int s=0,double t=0,int n=0):Person(p),Gunslinger(p,s,t),PokerPlayer(p,n) {}
	BadDude(const Gunslinger &gl,int n=0):Person(gl),Gunslinger(gl),PokerPlayer(gl,n) {}
	BadDude(const PokerPlayer &pp,int s=0,double t=0):Person(pp),Gunslinger(pp,s,t),PokerPlayer(pp) {}
	double Gdraw() {return Gunslinger::Draw();}
	int Cdraw() const {return PokerPlayer::Draw();}
	void Set();
	void Show() const;
};

#endif
