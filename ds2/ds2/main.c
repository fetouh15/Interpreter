//
//  main.c
//  ds2
//
//  Created by karim fathy on 5/2/17.
//  Copyright © 2017 Fetouh. All rights reserved.
//

#include <stdio.h>
typedef struct{
int coefficient;
int exponent;
struct polyNode *next;
} polyNode;

typedef struct {
    polyNode *head, *tail; } polyLinkedList;
polyLinkedList add, multiply,simp;

void initLinkedList(polyLinkedList *list) {
    list->head=NULL;
    list->tail=NULL; }

polyNode * newNode(int val, int val2) {
    polyNode* n=malloc(sizeof(polyNode));
    n->coefficient=val;
    n->exponent=val2;
    n->next=NULL;
    return n;
}

void addHead(polyLinkedList *list,int value, int value2) {
    polyNode *n=newNode(value, value2);
    n->next=list->head;
    list->head=n;
    if(list->tail==NULL)
        list->tail=n; }
void addTail(polyLinkedList *list,int value, int value2) {
    polyNode *n=newNode(value, value2);
    if(list->head==NULL)
        list->head=list->tail=n; else{
            polyNode *OldTail=list->tail; list->tail=n; OldTail->next=n;
        }}
void display_poly(polyLinkedList *x){

    if(x->head->exponent!=0)  {printf("%dx^%d", x->head->coefficient,x->head->exponent);} else{printf("%d", x->head->coefficient);}
    polyNode* n= x->head->next;
    while(n!=NULL){
        if(n->coefficient > 0)
        {  if(n->exponent!=0) {
            printf("+%dx^%d", n->coefficient,n->exponent);}
            else{    printf("+%d", n->coefficient);       }}
        else if(n->coefficient < 0)
        {
        
        if(n->exponent!=0) {
            printf("%dx^%d", n->coefficient,n->exponent);}
            else{    printf("%d", n->coefficient);       }}
        
        n=n->next;            } printf("\n");
}

float getValue (polyLinkedList *q,float x){
    float result=0;
    polyNode* n= q->head;
    while(n!=NULL){
        result+= n->coefficient*(powf(x,n->exponent));
        n=n->next;
    }

    return result;
}

polyLinkedList* poly_add (polyLinkedList *x, polyLinkedList *y ){
    int c;
    initLinkedList(&add);
    polyNode* n1= x->head;
    polyNode* n2= y->head;

 while(n1!=NULL)
{  if(n1->exponent == n2->exponent)
{ c=n1->coefficient+n2->coefficient;   addTail(&add,c, n2->exponent);         n2=n2->next;  n1=n1->next;  }
else if(n1->exponent > n2->exponent)
{addTail(&add, n1->coefficient, n1->exponent);      n1=n1->next;   }
    else if(n1->exponent < n2->exponent)
    {addTail(&add, n2->coefficient, n2->exponent);    n2=n2->next;     }
    
    
}
    while(n2!=NULL)
    {addTail(&add, n2->coefficient, n2->exponent); n2=n2->next;}
return &add;}
polyLinkedList * poly_mul (polyLinkedList *x, polyLinkedList *y ){
initLinkedList(&multiply);
    int c,e;
    polyNode* n1= x->head;
    polyNode* n2= y->head;
    while(n1!=NULL)
    { while(n2!=NULL){ c=n1->coefficient*n2->coefficient;
        e=n1->exponent+ n2->exponent;
        n2=n2->next;
        addTail(&multiply, c, e);
    }
    
    
    
    n2= y->head;
        n1=n1->next;
    
    


    }
    return &multiply;
}

/*polyLinkedList * poly_simp (polyLinkedList *x){
    polyNode* n1= x->head; int c;
    initLinkedList(&simp);
    polyNode* n2= simp.head;
    addTail(&simp, n1->coefficient, n1->exponent);
   n1 = n1->next;
    while(n1!=NULL){
        while(n2!=NULL){
        if(n1->exponent==n2->exponent){

c=n1->coefficient+n2->coefficient;   addTail(&simp,c, n2->exponent);   n1=n1->next;}
        else{  addTail(&simp,n1->coefficient, n1->exponent);    n2=n2->next;}
}  n2= simp.head;
    }
    return &simp;
}*/


int main(int argc, const char * argv[]) {
    polyLinkedList p1,p2; float get;
    int c = 0,e = 0,flag1=0,flag2=0;
    initLinkedList(&p1);
    //initLinkedList(&p3);
    initLinkedList(&p2);
    
    printf("first polynomial\n");
    printf("n1\n");
    int n1;
  scanf("%d",&n1);
    int i=0;
    for(i=0;i<n1;i++)
    { printf("enter coefficient\n");
        scanf("%d",&c);
        
    printf("enter exponent\n");
        scanf("%d",&e);
        
       addTail(&p1,c,e);
    }
    display_poly(&p1);
   // get=getValue(&p1,1);
    //printf("p1:\t%f\n",get);
    printf("second polynomial\n");
    printf("n2\n");
    int n2;
    scanf("%d",&n2);
    
    for(i=0;i<n2;i++)
    { printf("enter coefficient\n");
        scanf("%d",&c);
        
        printf("enter exponent\n");
        scanf("%d",&e);
        
        addTail(&p2,c,e);
    }
  display_poly(&p2);
    int choice,v;
    do{  printf("\n1-GET1 2-GET2 3-ADD 4-MULTIPLY 5-Exit\n");
        scanf("%d",&choice);
        switch (choice) {
        case 1:
        {printf("\nENter value");
            scanf("%d",&v);
            get=getValue(&p1,v);
            printf("\np1:\t%f\n",get);
            break;}
        case 2:
        {   printf("ENter value");
            scanf("%d",&v);
            get=getValue(&p2,v);
            printf("\np2:\t%f\n",get);
            break;}
        case 3:
        { add=*poly_add(&p1,&p2);
            printf("\nAdd=");display_poly(&add);
            break;}
        case 4:
        {
            multiply=*poly_mul(&p1,&p2);
            printf("\nMultiply=");
            //simp=*poly_simp(&multiply);
            display_poly(&multiply);

            
            
            
            break;}
            
            
            
            
        default:
            break;
    }
    
    } while(choice<5);
    
    
    /*display_poly(&p2);
    //get=getValue(&p2,1);
    //printf("p2:\t%f\n",get);
   add=*poly_add(&p1,&p2);
    printf("Add=");display_poly(&add);
    multiply=*poly_mul(&p1,&p2);
    printf("Multiply=");display_poly(&multiply);*/
    
    
    
    
    
    
    
    
    
    
    
    
    
    return 0;
}
