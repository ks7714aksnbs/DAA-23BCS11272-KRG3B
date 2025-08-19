#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node(int d):data(d),next(nullptr){}
};

class SinglyLinkedList {
    Node* head;
public:
    SinglyLinkedList():head(nullptr){}
    void insertBeginning(int x) {
        Node* n=new Node(x); n->next=head; head=n;
    }
    void insertEnd(int x) {
        Node* n=new Node(x); if(!head){head=n;return;}
        Node* t=head; while(t->next) t=t->next; t->next=n;
    }
    void insertPosition(int pos,int x) {
        Node* t=head; for(int i=0;i<pos-1 && t;i++) t=t->next;
        Node* n=new Node(x); n->next=t->next; t->next=n;
    }
    void deleteBeginning() {
        if(!head)return; Node* t=head; head=head->next; delete t;
    }
    void deleteEnd() {
        if(!head)return; if(!head->next){delete head;head=nullptr;return;}
        Node* t=head; while(t->next->next) t=t->next; delete t->next; t->next=nullptr;
    }
    void deletePosition(int pos) {
        Node* t=head; for(int i=0;i<pos-1 && t;i++) t=t->next;
        Node* del=t->next; t->next=del->next; delete del;
    }
    void display(){for(Node*t=head;t;t=t->next)cout<<t->data<<" ";cout<<"\n";}
};

int main(){
    SinglyLinkedList l;
    l.insertBeginning(1);
    l.insertEnd(2);
    l.insertEnd(3);
    l.insertPosition(1,99);
    l.display();
    l.deleteBeginning();
    l.deleteEnd();
    l.deletePosition(1);
    l.display();
}

