#include <string>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int solution(vector<vector<int>> jobs) {
    sort(jobs.begin(), jobs.end());
    
    int currentTime = 0;
    int answer = 0;
    
    auto cmp = [](const auto &a, const auto &b) {
        if (a[1] == b[1]) return a[0] > b[0];
        return a[1] > b[1];
    };
    
    priority_queue<vector<int>, vector<vector<int>>, decltype(cmp)> pq(cmp);
    
    for (int i = 0; i < jobs.size();) {
        while (i < jobs.size() && jobs[i][0] <= currentTime) {
            pq.emplace(jobs[i]);
            i++;
        }
        
        if (pq.empty()) {
            currentTime = jobs[i][0] + jobs[i][1];
            answer += jobs[i][1];
            i++;
            continue;
        }
        
        auto job = pq.top();
        pq.pop();
        currentTime += job[1];
        answer += currentTime - job[0];
    }
    
    while (!pq.empty()) {
        auto job = pq.top();
        pq.pop();
        currentTime += job[1];
        answer += currentTime - job[0];
    }
    
    return answer / (int) jobs.size();
}