#include <iostream>
using namespace std;

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

double add(double a,double b);
double unadd(double a,double b);
double mult(double a,double b);
double calc(double a,double b,double (*pf)(double a,double b));


int main(int argc, char** argv) {
	double (* pf[3])(double a,double b)={add,unadd,mult};
	char * name[3]={"add: ","unadd: ","mult: "};
	double x,y;
	cout<<"enter 2 numbers: ";
	while(cin>>x>>y){
		for(int i=0;i<3;i++){
			cout<<name[i]<<calc(x,y,pf[i])<<endl;
		}
		cout<<"enter 2 numbers: ";
	}
	return 0;
}
double add(double a,double b){
	return a+b;
}
double unadd(double a,double b){
	return a-b;
}
double mult(double a,double b){
	return a*b;
}
double calc(double a,double b,double (*pf)(double a,double b)){
	return (*pf)(a,b); 
}
