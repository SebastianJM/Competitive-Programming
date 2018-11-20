class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& A) {
        int l = 0, r = A.size() - 1;
        while(l < r) {
            while(l < A.size() && (A[l] & 1) != 1)
                l++;
            while(r >= 0 && (A[r] & 1) == 1)
                r--;
            if(l < r && (A[l] & 1) && !(A[r] & 1)) {
                swap(A[l], A[r]);
                l++;
                r--;
            }     
        }
        return A;
    }
};