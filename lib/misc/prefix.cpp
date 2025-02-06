template<typename T>
class PrefixSum {
private:
    vector<T> pre;
public:
    PrefixSum(vector<T> &arr) {
        pre = vector<T>(arr.size() + 1);
        for(size_t i = 0; i < arr.size(); i++) {
            pre[i + 1] = pre[i] + arr[i];
        }
    }
    T rangeSum(size_t l, size_t r) {
        return pre[r + 1] - pre[l];
    }
};