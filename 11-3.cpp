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
		 
	cout<<"��������루����q�˳���: ";
	while(cin>>target)
	{
		cout<<"���벽��: ";
		if(!(cin>>dstep))
			break;
		cout<<"��������Դ���: ";
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
		cout<<"\n��߲���: "<<max<<"\n��Ͳ���: "<<min<<"\nƽ������: "<<1.0*sum/n<<endl; 
		cout<<"\n��������루����q�˳���: ";
	}
	cout<<"bye!\n";
	cin.clear();
	while(cin.get()!='\n')
		continue;
	return 0;
}
