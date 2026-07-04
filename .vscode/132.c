#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int xn(int x, int n)
{
    if (n < 0)
    {
        return 0;
    }
    if (n == 0)
    {
        return 1;
    }
    else
    {
        return x * xn(x, n - 1);
    }
}

int nfactorial(int n)
{
    if (n < 0)
    {
        return 0;
    }
    if (n == 0)
    {
        return 1;
    }
    else
    {
        return n * nfactorial(n - 1);
    }
}
int fibonacci(int t)
{
    if (t < 0)
    {
        return 0;
    }
    if (t == 0)
    {
        return 0;
    }
    else if (t == 1)
    {
        return 1;
    }
    else
    {
        return fibonacci(t - 1) + fibonacci(t - 2);
    }
}

void quadratic_equation(double a, double b, double c)
{
    if (a == 0)
    {
        if (b == 0)
        {
            printf("No solution\n");
        }
        else
        {
            printf("One real root: %.2f\n", -c / b);
        }
        return;
    }

    double discriminant = b * b - 4 * a * c;
    double x1, x2;
    if (discriminant < 0)
    {
        printf("No real roots\n");
    }
    else if (discriminant == 0)
    {
        printf("One real root: %.2f\n", -b / (2 * a));
    }
    else
    {
        x1 = (-b + sqrt(discriminant)) / (2 * a);
        x2 = (-b - sqrt(discriminant)) / (2 * a);
        printf("Two real roots: %.2f and %.2f\n", x1, x2);
    }
}

void degrees(double degreesc)
{
    printf("Degrees F is %.2f\n", degreesc * 9 / 5 + 32);
    printf("Degrees K is %.2f\n", degreesc + 273.15);
}

void input_array(int arr[], int *size, int capacity)
{
    printf("Enter the size of the array (max %d): ", capacity);

    while (scanf("%d", size) != 1 || *size <= 0 || *size > capacity)
    {
        printf("Invalid! Please enter a positive integer up to %d: ", capacity);
        while (getchar() != '\n')
            ;
    }
    printf("Enter %d elements:\n", *size);

    for (int i = 0; i < *size; i++)
    {
        printf("Element [%d]: ", i);

        while (scanf("%d", &arr[i]) != 1)
        {
            printf("Invalid! Please enter an integer: ");
            while (getchar() != '\n')
                ;
        }
    }
}

void print_array(int arr[], int size)
{
    printf("Array elements: ");
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int sum(int arr[], int size)
{

    int total = 0;
    for (int i = 0; i < size; i++)
    {
        total += arr[i];
    }
    return total;
}

int average(int arr[], int size)
{
    int total = 0;
    for (int i = 0; i < size; i++)
    {
        total += arr[i];
    }
    return total / size;
}

double polynomial(double a[], int n, double x)
{
    double result = a[n];
    for (int i = n - 1; i >= 0; i--)
    {
        result = result * x + a[i];
    }
    return result;
}

void dec_to_bin(int x)
{
    char data[33];
    int index = 31;

    data[32] = '\0';

    if (x == 0)
    {
        data[index] = '0';
        printf("Binary of 0 = %s\n", &data[index]);
        return;
    }

    while (x > 0 && index >= 0)
    {
        data[index--] = (char)('0' + (x % 2));
        x /= 2;
    }

    printf("Binary = %s\n", &data[index + 1]);
}

int main(void)
{
    int x, n;
    printf("Enter x and n for x^n: ");
    scanf("%d %d", &x, &n);
    printf("x^n = %d\n", xn(x, n));

    int factorial_n;
    printf("Enter n for factorial: ");
    scanf("%d", &factorial_n);
    printf("n! = %d\n", nfactorial(factorial_n));

    int fib_n;
    printf("Enter t for fibonacci: ");
    scanf("%d", &fib_n);
    printf("fibonacci(t) = %d\n", fibonacci(fib_n));

    double a, b, c;
    printf("Enter a, b, c for quadratic equation: ");
    scanf("%lf %lf %lf", &a, &b, &c);
    quadratic_equation(a, b, c);

    double celsius;
    printf("Enter temperature in Celsius: ");
    scanf("%lf", &celsius);
    degrees(celsius);

    int arr[10];
    int size;
    input_array(arr, &size, 10);
    print_array(arr, size);
    printf("Sum of array elements: %d\n", sum(arr, size));
    printf("Average of array elements: %d\n", average(arr, size));

    int degree;
    printf("Enter degree of polynomial: ");
    while (scanf("%d", &degree) != 1 || degree < 0)
    {
        printf("Invalid! Please enter a non-negative degree: ");
        while (getchar() != '\n')
        {
        }
    }

    double coefficients[degree + 1];
    printf("Enter %d coefficients (a[0] to a[%d]):\n", degree + 1, degree);
    for (int i = 0; i <= degree; i++)
    {
        printf("a[%d]: ", i);
        scanf("%lf", &coefficients[i]);
    }

    double x_value;
    printf("Enter x: ");
    scanf("%lf", &x_value);
    printf("P(x) = %.4f\n", polynomial(coefficients, degree, x_value));

    dec_to_bin(10);
    return 0;
}