class Solution {
    public:
        double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
           
            vector<int> merged(nums1.begin(), nums1.end());
            merged.insert(merged.end(), nums2.begin(), nums2.end());
            
          
            sort(merged.begin(), merged.end());
            
            int size = merged.size();
            if (size == 0) return 0.0; // Handle empty input edge case
            
            
            if (size % 2 == 0) {
                return (merged[size / 2] + merged[(size / 2) - 1]) / 2.0;
            } else {
                return merged[size / 2];
            }
        }
    };
    