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
	
	flo.re_commu();//ң�����Դ����� 
	sun.buzz(flo);//������ң�������� 
	
	flo.set_state();//����ң����������
	flo.showstate();
	sun.buzz(flo);
	
	sun.set_state(flo);//�ֻ����� 
	flo.showstate();
	sun.buzz(flo);
	
	return 0;
}
