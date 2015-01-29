#include <iostream>

using namespace std;

void Print(int* beg, int* end);
size_t FindMaxNumber(int* array, size_t len);

// Return the index of the max number in a given array
size_t FindMaxNumber(int* array, size_t len) {
  if (!array || len <= 0) {
    return -1;
  }

  int* beg = array;
  int* end = array + len - 1;
  while (beg + 1 < end) {
    int* mid = beg + (end - beg) / 2;
    if ((mid == beg || *mid >= *(mid - 1)) && *mid >= *(mid + 1)) {
      return mid - array;
    } else if (* mid >= *beg && *mid < *(mid + 1)) {
      beg = mid;
    } else {
      end = mid;
    }

    Print(beg, end);
  }

  return *beg > *end ? beg - array : end - array;
}

void Print(int* beg, int* end) {
  while (beg != end) {
    cout << *beg;
    ++beg;
  }
  cout << *end << endl;
}

int main() {
  int array[] = {7,6,5,4,3,2,1};
  cout << FindMaxNumber(array, sizeof(array) / sizeof(int)) << endl;
}
