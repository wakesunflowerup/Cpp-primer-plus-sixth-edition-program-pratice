#include "9-4namespace.h"
#include <iostream>
using namespace std;

double f_average(double arr[],int n){
	double sum;
	for(int i=0;i<n;i++)
		sum+=arr[i];
	return sum/4.0;
}

double f_max(double arr[],int n){
	double max=arr[0];
	for(int i=1;i<n;i++)
		max= max>arr[i]?max:arr[i];
	return max;
}

double f_min(double arr[],int n){
	double min=arr[0];
	for(int i=1;i<n;i++)
		min= min<arr[i]?min:arr[i];
	return min;
}

namespace SALES{
	void setSales(Sales & s,const double ar[],int n){
		for(int i=0;i<n;i++)
			s.sales[i]=ar[i];
		s.average=f_average(s.sales,n);
		s.max=f_max(s.sales,n);
		s.min=f_min(s.sales,n);
	}
	
	void setSales(Sales & s){
		for(int i=0;i<4;i++){
			cout<<"enter #"<<i+1<<" quarter`s sales: ";
			cin>>s.sales[i];
		} 
		s.average=f_average(s.sales,4);
		s.max=f_max(s.sales,4);
		s.min=f_min(s.sales,4);
	}
	
	void showSales(const Sales & s){
		for(int i=0;i<4;i++){
			cout<<"#"<<i+1<<" quarter`s sales: "<<s.sales[i]<<endl;
		} 
		cout<<"average: "<<s.average<<endl;
		cout<<"max: "<<s.max<<endl;
		cout<<"min: "<<s.min<<endl;
	}
}
