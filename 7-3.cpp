#include <iostream>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
struct box{
	char maker[40];
	float height;
	float width;
	float length;
	float volume;
};

void show(box a);
void cal(box *a);

int main(int argc, char** argv) {
	box a={ "yasen",2.5,1.5,3.5,5.0};
	show(a);
	cal(&a);
	cout<<"volume is "<<a.volume<<endl; 
	
	return 0;
}

void show(box a){
	cout<<"maker: "<<a.maker<<endl;
	cout<<"height: "<<a.height<<endl;
	cout<<"width: "<<a.width<<endl;
	cout<<"length: "<<a.length<<endl;
	cout<<"volume: "<<a.volume<<endl;
}
void cal(box *a){
	a->volume=a->length*a->width*a->height; 
}
