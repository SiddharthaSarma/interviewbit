// https://www.interviewbit.com/problems/minimum-lights-to-activate/
#include<iostream>
#include<vector>

using namespace std;

int solve(vector<int> &A, int a) {
  int count = 0;
  int i = 0;
  bool bulbFound = false;
  int n = A.size();
  while (i < n) {
    int j = i + a - 1;
    j = j > n ? n : j;
    bulbFound = false;
    while (j >= (i - a + 1) && j >= 0 && j <= n) {
      if (A[j] == 1) {
        bulbFound = true;
        i = j + a;
        count++;
        break;
      }
      j--;
    }
    if (!bulbFound) {
      return -1;
    }
  }
  return count;
}


int main() {
  int n;
  cin >> n;
  vector<int> v(n);
  for (int i = 0; i < n; i++) {
    cin >> v[i];
  }
  int a;
  cin >> a;
  cout << solve(v, a) << endl;
}
