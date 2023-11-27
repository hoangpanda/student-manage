#include <iostream>
#include <utility>
#include <bits/stdc++.h>
using namespace std;

struct my_struct {
    int first, second, third;
};

// bool compare(my_struct& a, my_struct& b) {
//     if(a.first < b.first) return true;
//     return false;
// }

bool operator < (my_struct& a, my_struct& b) {
    if(a.first > b.first) return true;
    return false;
}

int main() {
    
    vector<my_struct> a;

    a.push_back({1,2,3});
    a.push_back({2,1,1});

    sort(begin(a), end(a));

    for(auto i:a) {
        cout << i.first << ' ' << i.second << ' ' << i.third << endl;
    }

    return 0;
}
