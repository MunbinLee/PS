#include <iostream>

using namespace std;

/*
 * S = 30만
 *
 * A-B를 지운다.
 * B-C를 지운다.
 *
 * B가 공통
 *
 * S=ABCBA => 2
 *  CBA (x)
 *  BCA
 *      A
 *  ABA
 *      A
 *
 * 단순 구현: 가능한 모든 쌍 찾기 O(S^2) - 찾은 후 탐색까지 감안하면 너무 느림
 *
 * 그리디??
 * - A와 가까운 B를 지우면 불리하다? X
 *      반례 : ABAB
 * - AB 보다 BC를 우선으로 지워야한다? X
 *      AABC, BABC, CABC, ABBC, ACBC, ABAC, ABCC, ABCA, ABCB
 *      반례 : BABC
 */

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    string S;
    cin >> S;
    
    return 0;
}
