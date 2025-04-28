ll gcd(ll a, ll b) {
    if (a % b == 0) {
        return b;
    }
    else return gcd(b, a % b);
}