// Copyright 2021 NNTU-CS
int countPairs1(int *arr, int len, int value) {
  int count = 0;
  for (int i = 0; i < len; ++i) {
    for (int j = 0; j < len; ++j) {
      if (i != j && arr[i] + arr[j] == value) {
        ++count;
      }
    }
  }
  return count / 2;
}

int countPairs2(int *arr, int len, int value) {
  int count = 0;
  int left = 0;
  int right = len - 1;

  while (left < right) {
    int sum = arr[left] + arr[right];
    if (sum == value) {
      int l_val = arr[left];
      int r_val = arr[right];
      int l_count = 0;
      int r_count = 0;

      while (left < right && arr[left] == l_val) {
        ++left;
        ++l_count;
      }

      while (right >= left && arr[right] == r_val) {
        --right;
        ++r_count;
      }

      count += l_count * r_count;
    } else if (sum < value) {
      ++left;
    } else {
      --right;
    }
  }

  return count;
}

int countPairs3(int *arr, int len, int value) {
  int count = 0;
  for (int i = 0; i < len; ++i) {
    int complement = value - arr[i];
    if (complement >= arr[i]) {
      if (std::binary_search(arr + i + 1, arr + len, complement)) {
        int first = i + 1;
        while (first < len && arr[first] < complement) {
          ++first;
        }

        int temp = 0;
        while (first + temp < len && arr[first + temp] == complement) {
          ++temp;
        }

        count += temp;
      }
    }
  }

  return count;
}
