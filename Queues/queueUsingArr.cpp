#include <iostream>
using namespace std;

class QueueArray {
    int arr[100], f, r;
public:
    QueueArray(): f(0), r(-1) {}
    void enqueue(int x) { arr[++r] = x; }
    int dequeue() { return arr[f++]; }
    bool empty() { return f > r; }
};

int main() {
    QueueArray q;
    q.enqueue(10);
    q.enqueue(20);
    cout << "Dequeue: " << q.dequeue() << "\n";
    cout << "Dequeue: " << q.dequeue() << "\n";
}

