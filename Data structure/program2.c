//DOUBLY LINEAR LINKED LIST IN C.
#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node* prev;
	struct node* next;
};
typedef struct node NODE;
typedef struct node* PNODE;
typedef struct node** PPNODE;

void InsertFirst(PPNODE Head,int iNo)
{
	PNODE newn=NULL;
	newn=(PNODE)malloc(sizeof(NODE));	
	
	newn->data=iNo;
	newn->prev=NULL;
	newn->next=NULL;

	if(*Head==NULL)
	{
		*Head=newn;
	}
	else
	{
		newn->next=*Head;
		(*Head)->prev=newn;
		*Head=newn;
	}
}

void InsertLast(PPNODE Head,int iNo)
{
	PNODE newn=NULL;
	newn=(PNODE)malloc(sizeof(NODE));
	PNODE temp=*Head;
	
	newn->data=iNo;
	newn->prev=NULL;
	newn->next=NULL;
	
	if(*Head==NULL)
	{
		*Head=newn;
	}
	else
	{
		while(temp->next!=NULL)
		{
			temp=temp->next;
		}
		temp->next=newn;
		newn->prev=temp;
	}
}

void DeleteFirst(PPNODE Head)
{
	if(*Head==NULL)
	{
		return;
	}
	else if((*Head)->next==NULL)
	{
		free(*Head);
		*Head=NULL;
	}
	else
	{
		*Head=(*Head)->next;
		free((*Head)->prev);
		(*Head)->prev=NULL;
	}
}

void DeleteLast(PPNODE Head)
{
	PNODE temp=*Head;
	
	if(*Head==NULL)
	{
		return;
	}
	else if((*Head)->next==NULL)
	{	
		free(*Head);
		*Head=NULL;
	}
	else
	{
		while(temp->next->next!=NULL)
		{
			temp=temp->next;
		}
			free(temp->next);
			temp->next=NULL;				
	}
}

int Count(PNODE Head)
{
	int iCnt=0;
	while(Head!=NULL)
	{
		iCnt++;
		Head=Head->next;
	}
	return iCnt;
}
void Display(PNODE Head)
{
	while(Head!=NULL)
	{
		printf("|%d|<=>",Head->data);
		Head=Head->next;
	}
	printf("NULL\n");
}

void InsertAtPos(PPNODE Head,int iNo,int iPos)
{
	int iSize=0,i=0;
	PNODE newn=NULL;
	newn=(PNODE)malloc(sizeof(NODE));
	PNODE temp=*Head;

	iSize=Count(*Head);
	
	if(iPos<1 || (iPos>iSize+1))
	{
		printf("Enter valid position\n");
		return ;
	}	
	else if(iPos==1)
	{
		InsertFirst(Head,iNo);
	}
	else if(iPos==iSize+1)
	{
		InsertLast(Head,iNo);
	}
	else
	{
		newn->data=iNo;
		newn->prev=NULL;
		newn->next=NULL;

		for(i=1;i<(iPos-1);i++)
		{
			temp=temp->next;
		}		
			newn->next=temp->next;
			temp->next->prev=newn;
			temp->next=newn;
			newn->prev=temp;
	}
}	

/*void DeleteAtPos(PPNODE Head,int iNo,int iPos)
{
	int iSize=0,i=0;
	PNODE temp=*Head;
	PNODE target=NULL;

	iSize=Count(*Head);
	
	if(iPos<1 || iPos>iSize)
	{
		printf("Enter valid position\n");
		return ;
	}	
	else if(iPos==1)
	{
		DeleteFirst(Head);
	}
	else if(iPos==iSize)
	{
		DeleteLast(Head);
	}
	else
	{
		for(i=1;i<(iPos-1);i++)
		{
			temp=temp->next;
		}		
		target=temp->next;
		temp->next=target->next;
		target->next->prev=temp;
		free(target);			
	}
}*/

void DeleteAtPos(PPNODE Head,int iPos)
{
	int iSize=0,i=0;
	PNODE temp=*Head;
	iSize=Count(*Head);
	
	if(iPos<1 || iPos>iSize)
	{
		printf("Enter valid position\n");
		return;
	}
	else if(iPos==1)
	{
		DeleteFirst(Head);
	}
	else if(iPos==iSize)
	{
		DeleteLast(Head);	
	}
	else
	{
		for(i=1;i<iPos-1;i++)
		{
			temp=temp->next;
		}
		temp->next=temp->next->next;
		free(temp->next->prev);
		temp->next->prev=temp;
	}
}	

int main()
{
	PNODE First=NULL;
	int iChoice=0,iValue=0,iRet=0,iPos=0;
	
	do
	{
		printf("\n****************************\n");
		printf("Enter your choice\n");
		printf("1.Insert at first\n");
		printf("2.Insert at last\n");
		printf("3.Insert at position\n");
		printf("4.Delete at first\n");
		printf("5.Delete at last\n");
		printf("6.Delete at position\n");
		printf("7.Count no of nodes\n");
		printf("8.Display nodes\n");
		printf("0.Exit\n\n");
		scanf("%d",&iChoice);
	
		switch(iChoice)
		{
			case 1:
				printf("Enter data to insert\n");
				scanf("%d",&iValue);
				InsertFirst(&First,iValue);
				break;
			case 2:
				printf("Enter data to insert\n");
				scanf("%d",&iValue);
				InsertLast(&First,iValue);
				break;
			case 3:
				printf("Enter data to insert\n");
				scanf("%d",&iValue);
				printf("Enter position where data have to insert\n");
				scanf("%d",&iPos);
				InsertAtPos(&First,iValue,iPos);
				break;
			case 4:
				DeleteFirst(&First);
				break;
			case 5:
				DeleteLast(&First);
				break;
			case 6:
				printf("Enter position where data have to delete\n");
				scanf("%d",&iPos);
				DeleteAtPos(&First,iPos);
				break;
			case 7:
				iRet=Count(First);
				printf("No of nodes %d",iRet);
				break;
			case 8:
				Display(First);
				break;
			case 0:
				printf("Exit\n");
				break;
			default :
				printf("Enter valid choice\n");
		}
	}while(iChoice!=0);
	
	return 0;
}
