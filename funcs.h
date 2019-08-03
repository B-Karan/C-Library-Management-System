void mainMenu(void)
{
	printf("\t\t\t----------WELCOME TO LIBRARY----------\n");
	printf("\t\t\t--------------------------------------\n\n");
	printf("\t\t\t>>Enter 'S' for Student  log In\n");
	printf("\t\t\t>>Enter 'F' for Faculty  log In\n");
	printf("\t\t\t>>Enter 'C' to Sign Up\n");
}
typedef struct{  //login struct
	char username[15];
	unsigned int psw;
}user;
user login(void)
{
	user a;
	printf("Enter Username :");
	scanf(" %s",a.username);
	printf("Enter password :");
	scanf(" %u",&a.psw);
	return a;
}
int check(user x,user y)
{
	if((!strcmp(x.username,y.username)&&(x.psw==y.psw)))
	return 1;
	else
	return 0;
}
typedef struct{   //book struct
	char title[25];
	char author[25];
	char publi[25];
	int stock;
}book;
book read(void)
{
	book a;
	printf("Enter Book's Title :");
	scanf(" %[^\n]",a.title);
	printf("Enter Book's Author :");
	scanf(" %[^\n]",a.author);
	printf("Enter Book's Publication :");
	scanf(" %[^\n]",a.publi);
	printf("Enter Quantity :");
	scanf(" %d",&a.stock);
	return a;
}
void search(char *b_name,char *a_name)
{
	FILE *fp1;
	if((fp1=fopen("book.txt","r"))==0)
	{
		printf("Unable to open file!");
		exit(0);
	}
	int i=0;
	book tem;
	rewind(fp1);
	while(!feof(fp1))
	{
		fread(&tem,sizeof(book),1,fp1);
		if((!strcmp(b_name,tem.title)&&(!strcmp(a_name,tem.author))))
		{
			printf("Title :%s\nAuthor :%s\nPublication :%s\nQuantity :%d\n",tem.title,tem.author,tem.publi,tem.stock);
			break;
		}
		else
		i=1;
		
	}
	if(i==1)
	{
		printf("Book Not Available.\n");
	}
}
typedef struct{
	char book_name[20];
	char author_name[20];
	char stu_name[20];
	int id;
}borrow;
