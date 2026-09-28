class Solution {
public:
    int maxDepth(string s) {
        int Count = 0;
        int Res = 0;

        for(int i=0;i<s.size();i++){
            if(s[i] == '('){
                Count++;
                Res = max(Res,Count);
            }
            else if(s[i] == ')'){
                Count--;
            }
        }

        return Res;
    }
};