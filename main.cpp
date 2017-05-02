#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;
long long sum;
vector<pair<int, pair<int, int>>> highways;

class set {
public:
    vector<int> members;
    vector<int> set_size;

    set(int n) {
        for (int i = 0; i < n; i++) {
            members.push_back(i);
            set_size.push_back(1);
        }
    }

    int shortest_path(int i) {
        while (i != members.at(i)) {
            members.at(i) = members.at(members.at(i));
            i = members.at(i);
        }
        return i;
    }

    void join(int u, int v) {
        int i = shortest_path(u);
        int j = shortest_path(v);

        if (set_size.at(i) < set_size.at(j)) {
            members.at(i) = j;
            set_size.at(j) += set_size.at(i);
        } else {
            members.at(j) = i;
            set_size.at(i) += set_size.at(j);
        }
    }

    int is_memeber(int u, int v) {
        return shortest_path(u) == shortest_path(v);
    }

};

void rob_co_mas() {
    set graf(n);
    int u, v;
    sort(highways.begin(), highways.end());
    int size = highways.size();
    for (int i = 0; i < size; ++i) {
        u = highways[i].second.first;
        v = highways[i].second.second;
        if (!graf.is_memeber(u, v)) {
            graf.join(u, v);
            sum += highways.at(i).first;
        } else if(highways.at(i).first < 0){
            sum += highways.at(i).first;
        }
    }
}

int main() {
    int cost;
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> cost;
            if (i < j) {
                highways.push_back(pair<int, pair<int, int>>(cost, pair<int, int>(i, j)));
            }
        }
    }
    rob_co_mas();
    cout << sum << endl;
    return 0;
}