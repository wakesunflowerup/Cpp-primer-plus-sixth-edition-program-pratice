#include <iostream>
#include <algorithm>
#include <string> 
#include <set>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
//下面有废案

template<typename T> // sort ,unique
int reduce(T ar[],int n);

template<typename T>//set 
int reduces(T ar[],int n);

int main(int argc, char** argv) {
	long ar[10]={6,4,3,5,2,1,7,4,2,9};
	string arr[10]={"apiary","beetle","ensign","cereal","danger","florid","ensign","florid","garage","beetle"};
	
	int m=reduce(ar,10);
	int mm=reduces(ar,10);
	int n=reduce(arr,10); 
	int nn=reduces(arr,10);
	
	cout<<m<<"\t"<<n<<endl;
	
	cout<<mm<<"\t"<<nn<<endl;
	return 0;
}

template<typename T>// sort 和 unique 
int reduce(T ar[],int n)
{
	sort(&ar[0],&ar[n]);
	T * end=unique(&ar[0],&ar[n]);
	return end-ar;
}

template<typename T>//set 
int reduces(T ar[],int n)
{
	set<T> temp(&ar[0],&ar[10]);//所谓构造函数？ 
//	set<T> temp;
//	for(int i=0;i<n;i++)	//构造空，插入 
//		temp.insert(&ar[0],&ar[n]);
	return temp.size();
}

//int reduce(long ar[],int n)//自己实现的排序后去重 
//{
//	for(int i=0;i<n-1;i++)//冒泡排序，需要比较 n-1 轮，每一轮将此轮中最大的数冒泡到后面
//	{
//		for(int j=0;j<n-i-1;j++)//每轮比较 n-1-i 个数
//		{
//			if(ar[j]>ar[j+1])
//			{
//				long temp=ar[j];
//				ar[j]=ar[j+1];
//				ar[j+1]=temp;
//			}
//		}
//	}
//	
//	long tmp[n];
//	int m=1;//不重复的元素个数,必定有一个 
//	tmp[0]=ar[0];//先把第一个存起来 
//	for(int i=1;i<n;i++)
//	{ 
//		if(ar[i]!=ar[i-1])
//			tmp[m++]=ar[i];//存一个之后 m 变为目前不重复数字的数目 
//	}
//	
//	for(int i=0;i<m;i++)
//		cout<<tmp[i]<<" ";
//	cout<<endl; 
//	return m;
//}

//*****************************************************************************

//int reduce(long ar[],int n)//自己实现的去重后排序 
//{
//	long tmp[n];
//	int m=0;//不重复的元素个数 
//	for(int i=0;i<n;i++)//遍历初始数组全部元素 
//	{
//		int j=0;
//		for(;j<m;j++)//遍历去重数组目前的全部元素 
//		{
//			if(ar[i]==tmp[j])
//				break;//如果发现重复跳出，使得下面的if判断不成立 
//		}
//		if(j==m)//无重复，赋值 
//			tmp[m++]=ar[i];
//	}
//	
//	long sortar[m];
//	for(int i=0;i<m;i++)
//		sortar[i]=tmp[i];//tmp后几个元素可能为0，去掉后面的0值 
//	
//	for(int i=0;i<m-1;i++)//冒泡排序，需要比较 m-1 轮，每一轮将此轮中最大的数冒泡到后面
//	{
//		for(int j=0;j<m-i-1;j++)//每轮比较 m-1-i 个数
//		{
//			if(sortar[j]>sortar[j+1])
//			{
//				long temp=sortar[j];
//				sortar[j]=sortar[j+1];
//				sortar[j+1]=temp;
//			}
//		}
//	}
//	for(int i=0;i<m;i++)
//		cout<<sortar[i]<<" ";
//	cout<<endl;
//	return m;
//}

