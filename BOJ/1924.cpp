/*

    bronze 5

    implementation

*/

#include <iostream>

using namespace std;

int x, y;

int date[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

int main() {

    cin >> x >> y;

    for(int i = 1; i <= x - 1; i++) y += date[i];

    if(y % 7 == 0) cout << "SUN\n";
    else if(y % 7 == 1) cout << "MON\n";
    else if(y % 7 == 2) cout << "TUE\n";
    else if(y % 7 == 3) cout << "WED\n";
    else if(y % 7 == 4) cout << "THU\n";
    else if(y % 7 == 5) cout << "FRI\n";
    else cout << "SAT\n";

    return 0;
}