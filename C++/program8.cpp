#include<iostream>
using namespace std;
//input : _ _ _Abc_ _ _pqr_ _ _A_ _AB_ _
//output:4
class StringX
{
	public:
	char ptr[30];
	
	void Accept()
	{
		cout<<"Enter String\n";
		scanf("%[^'\n']s",ptr);
	}
	int WordCount()
	{
		int iCnt=0;
		char *str=ptr;	
		while(*str!='\0')
		{
		
			if(*str==' ')
			{
				while((*str==' ') && (*str!='\0'))
				{
					str++;
				}
			}
			else
			{
				while((*str!=' ') && (*str!='\0'))
				{
					str++;
					if(*str==' ')
	 					iCnt++;
				}
			}
		}
		return iCnt;	
	}
};
int main()
{	
	int ret=0;
	StringX obj;
	obj.Accept();
	ret=obj.WordCount();
	cout<<"Word Count is :"<<ret<<"\n";
	return 0;
}
