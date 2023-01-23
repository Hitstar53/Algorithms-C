#include<stdio.h>
#include<math.h>
void func1(int n) {
    float result;
    result = pow(1.5,n);
    printf("%.2f\t",result);
}
void func2(int n) {
    float result;
    result = pow(n,3);
    printf("%.2f\t",result);
}
void func3(int n) {
    float result;
    result = log(log(n));
    printf("%.2f\t",result);
}
void func4(int n) {
    float result;
    result = log2(n);
    printf("%.2f\t",result);
}
void func5(int n) {
    float result;
    result = n*pow(2,n);
    printf("%.2f\t",result);
}
void func6(int n) {
    float result;
    result = log(n);
    printf("%.2f\t",result);
}
void func7(int n) {
    float result;
    result = pow(2,log2(n));
    printf("%.2f\t",result);
}
void func8(int n) {
    float result;
    result = exp(n);
    printf("%.2f\t",result);
}
void func9(int n) {
    float result;
    result = sqrt(log2(n));
    printf("%.2f\t",result);
}
void func10(int n) {
    float result;
    result = n*log2(n);
    printf("%.2f\t",result);
}
int main()
{
    printf("10 functions & values from 0 to 100:\n");
    printf("1.5^n\tn^3\tln(ln(n))\tlg(n)\tn*2^n\tln(n)\t2^lg(n)\te^n\tsqrt(lg(n))\tn*lg(n)\tn!\n");
    for(int i=0;i<=100;i++)
    {
        func1(i);
        func2(i);
        func3(i);
        func4(i);
        func5(i);
        func6(i);
        func7(i);
        func8(i);
        func9(i);
        func10(i);
        if(i<21) 
        {
            printf("%.2f\t",tgamma(i+1));
        }
        printf("\n");
    }
    return 0;
}