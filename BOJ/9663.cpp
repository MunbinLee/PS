#include <iostream>
#include <vector>
#include <array>

using namespace std;

int N;
vector<bool> isColumnAttacked;
array<vector<bool>, 2> isDiagonalAttacked;

int getDiagonal(int direction, int row, int column) {
    if (direction == 0) {
        return row + column;
    }
    
    return column - row + N - 1;
}

bool isAttacked(int row, int column) {
    if (isColumnAttacked[column]) {
        return true;
    }
    
    if (isDiagonalAttacked[0][getDiagonal(0, row, column)]) {
        return true;
    }
    
    if (isDiagonalAttacked[1][getDiagonal(1, row, column)]) {
        return true;
    }
    
    return false;
}

void attack(int row, int column) {
    isColumnAttacked[column] = true;
    isDiagonalAttacked[0][getDiagonal(0, row, column)] = true;
    isDiagonalAttacked[1][getDiagonal(1, row, column)] = true;
}

void cancelAttack(int row, int column) {
    isColumnAttacked[column] = false;
    isDiagonalAttacked[0][getDiagonal(0, row, column)] = false;
    isDiagonalAttacked[1][getDiagonal(1, row, column)] = false;
}

int placeQueen(int row) {
    if (row == N) {
        return 1;
    }
    
    int answer = 0;
    
    for (int column = 0; column < N; column++) {
        if (isAttacked(row, column)) {
            continue;
        }
        
        attack(row, column);
        answer += placeQueen(row + 1);
        cancelAttack(row, column);
    }
    
    return answer;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> N;
    
    isColumnAttacked.resize(N);
    isDiagonalAttacked.fill(vector<bool>(N * 2 - 1));
    
    cout << placeQueen(0);
    
    return 0;
}
