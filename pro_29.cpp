/*
 * 经典的粗调 + 微调的算法
 */
class Solution {
public:
    int divide(int dividend, int divisor) {
        if (0 == divisor) {
            return INT_MAX;
        }
        
        long long m = abs((long long)(dividend));
        //这里必须先把divisor转成uint64_t，因为divisor如果为INT_MIN的话，则abs转换会出错，是一个corner case
        long long n = abs((long long)(divisor));
        if (m < n) {
            return 0;
        }
        
        long long res = 0;
        while (m >= n) {
            long long p = 1;
            long long t = n;
            //每次两倍增加的粗调，如果越界了再慢启动，经典做法，学习之
            while (m > (t << 1)) {
                p <<= 1;
                t <<= 1;
            }
            
            res += p;
            m -= t;
        }
        
        if ((dividend < 0) ^ (divisor < 0)) {
            res = -res;
        }

        return res > INT_MAX ? INT_MAX : res;
    }
};
