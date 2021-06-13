// https://www.interviewbit.com/problems/max-sum-contiguous-subarray/
#include <iostream>
#include <vector>
using namespace std;

int solve(const vector<int> &arr) {
  int maxSum = arr[0];
  int sum = arr[0];
  for (int i = 1; i < (int)arr.size(); i++) {
    sum = max(sum, sum + arr[i]);
    maxSum = max(maxSum, sum);
  }
  return maxSum;
}

int main() {
  cout << "working" << endl;
  int n;
  cin >> n;
  vector<int> v(n);
  for (int i = 0; i < n; i++) {
    cin >> v[i];
  }
  cout << solve(v) << endl;
  return 0;
}
