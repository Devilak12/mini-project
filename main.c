#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<stdlib.h>

cstr[100];
int t=0;
int n=0; //used in Quantity and Records.txt
int k=0;
int ba=0;
int ti=0;
int *g;
struct item
{
	int productno;
	char productname[50];
	int quantity;
	int price;
}
item;
void create()
{
	int i=0;
	FILE *fp;
	fp=fopen("Records.txt","w");
	if(fp==NULL)
	{
		printf("Error\n");
	}
	printf("\t");
	printf("Enter the Number of Records:");
	scanf("%d",&n);
	printf("\n");
	FILE *fpq;
	fpq=fopen("Quantity.txt","w");
	//fprintf(fp,"productno\t,ProductName\t, Quantity\t, Price\n");
	fprintf(fpq,"%d",n);
	fclose(fpq);
	while(i<n)
	{
	    printf("\t");
		printf("Enter Product Code:");
		scanf("%d",&item.productno);
		printf("\t");
		printf("Enter Product Name:");
		scanf("%s",&item.productname);
		printf("\t");
		printf("Enter Quantity:");
		scanf("%d",&item.quantity);
		printf("\t");
		printf("Enter Price:");
		scanf("%d",&item.price);
		printf("\n");
		i++;
		fprintf(fp,"%d\t\t",item.productno);
		fputs(item.productname,fp);
		fprintf(fp,"\t%d\t%d\n",item.quantity,item.price);
	}
	g=fp;
	fclose(fp);
	printf("\t");
	printf("Records are Created");
	printf("\n");
	printf("\n");
}
void edit()
{
	FILE *fp;
	FILE *fptr;
	FILE *fpk;
	int h;
	int found=0;
	int ka=0;
	int p;
	fp=fopen("Records.txt","r");
	fptr=fopen("temp1.txt","w");
	fpk=fopen("temp2.txt","w");
	printf("\t");
	printf("Enter the Product Number to Delete: ");
	scanf("%d",&h);
	printf("\n");
	p=n;
	while(!(ka==p))
	{
		ka++;
		fscanf(fp,"%d",&item.productno);
		if(item.productno==h)
		{
			found=1;
			fscanf(fp,"%s",&item.productname);
			fscanf(fp,"%d",&item.quantity);
			fscanf(fp,"%d",&item.price);
			n--;
			printf("\t");
			printf("Product has been Successfully Deleted\n");
		}
		else
		{
			fscanf(fp,"%s",item.productname);
			fscanf(fp,"%d",&item.quantity);
			fscanf(fp,"%d",&item.price);
			fprintf(fptr,"%d\t%s\t%d\t%d\t",item.productno,item.productname,item.quantity,item.price);
		}
	}
	fprintf(fpk,"%d",n);
	fclose(fpk);
	fclose(fptr);
	fclose(fp);
	if(found==0)
	{
	    printf("\t");
		printf("Product no Found");
		printf("\n");
		printf("\n");
	}
	remove("Quantity.txt");
	rename("temp2.txt","Quantity.txt");
	remove("Records.txt");
	rename("temp1.txt","Records.txt");
}
void display()
{
	int nk=0;
	FILE *fp;
	fp=fopen("Records.txt","r");
	if(feof(fp))
	{
		printf("Error in Opening Files\n");
	}
	printf("\t");
	printf("==============================================================\n");
	printf("\t");
	printf("|Product Number\t|Product Name\t|Quantity\t|Price\t\n");
	printf("\t");
	printf("==============================================================\n");
	while(nk!=n)
	{
		nk++;
		fscanf(fp,"%d",&item.productno);
		if(item.productno==0)
		{
		    printf("\t");
			printf("There are no items in Cart");
			printf("\n");
			break;
		}
		fscanf(fp,"%s",&item.productname);
		fscanf(fp,"%d",&item.quantity);
		fscanf(fp,"%d",&item.price);
		printf("\n\t  %14d|\t%8s|\t%8d|\t%d|\n",item.productno,item.productname,item.quantity,item.price);
        //printf("\n");
	}
	fclose(fp);
}


struct customer
{
	int productno;
	char productname[10];
	int quantity;
	int price;
	int amount;
}
cst[100];

int main()
{
	char ch,password[10],q[10]="progto";
	int s=0;
	int y=0;
	int w=1;
	int i;
	FILE *fpe;
	fpe=fopen("Quantity.txt","r");
	fscanf(fpe,"%d",&n);
	fclose(fpe);
	printf("\n");
	printf("************************************************************************************************************************");
	printf("\n");
	printf("*****************************************    WELCOME TO DENIMXPRESS    *************************************************");
	printf("\n");
	printf("\t                               YOU ARE LUCKY TO BE SHOPPING HERE");
	printf("\n\n");
	printf("\t\t\tPlease note that all the Product's Price are Discounted and are Genuine");
	printf("\n");
	printf("\t\t\t\t\t");
    printf("      Reference Number: %d\n",n);
    q: printf("\n\t");
    printf("****************************");
    printf("\n");
    printf("\t");
    printf("Please Select an Option: ");
    printf("\n");
    printf("\t");
    printf("****************************");
    printf("\n");
    printf("\t");
	printf("01. ADMINISTRATOR");
	printf("\n\t");
	printf("02. CUSTOMER");
	printf("\n\t");
	printf("03. EXIT");
	printf("\n");
	printf("\n\t");
	printf("Please Enter an Option: ");
	scanf("%d",&s);

	switch(s)
	{
	          case 1: printf("\tEnter Password:\t");
              for(i=0;i<6;i++)
              {
              ch = getch();
              password[i] = ch;
              ch = '*' ;
               printf("%c",ch);
              }
              password[i]='\0';
              if(strcmp(password,q))
              {
                  printf("\n\t");
              printf("Wrong Password Please Try Again");
              printf("\n\n");
              goto q;
             }
               else
               goto l3;
               l3: printf("\n\t");
               printf("Access Granted\n");
               printf("\n\n");
               printf("\t");
               printf("****************************");
               printf("\n");
               printf("\t");
               printf("Please Select an Option: ");
               printf("\n");
               printf("\t");
               printf("****************************");
               printf("\n");
		       printf("\t01.CREATE");
		       printf("\n\t");
		       printf("02.DELETE/MODIFY");
		       printf("\n\t");
		       printf("03.DISPLAY");
		       printf("\n\t");
		       printf("04.MAIN MENU");
		       printf("\n");
		       printf("\n");
		       printf("\t");
		       printf("Please Enter an Option: ");
		        scanf("%d",&y);
		        switch(y)
		        {
        			case 1:create();
        			      goto q;
  			      case 2:edit();
  			             goto q;
                  case 3:display();
                         goto q;
                  case 4: goto q;
                  default : printf("error\n");
				  goto q;
        		}
		         break;

       case 2:
		         break;
      case 3: printf("\tExiting...\n");
      break;
      default : printf("error\n");
      break;
	}
}
