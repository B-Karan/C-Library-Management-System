#include<stdio.h>
#include<ctype.h>
#include<conio.h>
#include<string.h>
#include<stdlib.h>
#include "funcs.h"
#define clear system("cls");
int main()
{
	mainMenu();
	char c=tolower(getch());
	switch(c)
	{
		case 'f':{
			clear
			user a=login();
			user b;
			FILE *fptr;
			if((fptr=fopen("data.txt","r"))!=NULL)
			{
				fread(&b,sizeof(user),1,fptr);
				if(check(a,b))
				{
					printf("Access Successfull!\n");
					printf("Press 'ENTER' to Continue......");
					getchar();
					system("cls");
					printf("\t\t>>Press 'A' to add Books\n");
					printf("\t\t>>Press 'S' to Search Books\n");
					char b=tolower(getch());
					switch(b)
					{
						case 'a':{
							clear
							char res;
							do{
								book book1=read();
							    FILE *fbook=fopen("book.txt","a");
							    if(fbook!=NULL)
							    {
							     	if((fwrite(&book1,sizeof(book),1,fbook))!=NULL)
								    printf("Book Added Successfully.\nDo you want to add more books?[Y/N]");
								    res=tolower(getch());
								    system("cls");
							    }
							    fclose(fbook);
							}while(res=='y');
							break;
						}
						case 's':{
							char r;
							char *b_name=(char*)malloc(20),*a_name=(char*)malloc(20);
							do{
								clear
							printf("Enter Book Name :");
							scanf(" %[^\n]",b_name);
							printf("Enter Author Name :");
							scanf(" %[^\n]",a_name);
							search(b_name,a_name);
							printf("Do you want Any Other Books?[Y/N]\n");
							r=tolower(getch());
							}while(r=='y');
							free(b_name);
							free(a_name);
							break;
						}
					}
				}
				else
				{
					printf("Incorrect password/username.\n");
				}
				fclose(fptr);
			}
			break;
			}
		case 's':{
			clear
			user a=login();
			user b;
			FILE *fptr;
			if((fptr=fopen("data.txt","r"))!=NULL)
			{
				fread(&b,sizeof(user),1,fptr);
				if(check(a,b))
				{
					printf("Access Successfull!\n");
					printf("Press 'ENTER' to Continue......");
					getchar();
					system("cls");
					printf("\t\t>>Press 'B' to Borrow Books\n");
					printf("\t\t>>Press 'S' to Search Books\n");
					char b=tolower(getch());
					switch(b)
					{
						case 's':{
							char r;
							char *b_name=(char*)malloc(20),*a_name=(char*)malloc(20);
							do{
							clear
							printf("Enter Book Name :");
							scanf(" %[^\n]",b_name);
							printf("Enter Author Name :");
							scanf(" %[^\n]",a_name);
							search(b_name,a_name);
							printf("Do you want Any Other Books?[Y/N]\n");
							r=tolower(getch());
							}while(r=='y');
							free(b_name);
							free(a_name);
							break;
						}
						case 'b':{
							char resp;
							borrow *s1=(borrow*)malloc(sizeof(borrow));
							FILE *fborrow;
							if((fborrow=fopen("borrow.txt","a"))!=0)
							{
								do{
								clear
								printf("Enter Book name :");
								scanf(" %[^\n]",s1->book_name);
								printf("Enter Author Name :");
								scanf(" %[^\n]",s1->author_name);
								printf("Enter Your Name :");
								scanf(" %[^\n]",s1->stu_name);
								printf("Enter Registration Number :");
								scanf(" %d",&s1->id);
								if((fwrite(s1,sizeof(borrow),1,fborrow))!=0)
								printf("Borrow Successfull!\n");
								printf("Do you want any other book?[Y/N]\n");
								resp=tolower(getch());
							}while(resp=='y');
							}
							fclose(fborrow);
							free(s1);
							break;
						}
					}
				}
				else
				{
					printf("Incorrect password/username.\n");
				}
				fclose(fptr);
			}
			break;
		}
		case 'c':{
			clear
			user a=login();
			FILE *fp;
			if((fp=fopen("data.txt","w"))==NULL)
			{
				printf("Unable to create file.");
				exit(0);
			}
			if((fwrite(&a,sizeof(user),1,fp))!=NULL)
			printf("Account Created Succesfully!");
			fclose(fp);
			break;
		}
		default:{
			printf("InValid choice.");
			break;
		}
    }
return 0;;
}
