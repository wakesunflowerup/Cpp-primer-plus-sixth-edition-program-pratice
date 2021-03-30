#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>
#include <cstdlib>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

vector<int> Lotto(int n,int m);

int main(int argc, char** argv) {
	srand(time(0));//��������ÿ�ν����һ���������о�����STLҲ����д�� 
	vector<int> winners;
	winners=Lotto(51,6);
	for(int x:winners)
		cout<<x<<endl;

	

	return 0;
}


//vector<int> Lotto(int n,int m) //���� vector���� insert  
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
//		range.erase(range.begin()); //����˵����͸��Ӧ�����ظ����� 
//	}
//	sort(result.begin(),result.end());
//	return result;
//}


vector<int> Lotto(int n,int m) //vector �������÷� 
{
	vector<int> range(n);//ע������������ 
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
