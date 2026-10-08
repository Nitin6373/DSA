class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int low = 0;
        int high = (matrix.size() * matrix[0].size()) - 1;

        while(low <= high){
            int guess = (low + high)/2;
            int RowNo = guess / matrix[0].size();
            int ColNo = guess % matrix[0].size();

            if(matrix[RowNo][ColNo] == target)
                return true;

            if(matrix[RowNo][ColNo] > target)
                high = guess - 1;
            else
                low = guess + 1;
        }
        return false;
    }
};