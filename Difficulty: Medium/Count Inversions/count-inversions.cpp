class Solution {
  public:
  int cnt=0;


void merge(vector<int>& arr, int low, int mid, int high) {
        // Create temp arrays
        vector<int> temp;
        int left = low, right = mid + 1;

        // Merge two sorted halves
        while (left <= mid && right <= high) {
            if (arr[left] <= arr[right])
                temp.push_back(arr[left++]);
            else{
                cnt+=(mid - left + 1);temp.push_back(arr[right++]);
            }
                
        }

        // Copy remaining elements from left half
        while (left <= mid)
            temp.push_back(arr[left++]);

        // Copy remaining elements from right half
        while (right <= high){
            temp.push_back(arr[right++]);
        }

        // Copy sorted elements back to original array
        for (int i = low; i <= high; i++)
            arr[i] = temp[i - low];
    }

    // Recursive merge sort function
    void mergeSort(vector<int>& arr, int low, int high) {
        if (low >= high)
            return;

        // Find the middle index
        int mid = (low + high) / 2;

        // Recursively sort left half
        mergeSort(arr, low, mid);

        // Recursively sort right half
        mergeSort(arr, mid + 1, high);


        // Merge the two sorted halves
        merge(arr, low, mid, high);
    }
    int inversionCount(vector<int> &arr) {
        // Code Here
        if(arr.empty()) return 0;
        mergeSort(arr,0,arr.size()-1);
        return cnt;
    }
};