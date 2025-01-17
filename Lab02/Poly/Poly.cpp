#include <stdio.h>
#include <ctype.h>
#include "Poly.h"
#include <stdlib.h>
#include <math.h>

//-------------------------------------------------
// Creates a polynomial from an expression.
// Returns a pointer to the first PolyNode in the list (head of the list)
//
// Expression will be of the following sort:
// Ex1: 2.3x^4 + 5x^3 - 2.64x - 4
// Ex2: -4.555x^10 - 45.44
// Ex3: x^6 + 2x^4 - x^3 - 6.3x + 4.223 
// Ex4: 34
// Ex5: -x+1
// Ex6: -3x^4    +   4x
// Ex7: -2x  - 5
//
PolyNode* CreatePoly(char* expr) {
    PolyNode* poly = nullptr;
    double coef_val = 0;
    int expo_val = 0, sign_value = 1, index = 0;

    while (expr[index] != '\0') {
        char char_val = expr[index];
        // Check if the current character is a digit to extract the coefficient
        if (isdigit(char_val)) {
            coef_val = atof(&expr[index]) * sign_value;
            while (isdigit(expr[index]) || expr[index] == '.') {
                index++;
            }
            index--;
        }
        // Handle the 'x' variable and check if it has an exponent
        else if (char_val == 'x') {
            if (coef_val == 0 && expr[index + 1] != '.')
                coef_val = sign_value;
            if (expr[index + 1] == '^') {
                expo_val = atoi(&expr[index + 2]);
                while (isdigit(expr[index + 2])) {
                    index++;
                }
            }
            else {
                expo_val = 1;
            }
            // Add node to the polynomial
            poly = AddNode(poly, coef_val, expo_val);
            coef_val = 0;
            expo_val = 0;
        }
        // Handle negative and positive signs
        else if (char_val == '-') {
            sign_value = -1;
        }
        else if (char_val == '+') {
            sign_value = 1;
        }
        index++;
    }
    // Add the last node to the polynomial
    poly = AddNode(poly, coef_val, expo_val);
    return poly;
} //end-CreatePoly

/// -------------------------------------------------
/// Walk over the poly nodes & delete them
///
void DeletePoly(PolyNode* poly) {
    while (poly) {
        PolyNode* tmp = poly;
        poly = poly->next;
        free(tmp); // Free memory for each node
    }
} // end-DeletePoly

//-------------------------------------------------
// Adds a node (coefficient, exponent) to poly. If there already 
// is a node with the same exponent, then you simply add the coefficient
// to the existing coefficient. If not, you add a new node to polynomial
// Returns a pointer to the possibly new head of the polynomial.
//
PolyNode* AddNode(PolyNode* head, double coef, int exp) {
    if (coef == 0) {
        return head; // Do not add if the coefficient is zero
    }

    PolyNode* new_node = (PolyNode*)malloc(sizeof(PolyNode)); // Allocate memory for a new node
    new_node->coef = coef;
    new_node->exp = exp;
    new_node->next = NULL;

    // If the head is null or the exponent is greater than the head node, insert at the beginning
    if (!head || exp > head->exp) {
        new_node->next = head;
        return new_node;
    }

    PolyNode* current = head;
    PolyNode* previous = NULL;

    // Traverse the list to find the correct position to insert
    while (current && current->exp >= exp) {
        if (current->exp == exp) {
            current->coef += coef; // Update the coefficient if the exponent already exists
            if (current->coef == 0) { // If the coefficient becomes zero, delete the node
                if (previous) {
                    previous->next = current->next;
                }
                else {
                    head = current->next; // Update the head node
                }
                free(current); // Free memory for the deleted node
            }
            free(new_node); // Free memory for the newly created node as it is not needed
            return head;
        }
        previous = current;
        current = current->next;
    }

    // Insert the new node in its correct position
    new_node->next = current;
    if (previous) {
        previous->next = new_node;
    }
    else {
        head = new_node; // Update the head node
    }

    return head;
} // end-AddNode

