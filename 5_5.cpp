#include <iostream>
//#include <string>
using namespace std;
int main(int argc, char** argv) {
	char* month[12]={"january","february","march","april","may","june","july","august","september","october","november","december"};
	int numbers[12];
	int sum=0;
	for(int i=0;i<12;++i)
	{
		cout<<"input "<<month[i]<<" sell numbers"<<endl;
		 cin>>numbers[i];
		 sum=sum+numbers[i];
	}
	cout<<"sell all "<<sum<<endl;
	std::cout << "Hello world!\n";
}
