#include <iostream>
#include <cmath>
#include "15-2exc_mean.h"
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

double hmean(double a,double b);
double gmean(double a,double b);

int main(int argc, char** argv) {
	double x,y,z;
	cout<<"Enter 2 numbers: ";
	while(cin>>x>>y)
	{
		try
		{
			z=hmean(x,y);
			cout<<"Harmonic mean of "<<x<<" and "<<y<<" is "<<z<<endl;
			cout<<"Geometric mean of "<<x<<" and "<<y<<" is "<<gmean(x,y)<<endl;
			cout<<"Enter next set of numbers (q to quit): ";
		}
		catch(bad &b)//第二题分别写两个catch ，bad_hmean &bh , bad_gmean &bg 
		{
			cout<<b.what();
			cout<<"x: "<< b.v1_val() <<"\ty: "<<b.v2_val()<<endl;//第二题不用输出这行 
			cout<<"Sorry,you don`t get to play anymore.\n";
			break;//第二题continue，第三题break 
		}
	}
	

	cout<<"bye"<<endl;
	return 0;
}

double hmean(double a,double b)
{
	if(a==-b)
		throw bad_hmean(a,b);
	return 2.0*a*b/(a+b);
}
double gmean(double a,double b)
{
	if(a<0||b<0)
		throw bad_gmean(a,b);
	return std::sqrt(a*b);
}
