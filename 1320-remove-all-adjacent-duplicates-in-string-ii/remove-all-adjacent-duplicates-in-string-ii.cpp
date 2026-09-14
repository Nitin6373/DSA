class Solution {
public:
    string removeDuplicates(string s, int k) {
        stack<pair<int,int>> st;
        string Res;

        st.push({s[0],1});

        for(int i=1;i<s.size();i++){

            if(!st.empty() && st.top().first == s[i]){
                if(st.top().second == (k-1)){
                    st.pop();
                }   
                else{
                    st.top().second++;
                }
            }
            else{
                st.push({s[i],1});
            }
        }

        while(!st.empty()){
            while(st.top().second){
                Res.push_back(st.top().first);
                st.top().second--;
            }
            st.pop();
        }

        reverse(Res.begin(),Res.end());

        return Res;
    }
};