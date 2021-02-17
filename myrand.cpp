#include <random>

int myrand() {
    return rand() % 1000000000;
}

int myrand(int end) {
    return rand() % end;
}

template <typename T>
T myrand(T start, T end) {
    return rand() % (end - start) + start;
}
