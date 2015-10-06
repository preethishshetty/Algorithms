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


void reverseLL(Node **head)
{
    Node *cur=*head;
    Node *prev=NULL;
    
    
    while(cur!=NULL)
    {
        Node *t = cur->next;
        cur->next=prev;
        prev=cur;
        cur=t;
    }
    
    *head=prev;
}

void reverseLLRecursive(Node **head)
{
    Node *first=NULL;
    Node *rest=NULL;
    
    if(head==NULL)
        return;
    
    first=*head;
    rest=first->next;
    
    if(rest==NULL)
        return;
    
    reverseLLRecursive(&rest);
    
    (first->next)->next=first;
    first->next=NULL;
    
    *head=rest;
}


void LoopInLL(Node *head)
{
    Node *slowPtr=head;
    Node *fastPtr=head;
    
    while(slowPtr!=NULL && fastPtr!=NULL && fastPtr->next!=NULL)
    {
        slowPtr=slowPtr->next;
        fastPtr=(fastPtr->next)->next;
        if(slowPtr==fastPtr)
        {
            cout<<"FOUND LOOP!";
            return;
        }
    }

    cout<<"NO Loop Exists!";
}

bool compare(Node **head1,Node **head2)
{
    Node *headA=*head1;
    Node *headB=*head2;
    
    while(headA!=NULL && headB!=NULL)
    {
        if(headA->data!=headB->data)
        {
            return false;
        }
        
        headA=headA->next;
        headB=headB->next;
    }
    
    if(headA!=NULL || headB!=NULL)
        return false;
    
    return true;
}

void Palindrome(Node **head)
{
    Node *prevSlowPtr=NULL;
    Node *slowPtr=*head;
    Node *fastPtr=*head;
    Node *mid=NULL;
    
    while(fastPtr!=NULL && fastPtr->next!=NULL)
    {
        prevSlowPtr=slowPtr;
        slowPtr=slowPtr->next;
        fastPtr=(fastPtr->next)->next;
    }
    
    if(fastPtr!=NULL)
    {
        mid=slowPtr;
        slowPtr=slowPtr->next;
    }
    
    prevSlowPtr->next=NULL;
    Node *secondHalf=slowPtr;
    reverseLL(&secondHalf);

    bool result = compare(&*head,&secondHalf);
    if(result)
        cout<<"TRUE";
    else
        cout<<"FALSE";
    
    Traverse(*head);
    Traverse(secondHalf);

    
    if(mid==NULL)
    {
        prevSlowPtr->next=secondHalf;
    }
    else
    {
        prevSlowPtr->next=mid;
        mid->next=secondHalf;
    }

}

void removeDuplicates(Node **head)
{
    Node *cur=*head;
    cur=cur->next;
    Node *prev=*head;
    
    
    while(cur!=NULL)
    {
        if(prev->data==cur->data)
        {
            Node *t=cur;
            prev->next=cur->next;
            cur=cur->next;
            delete(t);
        }
        else
        {
            prev=cur;
            cur=cur->next;
        }
    }
}

void pairWiseSwap(Node **head)
{
    if(*head==NULL or (*head)->next==NULL)
        return;
    
    Node *prev=NULL;
    Node *A=*head;
    Node *B=(*head)->next;
    
    
    while(B!=NULL)
    {
        if(prev!=NULL)
            prev->next=B;
        else
            *head=B;
        
        A->next=B->next;
        B->next=A;
        prev=A;
        
        //New Pointers
        if(A==NULL || A->next==NULL)
            break;
        else
        {
            A=A->next;
            B=A->next;
        }
    }

}


void LinkedListTestConsole()
{
    
    Node *head=NULL;
    
    InsertEnd(head,10);
    InsertEnd(head,10);
    InsertEnd(head,10);
    InsertEnd(head,12);
    InsertEnd(head,20);
    InsertEnd(head,20);
    InsertEnd(head,25);
    
    InsertFront(&head,6);
    InsertFront(&head,6);
    
    InsertFront(&head,2);
    InsertFront(&head,2);
    
    Delete(&head,10);

    Traverse(head);
    
    removeDuplicates(&head);
    
    Traverse(head);
    
    pairWiseSwap(&head);
    
    Traverse(head);
    
    cout<<"\n\nNumber of nodes : "<<numberOfNode(head);
    
    swapNodes(&head,12,5);
    
    Traverse(head);
    
    DeleteGivenPointer(&head);
    
    Traverse(head);
    
    MiddleLL(&head);
    
    reverseLLRecursive(&head);

    cout<<"\n\nREVERSING A LINKED LIST : ";
    Traverse(head);
    
    
    reverseLL(&head);
    
    //deleteLL(&head);
    
    Traverse(head);
    
    cout<<"\n\nPalindrome : ";
    Palindrome(&head);
    
    Traverse(head);
     
}