#include <iostream>
#include "11-7com.h"
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	complex a(3.0,4.0);
	complex c;
	cout<<"Enter a complex number (q to quit):\n";
	while(cin>>c)
	{
		cout<<"c is "<<c<<'\n';
		cout<<"complex conjugate is "<<-c<<'\n';
		cout<<"a is "<<a<<'\n';
		cout<<"a + c is "<<a+c<<'\n';
		cout<<"a - c is "<<a-c<<'\n';
		cout<<"a * c is "<<a*c<<'\n';
		cout<<"2 * c is "<<2*c<<'\n';
		cout<<"Enter a complex number (q to quit) :\n";
	}
	cout << "Done!\n";
	
	return 0;
}
