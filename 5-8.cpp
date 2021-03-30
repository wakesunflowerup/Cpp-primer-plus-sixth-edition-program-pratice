#include <iostream>
#include <cstring>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	cout<<"Enter words(to stop,type the word done):"<<endl;
	char word[20];
	cin>>word;
	int i=0;
	while(strcmp(word,"done"))
	{
		i++;
		cin>>word;
	 } 
	 cout<<"You entered atotal of "<<i<<" words."<<endl;
	return 0;
}
