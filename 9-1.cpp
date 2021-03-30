#include <iostream>
#include <cstring>
#include "golf.h"
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	golf gog[5];
	golf g;
	int i=0;
	while(setgolf(g)){
		setgolf(gog[i],g.fullname,g.handicap);
		showgolf(gog[i]);
		cout<<"do you want to change handicap of golf?\n"
				"1.yes"		"2.no\n";
		int cho;
		cin>>cho;
		cin.get();
		if(cho==1){
			cout<<"enter the handicap: ";
			int hc;
			cin>>hc;
			cin.get();
			handicap(gog[i],hc);
			showgolf(gog[i]);
		}
		if(i<4)
			i++;
		else{
			cout<<"you have entered enough information of golf,program terminated.\n";
			break;
		}
		
	}
	
	return 0;
}


