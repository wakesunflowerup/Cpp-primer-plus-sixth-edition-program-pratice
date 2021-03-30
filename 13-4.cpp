#include <iostream>
#include <cstring>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

//b, ��ΪPortû�б����¶���ķ���ֻ�Ƕ�bottles���в�������Vintageport��ȫ�̳�����Щ�������������� 
//���¶��壬ֻ��Ҫֱ��ʹ�ü��ɣ� �������¶���ķ�������������� + �� << ��Show����Ҫ��Vintageport
//�¼���Ķ�����в��������������޸Ķ��壬��Ȼֻ��Ҫ������¼����nickname��year�Ĳ�����ʣ���ֱ��
//����Port�ķ�����

//c��<<  ��Ԫ�������麯������Ϊ��Ԫ�������Ա��ֻ�г�Ա����ʹ�麯����������ԭ��������������⣬����ͨ��
//����Ԫ����ʹ�����Ա����������� 
//   =  ��ֵ��������ᱻ�̳У� ����������ͬ���������¶��壬���������������麯�������ذ汾������������Port��= 
// ����������������¶��庯����������ʹ����ͬ�ĺ��������긲�ǻ�����������������ͬ���Ļ��෽�������ܲ������������ 
//  ������̳еķ������������������ȫ��ͬ������ֵ�������������������죬������Ϊ������һ������Ϊ����������β� 



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
	
	//����Ķ�����ָ������õ��õ� << ������ͬ����ΪPort�ķ����� 
		//���õ� = ������ͬ�����õ���Port������ָ�����Vintageport����
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
