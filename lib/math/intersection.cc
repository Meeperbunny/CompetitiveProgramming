// @returns The inclusive intersection of the 1-d ranges.
ll intersection(const pair<ll, ll> &a, const pair<ll, ll> &b, bool inclusive=true) {
    assert(a.first <= a.second && b.first <= b.second);
    ll up = min(a.second, b.second);
    ll low = max(a.first, b.first);
    return max(0ll, up - low + ll(inclusive ? 1 : 0));
}