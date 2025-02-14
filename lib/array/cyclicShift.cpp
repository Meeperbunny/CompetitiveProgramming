vector<int> computeLPS(const vector<int>& pattern) {
    int m = pattern.size();
    vector<int> lps(m, 0);
    int len = 0, i = 1;
    
    while (i < m) {
        if (pattern[i] == pattern[len]) {
            lps[i++] = ++len;
        } else if (len) {
            len = lps[len - 1];
        } else {
            lps[i++] = 0;
        }
    }
    return lps;
}

bool KMP(const vector<int>& text, const vector<int>& pattern) {
    int n = text.size(), m = pattern.size();
    vector<int> lps = computeLPS(pattern);
    int i = 0, j = 0;
    
    while (i < n) {
        if (text[i] == pattern[j]) {
            i++, j++;
        }
        if (j == m) return true;
        if (i < n && text[i] != pattern[j]) {
            j ? j = lps[j - 1] : i++;
        }
    }
    return false;
}

vector<int> findCyclicShiftIndices(const vector<int>& a, const vector<int>& b) {
    if (a.size() != b.size()) return {};
    vector<int> doubled = a;
    doubled.insert(doubled.end(), a.begin(), a.end());
    
    vector<int> lps = computeLPS(b);
    vector<int> indices;
    int n = doubled.size(), m = b.size();
    int i = 0, j = 0;
    
    while (i < n) {
        if (doubled[i] == b[j]) {
            i++, j++;
        }
        if (j == m) {  // Found a match
            indices.push_back(i - m);
            j = lps[j - 1];  // Continue searching
        } else if (i < n && doubled[i] != b[j]) {
            j ? j = lps[j - 1] : i++;
        }
    }
    
    // Filter indices to only include those within the first `a.size()`
    vector<int> validIndices;
    for (int idx : indices) {
        if (idx < a.size()) {
            validIndices.push_back(idx);
        }
    }
    return validIndices;
}