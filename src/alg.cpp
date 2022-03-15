// Copyright 2021 NNTU-CS
int countPairs1(int *arr, int len, int value) {
  int k = 0;
  for (int i = 0; i < len; i++) {
    for (int j = i+1; j < len; j++) {
      if (arr[i] + arr[j] == value) {
        k++;
      }
    }
  }
  return k;
}

int countPairs2(int *arr, int len, int value) {
int k = 0;
while (arr[len - 1] > value) {
  len--;
}
for (int i = 0; i < len; i++) {
  for (int j = i + 1; j < len; j++) {
    if (arr[i] + arr[j] == value) {
      k++;
      }
    }
  }
return k;
}

int search(int* arr, int len, int value, int left) {
int i = left, j = len - 1, k = 0; 
while (i < j) {
  int mid = i + (j - i) / 2;
  if (arr[mid] == value && mid != left) {
    k++;
    int x = mid, xx = mid;
    while (arr[++x] == value) {
      k++;
    }
    while (arr[--xx] == value && xx > left) {
      k++;
    }
    return k;
  } else if (arr[mid] > value) {
      j = mid;
  } else {
      i = mid + 1;
  }
return 0;
}

int countPairs3(int *arr, int len, int value) {
  int k = 0;
  for (int i = 0; i < len; i++) {
    k += search(arr, len, value - arr[i], i);
  }
  return k;
}
