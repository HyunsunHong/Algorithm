/*
  bfs + implementation
*/

#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

struct node {
    int one;
    int two;
    int three;
    int four;
    string log;

    node(int O, int TW, int TH, int FO, string LO) : one(O), two(TW), three(TH), four(FO), log(LO) {}
};

string bfs(node A, node B) {
    bool visited[10][10][10][10];
    queue<node> q;

    for(int i = 0; i < 10; i++) {
        for(int j = 0; j < 10; j++) {
            for(int k = 0; k < 10; k++) {
                for(int a = 0; a < 10; a++) {
                    visited[i][j][k][a] = false;
                }
            }
        }
    }

    if(A.one == B.one && A.two == B.two && A.three == B.three && A.four == B.four) {
        return "";
    }

    visited[A.one][A.two][A.three][A.four] = true;
    q.push(A);

    while(!q.empty()) {
        node curr = q.front();
        q.pop();

        int curr_num = curr.one * 1000 + curr.two * 100 + curr.three * 10 + curr.four;
        string curr_str = curr.log;

        // D
        int D_num = (curr_num*2) % 10000;
        if(!visited[D_num/1000][(D_num/100)%10][(D_num/10)%10][D_num%10]) {
            visited[D_num/1000][(D_num/100)%10][(D_num/10)%10][D_num%10] = true;
            curr_str.push_back('D');
            if(B.one == D_num/1000 && B.two == (D_num/100)%10 && B.three == (D_num/10)%10 && B.four == D_num%10) {
                return curr_str;
            }
           // cout << D_num << " " << curr_str << " D\n";
            q.push(node(D_num/1000, (D_num/100)%10, (D_num/10)%10, D_num%10, curr_str));
            curr_str.pop_back();
        }
        // S
        D_num = curr_num - 1;
        if(D_num == -1) D_num = 9999;
        if(!visited[D_num/1000][(D_num/100)%10][(D_num/10)%10][D_num%10]) {
            visited[D_num/1000][(D_num/100)%10][(D_num/10)%10][D_num%10] = true;
            curr_str.push_back('S');
            if(B.one == D_num/1000 && B.two == (D_num/100)%10 && B.three == (D_num/10)%10 && B.four == D_num%10) {
                return curr_str;
            }
            q.push(node(D_num/1000, (D_num/100)%10, (D_num/10)%10, D_num%10, curr_str));
            //cout << D_num << " " << curr_str << " S\n";
            curr_str.pop_back();
        }
        // L
        D_num = curr_num/1000 + (curr_num%1000)*10; 
        if(!visited[D_num/1000][(D_num/100)%10][(D_num/10)%10][D_num%10]) {
            visited[D_num/1000][(D_num/100)%10][(D_num/10)%10][D_num%10] = true;
            curr_str.push_back('L');
            if(B.one == D_num/1000 && B.two == (D_num/100)%10 && B.three == (D_num/10)%10 && B.four == D_num%10) {
                return curr_str;
            }
            q.push(node(D_num/1000, (D_num/100)%10, (D_num/10)%10, D_num%10, curr_str));
           // cout << D_num << " " << curr_str << " L\n";
            curr_str.pop_back();
        }
        // R
        D_num = (curr_num/10) + (curr_num%10)*1000;
        if(!visited[D_num/1000][(D_num/100)%10][(D_num/10)%10][D_num%10]) {
            visited[D_num/1000][(D_num/100)%10][(D_num/10)%10][D_num%10] = true;
            curr_str.push_back('R');
            if(B.one == D_num/1000 && B.two == (D_num/100)%10 && B.three == (D_num/10)%10 && B.four == D_num%10) {
                return curr_str;
            }
            q.push(node(D_num/1000, (D_num/100)%10, (D_num/10)%10, D_num%10, curr_str));
            //cout << D_num << " " << curr_str << " R\n";
            curr_str.pop_back();
        }
    }

    return "";
}

int main() {

    int T;
    vector<string> ans;

    cin >> T;

    while(T--) {
        string s;
        string A, B;

        cin >> A >> B;

        int a = stoi(A);
        int b = stoi(B);
        
        ans.push_back(bfs(node(a/1000, (a/100)%10, (a/10)%10, a%10, ""), node(b/1000, (b/100)%10, (b/10)%10, b%10, "")));
    }

    for(auto x : ans) {
        cout << x << "\n";
    }

    return 0;
}
