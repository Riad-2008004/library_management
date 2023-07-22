#include <stdio.h>
#include <conio.h>
#include <string.h>
#define FILE_NAME "library.txt"

typedef struct
{
    unsigned int books_id; 
    char bookName[50];
    char authorName[50];
    int bookId;
} s_BooksInfo;

viewBooks()
{
    char ch[99];
    FILE *ruet = NULL;
    int status = 0;
    ruet = fopen(FILE_NAME,"r");
    if(ruet == NULL)
    {
        printf("File is not opened\n");
    }
    headMessage("AVAILABLE BOOKS\n");
    while (!feof(ruet))
    {
        int i=1;
        fgets(ch,99,ruet);
        printf("\n\t\t\t %s",ch);
        i++;
    }
    fclose(ruet);
    printf("\n\n\n\t\t\t Enter any key to continue.....\n\n");
    getch();
    
}
void addBookInDataBase()
{
    char studentsinput[30];
    FILE *ruet = NULL;
    int status = 0;
    ruet = fopen(FILE_NAME,"a");
    if(ruet == NULL)
    {
        printf("File is not opened\n");
    }
    else{
    headMessage("ADD NEW BOOKS");
    printf("\n\n\t\t\tENTER YOUR DETAILS BELOW:");
    printf("\n\t\t\t---------------------------------------------------------------------------\n"); 
    fflush(stdin);
    printf("\n\t\t\tBook ID NO  = ");
    gets(studentsinput);
    fprintf(ruet," Book ID= %s",studentsinput);
    printf("\n\t\t\tBook Name  = ");
    gets(studentsinput);
    fprintf(ruet,"    Book Name= %s\n",studentsinput);
    fclose(ruet);
    printf("\n\t\t\tThanks!! Your Inputs are saved\n\n");
    }
}
void printMessageCenter(const char* message)
{
    int len =0;
    int pos = 0;
    len = (78 - strlen(message))/2;
    printf("\t\t\t");
    for(pos =0 ; pos < len ; pos++)
    {
        printf(" ");
    }
    printf("%s",message);
}
void headMessage(const char *message)
{
    //system("cls");
    printf("\t\t\t###########################################################################");
    printf("\n\t\t\t############                                                   ############");
    printf("\n\t\t\t############  Rajshahi University of Engineering & Technology  ############");
    printf("\n\t\t\t############                                                   ############");
    printf("\n\t\t\t###########################################################################");
    printf("\n\t\t\t---------------------------------------------------------------------------\n");
    printMessageCenter(message);
    printf("\n\t\t\t----------------------------------------------------------------------------");
}
void menu()
{
    int choice = 0;
    do
    {
        headMessage("MAIN MENU");
        printf("\n\n\n\t\t\t1.Add Books");
        printf("\n\t\t\t2.Search Books (BY ID)");
        printf("\n\t\t\t3.View Books");
        printf("\n\t\t\t4.Delete Book");
        printf("\n\t\t\t5.Update Password");
        printf("\n\t\t\t0.Exit");
        printf("\n\n\n\t\t\tEnter choice => ");
        scanf("%d",&choice);
        switch(choice)
        {
        case 1:
            addBookInDataBase();
            break;
        case 2:
            //searchBooks();
            break;
        case 3:
            viewBooks();
            break;
        case 4:
            //deleteBooks();
            break;
        case 0:
            printf("\n\n\n\t\t\t\tThank you!!!\n\n\n\n\n");
            while (1)
            { 
            }
            break;
        default:
            printf("\n\n\n\t\t\tINVALID INPUT!!! Try again...");
        }                                            
    }
    while(choice!=0);                                        
}
void login()
{
    unsigned char userName[30] = {0};
    unsigned char password[30] = {0};
    FILE *ruet = NULL;
    int L =0;
    headMessage("Login");
    ruet = fopen(FILE_NAME,"rb");
    if(ruet == NULL)
    {
        printf("File is not opened\n");
    }
    fclose(ruet);
    do
    {
        printf("\n\n\n\t\t\t\tUsername:");
        gets(userName);
        printf("\n\t\t\t\tPassword:");
        gets(password);
        if((strcmp(userName,"Riad2008004\0")==0) && (strcmp(password,"2008004\0")==0))
        {
            menu();
        }
        else
        {
            printf("\n\n");
            printf("\t\t\t\tLogin Failed Enter Again Username & Password\n\n");
            L++;
        }
    }
    while(L<=3);
    if(L>3)
    {
        headMessage("Login Failed\n");
        printf("\t\t\t\tSorry,Unknown User.");
        getch();
    }
}
void welcomeMessage()
{
    headMessage("Project By: Ariful Islam Riad");
    printf("\n\n\n\n\n");
    printf("\n\t\t                                  *------------------*\n");
    printf("\n\t\t                   =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=");
    printf("\n\t\t                   =                 WELCOME                   =");
    printf("\n\t\t                   =                   TO                      =");
    printf("\n\t\t                   =             AUTOMETIC LIBRARY             =");
    printf("\n\t\t                   =                  RUET                     =");
    printf("\n\t\t                   =           By:Department of MTE            =");
    printf("\n\t\t                   =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=");
    printf("\n\t\t                                  *------------------*\n");
    printf("\n\n\n\t\t\t Enter any key to continue.....\n\n");
    getch();
}
int main()
{
    welcomeMessage();
    login();
    return 0;
}