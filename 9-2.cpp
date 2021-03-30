#include <iostream>
#include <string>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
using namespace std;

void strcount(const string str);

int main(int argc, char** argv) {
	string input;
	cout<<"Enter a line(empty line to quit):\n";
	
	while(getline(cin,input)){
		if(input=="")
			break;
		strcount(input);
		cout<<"enter next line (empty line to quit):\n";
		
	} 
	cout<<"bye\n";
	return 0;
}

void strcount(const string str){
	static int total=0;
	int count =0;
	cout<<"\""<<str<<"\" contains ";
	while(str[count]!='\0')
		count++;
	total+=count;
	cout<<count<<" characters\n";
	cout<<total<<" characters total\n";
}
