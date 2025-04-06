// Copyright 2021 NNTU-CS
int countPairs1(int *arr, int len, int value) {
    int cnt = 0;
    for (int i = 0; i < len; ++i) {
        for (int j = i + 1; j < len; ++j) {
            if (arr[i] + arr[j] == value) {
                ++cnt;
            }
        }
    }
    return cnt;
}

int countPairs2(int *arr, int len, int value) {
    int cnt = 0;
    int l = 0;
    int r = len - 1;
    while (l < r) {
        int sum = arr[l] + arr[r];
        if (sum == value) {
            ++cnt;
            ++l;
        }
        else if (sum < value) {
            ++l;
        }
        else {
            --r;
        }
    }
    
    return cnt;
}

int countPairs3(int *arr, int len, int value) {
    int cnt = 0;
    for (int i = 0; i < len; ++i) {
        int x = value - arr[i];
        int lg = i + 1;
        int hg = len - 1;
        while (lg <= hg) {
            int sr = (lg + hg) / 2;
            if (arr[sr] == x) {
                ++cnt;
                break;
            }
            else if (arr[sr] < x) {
                lg = sr + 1;
            }
            else {
                hg = sr - 1;
            }
        }
    }
    return cnt;
}
