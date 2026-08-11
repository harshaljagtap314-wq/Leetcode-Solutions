class Solution {
public:

bool ispossible(vector<int> &position,int dist,int cownum){
    int cowcount=1;
    int lastpos=position[0];

    for(int i=1;i<position.size();i++){
        if(position[i] - lastpos >= dist){
            cowcount++;
            lastpos=position[i];
        }
    }

    return cowcount>=cownum;
}
    int maxDistance(vector<int>& position, int m) {

        sort(position.begin(),position.end());
    int maxi=*max_element(position.begin(),position.end());
    int mini=*min_element(position.begin(),position.end());
        int low=1;
        int high= maxi-mini;
        int ans=1;


        while(low<=high){
            int mid= low + (high-low)/2;

            if(ispossible(position,mid,m)){
                ans=max(ans,mid);
                low=mid+1;
            }else{
                high=mid-1;
            }
        }
        return ans;
        
    }
};