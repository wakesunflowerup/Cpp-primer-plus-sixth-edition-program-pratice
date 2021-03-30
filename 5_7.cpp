#include <iostream>
#include <string>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

struct car{
	string make;
	int year;
};
int main(int argc, char** argv) {
	cout<<"how many cars do you wish to catalog? ";
	int num;
	cin>>num;
	cin.get();
	car * user=new car [num];
	for(int i=1;i<=num;i++)
	{
		cout<<"Car #"<<i<<":"<<endl;
		cout<<"Please enter the make: ";
		getline(cin,user[i-1].make);
		cout<<"please enter the year made: ";
		cin>>user[i-1].year;
		cin.get();
	}
	cout<<"Here is your collection:"<<endl;
	for(int i=0;i<num;i++)
	{
		cout<<user[i].year<<" "<<user[i].make<<endl;
	}
	delete [] user;
	return 0;
}
