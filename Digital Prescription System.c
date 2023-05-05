#include <windows.h>
#include<stdio.h>
#include<string.h>
#include<time.h>

#define RETURNTIME 15

COORD coord = {0, 0}; // sets coordinates to 0,0
COORD max_res,cursor_size;
void gotoxy (int x, int y)
{
    coord.X = x;
    coord.Y = y; // X and Y coordinates
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void delay(unsigned int mseconds)
{
    clock_t goal = mseconds + clock();
    while (goal > clock());
}

struct meroDate
{
    int mm,dd,yy;
};

int t(void) //for time
{
    time_t t;
    time(&t);
    printf("Date and time:%s\n",ctime(&t));
    return 0 ;
}

int main()
{
    system("color F9");
    gotoxy(40,5);
    printf("Software Development Capstone Project");
    gotoxy(45,7);
    printf("Digital Prescription System");
    gotoxy(46,9);
    printf("Developed by Utsab Sarkar");
    gotoxy(52,10);
    printf("ID : 221-35-976");
    gotoxy(42,11);
    printf("Daffodil International University");
    gotoxy(47,15);
    printf("Press ANY to Continue");
    getch();
    homepage();
    getch();
    return 0;
}

void homepage();
void homepage(void)
{
    system("cls");
    system("color F1");
    gotoxy(36,1);
    printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
    printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
    gotoxy(38,2);
    printf("How do you want to use this application???");
    gotoxy(50,5);
    printf("1. As a Doctor.");
    gotoxy(50,7);
    printf("2. As a Patient.");
    gotoxy(45,12);
    printf("Press '0'(zero) to END.");
    gotoxy(35,14);
    printf("----------------------------------------");
    gotoxy(35,15);
    printf("Enter your choice:");
    switch(getch())
    {
    case '1':
        Password();
        break;
    case '2':
        searchmedi();
        break;
    case '0':
        stop();
        break;
    }
}

char password[10]= {"admin"};

void Password();
void Password(void) //for password option
{
    system("cls");
    gotoxy(40,3);
    printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 LOG IN PANEL");
    printf(" \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
    char d[25]=" Password Protected";
    char ch,pass[10];
    int i=0,j;

    gotoxy(32,5);
    for(j=0; j<20; j++)
    {
        delay(50);
        printf("*");
    }
    for(j=0; j<20; j++)
    {
        delay(50);
        printf("%c",d[j]);
    }
    for(j=0; j<20; j++)
    {
        delay(50);
        printf("*");
    }
    gotoxy(50,10);
    printf("Enter Password:");

    while(ch!=13)
    {
        ch=getch();

        if(ch!=13 && ch!=8)
        {
            putch('*');
            pass[i] = ch;
            i++;
        }
    }
    pass[i] = '\0';
    if(strcmp(pass,password)==0)
    {
        gotoxy(50,12);
        printf("Password match");
        gotoxy(45,13);
        printf("Press any key to countinue.....");
        getch();
        mainmenu();
    }
    else
    {
        gotoxy(45,12);
        printf("\aWarning!! Incorrect Password");
        getch();
        Password();
    }
}

void mainmenu(void);
void mainmenu()
{

    system("cls");
    system("color F3");
    int i;
    gotoxy(40,3);
    printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 MAIN MENU");
    printf(" \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
    gotoxy(40,5);
    printf("\xDB\xDB\xDB\xDB\xB2 1. Add Patient Medicine");
    gotoxy(40,7);
    printf("\xDB\xDB\xDB\xDB\xB2 2. Delete Patient ID");
    gotoxy(40,9);
    printf("\xDB\xDB\xDB\xDB\xB2 3. Search Patient Medicine");
    gotoxy(40,11);
    printf("\xDB\xDB\xDB\xDB\xB2 4. View all Patient Medicine");
    gotoxy(40,13);
    printf("\xDB\xDB\xDB\xDB\xB2 5. Edit Patient Medicine");
    gotoxy(40,15);
    printf("\xDB\xDB\xDB\xDB\xB2 6. Back to Homepage");
    gotoxy(40,19);
    printf("------------------------------------------");
    gotoxy(20,20);
    t();
    gotoxy(20,21);
    printf("Enter your choice:");
    switch(getch())
    {
    case '1':
        addmedi();
        break;
    case '2':
        deletemedi();
        break;
    case '3':
        searchmedi();
        break;
    case '4':
        viewmedi();
        break;
    case '5':
        editmedi();
        break;
    case '6':
        homepage();
        break;
    default:
    {
        gotoxy(10,23);
        printf("\aWrong Entry!!Please re-entered correct option");
        if(getch())
            mainmenu();
    }
    }
}

FILE *fp,*ft,*fs;
int s;

char catagories[][25]= {"Fever","Cold and Flu","Allergies","Headaches","Stomach Aches","Cancer"};

struct patient
{
    int id;
    char patname[20];
    char mediname[20];
    char takentime[20];
    int dosages;
    int count;
    int duration;
    char *cat;
    int age;
};
struct patient a;

void addmedi(void);
void addmedi(void)    //funtion that add books
{
    system("cls");
    int i;
    gotoxy(40,5);
    printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2SELECT CATEGOIES");
    printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
    gotoxy(40,7);
    printf("\xDB\xDB\xDB\xDB\xB2 1. Fever");
    gotoxy(40,9);
    printf("\xDB\xDB\xDB\xDB\xB2 2. Cold and Flu");
    gotoxy(40,11);
    printf("\xDB\xDB\xDB\xDB\xB2 3. Allergies");
    gotoxy(40,13);
    printf("\xDB\xDB\xDB\xDB\xB2 4. Headaches");
    gotoxy(40,15);
    printf("\xDB\xDB\xDB\xDB\xB2 5. Stomach Aches");
    gotoxy(40,17);
    printf("\xDB\xDB\xDB\xDB\xB2 6. Cancer");
    gotoxy(40,19);
    printf("\xDB\xDB\xDB\xDB\xB2 7. Back to main menu");
    gotoxy(40,21);
    printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
    printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
    gotoxy(40,22);
    printf("Enter your choice:");
    scanf("%d",&s);
    if(s==7)
        mainmenu() ;
    system("cls");
    fp=fopen("Bibek.dat","ab+");
    if(getdata()==1)
    {
        a.cat=catagories[s-1];
        fseek(fp,0,SEEK_END);
        fwrite(&a,sizeof(a),1,fp);
        fclose(fp);
        gotoxy(41,14);
        printf("The record is sucessfully saved");
        gotoxy(41,15);
        printf("Save any more?(Y / N):");
        if(getch()=='n')
            mainmenu();
        else
            system("cls");
        addmedi();
    }
}

int getdata();
int getdata()
{
    int t;
    gotoxy(40,3);
    printf("Enter the Information Below");
    gotoxy(40,4);
    printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
    printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
    gotoxy(40,13);
    printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
    printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
    gotoxy(41,5);
    printf("Category:");
    gotoxy(55,5);
    printf("%s",catagories[s-1]);
    gotoxy(41,6);
    printf("Patient ID:\t");
    gotoxy(55,6);
    scanf("%d",&t);
    if(checkid(t) == 0)
    {
        gotoxy(21,13);
        printf("\aThe patient id already exists\a");
        getch();
        mainmenu();
        return 0;
    }
    a.id=t;
    gotoxy(41,7);
    printf("Patient Name:");
    gotoxy(55,7);
    scanf("%s",&a.patname);
    gotoxy(41,8);
    printf("Patient Age:");
    gotoxy(55,8);
    scanf("%d",&a.age);
    gotoxy(41,9);
    printf("Medicine Name:");
    gotoxy(55,9);
    scanf("%s",&a.mediname);
    gotoxy(41,10);
    printf("Dosages a day:");
    gotoxy(55,10);
    scanf("%d",&a.dosages);
    gotoxy(41,11);
    printf("Taken(B/A):");
    gotoxy(55,11);
    scanf("%s",&a.takentime);
    gotoxy(41,12);
    printf("Duration:");
    gotoxy(55,12);
    scanf("%d",&a.duration);
    return 1;
}

int checkid(int);
int checkid(int t)  //check whether the book is exist in library or not
{
    rewind(fp);
    while(fread(&a,sizeof(a),1,fp)==1)
        if(a.id==t)
            return 0;  //returns 0 if book exits
    return 1; //return 1 if it not
}

char findmedi;

void deletemedi(void);
void deletemedi(void)    //funtion that add books
{
    system("cls");
    system("color F4");
    int d;
    char another='y';
    while(another=='y')  //infinite loop
    {
        system("cls");
        gotoxy(40,3);
        printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 DELETE PATIENTS INFO");
        printf(" \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
        gotoxy(30,5);
        printf("Enter patient ID to  delete:");
        scanf("%d",&d);
        fp=fopen("Bibek.dat","rb+");
        rewind(fp);
        while(fread(&a,sizeof(a),1,fp)==1)
        {
            if(a.id==d)
            {
                gotoxy(30,7);
                printf("The patient record is available");
                gotoxy(30,8);
                printf("Patient name is %s",a.patname);
                gotoxy(30,9);
                printf("Patient age is %d",a.age);
                findmedi='t';
            }
        }
        if(findmedi!='t')
        {
            gotoxy(30,10);
            printf("No record is found modify the search");
            if(getch())
                mainmenu();
        }
        if(findmedi=='t' )
        {
            gotoxy(30,11);
            printf("Do you want to delete it?(Y/N):");
            if(getch()=='y')
            {
                ft=fopen("test.dat","wb+");  //temporary file for delete
                rewind(fp);
                while(fread(&a,sizeof(a),1,fp)==1)
                {
                    if(a.id!=d)
                    {
                        fseek(ft,0,SEEK_CUR);
                        fwrite(&a,sizeof(a),1,ft); //write all in tempory file except that
                    }                              //we want to delete
                }
                fclose(ft);
                fclose(fp);
                remove("Bibek.dat");
                rename("test.dat","Bibek.dat"); //copy all item from temporary file to fp except that
                fp=fopen("Bibek.dat","rb+");    //we want to delete
                if(findmedi=='t')
                {
                    gotoxy(30,13);
                    printf("The record is sucessfully deleted");
                    gotoxy(30,14);
                    printf("Delete another record?(Y/N)");
                }
            }
            else
                mainmenu();
            fflush(stdin);
            another=getch();
        }
    }
    gotoxy(10,15);
    mainmenu();
}

void editmedi(void);
void editmedi(void)    //funtion that add books
{
    system("cls");
    int c=0;
    int d,e;
    char another='y';
    while(another=='y')
    {
        system("cls");
        gotoxy(40,3);
        printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 EDIT PATIENTS INFO");
        printf(" \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
        gotoxy(15,6);
        printf("Enter Patient Id to be edited:");
        scanf("%d",&d);
        fp=fopen("Bibek.dat","rb+");
        while(fread(&a,sizeof(a),1,fp)==1)
        {
            if(checkid(d)==0)
            {
                gotoxy(15,7);
                printf("The patent is availble");
                gotoxy(15,8);
                printf("The patient ID:%d",a.id);
                gotoxy(15,9);
                printf("Enter new patient name:");
                scanf("%s",&a.patname);
                gotoxy(15,10);
                printf("Enter new Medicine:");
                scanf("%s",&a.mediname);
                gotoxy(15,11);
                printf("Enter new dosages:");
                scanf("%d",&a.dosages);
                gotoxy(15,12);
                printf("Enter new Time:");
                scanf("%s",&a.takentime);
                gotoxy(15,13);
                printf("Enter new Duration:");
                scanf("%d",&a.duration);
                gotoxy(15,14);
                printf("The record is modified");
                fseek(fp,ftell(fp)-sizeof(a),0);
                fwrite(&a,sizeof(a),1,fp);
                fclose(fp);
                c=1;
            }
            if(c==0)
            {
                gotoxy(15,9);
                printf("No record found");
            }
        }
        gotoxy(15,16);
        printf("Modify another Record?(Y/N)");
        fflush(stdin);
        another=getch() ;
    }
    returnfunc();
}

void searchmedi(void);
void searchmedi(void)    //funtion that add books
{
    system("cls");
    int d;
    fp=fopen("Bibek.dat","rb+"); //open file for reading propose
    rewind(fp);   //move pointer at the begining of file
    gotoxy(40,3);
    printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 SEARCH PATIENT");
    printf(" \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
    gotoxy(40,5);
    printf("Enter Patient's Phone number:");
    scanf("%d",&d);
    gotoxy(40,7);
    printf("Searching........");
    while(fread(&a,sizeof(a),1,fp)==1)
    {
        if(a.id==d)
        {
            delay(2);
            system("cls");
            gotoxy(38,3);
            printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 PATIENT PRESCRIPTION");
            printf(" \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
            gotoxy(22,4);
            printf("CATEGORY:");
            gotoxy(22,5);
            printf("PATIENT NAME:");
            gotoxy(22,6);
            printf("AGE:");
            gotoxy(22,7);
            printf("PHONE NUMBER:");
            gotoxy(23,10);
            printf("NAME OF MEDICINE      DOSAGES      BEFORE/AFTER FOOD      DURATION");
            gotoxy(40,4);
            printf("%s",a.cat);
            gotoxy(40,5);
            printf("%s",a.patname);
            gotoxy(40,6);
            printf("%d",a.age);
            gotoxy(40,7);
            printf("%d",a.id);
            gotoxy(24,11);
            printf("%s",a.mediname);
            gotoxy(50,11);
            printf("%d",a.dosages);
            gotoxy(65,11);
            printf("%s",a.takentime);
            gotoxy(85,11);
            printf("%d",a.duration);
            findmedi='t';
        }
        fclose(fp);
    }
    if(findmedi!='t')  //checks whether conditiion enters inside loop or not
    {
        gotoxy(40,8);
        printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
        gotoxy(40,9);
        printf("\xB2");
        gotoxy(58,9);
        printf("\xB2");
        gotoxy(40,10);
        printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
        gotoxy(42,9);
        printf("\aNo Record Found");
    }
    gotoxy(40,17);
    printf("Try another search?(Y/N)");
    if(getch()=='y')
        searchmedi();
    else
        homepage();
    fclose(fp);
}

void viewmedi(void);
void viewmedi(void)    //funtion that add books
{
    int i=0,j;
    system("cls");
    gotoxy(20,1);
            printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 ALL PATIENT PRESCRIPTION INFO");
            printf(" \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
    gotoxy(2,2);
    printf("CATEGORY      PATIENT NAME     ID      AGE      MEDICINE      DOSAGES     TIME     DAYS ");
    j=4;
    fp=fopen("Bibek.dat","rb");
    while(fread(&a,sizeof(a),1,fp)==1)
    {
        gotoxy(3,j);
        printf("%s",a.cat);
        gotoxy(18,j);
        printf("%s",a.patname);
        gotoxy(33,j);
        printf("%d",a.id);
        gotoxy(41,j);
        printf("%d",a.age);
        gotoxy(50,j);
        printf("%s",a.mediname);
        gotoxy(66,j);
        printf("%d",a.dosages);
        gotoxy(75,j);
        printf("%s",a.takentime);
        gotoxy(85,j);
        printf("%d",a.duration);
        printf("\n\n");
        j++;
    }
    fclose(fp);
    gotoxy(35,25);
    returnfunc();
}

void returnfunc(void);
void returnfunc(void)
{
    {
        printf(" Press ENTER to return to main menu");
    }
a:
    if(getch()==13) //allow only use of enter
        mainmenu();
    else
        goto a;
}

void stop();
void stop(void)
{
    system("cls");
    gotoxy(36,3);
    printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 CLOSE APPLICATION");
    printf(" \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
    gotoxy(40,6);
    printf("Digital Prescription System");
    gotoxy(36,8);
    printf("******************************************");
    gotoxy(36,10);
    printf("******************************************");
    gotoxy(36,11);
    printf("******************************************");
    gotoxy(36,13);
    printf("******************************************");
    gotoxy(30,17);
    printf("Exiting in 3 second...........>");
    Sleep(3000);
    exit(0);
}
