#include "11-7com.h" 
complex::complex(double a,double b)
{
	real=a;
	imaginary=b;
}
complex::complex()
{
	real=0;
	imaginary=0;
}
complex::~complex()
{
}
ostream & operator<<(ostream &os,const complex &a)
{
	os<<"("<<a.real<<","<<a.imaginary<<"i)";
	return os;
}
istream & operator>>(istream &is,complex &a)
{
	double m,n;
	cout<<"real: ";
	if(!(is>>m))
		return is;
	cout<<"imaginary: ";
	is>>n;
	a=complex(m,n);
	return is;
}
complex operator+(const complex &a,const complex &b)
{
	return complex(a.real+b.real,a.imaginary+b.imaginary);
}
complex operator-(const complex &a,const complex &b)
{
	return complex(a.real-b.real,a.imaginary-b.imaginary);
}
complex operator*(const complex &a,const complex &b)
{
	return complex(a.real*b.real-a.imaginary*b.imaginary,a.real*b.imaginary+a.imaginary*b.real);
}
complex operator*(double a,const complex &b)
{
	return complex(b.real*a,b.imaginary*a);
}
complex operator*(const complex &b,double a)
{
	return complex(b.real*a,b.imaginary*a);
}
complex operator-(const complex &a)
{
	return complex(a.real,-a.imaginary);
}
