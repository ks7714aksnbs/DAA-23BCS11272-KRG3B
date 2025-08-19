#include <iostream>
#include <stack>
using namespace std;

class ParenthesisChecker {
public:
    bool check(string s){
        stack<char> st;
        for(char c:s){
            if(c=='('||c=='{'||c=='[') st.push(c);
            else{
                if(st.empty()) return false;
                if((c==')'&&st.top()!='(')||(c=='}'&&st.top()!='{')||(c==']'&&st.top()!='[')) return false;
                st.pop();
            }
        }
        return st.empty();
    }
};

int main(){
    ParenthesisChecker pc;
    cout<<(pc.check("{[()]}")?"Valid":"Invalid");
}

