class Solution {
  public:
    vector<int> findClosestElements(vector<int> &arr, int k, int x) {
        int i = 0, j = arr.size() - 1;
        while (j - i >= k) {
            if (x - arr[i] > arr[j] - x) {
                i++;
            } else {
                j--;
            }
        }
        return vector<int>(arr.begin() + i, arr.begin() + j + 1);
    }
};

class Solution {
  public:
    vector<int> findClosestElements(vector<int> &A, int k, int x) {
        int left = 0, right = A.size() - k;
        while (left < right) {
            int mid = (left + right) / 2;
            if (x - A[mid] > A[mid + k] - x)
                left = mid + 1;
            else
                right = mid;
        }
        return vector<int>(A.begin() + left, A.begin() + left + k);
    }
};