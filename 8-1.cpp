#include <iostream>
#include <string>
using namespace std;

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
//void out(char * arr);
void out(char * arr,int n=0);

int main(int argc, char** argv) {
	char * a="yasen best";
	char * b="liu";
	out(a);
	out(b,1);
	out(a,0); 
	return 0;
}


void out(char * arr,int n){
	if(n==0)
		return;
	else
	cout<<arr<<endl; 
}
