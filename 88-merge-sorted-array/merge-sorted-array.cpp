class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int ptr1=0,ptr2=0, i=0;
        vector<int> nums3(m+n);
        while(ptr1<m && ptr2<n && i<m+n-1){
            if(nums1[ptr1]<=nums2[ptr2]){
                nums3[i]=nums1[ptr1];
                i++;
                ptr1++;
            }
            else{
                nums3[i]=nums2[ptr2];
                i++;
                ptr2++;
            }
        }
        while(ptr1<m){
            nums3[i]=nums1[ptr1];
            ptr1++;
            i++;
        }
        while(ptr2<n){
            nums3[i]=nums2[ptr2];
            ptr2++;
            i++;
        }
        nums1=nums3;
    }
};