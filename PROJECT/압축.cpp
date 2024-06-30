// 문제해결프로젝트 프로젝트 5 - 압축(5점)
// 192992 이준연
#include <iostream>
#include <vector>
#include <map> // map 자료형 사용을 위해 선언함
#include <iomanip>
#include <string>
#include <limits.h>
#include <algorithm>
#include <cmath>    // abs(절댓값) 연산을 사용하기 위함
#include <random>
#include <time.h>    // 코드의 구동 시간 측정을 위해 해당 라이브러리를 설치해준다

using namespace std;

// 변환 비용 계산하기
int cost(int k, int w, int sl) {
    return k + w * sl;
}

// 변환 비용을 최소로 해 주는 숫자 찾기(첫 번째 숫자 한정)
int changeNumberFirst(map<int, string> &m, int a, int err, int w, int length) {
    map<int, string>::iterator it;
    int minValue = INT_MAX; // 일단 int형의 최댓값으로 설정(차차 비교하면서 바꿔나갈 거기 때문)
    int minidx = -1;

    for (it = m.begin(); it != m.end(); it++) {
        int val = cost(err + abs(a - it -> first), w, length);  // length가 수시로 바껴야 하는데.....
        if (val < minValue) {   // 앞의 값들과 비교하며 minValue 값을 차차 바꿔나간다
            minValue = val;
            minidx = it -> first;
        }
    }

    return minidx;  // 여기서 반환되는 minidx는 일차적으로 변환할 level에 관한 것!!
}

// 변환 비용을 최소로 해 주는 숫자 찾기(그 이후 자리 숫자들)
int changeNumberThen(map<int, string> &m, int a, int b, int err, int w, int length) {
    map<int, string>::iterator itt;
    int minValue = INT_MAX;
    int minidx = -1;

    for (itt = m.begin(); itt != m.end(); itt++) {
        // 2번째 이후 자리 원소들은 앞의 자리 level과 비교가 필요하므로, 파라미터를 하나 더 추가한 모습(앞의 자리 level 수와 비교)
        if (itt -> first == b) {
            length += 1;    // 바로 앞의 수가 같은 수? -> 0 하나만 뒤에 추가되므로 length에 +1만 한 값이 변환 비용 계산에 사용된다
        } else {
            length += 3;    // 바로 앞의 수와 다른 수? -> 1 + 기존 code 하면 총 length가 3이 길어지므로, length + 3이 변환 비용 계산에 사용된다.
        }
        int val = cost(err + abs(a - itt -> first), w, length);  // 위에서 변환해 준 임시 length로 변환 비용을 구한다
        if (val < minValue) {
            minValue = val;
            minidx = itt -> first;
        }
    }

    return minidx;  // 변환 비용을 최소로 만들어주는 level의 숫자 반환
}

// 기존 수열을 하나의 코드로 변환하는 함수
void changeSooyeol(map<int, string> &m, vector<int> &v, int w) {
    int length = 2; // 처음에는 그냥 무작정 2자리 수로 바꾸므로!!
    int error = 0;  // 전체 에러를 저장할 변수(초기값은 일단 0)
    vector<int> changed;    // 1차적으로 바꿀 수열(level)을 저장

    changed.push_back(changeNumberFirst(m, v[0], error, w, length)); // 어느 level의 수로 바꾸면 변환 비용이 최소로 될 것인가?
    string s = m[changeNumberFirst(m, v[0], error, w, length)];   // map을 활용해, 앞에서 구한 level의 수와 대치되는 code를 문자열에 추가한다
    error += abs(v[0] - changed[0]);    // 전체 에러에 현 상태에서의 에러값 추가(계속 누적해서 계산해야 하기 때문)

    // 앞서 입력한 수열의 2번째 부터 끝번째 원소까지 for문으로 계산한다
    for (int i = 1; i < v.size(); i++) {
        int newNum = changeNumberThen(m, v[i], changed[i-1], error, w, length);
        changed.push_back(newNum);  // 여기까지, 일차적으로 어느 level의 수로 변환되어야 할지 결정

        // 이제 전체 length 길이를 수정하고 code에도 추가 작업을 수행한다
        if (changed[i-1] == changed[i]) {
            length += 1;
            s.append("0");  // 앞의 글자와 같으면 0으로 대치
            error += abs(v[i] - changed[i]);    // 전체 error 값도 계속 갱신해준다.
        } else {
            length += 3;
            // changed.push_back(changeNumber(m, v[i], error, w, length));
            s.append("1");  // 앞의 글자와 같으면 1 + 기존 code로 대치
            s.append(m[newNum]);
            error += abs(v[i] - changed[i]);
        }
    }
    
    std::cout << cost(error, w, s.size()) << std::endl;
    std::cout << s << std::endl;
}


int main() {
    int n;  // 수열의 길이
    int w;  // 가중치의 크기

    vector<int> sooyeol;    // 입력된 수열 나타내는 벡터 선언
    map<int, string> table;

    table.insert(pair<int, string>(1, "00"));
    table.insert(pair<int, string>(86, "01"));
    table.insert(pair<int, string>(172, "10"));
    table.insert(pair<int, string>(256, "11"));


    std::cin >> n >> w;

    // 수열의 길이만큼, 정수를 수열 내에 push back 한다!!
    for (int i= 0; i < n; i++) {
        int c;
        std::cin >> c;
        sooyeol.push_back(c);
    }

    //clock_t: clock_ticks의 자료를 담고 있는 자료형으로, clock()의 반환형이다!!
    clock_t start = clock(); // 시작 시간 저장

    // 실행 코드 입력 
    changeSooyeol(table, sooyeol, w);
    
    clock_t end = clock(); // 코드가 끝난 시간 저장!!

    // 걸린 시간 출력
    std:cout << "걸린 시간: " <<  (double)(end - start)/CLOCKS_PER_SEC << "초" << std::endl;
}