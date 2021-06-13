// https://www.interviewbit.com/problems/maximum-sum-triplet/
#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

int maxLowerValue(set<int> &s, int m) {
  set<int>::iterator i;
  i = s.lower_bound(m);
  --i;
  return *i;
}

int maxTriplet(vector<int> & arr) {
  int ans = INT_MIN;
  int n = arr.size();
  int maxr[n + 1];
  maxr[n] = 0;
  for (int i = n - 1; i >= 0; i--) {
    maxr[i] = max(maxr[i + 1], arr[i]);
  }
  set<int> lowerValue;
  lowerValue.insert(INT_MIN);
  for (int i = 0; i < n; i++) {
    if (maxr[i + 1] > arr[i]) {
      ans = max(ans, maxLowerValue(lowerValue, arr[i]) + arr[i] + maxr[i]);
      lowerValue.insert(arr[i]);
    }
  }
  return ans;
}

int main() {
  int n;
  cin >> n;
  vector<int> v(n, 0);
  for (int i = 0; i < n; i++) {
    cin >> v[i];
  }
  cout << "output is " << maxTriplet(v) << endl;
}
