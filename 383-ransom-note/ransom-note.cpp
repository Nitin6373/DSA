class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char,int> fm;
        unordered_map<char,int> fr;

        for(int i=0;i<magazine.size();i++){
            fm[magazine[i]]++;
        }

        for(int i=0;i<ransomNote.size();i++){
            fr[ransomNote[i]]++;
            if(fr[ransomNote[i]] > fm[ransomNote[i]]){
                return false;
            }
        }

        return true;
    }
};