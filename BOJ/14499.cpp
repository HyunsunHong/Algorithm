/*

gold 4

simulation + implementation

*/

#include <iostream>

#define BUTTOM 6
#define TOP 1
#define EAST 3
#define WEST 4
#define FRONT 2
#define BACK 5

using namespace std;

int N, M, x, y, k;
int dice[7] = {0, }; 
int Map[20][20]; 
int dr[5] = {0, 0, 0, -1, 1};
int dc[5] = {0, 1, -1, 0, 0};
int buttom = dice[BUTTOM];
int top = dice[TOP];
int east = dice[EAST];
int west = dice[WEST];
int front = dice[FRONT];
int back = dice[BACK];

bool possible(int r, int c) {
    if(r < 0 || r >= N) return false;
    if(c < 0 || c >= M) return false;
    return true;
}

void copy_dice() {
    buttom = dice[BUTTOM];
    top = dice[TOP];
    east = dice[EAST];
    west = dice[WEST];
    front = dice[FRONT];
    back = dice[BACK];
}

void roll_east() {
    copy_dice();

    dice[BUTTOM] = east;
    dice[EAST] = top;
    dice[TOP] = west;
    dice[BACK] = back;
    dice[FRONT] = front;
    dice[WEST] = buttom; 
}

void roll_west() {
    copy_dice();

    dice[BUTTOM] = west;
    dice[EAST] = buttom;
    dice[TOP] = east;
    dice[BACK] = back;
    dice[FRONT] = front;
    dice[WEST] = top; 
}

void roll_north() {
    copy_dice();

    dice[BUTTOM] = back;
    dice[EAST] = east;
    dice[TOP] = front;
    dice[BACK] = top;
    dice[FRONT] = buttom;
    dice[WEST] = west; 
}

void roll_south() {
    copy_dice();

    dice[BUTTOM] = front;
    dice[EAST] = east;
    dice[TOP] = back;
    dice[BACK] = buttom;
    dice[FRONT] = top;
    dice[WEST] = west; 
}

void map_process() {

    cout << dice[TOP] << "\n";

    if(Map[x][y] == 0) {
            Map[x][y] = dice[BUTTOM];
    }
    else {
        dice[BUTTOM] = Map[x][y];
        Map[x][y] = 0;
    }
}

int main() {   

    cin >> N >> M >> x >> y >> k;

    for(int n = 0; n < N; n++) {
        for(int m = 0; m < M; m++) {
            cin >> Map[n][m];
        }
    }

    for(int i = 0; i < k; i++) {
        int command;
        int next_x, next_y;

        cin >> command;
        
        next_x = x + dr[command];
        next_y = y + dc[command];
        if(possible(next_x, next_y)) {

            x = next_x, y = next_y;

            if(command == 1) roll_east();
            else if(command == 2) roll_west();
            else if(command == 3) roll_north();
            else if(command == 4) roll_south();

            map_process();
        }
    }
    


    return 0;
}