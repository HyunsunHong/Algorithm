#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

bool cmp(int a, int b) {
    if(a > b) return true;

    return false;
}


int main() {

    //pair<int, int> p = make_pair(1, 3);

    //vecotr<pair<int, int> > vec;
    vector<int> vec;

    for(int i = 9; i > 0; i--) vec.push_back(i);


    

    sort(vec.begin(), vec.end());

    sort(vec.begin(), vec.end(), cmp);

    for(auto x : vec) cout << x << " ";

    return 0;
}