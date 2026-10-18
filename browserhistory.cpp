#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main() {
    stack<string> history;

    history.push("google.com");
    history.push("youtube.com");
    history.push("abcsc.com");
    history.push("facebook.com");

    // Press Back twice
    for (int i = 0; i < 2; i++) {
        if (!history.empty())
            history.pop();
    }

    if (!history.empty())
        cout << "Current top page: "
             << history.top() << '\n';
    else
        cout << "No history available.\n";

    return 0;
}
