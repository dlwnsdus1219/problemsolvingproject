// 문제해결 프로젝트 7주차 실습 과제 - 5H. 두 직사각형
// 192992 이준연
#include <iostream>
#include <cstdio>

using namespace std;

/* 입력: 테스트 케이스 수 T, 
다음 줄부터는 각 테스트케이스 입력
(각 점 A, B, P, Q의 X, Y좌표를 입력)*/

/* 출력: 각 테스트케이스에 대해 한 줄에 두 직사각형이 교차하는 영역의 넓이를 구하시오?*/

int get_area(int la, int ra, int ta, int ba, int lb, int rb, int tb, int bb) {
    int l, r, t, b;
    // 두 사각형이 교차하는 부분의 좌표 구하기
    l = max(la, lb); 
    r = min(ra, rb);
    t = min(ta, tb);
    b = max(ba, bb);

    // 앞서 구한 l좌표가 r좌표보다 왼쪽에 있고, b좌표가 t좌표보다 아래에 있으면 직사각형의 넓이를 계산 후 출력한다.
    if(l <= r && b <= t) {
        return ((r - l) *(t - b));
    }

    return 0; // 중첩 부분 없다면 0을 반환한다!!
}

void test_case() {
    int ax, ay, bx, by;
    int px, py, qx, qy;
    scanf("%d %d %d %d", &ax, &ay, &bx, &by);
    scanf("%d %d %d %d", &px, &py, &qx, &qy);

    // 직사각형 A
    int la, ra, ba, ta;
    la = min(ax, bx); // 2개의 x좌표 중 더 작은 값이 왼쪽 a
    ra = max(ax, bx); // 2개의 x좌표 중 더 큰 값이 오른쪽 a
    ta = max(ay, by); // 2개의 y좌표 중 더 큰 값이 위쪽 a
    ba = min(ay, by); // 2개의 y좌표 중 더 작은 값이 아래쪽 a

    // 직사각형 B(직사각형 A 좌표 구하는 것과 동일)
    int lb, rb, bb, tb;
    lb = min(px, qx);
    rb = max(px, qx);
    tb = max(py, qy);
    bb = min(py, qy);

    // 중첩 부분의 넓이를 구해준다!!
    int answer = get_area(la, ra, ta, ba, lb, rb, tb, bb);

    printf("%d\n", answer);

}

int main() {
    int t;  // 테스트 케이스 개수
    
    scanf("%d", &t); // 테스트 케이스 수 입력

    // test case 수 만큼 중첩 부분 넓이 구하는 작업 반복한다
    for(int i = 0; i < t; i++) {
        test_case();
    }
    return 0;
}