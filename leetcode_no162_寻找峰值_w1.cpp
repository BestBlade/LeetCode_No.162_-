/* ------------------------------------------------------------------|
峰值元素是指其值大于左右相邻值的元素。

给你一个输入数组 nums，找到峰值元素并返回其索引。数组可能包含多个峰值，在这种情况下，返回 任何一个峰值 所在位置即可。

你可以假设 nums[-1] = nums[n] = -∞ 。

 

示例 1：

输入：nums = [1,2,3,1]
输出：2
解释：3 是峰值元素，你的函数应该返回其索引 2。
示例 2：

输入：nums = [1,2,1,3,5,6,4]
输出：1 或 5
解释：你的函数可以返回索引 1，其峰值元素为 2；
     或者返回索引 5， 其峰值元素为 6。
 

提示：

1 <= nums.length <= 1000
-231 <= nums[i] <= 231 - 1
对于所有有效的 i 都有 nums[i] != nums[i + 1]
 

进阶：你可以实现时间复杂度为 O(logN) 的解决方案吗？

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/find-peak-element
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。|
-------------------------------------------------------------------*/

/*	双指针法
*
*	执行用时：0 ms, 在所有 C++ 提交中击败了100.00%的用户
*	内存消耗：8.1 MB, 在所有 C++ 提交中击败了81.94%的用户
*/

#include <iostream>
#include <string> 
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <map>
#include <stack>
#include <queue>

using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}

};

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};


/*	O(n)法
*
*	执行用时：0 ms, 在所有 C++ 提交中击败了100.00%的用户
*	内存消耗：8.4 MB, 在所有 C++ 提交中击败了99.93%的用户
*/
int findPeakElement(vector<int>& nums) {
    for (int i = 0; i < nums.size() - 1; i++) {
        //如果前面的比后面的大就返回
        //不然就下一个，保证前面的比后面的小
        if (nums[i] > nums[i + 1]) {
            return i;
        }
    }
    return nums.size() - 1;
}

/*	二分查找O(logn)法1
*
*	执行用时：4 ms, 在所有 C++ 提交中击败了95.14%的用户
*	内存消耗：8.6 MB, 在所有 C++ 提交中击败了91.69%的用户
*/

int findPeakElement(vector<int>& nums) {
    int l = 0;
    int r = nums.size() - 1;
    while (l < r) {
        int mid = (l + r) >> 1;
        if (nums[mid] > nums[mid + 1]) {
            r = mid;
        }
        else {
            l = mid + 1;
        }
    }
    return l;
}

/*	二分查找O(logn)法2
*
*	执行用时：4 ms, 在所有 C++ 提交中击败了95.14%的用户
*	内存消耗：8.5 MB, 在所有 C++ 提交中击败了94.80%的用户
*/
int dfs(vector<int>& nums, int l, int r) {
    if (l == r) {
        return l;
    }
    int mid = (l + r) >> 1;
    if (nums[mid] > nums[mid + 1]) {
        return dfs(nums, l, mid);
    }
    return dfs(nums, mid + 1, r);
}

int findPeakElement(vector<int>& nums) {
    return dfs(nums, 0, nums.size() - 1);
}