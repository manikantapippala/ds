#include<stdio.h>
#include<stdlib.h>
struct linklist{
	int data;
	struct linklist *next;
	};
void add(struct linklist **q,int val)
{
struct linklist *temp=*q,*r;
		
		
	if(temp==NULL)
	{	temp=malloc(sizeof(struct linklist*));
		temp->data=val;
		temp->next=NULL;
		*q=temp;
	}
	else
	{
		while(temp->next != NULL)
		{
			temp=temp->next;
		}
		r=malloc(sizeof(struct linklist*));
		r->data=val;
		r->next=NULL;
		temp->next=r;

	}	
}
void addfront(struct linklist **q,int val)
{
	struct linklist *temp=*q,*temp1;
	temp1=malloc(sizeof(struct linklist *));
	temp1->data=val;
	temp1->next=temp;
	*q=temp1;
}
void insert(struct linklist **q,int val,int pos)
{
	struct linklist *temp=*q,*temp1;
	int i;
	temp1=malloc(sizeof(struct linklist *));
	temp1->data=val;
	for(i=1;i<pos;i++)
	temp=temp->next;
	temp1->next=temp->next;
	temp->next=temp1;
	
}
void display(struct linklist **q)
{
	struct linklist *temp=*q;
	if(temp==NULL)
	printf("\nemplty list \n");
	else{
	while(temp != NULL)
	{
	printf("%d   ",temp->data);
	temp=temp->next;
	}}
}
void del(struct linklist **q)
{
	struct linklist *temp1,*temp=*q;
	if(temp==NULL)
	printf("no elements\n");
	else
	{
	while(temp->next->next != NULL)
	temp=temp->next;
	temp1=temp->next;
	temp->next=NULL;
	free(temp1);
	}
}
void delval(struct linklist **q,int key)
{
	struct linklist *temp1,*temp=*q;
	while(temp->next!=NULL)
	{
	if(temp->data==key)
	{
	temp1=temp->next;
	temp->next=temp->next->next;
	free(temp1);
	}
	else
	temp=temp->next;
	}
	//if(temp->next==NULL)
	//printf("\nKey is not found");
	
}
void delpos(struct linklist **q,int pos)
{
	struct linklist *temp1,*temp=*q;
	int i;
	for(i=1;i<pos;i++)
	temp=temp->next;
	temp1=temp->next;
	temp->next=temp->next->next;
	free(temp1);
}
void delfront(struct linklist **q)
{
	struct linklist *temp=*q,*temp1;
	if(temp==NULL)
	printf("empty list\n");
	else
	{
	temp1=temp;
	free(temp1);
	temp=temp->next;
	*q=temp;
	}
}
/*void copy(struct linklist **q, struct linklist **a)
{
	struct linklist *temp=*q,*temp1,*atemp=*a,*atemp1;
	if(temp==NULL)
	printf("empty list\n");
	else
	{
	while(temp->next!=NULL)
	{
	//temp1=malloc(sizeof(struct linklist *))	;
	add(&a,temp->data);
	temp=temp->next;
	}
	}
	
}*/
void destroy(struct linklist **q)
{
	struct linklist *temp1,*temp=*q;
	while(temp!=NULL)
	{
	temp1=temp;
	temp=temp->next;
	//printf("\n%d",temp1->data);
	free(temp1);
	}
	*q=temp;
}
int main()
{
	int i;
struct linklist *head=NULL,*copy=NULL;
struct linklist **q=&head,**a=&copy;
for(i=1;i<=5;i++)
add(&head,i);
delval(&head,2);
display(&head);
printf("\n");
for(i=1;i<=5;i++)
addfront(&head,i);
display(&head);
printf("\n");
//del(&head);
insert(&head,101,4);
display(&head);
printf("\n");

display(&head);
printf("\n");
delpos(&head,2);
display(&head);
printf("\n");
//copy(&head,&head1);
display(&head);
printf("\n");
delfront(&head);
display(&head);
printf("\n");
destroy(&head);
display(&head);
return 0;
}
