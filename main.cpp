#include <iostream>
#include <fstream>
#include "json.hpp"
#include <vector>
#include <set>
#include <cstdlib>
#include <map>

using namespace std;
using json = nlohmann::json;

typedef long long ll;
typedef pair<ll, ll> Point;

ll convertBase(const string& val, int base) {
    ll num = 0;
    for (char ch : val) {
        int digit = isdigit(ch) ? ch - '0' : ch - 'a' + 10;
        num = num * base + digit;
    }
    return num;
}

long double lagrangeInterpolation(const vector<Point>& points) {
    long double result = 0.0;
    int k = points.size();
    for (int i = 0; i < k; ++i) {
        long double term = points[i].second;
        for (int j = 0; j < k; ++j) {
            if (j != i)
                term *= (0.0 - points[j].first) / (points[i].first - points[j].first);
        }
        result += term;
    }
    return result;
}

void solveSecret(const string& filename) {
    ifstream infile(filename);
    json j;
    infile >> j;

    int n = j["keys"]["n"];
    int k = j["keys"]["k"];

    vector<Point> roots;
    for (auto& el : j.items()) {
        if (el.key() == "keys") continue;
        try {
            ll x = stoll(el.key());
            int base = stoi(el.value()["base"].get<string>());
            string value = el.value()["value"];
            ll y = convertBase(value, base);
            roots.push_back({x, y});
        } catch (...) {
            // skip malformed entry
        }
    }

    map<ll, int> cFreq;
    int total = roots.size();
    vector<int> indices(total);
    iota(indices.begin(), indices.end(), 0);

    vector<int> selectMask(total, 0);
    fill(selectMask.begin(), selectMask.begin() + k, 1);

    do {
        vector<Point> subset;
        for (int i = 0; i < total; ++i) {
            if (selectMask[i])
                subset.push_back(roots[i]);
        }

        try {
            ll c = lagrangeInterpolation(subset);
            cFreq[c]++;
        } catch (...) {
            continue;
        }

    } while (prev_permutation(selectMask.begin(), selectMask.end()));

    int maxFreq = 0;
    ll finalC = -1;
    for (auto& [c, freq] : cFreq) {
        if (freq > maxFreq) {
            maxFreq = freq;
            finalC = c;
        }
    }

    cout << "Secret (c): " << finalC << endl;
}

int main() {
    solveSecret("testcase1.json");
    solveSecret("testcase2.json");
    return 0;
}
