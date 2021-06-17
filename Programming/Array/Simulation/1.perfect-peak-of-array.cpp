// https://www.interviewbit.com/problems/perfect-peak-of-array/
#include <iostream>
#include <vector>

using namespace std;

int findPeak(vector<int>& arr)
{
    int n = arr.size();
    int mx[n], mn[n];
    mx[0] = arr[0];
    mn[n - 1] = arr[n-1];

    for (int i = 1; i < n; i++)
    {
        mx[i] = max(mx[i - 1], arr[i]);
    }
    for (int i = n - 2; i >= 0; i--)
    {
        mn[i] = min(mn[i + 1], arr[i]);
    }
    for(int  i = 1; i < n - 1; i++)
    {
        if (arr[i] > mx[i - 1] && arr[i] < mn[i + 1])
        {
            return 1;
        }
    }
    return 0;
}
int main()
{
    vector<int> v = {1, 2, 3, 4, 5, 4, 3, 2, 3, 10};
    cout << findPeak(v) << endl;
    return 0;
}
