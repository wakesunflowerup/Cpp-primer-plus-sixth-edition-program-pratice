#include <iostream>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
double transave(double a,double b);
int main(int argc, char** argv) {
	int a,b;
	cout<<"enter two numbers(once enter 0,end):"<<endl;
	while(cin>>a>>b){
		if(a==0||b==0){
			cout<<"u entered 0,program terminated\n";
			break;
		}
		else 
		cout<<transave(a,b)<<endl;
		
	}
	return 0;
}

double transave(double a,double b){
	double ave;
	ave=2.0*a*b/(a+b);
	return ave;
}
