#include <stdio.h>
#include<stdlib.h>


struct node
{
    int data;
    struct node *next;
};

void push(struct node **,int);
void display(struct node **);
void pop(struct node **);

 int main()
{
    int ch,data;
struct node *top=NULL;
while(1){
printf("1.push 2.pop 3.display 4.exit\n`");
scanf("%d",&ch);


    switch (ch)
    {
        case 1:
        printf("enter the data\n");
        scanf("%d",&data);
        push(&top,data);
        break;
        case 2:
        pop(&top);
        break; 
	case 3:
	display(&top);
	break;
        case 4:
        exit(1);
        break;
      	default:printf("enter the number between 1-4");
        break;
        
    }
}

    return 0;
}
void push(struct node **q,int data)
{
	struct node *temp;
	temp=*q;
	temp= (struct node *)malloc(sizeof(struct node));
	temp->data=data;
	temp->next=*q;
	*q=temp;	
	
}
void pop(struct node **q)
{
	struct node *temp;
	temp=*q;
	if(temp==NULL)
	{
		printf("No elements to delete");	
	}
	else
	{
		*q=temp->next;
		 free(temp);
		 temp=*q;		
	}
}

void display(struct node **q)
{
	struct node *temp;
	temp=*q;
	if(temp==NULL)
	printf("no elements to display\n");
	else
	{ 
		while (temp->next!=NULL)
		{
			printf("%d\n",temp->data);
			temp=temp->next;
		}
		printf("%d\n",temp->data);		
	}

}

