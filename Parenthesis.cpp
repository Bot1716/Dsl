#include <iostream>
#include <stack>
#include <string>
using namespace std;
bool isWellParenthesized(const string& expression) {
    stack<char> s;
    for(char ch : expression){
        if(ch=='(' || ch=='[' || ch=='{' ){
            s.push(ch);
        }
        else if(ch==')' || ch==']' || ch=='}' ){
            if(s.empty()){
                return false;
            }
            char top = s.top();
            s.pop();
            if(ch==')' && top!='(' || ch=='}' && top!='{' || ch==']' && top!='['){
                return false;
            }
        }
    }
    return s.empty();
}
int main() {
    string expression;
    cout<<"Enter an expression to check whether it is well parenthisized or not ";
    getline(cin,expression);
    if(isWellParenthesized(expression)){
        cout<<"This expression is well parenthisized";
    }
    else{
        cout<<"This expression is not well parenthisized";
    }
    return 0;
}
