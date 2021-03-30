#include "11-4mytime.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	Time aida(3,35);
	Time tosca(2,48);
	Time temp;
	
	cout<<"Aida and Tosca:\n";
	cout<<aida<<"; "<<tosca<<endl;
	temp=aida+tosca;
	cout<<"Aida + Tosca: "<<temp<<endl;
	temp=aida*1.17;
	cout<<"Aida * 1.17: "<<temp<<endl;
	cout<<"10.0 * Tosca: "<<10.0*tosca<<endl;
	return 0;
}
