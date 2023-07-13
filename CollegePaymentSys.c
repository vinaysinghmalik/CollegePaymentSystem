#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <math.h>
#define N 100
char usname[20]="admin";
char pwd[20]="**";
int I=0,mcse=0,mit=0,mae=0,mce=0,meee=0,mece=0,mme=0;
struct s1{
    char name[20];
    char dob[20];
    int ten;
    int twe;
    int sem;
    int year_of_joining;
    char branch[50];
    int fees;
    int year;
    int check[4];
    double phno;
    int reg;
    int dues[4];
    char dates[20][4];
}arr[N];

void add(){
    int c;
    printf("\nEnter Name :");
    scanf("%s",&arr[I].name);
    printf("Enter Date Of Birth (dd-mm-yyyy) :");
    scanf("%s",&arr[I].dob);
    printf("Enter 10th Percentage :");
    scanf("%d",&arr[I].ten);
    printf("Enter 12th Percentage :");
    scanf("%d",&arr[I].twe);
    Q:
    printf("\nBRANCH :  FEES/YEAR\n");
    printf("1. CSE :   200000\n");
    printf("2. IT  :   180000\n");
    printf("3. AE  :   170000\n");
    printf("4. ME  :   160000\n");
    printf("5. ECE :   160000\n");
    printf("6. EEE :   160000\n");
    printf("7. CE  :   140000\n\n");
    printf("Enter Your Choice :");
    scanf("%d",&c);
    switch(c){
        case 1:
        strcpy(arr[I].branch,"Computer Science and Engineering");
        arr[I].fees=200000;
        break;
        
        case 2:
        strcpy(arr[I].branch,"Information Technology");
        arr[I].fees=180000;
        break;
        
        case 3:
        strcpy(arr[I].branch,"Aeronautical Engineering");
        arr[I].fees=170000;
        break;
        
        case 4:
        strcpy(arr[I].branch,"Mechanical Engineering ");
        arr[I].fees=140000;
        break;
        
        case 5:
        strcpy(arr[I].branch,"Electrical and Communication Engineering");
        arr[I].fees=140000;
        break;
        
        case 6:
        strcpy(arr[I].branch,"Electrical and Electronics Engineering");
        arr[I].fees=160000;
        break;
        
        case 7:
        strcpy(arr[I].branch,"Civil Engineering");
        arr[I].fees=140000;
        break;
        
        default:
        printf("\nINVALID CHOICE\n\n");
        goto Q;
        break;
    }
    printf("Enter Year Of Joining :");
    scanf("%d",&arr[I].year_of_joining);
    printf("Enter Contact Number :");
    scanf("%lf",&arr[I].phno);
    arr[I].sem=1;
    arr[I].year=1;
    arr[I].reg=I;
    printf("\n\nYOUR REGISTRATION NUMBER IS %d\n",arr[I].reg);
    I++;
}

void aview(){
    for(int i=0; i<I; i++){
        printf("\nSTUDENT %d DETAILS:-\n\n",i+1);
        printf("Name :%s\n",arr[i].name);
        printf("Registerion Number :%d\n",arr[i].reg);
        printf("Date Of Birth :%s\n",arr[i].dob);
        printf("Year Of Joining :%d\n",arr[i].year_of_joining);
        printf("Branch :%s\n",arr[i].branch);
        printf("Current Acedemic Semester :%d\n",arr[i].sem);
        printf("Current Acedamic Year :%d\n",arr[i].year);
        printf("10th Percentage :%d %\n",arr[i].ten);
        printf("12th Percentage :%d %\n",arr[i].twe);
        printf("Contact Number :%10.0lf\n",arr[i].phno);
        printf("\nFees Paid For The Following Years :-\n");
        for(int k=0; k<4; k++){
            if(arr[i].check[k]==1){
                printf("Year :%d -> PAID\n",arr[i].year_of_joining+k);
            }
            else{
                printf("Year :%d -> PENDING\n",arr[i].year_of_joining+k);
            }
        }
    }
}

