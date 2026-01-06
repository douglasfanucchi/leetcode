double _pow(double x, int n) { // Time: O(log(abs(n))) | Space: O(log(abs(n)))
    double ans;

    if (n == 0) {
        return 1;
    }

    if (n % 2 && n > 0) {
        return x * _pow(x, n - 1);
    }
    if (n % 2 && n < 0) {
        return (1 / x) * _pow(x, n + 1);
    }

    ans = _pow(x, n / 2);

    return ans * ans;
}
