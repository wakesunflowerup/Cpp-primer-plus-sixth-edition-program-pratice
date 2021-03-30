#include <iostream>
#include <fstream>
#include <string>
#include <vector> 
#include <cstdlib>
#include <cctype>
#include <ctime>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

const int NUM=26;//我先生成了一个文件，再读取。运行一次后可以将写文件那部分代码注释掉 
vector<string> wordfile= {"apiary","beetle","cereal","danger","ensign","florid","garage",
	"health","insult","jackal","keeper","loaner","manage","nonce","onset","plaid","quilt",
	"remote","stolid","train","useful","valid","whence","xenon","yearn","zippy"}; 

int main(int argc, char** argv) {
	
	srand(time(0));
	char play;
	vector<string> wordlist;
	
	ofstream fout;
	fout.open("16-3wordlist.txt");
	for(int i=0;i<NUM;i++)
	{
		fout<<wordfile[i]<<" ";
	}
	fout.close();
	
	ifstream fin;
	fin.open("16-3wordlist.txt");
	if(!fin.is_open())
	{
		cout<<"16-3wordlist.txt is not opened.\n";
		exit(EXIT_FAILURE);
	}
	string temp;
	fin>>temp;
	while(fin.good())
	{
		wordlist.push_back(temp);
		fin>>temp;
	}
	
	if(fin.eof())
		cout<<"END of file reached.\n";
	else if(fin.fail())
		cout<<"input terminated by data mismatch.\n";
	else
		cout<<"input terminated by unknown reason.\n";
	fin.close();

	 
	cout<<"Will you play a word game?<y/n>: ";
	cin>>play;
	play=tolower(play);
	
	while(play=='y')
	{
		string target=wordlist[rand()%wordlist.size()];
		int length =target.length();
		string attempt(length,'-');
		string badchars;
		int guesses=6;
		cout<<"Guess my secret word.It has "<<length<<" letters, and you guess.\none letter at a time. You get "<<guesses<<" wrong guesses.\n";
		cout<<"Your word: "<<attempt<<endl;
		
		while(guesses>0&&attempt!=target)
		{
			char letter;
			cout<<"Guess a letter: ";
			cin>>letter;
			while(cin.get()!='\n')
				continue;
			
			letter=tolower(letter);
			if(badchars.find(letter)!=string::npos||attempt.find(letter)!=string::npos)
			{
				cout<<"You already guessed that. Try again.\n";
					continue;
			}
			
			int loc=target.find(letter);
			if(loc==string::npos)
			{
				cout<<"Oh, bad guess!\n";
				--guesses;
				badchars+=letter;
			}
			else
			{
				cout<<"Good guess!\n";
				attempt[loc]=letter;
				loc=target.find(letter,loc+1);
				while(loc!=string::npos)
				{
					attempt[loc]=letter;
					loc=target.find(letter,loc+1);
				}
			}
			
			cout<<"Your word: "<<attempt<<endl;
			if(attempt!=target)
			{
				if(badchars.length()>0)
					cout<<"Bad choices: "<<badchars<<endl;
			}
		}
		
		if(guesses>0)
			cout<<"That`s right!\n";
		else
			cout<<"Sorry, the word is "<<target<<".\n";
		cout<<"Will you play another?<y/n>: ";
		cin>>play;
		play=tolower(play);	
	}
	
	

	cout<<"bye\n";
	return 0;
}
