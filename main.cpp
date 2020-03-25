#define CATCH_CONFIG_MAIN


#include "catch.hpp"
#include <stack>
#include <iostream>

using namespace std;

// Returns true if character is a digit
bool isDigit(char c) {
    return (c >= '0' && c <= '9');
}

// Returns true if character is a + or a *
bool isOperator(char c) {
    return (c == '+' || c == '*');
}


// Given the integers a and b and a character
// that is either + or *, returns the result of the
// corresponding operation
int doOperation(int a, int b, char oper) {
    if (oper == '+' ) return a + b;
    else              return a * b;
}


// Given st, a non empty, valid postfix string that
// contains only digits, spaces and operators + or *,
// evaluates the expression and returns the result

int evalPostfix(const string &st) {
    stack<int> S;
    for (auto c: st) {
        if (c == ' ') {}
        else if (isDigit(c)) {
            S.push( c - '0');
        }
        else if (isOperator(c)) {
            int tmpB = S.top(); S.pop();
            int tmpA = S.top(); S.pop();
            S.push(doOperation(tmpA, tmpB, c));
        }
    }
    return S.top();
}


// Test cases for the function evalPostfix

TEST_CASE( "evalPostfix", "[evalPostfix]" ) {
    CHECK(evalPostfix("9 8 +") == 17);
    CHECK(evalPostfix("9 8 *") == 72);

    CHECK(evalPostfix("9 8 1 * +") == 17);
    CHECK(evalPostfix("9 8 1 + *") == 81);

    CHECK(evalPostfix("9 8 + 2 *") == 34);
    CHECK(evalPostfix("3 5 + 5 * 1 1 + +") == 42);
    CHECK(evalPostfix("1 2 + 3 4 * + 5 + 6 *") == 120);
}