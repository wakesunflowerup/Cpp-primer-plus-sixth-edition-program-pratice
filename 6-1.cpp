#include <iostream>
#include <cctype> 
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	cout<<"enter text for analysis, and type @ to terminate input.\n";
	char ch;
	cin.get(ch);
	while(ch!='@')
	{
		if(islower(ch))
		cout<<(char)toupper(ch);
		else if(isupper(ch))
		cout<<(char)tolower(ch);
		else if(!isdigit(ch))
		cout<<ch;
		
		cin.get(ch);
	}
	
	return 0;
}
