vector<vector<int>> getCycles(vector<int> &correctPos) {
    int n = correctPos.size();
    vector<bool> checked(n, false);
    vector<vector<int>> cycles;
    for(int i = 0; i < n; i++) {
        if (!checked[i]) {
            cycles.push_back({i});
            int cpos = i;
            checked[i] = true;
            int sz = 0;
            while(true) {
                cpos = correctPos[cpos];
                checked[cpos] = true;
                sz += 1;
                if (cpos == i) break;
                cycles.back().push_back(cpos);
            }
        }
    }
    return cycles;
}
