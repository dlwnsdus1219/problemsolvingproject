// 문제해결 프로젝트 프로젝트4 - 1. 행사
// 192992 이준연
#include <iostream>
#include <vector>
#include <iomanip>
#include <algorithm>
#include <cmath>
#include <queue>
#include <random>
#include <time.h>    // 코드의 구동 시간 측정을 위해 해당 라이브러리를 설치해준다


using namespace std;

// 좌표평면 위 참가자의 집 좌표 클래스로 표현
class Map {
    public:
        int x;
        int y;

        // Map 클래스의 생성자
        Map(int x, int y) {
            this -> x = x;
            this -> y = y;
        }
};

// 맨해튼 거리의 합이 최소가 되는 점 == 각 점 좌표들의 중간값(median)!!
vector<int> findMedian(vector<int>& v) {
    priority_queue<int> max_pq; // 최대 힙(큰 수부터 pop)
    priority_queue<int, vector<int>, greater<int>> min_pq;  // 최소 힙(작은 수부터 pop)
    vector<int> answer; // 중간값 원소들을 저장할 자료형 선언

    // 최대 힙, 최소 힙의 성질을 이용하여 중간값을 찾아준다!!
    for (int i = 0; i < v.size(); i++) {
        // max_pq에 더 많은 수가 있으면, min_pq에 대입한다
        if (max_pq.size() > min_pq.size()) {    
            min_pq.push(v[i]);
        } else {
            max_pq.push(v[i]);
        }

        if (!max_pq.empty() && !min_pq.empty()) {
            // max_pq의 top 원소가 min_pq의 top 원소보다 클 때, 둘의 자리를 swap한다(max_pq는 중간값 기준으로 더 작은값들이, min_pq는 더 큰 값들이 와야하기 때문!!)
            if (max_pq.top() > min_pq.top()) {
                // 기존 top 원소를 먼저 임의의 변수에 대입
                int a = max_pq.top();
                int b = min_pq.top();

                // 기존 top 원소는 pop으로 제거
                max_pq.pop();
                min_pq.pop();

                // 앞에서 저장했던 원소를, 서로 큐를 바꿔서 push한다
                max_pq.push(b);
                min_pq.push(a);
            }
        }
    }

    // 비교하고자 하는 원소의 개수가 홀수 개 -> 결국 마지막에 대입되는 원소는 max_pq의 top 원소로 남아, 결국 이 값이 중간값으로 남게 된다!!
    if (max_pq.size() != min_pq.size()) {
        answer.push_back(max_pq.top());
    } else {
        // 비교하고자 하는 원소의 개수가 짝수 개 -> max_pq의 top 원소와 min_pq의 top 원소 그 사이에 있는 값들이 모두 중간값으로 남게 된다!! -> 모두 answer에 저장
        for (int k = max_pq.top(); k <= min_pq.top(); k++) {
            answer.push_back(k);
        }
    }

    return answer;
}


int main() {
    int n;  // 전체 참가 인원
    std::cin >> n;

    vector<int> xd; // 참가자 주소의 x값 저장
    vector<int> yd; // 참가자 주소의 y값 저장

    vector<Map> player; // n명의 참가자들의 거주지를, 하나의 벡터로 저장

    vector<Map> event;  // 행사를 개최할 장소의 좌표를 저장할 벡터

    for (int i = 0; i < n; ++i) {   // 전체 인원수만큼 반복
        int xp, yp;
        cin >> xp >> yp;  // 각각 플레이어의 x좌표, y좌표 입력
        player.push_back(Map(xp, yp)); // 각 좌표를 player 벡터에 저장한다
    }
    
    //clock_t: clock_ticks의 자료를 담고 있는 자료형으로, clock()의 반환형이다!!
    clock_t start = clock(); // 시작 시간 저장

    // 각 플레이어의 x좌표, y좌표 따로 각각의 벡터에 넣는다(추후에 findMedian 연산을 하기 위해)
    for (int i = 0; i < player.size(); i++) {
        xd.push_back(player[i].x);
        yd.push_back(player[i].y);
    }

    vector<int> ak = findMedian(xd);    // 행사장 위치의 x값 후보들의 모임
    vector<int> bk = findMedian(yd);    // 행사장 위치의 y값 후보들의 모임

    // 앞에서 구한 x좌표값, y좌표값들의 후보들을 조합하여 행사장의 좌표를 생성한다.
    for (int i = 0; i < ak.size(); i++) {
        for (int j = 0; j < bk.size(); j++) {
            event.push_back(Map(ak[i], bk[j]));
        }
    }

    //랜덤 추출을 위해, 난수 생성기를 초기화한다
    std::random_device rd;  // 난수 생성기 장치
    std::mt19937 gen(rd()); // Mersene Twister 엔진 사용한 난수 생성기
    std::uniform_int_distribution<> dis(0, event.size() - 1);

    int rand_idx = dis(gen);    // 임의의 랜덤 인덱스 추출
    
    std::cout << event[rand_idx].x << " " << event[rand_idx].y << std::endl;    // 임의의 좌표값을 출력한다!!



    clock_t end = clock(); // 코드가 끝난 시간 저장!!

    // 걸린 시간 출력
    std:cout << "걸린 시간: " <<  (double)(end - start)/CLOCKS_PER_SEC << "초" << std::endl;

    return 0;
}




