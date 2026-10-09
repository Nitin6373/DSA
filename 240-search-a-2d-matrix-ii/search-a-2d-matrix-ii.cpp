class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int Row = matrix.size() - 1;
        int Col = 0;
        int n = matrix[0].size() - 1;

        while(Row >= 0 && Col <=  n){
            if(matrix[Row][Col] == target)
                return true;

            if(matrix[Row][Col] > target)
                Row--;
            else 
                Col++;
        }
        return false;
    }
};