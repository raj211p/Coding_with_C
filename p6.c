#include<stdio.h>
#include<stdlib.h>

#define BUFFER_SIZE 1000
 
void main()
{   FILE *fPtr;
    FILE *fTemp;
    char path[100];
    char buffer[BUFFER_SIZE];
    char newline[BUFFER_SIZE];
    int count=0,line;

    printf("\nEnter the name of the file to be modified: ");
    scanf("%s", path);
    fflush(stdin);
    /* char ch; printf("\nContents: \n");
    while(fPtr!=EOF)
    {ch=fgetc(fPtr); printf("%c",ch);
    } 
    fseek(fPtr,0,SEEK_SET);
    */
    printf("\nLine to be changed: number "); scanf("%d",&line);
    printf("\nNew text: ");
    scanf("%s",newline); 
    fPtr  = fopen(path, "r");
    fTemp = fopen("replace.txt", "w"); 

    if (fPtr == NULL || fTemp == NULL)
    {   printf("\nA file wasn't found! ");
        exit(0);
    }
    
    while ((fgets(buffer, BUFFER_SIZE, fPtr)) != NULL)
    {
      count++;
      if (count == line)
            fputs(newline, fTemp);
      else
            fputs(buffer, fTemp);
    }

    fclose(fPtr);
    fclose(fTemp);
    remove(path);
    rename("replace.txt", path);
    printf("\nReplacement successful."); char ch;
    printf("\nExit program?");
    scanf("%c",&ch);
}

