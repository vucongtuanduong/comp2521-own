#include <bits/stdc++.h>
using namespace std;
/*
each function call creates a new mini-environments are called stack frames

eg: factorial(2):
                                                                        fact(0)
                                   fact(1)                              fact(1)                        fact(1)
fact(2)-> face(2) calls face(1) -> fact(2) -> face(1) calls fact(0) -> fact(2) -> fact(0) returns 1 -> fact(2) -> fact(1) returns 1 * 1 = 1 - > fact(2)  -> fact(2) returns 2 * 1 = 2

-when the stack is growing, that is called winding
-when the stack is shrinking, that is called unwinding
*/
int factorial(int n) {
    //base cas: no recursive call needed
    if (n == 0) {
        return 1; 
    } else {
        return n * factorial(n - 1);
    }
}
int main () {
    freopen("input-fac.txt", "r", stdin);
    freopen("output-fac.txt", "w", stdout);
    int n;
    cin >> n;
    cout << factorial(n) << endl;
}