#define PROBLEM "https://judge.yosupo.jp/problem/scc"

#include "../../template/template.cpp"

#include "../../graph/graph-template.cpp"

#include "../../graph/connected-components/strongly-connected-components.cpp"

int main() {
  int N, M;
  cin >> N >> M;
  StronglyConnectedComponents<> g(N);
  g.read(M, 0, false, true);
  g.build();
  cout << g.group.size() << "\n";
  for(auto &p : g.group) {
    cout << p.size() << " " << p << "\n";
  }
}
