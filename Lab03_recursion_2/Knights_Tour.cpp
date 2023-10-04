#include <iostream>

#define MAXSIZE 9
#define MARK 1
#define UNMARK 0

using namespace std;

typedef struct Point {int x, y;} point;
point direction[8] = {{1, -2}, {2, -1}, {2, 1}, {1, 2},
                      {-1, 2}, {-2, 1}, {-2, -1}, {-1, -2}};

int board[MAXSIZE][MAXSIZE], path[MAXSIZE][MAXSIZE];

int knighttour(int n, int m, point pos, int cnt){
    point next;

    if(cnt == n * m)
        return 1;

    for(int i=0; i<8; i++){
        next.x = pos.x + direction[i].x;
        next.y = pos.y + direction[i].y;

        if(next.x > 0 && next.x <= n && next.y > 0 && next.y <= m && board[next.x][next.y] != MARK){
            board[next.x][next.y] = MARK;
            path[next.x][next.y] = cnt+1;

            if(knighttour(n, m, next, cnt+1))
                return 1;

            board[next.x][next.y] = UNMARK;
        }
    }

    return 0;
} 

void printtour(int n, int m){
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            printf("%d ", path[i][j]);
        }
        printf("\n");
    }
}


int main(){
    int testcase, n, m, s, t;
    point start;

    scanf("%d", &testcase);

    for(int tc=0;tc<testcase;tc++){
        scanf("%d %d %d %d", &n, &m, &s, &t);
        start.x = s;
        start.y = t;

        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                board[i][j] = UNMARK;
            }
        }

        board[start.x][start.y] = MARK;
        path[start.x][start.y] = 1;

        if(knighttour(n, m, start, 1)){
            printf("1\n");
            printtour(n, m);
        }
        else printf("0\n");
    }

    return 0;
}