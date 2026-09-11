class Solution {
public:
    string removeDuplicates(string s) {
        stack<char> st;
        string Res;

        st.push(s[0]);
        Res.push_back(s[0]);

        int i = 1;
        while(i < s.size()){
            if(!st.empty() && st.top() == s[i]){
                st.pop();
                Res.pop_back();
            }
            else{
                st.push(s[i]);
                Res.push_back(s[i]);
            }
            i++;
        }

        return Res;
    }
};