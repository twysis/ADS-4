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
  for (int i = 0; i < len; i++) {
    for (int j = len-1; j > i; j--) {
      if (arr[j] > value - arr[i]) {
        continue;
        } else if (arr[j] < value - arr[i]) {
          continue;
        } else if (arr[j] == value - arr[i]) {
          k++;
        } else {
          break;
        }
    }
  }
  return k;
}

int cbinsearch(int* arr, int size, int number, int left) {
int i = left, j = size, k = 0; // i - левая граница массива, j - правая
while (i < j) {
  int mid = i + (j - i) / 2;
  if (arr[mid] == number) {
    int x = mid;
    k++;
    while (arr[--mid] == number)
      k++;
    while (arr[++x] == number)
      k++;
    return k;
  } else if (arr[mid] > number) {
	  j = mid;
  } else {
	  i = mid + 1;
  }
}
return 0;
}

int countPairs3(int *arr, int len, int value) {
  int k = 0;
  for (int i = 0; i < len; i++) {
    if (value - arr[i] >= arr[i]) {
      k += cbinsearch(arr, len, value - arr[i], i);
      }
  }
  return k;
}
