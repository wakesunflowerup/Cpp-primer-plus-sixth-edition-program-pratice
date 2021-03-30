#ifndef ABSTR_H
#define ABSTR_H 
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

//不动态分配内存写个吉尔复制构造函数，全给你删了，默认的不香吗 
//在类内加个数据表示类型几乎得改所有的函数，写在外面吧
//如果让 employee 变成基类，也几乎得所有的函数，还是让 abstr_emp 作为基类 
enum classkind{Abstr_emp,Employee,Manager,Fink,Highfink}; 

class abstr_emp
{
private:
	std::string fname;             // abstr_emp's first name
	std::string lname;             // abstr_emp's last name
	std::string job;
public:
	abstr_emp():fname("sunflower"),lname("wakeup"),job("programer") {}
	abstr_emp(const std::string & fn, const std::string & ln,const std::string & j):fname(fn),lname(ln),job(j) {}
	virtual void ShowAll() const;        // labels and shows all data
	virtual void SetAll();                 // prompts user for values
	virtual void WriteAll(ofstream & fout) const;
	virtual void GetAll(ifstream & fin);
	friend std::ostream & operator<<(std::ostream & os, const abstr_emp & e);
	// just displays first and last name
	virtual ~abstr_emp() = 0;              // virtual base class
};
class employee : public abstr_emp
{
public:
	employee():abstr_emp() {}
	employee(const std::string & fn, const std::string & ln,const std::string & j):abstr_emp(fn,ln,j) {}
	virtual void ShowAll() const;
	virtual void SetAll();
	virtual void WriteAll(ofstream & fout) const;
	virtual void GetAll(ifstream & fin);
};

class manager: virtual public abstr_emp
{
private:
    int inchargeof;                 // number of abstr_emps managed
protected:
    int InChargeOf() const { return inchargeof; }      // output
    int & InChargeOf() { return inchargeof; }            // input
public:
	manager():abstr_emp(),inchargeof(0) {}
	manager(const std::string & fn, const std::string & ln,const std::string & j, int ico = 0)
		:abstr_emp(fn,ln,j),inchargeof(ico) {}
	manager(const abstr_emp & e, int ico):abstr_emp(e),inchargeof(ico) {}
//	manager(const manager & m);
	virtual void ShowAll() const;
	virtual void SetAll();
	virtual void WriteAll(ofstream & fout) const;
	virtual void GetAll(ifstream & fin);
};


class fink: virtual public abstr_emp
{
private:
    std::string reportsto;              // to whom fink reports
protected:
    const std::string ReportsTo() const { return reportsto; }
    std::string & ReportsTo() { return reportsto; }
public:
    fink():abstr_emp(),reportsto("daydayup") {}
    fink(const std::string & fn, const std::string & ln,const std::string & j, const std::string & rpo)
    	:abstr_emp(fn,ln,j),reportsto(rpo) {}
    fink(const abstr_emp & e, const std::string & rpo):abstr_emp(e),reportsto(rpo) {}
//    fink(const fink & e);
    virtual void ShowAll() const;
    virtual void SetAll();
    virtual void WriteAll(ofstream & fout) const;
    virtual void GetAll(ifstream & fin);
};
class highfink: public manager, public fink   // management fink
{
public:
    highfink() {}
    highfink(const std::string & fn, const std::string & ln,const std::string & j, const std::string & rpo,int ico)
    	:abstr_emp(fn,ln,j),manager(fn,ln,j,ico),fink(fn,ln,j,rpo) {}
	highfink(const abstr_emp & e, const std::string & rpo, int ico):abstr_emp(e),manager(e,ico),fink(e,rpo) {}
    highfink(const fink & f, int ico):abstr_emp(f),manager(f,ico),fink(f) {}
	highfink(const manager & m, const std::string & rpo):abstr_emp(m),manager(m),fink(m,rpo) {}
//	highfink(const highfink & h);
	virtual void ShowAll() const;
	virtual void SetAll();
	virtual void WriteAll(ofstream & fout) const;
	virtual void GetAll(ifstream & fin);
};
#endif
