class Solution {
public:
    int digitSumProduct(int n) {
        int sum = 0;
        int product = 1;

        while(n > 0) {
            int rem = n % 10;
            sum += rem;
            product *= rem;
            n /= 10;
        }

        return sum + product;
    }

    bool checkDivisibility(int n) {
        int res = digitSumProduct(n);

        return n % res == 0 ? 1 : 0;
    }
};