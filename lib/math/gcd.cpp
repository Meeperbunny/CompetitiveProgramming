LL gcd(LL a, LL b) {
    if (a % b == 0) {
        return b;
    }
    else return gcd(b, a % b);
}