class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        
        unordered_map<string,string> fs;

        for(int i=0;i<knowledge.size();i++){
            fs[knowledge[i][0]] = knowledge[i][1];
        }

        string Key = "";
        string Ans = "";
        bool Open = false;

        for(int i=0;i<s.size();i++){
            if(s[i] == '('){
                Open = true;
                continue;
            }
            if(s[i] == ')'){
                Open = false;
                if(fs.find(Key) == fs.end()){
                    Ans += "?";
                }
                else{
                    Ans += fs[Key];
                }
                Key = "";
                continue;
            }

            if(Open){
                Key += s[i];
                continue;
            }
            Ans += s[i];
        }

        return Ans;
    }
};