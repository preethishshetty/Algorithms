//
//  LinkedList.h
//  Algorithms
//
//  Created by Preethish Shetty on 10/5/15.
//  Copyright © 2015 Preethish Shetty. All rights reserved.
//

#include<iostream>
using namespace std;


struct Node
{
    int data;
    Node *next;
};


void Traverse(Node *head)
{
    if(head==NULL)
    {
        cout<<"\nThe Linked List is empty!";
        return;
    }
    
    cout<<"Data : ";
    while(head!=NULL)
    {
        cout<<head->data<<"->";
        head=head->next;
    }

}


void InsertEnd(Node *&head,int data)
{
    if(head==NULL)
    {
        head=new Node();        ////head=(Node*)malloc(sizeof(Node));
        head->data=data;
        head->next=NULL;
        return;
    }
    
    Node *node=new Node();
    node->data=data;
    node->next=NULL;
    
    Node *temp=head;
    while(temp->next!=NULL)
        temp=temp->next;
    
    temp->next=node;
}

void InsertFront(Node **head,int data)
{
    Node *node=new Node();
    node->data=data;
    node->next=*head;
    
    *head=node;
    return;
}

void InsertKey(Node *&head,int key)
{
    if(head==NULL)
    {
        head=new Node();
        head->data=key;
        head->next=NULL;
        return;
    }
    
    Node *node=new Node();
    node->data=key;
    node->next=NULL;
    
    Node *temp=head;
    Node *prev=NULL;
    
    //First Elem
    if(key<temp->data)
    {
        node->next=head;
        head=node;
        return;
    }
    
    while(temp->next!=NULL)
    {
        if(temp->data>key)
        {
            break;
        }
        else
        {   prev=temp;
            temp=temp->next;
        }
    }
    
    if(temp->next==NULL)
    {
        temp->next=node;
    }
    else
    {
        node->next=temp;
        prev->next=node;
    }
    
    return;
}

void LinkedListTestConsole()
{
    
    Node *head=NULL;
    
    InsertEnd(head,10);
    InsertEnd(head,12);
    
    InsertFront(&head,8);
    InsertFront(&head,6);
    
    InsertKey(head,111);
    InsertKey(head,5);
    
    Traverse(head);
    
    
    
}