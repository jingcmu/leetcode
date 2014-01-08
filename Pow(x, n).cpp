//采用了二分法，因为计算复杂度锐减为log n
//如果用循环连乘，计算复杂度是线性
class Solution {
public:
    double pow(double x, int n) {  
        if (n == 0) return 1.0;  
        // Compute x^{n/2} and store the result into a temporary  
        // variable to avoid unnecessary computing  
        double half = pow(x, n / 2);  
        if (n % 2 == 0)  
            return half * half;  
        else if (n > 0)  
            return half * half * x;  
        else  
            return half * half / x;  
    }
};