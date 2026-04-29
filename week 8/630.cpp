#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int scheduleCourse(vector<vector<int>>& courses) {
        // 依照 lastDay 從小到大排序
        sort(courses.begin(), courses.end(), [](vector<int>& a, vector<int>& b) {
            return a[1] < b[1];
        });

        priority_queue<int> maxHeap; // 存目前選到的課程 duration
        int totalTime = 0;

        for (auto& course : courses) {
            int duration = course[0];
            int lastDay = course[1];

            // 先選這門課
            totalTime += duration;
            maxHeap.push(duration);

            // 如果超過截止日，就刪掉目前最花時間的課
            if (totalTime > lastDay) {
                totalTime -= maxHeap.top();
                maxHeap.pop();
            }
        }

        return maxHeap.size();
    }
};