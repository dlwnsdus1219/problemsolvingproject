// 문제해결 프로젝트 4주차 과제 - 2F. 데스티니
// 192992 이준연
// 천체들 간 거리 측정--> 가장 가까이 있는 두 천체를 찾아라?
#include <cstdio>
#include <climits>  // 각 자료형의 최대
#include <iostream>
#include <cmath>    // 내장 수학 라이브러리

using namespace std;

class Point2D{
    private:
        int x;
        int y;

    public:
        // 외부에서 접근을 위해 아래와 같이 생성자 선언
        Point2D(int x = 0, int y = 0) {
            this -> x = x;
            this -> y = y;
        }

        // 2차원 점들 간 제곱 거리의 계산
        int getSquaredDistanceTo(const Point2D &target) const {
            int dx = abs(this -> x - target.x);
            int dy = abs(this -> y - target.y);
            return dx * dx + dy * dy;
        }

        // 앞서 구한 제곱 거리에 root를 씌운다
        double getDistanceTo(const Point2D& target) {
            double sqd = (double) this -> getSquaredDistanceTo(target); // 형변환 먼저 ㄱㄱ
            return sqrt(sqd);
        }
};

// main 함수 선언
int main() {
    int n;  // 점의 개수 선언
    scanf("%d", &n);

    Point2D* points;
    points = new Point2D[n];    // Point2D 배열 생성
    
    for (int i = 0; i < n; i++) {
        // n개의 좌표 입력
        int x, y;
        scanf("%d %d", &x, &y);

        points[i] = Point2D(x, y);   // Points 배열에 대입 ㄱㄱ
    }

    int min_sqd = INT_MAX;  // int형의 최댓값으로 일단 초기화
    int min_cnt = 0;

    for (int i = 0; i < n; i++) {
        // 첫 번째 쌍부터 순차적으로 뒤에 있는 쌍들과의 거리를 구한다
        for (int j = 0; j < i; j++) {
            int sqd = points[i].getSquaredDistanceTo(points[j]);
            if (sqd < min_sqd) {
                // 최소 거리 구하기
                min_sqd = sqd;
                min_cnt = 1;    // 해당 최소 거리 가진 점의 쌍 개수도 1로 초기화
            } else if(sqd == min_sqd) {
                // 최소 거리 가진 쌍 개수 update ㄱㄱ
                min_cnt++;
            }
        }
    }

    double distance = sqrt(min_sqd);
    printf("%.1f\n", distance); // 반올림 -> 소수점 첫째 자리까지 표현한다!!
    printf("%d\n", min_cnt);

    delete[] points;
    return 0;
}