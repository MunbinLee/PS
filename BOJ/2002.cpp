#include <iostream>
#include <vector>
#include <set>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int N;
	cin >> N;

	vector<string> carsIn(N), carsOut(N);
	for (auto &car : carsIn)
		cin >> car;
	for (auto &car : carsOut)
		cin >> car;

	set<pair<string, string>> st;
	for (int i = 0; i + 1 < N; i++)
		for (int j = i + 1; j < N; j++)
			st.emplace(carsIn[i], carsIn[j]);

	set<string> overtakes;
	for (int i = 0; i + 1 < N; i++)
		for (int j = i + 1; j < N; j++)
			if (!st.contains(pair<string, string>(carsOut[i], carsOut[j])))
				overtakes.emplace(carsOut[i]);

	cout << overtakes.size();

	return 0;
}