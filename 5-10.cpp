#include <iostream>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	cout<<"Enter number of rows:";
	int row;
	cin>>row;
	for(int i=1;i<=row;i++)
	{
		for(int j=1;j<=row-i;j++)
		cout<<".";
		for(int k=1;k<=i;k++)
		cout<<"*";
		cout<<endl;
	 } 
	return 0;
}
