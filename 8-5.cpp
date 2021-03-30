#include <iostream>
using namespace std;

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
template<typename T>
T max5(T * a);

int main(int argc, char** argv) {
	int a[5]={1,6,2,7,4};
	double b[5]={2.4,526.1,24.5,523.2,5.1};
	cout<<max5(a)<<endl;
	cout<<max5(b)<<endl; 
	
	return 0;
}

template<typename T>
T max5(T a[]){
	T max=a[0];
	for(int i=1;i<5;i++){
		if(max<a[i])
			max=a[i];
	}
	return max;
}
