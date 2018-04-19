#include<stdio.h>                   
#include<conio.h>                   
#include <stdlib.h>







void mainmenu(void);
void addbooks(void);
void deletebooks(void);
void searchbooks(void);
void viewbooks(void);
void editbooks(void);
void Password(void);



char findbook;
int selection;
char catagories[][50]={"Introduction to Computer Science","Electronics","English","Urdu","Calculus","Statistics"};

struct books
{
    int id;
    char stname[100];
    char name[100];
    char Author[100];
    int quantity;
    float Price;
    int count;
    int rackno;
    char *cat;

};
struct books a;
FILE *fp,*ft;

void main() {

   Password();

}





void Password(){
	int pass;
  	int j;
    for(j=0;j<20;j++)
    {
     printf("*");
    }
	
	printf("Password Protected");
   
   for(j=0;j<20;j++)
   {
     printf("*");
   }
   printf("\n");
   printf("Enter Password:");
    scanf("%d",&pass);
    if(pass==12345){
     
	 printf("Password Match !\n")	;
	 printf("Press any key to continue.....");
     getch();
     mainmenu();

    	
	}
    
   
   else{
   	
   	printf("Incorrect Password !");
   	system("cls");
   	Password();
   }
 
}








void mainmenu(){
	
 system("cls");
       //   textbackground(13);
    int i;
   
    printf("\t\t\t\t\t\t\"MAIN MENU\"\n\n");
      
    printf("1. Add Books\n");
   
    printf("2. Delete books\n");
   
    printf("3. Search Books\n");
      
    printf("4. View Book list\n");
   
    printf("5. Edit Book's Record\n");
   
    printf("6. Close Software\n");
   
   	printf("Enter your choice:");
  
   
   switch(getch())
    {
    case '1':
    	system("cls");
      	addbooks();
      	
	 
        break;
    case '2':
    	system("cls");
    	deletebooks();
        break;
    case '3':
		system("cls");
		searchbooks();
        break;
	case '4':
		system("cls");
    	viewbooks();
        break;
    case '5':
    	system("cls");
		editbooks();
        break;
	case '6':
        {
        system("cls");
        printf("Thanks for using the Software.\n");
        printf("Developed By :\n");
        printf("1.Asad Jivani\n");
        printf("2.Omar Faheem\n");
        printf("3.Khawaja Muhammad Abeer\n");
        exit(0);
        }
    default:
        {
        printf("Wrong Entry!! Please re-entered correct option: ");
        if(getch())
        mainmenu();
        }
 
    }
   
   
  }
  
  
 void addbooks(void)    
{

	    
    printf("\t\t\t\t\"SELECT CATEGORIES\"\n\n");
    
    
    printf("1. Introduction to Computer Science\n");
    
    printf("2. Electronics\n");
    
    printf("3. English\n");
    
    printf("4. Urdu\n");
    
    printf("5. Calculus\n");
    
    printf("6. Statistics\n");
    
    printf("7. Back to main menu\n");
    
    printf("Enter your choice:");
    scanf("%d",&selection);
    if(selection==7)
    mainmenu() ;
    system("cls");
//process of saving  
    fp=fopen("Books_Records.dat","ab+");
	if(getdata()==1){
    a.cat=catagories[selection-1];
	fseek(fp,0,SEEK_END);
	
	fwrite(&a,sizeof(a),1,fp);
	fclose(fp);
	printf("The record is sucessfully saved\n");
    printf("Do you want to save more?(1 / 0):");
    int opt;
    scanf("%d",&opt);
    if(opt==1){
	
      system("cls");	
      addbooks();
  }
    else if(opt==0){
	
       system("cls");
       mainmenu();
}
}
}
int checkid(int id)  //check whether the book is exist in library or not
{
	rewind(fp); //bilkul start
	while(fread(&a,sizeof(a),1,fp)==1)
	if(a.id==id)
	return 0;  //returns 0 if book exits
      return 1; //return 1 if it not
}

int getdata()
{
	int id;
	printf("Enter the Information Below");
	
	
	
	printf("\nCategory:  ");
	printf("%s\n",catagories[selection-1]);
	printf("Book ID:");
	scanf("%d",&id);
	if(checkid(id) == 0)
	{
		
		printf("\aThe book id already exists\a");
		getch();
		mainmenu();
		return 0;
	}
	a.id=id;
	printf("Book Name:");
	scanf("%s",a.name);
	printf("Author:");
	scanf("%s",a.Author);
	printf("Quantity:");
	scanf("%d",&a.quantity);
	printf("Price:");
	scanf("%f",&a.Price);
	printf("Rack No:");
	scanf("%d",&a.rackno);
	return 1;
}
void searchbooks(){
	
    printf("\t\t\t\t\"SEARCH BOOKS\"\n\n");
    int id;
    printf("Enter ID of Book:");
   	scanf("%d",&id); 
    fp=fopen("Books_Records.dat","rb+"); //open file for reading propose
    rewind(fp);
 	while(fread(&a,sizeof(a),1,fp)==1)
	    {
		if(a.id==id)
		{
		    
		    printf("The Book is available");
		    printf("\nID:%d",a.id);
			printf("\nName:%s",a.name);
		    printf("\nAuthor:%s ",a.Author);
		    printf("\nQantity:%d ",a.quantity);
		    printf("\nPrice:Rs.%.2f",a.Price);
		    printf("\nRack No:%d ",a.rackno); 
		    findbook='F';
		}

	    }
	   if(findbook!='F')  //checks whether conditiion enters inside loop or not
	    {
	    
	    printf("\nNo Record Found !");
	    }
	    printf("\nTry another search?(1/0): ");
	    int opt;
	    scanf("%d",&opt);
	    if(opt==1)
	    searchbooks();
	    else{
	    mainmenu();
		}
	    
	}
	
	
