// 문제해결 프로젝트 5주차 과제 - 3A. 전화번호
// 192992 이준연
#include <cstdio> // 입출력 헤더파일

using namespace std;

const int MAX_TABLE_LENGTH = 10000;

// 입력: 전화번호의 개수 N, N개의 전화번호(4개의 자연수로 구성, 0000~9999)
// 출력: 전화번호 뒷자리 중 가장 많이 등장한 번호?(단, 횟수 같은 번호 2개 이상 --> 사전순으로 출력)

// cnt 배열(공간에 의미 부여!!)을 구하기 위한 함수!!
void fillFrequencyTable(int data[], int n, int table[]) {
    // 빈도수 변수 선언
    int freq_no = 0;

    for (int i = 0; i < MAX_TABLE_LENGTH; i++) {
        table[i] = 0;   // 일단 table의 모든 원소를 0으로 초기화한다
    }


    // 해당 데이터(전화번호) 나올 때마다 인덱스(테이블) 값 1씩 증가시키는 메소드
    for (int i = 0; i < n; i++) {
        freq_no = data[i];
        table[freq_no] += 1;
    }
}

int getFrequentNumber (int data[], int n) {
    // 0000~9999에서 가장 많이 등장한 번호를 찾으시오
    int freq_no = 0;
    int* table;

    table = new int[MAX_TABLE_LENGTH]; // 전화번호 넣을 배열 정의(0~9999) - 숫자 횟수 카운트하는 히스토그램!!
    fillFrequencyTable(data, n, table);

    for (int i=0; i<MAX_TABLE_LENGTH; i++){
        // frequent number 지속적으로 업뎃!!
        if(table[i] > table[freq_no]){  // 횟수 같은 번호가 2개인 경우?
            freq_no = i;
        }
    }

    return freq_no;
}

int main() {
    int n;

    scanf("%d", &n);
    int* data = new int[n]; // 전화번호 개수 만큼 동적 배열을 할당한다.

    for (int i = 0; i < n; ++i) {
        scanf("%d", &data[i]);
    }

    int answer = getFrequentNumber(data, n);// 입력받은 전화번호를 토대로, 가장 많이 등장한 번호 return한다.

    //네 자리로 출력(앞에 빈자리는 모두 0으로 채워준다)!!
    printf("%04d", answer);

    delete[] data;

    return 0;
}
