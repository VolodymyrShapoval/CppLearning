#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n)
    {
        if (n == 0) return;
        if (m == 0)
        {
            nums1 = nums2;
            return;
        }

        vector<int> mergedArr(m+n);

        size_t i = 0, j = 0, ind = 0;
        for (; i < m && j < n; ++ind)
        {
            if (nums1[i] <= nums2[j])
            {
                mergedArr[ind] = nums1[i];
                ++i;
            }
            else if (nums1[i] > nums2[j])
            {
                mergedArr[ind] = nums2[j];
                ++j;
            }
        }

        while (ind < m + n)
        {
            if (i >= m)
            {
                mergedArr[ind] = nums2[j];
                ++j;
            }
            else if (j >= n)
            {
                mergedArr[ind] = nums2[j];
                ++j;
            }
            ++ind;
        }

        nums1 = mergedArr;
    }
};

int main()
{
    vector<int> nums1 = { 1,2,3};
    nums1.reserve(6);
    vector<int> nums2 = { 2,5,6 };

    Solution solution;
    solution.merge(nums1, nums1.size(), nums2, nums2.size());

    cout << "Merged array: ";
    for (size_t i = 0; i < nums1.size(); ++i)
    {
        cout << nums1[i] << " ";
    }
    cout << endl;

    return 0;
}