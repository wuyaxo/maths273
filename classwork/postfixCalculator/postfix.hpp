//
// Created by David on 2/29/24.
//
#pragma once
#ifndef POSTFIXCALCULATOR_POSTFIX_H

#include <unordered_set>
#include <string>
#include <stack>
#include <sstream>
#include <exception>

bool isOperator(const char &operator_char) {
    std::unordered_set<char> operators = {'+', '-', '*', '/'};
    return operators.find(operator_char) != operators.end();
}

int doOperation(int a, int b, const char str) {
    int result;
    switch (str) {
        case '+':
            result = a + b;
            break;
        case '-':
            result = a - b;
            break;
        case '*':
            result = a * b;
            break;
        case '/':
            result = a / b;
            break;
        default:
            throw std::invalid_argument("not a valid operator");
    }
    return result;
}

int postfix_calculator(const std::string &str) {
    std::stack<int> S;
    std::string token;
    std::istringstream iss(str);
    while (iss >> token) {
        if (isOperator(token[0])) {
            //pop twice
            int right = S.top();
            S.pop();
            int left = S.top();
            S.pop();
            S.push(doOperation(left, right, token[0]));
        } else {
            // push onto stack
            S.push(std::stoi(token));
        }
    }
    return S.top();
}

#define POSTFIXCALCULATOR_POSTFIX_H

#endif //POSTFIXCALCULATOR_POSTFIX_H
