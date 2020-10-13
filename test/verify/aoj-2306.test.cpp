#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2306"

#include "../../template/template.cpp"
#include "../../graph/template.cpp"

#include "../../graph/others/enumerate-cliques.cpp"

int main() {
  int N, M;
  cin >> N >> M;
  Matrix< bool > g(N, vector< bool >(N));
  Matrix< int > h(N, vector< int >(N));
  for(int i = 0; i < M; i++) {
    int x, y, z;
    cin >> x >> y >> z;
    --x, --y;
    g[x][y] = true;
    g[y][x] = true;
    h[x][y] = z;
    h[y][x] = z;
  }
  auto cliques = enumerate_cliques(g);
  int ret = 0;
  for(auto &clique : cliques) {
    if(clique.size() == 1) continue;
    int add = 0;
    for(auto &i : clique) {
      int uku = 1 << 30;
      for(auto &j : clique) {
        if(i != j) uku = min(uku, h[i][j]);
      }
      add += uku;
    }
    ret = max(ret, add);
  }
  cout << ret << "\n";
}

