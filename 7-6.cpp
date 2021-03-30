#include <iostream>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
int Fill_array(double a[],int n);
void Show_array(const double a[],int n);
void Reverse_array(double a[],int n);

int main(int argc, char** argv) {
	cout<<"enter the number of numbers entered: ";
	int n;
	cin>>n;
	double a[n];
	int m=Fill_array(a,n);
	Show_array(a,m);
	Reverse_array(a,m);
	Show_array(a,m);
	
	
	return 0;
}

int Fill_array(double a[],int n){
	cout<<"enter a double number(up to )"<<n<<" numbers: ";
	int i=0;
	while(i<n&&cin>>a[i]){
		if(++i<n)
		cout<<"enter next double number: ";
	}
	return i;
}

void Show_array(const double a[],int n){
	for(int i=0;i<n;i++)
	cout<<a[i]<<endl;
} 

void Reverse_array(double a[],int n){
	for(int i=1;i<n/2;i++){
		double temp;
		temp=a[i];
		a[i]=a[n-1-i];
		a[n-1-i]=temp;
	}
}
