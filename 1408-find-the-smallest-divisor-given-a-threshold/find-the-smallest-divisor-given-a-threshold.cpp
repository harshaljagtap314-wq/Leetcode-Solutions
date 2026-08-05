class Solution {
public:

    bool possibledivisor(vector<int> &nums,int ele,int threshold){
        int sum=0;
        
        for(int i=0;i<nums.size();i++){
            sum+=ceil((double) nums[i]/ele);

        }
        
         if(sum<=threshold){
                return true;
            }

        return false;
    }

    int smallestDivisor(vector<int>& nums, int threshold) {

        int low=1;
        int high=*max_element(nums.begin(),nums.end());
        int ans=0;

        while(low<=high){
        int mid= low + (high-low)/2;

            if(possibledivisor(nums,mid,threshold)){
                ans=mid;
                high=mid-1;
            }else{
                low=mid+1;
            }
        }
        return ans;
    }
};