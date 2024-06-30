// 문제해결 프로젝트 10주차 실습과제 - 6G. 불안정 지역
// 192992 이준연

#include <iostream>
#include <queue>
#include <vector>

// 입력: 테스트 케이스 개수 T, 
// 각 테스트 케이스 순차적으로 입력(첫 줄 - 도시의 수, 한 조사 영역이 포함하는 연속된 도시의 수), 다음 줄에는 각 도시의 소득 수준을 N개의 자연수로 나타낸다
// 출력: 각 테스트 케이스에 대한 정답 출력(연속한 K개의 도시로 이루어진 영역 중 가장 큰 소득차 가지는 영역의 소득차?)
// 시간 복잡도는 O(n * k)

using namespace std;

class City {
    public:
        int index;  // 도시 인덱스
        int income; // 해당 도시의 소득
        
        City(int index, int income) {
            this -> index = index;
            this -> income = income;
        }

        // 대소 관계 추가
        bool operator < (const City& o) const {
            // less
            return this -> income < o.income;
        }
        bool operator > (const City& o) const {
            // greater
            return this -> income > o.income;
        }
};

// 가장 큰 도시 간 소득 차 구하기
int getMaximumRangeDifference(int n, int k, const vector<City>& cities) {
    int answer = 0;// 초기값은 0으로 일단 초기화

    // 소득이 가장 적은 도시부터 pop되는 우선순위 큐(오름차순)
    priority_queue<City, vector<City>, greater<City>> rangeMinimum;

    // 클래스의 경우. 무엇을 대소관계 적용하여 결과를 낼 지 모른다 -> 클래스 멤버 함수 내 연산자 오버로딩 통해 대소관계 정의!!

    // 소득이 가장 높은 도시부터 pop되는 우선순위 큐(내림차순)
    priority_queue<City> rangeMaximum;  // 아래 default 값에서 뒤의 2개 파라미터가 생략!!
    // default: priority_queue<City, vector<City>, less<City>> rangeMaximum;

    // 기존 2중 for문 O(n*k)에서 O(n)으로 훨씬 빠르고 효율적인 코딩 가능!!

    // 먼저 첨부터 k - 1번째 도시까지 각각 큐에 저장한다
    for (int i = 0; i < k - 1; i++) {
        rangeMaximum.push(cities[i]);   // 큰 값부터 작은 값가지 차례로 저장
        rangeMinimum.push(cities[i]);   // 작은 값부터 큰 값까지 차례로 저장
    }

    // 그 이후 도시들도 똑같이 큐에 저장 수행!!
    for (int i = k - 1; i < n; i++) {
        rangeMaximum.push(cities[i]);   // 큰 값부터 작은 값가지 차례로 저장
        rangeMinimum.push(cities[i]);   // 작은 값부터 큰 값까지 차례로 저장
        // rangeMaximum: top값이 max, rangeMinimum: top 값이 min
        // k개의 자연수 범위 내에서 최대, 최소값 각각 없에기(rangeMaximum, rangeMinimum)
        while (rangeMaximum.top().index < i - k + 1){
            rangeMaximum.pop();
        } 
        while (rangeMinimum.top().index < i - k + 1) {
            rangeMinimum.pop();
        }
        // 기존 answer와 현재 range 내 min, max 값의 차이를 수시로 비교하며 answer 값을 상시로 업데이트한다!!
        answer = max(answer, rangeMaximum.top().income - rangeMinimum.top().income);

    }
    

    return answer;
}

void process(int caseIndex) {
    int n, k;   // n은 도시 수, k는 한 조사 영역이 포함하는 연속한 도시 수
    cin >> n >> k;

    vector<City> cities;    // 조사할 도시들을 담을, City 클래스 기반의 벡터 선언!!

    for (int i = 0; i < n; i += 1) {
        int income;
        cin >> income;  // n개 도시들의 소득 수준을 입력!!
        cities.push_back(City(i, income));  // 각 도시들을 벡터 내에 push back
    }

    int answer = getMaximumRangeDifference(n, k, cities);   // 가장 큰 소득차를 가지는 영역의 소득차는?

    cout << answer << endl;
}

int main() {
    int caseSize;
    cin >> caseSize;    // 테스트 케이스 수 입력

    for (int caseIndex = 1; caseIndex <= caseSize; caseIndex += 1) {
        process(caseIndex);  // 각 테스트 케이스 마다 process 수행
    }
}