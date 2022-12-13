
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
class Node{
public:
int data;
Node *next;
//constructor
Node(int data)
{
  this->data=data;
  this->next=NULL;
}
//destructor
Node()
{
    int data=this->data;
    //free the memory
    if(this->next!=NULL)
    {
        delete next;
        this->next=NULL;
    }
    cout<<"memory is free guys";
}
};
void deleteNode(int posn,Node*&head)
{
    //deleting first /starting node
    if(posn==1)
    {
        Node *temp=head;
        head=head->next;
        temp->next=NULL;
        delete temp;
    }
    else
    {
        //deleting any middle node or last node
        Node *temp=head;
        Node *prev=NULL;
        int ctr=1;
        while(ctr<posn)
        {
            prev=temp;
            temp=temp->next;
            ctr++;
        }
        prev->next=temp->next;
        temp->next=NULL;
        delete temp;
    }
}
void insertathead(Node*&head,int d)
{
  //creating a new node
  Node *temp=new Node(d);
  temp->next=head;
  head=temp;
}
void insertattail(Node* &tail,int d)
{
    //creating a new node
    Node *temp=new Node(d);
    tail->next=temp;
    tail=tail->next;
}
void insertatposn(Node* &head,int posn,int d)
{
    if(posn==1)
    {
        insertathead(head,d);
        return;
    }
    //creating a new node to store head kyunki head sae koi chekhani nhi //
    Node *temp=head;
    int ctr=1;
    while(ctr<posn-1)
    {
        temp=temp->next;
        ctr++;
    }
    //creating a node which is going to be inserted at given posn
Node *toinsert=new Node(d);
toinsert->next=temp->next;
temp->next=toinsert;
}
void print(Node *&head)
{
  Node *temp=head;
  while(temp!=NULL)
    {
      cout<< temp->data <<endl;
      temp=temp->next;
    }
  cout<<endl;
}
int main()
{
  //create a new node
  Node *node1=new Node(10);
  //head pointed to node 1
  Node *head=node1;
  insertathead(head,12);
  print(head);
  //inserting at head;
    insertathead(head,14);
    print(head);

   //inserting at tail;
    Node*tail=node1;
    insertattail(tail,15);
   print(tail);
  //inserting at posn
  insertatposn(head,2,18);
  print(head);
  deleteNode(2,head);
  print(head);
  return 0;
}
