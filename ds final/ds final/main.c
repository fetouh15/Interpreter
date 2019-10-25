//
//  main.c
//  ds final
//
//  Created by karim fathy on 5/6/17.
//  Copyright © 2017 Fetouh. All rights reserved.
//

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define maxsize 50
typedef struct {
    char vn[50];
    float data;
    struct Node *next; } Node;
typedef struct {
    Node *head, *tail; } LinkedList;
void initLinkedList(LinkedList *list) {
    list->head=NULL;
    list->tail=NULL; }
Node * newNode(float val, char val2[]) {
    
    Node* n=(Node*)malloc(sizeof(Node));
    n->data=val;
    strcpy(n->vn, val2);
    n->next=NULL;
    return n;}

void addTail(LinkedList *list,float value, char val2[]) {
    Node *n=newNode(value, val2);
    if(list->head==NULL)
        list->head=list->tail=n; else{
            Node *OldTail=list->tail; list->tail=n; OldTail->next=n;
        }}

LinkedList L1;
typedef struct{
    float items[maxsize];
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
    float value;
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
void push(Stack*s, float value){
    s->items[s->top]=value;
    s->top++;
}

float pop(Stack *s){
    float value;
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
float postfixV(char d[]){
    int i,j=0,n;
    int len;
    len=mystrlen(d);
    float x,y,z=0;
    float numb;
    char temp[50]="\0";
    for(i=0;i<len;i++)
    { j=0;
        for(n=0;n<50;n++)
        { temp[n]='\0';         }
        if((d[i]>='0' && d[i]<='9')|| d[i]=='.')
        { while((d[i]>='0' && d[i]<='9')|| d[i]=='.')
        { temp[j]=d[i];
            j++;
            i++;
        } numb=atof(temp); push(&s,numb); }
        
        
        switch(d[i]){
                /* case('0'): push(&s,0); break;
                 case('1'): push(&s,1); break;
                 case('2'): push(&s,2); break;
                 case('3'): push(&s,3); break;
                 case('4'): push(&s,4); break;
                 case('5'): push(&s,5); break;
                 case('6'): push(&s,6); break;
                 case('7'): push(&s,7); break;
                 case('8'): push(&s,8); break;
                 case('9'): push(&s,9); break;*/
            case('*'): x=pop(&s); y=pop(&s); z=x*y; push(&s,z);  break;
            case('+'): x=pop(&s); y=pop(&s); z=x+y; push(&s,z);  break;
            case('-'): x=pop(&s); y=pop(&s); z=y-x; push(&s,z);  break;
            case('/'): x=pop(&s); y=pop(&s); z=y/x; push(&s,z);  break;}}
    return pop(&s);
}
void infixTopostfix(char infix[], char postfix[])
{ int i=0,k=0;
    float value;
    char x,garb;
    while(infix[i] != '\0')
    {
        if((infix[i]>='0' && infix[i]<='9')|| infix[i]=='.')
        {postfix[k]=infix[i]; k++;
            if(infix[i+1]=='(' || infix[i+1]==')' ||infix[i+1]=='+' || infix[i+1]=='-' ||infix[i+1]=='*' ||infix[i+1]=='(')
            {postfix[k]='|'; k++;}
        }
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
        postfix[k]=pop2(&s2); k++; }   postfix[k]='\0';  }
   






int checkeq(int len, char x[100])
{ int i=0,flag = 0;
    for(i=0;i<len;i++)
{ if(x[i]=='=')
{flag++;
}
} return flag;                }
int checkv(int len,char x[50] )
{   int i=0,flag = 0;

    for(i=0;i<len;i++)
    { if(x[i]=='*' || x[i]=='+' || x[i]=='-' || x[i]=='/' || x[i]=='('|| x[i]==')')
    {
        flag=1;
    }
        if(x[i]>='0' && x[i]<='9')
        {   if(i==0){flag=1;}}
    }

    return flag;

}
int checkexp(int len, char* y)
{ int i=0,j=0,flag=0;
    for(i=0;i<len;i++){
        if(*(y+i)=='.')
        { if(*(y+i-1)<'0'||*(y+i-1)>'9')
        {flag=2; break;}
            if(*(y+i+1)<'0'||*(y+i+1)>'9')
            {flag=2; break;}
        
        
        }
        if(*(y+i)<'0'||*(y+i)>'9')
        {flag=1;}
      //  while(j<len)
        //{     if(*(y+i)=='*' || *(y+i)=='+' || *(y+i)=='-' || *(y+i)=='/')         j++;}
        if(*(y+i)=='*' || *(y+i)=='+' || *(y+i)=='/' || *(y+i)=='-')
        {  if(*(y+i+1)=='*' || *(y+i+1)=='+' ||  *(y+i+1)=='/' ||  *(y+i+1)==')')
            {flag=2; break;}}
       else if(*(y+i)=='*' || *(y+i)=='+' || *(y+i)=='/')
        {if(*(y+i-1)=='*' || *(y+i-1)=='+' || *(y+i-1)=='-' || *(y+i-1)=='/' ||  *(y+i-1)=='(')//sal7 ba3deen 7owar el minus 7pp teslam
            {flag=2; break;} }
                else
            flag=1;  }
    
 //   if(j==i)
   //     flag=5;
    if (*(y+len-1)=='*' || *(y+len-1)=='+' || *(y+len-1)=='-' || *(y+len-1)=='/' ||  *(y+len-1)=='(') {
        flag=2;
    }
        return flag;
}

int exphandler(char temp2[50], char a1[50],int len){
    char a[20],v[15];
    int i=0,j=0,k=0,p,h=0;
    Node *n1;
    int m,flag5 = 0;
    while(i<len){
        m=0; flag5=2;
        
        
        while((temp2[i]<='9' && '0'<=temp2[i])|| temp2[i]=='*' || temp2[i]=='+' || temp2[i]=='-' || temp2[i]=='/' || temp2[i]=='('|| temp2[i]==')' ||temp2[i]=='.')
        { a1[k]=temp2[i]; k++; i++;} if(i==len){temp2[i]='\0';} if(temp2[i]=='\0') {break;}
        if( temp2[i]!='*' && temp2[i]!='+' && temp2[i]!='-' && temp2[i]!='/' && temp2[i]!='('&& temp2[i]!=')')
        {j=i;
            /*  if(a[k][0]!='\0')
             k++;*/
            while( temp2[j]!='*' && temp2[j]!='+' && temp2[j]!='-' && temp2[j]!='/' && temp2[j]!='('&& temp2[j]!=')'&& temp2[j]!='\0')
            {
                
                a[m]=temp2[j];  j++; m++;   }    i=j; //i++
            
            n1=L1.head;
            while(n1!=NULL)
            {  p=strcmp(a,n1->vn);
                if(p==0){
                    sprintf(v,"%f", n1->data);
                    while(v[h]!='\0')
                    {a1[k]=v[h]; k++; h++;}
                    h=0;
                    flag5=1;
                    break;
                }
                n1=n1->next;
                
            }
            if(flag5==2){  printf("Invalid Symbol %s\n",a); flag5=3;  break;  }
            
        }  if(flag5==3){   break;  }
        
    }
    a1[k]='\0';
    return flag5;


}

int mystrlen(char x[100]){  int i=0;

while(x[i]!='\0')
    {i++;}
    return i;
}
int mystrcmp (char x[100], char y[100]){
    int i,r=0;
    for(i=0;i<strlen(x);i++)
    { if(x[i]!=y[i])
        { r=1; break;      }
    }
    return r;
}








int main(int argc, const char * argv[]) {
    char x[100]="NULL";
    int j=0,flagv=0,flagow=0,flagexp=0,flageq=0,flag5=0,len,len2,len3,count1 = 0,count2 = 0;
    char end[4]="end";
    int r = 1,i=0,z; float input = 0.0;
  
    char x1[50],x2[50],temp[50],temp2[50];
    char a1[50];
    Node *n1;
     initLinkedList(&L1);

    while(r!=0){
       fflush( stdout );
        printf("Enter the expression (or “end” to exit):\n");
        scanf("%s",x);

       
     
    // r=strncmp(x,end,3);
      r=0;
     for(i=0;i<3;i++)
        { if(end[i]!=x[i])
        { r=1; break;      }
        }
        if(r==0){break;}
       
        len3=mystrlen(x);
        flageq=0;
        flagv=0;
        flagexp=0;
        flagow=0;
        
     
        flageq=checkeq(len3, x);
        if(flageq==0){ printf("Missing = in the expression\n"); continue;         }
        else if(flageq>1){  printf("invalid expressions\n"); continue;}
        
        count1 = 0;
        count2 = 0;
        for(i=0;i<len3;i++)
        {
        if(x[i]=='(')
            count1++;
            else if(x[i]==')')
                count2++;
        
        }
        if( count1 != count2)
        { printf("invalid expressions\n"); continue;}
        i=0; j=0;
        while(x[i]!='=')
        {x1[i]=x[i]; i++;}
        x1[i]='\0';
        i++;
        while(i<len3)
        {    temp2[j]=x[i];     j++;            i++; }
        temp2[j]='\0';
     
        strcpy(temp, x1);
        
        len2=mystrlen(x1);
        
       
        flagv=checkv(len2, x1);
        if(flagv==1){ flagv=0; printf("error\n");
            continue;            }
        

       

           len=mystrlen(temp2);
            
        
            flagexp= checkexp(len, temp2);
            
        if(flagexp==2) { printf("error\n"); continue;  }
            if(flagexp==0) {input=atof(temp2);  }
            if(flagexp==1){
                flag5=exphandler(temp2, a1, len);
       if(flag5==3){ flag5=0;  continue;  }
               
                
                infixTopostfix(a1, x2);
                //x2[strlen(x2)]='\0';
                input=postfixV(x2);
        }

        
       
        n1=L1.head;
        while(n1!=NULL)
        {
            z=strcmp(temp,n1->vn);
            if(z==0){
                 printf("The value of entered expression %f\n",input);
                n1->data=input; 
                flagow=1;  break;  }
            n1=n1->next;
        }
        
        if(flagow==0){ printf("The value of entered expression %f\n",input); addTail(&L1, input, temp);                  }
    
    
    
    }
    
    
   
    return 0;
}
