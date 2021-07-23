//Max between 2 nos using function template.
#include<iostream>
using namespace std;

template <class T>
T Max(T iNo1,T iNo2)
{
	if(iNo1>iNo2)
		return iNo1;
	else
		return iNo2;
}

int main()
{
	int iValue1=0,iValue2=0,iRet1=0;
	float iNo1=0,iNo2=0,iRet2=0;
	
	cout<<"Enter two nos\n";
	cin>>iValue1>>iValue2;

	cout<<"Enter two nos\n";
	cin>>iNo1>>iNo2;
	
	iRet1=Max(iValue1,iValue2);
	cout<<"Maximum is :"<<iRet1<<"\n";
	
	iRet2=Max(iNo1,iNo2);
	cout<<"Maximum is :"<<iRet2<<"\n";
	
	return 0;
}
