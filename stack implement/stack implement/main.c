//
//  main.c
//  stack implement
//
//  Created by karim fathy on 3/6/17.
//  Copyright © 2017 Fetouh. All rights reserved.
//

#include <stdio.h>
#define maxsize 20
typedef struct{
    int items[maxsize];
    int top;
} Stack;
Stack s;

;
typedef struct{
    char itemsch[maxsize];
    int top;
} Stackch;
Stackch s2;



void push2(Stackch *s2,char value)
{             s2->itemsch[s2->top]=value;
    s2->top++;
}

char pop2(Stackch *s2)
{
    int value;
    s2->top--;
    value=s2->itemsch[s2->top];
    return value;
}

void intialize(Stack*s){s->top=0;}

int isEmpty(Stack *s){
if(s->top==0)
    return 1;
else return 0;
}
int isFull(Stack *s){
    if(s->top==maxsize)
        return 1; else return 0;}
void push(Stack*s, int value){
    s->items[s->top]=value;
    s->top++;
}

int pop(Stack *s){
    int value;
    s->top--;
    value=s->items[s->top];
    return value;

}
int priority(char x)
{
    if(x == '(')
        return 0;
    else if(x == '+' || x == '-')
        return 1;
    else if(x == '*' || x == '/')
        return 2;
    else return -1;
}

char toop(Stackch *s2){ char c; c=pop2(s2); push2(s2,c); return c;          }
int postfixV(char d[]){
    int i,x,y,z = 0;
    for(i=0;i<maxsize;i++)
    {switch(d[i]){
 case('0'): push(&s,0); break;
case('1'): push(&s,1); break;
case('2'): push(&s,2); break;
 case('3'): push(&s,3); break;
case('4'): push(&s,4); break;
case('5'): push(&s,5); break;
case('6'): push(&s,6); break;
case('7'): push(&s,7); break;
 case('8'): push(&s,8); break;
case('9'): push(&s,9); break;
case('*'): x=pop(&s); y=pop(&s); z=x*y; push(&s,z);  break;
case('+'): x=pop(&s); y=pop(&s); z=x+y; push(&s,z);  break;
case('-'): x=pop(&s); y=pop(&s); z=y-x; push(&s,z);  break;
case('/'): x=pop(&s); y=pop(&s); z=y/x; push(&s,z);  break;}}
    return pop(&s);
}
void infixTopostfix(char infix[], char postfix[])
{ int i=0,k=0,value; char x,garb;
    while(infix[i] != '\0')
    {
        if(infix[i]>='0' && infix[i]<='9')
        {postfix[k]=infix[i]; k++;}
        else if(infix[i] == '(')
            push2(&s2,infix[i]);
        else if(infix[i] == ')')
        {
            while(toop(&s2) != '(')
            {postfix[k++]=pop2(&s2); }
            garb=pop2(&s2);
        }
        else
            if(priority(toop(&s2)) <= priority(infix[i]))
            {
                push2(&s2,infix[i]);}
        
            else{while(priority(toop(&s2)) >= priority(infix[i]))
            {postfix[k]=pop2(&s2); k++;    }
                push2(&s2,infix[i]);}
        
        i++;}
    while(toop(&s2) > -1)
    {
        postfix[k]=pop2(&s2); k++; }
    printf("%s\n",postfix);

    value=postfixV(postfix);
    printf("Value= %d\n",value);}

int main(int argc, const char * argv[]) {
    int c,v,i=0,x=0;
    char d[maxsize];
    char f[maxsize];
    scanf("%s",d);
    infixTopostfix(d,f);
 /*   printf("1-Postfix Value\n2-Infix to Postfix");
    scanf("%d",&c);
    if(c==1){
    scanf("%s",d);
    intialize(&s);
    v=postfixV(d);
        printf("postfix value= %d\n",v);}
else{ scanf("%s",f);
    intialize(&s);
    while(f[i] != '\0')
{
if(f[i]>='0' && f[i]<='9')
printf("%c",f[i]);
else if(f[i] == '(')
push2(f[i]);
  else if(f[i] == ')')
 {
 while((x = pop2()) != '(')
printf("%c", x);
}
else
if(priority(temp[top-1]) <= priority(f[i]))
{
    push2(f[i]);}

else{while(priority(temp[top-1]) >= priority(f[i]))
{printf("%c",pop2());}
               push2(f[i]);}
           
    i++;}
    while(top != -1)
    {
        printf("%c",pop2()); }
}*/
    return 0; }
