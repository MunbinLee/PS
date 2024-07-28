#include <iostream>
#include <array>
#include <vector>

using namespace std;

array<array<bool, 9>, 9> usedRow{}, usedColumn{}, usedBox{};
vector<vector<int>> board;
vector<pair<int, int>> unknowns;

int getBox(int r, int c)
{
	int y = r / 3;
	int x = c / 3;
	return y * 3 + x;
}

void print()
{
	for (int r = 0; r < 9; r++)
	{
		for (int c = 0; c < 9; c++)
		{
			cout << board[r][c] << ' ';
		}
		cout << '\n';
	}
}

void dfs(int index)
{
	if (index == (int)unknowns.size())
	{
		print();
		exit(0);
	}

	auto [r, c] = unknowns[index];

	for (int num = 1; num <= 9; num++)
	{
		if (usedRow[r][num])
			continue;
		if (usedColumn[c][num])
			continue;
		if (usedBox[getBox(r, c)][num])
			continue;

		usedRow[r][num] = true;
		usedColumn[c][num] = true;
		usedBox[getBox(r, c)][num] = true;

		board[r][c] = num;
		dfs(index + 1);

		usedRow[r][num] = false;
		usedColumn[c][num] = false;
		usedBox[getBox(r, c)][num] = false;
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	board = vector<vector<int>>(9, vector<int>(9));

	for (int r = 0; r < 9; r++)
	{
		for (int c = 0; c < 9; c++)
		{
			int &num = board[r][c];
			cin >> num;

			if (num == 0)
			{
				unknowns.emplace_back(r, c);
				continue;
			}

			usedRow[r][num] = true;
			usedColumn[c][num] = true;
			usedBox[getBox(r, c)][num] = true;
		}
	}

	dfs(0);

	return 0;
}