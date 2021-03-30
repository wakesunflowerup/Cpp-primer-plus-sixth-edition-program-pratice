#include <iostream>
#include "9-4namespace.h"
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
using namespace std;
using namespace SALES;
int main(int argc, char** argv) {
	Sales s1,s2;
	double arr[4]={2.65,4.54,1.25,3.62};
	setSales(s1);
	
	setSales(s2,arr,4);

	showSales(s1);
	showSales(s2);
	
	return 0;
}
