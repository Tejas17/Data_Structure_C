//
//  main.c
//  C-BST
//
//  Created by Tejas Bhope on 10/10/15.
//  Copyright © 2015 Tejas Bhope. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node* next;
};

struct node* InsertNode( struct node* , int );
void SearchNode(struct node*, int data);
void PrintList(struct node*);



int main(int argc, const char * argv[]) {

    struct node* head = NULL;
    int array[4]={1,2,3,4};
    
    for (int i=0; i< (sizeof(array)/sizeof(array[0]));i++)
    {
        head = InsertNode(head,array[i]);
    }
    PrintList(head);
    SearchNode(head,1);
}

struct node* InsertNode(struct node* head, int data)
{
    struct node * tmp = (struct node*) malloc(sizeof(struct node*));
    if(tmp!=NULL)
    {
        tmp->data=data;
        tmp->next=head;
    }
    return tmp;
}

void PrintList(struct node* head)
{
    while (head!=NULL)
    {
        printf("%d->",head->data);
        head=head->next;
    }
    printf("NULL \n");
}

void SearchNode(struct node* head, int data)
{
    for (int position=4;head!=NULL;head=head->next,position--)
    {
        if (head->data==data)
        {
            printf("Yes we found it and position is %d\n",position);
        }
    }
}
