#include <iostream>
#include <algorithm>
#include <string> 
#include <set>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
//�����зϰ�

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

template<typename T>// sort �� unique 
int reduce(T ar[],int n)
{
	sort(&ar[0],&ar[n]);
	T * end=unique(&ar[0],&ar[n]);
	return end-ar;
}

template<typename T>//set 
int reduces(T ar[],int n)
{
	set<T> temp(&ar[0],&ar[10]);//��ν���캯���� 
//	set<T> temp;
//	for(int i=0;i<n;i++)	//����գ����� 
//		temp.insert(&ar[0],&ar[n]);
	return temp.size();
}

//int reduce(long ar[],int n)//�Լ�ʵ�ֵ������ȥ�� 
//{
//	for(int i=0;i<n-1;i++)//ð��������Ҫ�Ƚ� n-1 �֣�ÿһ�ֽ�������������ð�ݵ�����
//	{
//		for(int j=0;j<n-i-1;j++)//ÿ�ֱȽ� n-1-i ����
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
//	int m=1;//���ظ���Ԫ�ظ���,�ض���һ�� 
//	tmp[0]=ar[0];//�Ȱѵ�һ�������� 
//	for(int i=1;i<n;i++)
//	{ 
//		if(ar[i]!=ar[i-1])
//			tmp[m++]=ar[i];//��һ��֮�� m ��ΪĿǰ���ظ����ֵ���Ŀ 
//	}
//	
//	for(int i=0;i<m;i++)
//		cout<<tmp[i]<<" ";
//	cout<<endl; 
//	return m;
//}

//*****************************************************************************

//int reduce(long ar[],int n)//�Լ�ʵ�ֵ�ȥ�غ����� 
//{
//	long tmp[n];
//	int m=0;//���ظ���Ԫ�ظ��� 
//	for(int i=0;i<n;i++)//������ʼ����ȫ��Ԫ�� 
//	{
//		int j=0;
//		for(;j<m;j++)//����ȥ������Ŀǰ��ȫ��Ԫ�� 
//		{
//			if(ar[i]==tmp[j])
//				break;//��������ظ�������ʹ�������if�жϲ����� 
//		}
//		if(j==m)//���ظ�����ֵ 
//			tmp[m++]=ar[i];
//	}
//	
//	long sortar[m];
//	for(int i=0;i<m;i++)
//		sortar[i]=tmp[i];//tmp�󼸸�Ԫ�ؿ���Ϊ0��ȥ�������0ֵ 
//	
//	for(int i=0;i<m-1;i++)//ð��������Ҫ�Ƚ� m-1 �֣�ÿһ�ֽ�������������ð�ݵ�����
//	{
//		for(int j=0;j<m-i-1;j++)//ÿ�ֱȽ� m-1-i ����
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

