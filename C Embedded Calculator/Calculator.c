/**
 * This program implements a simple calculator comprised of common math functions
 *
 * @file Calculator.c
 * @author Nicolas Jorgensen njorgen1@ucsc.edu
 *
 * @date Oct 13th, 2024
 */
// Standard libraries.
#include <stdio.h>
#include <math.h>

// User libraries.
#include "BOARD.h"

double Add(double operand1, double operand2);
double Multiply(double operand1, double operand2);
double AbsoluteValue(double operand);
double FahrenheitToCelsius(double operand);
double Tangent(double operand);
double Subtract(double operand1, double operand2);
double Divide(double operand1, double operand2);
double CelsiusToFahrenheit(double);
double Round(double);
double Average(double, double);


void CalculatorRun(void)
{
    printf(
        "\n\nWelcome to Nic's calculator program! Compiled at %s %s\n\r",
        __DATE__,
        __TIME__
    );

    while(1) {
        char op_choice = -1;
        int need_input = 1; //holds sentinel value for operator loop
        double operand1 = 0.0, operand2 = 0.0, result = 0;

        //User input block with introduction
        while(need_input) {
            printf("Enter a mathematical operation to perform");
            printf("\t\t%s","(*,/,+,-,m,a,c,f,t,q,r): ");

            scanf(" %c", &op_choice);
            //flushes the input buffer, in case user did not enter a char
            while(getchar() != '\n');

            printf("\rCharacter received was: '%c'\n\r", op_choice);
            
            if(op_choice != '+' && op_choice != '-' && op_choice != '/' &&
               op_choice != '*' && op_choice != 'm' && op_choice != 'a' &&
               op_choice != 'c' && op_choice != 'f' && op_choice != 't' &&
               op_choice != 'r' && op_choice != 'q') {
                printf("Error, not a valid operator.\n\r");
            }
            //user picked a valid operator
            else {
                need_input = 0;
            }
        } 

        //User quit
        if(op_choice == 'q') {
            goto Quit; //To return statement
        }

        printf("Enter the first operand: ");
        scanf(" %lf", &operand1);

        if(op_choice == '+'||op_choice == '-'||op_choice == '/'||
                              op_choice == '*'||op_choice == 'm') {
            printf("Enter the second operand: ");
            scanf(" %lf", &operand2);
        }

        switch(op_choice) {
        case '+':
            result = Add(operand1,operand2);
            printf("Result of %lf + %lf: %lf\n",
                    operand1, operand2, result);
            break;
        case '-':
            result = Subtract(operand1,operand2);
            printf("Result of %lf - %lf: %lf\n",
                    operand1, operand2, result);
            break;
        case '/':
            result = Divide(operand1,operand2);
            //if divisor == 0
            if(result == HUGE_VAL) {
                printf("ERROR: Cannot divide by zero!\n");
                break;
            }
            printf("Result of %lf / %lf: %lf\n",
                    operand1, operand2, result);
            break;
        case '*':
            result = Multiply(operand1,operand2);
            printf("Result of %lf * %lf: %lf\n",
                    operand1, operand2, result);
            break;
        case 'm':
            result = Average(operand1,operand2);
            printf("Result of mean(%lf & %lf): %lf\n",
                    operand1, operand2, result);
            break;
        case 'a':
            result = AbsoluteValue(operand1);
            printf("Result of |%lf|: %lf\n",
                    operand1, result);
            break;
        case 'c':
            result = FahrenheitToCelsius(operand1);
            printf("Result of (%.2lf deg->C): %lf\n",
                    operand1, result);
            break;
        case 'f':
            result = CelsiusToFahrenheit(operand1);
            printf("Result of (%.2lf deg->F): %lf\n",
                    operand1, result);
            break;
        case 't':
            result = Tangent(operand1);
            printf("Result of tan(%.2lf): %lf\n",
                    operand1, result);
            break;
        case 'r':
            result = Round(operand1);
            printf("Result of round(%lf): %lf\n",
                    operand1, result);
            break;
        }
        printf("\n"); //tidy formatting
    } 
    
    Quit://label for goto statement
    
    return;
}

double Add(double operand1, double operand2)
{
    return operand1 + operand2;
}

double Subtract(double operand1, double operand2)
{
    return operand1 - operand2;
}

double Multiply(double operand1, double operand2)
{
    return operand1 * operand2;
}

double Divide(double numerator, double denom)
{
	if(denom == 0) {
        return HUGE_VAL;
    }

    return numerator / denom;
}

double AbsoluteValue(double operand)
{
    if(operand < 0) {
        operand = -operand;
    }

    return operand;
}

double FahrenheitToCelsius(double fahr)
{
    double cel;

    cel = (fahr - 32.0) * (5.0/9.0);

    return cel;
}

double CelsiusToFahrenheit(double cel)
{
    double fahr;

    fahr = cel * (9.0/5.0) + 32.0;

    return fahr;
}

double Average(double operand1, double operand2)
{
    return (operand1 + operand2)/2.0;
}

double Tangent(double deg)
{
    double rads = deg *M_PI/ 180.0;

    return tan(rads);
}

double Round(double unround)
{
    double round, deci;
    
    round = (int)unround;//discarding the decimal values of unround
    deci = unround - round;//deci is now == to only unround's decimals

    if(deci >= 0.5 || deci <= -0.5) {
        if(deci > 0) {
            round++;//round up
        }
        else {
            round--;//round away from zero for (-)
        }
    }

    return round;
}

