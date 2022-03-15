// Copyright 2021 NNTU-CS
int countPairs1(int *arr, int len, int value) {
  int k = 0;
  for (int i = 0; i < len; i++) {
    for (int j = i+1; j < len; j++) {
      if (arr[i] + arr[j] == 50) {
        k++;
      }
    }
  }
  return k;
}

int countPairs2(int *arr, int len, int value) {
  int k = 0;
  for (int i = 0; i < len; i++) {
    for (int j = len-1; j > 0; j--) {
      if (arr[i] + arr[j] > value) {
        continue;
      } else if (arr[i] + arr[j] == 50) {
        k++;
      } else {
        break;
      }
    }
  }
  return k;
}

int cbinsearch(int* arr, int len, int value) {
	int i = 0, j = len - 1, k = 1;
	while (i < j) {
		int mid = i + (j - i) / 2;
		if (arr[mid] == value) {
			int x = mid;
			while (arr[--mid] == value)
				k++;
			while (arr[++x] == value)
				k++;
			return k;
		}
		else if (arr[mid] > value) {
			j = mid;
		}
		else {
			i = mid + 1;
		}
	}
	return 0;
}

int countPairs3(int *arr, int len, int value) {
  int k = 0;
  for (int i = 0; i < len; i++) {
    if (value - arr[i] >= arr[i]) {
      k += cbinsearch(arr, len, value - arr[i]);
      }
  }
  return k;
}
