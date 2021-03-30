#include <iostream>
#include <fstream>
#include <cstdlib>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	ifstream file;
	file.open("text.txt");
	if(!file.is_open()){
		cout<<"cant open the file text.txt"<<endl;
		exit(EXIT_FAILURE);
	}
	char ch;
	int count=0;
	file.get(ch);
	while(file.good()){
		++count;
		file.get(ch);
	}
	if(file.eof())
	cout<<"end of file reached.\n";
	else if(file.fail())
	cout<<"input terminated by data mismatch.\n";
	else 
	cout<<"input terminated by unknown reason.\n";
	if(count==0)
	cout<<"no data processed.\n";
	else{
		cout<<count<<" characters read.\n";
	}
	file.close();
	return 0;
}
