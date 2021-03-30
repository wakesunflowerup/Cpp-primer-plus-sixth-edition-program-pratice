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
	int n;
		 
	cout<<"请输入距离（输入q退出）: ";
	while(cin>>target)
	{
		cout<<"输入步长: ";
		if(!(cin>>dstep))
			break;
		cout<<"请输入测试次数: ";
		if(!(cin>>n))
			break;
		int sum=0,max=0,min=(target/dstep)*(target/dstep);
		for(int i=0;i<n;i++)
		{
			while(result.magval()<target)
			{
				direction=rand()%360;
				step.reset(dstep,direction,Vector::POL);
				result=result+step;
				steps++;
			}
			sum+=steps;
			max=max>steps?max:steps;
			min=min<steps?min:steps;
			cout<<"\nAfter "<<steps<<" steps, the subject has the following location:\n";
			cout<<result<<endl;
			result.polar_mode();
			cout<<" or\n"<<result<<endl;
			cout<<"Average outward distance per step = "<<result.magval()/steps<<endl;
			steps=0;
			result.reset(0.0,0.0);
		}
		cout<<"\n最高步数: "<<max<<"\n最低步数: "<<min<<"\n平均步数: "<<1.0*sum/n<<endl; 
		cout<<"\n请输入距离（输入q退出）: ";
	}
	cout<<"bye!\n";
	cin.clear();
	while(cin.get()!='\n')
		continue;
	return 0;
}
