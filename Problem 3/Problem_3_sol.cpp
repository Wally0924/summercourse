#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
using namespace std;
double findMedianSortedArrays(vector<int> nums1, vector<int> nums2)
{
    int n1 = nums1.size();
    int n2 = nums2.size();
    vector<int> merged(n1 + n2);
    // 線性合併
    merge(nums1.begin(), nums1.end(), nums2.begin(), nums2.end(), merged.begin());
    if ((n1 + n2) % 2 == 0)
    {
        return (merged[(n1 + n2) / 2 - 1] + merged[(n1 + n2) / 2]) / 2.0;
    }
    else
    {
        return merged[(n1 + n2) / 2];
    }
}

int main()
{
    vector<int> nums1 = {1, 2};
    vector<int> nums2 = {3, 4};
    double result = findMedianSortedArrays(nums1, nums2);
    cout << fixed << setprecision(5) << result << endl;
    return 0;
}