//-------------------------------------------------
// Adds two polynomials and returns a new polynomial that contains the result
// Computes: poly3 = poly1 + poly2 and returns poly3
//
PolyNode* Add(PolyNode* poly1, PolyNode* poly2) {
    PolyNode* result = NULL;
    // Traverse both polynomials and add their corresponding nodes
    while (poly1 || poly2) {
        if (poly1) {
            result = AddNode(result, poly1->coef, poly1->exp);
            poly1 = poly1->next;
        }
        if (poly2) {
            result = AddNode(result, poly2->coef, poly2->exp);
            poly2 = poly2->next;
        }
    }
    return result;
} //end-Add

//-------------------------------------------------
// Subtracts poly2 from poly1 and returns the resulting polynomial
// Computes: poly3 = poly1 - poly2 and returns poly3
//
PolyNode* Subtract(PolyNode* poly1, PolyNode* poly2) {
    PolyNode* result = NULL;
    // Traverse both polynomials and subtract their corresponding nodes
    while (poly1 || poly2) {
        if (poly1) {
            result = AddNode(result, poly1->coef, poly1->exp);
            poly1 = poly1->next;
        }
        if (poly2) {
            result = AddNode(result, -poly2->coef, poly2->exp); // Negate the coefficient of poly2
            poly2 = poly2->next;
        }
    }
    return result;
} //end-Substract

//-------------------------------------------------
// Multiplies poly1 and poly2 and returns the resulting polynomial
// Computes: poly3 = poly1 * poly2 and returns poly3
//
PolyNode* Multiply(PolyNode* poly1, PolyNode* poly2) {
    PolyNode* result = NULL;
    // Nested loop to multiply each term of poly1 with every term of poly2
    for (PolyNode* p1 = poly1; p1 != NULL; p1 = p1->next) {
        for (PolyNode* p2 = poly2; p2 != NULL; p2 = p2->next) {
            result = AddNode(result, p1->coef * p2->coef, p1->exp + p2->exp);
        }
    }
    return result;
} //end-Multiply

//-------------------------------------------------
// Evaluates the polynomial at a particular "x" value and returns the result
//
double Evaluate(PolyNode* poly, double x) {
    double result = 0;
    // Traverse the polynomial and calculate the result for the given x
    while (poly) {
        result += poly->coef * pow(x, poly->exp);
        poly = poly->next;
    }
    return result;
} //end-Evaluate

//-------------------------------------------------
// Computes the derivative of the polynomial and returns it
// Ex: poly(x) = 3x^4 - 2x + 1-->Derivative(poly) = 12x^3 - 2
//
PolyNode* Derivative(PolyNode* poly) {
    PolyNode* result = NULL;
    // Traverse the polynomial and calculate the derivative
    while (poly) {
        if (poly->exp > 0) {
            result = AddNode(result, poly->coef * poly->exp, poly->exp - 1);
        }
        poly = poly->next;
    }
    return result;
} //end-Derivative

//-------------------------------------------------
// Plots the polynomial in the range [x1, x2].
// -39<=x1<x2<=39
// -12<=y<=12
// On the middle of the screen you gotta have x & y axis plotted
// During evaluation, if "y" value does not fit on the screen,
// then just skip it. Otherwise put a '*' char depicting the curve
//
void Plot(PolyNode* poly, int x1, int x2) {
    // Iterate over the y-axis from top to bottom
    for (int y = 12; y >= -12; y--) {
        for (int x = x1; x <= x2; x++) {
            // Plot '*' if the evaluated value at 'x' is equal to 'y'
            if (round(Evaluate(poly, x)) == y)
                printf("*");
            else if (x == 0)
                printf("|"); // Plot the y-axis
            else if (y == 0)
                printf("-"); // Plot the x-axis
            else
                printf(" ");
        }
        printf("\n");
    }
} //end-Plot