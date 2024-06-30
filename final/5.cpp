// 기말고사 5번 - 192992 이준연
#include <iostream>
#include <stdio.h>
#include <cstdio>

using namespace std;

class Gridbools {
    public:
        int w;
        int h;
        int x;
        int y;

        Gridbools(int w, int h, int x, int y) {
            this -> w = w;
            this -> h = h;
            this -> x = x;
            this -> y = y;
        }
}


int main() {
    int w, h;   // 격자의 가로, 세로
    int p, q;   // 초기 위치의 좌표값
    int t;  // 개미가 움직이는 시간

    bool changex;
    bool changey;

    cin >> w >> h;
    cin >> p >> q;
    cin >> t;

    for (int i = 0; i < t; i++) {
        if (p == w) {
            p -= 1;
            
        }

        if (p >= 0) {
            p += 1;
        }

        if (q >= 0) {
            q += 1;
        }

        if (q == h) {
            q -= 1;
        }
        
    }


}