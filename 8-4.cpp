#include <iostream>
#include <cstring>
using namespace std;

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
struct stringy{
	char * str;
	int ct;
};

void set(stringy & a,const char * b);
void show(const stringy & a,int n=1);
void show(const char * a,int n=1);


int main(int argc, char** argv) {
	stringy beany;
	char testing[]="reality isn`t what it used to be.";
	
	set(beany,testing);
	show(beany);
	show(beany,2);
	testing[0]='D';
	testing[1]='u';
	show(testing);
	show(testing,3);
	show("done!");
	
	return 0;
}

void set(stringy & a,const char * b){
	a.ct=strlen(b);
	a.str=new char;
	strcpy(a.str,b);
}
void show(const stringy & a,int n){
	if(n<=0)
		return;
	else{
		for(int i=0;i<n;i++){
			cout<<a.str<<endl;
			cout<<a.ct<<endl;
		}
	}
}
void show(const char * a,int n){
	if(n<=0)
		return;
	else{
		for(int i=0;i<n;i++){
			cout<<a<<endl;
		}
	}
}
