#include "15-1tv.h"
#include <iostream>


bool Tv::volup()
{
	if(volume<MaxVal)
	{
		volume++;
		return true;
	}
	else 
		return false;
}

bool Tv::voldown()
{
	if(volume>MinVal)
	{
		volume--;
		return true;
	}
	else
		return false;
}

void Tv::chanup()
{
	if(channel<maxchannel)
		channel++;
	else
		channel=1;
}

void Tv::chandown()
{
	if(channel>1)
		channel--;
	else
		channel=maxchannel;
}

void Tv::settings() const
{
	using std::cout;
	using std::endl;
	cout<<"TV is "<<(state==Off?"Off":"On")<<endl;
	if(state==On)
	{
		cout<<"Volume setting = "<<volume<<endl;
		cout<<"Channel setting = "<<channel<<endl;
		cout<<"Mode = "<<(mode==Antenna?"antenna":"cable")<<endl;
		cout<<"Input = "<<(input==TV?"TV":"DVD")<<endl;
	}
}

void Tv::buzz(Remote &r)
{
	r.re_commu();
}

bool Tv::set_state(Remote &r)
{
	if(state==On)
	{
		r.set_state();
		return true;
	}
	else
		return false;
}

void Remote::re_commu() const
{
	if(state==Commu)
		std::cout<<"用什么互动方式呢？？？？"<<std::endl; 
	else
		std::cout<<"不在互动模式，不能互动，请设置为互动模式。"<<std::endl;
}

void Remote::showstate() const
{
	std::cout<<"state: "<<(state==Commu?"Commu":"Uncommu")<<std::endl;
}
