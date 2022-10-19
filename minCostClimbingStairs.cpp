int minCostClimbingStairs(vector<int>& cost) {
  vector<int> dp(cost.size() + 1);
  dp[0] = 0;
  dp[1] = 0;
  for (int i = 2; i < cost.size(); i++) {
    dp[i] = min(dp[i - 1] + cost[i - 1], dp[i - 2] + cost[i - 2]);
  }
  return dp[cost.size()];
}

// dfs
int dfs(int i, int j, int m, int n) {
  if (i >= m || j > n) return 0;
  if (i == m && j == n) return 1;
  return dfs(i + 1, j, m, n) + dfs(i, j + 1, m, n);
}

int uniquePaths(int m, int n) { return dfs(1, 1, m, n); }
// dp
int uniquePaths(int m, int n) {
  vector<vector<int>> dp(m, vector<int>(n, 0));
  for (int i = 0; i < m; i++) dp[i][0] = 1;
  for (int j = 0; j < n; j++) dp[0][j] = 1;
  for (int i = 1; i < m; i++) {
    for (int j = 1; j < n; j++) {
      dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
    }
  }
  return dp[m - 1][n - 1];
}

int uniquePaths(int m, int n) {
  vector<int> dp(n);
  for (int i = 0; i < n; i++) dp[i] = 1;
  for (i = 1; i < m; i++) {
    for (j = 1; j < n; j++) {
      dp[j] += dp[j - 1];
    }
  }
  return dp[n - 1];
}

int uniquePathWithObstacles(vector<vector<int>>& obstacleGrid) {
  int m = obstacleGrid.size();
  int n = obstacleGrid[0].size();
  if (obstacleGrid[m - 1][n - 1] == 1 || obtacleGrid[0][0] == 1) return 0;
  vector<vector<int>> dp(m, vector<int>(n, 0));
  for (int i = 0; i < m && obstacleGrid[i][0] == 0; i++) dp[i][0] = 1;
  for (int j = 0; j < n && obstacleGrid[0][j] == 0; j++) dp[0][j] = 1;
  for (int i = 1; i < m; i++) {
    for (int j = 1; j < n; j++) {
      if (obstacleGrid[i][j] == 1) continue;
      dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
    }
  }
  return dp[m - 1][n - 1];
}

class MyStack() {
 private:
  queue<int> q;

 public:
  MyStack() {}

  void push(int x) { q.push(x); }
  int pop() {
    int n = q.size() - 1;
    while (n--) {
      q.push(q.front());
      q.pop();
    }
    int res = q.front();
    q.pop();
    return res;
  }

  int top() { return q.back(); }

  bool empty() { return q.empty(); }
};

class MyQueue {
 private:
  stack<int> s1, s2;

 public:
  MyQueue() {}

  void push(int x) { s1.push(x); }

  int pop() {
    if (s2.empty()) {
      while (!s1.empty()) {
        s2.push(s1.top());
        s1.pop();
      }
    }
    int res = s2.top();
    s2.pop();
    return res;
  }

  int peek() {
    int cur = this->pop();
    s2.push(cur);
    return cur;
  }

  bool empty() { return s1.empty() && s2.empty(); }
};

struct Box{
  /* data */
  float left, top, right, bottom, confidence;
  int class_label;
  BoxArray() = default;
  BoxArray(float left, float top, float right, float bottom, float confidence,
           int class_label)
      : left(left),
        top(top),
        right(right),
        bottom(bottom),
        confidence(confidence),
        class_label(class_label) {}

};
typedef std::vector<Box> BoxArray;

BoxArray nms(BoxArray& boxs, float threshold) {
  std::sort(boxs.begin(), boxs.end(),
            [](BoxArray const_reference a, BoxArray const_reference b) {
              return a.confidence > b.confidence
            });
  vector<int> remove_flag(boxs.size());
  BoxArray output;
  output.reserve(boxs.size());
  for (int i = 0; i < boxs.size(); i++) {
    if (remove_flag[i]) continue;
    auto& a = boxs[i];
    output.push_back(a);
    for (int j = i + 1; j < boxs.size(); j++) {
      if (remove_flag[j]) continue;
      auto& b = boxs[j];
      if (b.class_label == a.class_label) {
        if (iou(b, a) > threshold) {
          remove_flag[j] = true;
        }
      }
    }
  }
  return output;
}