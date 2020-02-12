#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    char pass[10],usn[10],ch;
    int i;
    printf("\nEnter your USN:\t");
    gets(usn);
    printf("\nEnter your password(eight characters only):");
    for(i=0;i<8;i++){
        ch = getch();
        pass[i] = ch;
        ch = '*';
        printf("%c",ch);
    }
    pass[i] = NULL;

    printf("\n\nlogin successful :)");
    int choice;
    do{
    printf("\n\nyour attendance system.\nwhat do you want to do?\n");
    printf("1.mark my attendance\n");
    printf("2.view attendance\n");
    printf("3.check eligibility\n");
    printf("\n\n\nenter your choice:");
    scanf("%d",&choice);

    switch(choice){
    case 1: mark();
            break;
    case 2: view();
            break;
    case 3: check();
            break;
    default:exit(0);

    }
    }while(choice<=3);
    return 0;
}


void mark()
{
    int c;
    do{
    printf("\n1.software engineering\n");
    printf("2.data structures\n");
    printf("3.discrete mathematics\n");
    printf("4.computer organization\n");
    printf("5.analog and digital electronics\n");
    printf("6.engineering mathematics\n");

    printf("which subject did you just attend?(enter the number)\n");
    scanf("%d",&c);

    switch(c){
        case 1: se();
                break;
        case 2: //ds();
                break;
        case 3: //dms();
                break;
        case 4: //co();
                break;
        case 5: //ade();
                break;
        case 6: //em();
                break;
        default:exit(0);
    }
    }while(c<=6);
}
void se(){
    FILE *fp;
    time_t t;
    time(&t);
    int countday = 0;
    int countse = 0;
    int n;
    char a[2];
    fp = fopen("se.txt","a+");
    printf("enter the day:");
    scanf("%d",&countday);
    printf("\npress (1) if you are present or (0) if you did not attend\n\n");
    scanf("%d",&n);

    switch(n){

    case 1: printf("good job. attendance has been updated\n");

            fprintf(fp,"%s---->P\n",ctime(&t));
            getch();
            countse+=1;
            break;

    case 0: printf("not a good job. attendance has been updated\n");
            fprintf(fp,"\n%s---->ab\n",ctime(&t));

    default:exit(0);
    }


}
void view()
{
    int c;

    printf("\n1.software engineering\n");
    printf("2.data structures\n");
    printf("3.discrete mathematics\n");
    printf("4.computer organization\n");
    printf("5.analog and digital electronics\n");
    printf("6.engineering mathematics\n");

    printf("which subject's attendance do you want to view?(enter the number)\n");
    scanf("%d",&c);

    switch(c){
        case 1: sev();
                break;
        case 2: //ds();
                break;
        case 3: //dms();
                break;
        case 4: //co();
                break;
        case 5: //ade();
                break;
        case 6: //em();
                break;
        default:exit(0);
    }
}
void sev(){
    char c;
    FILE *fp;
    fp = fopen("se.txt","r");
    c = fgetc(fp);
    while (c != EOF)
    {
        printf ("%c", c);
        c = fgetc(fp);
    }

    fclose(fp);

}

void check()
{
  int c;

    printf("\n1.software engineering\n");
    printf("2.data structures\n");
    printf("3.discrete mathematics\n");
    printf("4.computer organization\n");
    printf("5.analog and digital electronics\n");
    printf("6.engineering mathematics\n");

    printf("which subject do you want to check eligibility?(enter the number)\n");
    scanf("%d",&c);

    switch(c){
        case 1: checkse();
                break;
        case 2: //ds();
                break;
        case 3: //dms();
                break;
        case 4: //co();
                break;
        case 5: //ade();
                break;
        case 6: //em();
                break;
        default:exit(0);
    }
}
void checkse(int countday,int countse)
{
    int TotalClasses = 30;
    float res;
    printf("total number of classes attended = %d\n\n",countse);

    res = (countday/TotalClasses)*100;

    if(res<=75){
        printf("%f --- not eligible\n",res);
    }
    else{
        printf("%f --- eligible\n",res);
    }

}
