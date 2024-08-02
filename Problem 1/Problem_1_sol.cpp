#include <iostream>
#include <vector>
using namespace std;

vector<int> GetIndex(vector<int> nums, int target) {
    int left = 0;
    int right = nums.size() - 1;
    //設定開始及結束Index初始值
    int start = -1;
    int end = -1;
    
    //Binary Search 左邊界
    //當left <= right時，代表還有元素可以搜尋，兩者交錯後代表搜尋完畢
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (nums[mid] >= target) {
            right = mid - 1;
        } else {
            left = mid + 1;
        }
        if (nums[mid] == target) {
            start = mid;
        }
    }

    //Binary Search 右邊界
    left = 0;
    right = nums.size() - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (nums[mid] <= target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
        if (nums[mid] == target) {
            end = mid;
        }
    }
    //若沒找到target，則start及end皆為-1
    return {start, end};
}

int main() {
    vector<int> nums = {};
    int target = 0;
    vector<int> result = GetIndex(nums, target);
    cout << "[" << result[0] << "," << result[1] << "]" << endl;
    return 0;
}
