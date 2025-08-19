#include <iostream>
using namespace std;

class CircularQueue {
    int *arr, size, front, rear, count;
public:
    CircularQueue(int n){ size=n; arr=new int[size]; front=0; rear=-1; count=0; }
    void enqueue(int x){ if(count<size){ rear=(rear+1)%size; arr[rear]=x; count++; } }
    void dequeue(){ if(count>0){ front=(front+1)%size; count--; } }
    int peek(){ return (count>0)?arr[front]:-1; }
    bool empty(){ return count==0; }
};

int main(){
    CircularQueue cq(5);
    cq.enqueue(1); cq.enqueue(2); cq.enqueue(3);
    cout<<cq.peek()<<"\n";
    cq.dequeue();
    cout<<cq.peek()<<"\n";
}

