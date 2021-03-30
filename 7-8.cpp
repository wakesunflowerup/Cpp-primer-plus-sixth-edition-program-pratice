#include <iostream>

using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
const int seasons=4;
struct season{
	double expense[seasons];
};

const char * snames[seasons]={"spring","summer","fall","winter"};

void fill(double * arr,int n);
void show(const double * arr,int n);
void fills(season * st);
void shows(const season *st);


int main(int argc, char** argv) {
	double expenses[seasons];
	season st;
	fill(expenses,seasons);
	show(expenses,seasons);
	fills(&st);
	shows(&st);
	return 0;
}

void fill(double * arr,int n){
	for(int i=0;i<n;i++){
		cout<<"enter "<<snames[i]<<" expenses: ";
		cin>>arr[i];
	}
}

void show(const double * arr,int n){
	double total =0.0;
	cout<<"\nEXPENSES\n";
	for(int i=0;i<n;i++){
		cout<<snames[i]<<":$"<<arr[i]<<endl;
		total+=arr[i];
	}
	cout<<"total expenses:$"<<total<<endl;
}

void fills(season * st){
	for(int i=0;i<seasons;i++){
		cout<<"enter "<<snames[i]<<" expenses: ";
		cin>>st->expense[i];
	}
} 

void shows(const season * st){
	double total=0.0;
	cout<<"\nEXPENSES\n";
	for(int i=0;i<seasons;i++){
		cout<<snames[i]<<":$"<<st->expense[i]<<endl;
		total+=st->expense[i];
		
	}
	cout<<"total expenses:$"<<total<<endl;
}
