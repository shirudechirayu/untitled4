#include<stdio.h>
#include<stdlib.h>

typedef int listentry;

typedef struct node
{
	listentry data;
	struct node* next;
}NODE;

NODE* createnode(listentry data)
{
	NODE* p;
	p=(NODE*)malloc(sizeof(NODE));
	p->data=data;
	p->next=NULL;
	return p;
}

NODE* insertbegin(listentry data,NODE* head)
{
	NODE* p;
	p=createnode(data);
	p->next=head;
	head=p;
	return head;
}

NODE* insertend(listentry data,NODE* head)
{
	NODE *p,*curr;
	p=createnode(data);
	if(head==NULL)
	{
		head=p;
	}
	else
	{
		curr=head;
		while(curr->next!=NULL)
		{
			curr=curr->next;
		}
		
		curr->next=p;
	}
	return head;
}

void printlinkedlist(NODE* head)
{
	NODE *curr;
	curr=head;
	while(curr!=NULL)
	{
		printf("\n %d",curr->data);
		curr=curr->next;
	}
}


NODE* mergell(NODE *head1,NODE *head2)
{
	NODE *head3,*curr,*curr1;
	head3=NULL;
	curr=head1;
	curr1=head2;
	while(curr!=NULL&&curr1!=NULL)
	{
		if(curr->data<curr1->data)
		{
			
			head3=insertend(curr->data,head3);
			curr=curr->next;
		}
		else
		{
			
			head3=insertend(curr1->data,head3);
			curr1=curr1->next;
		}
	}
	if(curr==NULL)
	{
		while(curr1!= NULL)
		{
			head3=insertend(curr1->data,head3);
			curr1=curr1->next;
		}
	}
	else if (curr1==NULL)
	{
		while(curr!= NULL)
		{
			head3=insertend(curr->data,head3);
			curr=curr->next;
		}
	}
	return head3;
}

int main()
{
	NODE *head1,*head2,*head3;
	int choice=-1;
	head1=NULL;
	head2=NULL;
	head3=NULL;
	
	while(choice)
	{
		printf("\nEnter\n1.to insert data to l1\n2.to insert data to l2\n3.to make l3 with alternate data\n");
		scanf("%d",&choice);
		
		switch(choice)
		{
			case 1:
				int data;
				printf("Enter data\n");
				scanf("%d",&data);
				head1=insertend(data,head1);
				break;
				
			case 2:
				printf("Enter data\n");
				scanf("%d",&data);
				head2=insertend(data,head2);
				break;
				
			case 3:
				head3=mergell(head1,head2);
				printf("The merged list is\n");
				printlinkedlist(head3);
				break;
		}
		
	}
}
