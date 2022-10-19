#include <iostream>
#include <vector>
using namespace std;

void print(vector<vector<int>> v) {
  for (auto v1 : v) {
    for (auto v2 : v1) {
      cout << v2 << " ";
    }
    cout << endl;
  }
}

vector<vector<int>> maxPooling(vector<vector<int>> feature_map, int kernel_h,
                               int kernel_w, int stride_h, int stride_w) {
  int feat_h = feature_map.size(), feat_w = feature_map[0].size();
  int out_h = (feat_h - kernel_h) / stride_h + 1;
  int out_w = (feat_w - kernel_w) / stride_w + 1;
  int mod_h = (feat_h - kernel_h) % stride_h;
  int mod_w = (feat_w - kernel_w) % stride_w;
  if (mod_h) out_h++;
  if (mod_w) out_w++;
  vector<vector<int>> out_feat(out_h, vector<int>(out_w));
  vector<vector<int>> pad_feat(feature_map);
  if (mod_w) {
    for (int i = 0; i < feat_h; i++) {
      for (int j = 0; j < stride_w - mod_w; j++) {
        pad_feat[i].push_back(pad_feat[i][feat_w - 1]);
      }
    }
  }
  if (mod_h) {
    for (int i = 0; i < stride_h - mod_h; i++) {
      pad_feat.push_back(pad_feat[feat_h - 1]);
    }
  }
  print(pad_feat);

  for (int i = 0; i < out_h; i++) {
    for (int j = 0; j < out_w; j++) {
      int start_h = i * stride_h;
      int start_w = j * stride_w;
      int max_v = pad_feat[start_h][start_w];
      for (int kernel_i = 0; kernel_i < kernel_h; kernel_i++) {
        for (int kernel_j = 0; kernel_j < kernel_w; kernel_j++) {
          max_v = max(max_v, pad_feat[start_h + kernel_i][start_w + kernel_j]);
        }
      }
      out_feat[i][j] = max_v;
    }
  }
  return out_feat;
}

int main() {
  vector<vector<int>> feature_map = {{0, 1, 2, 3, 4},
                                     {5, 6, 7, 8, 9},
                                     {9, 10, 11, 12, 13},
                                     {9, 10, 11, 12, 13},
                                     {9, 10, 11, 12, 13}};
  auto res = maxPooling(feature_map, 2, 2, 2, 2);
  // auto res = maxPooling(feature_map, 3, 3, 3, 3);

  print(res);
  return 0;
}