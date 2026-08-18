class Solution {
public:
    bool backspaceCompare(string s, string t) {
        int First = s.size() - 1;
        int Second = t.size() - 1;
        int Skips = 0;
        int Skipt = 0;

        while (First >= 0 || Second >= 0) {

            // Till Valid Char in s
            while(First >= 0){
                if(s[First] == '#'){
                    First--;
                    Skips++;
                }
                else{
                    if(Skips > 0){
                        Skips--;
                        First--;
                    }
                    else{
                        break;
                    }
                }
            }

            // Till VAlid Char in t
            while(Second >= 0){
                if(t[Second] == '#'){
                    Second--;
                    Skipt++;
                }
                else{
                    if(Skipt > 0){
                        Skipt--;
                        Second--;
                    }
                    else{
                        break;
                    }
                }
            }

            // If Empty Strings
            if(First < 0 && Second < 0){
                return true;
            }

            // If One of them has valid char
            if(First < 0 || Second < 0){
                return false;
            }

            // Both have valid char but not the same
            if(s[First] != t[Second]){
                return false;
            }

            First--;
            Second--;
        }
        return true;
    }
};