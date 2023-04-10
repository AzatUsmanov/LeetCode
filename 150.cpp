#include <stack>
#include <string>
class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> stack;
        int a = 0, b = 0;
         for(int i = 0; i < tokens.size(); i++){
             if (tokens[i] == "+"){
                a = stack.top();
                stack.pop();
                b = stack.top();
                stack.pop();
                stack.push(b + a);
             } else if (tokens[i] == "-"){
                a = stack.top();
                stack.pop();
                b = stack.top();
                stack.pop();
                stack.push(b - a);
             } else if (tokens[i] == "*"){
                a = stack.top();
                stack.pop();
                b = stack.top();
                stack.pop();
                stack.push(b * a);
             } else if (tokens[i] == "/"){
                 a = stack.top();
                stack.pop();
                b = stack.top();
                stack.pop();
                stack.push(b / a);
             } else {
                 stack.push(stoi(tokens[i]));
             }
        }
        return stack.top();
    }
};