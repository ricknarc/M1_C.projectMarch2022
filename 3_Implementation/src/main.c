#include<stdio.h>
#include<stdlib.h>
#define size 2


typedef struct NODE
{
	int registno;
	int userage;
	char name[20];
	struct NODE *next;
} node;

node* deq();
int create();
int reserve(node*);
int cancel(int);
void enq(node*);
void display();


node *start;
node *front;
node *rear;
int flag=0;
int number=0;

int create( )
{
	node *new;
	new=(node *)malloc(sizeof(node));
	new->registno=1;
	printf("Name: ");
	scanf("%s", new->name);
	printf("Age : ");
	scanf("%d", &new->userage);
    if(new->userage>=90 || new->userage<=10) {
        free(new);
        return -1;
    }
	start=new;
	new->next=NULL;
	number++;
    return 1;
	
}

int reserve(node *start)
{
	int temp;
	if(start==NULL)
	{   
   		temp = create(start);
		 return temp;
	}
	else 
	{
	
	node *temp, *new_node;
	temp=start;
	while(temp->next!=NULL)
	{ 
	  temp=temp->next;
	}
	
	new_node=(node *)malloc(sizeof(node));
	
	printf("Name: ");
	scanf("%s", new_node->name);
	printf("Age : ");
	scanf("%d", &new_node->userage);
    if(new_node->userage >=90 || new_node->userage<=10) {
        return -1;
    }
	new_node->next=NULL;
	if(number<=size)
	{
		number++;
		new_node->registno=number;
		temp->next=new_node;
		
		return 1;
	}
	else
	{
		enq(new_node);
		return 0;
	}
}
}


int cancel(int reg)
{
	node *ptr, *preptr, *new;
	ptr=start;
	preptr=NULL;
	if(start==NULL)
	return -1;
	if(ptr->next==NULL && ptr->registno==reg)
		{
		start=NULL;
		number--;
		free(ptr);
		return 1;
		
		}
		
	else{	
	while(ptr->registno!=reg && ptr->next!=NULL)
		{
			preptr=ptr;
			ptr=ptr->next;
		}
		if(ptr==NULL && ptr->registno!=reg)
			return -1;
		else
			preptr->next=ptr->next;
		free(ptr);
		new=deq();
		while(preptr->next!=NULL)
			preptr=preptr->next;
		preptr->next=new;
		number--;
		return 1;
	
	}
}

void enq(node *new_node)
{
	if(rear==NULL)
	{
		rear=new_node;
		rear->next=NULL;
		front=rear;
	}
	else
	{
		node *temp;
		temp=new_node;
		rear->next=temp;
		temp->next=NULL;
		rear=temp;
	}
	flag++;
}

node* deq()
{
	node *front1;
	front1=front;
	if(front==NULL)
		return NULL;
	else
	{
	    flag-- ;
		if(front->next!=NULL)
		{
			front=front->next;
			front1->next=NULL;
			return front1;
		}
		else
		{
			front=NULL;
			rear=NULL;
			
			return front1;
		}
	}	
}

// user name and Resistration function

void display()
{
	node *temp;
	temp=start;
	while(temp!=NULL)
	{
		printf("\nRegistration Number: %d\n", temp->registno);
		printf("Name : %s\n\n", temp->name);
		temp=temp->next;
    }
    
}

//Main function
int main()
{
	int choice, status=0,canc=0, reg=0;
	start=NULL;
	rear=NULL;
	front=NULL;
	printf("\t\t\t**RAILWAY RESERVATION**\t\t\t\t\n");
	int ch =0;
	while(ch!=4)
	{
	printf("\n\nDo you want to - \n 1. Book a ticket \n 2. Cancel Booking \n 3. Display passenger details \n 4. exit\n\n");
	scanf("%d", &choice); 
	switch(choice)
	{	
		case 1 :  status=reserve(start);
	              if(status==0)
	                printf("\nBooking Full!! \nYou are added to waiting list. Waiting list number %d", flag);
	              else if(status == -1) {
                      printf("\n userage not eligible");
                  }
                  else
	                printf(" \nBooking Successful!!! Enjoy your journey! Your Reg No is %d\n\n", number);
	                
	              break;
	        
	    case 2:   printf(" \n Give the Registration number to be cancelled\n");
	              scanf(" %d", &reg);
	              if(reg>number)
	              printf("Invalid!!");
	              else
	              {
	              canc=cancel(reg);
	              if(canc==-1)
	              	printf("\nRegistration number invalid!!\n");
	              else
	              	printf("\nRegistration cancelled successfully\n");
	              	}
	              break;
	              
	    case 3: display();
	    break;
	    case 4: exit(0);   
	    break;
	    default: printf("\nWrong choice!\n");                 
	
	}
	
}

}