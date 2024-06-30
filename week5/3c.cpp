// 문제해결 프로젝트 5주차 과제 - 3C. 응모
// 192992 이준연

#include <cstdio>
#include <vector> // 벡터 컨테이너 선언 위한 헤더파일!!

using namespace std;

const int MAX_SERIAL_NUMBER = 100000;

// 입력: 데이터의 수 N, 다음 줄에는 응모한 시리얼 번호 입력
// 출력: 응모한 모든 시리얼 번호 중, 두 번 이상 응모한 번호 제외하고 나머지 번호들을 공백으로 구분 후 오름차순 출력 
// 많은 숫자 데이터를 정렬, 자료구조 등을 사용하지 않고 배열만으로 처리하라?

// serial number 별로 빈도 측정하는 테이블 선언
void fillFrequencyTable(const vector<int> &data, int n, vector<int> &table) {
    table.clear();  // 벡터 일단 초기화
    table.resize(MAX_SERIAL_NUMBER + 1, 0); // 벡터의 크기를 재할당한다

    for (int i = 0; i < n; i++) {
        int serial = data[i];
        table[serial] += 1; // 본격적으로 테이블 통해 빈도 수 데이터를 채워 나감
    }
}

// data[0] ~ data[n-1] 중에서 중복이 없는 원소들 반환!!
vector<int> getUniqueElements(const vector<int> &data, int n) {
    vector<int> ret;    //  유일한 원소들을 담을 배열 선언(배열과 달리, 고정 사이즈 아님) -> 이래서 이 문제부터 배열 대신 벡터를 쓰는건가..?

    // 각 데이터에 대한 빈도 수 테이블 계산!!
    vector<int> table;
    fillFrequencyTable(data, n, table);

    for (int number = 0; number <= MAX_SERIAL_NUMBER; number++) {
        // 조회 가능한 모든 시리얼 넘버에 대해 조회!!
        if (table[number] == 1) {
            // 한 번만 등장한 number를 차례로 정답 벡터에 추가!!
            ret.push_back(number);
        }
    }

    // 이미 오름차순으로 추가했기에, ret를 따로 정렬할 필요는 X(이미 인덱스가 오름차순인 table을 참조했기 때문)
    return ret;
}

int main() {
    int n;
    scanf("%d", &n);    // 데이터의 수 n

    vector<int> data = vector<int>(n);  // 응모할 시리얼 번호들 벡터(메모리 자동 할당)

    for (int i = 0; i < n; i++) {
        scanf("%d", &data[i]);  // 시리얼 번호 입력!!
    }

    const vector<int> answer = getUniqueElements(data, n);

    // 각 원소들을 출력한다
    for (int i = 0; i < answer.size(); i++) {
        if (i > 0) {
            // 첫 원소가 아니라면 앞에 공백 하나 추가!!
            printf(" ");
        }
        printf("%d", answer[i]);
    }

    return 0;
}