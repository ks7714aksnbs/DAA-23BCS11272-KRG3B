#include <iostream>
using namespace std;

class StackArray {
    int arr[100], top;
public:
    StackArray(): top(-1) {}
    void push(int x) { arr[++top] = x; }
    int pop() { return arr[top--]; }
    int peek() { return arr[top]; }
    bool empty() { return top == -1; }
};

int main() {
    StackArray s;
    s.push(10);
    s.push(20);
    cout << "Pop: " << s.pop() << "\n";
    cout << "Peek: " << s.peek() << "\n";
}

