class Solution {
public:
    int maxPerformance(int n, vector<int>& speed, vector<int>& efficiency, int k) {
        const int MOD = 1e9 + 7;

        vector<pair<int, int>> eng;
        eng.reserve(n);

        for (int i = 0; i < n; ++i) {
            eng.emplace_back(efficiency[i], speed[i]);
        }

        sort(eng.rbegin(), eng.rend());

        priority_queue<int, vector<int>, greater<int>> pq;
        long long sum = 0, ans = 0;

        for (const auto& [eff, spd] : eng) {
            pq.push(spd);
            sum += spd;

            if ((int)pq.size() > k) {
                sum -= pq.top();
                pq.pop();
            }

            long long perf = sum * eff;
            if (perf > ans) ans = perf;
        }

        return (int)(ans % MOD);
    }
};