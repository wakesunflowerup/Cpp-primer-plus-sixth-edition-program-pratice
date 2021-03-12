#include <iostream>
#include <string>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	cout<<"Enter words(to stop, type the word done):"<<endl;
	string word;
	cin>>word;
	int i=0;
	while(word!="done")
	{
		i++;
		cin>>word;
	}
	cout<<"You entered a total of "<<i<<" words."<<endl;
	return 0;
}
