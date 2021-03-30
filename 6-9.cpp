#include <iostream>
#include <cstdlib>
#include <fstream>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

struct dona{
	char name[15];
	int money; 
};

int main(int argc, char** argv) {
	ifstream info;
	info.open("6_5.txt");
	if(!info.is_open()){
		cout<<"cant open the file\n";
		cout<<"program terminating\n";
		exit(EXIT_FAILURE);
	}
	else
	cout<<"file is opened.\n";
	int n;
	info>>n;
	info.get();
	dona* nm=new dona [n];
	for(int i=0;i<n;i++){
	info.getline(nm[i].name,15);
	info>>nm[i].money;
	info.get();	
	}
	info.close();
	int count1=0;
	int count2=0;
	cout<<"grand patrons:"<<endl;
	for(int i=0;i<n;i++){
		if(nm[i].money>10000){
		count1++;
		cout<<nm[i].name<<endl;
		cout<<nm[i].money<<endl;
		}
	}
	if(count1==0)
	cout<<"none"<<endl;
	cout<<"patrons:"<<endl;
	for(int i=0;i<n;i++){
		if(nm[i].money<10000){
		count2++;
		cout<<nm[i].name<<endl;
		cout<<nm[i].money<<endl;
		}
	}
	if(count2==0)
	cout<<"none"<<endl;
	delete [] nm;
	return 0;
}
