#include <iostream>
using namespace std;

class PriorityQueue {
    int *arr, size, count;
public:
    PriorityQueue(int n){ size=n; arr=new int[size]; count=0; }
    void enqueue(int x){
        if(count<size){ arr[count++]=x; for(int i=count-1;i>0;i--) if(arr[i]>arr[i-1]) swap(arr[i],arr[i-1]); }
    }
    void dequeue(){ if(count>0){ for(int i=0;i<count-1;i++) arr[i]=arr[i+1]; count--; } }
    int peek(){ return (count>0)?arr[0]:-1; }
    bool empty(){ return count==0; }
};

int main(){
    PriorityQueue pq(5);
    pq.enqueue(10); pq.enqueue(50); pq.enqueue(30);
    cout<<pq.peek()<<"\n";
    pq.dequeue();
    cout<<pq.peek()<<"\n";
}

