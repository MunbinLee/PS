#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/*
 * 집 N=20만개 공유기 N개 좌표 0~10억
 * 집의 좌표는 정렬되어있지 않음 (대체 왜?)
 * 가장 인접한 두 공유기 간의 거리를 최대로 해야함
 *
 * 일단 맨 처음이랑 맨 끝에 설치하면 개이득이다.
 *
 * 거리 1~10억 이분탐색?
 *
 * 20만 * log_2 10억 = 기껏해야 32
 */

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, C;
    cin >> N >> C;

    vector<int> positions(N);

    for (int &position: positions) {
        cin >> position;
    }

    sort(positions.begin(), positions.end());

    // 최소한의 거리가 minDist일 때, 모든 공유기를 설치할 수 있는지
    auto isAvailable = [&](int minDist) {
        int lastPosition = positions[0];
        int router = 1;

        for (int i = 1; i < positions.size(); i++) {
            if (positions[i] - lastPosition < minDist) continue;

            router++;
            lastPosition = positions[i];
        }

        return router >= C;
    };

    int lo = 1;
    int hi = 1'000'000'000;
    int answer = -1;

    while (lo <= hi) {
        int md = lo + (hi - lo) / 2;

        if (isAvailable(md)) {
            answer = max(answer, md);
            lo = md + 1;
        } else {
            hi = md - 1;
        }
    }

    cout << answer;

    return 0;
}
