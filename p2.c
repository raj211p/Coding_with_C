#include <stdio.h>
#include <stdlib.h>

struct node

{
 int data;
 struct node *next;
};


struct node* createnode()
{
 struct node *x; x=(struct node*)malloc(sizeof(struct node));
  if(x==NULL)
  {
   printf("\nMemory Allocation failed!"); exit(0);
  }
  x->next=NULL; return(x);
}

void display(struct node* head)
{ while(head!=NULL)
  { printf(" %d",head->data);
    head=head->next;
  }

}

struct node* insertatfront(struct node* head)

{ struct node* insert;
  insert=createnode();
  printf("\nEnter the value of the element: ");
  scanf("%d",&insert->data);
  insert->next=head;
  head=insert;
  return(head);
}

struct node* insertatlast(struct node* head)
{   
    struct node *temp=head;
    struct node*insert;
    insert=createnode();
    printf("\nEnter the value of the element: \n");
    scanf("%d",&insert->data);
    insert->next=NULL;
    while(temp->next!=NULL)
    { temp=temp->next;
    }
    temp->next=insert;
    return(head);
}

void sumofalternatenodes(struct node* head)
{int c=0,s=0;
      while(head!=NULL)
      { c++;
        if(c%2!=0)
           s=s+head->data;
	head=head->next;
      }
  printf("\nSum of alternate nodes: %d\n",s);
}

void sumofallelements(struct node* head)
{ int s=0;
  while(head!=NULL)
  {
    s=s+head->data;
    head=head->next;
  }
  printf("\nSum of nodes is :%d\n",s);
}

void sumofevenoddelements(struct node* head)
{   int s1=0,s2=0,c=0;
    while(head!=NULL)
    {
        c++;
        if(c%2==0)
            s2=s2+head->data;
        else
            s1=s1+head->data;
	head=head->next;
    }
    printf("\nSum of the even nodes: %d",s2);
    printf("\nSum of the odd nodes: %d",s1);
}

int main()
{
 struct node* head=NULL;
 int choice;
 do
  { printf("\n");
    printf("1.Display all the elements\n");
    printf("2.Insert at the front\n");
    printf("3.Insert at the end\n");
    printf("4.Sum of alternate node elements\n");
    printf("5.Sum of all elements in the list\n");
    printf("6.Sum of even and odd elements in the list\n");
    printf("7.Exit\n");
    printf("Enter your choice:\n");
    scanf("%d",&choice);

    switch(choice)
     {
     case 1:display(head);
            break;
     case 2:head=insertatfront(head);
            break;
     case 3:head=insertatlast(head);
            break;
     case 4:sumofalternatenodes(head);
            break;
     case 5:sumofallelements(head);
            break;
     case 6:sumofevenoddelements(head);
            break;
     case 7:exit(0);
     }
   }while(choice!=7);
}

