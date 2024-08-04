#include <iostream>
#include <string>
using namespace std;

// 以每個字元為中心，往兩邊檢查是否為迴文子字串
string lps(string str)
{
    int n = str.length();
    // 空字串
    if (n == 0)
    {
        return "";
    }
    // 最長迴文子字串長度
    int maxLength = 1;
    // 最長迴文子字串起始位置
    int start = 0;

    for (int i = 0; i < n; i++)
    {
        // 處理奇數長度的迴文
        int left = i;
        int right = i;
        while (left >= 0 && right < n && str[left] == str[right])
        {
            int currLength = right - left + 1;
            if (currLength > maxLength)
            {
                maxLength = currLength;
                start = left;
            }
            left--;
            right++;
        }

        // 處理偶數長度的迴文
        left = i;
        right = i + 1;
        while (left >= 0 && right < n && str[left] == str[right])
        {
            int currLength = right - left + 1;
            if (currLength > maxLength)
            {
                maxLength = currLength;
                start = left;
            }
            left--;
            right++;
        }
    }
    return str.substr(start, maxLength);
}

int main()
{
    string str = "cbbd";
    cout << "Longest palindromic substring: " << lps(str) << endl;
    return 0;
}
