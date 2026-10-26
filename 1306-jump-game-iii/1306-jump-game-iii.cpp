class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        int n = arr.size();
        if (start >= n || start < 0)
            return 0;
        if (arr[start] == 0)
            return 1;
        if (arr[start] == -1)
            return 0;
        int jump = arr[start];
        arr[start] = -1;
        return canReach(arr, start + jump) || canReach(arr, start - jump);
    }
};