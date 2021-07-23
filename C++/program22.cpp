//max in array by generic
#include<iostream>
using namespace std;

template <class T>
T Maximum(T Arr[],int iSize)
{
	T iMax=Arr[0];
	for(int i=0;i<iSize;i++)
	{
		if(Arr[i]>iMax)
			iMax=Arr[i];
	}
	return iMax;
}

int main()
{
	float *arr=NULL;
	int iSize=0;
	float iRet=0;

	cout<<"Enter the no of elements\n";
	cin>>iSize;

	arr=new float[iSize];
	
	cout<<"Enter the values\n";
	for(int i=0;i<iSize;i++)
	{
		cin>>arr[i];
	}
	iRet=Maximum(arr,iSize);
	cout<<"Largest no is :"<<iRet<<"\n";	
	
	delete []arr;	
	return 0;
}
