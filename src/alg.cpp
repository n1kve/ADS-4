// Copyright 2021 NNTU-CS
#include <algorithm>
int countPairs1(int *arr, int len, int value) {
    int cnt = 0;
    for (int i = 0; i < len; i++) {
        for (int j = i + 1; j < len; j++) {
            if (arr[i] + arr[j] == value) {
                cnt++;
            }
        }
    }
    return cnt;
}

int countPairs2(int *arr, int len, int value) {
    int cnt = 0;
    for (int i = 0; i < len - 1; i++) {
        for (int j = len - 1; j > i; j--) {
            if (arr[i] + arr[j] == value) {
                cnt++;
            }
        }
    }
    return cnt;
}

int countPairs3(int *arr, int len, int value) {
    int cnt = 0;
    std::sort(arr, arr + len);
    for (int i = 0; i < len; ++i) {
        int x = value - arr[i];
        int lg = i + 1;
        int hg = len - 1;
        while (lg <= hg) {
            int sr = (lg + hg) / 2;
            if (arr[sr] == x) {
                ++cnt;
                int temp = sr;
                while (temp - 1 >= lg && arr[temp - 1] == x) {
                    ++cnt;
                    --temp;
                }
                temp = sr;
                while (temp + 1 <= hg && arr[temp + 1] == x) {
                    ++cnt;
                    ++temp;
                }
                break;
            } else if (arr[sr] < x) {
                lg = sr + 1;
            } else {
                hg = sr - 1;
            }
        }
    }
    return cnt;
}
