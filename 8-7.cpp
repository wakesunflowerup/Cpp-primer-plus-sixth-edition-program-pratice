#include <iostream>
using namespace std;
 
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
template<typename T>
void sumarray(T arr[],int n);

template<typename T>
void sumarray(T * arr[],int n);

struct debts{
	char name[50];
	double amount;
};

int main(int argc, char** argv) {
	int things[6]={13,31,103,301,310,130};
	struct debts mr_E[3]={{"ima wolfe",2400.0},{"ura fpxe",1300.0},{"iby stout",1800.0}};
	double * pd[3];
	for(int i=0;i<3;i++)
		pd[i]=&mr_E[i].amount;
	cout<<"listing mr.E`s counts of things:\n";
	
	sumarray(things,6);
	cout<<"listing mr_E`s debts:\n";
	sumarray(pd,3);
	
	return 0;
}

template<typename T>
void  sumarray(T arr[],int n){
	cout<<"template a\n";
	int sum=0;
	for(int i=0;i<n;i++)
		sum+=arr[i];
	cout<<sum<<endl;
}

template<typename T>
void sumarray(T * arr[],int n){
	cout<<"template b\n";
	int sum=0;
	for(int i=0;i<n;i++)
		sum+=*arr[i];
	cout<<sum<<endl;
}
