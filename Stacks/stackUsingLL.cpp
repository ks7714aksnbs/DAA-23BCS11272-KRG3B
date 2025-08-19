#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node(int d): data(d), next(nullptr) {}
};

class StackList {
    Node* top;
public:
    StackList(): top(nullptr) {}
    void push(int x) { top = new Node(x){*top}; } // shorthand won't work in some compilers
    int pop() {
        int v = top->data;
        Node* t = top;
        top = top->next;
        delete t;
        return v;
    }
    int peek() { return top->data; }
    bool empty() { return !top; }
};

int main() {
    StackList s;
    s.push(10);
    s.push(20);
    cout << "Pop: " << s.pop() << "\n";
    cout << "Peek: " << s.peek() << "\n";
}

