#include <iostream>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	char* year[3]={"first","second","third"};
	char* month[12]={"yi","er","san","si","wu","liu","qi","ba","jiu","shi","shiyi","shier"};
	int sale[3][12];
	int sumall=0;
	for(int i=0;i<3;i++)
	{
		int sum=0;
		for(int j=0;j<12;j++)
		{
			cout<<"input "<<year[i]<<" year "<<month[j]<<" yue sales volume:"<<endl;
			cin>>sale[i][j];
			sum=sum+sale[i][j];
		}
		cout<<year[i]<<" year`s sales volume is"<<sum<<endl;
		sumall=sumall+sum;
	}
	cout<<"sales volume is all "<<sumall<<endl;
	return 0;
}
