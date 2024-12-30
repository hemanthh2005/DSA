#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#define max 100
char s[max];
int top=-1;
void push(char s[],char);
char pop(char s[]);
void InfixToPostfix(char infix[],char postfix[]);
int getPriority(char);
    int main()
    {
        char infix[100],postfix[100];
        printf("Enter the valid infix expression\n");
        scanf("%s",infix);
        strcpy(postfix,"");
        InfixToPostfix(infix,postfix);
        printf("\n The postfix expression is:\n");
        printf("%s\n",postfix);
        return 0;
}

void InfixToPostfix(char infix[],char postfix[])
{
    int i=0,j=0;
    char temp;
    strcpy(postfix,"");

    while(infix[i]!='\0')
    {

        if(infix[i]=='(')
        {

            push(s,infix[i]);
            i++;
    }
    else if(infix[i]==')')
    {
         while((top!=-1)&&(s[top]!='('))
        {
            postfix[j]=pop(s);
            j++;
    }
    if(top==-1)
    {
        printf("\n Incorrect Expression\n");
        exit(0);
}
temp=pop(s);
i++;
}

    else if(isdigit(infix[i])||isalpha(infix[i]))
    {

        postfix[j]=infix[i];
        j++;
        i++;
}

    else if(infix[i]=='+'|| infix[i]=='-'||infix[i]=='*'
    ||infix[i]=='/'||infix[i]=='%'||infix[i]=='$'||infix[i]=='^')
    {

        while((top!=-1) && (s[top]!='(') &&
        (getPriority(s[top])>=getPriority(infix[i])))
        {
            postfix[j]=pop(s);
            j++;
    }
    push(s,infix[i]);
    i++;
 }
    else
    {
        printf("\n Incorect Element in Expression\n");
        exit(1);
 }
 }

    while((top!=-1)&&(s[top]!='('))
    {
        postfix[j]=pop(s);
        j++;
 }
 postfix[j]='\0';
}

int getPriority(char op)
    {
    if(op=='^'|| op=='$')
    return 2;
    else if(op=='/' ||op=='*' ||op=='%')
    return 1;
    else if(op=='+' || op=='-')
    return 0;
}

void push(char s[],char val)
{
    if(top==max-1)
    {
        printf("STACK OVERFLOW\n");
    }
    else
    {
        top=top+1;
        s[top]=val;
}
}

char pop(char s[])
{
    char val=' ';
    if(top==-1)
    {
        printf("STACK UNDERFLOW\n");
}
else
{
    val=s[top];
    top=top-1;
}
return val;
}
