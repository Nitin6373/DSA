class Solution {
public:
    int maxArea(vector<int>& height) {
        int MA = 0;
        int Left = 0;
        int Right = height.size() - 1;

        while(Left <= Right){
            int Area = min(height[Left],height[Right]) * (Right-Left);
            MA = max(MA,Area);
            if(min(height[Left],height[Right]) == height[Left]){
                Left++;
            }
            else{
                Right--;
            }
        }

        return MA;
    }
};