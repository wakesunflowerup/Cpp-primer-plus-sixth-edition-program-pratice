#include <iostream>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
const int MAX=5;

double * fill(double * begin,double *end);
void show(const double * begin,const double * end);
void revalue(double r,double * begin,double * end);

int main(int argc, char** argv) {
	double properties[MAX];
	double * end=fill(properties,properties+5);
	show(properties,end);
	if(end!=properties){
		cout<<"enter revaluation factor: ";
		double factor;
		while(!(cin>>factor)){
			cin.clear();
			while(cin.get()!='\n')
			continue;
		cout<<"bad input;please enter a  number: "; 
		}
	revalue(factor,properties,end);
	show(properties,end);
	}
	cout<<"done\n";
	cin.get();
	cin.get();
	return 0;
}

double * fill(double * begin,double * end){
	double * temp;
	int i=1;
	for(temp=begin;temp!=end;temp++){
		cout<<"enter value #"<<i<<":";
		cin>>*temp;
		i++;
		if(!cin){
			cin.clear();
			while(cin.get()!='\n')
				continue;
			cout<<"bad input,terminated.\n"; 
			break;
		}
		else if(*temp<0)
			break;
		
	}
	return temp;
}

void show(const double * begin,const double * end){
	int i=1;
	for(const double * pt=begin;pt!=end;pt++){
		cout<<"property #"<<i<<":$";
		cout<<*pt<<endl;
		i++;
	}
}

void revalue(double r,double * begin,double * end){
	for(double * pt=begin;pt!=end;pt++)
		*pt *=r;
}
