class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        stack<int> st;
        int n = nums.size();
        vector<int> Res(n);

        for(int i=n-2;i>=0;i--){
            st.push(nums[i]);
        }

        for(int i=n-1;i>=0;i--){
            while(!st.empty()){
                if(st.top() > nums[i]){
                    Res[i] = st.top();
                    break;
                }
                else{
                    st.pop();
                }
            }

            if(st.empty()){
                Res[i] = -1;
            }

            st.push(nums[i]);
        }
        return Res;
    }
};