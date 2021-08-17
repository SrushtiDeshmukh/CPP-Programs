/*********Queue***********/
#include<iostream>
using namespace std;

typedef struct node
{
	int data;
	struct node* next;
}NODE, *PNODE;

class Queue
{
	private:
	  PNODE Head;
	  PNODE Tail;
	  int iSize;

	public:
	  Queue();
	  ~Queue();

	void EnQueue(int);
	int DeQueue();
	void Display();
	int Count();
};

Queue::Queue()
{
	cout<<"Inside constructor\n";
	Head=NULL;
	Tail=NULL;
	iSize=0;
}

Queue::~Queue()
{
	cout<<"Inside Destructor\n";
	while(Head!=NULL)
	{
		PNODE temp=Head;
		Head=Head->next;
		delete temp;
	}
	
}
	

void Queue::EnQueue(int iNo)	//InsertLast
{
	PNODE newn=new NODE;
	newn->data=iNo;
	newn->next=NULL;	
	
	if(Head==NULL && Tail==NULL)
	{
		Head=newn;
		Tail=newn;
	}
	else
	{
		Tail->next=newn;
		Tail=newn;
	}
	iSize++;
}

int Queue::DeQueue()	//DeleteFirst
{
	int iRet=-1;
	PNODE temp=Head;

	if(Head==NULL && Tail==NULL)
	{
		cout<<"Queue is empty\n";
	}
	else if(Head==Tail)
	{
		iRet=Head->data;
		delete Head;
		Head=NULL;
		Tail=NULL;
		iSize--;	
	}
	else
	{
		Head=Head->next;
		iRet=temp->data;
		delete temp;	
		iSize--;
	}
		return iRet;
}

void Queue::Display()
{
	PNODE temp=Head;
	while(temp!=NULL)
	{
		cout<<"|"<<temp->data<<"|=>";
		temp=temp->next;
	}
	cout<<"NULL\n";
}

int Queue::Count()
{
	return iSize;
}

int main()
{
	Queue *obj=new Queue;
	int iChoice=0,iRet=0,iNo=0;

	do
	{
		cout<<"Enter your Choice\n";
		cout<<"1:Add element in queue\n";
		cout<<"2:Remove element from queue\n";
		cout<<"3:Display elements in queue\n";
		cout<<"4:Count the elements in queue\n";
		cout<<"0:Exit\n";
		cin>>iChoice;

		switch(iChoice)
		{
			case 1:
				cout<<"Enter element to add\n";
				cin>>iNo;
				obj->EnQueue(iNo);
				break;

			case 2:
				iRet=obj->DeQueue();
				cout<<"Removed element is :"<<iRet<<"\n";
				break;

			case 3:
				cout<<"Elements in queue are :\n";
				obj->Display();
				break;

			case 4:
				iRet=obj->Count();
				cout<<"Number of elements :"<<iRet<<"\n";
				break;
	
			case 0:
				cout<<"Exit\n";
				break;

			default:
				cout<<"Enter valid choice\n";
		}
	}while(iChoice!=0);	

	return 0;
}


/*
	class node: def __init__(self,data): self.data=data self.next=None class Queue: def __init__(self): print("Inside Constructor") self.head=None self.iSize=0 def enQueue(self,iNo): newn=node(iNo) temp=self.head if self.head==None: self.head=newn else: while temp.next!=None: temp=temp.next temp.next=newn self.iSize=self.iSize+1 def deQueue(self): temp=None iRet=None if self.head==None: print("The Queue is empty") return iRet else: self.iSize=self.iSize-1 temp=self.head self.head=self.head.next iRet=temp.data del temp return iRet def display(self): if self.head==None: print("The Queue is empty") else: temp=self.head while temp!=None: print(temp.data,end=" ") temp=temp.next def count(self): if self.head==None: print("The Queue is empty") else: return self.iSize def __del__(self): print("Inside Destructor") temp=None while self.head!=None: temp=self.head self.head=self.head.next del temp 
*/

/*
#include<iostream>
using namespace std;

typedef struct node
{
    int data;
    struct node *next;
}NODE, *PNODE;

class Queue
{
private:
    PNODE Head;
    int iSize;
    
public:
    Queue();
    void Display();
    int Count();
    void Enqueue(int);
    int Dequeue();
};

Queue::Queue()
{
    Head = NULL;
    iSize = 0;
}

void Queue::Display()
{
    PNODE temp = Head;
    cout<<"Elements of queue are\n";
    while(temp != NULL)
    {
        cout<<temp->data<<"\t";
        temp = temp -> next;
    }
    cout<<"\n";
}

int Queue::Count()
{
    return iSize;
}

void  Queue::Enqueue(int iNo)   // InsertLast
{
    PNODE newn = new NODE;
    newn->data = iNo;
    newn->next = NULL;
    
  if(Head == NULL)
  {
      Head = newn;
  }
  else
  {
    PNODE temp = Head;
    while(temp-> next != NULL)
    {
        temp = temp -> next;
    }
    temp->next = newn;
  }
    iSize++;
}

int Queue::Dequeue()    // Delete First
{
    if(Head == NULL)
    {
        cout<<"Queue is empty\n";
        return -1;
    }
    else
    {
        int iNo = Head -> data;
        PNODE temp = Head;
        Head = Head -> next;
        delete temp;
        iSize--;
        
        return iNo;
    }
}

int main()
{
    Queue obj;
    int iChoice = 1, iNo = 0, iRet = 0;
    while(iChoice != 0)
    {
        cout<<"Pleaseeneter the option\n";
        cout<<"1 : Insert the element\n";
        cout<<"2 : Delete the element\n";
        cout<<"3 : Display the elemenets\n";
        cout<<"4 : Count the enumber of elements\n";
        cout<<"0 : Terminate the application\n";
        cin>>iChoice;
        switch(iChoice)
        {
            case 1:
                cout<<"Enter th elemenet\n";
                cin>>iNo;
                obj.Enqueue(iNo);
                break;
                
            case 2:
                iRet = obj.Dequeue();
                cout<<"Removed element is : "<<iRet<<"\n";
                break;
                
            case 3:
                obj.Display();
                break;
                
            case 4 :
                iRet = obj.Count();
                cout<<"Number of elements in queue are : "<<iRet<<"\n";
                break;
                
            case 0:
                cout<<"Thank you for using the application\n";
                break;
                
            default:
                cout<<"Please enter the proper choice\n";
                break;
        }// End of switch
    } // End of while
    
    
    return 0;
}// End of main


*/
