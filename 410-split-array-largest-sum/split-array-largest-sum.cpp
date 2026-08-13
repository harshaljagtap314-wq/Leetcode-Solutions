class Solution {
public:

    int ispossible(vector<int> nums,int k,int splitmax){
        int sum=0;
        int arrnum=1;

        for(int i=0;i<nums.size();i++){

            if(sum + nums[i]<=splitmax){
                sum+=nums[i];
                
            }else{
                sum=nums[i];
                arrnum++;
            }
        }
        return arrnum;
    }





    int splitArray(vector<int>& nums, int k) {

       

        int low=*max_element(nums.begin(),nums.end());
        int high=accumulate(nums.begin(),nums.end(),0);

        while(low<=high){
            int mid = low + (high-low)/2;

            int ans=ispossible(nums,k,mid);

            if(ans > k){
                low=mid+1;

            }else{
                high=mid-1;
            }
            
        }
        return low;
    }
};