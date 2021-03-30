#include <iostream>
#include <fstream>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
struct donate{
	char name[15];
	double money;
};
int main(int argc, char** argv) {
	cout<<"enter the numbers of patrons:";
	int n;
	int count1=0;
	int count2=0;
	cin>>n;
	cin.get();
	donate* a=new donate[n];
	ofstream outFile;
	outFile.open("6_5.txt");
	outFile<<n<<endl;
	for(int i=0;i<n;i++){
		cout<<"enter name and donation money of patrons #:"<<i+1<<endl;
		cin.getline(a[i].name,15);
		cin>>a[i].money;
		cin.get();
		outFile<<a[i].name<<endl;
		outFile<<a[i].money<<endl;
	}
	outFile.close();
	cout<<"Grand Patrons:"<<endl;
	for(int i=0;i<n;i++){
		if(a[i].money>10000) {
			count1++;
			cout<<a[i].name<<endl;
			cout<<a[i].money<<endl;
		}

	}
		if(count1==0)
		cout<<"none"<<endl;
	cout<<"Patrons:"<<endl;
	for(int i=0;i<n;i++){
		if(a[i].money<10000) {
			count2++;
			cout<<a[i].name<<endl;
			cout<<a[i].money<<endl;
		}
	}
		if(count2==0)
		cout<<"none"<<endl;
	delete [] a;
	return 0;
}
