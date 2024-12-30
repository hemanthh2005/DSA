#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#define max 100

double s[max];
int top;
void push(double s[],double val);
double pop(double s[]);
double evaluate(char postfix[]);

void main(){
    double val;
    char postfix[100];
    printf("Enter the postfix expression: ");
    scanf("%d",&postfix);
    val=evaluate(postfix);
    printf("result to postfix expression: %1f\n",val);
}

double evaluate(char postfix[]){
    int i=0;
    double op1,op2,value;
    while(postfix[i]!='\0'){
        if(isdigit(postfix[i])){
            push(s,(double)(postfix[i])-'0');
        }else{
            op2=pop(s);
            op1=pop(s);
            switch (postfix[i])
            {
            case '+':value=op1+op2;
                break;
            case '-':value=op2-op1;
                break;
            case '*':value=op2*op1;
                break;
            case '/':value=op1/op2;
                break;
            case '%':value=(int )op1 % (int)op2;
                break;
            // case '^': value=pow(op1,op2);
            //     break;
            } push(s,value);
        }i++;
    } return pop(s);
}
 void push(double s[],double val){
    if(top==max-1){
        printf("overflow");
    }else{
        top=top+1;
        s[top]=val;
    }
}

double pop(double s[]){
    if(top==-1){
        printf("underflow");
    }else{
        
        int val=s[top];
        top=top-1;
        
     return val;
    }
}
