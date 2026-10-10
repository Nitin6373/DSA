class Solution {
public:
    bool Helper(vector<vector<int>>& arr, int k, int guess) {
        int Count = 0;

        int Row = arr.size() - 1;
        int n = arr[0].size();
        int Col = 0;

        while (Row >= 0 && Col < n) {
            if (arr[Row][Col] > guess) {
                Row--;
            } else {
                Count += Row + 1;
                Col++;
            }
        }

        if (Count >= k)
            return true;
        return false;
    }
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int Rows = matrix.size();
        int Cols = matrix[0].size();
        int Res = -1;

        int low = matrix[0][0];
        int high = matrix[Rows - 1][Cols - 1];

        while(low <= high){
            int Guess = (low + high)/2;
            if(Helper(matrix,k,Guess)){
                Res = Guess;
                high = Guess - 1;
            }
            else
                low = Guess + 1;
        }

        return Res;
    }
};