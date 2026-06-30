class Solution {
public:
// Harshal
    int maxProduct(vector<int>& nums) {
        int n=nums.size();
        int maxi=INT_MIN;
        int preffix=0,suffix=0;

        for(int i=0;i<n;i++){
            if(preffix == 0) preffix=1;
            if(suffix == 0) suffix  =1;

            preffix*=nums[i];
            suffix*=nums[n-i-1];

            maxi=max(maxi,max(preffix,suffix));
        }
        return maxi;
    }
};