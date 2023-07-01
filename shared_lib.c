
int add(int a, int b) {
    return a+b;
}

int sub(int a, int b) {
    add(a,b);
    return a-b;
}

int fib(int n) {
    if (n <= 1) {
        return 1;
    }

    return (fib(n-1) + fib(n-2));
}

int add_alot(int n) {
    for (int i=0; i<n; i++) {
        add(i,i);
    }

    return 0;
}