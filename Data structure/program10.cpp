/*2. Write a program which search last occurrence of particular element from
singly linear linked list.
Function should return position at which element is found.*/
//Input linked list : |10|->|20|->|30|->|40|->|50|->|30|->|70|
//Input element : 30
//Output : 3
#include<stdio.h>
#include<stdlib.h>
struct node
{
	int Data;
	struct node *Next;
};
typedef struct node NODE;
typedef struct node* PNODE;
typedef struct node** PPNODE;
void InsertLast(PPNODE Head,int iNo)
{
	PNODE newn=NULL;
	PNODE temp=*Head; 
	newn=(PNODE)malloc(sizeof(NODE));
	
	newn->Data=iNo;
	newn->Next=NULL;

	if(*Head==NULL)
	{
		*Head=newn;
	}
	else
	{
		while(temp->Next!=NULL)
		{
			temp=temp->Next;
		}
		temp->Next=newn;
	}
}
int LastOccurence(PNODE Head,int iNo)
{
	int iCnt=0;
	int iPos=0;
	if(Head==NULL)
	{
		printf("LL is  empty\n");
		return 0;
	}
	else
	{
		while(Head!=NULL)
		{
			iCnt++;		
			if(Head->Data==iNo)
			{	
				iPos=iCnt;	
			}
			Head=Head->Next;
		}	
	}
	return iPos;
}
void Display(PNODE Head)
{
	while(Head!=NULL)
	{
		printf("|%d|->\t",Head->Data);
		Head=Head->Next;
	}
	printf("NULL\n");
}
int main()
{
	PNODE First=NULL;
	int ch=0;
	do
	{
		printf("\t1.Insert element\n");
		printf("\t2.Display\n");
		printf("\t3.Last occ of given element\n");
		printf("\t0.Exit\n");
		
		printf("Enter choice\n");
		scanf("%d",&ch);
		
		switch(ch)
		{
			case 1:
			{	
				int iValue=0;
				printf("Enter no u want to insert\n");
				scanf("%d",&iValue);
				InsertLast(&First,iValue);
				break;
			}		
			case 2:
			{
				Display(First);
				break;
			}
			case 3:
			{
				int iNo=0;
				int iRet=0;
				printf("Enter no u want to search\n");
				scanf("%d",&iNo);
				iRet=LastOccurence(First,iNo);
				if(iRet==0)
					printf("No such elements in LL\n");
				else
					printf("Last occurence is %d\n",iRet);
					break;
			}
			case 0:
				printf("Exit the application\n");
				break;
				
			default :
				printf("Enter valid choice\n");
		}
	}while(ch!=0);
	
	return 0;
}
