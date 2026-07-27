class Solution { 
public: 
    int singleNonDuplicate(vector<int>& nums) { 
        int n = nums.size(); 
        
        // Edge cases for boundary elements
        if (n == 1) return nums[0]; 
        if (nums[0] != nums[1]) return nums[0]; 
        if (nums[n-1] != nums[n-2]) return nums[n-1]; 
        
        int low = 1; 
        int high = n - 2; 
        
        while (low <= high) { 
            int mid = low + (high - low) / 2; 
            
            // Check if mid is the single element
            if (nums[mid] != nums[mid-1] && nums[mid] != nums[mid+1]) { 
                return nums[mid]; 
            } 
            
            // Check if we are in the left half
            if ((mid % 2 == 1 && nums[mid] == nums[mid-1]) || 
                (mid % 2 == 0 && nums[mid] == nums[mid+1])) { 
                low = mid + 1; // Eliminate left half
            } else { 
                high = mid - 1; // Eliminate right half
            } 
        } 
        
        return -1; // Fallback return statement to satisfy the compiler
    } 
};
