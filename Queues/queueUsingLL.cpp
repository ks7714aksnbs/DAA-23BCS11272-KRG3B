#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node(int d): data(d), next(nullptr) {}
};

class QueueList {
    Node* f, *r;
public:
    QueueList(): f(nullptr), r(nullptr) {}
    void enqueue(int x) {
        Node* n = new Node(x);
        if (!r) f = r = n;
        else { r->next = n; r = n; }
    }
    int dequeue() {
        int v = f->data;
        Node* t = f;
        f = f->next;
        if (!f) r = nullptr;
        delete t;
        return v;
    }
    bool empty() { return !f; }
};

int main() {
    QueueList q;
    q.enqueue(10);
    q.enqueue(20);
    cout << "Dequeue: " << q.dequeue() << "\n";
    cout << "Dequeue: " << q.dequeue() << "\n";
}

