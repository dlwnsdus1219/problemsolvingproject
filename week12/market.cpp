// 문제해결 프로젝트 12주차 실습과제 - 6K. 시장 추천하기
// 192992 이준연
#include <iostream>
#include <string>
#include <map>

// N개의 투표용지와 각 투표용지에 적힌 후보자의 이름이 주어졌을 때 가장 많는 표 얻은 후보자의 이름을 출력하시오?
// (단, 모든 후보자는 서로 다른 이름을 갖고있으며 같은 표수를 얻은 후보는 여러 명 존재 가능하다)

// 입력: 투표용지 개수 N, 이후 N줄에 거쳐서 각 후보자 이름 입력
// 출력: 첫 줄에는 가장 많는 표 획득한 후보자의 표 수, 둘째 줄에는 해당 표 수만큼 표 얻은 후보들의 이름을 공백으로 구분하여 사전순-오름차순 출력한다

using namespace std;

int main() {
    int N;  // 투표용지의 개수 N
    cin >> N;

    map<string, int> freqMap;
    int maxFrequency = 0;   // 최다 득표 후보(차차 갱신 예정)

    // 각 후보자의 이름 하나씩 추가 시마다, 최다 득표 후보 리스트를 갱신한다!!
    for (int i = 0; i < N; i++) {
        string s;
        cin >> s;
        freqMap[s]++;   // 최다 득표 수 증가

        int k = freqMap[s]; // 최다 득표 후보?
        if (k > maxFrequency) {
            // 최다 득표 후보를 갱신한다(기존 값보다 크면 바꾸기)
            maxFrequency = k;
        }

        // 최다 득표 후보 출력
        cout << maxFrequency << endl;

        // 최다 득표 후보 이름, 사전순 출력
        map<string, int>::iterator it;
        for (it = freqMap.begin(); it != freqMap.end(); it++) {
            if (it -> second == maxFrequency) {
                // 해당 value에 맞는 key 값 출력
                printf("%s", it -> first.c_str());  //c_str는 문자열 출력 시 반드시 필요함!!
            }
        }

    }
}
// 쌍으로 이루어진 데이터를 활용한 문제 해결할 때, Map을 이용하여 쉽고 효율적으로 풀 수 있다!!