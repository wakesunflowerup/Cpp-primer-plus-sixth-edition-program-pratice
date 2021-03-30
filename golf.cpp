#include <iostream>
#include <cstring>
#include "golf.h"
using namespace std;
void setgolf(golf & g,const char * name,int hc){
	strcpy(g.fullname,name);
	g.handicap=hc;
}

int setgolf(golf & g){
	
	cout<<"please enter the fullname of golf(if u enter nothing,program will be terminated.): ";
	cin.getline(g.fullname,Len);
	if(!strcmp(g.fullname,"")){
		cout<<"u enter nothing,program terminated." ;
		return 0;
	}
		
	cout<<"please enter the handicap of golf: ";
	cin>>g.handicap;

	
		return 1;
	
}

void handicap(golf & g,int hc){
	g.handicap=hc;
}

void showgolf(const golf & g){
	cout<<"golf`s fullname: "<<g.fullname<<endl;
	cout<<"golf`s handicap: "<<g.handicap<<endl; 
}
