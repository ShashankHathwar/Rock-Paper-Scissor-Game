#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include<ctype.h>

int n, win, loss, draw,numofgames, e, i;

typedef struct{
    char name[10];
    int numofround;
    int w;

}user;
user users[10];

int intgetinteger() {
    char buffer[100];   // temporary string
    int value;

    while (1) {
        printf("\nEnter your choice: ");
        scanf("%99s", buffer);   // read as string

        // Step 1: Check if every character is a digit
        int valid = 1;
        for (int i = 0; buffer[i] != '\0'; i++) {
            if (!isdigit(buffer[i])) {
                valid = 0;
                break;
            }
        }

        // Step 2: If not valid, reject and loop again
        if (!valid) {
            printf("Invalid input. Please enter numbers only.\n");
            continue;
        }

        // Step 3: Convert string to integer
        value = atoi(buffer);
        return value;   // return the safe integer
    }
}


void game(){
    srand(time(NULL));
        int  i,r;
        win=0;
        loss = 0;
        draw = 0;
        numofgames=0;
        label:
        printf("\nNumber of rounds to be played in the series ---->\n");
        n=intgetinteger();
        numofgames=numofgames+n;

    for (i = 1; i <= n; i++) {
        int uchoice, cchoice;

        printf("\nThe choices are:\n1. Rock\n2. Paper\n3. Scissor\nEnter your choice: ");
        uchoice=intgetinteger();

        cchoice = (rand() % 3) + 1;

        if (uchoice > 3) {
            printf(" \nInvalid choice: Please select a choice from 1-3.\n");
        }
        else if (uchoice == cchoice) {
            printf(" \n\033[33mIts a draw!!\033[0m\n");
            draw++;
        }
        else if (cchoice == 1 && uchoice == 3) {
            printf(" \n\033[31mYou lose!!\033[0m\n");
            loss++;
        }
        else if (cchoice == 1 && uchoice == 2) {
            printf(" \n\033[32mYou win!!\033[0m\n");
            win++;
        }
        else if (cchoice == 2 && uchoice == 1) {
            printf(" \n\033[31mYou lose!!\n\033[0m");
            loss++;
        }
        else if (cchoice == 2 && uchoice == 3) {
            printf(" \n\033[32mYou win!!\033[0m\n");
            win++;
        }
        else if (cchoice == 3 && uchoice == 2) {
            printf(" \n\033[31mYou lose!!\033[0m\n");
            loss++;
        }
        else if (cchoice == 3 && uchoice == 1) {
            printf(" \n\033[32mYou win!!\n033[0m\n");
            win++;
        }

        switch (cchoice) {
            case 1: {
                printf("\nThe computer's choice was : Rock\n");
                break;
            }
            case 2: {
                printf("\nThe computer's choice was : Paper\n");
                break;
            }
            case 3: {
                printf("\nThe computer's choice was : scissor\n");
                break;
            }
        }

        switch (uchoice) {
            case 1: {
                printf("Your choice was : Rock\n");
                break;
            }
            case 2: {
                printf("Your choice was : Paper\n");
                break;
            }
            case 3: {
                printf("Your choice was : scissor\n");
                break;
            }
        }
    }

    printf ("\n\n\033[32mThe total number of wins in the series : %d\033[0m\n", win);
    printf ("\033[31mThe total number of losses in the series: %d\033[0m\n", loss);
    printf ("\033[33mThe total number of draws in the series: %d\033[0m\n\n", draw);

    if (win == loss){
        printf("\033[33mThe series is a draw !!!\033[0m");
    }
    else if (win > loss) {
        printf("\033[32mYou win the series!!!\033[0m");
    }
    else {
        printf("\033[31mYou lose the series.\033[0m");
    }
    label5:
        printf("\n\nDo you want to play the game again:\nYes = Enter 1\nNo = Enter 2\n");
        r=intgetinteger();

    if(r==1){
        goto label;
    }
    else if(r>2){
        printf("Enter a valid choice(1-2).");
        goto label5;
    }
}

