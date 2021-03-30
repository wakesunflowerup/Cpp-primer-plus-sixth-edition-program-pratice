#include <iostream>
#include <cstring>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

//b, 因为Port没有被重新定义的方法只是对bottles进行操作，而Vintageport完全继承了这些方法，所以无需 
//重新定义，只需要直接使用即可； 而被重新定义的方法，重载运算符 + 和 << ，Show等需要对Vintageport
//新加入的对象进行操作，所以仍需修改定义，虽然只需要补充对新加入的nickname和year的操作，剩余的直接
//调用Port的方法；

//c，<<  友元不能是虚函数，因为友元不是类成员，只有成员才能使虚函数，如果这个原因引起了设计问题，可以通过
//让友元函数使用虚成员函数来解决。 
//   =  赋值运算符不会被继承， 函数参数不同，属于重新定义，并不会生成两个虚函数的重载版本，而是隐藏了Port的= 
// 如果在派生类中重新定义函数，将不是使用相同的函数特征标覆盖基类声明，而是隐藏同名的基类方法，不管参数特征标如何 
//  派生类继承的方法的特征标与基类完全相同，但赋值运算符的特征标随类而异，这是因为它包含一个类型为其所属类的形参 



class Port{
private:
	char * brand;	
	char style[20];
	int bottles;
public:	
	Port(const char *br="none",const char *st="none",int b=0);
	Port(const Port & p);
	virtual ~Port(){delete [] brand;}
	Port & operator=(const Port & p);
	Port & operator+=(int b);
	Port & operator-=(int n);
	int BottleCount()const {return bottles;}
	virtual void Show() const;
	friend ostream & operator<<(ostream & os,const Port & p);
};

class Vintageport : public Port{
private:
	char * nickname;
	int year;
public:
	Vintageport();
	Vintageport(const char * br,char * st,int b,const char *nn,int y);
	Vintageport(const Vintageport &vp );
	~Vintageport() {delete [] nickname;}
	Vintageport & operator=(const Vintageport & vp);
	void Show() const;
	friend ostream & operator<<(ostream &os,const Vintageport & vp);
};

Port::Port(const char *br,const char *st,int b)
{
	brand=new char[strlen(br)+1];
	strcpy(brand,br);
	strcpy(style,st);
	bottles=b;
}
Port::Port(const Port &p)
{
	brand=new char[strlen(p.brand)+1];
	strcpy(brand,p.brand);
	strcpy(style,p.style);
	bottles=p.bottles;
}
Port & Port::operator=(const Port &p)
{
	if(this==&p)
		return *this;
	delete [] brand;
	brand=new char[strlen(p.brand)+1];
	strcpy(brand,p.brand);
	strcpy(style,p.style);
	bottles=p.bottles;
	return *this;
}
Port & Port::operator+=(int b)
{
	bottles+=b;
	return *this;
}
Port & Port::operator-=(int n)
{
	bottles-=n;
	return *this;
}
void Port::Show() const
{
	cout<<"Brand: "<<brand<<"\nKind: "<<style<<"\nBottles: "<<bottles<<endl;
}
ostream & operator<<(ostream & os,const Port & p)
{
	os<<p.brand<<", "<<p.style<<", "<<p.bottles;
	return os;
}

Vintageport::Vintageport():Port()
{
	nickname=new char[1];
	nickname[0]='\0';
	year=0;
} 
Vintageport::Vintageport(const char * br,char * st,int b,const char *nn,int y):Port(br,st,b)
{
	nickname=new char[strlen(nn)+1];
	strcpy(nickname,nn);
	year=y;
}

Vintageport::Vintageport(const Vintageport &vp):Port(vp) 
{
	nickname=new char[strlen(vp.nickname)+1];
	strcpy(nickname,vp.nickname);
	year=vp.year;
}
Vintageport & Vintageport::operator=(const Vintageport & vp)
{
	if(this==&vp)
		return *this;
	Port::operator=(vp);
	delete [] nickname;
	nickname=new char[strlen(vp.nickname)+1];
	strcpy(nickname,vp.nickname);
	year=vp.year;
	return *this;
}
void Vintageport::Show() const
{
	Port::Show();
	cout<<"Nickname: "<<nickname<<"\nYear: "<<year<<endl;
}
ostream & operator<<(ostream &os,const Vintageport & vp)
{
	os<<(const Port &)vp;
	os<<", "<<vp.nickname<<", "<<vp.year;
	return os;
}

int main(int argc, char** argv) {
	using std::cout;
	using std::endl;
	Port a("Sunflower","Wakeup",100);
	Port b;
	Port c;
	c=a;
	cout<<"#a:"<<endl;
	a.Show();
	cout<<a<<endl;
	cout<<"#b:"<<endl;
	b.Show();
	cout<<b<<endl;
	cout<<"#c:"<<endl;
	c.Show();
	cout<<c<<endl;
	cout<<"c+5"<<endl;
	c+=5;
	c.Show();
	cout<<c<<endl;
	Vintageport d("Sunflower","Wakeup",100,"DayDayUp",2021);
	Vintageport e;
	Vintageport f;
	f=d;
	cout<<"#d:"<<endl;
	d.Show();
	cout<<d<<endl;
	cout<<"#e:"<<endl;
	e.Show();
	cout<<e<<endl;
	cout<<"#f:"<<endl;
	f.Show();
	cout<<f<<endl;
	cout<<"f+5"<<endl;
	f+=5;
	f.Show();
	cout<<f<<endl;
	
	//下面的东西，指针和引用调用的 << 方法相同，均为Port的方法； 
		//调用的 = 方法不同，引用调用Port方法，指针调用Vintageport方法
			//why? 
	
	cout<<endl<<endl<<endl;
	Port &test=d;
	Port *test1=&d; 
	
	cout<<test<<endl;
	cout<<*test1<<endl;
	cout<<endl;
	
	test.Show();
	test1->Show();
	cout<<endl;
	 
	Vintageport t("yasen","liu",1242,"asd",124);
	test=t;
	test1=&t;
	cout<<test<<endl;
	cout<<*test1<<endl;
	cout<<endl;
	
	test.Show();
	test1->Show();
	return 0;
}
