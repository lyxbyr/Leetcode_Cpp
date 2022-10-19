#include <iostream>
#include <vector>
using namespace std;
void swap(vector<int>& arr, int i, int j) {
  int tmp = arr[i];
  arr[i] = arr[j];
  arr[j] = tmp;
}

void heapInsert(vector<int>& arr, int index) {
  while (arr[index] > arr[(index - 1) / 2]) {
    swap(arr, index, (index - 1) / 2);
    index = (index - 1) / 2;
  }
}

void heapify(vector<int>& arr, int index, int heapSize) {
  int left = index * 2 + 1;
  int right = index * 2 + 2;
  while (left < heapSize) {
    /* code */
    int largest =
        left + 1 < heapSize && arr[left] < arr[left + 1] ? left + 1 : left;
    largest = arr[largest] > arr[index] ? largest : index;
    if (largest == index) {
      break;
    }
    swap(arr, largest, index);
    index = largest;
    left = index * 2 + 1;
  }
}

void heapSort(vector<int>& arr) {
  if (arr.empty() || arr.size() < 2) return;
  for (int i = 0; i < arr.size(); i++) {
    heapInsert(arr, i);
  }
  int heapSize = arr.size();
  swap(arr, 0, --heapSize);
  while (heapSize > 0) {
    heapify(arr, 0, heapSize);
    swap(arr, 0, --heapSize);
  }
}

int main() {
  vector<int> nums = {3, 6, 61, 17, 9, 0};
  heapSort(nums);
  for (auto num : nums) {
    cout << num << " ";
  }
  cout << endl;
  return 0;
}
