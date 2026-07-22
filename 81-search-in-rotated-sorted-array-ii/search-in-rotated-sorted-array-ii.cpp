class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int low=0;
        int high=nums.size()-1;

        while(low<=high){
            int mid=low + (high-low)/2;

            if(nums[mid] == target){
                return true;
            }
            // If we have duplicates in our array:-
            //We shrink the array lenght
            if(nums[mid] == nums[high] && nums[mid] == nums[low]){
                low++;
                high--;
                continue;
            }
            //If left us sorted
              if(nums[mid]>=nums[low]){
                if(nums[low]<=target && nums[mid]>=target){
                    high=mid-1;
                }else {
                    low=mid+1;
                }
             }
             //If right is sorted
            else {
                if(nums[mid]<=target && nums[high]>=target){
                    low=mid+1;
                }else{
                    high=mid-1;
                }
            }
        }

        return false;
    }
};