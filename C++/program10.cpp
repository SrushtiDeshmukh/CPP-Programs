
#include<fcntl.h>
#include<unistd.h>
#include<iostream>

using namespace std;
class FileX
{
	public:
	int fd;
	FileX(char Name[])	//FileX(char *Name)		
	{
		fd=creat(Name,0777);
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
};
int main()
{
	char str[30];
	cout<<"Enter file name\n";
	cin>>str;
	FileX obj(str);		//FileX obj(100);
	return 0;
}


/*
0777 = read , write & execute for owner, group and others

*/
