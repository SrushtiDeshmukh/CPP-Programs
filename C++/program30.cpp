//2. Write application which accept file name and one character from user. Count the frequency of that character in file.
#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<unistd.h>
#include<iostream>
using namespace std;
class FileX
{
	public:
	int fd=0;
	FileX(char *Name)
	{
		fd=open(Name,O_RDONLY);
		if(fd==-1)
			cout<<"Unable to open file\n";
		else
			cout<<"File created succesfully\n";
	}
	int Frequency(char ch)
	{
		char arr[10],*ptr=arr;
		int iCnt=0;
		int i=0,ret=0;
		while((ret=read(fd,arr,10))!=0)
		{
			read(fd,arr,ret);
			
			for(i=1;i<=ret;i++)
			{
				if(*ptr==ch)
				{
					iCnt++;
				}
				ptr++;
			}
		}		
		return iCnt;
	}
	~FileX()
	{
		close(fd);
	}
};
int main()
{
	char str[30]={'\0'},ch='\0';
	int ret;
	cout<<"Enter the file name\n";
	cin>>str;
	
	cout<<"Enter the character\n";
	cin>>ch;
	
	FileX obj(str);
	ret=obj.Frequency(ch);
	cout<<"Frequency of "<<ch<<" is "<<ret<<"\n";
}
