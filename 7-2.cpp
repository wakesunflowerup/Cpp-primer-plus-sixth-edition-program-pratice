#include <iostream>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
const int MAX=10;
int input(int a[],int b);
void show(int a[],int b);
void average(int a[],int b);

int main(int argc, char** argv) {
	int a[MAX];
	int size=input(a,MAX);
	show(a,size);
	average(a,size);
	
	return 0;
}

int input(int a[],int b){
	cout<<"enter up to 10 golf grades:\n";
	int i=0;
	/* 
	for(i=0;i<MAX;i++){
		cout<<"grade #"<<i+1<<": "<<endl;
		int temp;
		cin>>temp;
		if(!cin){
			cin.clear();
			while(cin.get()!='\n')
			continue;
			cout<<"bad input;input process terminated.\n";
			break;
		}
		else if(temp<0)
		break;
		a[i]=temp;
	}
	*/ 
	
	cout<<"grade #1£º "<<endl;
	while(i<MAX&&cin>>a[i]){
		if(++i<MAX)
		cout<<"grade #"<<i+1<<": "<<endl;
	} 
	return i;
}

void show(int a[],int b){
	cout<<"grades: ";
	for(int i=0;i<b;i++)
	cout<<a[i]<<" ";
	cout<<endl;
}

void average(int a[],int b){
	double sum=0;
	for(int i=0;i<b;i++)
	sum+=a[i];
	cout<<"average grade is: "<<sum/b<<endl;
}
