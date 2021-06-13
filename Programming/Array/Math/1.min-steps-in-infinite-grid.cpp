// https://www.interviewbit.com/problems/min-steps-in-infinite-grid/

#include <iostream>
#include <vector>
using namespace std;


int coverPoints(vector<int> &A, vector<int> &B) {
  int result = 0;
  int prev_x = A[0];
  int prev_y = B[0];
  for (int i = 1; i < (int)A.size(); i++) {
    result += max(abs(prev_x - A[i]), abs(prev_y - B[i]));
    prev_x = A[i];
    prev_y = B[i];
  }
  return result;
}

int main() {
  cout << "working" << endl;
  vector<int> v1 = {0, 1, 1};
  vector<int> v2 = {0, 1, 2};
  cout << coverPoints(v1, v2) << endl;
}
