// https://leetcode.com/problems/next-greater-element-iii/

// Next Greater Element III : Logic: use next permutation approach:

class Solution {
public:
    int nextGreaterElement(int n) {
        auto digits = to_string(n);
        next_permutation(begin(digits), end(digits));
        auto res = stoll(digits);
        return (res > INT_MAX || res <= n) ? -1 : res;
    }
};