void leaderboard(){
    int u=0;
    char n[10]={"\0"};
    while(u<10 && strcmp(users[u].name, n)!=0){
            u++;
    }
    if(u==0){
        printf("You are the only player in the game.");
    }
    else if(u<10){
            printf("The leaderboard is as follows:\n");
      for(int i = 0; i < u - 1; i++) {
        for(int j = 0; j < u - i - 1; j++) {
            if(users[j].w < users[j + 1].w) {
                user temp[10];
                temp[j] = users[j];
                users[j]= users[j + 1];
                users[j + 1]= temp[j];
            }
        }

            }
            printf("\033[44m\033[32m%-8s %-12s %-15s %-20s\033[0m\033[0m\n", "SI.No", "Name", "No.of wins", "No.of rounds played");
            printf("----------------------------------------------------------\n");
             for(int t=0;t<u;t++){
            printf("\033[44m\033[32m%-8d %-12s %-15d %-20d\033[0m\033[0m\n", t+1, users[t].name, users[t].w, users[t].numofround);
    }
    }
}


void login1(){
    int y;
    printf("\nDirecting to the game arena....\n\n");
            game();
            users[e].numofround=numofgames;
            users[e].w=win;
            label:
                printf("\nDo you want to see the leader board:\n1. Yes\n2. No\n ");
            y=intgetinteger();
            if(y==1){
                leaderboard();
            }
            else if(y==2){
                return;
            }
            else{
                printf("Enter the valid choice.\n");
                goto label;
            }
}

void newuser(){
    int j=0;
    char run[10]={"\0"};
    while(j<10 && strcmp(users[j].name, run)!=0){
        j++;
    }
    if(j>=10){
        printf("The game capacity is full.");
    }
    if(j<10){
        printf("\nEnter your name(no spaces):");
            scanf("%9s", users[j].name);
            e=j;
            printf("\nPosition %d is empty out of limited 10 positions.\n", e+1);
            login1();
    }
}


void database(){
    char nameofuser[10];
    int k;
    int y;
    int o;
    i=-1;
    printf("Enter your name (in lower case only, without any spaces):");
    scanf("%9s", nameofuser);
    for(k=0;k<10;k++){
        if(strcmp(users[k].name, nameofuser)== 0){
           i=1;
           e=k;
           break;
        }
        }

    if(i==1){
            printf("User found at %d position.\n1. Do you want to play.. or\n2. Do you want to register a new user...\n ", e+1);
            o=intgetinteger();
            if(o==1){
                    login1();
            }
            else if(o==2){
                newuser();
            }
        }
        else{
            printf("User not found.\nEnter the correct user name.\n ");

        }
}


void userfirst(){
    int num;
    int u;
    printf("\n1. Login\n2. Signup\n3. Exit the game.\n");
    num=intgetinteger();

if(num==1){
        database();
        label2:printf("\n\nDo you want another player to play...\n1. Yes\n2. No\n");
        u=intgetinteger();
        if(u==1){
            userfirst();
        }
        else if(u>2){
            printf("Enter a valid choice.");
            goto label2;
         }
    }
    else if(num==2){
        newuser();
        userfirst();
    }
    else if(num==3){
        exit(0);
    }
    else {
        printf("Enter a valid choice.");
        int cc;
        label3:
            printf("Do u want to select the choice again(number only)\n1. Yes\n2. No\n");
        cc=intgetinteger();
        if(cc==1){
                userfirst();
                }
                else if(cc==2){
                    exit(0);
                }
                else{
                    printf("Choose a valid option.\n");
                    goto label3;
                }


        }



}


int main(){
    printf("\n\033[32m******Welcome to the Rock Paper Scissor game******\033[0m\n\n");
    for(int i=0;i<10;i++){
    users[i].name[0] = '\0';
    }
    userfirst();
    return 0;
}
