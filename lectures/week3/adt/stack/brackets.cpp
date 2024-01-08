
#include "Stack.cpp"
using namespace std;
int getMatchingBracket(int ch);
int main () {
    freopen("input.txt", "r", stdin);
    bool balanced = true;
    Stack *s = StackNew();
    int ch;
    while ((ch = getchar()) != EOF) {
        if (ch == '(' || ch == '[' || ch == '{') {
            StackPush(s, ch);
        } else if (ch == ')' || ch == ']' || ch == '}') {
            if (StackSize(s) == 0) {
                balanced = false;
                break;
            }
            int top = StackPop(s);
            if (top != getMatchingBracket(ch)) {
                balanced = false;
                break;
            }
        }
    }
    if (StackSize(s) != 0) {
        balanced = false;
    }
    StackFree(s);
    if (balanced) {
        cout << "Balanced" << endl;
    } else {
        cout << "Not balanced" << endl;
    }
}
int getMatchingBracket(int ch) {
    if (ch == ')') {
        return '(';
    } else if (ch == ']') {
        return '[';
    } else if (ch == '}') {
        return '{';
    } else {
        return '?';
    }
}