#include <iostream>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
double jc(int n); 

int main(int argc, char** argv) {
	cout<<"enter a number: ";
	int n;
	while(cin>>n){
		double jiec; 
		jiec=jc(n);
		cout<<n<<" µÄ½×³ËÊÇ£º "<<jiec<<endl; 
		cout<<"enter next number£¨q to quit): ";
	}
	
	
	return 0;
}

double jc(int n){
	if(n==0)
	return 1;
	else
	return n*jc(n-1);
}
