/*
 * @lc app=leetcode.cn id=128 lang=cpp
 *
 * [128] 最长连续序列
 */

// @lc code=start
class UnionSet
{
public:
    vector<int> size, father;
    void init(int n) {
        father.resize(n + 5);
        size.resize(n + 5);
        for (int i = 0; i <= n; i++) {
            father[i] = i;
            size[i] = 1;
        }
        return ;
    }
    int get(int x) {
        return father[x] = (father[x] == x ? x : get(father[x]));
    }
    void merge(int a, int b) {
        int fa = get(a), fb = get(b);
        if (fa == fb) return ;
        father[fa] = fb;
        size[fb] += size[fa];
        return ;
    }
};
class Solution
{
public:
    int longestConsecutive(vector<int> &nums)
    {
        /*
        int maxCount = 0, lCount = 0, rCount = 0;
        unordered_map<int, int> s;
        for (auto nums[i] : nums) {
            if (s[nums[i]]) continue;
            int l = s[nums[i] - 1], r = s[nums[i] + 1];
            int sum = l + r + 1;
            s[nums[i]] = s[nums[i] - l] = s[nums[i] + r] = sum;
            maxCount = max(maxCount, sum);
        }
        return maxCount;
        */
        /*
        unordered_set<int> set(nums.begin(), nums.end());
        int res = 0;
        for (auto nums[i] : nums) {
            if (!set.count(nums[i])) continue;
            set.erase(nums[i]); 
            int pre = nums[i] - 1, next = nums[i] + 1;
            while (set.count(pre)) set.erase(pre--);
            while (set.count(next)) set.erase(next++);
            res = max(res, next - pre - 1);
        }
        return res;
        */

        unordered_map<int, int> s;
        u.init(nums.size());
        for (int i = 0; i < nums.size(); i++) {
            int val = nums[i];
            if (s.find(val) != s.end()) continue;
            if (s.find(val - 1) != s.end()) {
                u.merge(s[val - 1], i);
            }
            if (s.find(val + 1) != s.end()) {
                u.merge(s[val + 1], i);
            }
            s[val] = i;
        }
        int ans = 0;
        for (int i = 0; i < nums.size(); i++) {
            ans = max(ans, u.size[i]);
        }
        return ans;
    }

private:
    UnionSet u;
};
// @lc code=end
