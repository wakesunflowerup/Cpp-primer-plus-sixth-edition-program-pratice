#include <iostream>
#include <cctype>
#include <cstring>
using namespace std;
const int strsize=15;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	cout<<"enter words £¨q to quit): "<<endl;
	char a[strsize];
	int count=0;//all
	int count1=0;//shuzi=others
	int count2=0;//aeiou=vowels
	int count3=0;//consonants
	cin>>a;
	while(strcmp(a,"q")){
		count++; 
		if(!isalpha(a[0]))
		count1++;
		else 
		switch(a[0]){
			case 'a':
			case 'e':
			case 'i':
			case 'o':
			case 'u':count2++;
			break;
			default :count3++; 
		}
		cin>>a;
	}	
	cout<<count2<<" words beginning with vowels"<<endl;
	cout<<count3<<" words beginning with consonants"<<endl;
	cout<<count1<<" others"<<endl;
	return 0;
}
