//Accept file name from user read all content in that.
#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<unistd.h>
#include<iostream>
using namespace std;
class FileX
{
	public:
	int fd;
	FileX(char Name[])			
	{
		fd=open(Name,O_RDONLY);
		if(fd==-1)
		{
			cout<<"Unable to create file\n";
		}
		else
		{
			cout<<"File succesfully created\n";
		}
	}
	~FileX()
	{
		close(fd);
	}
	void ReadData()
	{
		char arr[10];
		int ret=0;
		while((ret=read(fd,arr,10))!=0)
		{
			write(1,arr,ret);
		}
	}
};
int main()
{
	char str[30];
	int no;
	cout<<"Enter file name\n";
	cin>>str;
	FileX obj(str);		
	
	obj.ReadData();
	return 0;
}

