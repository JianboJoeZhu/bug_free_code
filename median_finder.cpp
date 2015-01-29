#include <iostream>

using namespace std;

void Swap(int*, int*);
int* Partition(int* beg, int* end);
int FindMedian(int* array, size_t len);

int* Partition(int* beg, int* end) {
  int* flag = beg;
  ++beg;
  while (beg < end) {
    while (*beg < *flag) {
      ++beg;
    }
    while (*end > *flag) {
      --end;
    }

    if (beg >= end) {
      break;
    }

    Swap(beg, end);
  }
  Swap(flag, end);

  return end;
}

void Swap(int* a, int* b) {
  int temp = *a;
  *a = *b;
  *b = temp;
}

int FindMedian(int* array, size_t len) {
  if (!array || len <= 0) {
    return -1;
  }

  int* beg = array;
  int* end = array + len - 1;
  int n = (len + 1) / 2;
  while (beg <= end) {
    int* mid = Partition(beg, end);
    int small_part_number = mid - beg + 1;
    if (small_part_number == n) {
      return *mid;
    } else if (small_part_number < n) {
      beg = mid + 1;
      n -= small_part_number;
    } else {
      end = mid - 1;
    }
  }
}

int main() {
  int array[] = {190,91,54,29,71,380,42, 21, 110, 45, 31};
  cout << FindMedian(array, sizeof(array) / sizeof(int)) << endl;
}
