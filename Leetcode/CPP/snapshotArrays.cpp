#include <bits/stdc++.h>

using namespace std;

class SnapshotArray {
public:
  vector<map<int, int>> arr;
  int snap_id = 0;

  SnapshotArray(int length) {
    arr.resize(length);
    for (int i = 0; i < length; i++)
      arr[i][0] = 0;
  }

  void set(int index, int val) { arr[index][snap_id] = val; }

  int snap() {
    snap_id++;
    return snap_id - 1;
  }

  int get(int index, int snap_id) {
    if (arr[index].find(snap_id) == arr[index].end()) {
      auto it = --arr[index].lower_bound(snap_id);
      return it->second;
    }
    return arr[index][snap_id];
  }
};

int main() { return 0; }
