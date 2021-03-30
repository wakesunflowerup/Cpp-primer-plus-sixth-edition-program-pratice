#include "11-5stone.h"

void Stonewt::setpo()
{
	pounds=stone*Lbs_per_stn+pds_left;
}
void Stonewt::setst()
{
	stone=pounds/Lbs_per_stn;
	pds_left=int(pounds)%Lbs_per_stn;
}
Stonewt::Stonewt(double lbs)
{
	pounds=lbs;
	setst();
	mode=PO;
}
Stonewt::Stonewt(int stn,double lbs)
{
	stone=stn;
	pds_left=lbs;
	setpo();
	mode=ST;
}
Stonewt::Stonewt()
{
	stone=pds_left=pounds=0;
	mode=PO;
}
Stonewt::~Stonewt()
{
}
void Stonewt::st_mode()
{
	mode=ST;
}
void Stonewt::po_mode()
{
	mode=PO;
}
ostream & operator<<(ostream &os,const Stonewt &a)
{
	if(a.mode==Stonewt::PO)
	{
		os<<a.pounds<<" pounds.";
	}
	else if(a.mode==Stonewt::ST)
	{
		os<<a.stone<<" stone, "<<a.pds_left<<" pounds.";
	}
	return os; 
}
Stonewt operator+(const Stonewt &a,const Stonewt &b)
{
	return Stonewt(a.pounds+b.pounds);
}
Stonewt operator-(const Stonewt &a,const Stonewt &b)
{
	return Stonewt(a.pounds-b.pounds);
}
Stonewt operator*(const Stonewt &a,double n)
{
	return Stonewt(a.pounds*n);
}
Stonewt operator*(double n,const Stonewt &a)
{
	return Stonewt(a.pounds*n);
} 
bool operator>(const Stonewt &a,const Stonewt &b)
{
	return a.pounds>b.pounds?true:false;
}
bool operator>=(const Stonewt &a,const Stonewt &b)
{
	return a.pounds>=b.pounds?true:false;
}
bool operator<(const Stonewt &a,const Stonewt &b)
{
	return a.pounds<b.pounds?true:false;
}
bool operator<=(const Stonewt &a,const Stonewt &b)
{
	return a.pounds<=b.pounds?true:false;
}
bool operator==(const Stonewt &a,const Stonewt &b)
{
	return a.pounds==b.pounds?true:false;
}
bool operator!=(const Stonewt &a,const Stonewt &b)
{
	return a.pounds!=b.pounds?true:false;
}
