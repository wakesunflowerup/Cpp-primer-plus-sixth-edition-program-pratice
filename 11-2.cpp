#include "vect.h"
#include <cstdlib>
#include <ctime>
#include <fstream>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	srand(time(0));
	double direction;
	Vector step;
	Vector result(0.0,0.0);
	unsigned long steps=0;
	double target;
	double dstep;
	ofstream fout;
	fout.open("11-1_thewalk.txt");
	
	cout<<"请输入距离（输入q退出）: ";
	while(cin>>target)
	{
		cout<<"输入步长: ";
		if(!(cin>>dstep))
			break;
		fout<<"Target Distance: "<<target<<",Step Size: "<<dstep<<endl;
		while(result.magval()<target)
		{
			fout<<result<<endl;
			direction=rand()%360;
			step.reset(dstep,direction,Vector::POL);
			result=result+step;
			steps++;
		}
		fout<<steps<<": "<<result<<endl;
		cout<<"After "<<steps<<" steps, the subject has the following location:\n";
		fout<<"After "<<steps<<" steps, the subject has the following location:\n";
		cout<<result<<endl;
		fout<<result<<endl;
		result.polar_mode();
		cout<<" or\n"<<result<<endl;
		fout<<" or\n"<<result<<endl;
		cout<<"Average outward distance per step = "<<result.magval()/steps<<endl;
		fout<<"Average outward distance per step = "<<result.magval()/steps<<endl;
		steps=0;
		result.reset(0.0,0.0);
		cout<<"请输入距离（输入q退出）: ";
	}
	cout<<"bye!\n";
	cin.clear();
	while(cin.get()!='\n')
		continue;
	fout.close();
	return 0;
}
