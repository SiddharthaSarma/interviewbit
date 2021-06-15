// https://www.interviewbit.com/problems/partitions/
#include <iostream>
#include <vector>
using namespace std;

int solve(vector<int> &arr) {
  int sum = 0;
  int ways = 0;
  int n = arr.size();
  for (int a : arr) {
    sum += a;
  }
  if (sum % 3 != 0) {
    return ways;
  }
  sum /= 3;
  vector<int> suffixSum(n);
  int tempSum = 0;
  for (int i = n - 1; i >= 0; i--) {
    tempSum += arr[i];
    suffixSum[i] = tempSum == sum ? 1 : 0;
  }
  for (int i = n - 2; i >= 0; i--) {
    suffixSum[i] += suffixSum[i + 1];
  }
  tempSum = 0;
  for (int i = 0; i + 2 < n; i++) {
    tempSum += arr[i];
    if (tempSum == sum) {
      ways += suffixSum[i + 2];
    }
  }
  return ways;
}

int main() {
  int n;
  cin >> n;
  vector<int> v(n);
  for (int i = 0; i < n; i++) {
    cin >> v[i];
  }
  cout << solve(v) << endl;
}
