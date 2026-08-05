class Solution {
public:

  bool  possible(vector<int> bloomDay,int day,int m,int k){
        int count=0;
        int noofbou=0;

        for(int i=0;i<bloomDay.size();i++){
            if(day>=bloomDay[i]){
                count++;
            }else{
                noofbou+=count/k;
                count=0;
            }
        }
         noofbou+=count/k;

        return noofbou>=m;
    }



    int minDays(vector<int>& bloomDay, int m, int k) {
        long long val=(long long)m*k;
        if(val>bloomDay.size()) return -1;

        int minday=*min_element(bloomDay.begin(),bloomDay.end());
        int maxday=*max_element(bloomDay.begin(),bloomDay.end());


        int low=minday;
        int high=maxday;
        int ans=-1;

        while(low<=high){
            int mid= low + (high-low)/2;

            if(possible(bloomDay,mid,m,k)){
                ans=mid;
                high=mid-1;
            }else{
                low=mid+1;
            }
        }
        return ans;
    }
};