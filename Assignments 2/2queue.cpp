#include<bits/stdc++.h>
using namespace std;

template<class datatype>

class STACK{
private:
    queue<datatype> s1;
    queue<datatype> s2;

public:
    bool isEmpty() {
        return s2.empty();
    }
    void push(datatype x) {
        while(!s2.empty()) {
            s1.push(s2.front());
            s2.pop();
        }
        s2.push(x);
        while(!s1.empty()){
            s2.push(s1.front());
            s1.pop();
        }
    }
    datatype pop() {
        if(s2.empty())
        {
            exit(EXIT_FAILURE);
        }
        datatype tmp = s2.front();
        s2.pop();
        return tmp;
    }
    datatype peek() {
        if(s2.empty()) {
            exit(EXIT_FAILURE);
        }
        return s2.front();
    }
    int SIZE(){
        return s2.size();
    }
};
int main(){
    STACK<int> s;
    int n; cin >> n;
    for(int i = 0; i < n; i++){
        int x; cin >> x;
        s.push(x);
    }
    while(!s.isEmpty()){
        cout<< s.pop() <<endl;
    }
    cout<< s.peek();
    return 0;
}