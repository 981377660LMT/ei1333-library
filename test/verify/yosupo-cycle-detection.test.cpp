#define PROBLEM "https://judge.yosupo.jp/problem/ecycle_detection"

#include "../../template/template.cpp"

#include "../../graph/others/cycle-detection.cpp"

int main() {
    int N, M;
    cin >> N >> M;
    CycleDetection<> g(N);
    g.read(M, 0, false, true);
    auto ret = g.build();
    if(ret.empty()) {
        cout << -1 << "\n";
    } else {
        cout << ret.size() << "\n";
        for(auto& e : ret) cout << e.idx << "\n";
    }
}