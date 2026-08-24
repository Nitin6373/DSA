class Solution {
public:
    int maximumSum(vector<int>& arr) {
        int Nodelete = arr[0];
        int OneDelete = INT_MIN;
        int Res = arr[0];
        int v2;

        for(int i=1;i<arr.size();i++){

            int PrevNoDelete = Nodelete ;
            Nodelete = max((Nodelete + arr[i]) , arr[i]);

            if(OneDelete == INT_MIN){
                v2 = arr[i];
            }
            else{
                v2 = OneDelete + arr[i];
            }

            OneDelete = max(v2 , PrevNoDelete);

            Res = max(Res , max(Nodelete,OneDelete));
        }
        return Res;
    }
};