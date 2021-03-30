#include <iostream>
//#include <string> 
#include "Account.h"
//using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	string name="sunflower";//dev c++的函数参数不能接受const char*到 string的转换，why？ 
	string account="sf123456";
	Account acc1=Account(); 
	Account acc2=Account(name,account,50000);
	acc1.show(); 
	acc2.show();
	acc1.in(50000);
	acc2.in(50000);
	acc1.show();
	acc2.show();
	acc1.out(10000);
	acc2.out(10000);
	acc1.show();
	acc2.show();
	return 0;
}



