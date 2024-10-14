#include <stdio.h>

// Recursive function to evaluate a polynomial using Horner's rule
double horner(double coeff[], int n, double x) {
    // Base case: when n is 0, return the constant term
    if (n == 0)
        return coeff[0];
    
    // Recursive step: coeff[n] + x * horner(coeff, n-1, x)
    return coeff[n] + x * horner(coeff, n - 1, x);
}

int main() {
    int degree;
    double x;

    // Input: Degree of the polynomial
    printf("Enter the degree of the polynomial: ");
    scanf("%d", &degree);

    double coeff[degree + 1];

    // Input: Coefficients of the polynomial
    printf("Enter the coefficients of the polynomial (from constant to highest degree):\n");
    for (int i = 0; i <= degree; i++) {
        printf("Coefficient of x^%d: ", i);
        scanf("%lf", &coeff[i]);
    }

    // Input: Value of x
    printf("Enter the value of x: ");
    scanf("%lf", &x);

    // Evaluate the polynomial using Horner's Rule
    double result = horner(coeff, degree, x);

    // Output the result
    printf("The value of the polynomial at x = %.2lf is %.2lf\n", x, result);

    return 0;
}
