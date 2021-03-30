#include <iostream>
#include <cctype>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	cout<<"please enter income,under 0 or non-number to end:";
	double ic,tax;
	while(cin>>ic){
		if(ic<0)
		break;
		if(ic<5001)
		tax=0;
		else if(ic<15001)
		tax=(ic-5000)*0.10;
		else if(ic<35001)
		tax=(ic-15000)*0.15+10000*0.10;
		else
		tax=(ic-35000)*0.20+20000*0.15+10000*0.10;
		cout<<tax<<endl;
		cout<<"please enter income,under 0 or non-number to end:";
	}
	cout<<"bye!"<<endl;
	return 0;
}
