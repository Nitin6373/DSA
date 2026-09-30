class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {

        int low = 0;
        int high = arr.size() - 1;
        int Res = -1;

        while(low < high){
            int Guess = (low + high) / 2;

            if(arr[Guess] > arr[Guess + 1]){
                high = Guess;
                Res = Guess;
                continue;
            }

            if(arr[Guess] < arr[Guess + 1]){
                low = Guess + 1;
            }
        }

        return Res;
    }
};