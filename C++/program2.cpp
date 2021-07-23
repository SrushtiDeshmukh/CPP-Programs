#include<iostream>
using namespace std;
class Arithmetic
{
	public:		//Access specifier
		int iNo1,iNo2;		//Characteristics
		
		Arithmetic(int x,int y)		//Constructor
		{
			iNo1=x;
			iNo2=y;
		}
		
		int Addition()		//Behaviour
		{
			int iResult=0;
			iResult=iNo1+iNo2;
			return iResult;
		}
		int Subtraction()	//Behaviour
		{
			int iResult=0;
			iResult=iNo1-iNo2;
			return iResult;
		}
};
int main()
{
	int iRet1=0,iRet2=0;
	Arithmetic obj1(10,11);		//object creation
	Arithmetic obj2(20,15);		//object creation
	
	iRet1=obj1.Addition();
	cout<<"Addition is :"<<iRet1<<"\n";
	
		
	iRet2=obj2.Subtraction();
	cout<<"Subtraction is :"<<iRet2<<"\n";
	return 0;
}

