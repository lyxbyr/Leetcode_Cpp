#include <iostream>
#include <vector>
using namespace std;
void swap(vector<int>& arr, int i, int j) {
  int tmp = arr[i];
  arr[i] = arr[j];
  arr[j] = tmp;
}

vector<int> partition(vector<int>& arr, int L, int R) {
  int less = L - 1;
  int more = R;
  while (L < more) {
    if (arr[L] < arr[R]) {
      swap(arr, ++less, L++);
    } else if (arr[L] > arr[R]) {
      swap(arr, --more, L);
    } else {
      L++;
    }
  }
  swap(arr, more, R);
  return {less + 1, more};
}

void quickSort(vector<int>& arr, int L, int R) {
  if (L < R) {
    auto p = partition(arr, L, R);
    quickSort(arr, L, p[0] - 1);
    quickSort(arr, p[1] + 1, R);
  }
}

void quickSort(vector<int>& arr) {
  if (arr.empty() || arr.size() < 2) return;
  quickSort(arr, 0, arr.size() - 1);
}

int main() {
  vector<int> nums = {3, 5, 6, 7, 9, 0};
  quickSort(nums);
  for (auto num : nums) {
    cout << num << " ";
  }
  cout << endl;
  return 0;
}
