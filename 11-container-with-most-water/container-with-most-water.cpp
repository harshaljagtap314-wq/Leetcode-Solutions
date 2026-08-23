class Solution {
public:
    int maxArea(vector<int>& height) {
        int maxi=INT_MIN;
        int n=height.size();
        int j=n-1;
        double area=-1;
        int i=0;

while(i < j) {
    area = min(height[i], height[j]) * (j - i);

    maxi = max(maxi, (int)area);

    if(height[i] < height[j]) {
        i++;
    } else {
        j--;
    }
}

return maxi;
    }
};