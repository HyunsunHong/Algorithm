/*
  
  gold 3
  
  implementation

*/

#include <iostream> 

using namespace std;

char input[20];
int N;
int ans = -987654321;

int cal_op(int a, int b, char op) {
    if(op == '+') a += b;
    else if(op == '-') a -= b;
    else if(op == '*') a *= b;

    return a;
}

void go(int idx, int ret) {
    if(idx > N) {
        ans = max(ans, ret);
        return;
    }

    if(idx == 1) {
        go(idx + 2, input[idx] - '0');
        return;
    }
    
    // 괄호 x
    go(idx + 2, cal_op(ret, input[idx] - '0', input[idx - 1]));
    
    // 괄호 o
    if(idx + 2 <= N) {
        int cal =  cal_op(input[idx] - '0', input[idx + 2] - '0', input[idx + 1]);
        go(idx + 4, cal_op(ret, cal, input[idx - 1]));
    }
}


int main() {

    cin >> N;

    for(int i = 1; i <= N; i++) cin >> input[i];
        
    go(1, 0);

    cout << ans;

    return 0;
}
