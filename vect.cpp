#include"vect.h"
#include <cmath>
const double Rad_to_deg=45.0/atan(1.0);

void Vector::set_mag()
{
	mag=sqrt(x*x+y*y);
}
void Vector::set_ang()
{
	if(x==0.0&&y==0.0)
		ang=0.0;
	else
		ang =atan2(y,x);
}
void Vector::set_x()
{
	x=mag*cos(ang);
}
void Vector::set_y()
{
	y=mag*sin(ang);
}

Vector::Vector()
{
	mag=ang=x=y=0.0;
	mode=RECT;
}
Vector::Vector(double n1,double n2,Mode form)
{
	mode=form;
	if(form==POL)
	{
		mag=n1;
		ang=n2;
//		set_x();
//		set_y();
	}
	else if(form==RECT)
	{
		x=n1;
		y=n2/Rad_to_deg;
//		set_mag();
//		set_ang();
	}
	else
	{
		cout<<"第三个参数只能为RECT或POL，此向量被设置为0.\n";
		mag=ang=x=y=0;
		mode=RECT;
	}
}
void Vector::reset(double n1,double n2,Mode form)
{
	mode=form;
	if(form==POL)
	{
		mag=n1;
		ang=n2;
//		set_x();
//		set_y();
	}
	else if(form==RECT)
	{
		x=n1;
		y=n2/Rad_to_deg;
//		set_mag();
//		set_ang();
	}
	else
	{
		cout<<"第三个参数只能为RECT或POL，此向量被设置为0.\n";
		mag=ang=x=y=0;
		mode=RECT;
	}
}
Vector::~Vector()
{
}
double Vector::xval()
{
	x=mag*cos(ang);
	return x;
}
double Vector::yval() 
{
	y=mag*sin(ang);
	return y;
}
double Vector::magval() 
{
	mag=sqrt(x*x+y*y);
	return mag;
}
double Vector::angval() 
{
	if(x==0&&y==0)
		ang=0.0;
	else
		ang=atan2(y,x);
	return ang;
}
void Vector::polar_mode()
{
	mode=POL;
}
void Vector::rect_mode()
{
	mode=RECT;
}
Vector Vector::operator+(Vector &b)const
{
	return Vector(x+b.xval(),y+b.yval());
}
Vector Vector::operator-(Vector &b)const
{
	return Vector(x-b.xval(),y-b.yval());
}
Vector Vector::operator-()const
{
	return Vector(-x,-y);
}
Vector Vector::operator*(double n)const
{
	return Vector(x*n,y*n);
}
Vector operator*(double n,const Vector & a)
{
	return a*n;
}
ostream & operator<<(ostream & os,const Vector & v)
{
	if(v.mode==Vector::RECT)
		os<<"(x,y) = ("<<v.x<<", "<<v.y<<")";
	else if(v.mode==Vector::POL)
		os<<"(m,a) = ("<<v.mag<<", "<<v.ang*Rad_to_deg<<")";
	else 
		os<<"向量的格式不正确，请检查向量格式.";
	return os;
}
