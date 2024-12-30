#include <stdio.h>
#include <stdlib.h>
#define max 4

int s[max];
int top=-1;

void push(int s[],int val);
void pop(int s[]);
void display(int s[]);

void main(){
int val,option;
do{
    printf("1.push\t2.popt\t3.display\4.display");
    printf("Enter your option: ");
    scanf("%d",&option);
    switch (option)
    {
    case 1:/* constant-expression */
        printf("Enter the num to be inserted: \n");
        scanf("%d",&val);/* code */
        push(s,val);
        break;
    case 2:pop(s);
    break;
         case 3: display(s);
    break;
    case 4:
    exit(0);
        break;
    }
}while(option != 4);

} void push(int s[],int val){
    if(top==max-1){
        printf("overflow");
    }else{
        top=top+1;
        s[top]=val;
        printf("%d is inserted into stack\n",val);
    }
}

void pop(int s[]){
    if(top==-1){
        printf("underflow");
    }else{
        
        int val=s[top];
        top=top-1;
        printf("%d is inserted into stack\n",val);
    }
}
void display(int s[]){
    int i;
    if(top==-1){
        printf("empty");
    }else{
        for(i=top;i>=0;i--){
            printf("%d\n",s[i]);
        }
    }
}