#include <iostream>
#include <vector>

using namespace std;


int divisibleSumPairs(int size, int divisor, vector<int> arrray) {
    int answer = 0;

    vector<int> remainderCounts(divisor, 0);
    for (int i = 0; i < size; i++) {
        arrray[i] %= divisor;
        int difference = divisor - arrray[i];
        difference %= divisor;
        answer += remainderCounts[difference];
        remainderCounts[arrray[i]]++;
    }
    return answer;
}

int main() {
    std::vector arr = {1, 2, 3, 4, 5, 6};
    int n = 6;
    int k = 3;
    std::cout << divisibleSumPairs(n, k, arr) << std::endl;
    return 0;
}

