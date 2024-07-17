    bool isPossible(long long a[], long long b[], int n, long long k) {
        sort(a, a + n);
        sort(b, b + n);
        for (int i = 0, j = n - 1; i < n && j >= 0; i++, j--) {
            if ((a[i] + b[j]) < k) {
                return false;
            }
        }
        return true;
    }
};
