//STACK
#include<iostream>
using namespace std;

typedef struct node
{
	int data;
	struct node* next;
}NODE,*PNODE;

class Stack
{
	private:
	  PNODE Head;
	  int iSize;
	
	public:
	  Stack();	
	  ~Stack();  	

	  void Push(int);	
	  int Pop();		
	  int Peek();
	  void Display();
	  int Count();
};

Stack::Stack()
{
	cout<<"Inside Constructor\n";
	this->Head=NULL;
	this->iSize=0;
}

Stack::~Stack()
{
	cout<<"Inside Destructor\n";
	PNODE temp=NULL;

	while(Head!=NULL)
	{
		temp=Head;
		Head=Head->next;
		delete temp;
	}	
}

void Stack::Push(int iNo)
{
	PNODE newn=new NODE;
	newn->data=iNo;
	newn->next=NULL;
	
	newn->next=Head;
	Head=newn;
	iSize++;
}


int Stack::Pop()
{
	int iRet=-1;
	
	if(iSize==0)
	{
		cout<<"Stack is empty\n";
	}
	else
	{
		PNODE temp=Head;
		Head=Head->next;
		iRet=temp->data;
		delete temp;
		iSize--;
	}
	return iRet;
}

int Stack::Peek()
{
	if(iSize==0)
	{
		cout<<"Stack is empty\n";
		return -1;
	}
	else
	{
		return Head->data;
	}
}

void Stack::Display()
{
	PNODE temp=Head;
	
	while(temp!=NULL)
	{
		cout<<temp->data<<"\t";
		temp=temp->next;
	}
	cout<<"\n";
}

int Stack::Count()
{
	return this->iSize;
}
int main()
{
	Stack *obj=new Stack;	
	int iOption=1,iRet=0,iNo=0;
	
	while(iOption!=0)
	{
		cout<<"Select the option\n";
		cout<<"1:Push the element\n";
		cout<<"2:Pop the element\n";
		cout<<"3:Display the elements\n";
		cout<<"4:Count elements\n";
		cout<<"5:Peek the element\n";
		cout<<"0:Exit\n";
		cin>>iOption;
	
		switch(iOption)
		{
			case 1:
				cout<<"Enter the element to push\n";
				cin>>iNo;
				obj->Push(iNo);
				break;
	
			case 2:
				iRet=obj->Pop();
				cout<<"Poped element is :"<<iRet<<"\n";				
				break;

			case 3:
				cout<<"Elements of stack are :\n";
				obj->Display();
				break;
			
			case 4:
				iRet=obj->Count();
				cout<<"Number of elements in stack are :"<<iRet<<"\n";
				break; 

			case 5:
				iRet=obj->Peek();
				cout<<"Value of top element is :"<<iRet<<"\n";
				break;
	
			case 0:
				cout<<"Exit\n";
				delete obj; 
				break;

			default:
				cout<<"Enter valid option\n";
		}
	}	
	
	return 0;
}

