int bar(int n);

int foo(int n) {
	if (n == 0)
		return 0;
	n--;
	return bar(n);
}

int bar(int n) {
    if (n == 0)
        return foo(0);

    return 1 + foo(n);
}

int main () {
    int x = bar(2);

    return 0;
}

/*

bar(2) -> 1 + foo(2) -> bar(1) -> 1 + foo(1) -> bar(0) -> 0

1st call to foo is foo(2), which returns 1
2nd call to foo is foo(1), which returns 0

*/