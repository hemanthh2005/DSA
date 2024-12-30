#include<stdio.h>

void move (int n,char scr[],char dest[],char temp[])
{
    if (n==1)
    printf("\n move from %c to %c", scr, dest);
    else{
        move(n-1,scr,temp,dest);
        move(1,scr,dest,temp);
        move(n-1,temp,dest,scr);
    }
}
    int main(){
        int n;
        printf("\n Enter the number of ringd:");
        scanf("%d",&n);
        move(n,'A','B','C');
        return 0;
    }