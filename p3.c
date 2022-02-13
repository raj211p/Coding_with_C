#include<stdio.h>

struct itemtemplate 
{ char name[20]; float uprice;
  int quant;
  float total, tax, finalsum;
};

void compute(int n)
{ struct itemtemplate item[n]; printf("\nData entry:\n"); float btotal=0;
  for(int i=0; i<n; i++)
  { printf("\nItem %d:",i+1);
    printf("\nItem name: "); scanf("%s",&item[i].name); fflush(stdin);
    printf("\nMRP per unit: "); scanf("%f",&item[i].uprice);
    printf("\nQuantity: ");  scanf("%d",&item[i].quant);
    item[i].total=((item[i].quant)*(item[i].uprice));
    item[i].tax=0.08*item[i].total;  item[i].finalsum=item[i].total+item[i].tax;
    btotal+=item[i].finalsum;
  }
 
 printf("\nFinal bill: ");
  for(int i=0; i<n; i++)
  { printf("\nItem %d:",i+1);
    printf("\nItem name: %s",item[i].name);
    printf("\nMRP per unit: %.2f",item[i].uprice);
    printf("\nQuantity: %d",item[i].quant);
    printf("\nTotal: %.2f",item[i].total);
    printf("\nTax: %.1f",item[i].tax);
    printf("\nTotal(after taxes): %.2f",item[i].finalsum);
  }
 printf("\nTotal bill amount: %.2f",btotal);
}

void main()
{ int n;
  printf("\nEnter the number of items on the bill: "); //Each 'item' may include multiple copies of 1 product
  scanf("%d",&n);     
  compute(n);
}