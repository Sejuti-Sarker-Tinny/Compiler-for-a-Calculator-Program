#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

double evaluate_expression(const char* expression) {
    double result = 0, current_number = 0;
    char operator = '+';

    for (const char* current = expression; *current != '\0'; current++) {
        if (isspace(*current)) continue;

        if (isdigit(*current) || *current == '.') {
            current_number = strtod(current, (char**)&current) - 1;
        } else {
            if (operator == '+') result += current_number;
            else if (operator == '-') result -= current_number;
            else if (operator == '*') result *= current_number;
            else if (operator == '/') {
                if (current_number != 0) result /= current_number;
                else {
                    printf("Error: Division by zero\n");
                    exit(EXIT_FAILURE);
                }
            }

            operator = *current;
        }
    }

    if (operator == '+') result += current_number;
    else if (operator == '-') result -= current_number;
    else if (operator == '*') result *= current_number;
    else if (operator == '/') {
        if (current_number != 0) result /= current_number;
        else {
            printf("Error: Division by zero\n");
            exit(EXIT_FAILURE);
        }
    }

    return result;
}

int main() {
    char input[100];
    printf("Enter a mathematical expression: ");
    fgets(input, sizeof(input), stdin);

    double result = evaluate_expression(input);
    printf("Result: %.2f\n", result);

    return 0;
}
