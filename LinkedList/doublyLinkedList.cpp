#include <iostream>
using namespace std;

class Node {
public:
    int data; Node*prev,*next;
    Node(int d):data(d),prev(nullptr),next(nullptr){}
};

class DoublyLinkedList {
    Node* head;
public:
    DoublyLinkedList():head(nullptr){}
    void insertBeginning(int x){
        Node*n=new Node(x);
        if(head){n->next=head;head->prev=n;}
        head=n;
    }
    void insertEnd(int x){
        Node*n=new Node(x);
        if(!head){head=n;return;}
        Node*t=head;while(t->next)t=t->next;
        t->next=n;n->prev=t;
    }
    void insertPosition(int pos,int x){
        Node*t=head;for(int i=0;i<pos&&t;i++)t=t->next;
        Node*n=new Node(x);
        n->next=t;n->prev=t->prev;
        if(t->prev) t->prev->next=n; else head=n;
        t->prev=n;
    }
    void deleteBeginning(){
        if(!head)return;
        Node*t=head;head=head->next;
        if(head)head->prev=nullptr;
        delete t;
    }
    void deleteEnd(){
        if(!head)return;
        Node*t=head;while(t->next)t=t->next;
        if(t->prev) t->prev->next=nullptr; else head=nullptr;
        delete t;
    }
    void deletePosition(int pos){
        Node*t=head;for(int i=0;i<pos&&t;i++)t=t->next;
        if(!t)return;
        if(t->prev) t->prev->next=t->next; else head=t->next;
        if(t->next) t->next->prev=t->prev;
        delete t;
    }
    void display(){for(Node*t=head;t;t=t->next)cout<<t->data<<" ";cout<<"\n";}
};

int main(){
    DoublyLinkedList d;
    d.insertBeginning(1);
    d.insertEnd(2);
    d.insertEnd(3);
    d.insertPosition(1,99);
    d.display();
    d.deleteBeginning();
    d.deleteEnd();
    d.deletePosition(1);
    d.display();
}

