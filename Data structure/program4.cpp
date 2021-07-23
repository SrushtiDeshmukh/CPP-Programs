//SINGLY CIRCULAR IN CPP			
#include<iostream>
using namespace std;

typedef struct node
{
	int data;
	struct node* next;
}NODE,*PNODE;

class SinglyCL
{
	private:
	PNODE Head;
	PNODE Tail;
	int iSize;
	
	public:
	SinglyCL()
	{
		Head=NULL;
		Tail=NULL;
		iSize=0;
	}
	
	void InsertFirst(int iNo)
	{
		PNODE newn=NULL;
		newn=new NODE;
		newn->data=iNo;
		newn->next=NULL;
	
		if((Head==NULL) && (Tail==NULL))
		{
			Head=newn;
			Tail=newn;
		}
		else
		{
			newn->next=Head;
			Head=newn;
		}
			iSize++;
			Tail->next=Head;
	}

	void InsertLast(int iNo)
	{
		PNODE newn=NULL;
		newn=new NODE;
		newn->data=iNo;
		newn->next=NULL;
	
		if((Head==NULL) && (Tail==NULL))
		{
			Head=newn;
			Tail=newn;
		}
		else
		{
			Tail->next=newn;
			Tail=Tail->next;	//Tail=newn;
		}
			iSize++;
			Tail->next=Head;
	}
	
	int Count()
	{
		return iSize;
	}
	
	void Display()
	{
		PNODE temp=Head;
		int i=0;
		for(i=1;i<=iSize;i++)
		{
			cout<<"|"<<temp->data<<"|->"<<"\t";
			temp=temp->next;
		}
		cout<<"\n";
	}
	
	void DeleteFirst()
	{
		if((Head==NULL) && (Tail==NULL))
		{
			return ;
		}
		else if(Head==Tail)
		{
			delete Head;
			Head=NULL;
			Tail=NULL;
			iSize--;
		}
		else
		{
			Head=Head->next;
			delete (Tail->next);
			Tail->next=Head;
			iSize--;
		}
	}

	void DeleteLast()
	{
		if((Head==NULL) && (Tail==NULL))
		{
			return ;
		}
		else if(Head==Tail)
		{
			delete Head;
			Head=NULL;
			Tail=NULL;
			iSize--;
		}
		else
		{
			PNODE temp=Head;
			int i=0;
			for(i=1;i<iSize-1;i++)
			{
				temp=temp->next;
			}	
				delete Tail;
				Tail=temp;
				Tail->next=Head;
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

		if(iPos<1 || (iPos>iSize+1))
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

		if(iPos<1 || (iPos>iSize))
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
	SinglyCL obj;
	int iChoice=1,iRet=0,iPos=0,iValue;
	
	while(iChoice!=0)
	{
		cout<<"Enter your choice\n";
		cout<<"1:Insert at first \n";
		cout<<"2:Insert at last \n";
		cout<<"3:Insert at position \n";
		cout<<"4:Delete at first \n";
		cout<<"5:Delete at last \n";
		cout<<"6:Delete at position \n";
		cout<<"7:Display elements \n";
		cout<<"8:Count the nodes \n";
		cout<<"0:Exit \n";
		cin>>iChoice;

		switch(iChoice)
		{
		case 1:
			cout<<"Enter number\n";
			cin>>iValue;
			obj.InsertFirst(iValue);
			break;

		case 2:
			cout<<"Enter number\n";
			cin>>iValue;
			obj.InsertLast(iValue);
			break;
			
		case 3:
			cout<<"Enter number\n";
			cin>>iValue;
			cout<<"Enter position\n";
			cin>>iPos;
			obj.InsertAtPos(iValue,iPos);
			break;

		case 4:
			obj.DeleteFirst();
			break;
		
		case 5:
			obj.DeleteLast();
			break;
		
		case 6:
			cout<<"Enter position\n";
			cin>>iPos;
			obj.DeleteAtPos(iPos);
			break;

		case 7:
			obj.Display();
			break;
		
		case 8:
			iRet=obj.Count();
			cout<<"Number of nodes :"<<iRet<<"\n";
			break;
	
		case 0:
			cout<<"Exit\n";
			break;
		
		default:
			cout<<"Enter valid choice\n";
		}
	}
	return 0;
}
