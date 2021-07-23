//4. Write application which accept file name from user and display size of file.
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
			cout<<"file opened successfully\n";
	}
	void Display()
	{
		int ret=0;
		char arr[10];
		int iCnt=0;
		while((ret=read(fd,arr,1))!=0)
		{
			iCnt++;
		}
		cout<<"size of the file is "<<iCnt<<"\n";
	}
};
int main()
{
	char str[30];
	cout<<"Enter the file name\n";
	cin>>str;
	
	FileX obj(str);
	obj.Display();
}
