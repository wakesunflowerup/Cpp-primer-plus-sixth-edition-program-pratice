#include <iostream>
#include "14-5abstr.h"
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	
	employee em("Trip", "Harris", "Thumper");
	cout << em << endl;
	em.ShowAll();
	cout<<endl;
	manager ma("Amorphia", "Spindragon", "Nuancer", 5);
	cout << ma << endl;
	ma.ShowAll();
	cout<<endl;
	fink fi("Matt", "Oggs", "Oiler", "Juno Barr");
	cout << fi << endl;
	fi.ShowAll();
	cout<<endl;
	highfink hf(ma, "Curly Kew");     // recruitment?
	hf.ShowAll();
	cout<<endl;
	cout << "Press a key for next phase:\n";
	cin.get();

	highfink hf2;
	hf2.SetAll();
	
	cout << "Using an abstr_emp * pointer:\n";
	abstr_emp * tri[4] = {&em, &fi, &hf, &hf2};
	for(int i = 0; i < 4; i++)
		tri[i] ->ShowAll();
	
//û�ж�̬�����ڴ�ȥר��дʲô��ֵ����������ƹ��캯������������ ��ʲô?

//����Ϊ�麯��������ָ��������Ļ���ָ��������ڵ����麯������ʱ�����Ը���
//ʵ��ָ����������ڵ��麯������������ֻ�ܵ��û��෽�� 

//���������������������Ƕ��ؼ̳У���ô��ֻ�Ậ��һ�ݻ������ݣ������Ƕ�� 
//ͬʱ���Ծ������� ��ֵ�͵��÷����Ķ����� 
 
//�д���������̳е����ݲ��֣����д������̳е����ݲ��֣�ֻ��û���µ� 

//���Ը���࣬�������ڿ�����ʽ����ת�������е������඼����ʹ����������Ԫ
//�����ǰ�������ඨ��ķ��������е� 

//what r u fuvking say? �����Ը�������ʵ�����󣬻ᱨ����ס� 
	return 0;
}
