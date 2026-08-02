class Solution {
public:


    long long calculateTotalhour(vector<int> piles,int speed){
        long long totalh=0;
        for(int banana : piles){
          totalh += (banana + speed - 1) / speed;        
        }
          return totalh;
    }


    int minEatingSpeed(vector<int>& piles, int h) {
        
        int maxi=*max_element(piles.begin(),piles.end());

        int low=1;
        int high=maxi;

        while(low<=high){
            int mid=low + (high-low)/2;

            long long totalh=calculateTotalhour(piles,mid);

            if(totalh<=h){
                high=mid-1;
            }else{
                low=mid+1;
            }
        }
        
        return low;

    }
};