#include<stdio.h>
struct cmp
{ int re,img;
};

void compute(struct cmp c1, struct cmp c2)
{ struct cmp c3;
  c3.re=c1.re+c2.re;
  c3.img=c1.img+c2.img;
  if(c3.img>=0)
  printf("\nSum: %d+%dj",c3.re,c3.img);
  else
  printf("\nSum: %d%dj",c3.re,c3.img);
  
  struct cmp c4;
  c4.re=c1.re-c2.re;
  c4.img=c1.img-c2.img;
  if(c4.img>=0)
  printf("\nDifference: %d+%dj",c4.re,c4.img);
  else
  printf("\nDifference: %d%dj",c4.re,c4.img);
  
  struct cmp c5;
  c5.re=((c1.re*c2.re)-(c1.img*c2.img));
  c5.img=((c1.re*c2.img)+(c1.img*c2.re));
  if(c5.img>=0)
  printf("\nProduct: %d+%dj",c5.re,c5.img);
  else
  printf("\nProduct: %d%dj",c5.re,c5.img);
}

void main()
{ struct cmp c1,c2;
  printf("\nReal component of the first number: ");
  scanf("%d",&c1.re); fflush(stdin);
  printf("\nImaginary component of the first number: ");
  scanf("%d",&c1.img); fflush(stdin);
  printf("\nReal component of the second number: ");
  scanf("%d",&c2.re); fflush(stdin);
  printf("\nImaginary component of the second number: ");
  scanf("%d",&c2.img); fflush(stdin);

  compute(c1,c2);
}