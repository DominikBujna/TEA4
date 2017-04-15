#include <iostream>
#include <vector>

using namespace std;

struct highway {
    int city1;
    int city2;
    int cost;
};
struct compare_cost{
    bool operator() (const highway lhs, const highway rhs) const{
        return lhs.cost < rhs.cost;
    }
};

int n;
vector<highway> costs;

int rob_co_mas() {
    vector<int> cities;
    sort(costs.begin(), costs.end(),compare_cost());
    //pridam najlacnejsiu, bude v kostre
    cities.push_back(costs.at(0).city1);
    cities.push_back(costs.at(0).city2);
    for(int i = 0; i < n-1; i++){
        
    }
    return 0;
}


int main() {
    cin >> n;

    for (int i = 0; i < n; i++) {
        vector<highway> temp;
        for (int j = 0; j < n; j++) {
            if (i != j) {
                highway meh;
                cin >> meh.cost;
                meh.city1 = i;
                meh.city2 = j;
                costs.push_back(meh);
            }
        }

    }
    return 0;
}