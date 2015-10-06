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
    
    cout<<"\nData : ";
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
    
    while(temp!=NULL)
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
    
    prev->next=node;
   
    return;
}

void Delete(Node **head,int key)
{
    if((*head)->data==key)
    {
        Node *temp=*head;
        *head=(*head)->next;
        delete(temp);
        return;
    }
    
    Node *temp=*head;
    Node *prev=NULL;
    
    while(temp!=NULL)
    {
        if(temp->data==key)
        {
            prev->next=temp->next;
            temp->next=NULL;
            delete(temp);
            return;
        }
        else
        {
            prev=temp;
            temp=temp->next;
        }
    }
    
    if(temp==NULL)
        cout<<"KEY NOT FOUND : "<<key<<"\n";
    
}

int numberOfNode(Node *head)
{
    if(head==NULL)
        return 0;
    else
        return 1 + numberOfNode(head->next);

}

void swapNodes(Node **head,int x,int y)
{
    int flag=0;
    Node *curX=*head;
    Node *prevX=NULL;
    
    while(curX!=NULL)
    {
        if(curX->data==x)
        {
            break;
        }
        
        prevX=curX;
        curX=curX->next;
    }
    
    if(curX==NULL)
    {
        cout<<"\nX not found!";
        return;
    }
    
    Node *curY=*head;
    Node *prevY=NULL;
    while(curY!=NULL)
    {
        if(curY->data==y)
        {
            break;
        }
        
        prevY=curY;
        curY=curY->next;
    }
    
    if(curY==NULL)
    {
        cout<<"\nY not found!";
        return;
    }
    
    
    if(prevX==NULL)
        *head=curY;
    else
        prevX->next=curY;
    
    if(prevY==NULL)
        *head=curX;
    else
        prevY->next=curX;
    
    Node *temp=curX->next;
    curX->next=curY->next;
    curY->next=temp;
    
    
}

void DeleteGivenPointer(Node **node)
{
    Node *temp=(*node)->next;
    Node *cur = (*node);
    
    if(temp==NULL)
    {
        cout<<"\nNo Solution!";
        return;
    }
    
    cur->data=temp->data;
    cur->next=temp->next;
    
    delete(temp);
    
    return;
}

void MiddleLL(Node **head)
{
    Node *slowPtr=*head;
    Node *fastPtr=*head;
    
    while(fastPtr!=NULL && fastPtr->next!=NULL)
    {
        fastPtr=(fastPtr->next)->next;
        slowPtr=slowPtr->next;
    
    }

    cout<<"\nMIDDLE ELEMENT : "<<slowPtr->data;
}

void deleteLL(Node **head)
{
    Node *temp=*head;

    while(temp!=NULL)
    {
        Node *temp2=temp;
        temp=temp->next;
        delete(temp2);
    }
}


void LinkedListTestConsole()
{
    
    Node *head=NULL;
    
    InsertEnd(head,10);
    InsertEnd(head,12);
    InsertEnd(head,20);
    InsertEnd(head,25);
    
    InsertFront(&head,2);
    InsertFront(&head,8);
    InsertFront(&head,6);
    
    InsertKey(head,111);
    InsertKey(head,5);
    
    Delete(&head,100);
    Delete(&head,8);
    Delete(&head,111);
    
    
    cout<<"\nNumber of nodes : "<<numberOfNode(head);
    
    Traverse(head);
    
    swapNodes(&head,12,5);
    
    Traverse(head);
    
    DeleteGivenPointer(&head);
    
    Traverse(head);
    
    MiddleLL(&head);
    
    deleteLL(&head);
    if(head==NULL)
        cout<<"EMPTY LINKED LIST!";
    else
        cout<<"HEAD : "<<head->data;

    
}