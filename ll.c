#include <stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next;
};

void insert_at_begin(struct node **,int);
void insert_at_end(struct node **,int);
void display(struct node **);
void delete_from_begin(struct node **);
void delete_from_end(struct node **);
void insert_at_position(struct node **, int , int);
void delete_at_position(struct node **, int);
 int main()
{
    int ch,data,pos;
struct node *start=NULL;
 
while(1){
printf(" 1.insertion at begin\n 2.insertion at end\n 3.display\n 4.delete from begin\n 5.delete from end\n 6.insert_at_position\n 7.delete_at_position\n 8.exit\n");
scanf("%d",&ch);
switch (ch)
{
        case 1:
        printf("enter the data\n");
        scanf("%d",&data);
        insert_at_begin(&start,data);
        break;
        case 2:
        printf("enter the data\n");
        scanf("%d",&data);
        insert_at_end(&start,data);
        break; 
	case 3:
	display(&start);
	break;
        case 4:
        delete_from_begin(&start);
        break;
        case 5:
        delete_from_end(&start);
        break;
	case 6:
	printf("enter the data and position\n");
        scanf("%d %d",&data,&pos);	
        insert_at_position(&start,pos,data);
        break;
	case 7:
	printf("enter the position\n");
        scanf("%d",&pos);	
        delete_at_position(&start,pos);
        break;
        case 8:
        exit(0);
       default:printf("invalid");
        break;
        
    }
}

    return 0;
}
void insert_at_begin(struct node **q,int data)
{
	struct node *temp,*n;
	temp=*q;
	if(temp==NULL)
	{
		temp= (struct node *)malloc(sizeof(struct node));
		temp->data=data;
		temp->next=NULL;
		*q=temp;	
	}
	else
	{
		n=(struct node *)malloc(sizeof(struct node));
		n->data=data;
		n->next=temp;	
		*q=n;	
	}
}
void insert_at_end(struct node **q,int data)
{
	struct node *temp,*n;
	temp=*q;
	if(temp==NULL)
	{
		temp= (struct node *)malloc(sizeof(struct node));
		temp->data=data;
		temp->next=NULL;
		*q=temp;	
	}
	else
	{
		while(temp->next !=NULL)
			temp=temp->next;
		n=(struct node *)malloc(sizeof(struct node));
		n->data=data;
		n->next=NULL;
		temp->next=n;		
	}
}
void delete_from_begin(struct node **q)
{
	struct node *temp;
	temp=*q;
	if(temp==NULL)
	{
		printf("No elements ro delete");	
	}
	else
	{
		*q=temp->next;
		 free(temp);
		 temp=*q;		
	}
}
void delete_from_end(struct node **q)
{
	struct node *temp,*temp1;
	temp=*q;
	if(temp==NULL)
	{
		printf("No elements ro delete");	
	}
	else
	{
		while(temp->next->next != NULL)
		temp=temp->next;
		temp1=temp->next;
		temp->next=NULL;
		free(temp1);
	}
	
}
void display(struct node **q)
{
	struct node *temp;
	temp=*q;
	if(temp==NULL)
	printf("no elements to display");
	else
	{ 
		while (temp->next!=NULL)
		{
			printf("%d  ",temp->data);
			temp=temp->next;
		}
		printf("%d  ",temp->data);
		printf("\n");		
	}


}
void insert_at_position(struct node **q, int pos, int data)
{
	struct node *temp,*n;
	temp=*q;
	if(temp==NULL)
	{
		temp= (struct node *)malloc(sizeof(struct node));
		temp->data=data;
		temp->next=NULL;
		*q=temp;	
	}
	else
	{
		for(int i=1;i<pos-1;i++)
			temp=temp->next;
		n=(struct node *)malloc(sizeof(struct node));
		n->data=data;
		n->next=temp->next;
		temp->next=n;		
	}
}
void delete_at_position(struct node **q, int pos)
{
	struct node *temp;
	temp=*q;
	if(temp==NULL)
	printf("no elements to display");
	else
	{ 
		for(int i=1;i<pos-1;i++)
		{
			temp=temp->next;
		}
		temp->next=temp->next->next;
		temp=temp->next;
		free(temp);		
	}

}
