// 문제해결 프로젝트 5주차 과제 - 3B. 페인트
// 192992 이준연
#include <cstdio>
#include <iostream>

// 입력: 좌석 수 N, 색칠 할 방법의 수 M / 그 이후 나오는 세 정수(가장 왼쪽, 가장 오른쪽, 해당 구역에 칠할 색의 번호)
// 출력: 가장 많은 좌석이 가진 색, 가장 적은 좌석이 가진 색(단, 아무 좌석에도 칠해지지 않은 색은 제외함!!)
// if, 조건 만족하는 색이 2개 이상이면, 번호가 더 작은 색을 출력한다!!

const int MAX_SEAT_NUMBER = 1000;   // 전체 좌석 총 1000개
const int MAX_COLOR_NUMBER = 100;   // 전체 좌석 총 100개

// 페인팅 하는 경우를 클래스로 정의
class Painting {
    public:
        int left;
        int right;
        int color;
    
    Painting() {}

    // 생성자 정의
    Painting(int left, int rignt, int color) {
        this ->left = left;
        this -> right = right;
        this -> color = color;
    }
};

// 색상 빈도 별 테이블(히스토그램) 만들기
void fillFrequencyTable(int seats[], int n, int table[]) {
    // 일단 모든 색상의 빈도를 0으로 초기화한다
    for (int i = 0; i < MAX_COLOR_NUMBER; i++) {
        table[i] = 0;
    }

    // 이제 본격적으로 seats에 나온 정보를 기반으로 color table을 업데이트한다
    for (int j = 0; j < n; j++) {
        int color = seats[j];
        table[color] += 1;  // 해당 색상이 하나씩 나올 때마다 빈도를 1씩 추가한다!!
    }
}

// 별도의 함수를 통해 가장 많이 쓰인 색상, 가장 적게 쓰인 색상 정의
void solve(int n, int m, const Painting paints[]) {
    int *seats = new int[n];    // 좌석 나타내는 배열 선언

    // 일단 모든 좌석의 색상을 0으로 초기화한다!!
    for (int i = 0; i < n; i++) {
        seats[i] = 0;
    }

    // 색칠 이벤트를 본격적으로 실시 -> 색상 배열의 색 변경!!
    for (int i = 0; i < m; i++) {
        // 모든 색칠 정보 paints를 입력
        const Painting &p = paints[i];

        // 각 페인팅 정보에 따라 좌석의 색상 업데이트
        for (int j = p.left; j <= p.right; j++) {
            seats[j] = p.color;
        }
    }

    // 색칠 완료 후의 색상 정보를 기반으로, 모든 색상에 대한 빈도 수 테이블을 계산한다.
    int *table = new int[MAX_COLOR_NUMBER]; // 색상 빈도 수 테이블
    fillFrequencyTable(seats, n, table);    // 색상 별로 자리 수를 업데이트한다

    int minColor = seats[0];    // 가장 적게 등장한 색상
    int maxColor = seats[0];    // 가장 많이 등장한 색상

    for (int i = 0; i < MAX_COLOR_NUMBER; i++) {
        if (table[i] == 0) {
            // 한 번도 등장하지 않은 색상은 제외한다!!
            continue;
        }

        if (table[minColor] > table[i]) {
            // minColor 갱신하기
            minColor = i;
        }

        if (table[maxColor] < table[i]) {
            maxColor = i;
        }
    }

    printf("%d", maxColor);
    printf("%d", minColor);

    delete[] table;
}

// 일단 메인 함수부터 선언
int main() {
    int n, m;   // 각각 좌석의 수, 색칠할 방법의 수
    scanf("%d %d", &n, &m);

    Painting* paints = new Painting[m];

    for (int i = 0; i < m; i++) {
        scanf("%d", &paints[i].left);
        scanf("%d", &paints[i].right);
        scanf("%d", &paints[i].color);

        // 좌석 번호는 1번부터 시작, but 위 클래스는 0번부터 시작
        paints[i].left -= 1;
        paints[i].right -= 1;
    }

    // 정답(별도의 함수 정의)
    solve(n, m, paints);

    return 0;
}