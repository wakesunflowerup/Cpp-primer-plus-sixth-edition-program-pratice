#include <iostream>
#include <vector>
#include <list>
#include <cstdlib>
#include <ctime>
#include <algorithm>

using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

// list.sort()��ʱ�临�Ӷ�Ϊ N*logN

//���Ƶ�ʱ��������Ϊ���� 

//����Ϊʲô ����ĸ��������Ƶ�ʱ�� ���� Խ��Խ����  ���帴�� ���� ���� ��ʱ��֮���أ� 

//		10*N*log10*N  =  10N * (1+logN)  =  10N+10N*logN 
//		/
//		N*logN  =  10/logN +10 			Խ����������Խ��������10 
//		100000   ��   1000000	12��
//		1000000  ��  10000000	11.67�� 
//		�м���� �ڴ��д ���ĵ�ʱ��϶� 
//		���ƣ����򣬸���ʱ���ȷ��һ�� 
 
const int MAX[3]={100000,1000000,10000000};

int main(int argc, char** argv) {
	
	srand(time(0));
	
	double t_vi_sort,t_li_sort,t_li_to_vi,t_vi_to_li,t_sum;
	
	for(int j=0;j<3;j++)
	{
		vector<int> vi0(MAX[j]);
		vector<int> vi(MAX[j]);
		list<int> li(MAX[j]);
	 	
		for(int i=0;i<MAX[j];i++)
	 		vi0[i]=rand();
	 	
	//copy vector to list
		clock_t start=clock();
		copy(vi0.begin(),vi0.end(),li.begin());//û�� list �� insert ����
		clock_t end=clock();
		t_vi_to_li=(double)(end-start)/CLOCKS_PER_SEC; 
	
	
	//copy list to vector
		start=clock();
		copy(li.begin(),li.end(),vi.begin());
		end=clock();
		t_li_to_vi=(double)(end-start)/CLOCKS_PER_SEC; 
		
	 	
	 	start=clock();// sort vector
	 	sort(vi.begin(),vi.end());
	 	end=clock();
	 	t_vi_sort=(double)(end-start)/CLOCKS_PER_SEC;
	 	
	 	start=clock();//sort list
	 	li.sort();
	 	end=clock();
	 	t_li_sort=(double)(end-start)/CLOCKS_PER_SEC;
	
	// /*copy*/,  copy,sort,copy
	 	copy(vi0.begin(),vi0.end(),li.begin());
		start=clock();
		copy(li.begin(),li.end(),vi.begin());
		sort(vi.begin(),vi.end());
		copy(vi.begin(),vi.end(),li.begin());
		end=clock(); 
	 	t_sum=double(end-start)/CLOCKS_PER_SEC;
	 	
	 	cout<<"\n�����СΪ "<<MAX[j]<<"�������: "; 
	 	cout<<"\n��vector���Ƶ�list��ʱ��: "<<t_vi_to_li;
	 	cout<<"\n��list���Ƶ�vector��ʱ��: "<<t_li_to_vi;
	 	cout<<"\n��vector�����ʱ��: "<<t_vi_sort;
	 	cout<<"\n��list�����ʱ��: "<<t_li_sort;
	 	cout<<"\n����--����--���� ��ʱ��: "<<t_sum<<endl; 
	}
 	
 	cout<<"bye.\n";
	return 0;
}
