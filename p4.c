#include <stdio.h>
#include<stdlib.h>

struct course
{
 char ccode[15],cname[30];
};

void readinit(struct course *c)
{int i; printf("\nRegistration of courses: \nEnter the details of the 6 courses you wish to be enrolled in: \n");
 for(i=0;i<6;i++) 
 { printf("\nCourse name: "); gets(c[i].cname); fflush(stdin); printf("\nCourse code: "); gets(c[i].ccode); fflush(stdin);
 }
}

void readend(struct course *c)
{printf("\nDo you wish to drop any courses?(y/n) ");
 char ch; scanf("%c",&ch);
 if(ch=='y'||ch=='Y')
 { int n; printf("\nEnter the number of courses you wish to stay enrolled in: "); 
   scanf("%d",&n); struct course *c2=(struct course*)realloc(c,n*sizeof(struct course));
   int i; printf("\nRe-registration of courses: \nEnter the details of the courses you wish to stay enrolled in: \n");
   for(i=0;i<n;i++) 
    { printf("\nCourse name: "); scanf("%s",c2[i].cname); fflush(stdin);
      printf("\nCourse code: "); scanf("%s",c2[i].ccode); fflush(stdin);
    }
   printf("\nCourses retained: \n");
   for(i=0;i<n;i++) 
    { printf("\nCourse name: "); printf("%s",c2[i].cname);
      printf("\nCourse code: "); printf("%s",c2[i].ccode);
    }
  }
 else
   exit(0);
}

void main()
{
 struct course* c=(struct course*)malloc(6*sizeof(struct course));
 readinit(c); readend(c);
}

