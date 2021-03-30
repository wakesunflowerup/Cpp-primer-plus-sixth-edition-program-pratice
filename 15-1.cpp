#include <iostream>
#include "15-1tv.h"
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	Tv sun;
	cout<<"TV default setting: \n";
	sun.onoff();
	sun.settings();
	
	Remote flo;
	cout<<"Remote default state: \n";
	flo.showstate();
	
	flo.re_commu();//遥控器自带互动 
	sun.buzz(flo);//电视让遥控器互动 
	
	flo.set_state();//设置遥控器不互动
	flo.showstate();
	sun.buzz(flo);
	
	sun.set_state(flo);//又互动了 
	flo.showstate();
	sun.buzz(flo);
	
	return 0;
}
