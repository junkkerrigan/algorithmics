#include <iostream>
#include <vector>
#include <deque>
using namespace std;

struct vertax {
  int vert, index, father;
  bool visited;
  vertax(int a) {
    vert = a;
    index = 10001;
    father = a;
    visited = false;
  }
  vertax(int a, int b) {
    vert = a;
    father = b;
    index = 10001;
    visited = false;
  }
  vertax(int a, int b, int x) {
    vert = a;
    father = b;
    index = x;
    visited = false;
  }
  vector<vertax> follow;
  ~vertax() {}
};

struct graph {
  vector<vertax> v;
  int count;
  graph(){};
  graph(int n) { count = n; }
  void get() {
    for (int i = 1; i <= count; i++) {
      vertax v(i);
      for (int j = 1; j <= count; j++) {
        int x;
        cin >> x;
        if (x != 0) {
          vertax temp(j, i, x);
          v.follow.push_back(temp);
        }
      }
      graph::v.push_back(v);
    }
  }
  void write() {
    for (int i = 0; i < count; i++) {
      cout << v[i].index << ":";
      for (int j = 0; j < v[i].follow.size(); j++)
        cout << v[i].follow[j].vert << " ";
      cout << endl;
    }
  }
  void way(vertax& x) {
    deque<vertax> list;
    x.index = 0;
    x.visited = true;
    list.push_front(x);
    while (!list.empty()) {
      vertax& y = list[0];
      for (int i = 0; i < y.follow.size(); i++) {
        v[y.follow[i].vert - 1].visited = true;
        if (v[y.follow[i].vert - 1].index > y.index + y.follow[i].index) {
          v[y.follow[i].vert - 1].index = y.index + y.follow[i].index;
          if (v[y.follow[i].vert - 1].index > -102)
            list.push_back(v[y.follow[i].vert - 1]);
        }
      }
      list.pop_front();
    }
  }
  void def() {
    for (int i = 0; i < v.size(); i++) {
      v[i].index = 10001;
      v[i].visited = false;
    }
  }
  void task1() {
    for (int i = 0; i < v.size(); i++) {
      way(v[i]);
      for (int j = 0; j < v.size() - 1; j++) {
        if (!v[j].visited)
          cout << 0 << " ";
        else if (v[j].index < -50)
          cout << 2 << " ";
        else
          cout << 1 << " ";
      }
      if (!v[v.size() - 1].visited)
        cout << 0;
      else if (v[v.size() - 1].index < -50)
        cout << 2;
      else
        cout << 1;
      def();
      cout << endl;
    }
  }
  void task2() {
    for (int i = 0; i < v.size(); i++) {
      way(v[i]);
      for (int j = 0; j < v.size() - 1; j++) {
        if (!v[j].visited)
          cout << 0 << " ";
        else
          cout << v[j].index << " ";
      }
      if (!v[v.size() - 1].visited)
        cout << 0;
      else
        cout << v[v.size() - 1].index;
      def();
      cout << endl;
    }
  }
};

int main() {
  ios::sync_with_stdio(false);
  int n;
  cin >> n;
  graph dog(n);
  dog.get();
  dog.task2();
  return 0;
}