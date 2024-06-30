// 문제해결 프로젝트 11주차 실습과제 - 6I. 정사각형
// 192992 이준연
#include <iostream>
#include <iomanip> // 입, 출력 데이터의 스트림 제어!!
#include <vector>
#include <cmath>
#include <set>
#include <algorithm>

// N개의 점에 대한 좌표 중, 4개를 골라 만들 수 있는 정사각형의 넓이 중 가장 큰 넓이는?

// 입력: 테스트 케이스 개수 T, 그 이후 각 줄에다가 테스트 케이스 입력(첫 줄에는 좌표의 수 N, 이후 N줄에 거쳐서 각 점들의 X좌표, Y좌표 입력!!)
// 출력: 각 테스트 케이스에 대한 정답 출력

using namespace std;

// 좌표평면 위의 점 정의할 Class 선언!!
class Point2D{
    public:
        int x;
        int y;
        int index;

        Point2D(int i, int x, int y) {
            this -> index = i;
            this -> x = x;
            this -> y = y;
        }

        // 인덱스 입력 안 받을 때의 Point2D 클래스 생성자?
        Point2D (int x, int y) {
            this -> index = 1;
            this -> x = x;
            this -> y = y;
        }

        // 두 점을 기준으로 해당 사각형이 정사각형인지 판단? -> 2개의 좌표를 기준으로 삼아 dx, dy를 더해주는 형태로 구한다!!
        // 예를 들어 한 변 위에 있는 2개의 좌표가 정해지고 나면, 해당 점으로부터 dx dy를 더해주고 -dy dx를 가로 세로에 더해준 점이 존재하는지 확인한다
        // 즉, 한 변위에 있는 2개의 점을 기준으로 정사각형인 점의 위치를 계산해서 존재 여부를 판단하여 정사각형의 여부를 판단한다
        long long getSquaredDistanceTo(Point2D target) {
            // 두 좌표 간의 제곱거리를 계산한다!!
            long long dx = abs(this -> x - target.x);
            long long dy = abs(this -> x - target.y);
            return dx * dx + dy * dy;   // 두 타겟 간의 제곱 거리 반환
        }

        // Point2D 객체 간 대소 관계 정의!!
        bool operator < (const Point2D& other) const {
            // x좌표가 다르면, x좌표 기준으로 비교 ㄱㄱ'
            if (this -> x != other.x) {
                return this -> x < other.x;
            }

            // x좌표가 같으면, y좌표를 기준으로 비교!!
            return this -> y < other.y;
        }
};

// 각 테스트 케이스 별로 최대의 정사각형 넓이를 구하는 함수
long long getMaximumSquareArea(int n, const vector<Point2D>& points) {
    long long answer = 0;   // 초기값은 0으로 일단 선언

    // 모든 점을 set에 일단 저장(중복 점 제거)
    set<Point2D> pSet;  // 기본값은 less(오름차순), dataType이 class이므로 대소 관계를 정의할 필요가 있어 보임.
    for (int i = 0; i < n; i++) {
        // pSet에 일단 점들을 모두 삽입한다(자연스러운 중복 제거)
        pSet.insert(points[i]);
    }

    // 임의의 두 점 a, b
    for (int i = 0; i < n; i++) {
        Point2D pa = points[i];
        for (int j = 0; j < n; j++) {
            Point2D pb = points[j];

            if (i == j) {
                // 같은 점은 모두 제외시킨다
                continue;
            }

            // 일단 pa - pb가 정사각형의 한 변이라 가정(제곱 거리를 구한다)
            long long area = pa.getSquaredDistanceTo(pb);

            // 이미 구한 사각형보다 넓이가 작을 수밖에 없다 -> 건너뜀(우리의 목적은 최대 넓이이므로!!)
            if (area < answer) {
                continue;
            }

            // pa -> pb 방향의 x, y 좌표 거리
            int dx = pb.x - pa.x;
            int dy = pb.y - pa.y;

            // 벡터 dx, dy를 90도 회전 -> <-dy, dx>
            // pa와 pb에 벡터 <-dy, dx>를 각각 더하여 정사각형 구성하는 pd, pc도 찾는다!
            Point2D pd(pa.x - dy, pa.y + dx);
            Point2D pc(pb.x - dy, pb.y + dx);

            // pd, pc가 위 set에 있으면 아래 메소드를 갱신한다!!
            if (pSet.find(pc) != pSet.end() && pSet.find(pd) != pSet.end()) {
                answer = max(answer, area);
            }
        }
    }


}

// 프로세스 함수 정의
void process(int caseIndex) {
    int n;  // 테스트 케이스(점) 수 입력
    cin >> n;

    vector<Point2D> points; // 각 좌표를 삽입할 Point2D 클래스의 벡터를 선언 

    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        points.push_back(Point2D(i, x, y));    // 각 좌표를 삽입
    }

    double answer = getMaximumSquareArea(n, points);    // 각 테스트 케이스에 대해 최대 넓이 구하기(출력 형식 고려하여 double로 선언)

    cout << fixed << setprecision(2) << answer << endl;     // 고정 소수점 2자리까지 출력하라!!
}

// main 함수 정의
int main() {
    int caseSize;
    cin >> caseSize;    // 테스트 케이스 개수를 입력한다

    for (int caseIndex = 1; caseIndex <= caseSize; caseIndex += 1) {
        // 각 테스트 케이스 별로 프로세스를 수행한다!!
        process(caseIndex);
    }
}