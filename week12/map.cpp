#include <map>
#include <string>
#include <stdio.h>

using namespace std;

int main() {
    map<char*, string> sMap;    // 둘 다 문자열이지만, char&*는 정렬되지 않음

    sMap["중국"] = "China";
    sMap["미국"] = "United States";
    sMap["일본"] = "Japan";
    sMap["한국"] = "Korea";

    map<char*, string>::iterator itStrMap;

    printf("sMap\n");
    for (itStrMap = sMap.begin(); itStrMap != sMap.end(); itStrMap++) {
        printf("%s: %s\n", itStrMap -> first, itStrMap -> second.c_str());
    }
    printf("\n");   // 마지막에 넣은 한국이 제일 먼저 출력

    sMap.erase("일본");

    printf("sMap\n");
    for (itStrMap = sMap.begin(); itStrMap != sMap.end(); itStrMap++) {
        printf("%s: %s\n", itStrMap -> first, itStrMap -> second.c_str());
    }
    printf("\n");   // 마지막에 넣은 한국이 제일 먼저 출력
}
