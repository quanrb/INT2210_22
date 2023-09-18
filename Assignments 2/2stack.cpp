#include<bits/stdc++.h>
using namespace std;

template<class datatype>

class QUEUE{
private:
    stack<datatype> s1;
    stack<datatype> s2;

public:
    bool isEmpty() {
        return s2.empty();
    }
    void enqueue(datatype x) {
        while(!s2.empty()) {
            s1.push(s2.top());
            s2.pop();
        }
        s2.push(x);
        while(!s1.empty()){
            s2.push(s1.top());
            s1.pop();
        }
    }
    datatype dequeue() {
        if(s2.empty())
        {
            exit(EXIT_FAILURE);
        }
        datatype tmp = s2.top();
        s2.pop();
        return tmp;
    }
    datatype peek() {
        if(s2.empty()) {
            exit(EXIT_FAILURE);
        }
        return s2.top();
    }
    int SIZE(){
        return s2.size();
    }
};
int main(){
    QUEUE<int> q;
    int n; cin >> n;
    for(int i = 0; i < n; i++){
        int x; cin >> x;
        q.enqueue(x);
    }
    while(!q.isEmpty()){
        cout<<q.dequeue()<<endl;
    }
    cout<<q.peek();
    return 0;
}