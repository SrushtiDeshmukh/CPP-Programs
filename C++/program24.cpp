//Singly linked list in generic way
#include<iostream>
using namespace std;

template<class T>
struct node
{
	T data;
	struct node* next;		
};

template <class T>
class SinglyLL
{
	private:
	 struct node<T> *Head;	
	 int iSize;

	public:
	SinglyLL();
	void Display();
	int Count();
	void InsertFirst(T);
};

template <class T>
void SinglyLL<T>::InsertFirst(T no)
{
	struct node<T> *newn=new struct node<T>;
	newn->data=no;
	newn->next=NULL;

	newn->next=Head;
	Head=newn;
	iSize++;
}

template <class T>
int SinglyLL<T>::Count()
{
	return iSize;
}
	
template <class T>
void SinglyLL<T>::Display()
{
	struct node<T> *temp=Head;
	while(temp!=NULL)
	{
		cout<<temp->data<<"\t";
		temp=temp->next;
	}
	cout<<"\n";
}

template <class T>
SinglyLL<T>::SinglyLL()
{
	Head=NULL;
	iSize=0;
}

int main()
{
	SinglyLL <double>obj1;
	obj1.InsertFirst(51.3);
	obj1.InsertFirst(21.9);
	obj1.InsertFirst(11.5);
	obj1.Display();
	
	SinglyLL <char>obj2;
	obj2.InsertFirst('A');
	obj2.InsertFirst('B');
	obj2.InsertFirst('C');
	obj2.InsertFirst('D');
	obj2.Display();
	
	cout<<"length of LL is :"<<obj1.Count()<<"\n";
	cout<<"length of LL is :"<<obj2.Count()<<"\n";

	return 0;
}
