#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>
#include <cstdlib>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

vector<int> Lotto(int n,int m);

int main(int argc, char** argv) {
	srand(time(0));//这玩意让每次结果不一样，不过感觉不用STL也可以写啊 
	vector<int> winners;
	winners=Lotto(51,6);
	for(int x:winners)
		cout<<x<<endl;

	

	return 0;
}


//vector<int> Lotto(int n,int m) //利用 vector方法 insert  
//{
//	vector<int> range;
//	vector<int> result;
//	for(int i=0;i<n;i++)
//		range.insert(range.end(),i);
//	
//	for(int i=0;i<6;i++)
//	{
//		random_shuffle(range.begin(),range.end());
//		result.insert(result.end(),*range.begin());
//		range.erase(range.begin()); //按理说大乐透不应该有重复数字 
//	}
//	sort(result.begin(),result.end());
//	return result;
//}


vector<int> Lotto(int n,int m) //vector 的数组用法 
{
	vector<int> range(n);//注意和上面的区别 
	vector<int> result(m);
	for(int i=0;i<n;i++)
		range[i]=i+1;
	
	for(int i=0;i<6;i++)
	{
		random_shuffle(range.begin(),range.end());
		result[i]=range[0];
		range.erase(range.begin()); 
	}
	sort(result.begin(),result.end());
	return result;
}
