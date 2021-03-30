#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <memory>

using namespace std; 
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
//  I like STL!!!
//	GOOD THOUGHT 


struct review{
	string title;
	int rating;
	int price;
};

bool operator<(const shared_ptr<review> & p1,const shared_ptr<review> & p2);
bool worseThan(const shared_ptr<review> & p1,const shared_ptr<review> & p2);
bool cheaperThan(const shared_ptr<review> & p1,const shared_ptr<review> & p2);
bool Fillreview(review & rr);
void Showreview(const shared_ptr<review> & pp);

int main(int argc, char** argv) {
	
	vector<review> books;
	review temp;
	
	while(Fillreview(temp))
		books.push_back(temp);
	int size=books.size();
	vector<shared_ptr<review>> pointers,letterp(size),r_by_lp(size),r_by_hp(size),p_by_lp(size),p_by_hp(size);//�������� 
	for(review re:books)
		pointers.push_back(shared_ptr<review>(new review(re)));
	
//������ĿҪ��Ļ�������� ����ָ�����鴴�� 2 ���ͺ��ˡ�һ�����ڴ洢ԭʼ���ݣ� һ����ԭʼ���ݸ��ƹ�ȥ��Ȼ������û�����ѡ������ʽ 
//	�������� �ռ� �� ʱ��		//���ŵ����ò��ߣ�sort�е������������Ŷ� ���������� ��ƫ�� 

	partial_sort_copy(pointers.begin(),pointers.end(),letterp.begin(),letterp.end());
	partial_sort_copy(pointers.begin(),pointers.end(),r_by_lp.begin(),r_by_lp.end(),worseThan);
	partial_sort_copy(pointers.begin(),pointers.end(),r_by_hp.rbegin(),r_by_hp.rend(),worseThan);
	partial_sort_copy(pointers.begin(),pointers.end(),p_by_lp.begin(),p_by_lp.end(),cheaperThan);
	partial_sort_copy(pointers.begin(),pointers.end(),p_by_hp.rbegin(),p_by_hp.rend(),cheaperThan);
	
	
	if(books.size()>0)
	{
		cout<<"\nThank you. You entered the following "<<pointers.size()<<" ratings: \n"<<"Rating\tBook\tPrice\n";
		for_each(pointers.begin(),pointers.end(),Showreview);
		while(1)
		{
			cout<<"\nEnter a character to choose different sorts:\n"
					"a.ordinary   b.letter   c.rating_by_low   d.rating_by_high\n"
					"e.price_by_low   f.price_by_high   q.quit\n";
			char ch;
			cin>>ch;
			while(cin.get()!='\n')
				continue;
				
	
			if(ch=='q'||ch=='Q')
				break;
				 
			switch(ch){
				case 'a':{
					cout<<"\nOrdinary order:\nRating\tBook\tPrice\n";
					for_each(pointers.begin(),pointers.end(),Showreview);
					break;
				}
				case 'b':{
					cout<<"\nSorted by letter of title:\nRating\tBook\tPrice\n";
					for_each(letterp.begin(),letterp.end(),Showreview);
					break;
				}
				case 'c':{
					cout<<"\nSorted by rating by low:\nRating\tBook\tPrice\n";
					for_each(r_by_lp.begin(),r_by_lp.end(),Showreview);
					break;
				}
				case 'd':{
					cout<<"\nSorted by rating by high:\nRating\tBook\tPrice\n";
					for_each(r_by_hp.begin(),r_by_hp.end(),Showreview);
					break;
				}
				case 'e':{
					cout<<"\nSorted by price by low:\nRating\tBook\tPrice\n";
					for_each(p_by_lp.begin(),p_by_lp.end(),Showreview);
					break;
				}
				case 'f':{
					cout<<"\nSorted by price by high:\nRating\tBook\tPrice\n";
					for_each(p_by_hp.begin(),p_by_hp.end(),Showreview);
					break;
				}	
			}
		}
		
//		sort(books.begin(),books.end(),worseThan);
//		cout<<"Sorted by rating:\nRating\tBook\n";
//		for_each(books.begin(),books.end(),Showreview);
	}
	else
		cout<<"NO ENTRIES.\nBYE\n"; 
	
	cout<<"bye\n";
	return 0;
}

bool operator<(const shared_ptr<review> &p1,const shared_ptr<review> &p2)
{
	if(p1->title<p2->title)
		return true;
	else if(p1->title==p2->title&&p1->rating<p2->rating)
		return true;
	else if(p1->title==p2->title&&p1->rating==p2->rating&&p1->price<p2->price)
		return true;
	else
		return false;
}
bool worseThan(const shared_ptr<review> &p1,const shared_ptr<review> &p2)//�Ͳ��Ƚϼ۸��� 
{
	if(p1->rating<p2->rating)
		return true;
	else
		return false;
}
bool cheaperThan(const shared_ptr<review> &p1,const shared_ptr<review> &p2)
{
	if(p1->price<p2->price)
		return true;
	else
		return false;
}
bool Fillreview(review &rr)
{
	cout<<"Enter book title (quit to quit): ";
	getline(cin,rr.title);
	if(rr.title=="quit")
		return false;
	cout<<"Enter book rating: ";
	cin>>rr.rating;
	cout<<"Enter book price: ";
	cin>>rr.price;
	if(!cin)
		return false;
	while(cin.get()!='\n')
		continue;
	return true;
}
void Showreview(const shared_ptr<review> &pp)
{
	cout<<pp->rating<<"\t"<<pp->title<<"\t"<<pp->price<<endl;
}
