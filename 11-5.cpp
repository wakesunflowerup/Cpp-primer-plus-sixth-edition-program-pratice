#include "11-5stone.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
//	Stonewt a(33);
//	Stonewt b(5,2);
//	Stonewt c;
//	cout<<a<<endl;
//	cout<<b<<endl;
//	a.st_mode();
//	b.po_mode();
//	b.st_mode();
//	cout<<a<<endl;
//	cout<<b<<endl;
//	c=a+b;
//	cout<<c<<endl;
//	c=b-a;
//	cout<<c<<endl;
//	c=a*2;
//	cout<<c<<endl;
//	c=2*b;
//	cout<<c<<endl;
//	c.st_mode();
//	cout<<c<<endl;
//	a>b?cout<<a<<endl:cout<<b<<endl;
	Stonewt arr[6]={Stonewt(313),{30,2},(5)};
	for(int i=3;i<6;i++)
	{
		double n;
		cout<<"输入物品重量: ";
		cin>>n;
		arr[i]=Stonewt(n);
	}
	Stonewt max=arr[0],min=arr[0],com=Stonewt(11,0);
	int num=0;
	for(int i=0;i<6;i++)
	{
		max=max>arr[i]?max:arr[i];
		min=min<arr[i]?min:arr[i];
		num+=arr[i]>=com?1:0;
	}
	cout<<max<<endl;
	cout<<min<<endl;
	cout<<num<<endl;
	
	return 0;
}
