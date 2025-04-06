// Copyright 2021 NNTU-CS
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

void bubbleSort(int *arr, int len) {
    for (int i = 0; i < len - 1; ++i) {
        for (int j = 0; j < len - 1 - i; ++j) {
            if (arr[j] > arr[j + 1]) {
                int t = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = t;
            }
        }
    }
}

int countPairs3(int *arr, int len, int value) {
    int cnt = 0;
    bubbleSort(arr, len);
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
