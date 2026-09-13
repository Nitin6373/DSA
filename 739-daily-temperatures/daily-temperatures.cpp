class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {

        int n = temperatures.size();
        vector<int> Res(n);
        Res[n-1] = 0;

        stack<int> st;
        st.push(n-1);

        for(int i = n - 2 ; i >= 0 ; i--){
            while(!st.empty()){
                if(temperatures[st.top()] > temperatures[i]){
                    Res[i] = st.top() - i;
                    break;
                }
                else{
                    st.pop();
                }
            }
            if(st.empty()){
                Res[i] = 0;
            }
            st.push(i);
        }
        return Res;
    }
};