#include <iostream>
#include <vector>
using namespace std;

void merge(vector<int>& arr, int L, int m, int R) {
  int* help = new int[R - L + 1];
  int i = 0;
  int p1 = L, p2 = m + 1;
  while (p1 <= m && p2 <= R) {
    help[i++] = arr[p1] < arr[p2] ? arr[p1++] : arr[p2++];
  }
  while (p1 <= m) {
    help[i++] = arr[p1++];
  }
  while (p2 <= R) {
    help[i++] = arr[p2++];
  }
  for (int i = 0; i < R - L + 1; i++) {
    arr[L + i] = help[i];
  }
  delete[] help;
}

void mergeSort(vector<int>& arr, int L, int R) {
  if (L == R) {
    return;
  }
  int mid = L + ((R - L) >> 1);
  mergeSort(arr, L, mid);
  mergeSort(arr, mid + 1, R);
  merge(arr, L, mid, R);
}

void mergeSort(vector<int>& arr) {
  if (arr.empty() || arr.size() < 2) return;
  mergeSort(arr, 0, arr.size() - 1);
}

int main() {
  vector<int> nums = {3, 5, 6, 7, 9, 0};
  mergeSort(nums);
  for (auto num : nums) {
    cout << num << " ";
  }
  cout << endl;
  return 0;
}
