// 기말고사 3번 - 192992 이준연
#include <map>
#include <iostream>
#include <stdio.h>
#include <set>
#include <queue>
#include <cstdio>

using namespace std;

int main() {
    map<string, int> hubo;  // 후보자 이름, 득표수 관리 맵
    set<int> s;
    int maxvalue = 0;
     
    cin >> n;


    // 각 후보자의 이름이 나올 때마다 하나씩 표 수 증가한다
    for (int i = 0; i < n; i++) {
        cin >> s;
        hubo[s]++;
    }

    map<string, int>::iterator it;

    for (it = hubo.first(); it = hubo.end(); it++) {
        set.insert(it -> second);
    }
}