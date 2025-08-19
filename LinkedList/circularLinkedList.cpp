#include <iostream>
using namespace std;

class Node {
public:
    int data; Node*next;
    Node(int d):data(d),next(this){}
};

class CircularLinkedList {
    Node* head;
public:
    CircularLinkedList():head(nullptr){}
    void insertBeginning(int x){
        Node*n=new Node(x);
        if(!head){head=n;return;}
        Node*t=head;while(t->next!=head)t=t->next;
        n->next=head;t->next=n;head=n;
    }
    void insertEnd(int x){
        Node*n=new Node(x);
        if(!head){head=n;return;}
        Node*t=head;while(t->next!=head)t=t->next;
        t->next=n;n->next=head;
    }
    void insertPosition(int pos,int x){
        Node*t=head;for(int i=0;i<pos-1;i++)t=t->next;
        Node*n=new Node(x);n->next=t->next;t->next=n;
    }
    void deleteBeginning(){
        if(!head)return;
        Node*t=head;while(t->next!=head)t=t->next;
        Node*tmp=head;head=head->next;t->next=head;delete tmp;
    }
    void deleteEnd(){
        if(!head)return;
        Node*t=head;while(t->next->next!=head)t=t->next;
        delete t->next;t->next=head;
    }
    void deletePosition(int pos){
        Node*t=head;for(int i=0;i<pos-1;i++)t=t->next;
        Node*del=t->next;t->next=del->next;delete del;
    }
    void display(){
        if(!head)return;Node*t=head;
        do{cout<<t->data<<" ";t=t->next;}while(t!=head);
        cout<<"\n";
    }
};

int main(){
    CircularLinkedList c;
    c.insertBeginning(1);
    c.insertEnd(2);
    c.insertEnd(3);
    c.insertPosition(1,99);
    c.display();
    c.deleteBeginning();
    c.deleteEnd();
    c.deletePosition(1);
    c.display();
}

