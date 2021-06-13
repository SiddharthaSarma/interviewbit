// https://www.interviewbit.com/problems/add-one-to-number/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> solve(const vector<int>& arr) {
  vector<int> result;
  int n = arr.size();
  int sum = arr[n - 1] + 1;
  int carry = sum / 10;
  int value = sum % 10;
  result.emplace_back(value);

  for (int i = n - 2; i >= 0; i--) {
    sum = arr[i] + carry;
    carry = sum / 10;
    value = sum  % 10;
    if (i == 0 && (carry == 1 || value != 0)) {
      result.emplace_back(value);
    } else if (i != 0) {
      result.emplace_back(value);
    }
  }
  if (carry == 1) {
    result.emplace_back(1);
  }
  reverse(result.begin(), result.end());
  while (result[0] == 0) {
    result.erase(result.begin());
  }
  return result;
}

int main() {
  int n;
  cin >> n;
  vector<int> v(n);
  for (int i = 0; i < n; i++) {
    cin >> v[i];
  }
  vector<int> result = solve(v);
  for (int i = 0; i < n; i++) {
    cout << result[i] << " ";
  }
  cout << endl;
}
