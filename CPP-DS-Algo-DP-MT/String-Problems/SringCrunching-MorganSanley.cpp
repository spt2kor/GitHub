#include <iostream>
#include <string>
using namespace std;
/*
remove string if consecutive char appear more then 2, recursively
	aabbccdddccbbaa	=>	"NULL"
	aabbcccbbddaa	=>	"aaddaa"
	abcde			=>	"abcde"

*/

string stringCrunching(const string & str);
string stringCrunchingNaive(const string & str);
void main()
{
	cout<<"\n Program Started "<<__FILE__<<endl;
	string str = "aabbccdddccbbaa";
	cout<<"\n current string str = "<<str<<endl;
	string result = stringCrunchingNaive(str);
	cout<<"\n result string = "<<result<<endl;

	//string test = "test";
	//cout<<"\n test[4] = "<<(int)test[4];		//prints null value as 0
	//cout<<"\n test[5] = "<<(int)test[5];
	cout<<"\n Program Ended"<<endl;
}

string stringCrunchingNaive(const string & str1)//aabbccdddccbbaa	
{

	if(str1.empty())
		return str1;

	
	string str = str1;
	string res(str.size(),0);

	while (1)
	{
		bool ischanged = false;
		int j=0;int k = 0;
		int count = 0;
		
		cout<<"\n str string = "<<str<<", str.size() = "<<str.size()<<endl;
		
		for(int i=0;i<str.size()+1 ; ++i)
		{

			if(str[i] == str[j])
			{
				count++;
			}
			else
			{
				if(count >2)
				{
					j = i;
					ischanged  = true;
				}
				else
				{
					while(i!=j)
					{
						res[k++]=str[j++]; 
					}
				}
				count = 1;
			}

		}//for(int i=0;i<str.size()+1 ; ++i)
		res[k] = 0;
		if(! ischanged )
			break;
		str = res.substr(0,k);
		
		res.erase();
		res.clear();
		res = str;
		cout<<"\n res string = "<<res<<", res.size() = "<<res.size()<<endl;
	}//while (1)

	return res;
}

//aabbbaa
//01234567
// j   i
string stringCrunching(const string & str)//aabbccdddccbbaa	
{
	if(str.empty())
		return str;

	char* res = new char[str.size()+1];
	
	int j = -1 ;
	int count = 0 ;
	int i = 0 ; 
	int * prev = new int [str.size()];
	for (int i=0;i<str.size();++i)
		prev[i] = i-1;

	while ( i< (str.size()+1) )
	{
		if(str[i] == str[j+1])
		{
			count++;
			++i;
		}
		else
		{
			if(count > 2) //count is 3,4,5,6
			{
				prev[i] = j;
				if(j > -1)
					j = j - 1;				
			}
			else    //count 0,1,2
			{
				j = i-1;
				count = 0;
			}
		}
	}

	return res;
}

