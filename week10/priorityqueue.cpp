#include <iostream>
#include <queue>

using namespace std;

struct Custom {
    int x;
    int y;
    int value;
    Custom(int value) : x(0), y(0), value(value){

    }
};

// 오름차순 정렬
struct cmp {
    bool operator()(Custom t, Custom u) {
        return t.value > u.value;
    }
};

int main() {
    // 우선순위 큐
    priority_queue<Custom, vector<Custom>, cmp> pq;

    // push(element)
    pq.push(Custom(5));
    pq.push(Custom(2));
    pq.push(Custom(8));
    pq.push(Custom(9));
    pq.push(Custom(1));
    pq.push(Custom(14));
}