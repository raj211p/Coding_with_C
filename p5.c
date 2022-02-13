#include<stdio.h>
#include<stdlib.h>

struct node

{
 int data;
 struct node *link;
};

struct node *start=NULL;

void createnode()
{
 struct node *temp;
  temp=(struct node *)malloc(sizeof(struct node));
  if(temp==NULL)
  {
    printf("\nMemory unavailable! ");
    return;
  }
  printf("\nEnter a value: ");
  scanf("%d",&temp->data);
  temp->link=NULL;
  if(start==NULL)  //Adding the 1st node
  { start=temp;
  }
  else             //Adding subsequent nodes
  { struct node* ptr=start;
    while(ptr->link!=NULL)
    {
      ptr=ptr->link;
    }
    ptr->link=temp;
  }
}

void display()
{ struct node *ptr=start; int flag=0;
  while(ptr!=NULL)
  { printf("%d ",ptr->data); flag=1;
    ptr=ptr->link;
  }
  if(flag==0)
    printf("\nThe list is empty.");
}

void delfront()
{ struct node* ptr;
  ptr=start; 
  if(ptr==NULL)
    printf("\nThe list is empty.");  
  else
   { start=start->link; free(ptr);
   }
}

void dellast()
{ struct node *ptr=start; struct node *temp;
  if(ptr==NULL)
    printf("\nThe list is empty.");  
  else
  { 
    while(ptr->link!=NULL)
     { temp=ptr; ptr=ptr->link;
     }
    temp->link=NULL; free(ptr);
  }
}

void search()
{struct node *ptr=start; int x,i=0; 
 printf("\nEnter the value to be found: "); scanf("%d",&x); int flag=0;
 while(ptr!=NULL)
  { if(x==ptr->data)
    { printf("\nThe element was found at position %d.",i+1); 
      flag=1;
    }
    ptr=ptr->link; i++;
  }
 if(flag==0)
    printf("\nThe element was not found in the list.");
}

void findproduct()
{ int div; printf("\nEnter the number which should be a factor of some of the nodes: ");
  scanf("%d",&div); int product=1; struct node *ptr=start; int flag=0;
  while(ptr!=NULL)
  {if(((ptr->data)%div)==0)
    { product*=ptr->data; flag=1;
    }
   
   ptr=ptr->link;
  }
  if(flag==1)
      printf("\nProduct of the nodes that are divisible by %d: %d\n",div,product);
  
  else
      printf("\nNone of the elements in the list are divisible by %d.",div);   
}

int main()
{
 int choice;
 do
  { printf("\n");
    printf("\n1.Display all the elements");
    printf("\n2.Insert an element at the end");
    printf("\n3.Delete an element at the front");
    printf("\n4.Delete an element at the end");
    printf("\n5.Search for an element in the list");
    printf("\n6.Find the product of all the elements that are divisible by a given number");
    printf("\n7.Exit");
    printf("\nEnter your choice:\n");
    scanf("%d",&choice);

    switch(choice)
    {
     case 1:display();
            break;
     case 2:createnode();
            break;
     case 3:delfront();
            break;
     case 4:dellast();
            break;
     case 5:search();
            break;
     case 6:findproduct();
            break;
     case 7:exit(0);
    }
   }while(choice!=7);
}
