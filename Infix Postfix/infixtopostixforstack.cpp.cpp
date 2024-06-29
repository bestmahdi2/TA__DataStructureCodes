//کلاس پشته 
#include <iostream>
#include <string>

class Stack {
private:
    char data[100];
    int top;

public:
    Stack() {
        top = -1;
    }

    void push(char value) {
        if (top < 99) {
            data[++top] = value;
        }
    }

    char pop() {
        if (top >= 0) {
            return data[top--];
        }
        return '\0';
    }

    char peek() {
        if (top >= 0) {
            return data[top];
        }
        return '\0';
    }

    bool isEmpty() {
        return top == -1;
    }
};
//تابع برای اولویت ها 
int get(char w) {
    if (w == '+' || w == '-')
        return 1;
    else if (w == '*' || w == '/')
        return 2;
    return 0;
}
//تابع تبدیل infixبه postfix
std::string infixToPostfix(std::string infix) {
    std::string postfix = "";
    Stack temp;

    for (int i = 0; i < infix.size(); ++i) {
        char c = infix[i];
        if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z') || (c >= '0' && c <= '9')) {
            postfix += c;
        } else if (c == '(') {
            temp.push(c);
        } else if (c == ')') {
            while (!temp.isEmpty() && temp.peek() != '(') {
                postfix += temp.pop();
            }
            temp.pop();
        } else if (c == '+' || c == '-' || c == '*' || c == '/') {
            while (!temp.isEmpty() && temp.peek() != '(' && get(temp.peek()) >= get(c)) {
                postfix += temp.pop();
            }
            temp.push(c);
        }
    }

    while (!temp.isEmpty()) {
        postfix += temp.pop();
    }

    return postfix;
}
//تابع محاسبه مقدار عددی از روی postfix
int PostfixValue(std::string postfix) {
    Stack value;

    for (int j = 0; j < postfix.size(); ++j) {
        char C = postfix[j];
        if ((C >= '0' && C <= '9') || (C >= 'A' && C <= 'Z') || (C >= 'a' && C <= 'z')) {
            value.push(C);
        } else if (C == '+' || C == '-') {
            int x2 = value.pop();
            int x1 = value.pop();
            if (C == '+') {
                value.push(x1 + x2);
            } else if (C == '-') {
                value.push(x1 - x2);
            }
        } else if (C == '*' || C == '/') {
            int x2 = value.pop();
            int x1 = value.pop();
            if (C == '*') {
                value.push(x1 * x2);
            } else if (C == '/' && x2 != 0) {
                value.push(x1 / x2);
            } else {
                std::cerr << "\n";
                return 0;
            }
        }
    }

    if (!value.isEmpty()) {
        return value.pop();
    } else {
        std::cerr << "\n";
        return 0;
    }
}

int main() {
    std::string infix;
    std::cout << "Enter an infix: ";
    std::getline(std::cin, infix);

    std::string postfix = infixToPostfix(infix);
    std::cout << "Infix: " << infix << std::endl;
    std::cout << "Postfix: " << postfix << std::endl;

    int result = PostfixValue(postfix);
    std::cout << "Result: " << result << std::endl;

    return 0;
}