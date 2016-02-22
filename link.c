#include <stdio.h>
#include <stdlib.h>
	struct emp{
		int ID;
		struct emp* nxt;
	};
	typedef struct emp Link;
	int flag=0;
	enum {delerr=1,udateerr};

Link* InsertList(Link*,int);
void PrintList (Link*);

Link* DeleteList (Link* p,int n){
	Link* tmp = p;
	Link* prev =p;
	while(tmp!=NULL)
	{
		if(tmp->ID==n){
			if (tmp==p)
				p=tmp->nxt;
				prev->nxt = tmp->nxt;
				free (tmp);
				flag=1;
			break;
		}
		else{
			prev=tmp;
			tmp=tmp->nxt;
		}
	}
	return p;
}
void UpdateList (Link* p,int n,int r)
{
	Link* tmp= p;
	while(tmp!=NULL)
	{
		if (tmp->ID==n)
		{
			tmp->ID= r;
			flag = 2; // whether list is updated or not
			break;
		}
		tmp=tmp->nxt;
	}
}
void SortList(Link* head){
	int tmp1;
	Link* tmp = head;
	Link* next;
	for (;tmp!=NULL;tmp=tmp->nxt)
	{
		for (next=tmp->nxt;next!=NULL;next=next->nxt)
		{
			if ((tmp->ID)>(next->ID))
				{
					tmp1=tmp->ID;
					tmp->ID=next->ID;
					next->ID=tmp1;
				}
		}
	}
}
int main()
{
	//printf("Please enter the numbers you want to enter into the list\n");
	//scanf
	int a[]= {10,20,30,40,50};
	Link* head=NULL;
	for (int j=0; j<5;j++)
		head = InsertList(head,a[j]);
	PrintList(head);
	
	head = DeleteList(head,20);
	if(flag==1)
	{
		PrintList(head);
	}
	else
		printf("Are Your kidding me? Wrong node to delete\n");
	
	UpdateList (head,30,6);
	if(flag==2)
	{
		PrintList(head);
	}
	else
		printf("Are Your kidding me? Wrong node to update\n");
	SortList(head);
	PrintList(head);
}

Link* InsertList(Link* head, int n)
{
Link* tmp;
tmp = (Link*) malloc (sizeof(Link));
tmp->ID= n;
tmp->nxt=head;
return tmp;
} 

void PrintList(Link* head)
{
	while (head != NULL)
	{
		printf("%d->",head->ID);
		head = head->nxt;
	}
printf("NULL");
printf("\n----------------------\n");
}