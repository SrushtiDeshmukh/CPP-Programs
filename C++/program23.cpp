//Maximum element from array using template class and function
#include<iostream>

using namespace std;

template <class T>
class Array
{
	private : 
		T *Arr;
		int iSize;
		
	public:
		Array(int no)
		{
			iSize = no;
			Arr = new T[iSize];
		}
		
		~Array()
		{
			delete []Arr;
		}
		
		void Accept()
		{
			cout<<"Enter the values \n";
			for(int  i = 0;i < iSize;i++)
			{
				cin>>Arr[i];
			}
		}
		
		T Maximum()
		{
			T Max = Arr[0];
			
			for(int i = 0;i < iSize;i++)
			{
				if(Arr[i] > Max)
				{
					Max = Arr[i];
				}
			}
			
			return Max;
		}
};

int main()
{
	int iRet1 = 0;
	float iRet2=0;
	int iNo=0;

	cout<<"Enter number of elements\n";
	cin>>iNo;		
	
	Array <int> *obj1=new Array <int>(iNo);
	Array <float> *obj2=new Array <float>(iNo);
	
	obj1->Accept();
	iRet1 = obj1->Maximum();
	cout<<"Maximum is : "<<iRet1<<"\n";
	delete obj1;
	
	obj2->Accept();
	iRet2 = obj2->Maximum();
	cout<<"Maximum is : "<<iRet2<<"\n";
	delete obj2;
		
	return 0;
}
