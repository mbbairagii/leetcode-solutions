class Solution {
public:
    int reverse(int x) {
        int rev = 0;

        while (x != 0) {
            int digit = x % 10;

            // overflow condition: Multiplying by 10 will exceed the allowed
            // range. if rev is exactly at the boundary, we must check the last
            // digit too 
            //INT_MAX=2147483647
            if (rev > INT_MAX / 10 || (rev == INT_MAX / 10 && digit > 7)) {
                return 0;
            }

            // underflow comdition: Multiplying by 10 will go below the allowed
            // range.
            // But what if rev is exactly at the boundary?
            // We must check the last digit too.
            //INT_MIN=-2147483648
            if (rev < INT_MIN / 10 || (rev == INT_MIN / 10 && digit < -8)) {
                return 0;
            }

            rev = rev * 10 + digit;
            x = x / 10;
        }

        return rev;
    }
};