#include <iostream>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
void showmenu();
void report();

int main(int argc, char** argv) {
	showmenu();
	char choice;
//	cin>>choice;
	while(cin>>choice)
	{
		switch(choice)
		{
			case 'c':
			case 'C':report();
			break;
			case 'p':
			case 'P':cout<<"he is a pianist.\n";
			break;
			case 't':
			case 'T':cout<<"A maple is a tree.\n";
			break;
			case 'g':
			case 'G':cout<<"Let`s play game.\n";
			break;
			default:cout<<"Please enter a c,p,t,or g:";
		}
	 } 
	
	return 0;
}

void showmenu()
{
	cout<<"please enter one of the following choices:\n"
		   "c) carnivore		p) pianist\n"
		   "t) tree			g) game\n";
}

void report()
{
	cout<<"a maple is a \n";
}
