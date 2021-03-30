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
	
//没有动态分配内存去专门写什么赋值运算符，复制构造函数，析构函数 干什么?

//定义为虚函数可以让指向派生类的基类指针和引用在调用虚函数方法时，可以根据
//实际指向的派生类内的虚函数方法，否则只能调用基类方法 

//这样派生类的派生类如果是多重继承，那么其只会含有一份基类数据，不会是多份 
//同时可以尽量避免 赋值和调用方法的二义性 
 
//有从两个基类继承的数据部分，还有从虚基类继承的数据部分，只是没有新的 

//可以搞更多，但是由于可以隐式向上转换，所有的派生类都可以使用虚基类的友元
//不过是按照虚基类定义的方法来运行的 

//what r u fuvking say? 不可以搞虚基类的实例对象，会报错的亲。 
	return 0;
}
