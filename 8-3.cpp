#include <iostream>
#include <string>
#include <cctype>
using namespace std;

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
string & trans(string & s);


int main(int argc, char** argv) {
	cout<<"enter a string(q to quit):";
	string str;
	while(getline(cin,str)){
//	string a=trans(str);
//	cout<<a<<endl;
		if(!(str=="q"||str=="Q")){
			string a=trans(str);
			cout<<a<<endl;
			cout<<"next string(q to quit):";
		}
		else{
			cout<<"bye.\n";
			break;
		}
	}
	return 0;
}

string & trans(string &s){
	int i; 
	for(i=0;s[i];i++){
		s[i]=toupper(s[i]);
	}
	s[i]='\0';
	return s;
}
