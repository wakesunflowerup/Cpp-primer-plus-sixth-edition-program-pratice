#include <iostream>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
long double pro(unsigned field,unsigned choices);

int main(int argc, char** argv) {
	double field1,field2,choices1,choices2;
	cout<<"enter the total number of choices in the field numbers and\n"
			"the total number of choices in the special numbers and\n"
			"the number of picks allowed in the field numbers and\n"
			"the number of picks allowed in the special numbers.\n";
			
			while(cin>>field1>>field2>>choices1>>choices2&&choices1<field1&&choices2<field2){
				cout<<"you have one chance in ";
				cout<<pro(field1,choices1)*pro(field2,choices2);
				cout<<" of winning.\n";
				cout<<"next four numbers (q to quit):";
			}
			cout<<"bye\n";
	return 0;
}

long double pro(unsigned field,unsigned choices){
	long double prob=1.0;
	unsigned n, m;
	for(n=field,m=choices;m>0;n--,m--){
		prob=prob*n/m;
	}
	return prob;
}
