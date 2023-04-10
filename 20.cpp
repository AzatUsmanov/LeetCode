#include<stack>
class Solution {
public:
    bool isValid(string s) {
        stack<int> stack;
        for(int i = 0; i < s.length(); i++){
            switch(s[i]){
                case '(':{
                    stack.push(s[i]);
                }
                break; 
                case '[':{
                    stack.push(s[i]);
                }
                break;
                 case '{':{
                    stack.push(s[i]);
                }
                break;
                 case ')':{
                    if (!stack.empty() && stack.top() == '('){
                        stack.pop();
                    } else return false;
                }
                break;
                 case ']':{
                    if (!stack.empty() && stack.top() == '['){
                        stack.pop();
                    } else return false;
                }
                break;
                 case '}':{
                    if (!stack.empty() && stack.top() == '{'){
                        stack.pop();
                    } else return false;
                }
                break;
            }
        }
        return stack.empty() && true;
    }
};