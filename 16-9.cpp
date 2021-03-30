#include <iostream>
#include <vector>
#include <list>
#include <cstdlib>
#include <ctime>
#include <algorithm>

using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

// list.sort()的时间复杂度为 N*logN

//复制的时间增长均为线性 

//不过为什么 总体的复制排序复制的时间 总是 越来越大于  单体复制 排序 复制 的时间之和呢？ 

//		10*N*log10*N  =  10N * (1+logN)  =  10N+10N*logN 
//		/
//		N*logN  =  10/logN +10 			越大增长倍率越慢，趋近10 
//		100000   到   1000000	12倍
//		1000000  到  10000000	11.67倍 
//		中间可能 内存读写 消耗的时间较多 
//		复制，排序，复制时间的确短一点 
 
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
		copy(vi0.begin(),vi0.end(),li.begin());//没用 list 的 insert 方法
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
	 	
	 	cout<<"\n数组大小为 "<<MAX[j]<<"的情况下: "; 
	 	cout<<"\n从vector复制到list的时间: "<<t_vi_to_li;
	 	cout<<"\n从list复制到vector的时间: "<<t_li_to_vi;
	 	cout<<"\n对vector排序的时间: "<<t_vi_sort;
	 	cout<<"\n对list排序的时间: "<<t_li_sort;
	 	cout<<"\n复制--排序--复制 的时间: "<<t_sum<<endl; 
	}
 	
 	cout<<"bye.\n";
	return 0;
}
