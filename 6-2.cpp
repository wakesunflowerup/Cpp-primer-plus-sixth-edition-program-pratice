#include <iostream>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	double d[10];
	cout<<"enter up to 10 numbers:"<<endl;
	int i=0;
	cout<<"#1:";
	while(i<10&&cin>>d[i]){
		if(++i<10)
		cout<<"#"<<i+1<<":";
	}
	double sum=0;
	double ave=0;
	int count=0;
	for(int j=0;j<i;j++)
	sum+=d[j];
	ave=sum/i;
	if(i==0)
	cout<<"no number\n";
	else{
		for(int j=0;j<i;j++)
		{
			if(d[j]>ave)
			count++;
		}
		cout<<"average is "<<ave<<endl;
		cout<<"there is "<<count<<" numbers over average"<<endl;
	}
	return 0;
}
