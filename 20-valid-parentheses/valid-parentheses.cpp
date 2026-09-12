class Solution {
public:
    bool isValid(string s) {
        stack<char> st;

        for(int i=0;i<s.size();i++){
            if(s[i] == '(' || s[i] == '{' || s[i] == '['){ // Means Opening Brackets 
                st.push(s[i]);
            }
            else{ // Means Closing Brackets Found
                if(!st.empty()){
                    if(s[i] == ')' && st.top() == '('){
                        st.pop();
                    }
                    else if(s[i] == '}' && st.top() == '{'){
                        st.pop();
                    }
                    else if(s[i] == ']' && st.top() == '['){
                        st.pop();
                    }
                    else{
                        return false;
                    }
                    continue;
                }
                return false;
            }
        }
        if(!st.empty()){
            return false;
        }
        return true;
    }
};