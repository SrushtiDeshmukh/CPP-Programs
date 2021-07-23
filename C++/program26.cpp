//2. Write application which accept file name from user and create that file.
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
	FileX(char *Name)
	{
		fd=creat(Name,O_CREAT);	
		if(fd==-1)
		{
			cout<<"Unable to create file\n";
		}
		else
		{
			cout<<"File created successfully\n";
		}
	}
};
int main()
{
	char str[30];
	cout<<"Enter file name\n";
	cin>>str;
	
	FileX obj(str);
	return 0;
}
