#include <iostream>
#include <map>
#include <ranges>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    map<string, bool> company;

    int n;
    cin >> n;

    while (n--) {
        string name, type;
        cin >> name >> type;

        company[name] = type == "enter";
    }

    for (auto &it: ranges::reverse_view(company)) {
        if (!it.second) continue;
        cout << it.first << '\n';
    }

    return 0;
}
