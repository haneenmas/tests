#include <stdio.h>

int add(int a, int b);
int sub(int a, int b);
int fib(int n);
int add_alot(int n);

int func() {
    return 777;
}

int main() {
    int sum;
//    sum = add(1,2);
//    sum = add(34, 7);
    sum = add(1,2);
    sum = add(3,3);

//    func();
    sum = sub(1,2);

//    sum = add(5,5);

//    sum = fib(8);
//    sum = fib(2);

//    func();

    add_alot(7);


    return 0;
}