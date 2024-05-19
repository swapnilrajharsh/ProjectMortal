class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int left = m-1, right = n-1, idx = m+n-1;

        while (left >= 0 && right >= 0) {
            if (nums1[left] >= nums2[right]){
                nums1[idx] = nums1[left];
                left--;
                idx--;
            } else {
                nums1[idx] = nums2[right];
                right--;
                idx--;
            }
        }

        while (left >= 0) {
            nums1[idx] = nums1[left];
            left--;
            idx--;
        }

        while (right >= 0) {
            nums1[idx] = nums2[right];
            right--;
            idx--;
        }
    }
};