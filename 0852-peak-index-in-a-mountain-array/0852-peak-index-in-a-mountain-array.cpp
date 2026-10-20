class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int st = 0;
        int end = arr.size() - 1;

        while (st < end) {
            int mid = st + (end - st) / 2;

            if (arr[mid] < arr[mid + 1]) {
                st = mid + 1; // On the rising slope -> peak is to the right
            } else {
                end = mid;     // On the falling slope (or at peak) -> peak is here or to the left
            }
        }
        return st;
    }
};