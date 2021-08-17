//SINGLY LINEAR IN CPP.
using namespace std;
#include<iostream>
struct node
{
	int data;
	struct node* next;
};
typedef struct node NODE;
typedef struct node* PNODE;

class SinglyLL
{
	private:
	PNODE Head;
	int iSize;
	
	public:
	SinglyLL()	//default constructor
	{	
		Head=NULL;
		iSize=0;
	}
	
	int Count()
	{
		return iSize;
	}
	
	void Display()
	{
		PNODE temp=Head;
		while(temp!=NULL)
		{
			cout<<temp->data<<"\t";
			temp=temp->next;
		}
		cout<<"\n";
	}

	void InsertFirst(int iValue)
	{
		PNODE newn=NULL;
		newn=new NODE;
		newn->data=iValue;
		newn->next=NULL;
		if(Head==NULL)
		{
			Head=newn;
		}
		else
		{
			newn->next=Head;
			Head=newn;
		}
		iSize++;
	}	
	
	void InsertLast(int iValue)
	{
		PNODE newn=NULL;
		PNODE temp=Head;
		newn=new NODE;
		newn->data=iValue;
		newn->next=NULL;
		if(Head==NULL)
		{
			Head=newn;
		}
		else
		{
			while(temp->next!=NULL)	
			{
				temp=temp->next;
			}
			temp->next=newn;
		}
		iSize++;
	}	

	void DeleteFirst()
	{
		if(Head==NULL)
		{
			return;
		}
		else
		{
			PNODE temp=Head;
			Head=Head->next;
			delete temp;
			iSize--;
		}
	}
/*	void DeleteFirst()
	{
		if(Head!=NULL)
		{
			PNODE temp=Head;
			Head=Head->Next;
			delete temp;
			iSize--;
		}
	}
*/
	
	void DeleteLast()
	{
		if(Head==NULL)
		{
			return;
		}
		else if(Head->next==NULL)	
		{
			delete Head;
			Head=NULL;
			iSize--;
		}
		else
		{
			PNODE temp=Head;
			while(temp->next->next!=NULL)
			{
				temp=temp->next;
			}
			delete temp->next;
			temp->next=NULL;
			iSize--;			
		}
	}
	
	void InsertAtPos(int iNo,int iPos)
	{
		int i=0;
		PNODE temp=Head;
		PNODE newn=NULL;
		newn=new NODE;
		newn->data=iNo;
		newn->next=NULL;
		
		if((iPos<1) || (iPos>iSize+1))
		{
			cout<<"Enter valid position\n";
			return;
		}
		else if(iPos==1)
		{
			InsertFirst(iNo);
		}
		else if(iPos==iSize+1)
		{
			InsertLast(iNo);
		}
		else
		{
			for(i=1;i<iPos-1;i++)
			{
				temp=temp->next;
			}
				newn->next=temp->next;
				temp->next=newn;
				iSize++;
		}
	}
	
	void DeleteAtPos(int iPos)
	{
		int i=0;
		PNODE temp=Head;
		PNODE target=NULL;
		
		if((iPos<1) || (iPos>iSize))
		{
			cout<<"Enter valid position\n";
			return;
		}
		else if(iPos==1)
		{
			DeleteFirst();
		}
		else if(iPos==iSize)
		{
			DeleteLast();
		}
		else
		{
			for(i=1;i<iPos-1;i++)
			{
				temp=temp->next;
			}
				target=temp->next;
				temp->next=target->next;
				delete target;	
				iSize--;	
		}
	}
};

int main()
{
	int iChoice=1,iNo=0,iPos=0;
	SinglyLL obj1;
	
	while(iChoice!=0)
	{
		cout<<"Enter Your choice :"<<"\n";
		cout<<"1:Insert at first"<<"\n";
		cout<<"2:Insert at last"<<"\n";
		cout<<"3:Insert at position"<<"\n";
		cout<<"4:Delete at first"<<"\n";
		cout<<"5:Delete at last"<<"\n";
		cout<<"6:Delete at position"<<"\n";
		cout<<"7:Display the contents"<<"\n";
		cout<<"8:Count nodes"<<"\n";
		cout<<"0:Exit"<<"\n";
		cin>>iChoice;

		switch(iChoice)
		{
			case 1:
				cout<<"Enter number\n";
				cin>>iNo;
				obj1.InsertFirst(iNo);
				break;
			case 2:
				cout<<"Enter number\n";
				cin>>iNo;
				obj1.InsertLast(iNo);
				break;
		
			case 3:
				cout<<"Insert data\n";
				cin>>iNo;
				cout<<"Enter position\n";
				cin>>iPos;
				obj1.InsertAtPos(iNo,iPos);
				break;
		
			case 4:
				obj1.DeleteFirst();
				break;

			case 5:
				obj1.DeleteLast();
				break;

			case 6:
				cout<<"Enter position\n";
				cin>>iPos;
				obj1.DeleteAtPos(iPos);
				break;

			case 7:
				obj1.Display();
				break;

			case 8:
				iNo=obj1.Count();
				cout<<"Number of elements are :"<<iNo<<"\n";
				break;

			case 0:
				cout<<"Exit"<<"\n";
				break;

			default:
				cout<<"Enter proper position"<<"\n";
		}
		
	}
	return 0;
}
