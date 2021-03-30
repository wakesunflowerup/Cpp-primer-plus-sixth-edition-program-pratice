#include <iostream>
using namespace std;

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
class Move{
private:
	double x;
	double y;
public:
	Move(double a=0,double b=0);
	void showmove()const;
	Move add(const Move & m)const;
	void reset(double a=0,double b=0);
};
Move::Move(double a,double b)
{
	x=a;
	y=b;
}
void Move::showmove()const
{
	cout<<"x= "<<x<<"\ny= "<<y<<endl;
}
Move Move::add(const Move &m)const
{
	Move mr;
	mr.x=x+m.x;
	mr.y=y+m.y;
	return mr;
}
void Move::reset(double a,double b)
{
	x=0;
	y=0;
}
int main(int argc, char** argv) {
	Move m1=Move(5,5);
	m1.showmove();
	Move m2=m1.add(m1);
	m2.showmove();
	m2.reset();
	m2.showmove();
	
	return 0;
}
