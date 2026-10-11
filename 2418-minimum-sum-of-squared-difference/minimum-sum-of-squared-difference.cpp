class Solution {
public:
    long long minSumSquareDiff(vector<int>& nums1,
                               vector<int>& nums2,
                               int k1, int k2) {

        int n = nums1.size();

        vector<long long> freq(100001, 0);

        int maxDiff = 0;

        // Find all differences
        for (int i = 0; i < n; i++) {
            int d = abs(nums1[i] - nums2[i]);

            freq[d]++;
            maxDiff = max(maxDiff, d);
        }

        long long k = (long long)k1 + k2;

        // Reduce differences starting from largest
        for (int d = maxDiff; d > 0 && k > 0; d--) {

            long long take = min(k, freq[d]);

            // Move 'take' elements from d to d-1
            freq[d] -= take;
            freq[d - 1] += take;

            k -= take;
        }

        long long ans = 0;

        for (int d = 1; d <= maxDiff; d++) {
            ans += freq[d] * 1LL * d * d;
        }

        return ans;
    }
};