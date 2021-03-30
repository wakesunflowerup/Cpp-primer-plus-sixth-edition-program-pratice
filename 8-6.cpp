#include <iostream>
#include <cstring>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
template<typename T>
T maxn(T * a,int n);

template<>char * maxn<char *>(char * a[],int n);

int main(int argc, char** argv) {
	int a[6]={1,5,73,3,8,13};
	double b[4]={24.5,62.1,125.3,5.1};
	char * c[5]={"ya sen","li u","l ove","pr ogram","pra gram"};
	cout<<maxn(a,6)<<endl;
	cout<<maxn(b,4)<<endl;
	cout<<maxn(c,5)<<endl;
	return 0;
}

template<typename T>
T maxn(T * a,int n){
	T max=a[0];
	for(int i=1;i<n;i++){
		if(max<a[i])
			max=a[i]; 
	}
	return max;
}
template<>char * maxn(char * a[],int n){
	int max=strlen(a[0]);
	char * maxch=a[0];
	for(int i=1;i<n;i++){
		if(max<strlen(a[i])){
			max=strlen(a[i]);
			maxch=a[i];
		}
	}
	return maxch;
}