void deletebooks()    //function that delete items from file fp
{
	
	

    system("cls");
    int id;
    char another='y';
    while(another=='y')  //infinite loop
    {
	system("cls");
	
	printf("Enter the Book ID to  delete:");
	scanf("%d",&id);
	fp=fopen("Books_Records.dat","rb+");
	rewind(fp);
	while(fread(&a,sizeof(a),1,fp)==1)
	{
	    if(a.id==id)
	    {

		
		printf("This book record is available\n");
		
		printf("Book name is %s",a.name);
		
		printf("\nRack No. is %d",a.rackno);
		findbook='t';
	    }
	}
	if(findbook!='t')
	{
	    
	    printf("\nNo record is found modify the search");
	    if(getch())
	    mainmenu();
	}
	if(findbook=='t' )
	{
	    
	    printf("\nDo you want to delete it?(Y/N):");
	    if(getch()=='y')
	    {
	    	
		ft=fopen("test.dat","wb+");  //temporary file for delete
		rewind(fp);
		while(fread(&a,sizeof(a),1,fp)==1)
		{
		    if(a.id != id)
		    {
			fseek(ft,0,SEEK_CUR);
			fwrite(&a,sizeof(a),1,ft); //write all in tempory file except that
		    }                              //we want to delete
		}
		fflush(ft);
		fflush(fp);
		fclose(ft);
		fclose(fp);
		remove("Books_Records.dat");
		rename("test.dat","Books_Records.dat"); //copy all item from temporary file to fp except that
	
		if(findbook=='t')
		{
		   
		    printf("\nThe record is sucessfully deleted\n");
		   
		    printf("\nDelete another record?(Y/N):");
		}
	    }
	else
	mainmenu();
	fflush(ft);
	fflush(fp);
	
	
	fflush(stdin);
	another=getch();
	}
	}
    mainmenu();
}


  
void viewbooks(){
	
	
	int i=0;
    system("cls");
    printf("\t\t\t\t\"BOOKS LIST\"\n\n");
    fp=fopen("Books_Records.dat","rb");
    while(fread(&a,sizeof(a),1,fp)==1)
    {
	i++;
	printf("CATEGORY: %s\n",a.cat);
	
	printf("ID: %d\n",a.id);
	
	printf("BOOK NAME: %s\n",a.name);
	
	printf("AUTHOR: %s\n",a.Author);
	
	printf("QTY: %d\n",a.quantity);
	
	printf("PRICE: %.2f\n",a.Price);
	
	printf("RackNo: %d\n",a.rackno);
	printf("\n\n");
	
      }
      
    printf("Total Books= %d",i);
    fclose(fp);
    if(getch()) 
    mainmenu();
    
    
      
}
void editbooks(void)  //edit information about book
{
	system("cls");
	int flag=0;
	int id,e;
	
	
	printf("\t\t\t\t\"EDIT BOOKS DATA\"\n\n");
	char another='y';
	while(another=='y')
	{
		system("cls");
		printf("Enter Book Id to be edited:");
		scanf("%d",&id);
		fp=fopen("Books_Records.dat","rb+");
		while(fread(&a,sizeof(a),1,fp)==1)
		{
			if(checkid(id)==0)
			{
				
				printf("This book is availble\n");
				printf("The Book ID:%d",a.id);
				printf("\nEnter new name:");
				scanf("%s",a.name);
				printf("\nEnter new Author:");
				scanf("%s",a.Author);
				printf("\nEnter new quantity:");
				scanf("%d",&a.quantity);
				printf("\nEnter new price:");
				scanf("%f",&a.Price);
				printf("\nEnter new rackno:");
				scanf("%d",&a.rackno);
				printf("\nThis record is modified");
				fseek(fp,ftell(fp)-sizeof(a),0);
				fwrite(&a,sizeof(a),1,fp);
				fclose(fp);
				flag=1;
			}
			if(flag==0)
			{
				
				printf("\nNo record found !");
			}
		}
		printf("\nModify another Record?(Y/N)");
		fflush(stdin);
		another=getch() ;
	   

	}
	 if(getch()) 
        mainmenu();

}
