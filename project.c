//bus list
//ticket booking
//ticket cancel
//bus status
//exit


#include<stdio.h>
#include<stdlib.h>
#include<string.h>


void bus();

char st[10][130]={"Sakura","Hanif","Ena","Shamoli","Eagle"};






int main()
{
    system("cls");
int a;
 printf("\t\t\t\t\t\nWellcome to bus booking\n");
 printf("\t\t\t\t \n[1]=Bus list");
 printf("\t\t\t\t\t\n[2]=Ticket Booking");
 printf("\t\t\t\t\t\n[3]=Ticket cancle");
 printf("\t\t\t\t\t\n[4]=Bus Status");
 printf("\t\t\t\t\t\n[5]=Exit\n\n");

 printf("Choice your number");

scanf("%d",&a);

switch(a)




 case 1:
     {


      bus();
      break;
     }
}


void bus()
{
    system("cls");
    printf("\t\t\t\tWellcome to ticket booking");

    printf("\n[1]= %s\n",st[1]);
    printf("[1]= %s\n",st[2]);
    printf("[1]= %s\n",st[3]);
    printf("[1]= %s\n",st[4]);
    printf("[1]= %s\n",st[5]);






}
