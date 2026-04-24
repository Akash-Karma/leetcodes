class Solution {
public:
    int maxArea(vector<int>& height) {
        int l=0, r=height.size()-1, maxi=0;
        while(l<r){
            int area=min(height[l],height[r]) * (r-l);
            maxi=max(area,maxi);
            if(height[l]>=height[r]) r--;
            else  l++;

        }
        return maxi;
    }
};