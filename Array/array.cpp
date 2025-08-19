#include <iostream>
using namespace std;

class Array {
    int arr[100];
    int n;
public:
    Array(int a[], int size) {
        n = size;
        for(int i=0;i<size;i++) arr[i]=a[i];
    }
    void insertBeforeIndex(int idx, int val) {
        for(int i=n;i>idx;i--) arr[i]=arr[i-1];
        arr[idx]=val; n++;
    }
    void insertBeforeValue(int x, int val) {
        int idx=-1; for(int i=0;i<n;i++) if(arr[i]==x){ idx=i; break; }
        for(int i=n;i>idx;i--) arr[i]=arr[i-1];
        arr[idx]=val; n++;
    }
    void deleteBeforeIndex(int idx) {
        for(int i=idx-1;i<n-1;i++) arr[i]=arr[i+1]; n--;
    }
    void deleteBeforeValue(int x) {
        int idx=-1; for(int i=0;i<n;i++) if(arr[i]==x){ idx=i; break; }
        for(int i=idx-1;i<n-1;i++) arr[i]=arr[i+1]; n--;
    }
    void display() {
        for(int i=0;i<n;i++) cout<<arr[i]<<" "; cout<<"\n";
    }
};

int main() {
    int a[]={1,2,3,4,5};
    Array arr(a,5);
    arr.insertBeforeIndex(2,99);
    arr.display();
    arr.insertBeforeValue(4,77);
    arr.display();
    arr.deleteBeforeIndex(3);
    arr.display();
    arr.deleteBeforeValue(5);
    arr.display();
}