int nview(){
    char nm[20];
    int r;
    printf("Enter Student Name :");
    scanf("%s",&nm);
    printf("Enter Registerion Number :");
    scanf("%d",&r);
    for(int i=0; i<I; i++){
        if(!strcmp(nm,arr[i].name) && r==arr[i].reg){
            printf("Name :%s\n",arr[i].name);
            printf("Registerion Number :%d\n",arr[i].reg);
            printf("Date Of Birth :%s\n",arr[i].dob);
            printf("Year Of Joining :%d\n",arr[i].year_of_joining);
            printf("Branch :%s",arr[i].branch);
            printf("Current Semester :%d\n",arr[i].sem);
            printf("Current Year :%d\n",arr[i].year);
            printf("10th Percentage :%d %\n",arr[i].ten);
            printf("12th Percentage :%d %\n",arr[i].twe);
            printf("Contact Number :%10.0lf\n",arr[i].phno);
            printf("\nFees Paid For The Following Years :-\n");
            for(int k=0; k<4; k++){
                if(arr[i].check[k]==1){
                    printf("Year :%d -> PAID\n",arr[i].year_of_joining+k);
                }
                else{
                    printf("Year :%d -> PENDING\n",arr[i].year_of_joining+k);
                }
            }
            return 0;
        }
    }
    printf("\nSTUDENT NOT FOUND !!\n");
    return 0;
}

void money(){
    printf("BRANCH   : INCOME EARNED\n");
    printf(" CSE     : %d\n",mcse);
    printf(" IT      : %d\n",mit);
    printf(" AE      : %d\n",mae);
    printf(" ME      : %d\n",mme);
    printf(" ECE     : %d\n",mece);
    printf(" EEE     : %d\n",meee);
    printf(" CE      : %d\n\n",mce);
    
}
int date(int d,int m,int y,int i){
    int y1,d1,m1,days=0;
    y1=arr[i].year_of_joining+arr[i].year-1;
    d1=15;
    m1=5;
    if(d>d1 && m>=m1 && y>=y1){
        days+=(m-m1)*30;
        days+=d-d1;
        if(y-y1>1 || days>=50){
            return 25000;
        }
        else{
            return days*500;
        }
    }
    else{
        return 0;
    }
    
}

int fpay(){
    char nm[20];
    int d,m,y,due,c,s,r;
    printf("Enter Student Name :");
    scanf("%s",&nm);
    printf("Enter Registerion Number :");
    scanf("%d",&r);
    printf("LATE FEE =500/DAY\n");
    for(int i=0; i<I; i++){
        if(!strcmp(nm,arr[i].name) && r==arr[i].reg){
            printf("Enter Today's Date (dd-mm-yyyy):");
            scanf("%d-%d-%d",&d,&m,&y);
            printf("\nBranch :%s\n",arr[i].branch);
            printf("Fee :%d\n",arr[i].fees);
            due=date(d,m,y,i);
            printf("Dues :%d\n",due);
            printf("Total Fees :%d\n",arr[i].fees+due);
            s=strlen(arr[i].branch);
            printf("Would You Like To Pay The Fees(1 or 0) ?");
            scanf("%d",&c);
            if(c==1){
                arr[i].check[arr[i].year-1]=1;
                //char d1=d;
                //char m1=m;
                //char y1=y;
                //char temp[10];
                //strcat(temp,d1);
                //strcat(temp,'-');
                //strcat(temp,m1);
                //strcat(temp,'-');
                //strcat(temp,y1);
                //arr[i].dates[20][arr[i].year-1]=temp;
                arr[i].dues[arr[i].year-1]=due;
                arr[i].year+=1;
                arr[i].sem+=2;
                switch(s){
                    case 32:
                    mcse+=due+arr[i].fees;
                    break;
                    
                    case 22:
                    mit+=due+arr[i].fees;
                    break;
                    
                    case 24:
                    mae+=due+arr[i].fees;
                    break;
                    
                    case 23:
                    mme+=due+arr[i].fees;
                    break;
                    
                    case 40:
                    mece+=due+arr[i].fees;
                    break;
                    
                    case 38:
                    meee+=due+arr[i].fees;
                    break;
                    
                    case 17:
                    mce+=due+arr[i].fees;
                    break;
                }
                printf("FEES PAID SUCCESSFULLY!!\n\n");
                printf("\t\t================\n");
                printf("\t\t     RECIPT\n");
                printf("\t\t================\n\n");
                //printf("Date :%s\n",arr[i].dates[20][arr[i].year-2]);
                printf("Name :%s\n",arr[i].name);
                printf("Registration Number :%d\n",arr[i].reg);
                printf("Branch :%s\n",arr[i].branch);
                printf("Year :%d\n",arr[i].year+arr[i].year_of_joining-1);
                printf("Fees :%d\n",arr[i].fees);
                printf("Dues :%d\n",due);
                printf("Total Fees Paid :%d\n\n",due+arr[i].fees);
            }
            return 0;
        }
    }
    printf("\nSTUDENT NOT FOUND !!\n");
    return 0;
}

int hpay(){
    char nm[20];
    int r;
    printf("Enter Student Name :");
    scanf("%s",&nm);
    printf("Enter Registerion Number :");
    scanf("%d",&r);
    for(int i=0; i<I; i++){
        if(!strcmp(nm,arr[i].name) && r==arr[i].reg){
            for(int k=0; k<4; k++){
                if(arr[i].check[k]){
                    printf("\n\t\t================\n");
                    printf("\t\t     RECIPT\n");
                    printf("\t\t================\n\n");
                    //printf("Date :%s\n",arr[i].dates[20][k]);
                    printf("Name :%s\n",arr[i].name);
                    printf("Registration Number :%d\n",arr[i].reg);
                    printf("Branch :%s\n",arr[i].branch);
                    printf("Year :%d\n",arr[i].year+arr[i].year_of_joining+k-2);
                    printf("Fees :%d\n",arr[i].fees);
                    printf("Dues :%d\n",arr[i].dues[k]);
                    printf("Total Fees Paid :%d\n\n",arr[i].dues[k]+arr[i].fees);
                }
                else{
                    return 0;
                }
            }
        }
    }
    printf("NO HISTORY FOUND!!\n");
    return 0;
}

void student(){
    int c;
    for(;;){
        printf("\n1. PAY FEES\n");
        printf("2. VIEW PAYMENT HISTORY\n");
        printf("3. HOME\n");
        printf("4. EXIT\n\n");
        printf("Enter Your Choice :");
        scanf("%d",&c);
        switch(c){
            case 1:
            fpay();
            break;
        
            case 2:
            hpay();
            break;
            
            case 3:
            main();
            break;
            
            case 4:
            exit(0);
            break;
            
            default:printf("\nINVALID CHOICE\n\n");
            break;
        }
    }
}

void admin(){
    int c;
    for(;;){
        printf("\n1. ADD STUDENT DETAILS \n");
        printf("2. ALL STUDENT DETAILS \n");
        printf("3. STUDENT DETAILS(By Name)\n");
        printf("4. INCOME EARNED(Branch Vise)\n");
        printf("5. HOME\n");
        printf("6. EXIT\n\n");
        printf("Enter Your Choice :");
        scanf("%d",&c);
        switch(c){
            case 1:
            add();
            break;
        
            case 2:
            aview();
            break;
        
            case 3:
            nview();
            break;
        
            case 4:
            money();
            break;
        
            case 5:
            main();
            break;
        
            case 6:
            exit(0);
            break;
        
            default:printf("\nINVALID CHOICE\n\n");
            break;
        }
    }
}

int main()
{
    int c;
    char u[20],p[20];
    printf("\t\t\t\t\tCOLLEGE PAYMENT SYSTEM\n\n");
    for(;;){
        printf("1. STUDENT\n");
        printf("2. ADMIN\n");
        printf("3. EXIT\n\n");
        printf("Enter Your Choice :");
        scanf("%d",&c);
        switch(c){
            case 1:
            student();
            break;
            
            case 2:
            printf("Enter Username :");
            scanf("%s",&u);
            printf("Enter Password :");
            scanf("%s",&p);
            if(!strcmp(u,usname) && !strcmp(p,pwd)){
                admin();
            }
            else{
                printf("\n\nINVALID USERNAME OR PASSWORD\n\n");
            }
            break;
            
            case 3:
            exit(0);
            break;
            
            default:printf("\nINVALID CHOICE\n\n");
            break;
    }
    }
}
