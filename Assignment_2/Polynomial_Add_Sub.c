#include <stdio.h>
#include <stdlib.h>

// Structure to represent a term in the polynomial
struct Term {
    int coeff;    // Coefficient
    int exp;      // Exponent
    struct Term* next;  // Pointer to the next term
};

// Function to create a new term
struct Term* createTerm(int coeff, int exp) {
    struct Term* newTerm = (struct Term*)malloc(sizeof(struct Term));
    newTerm->coeff = coeff;
    newTerm->exp = exp;
    newTerm->next = NULL;
    return newTerm;
}

// Function to add a term to the polynomial
void addTerm(struct Term** poly, int coeff, int exp) {
    struct Term* newTerm = createTerm(coeff, exp);
    
    if (*poly == NULL) {
        *poly = newTerm;
        return;
    }

    struct Term* temp = *poly;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newTerm;
}

// Function to print a polynomial
void printPolynomial(struct Term* poly) {
    if (poly == NULL) {
        printf("0\n");
        return;
    }
    
    struct Term* temp = poly;
    while (temp != NULL) {
        if (temp->coeff > 0 && temp != poly)
            printf(" + ");
        else if (temp->coeff < 0)
            printf(" - ");
        
        printf("%dx^%d", abs(temp->coeff), temp->exp);
        
        temp = temp->next;
    }
    printf("\n");
}

// Function to add two polynomials
struct Term* addPolynomials(struct Term* poly1, struct Term* poly2) {
    struct Term* result = NULL;

    while (poly1 != NULL && poly2 != NULL) {
        if (poly1->exp > poly2->exp) {
            addTerm(&result, poly1->coeff, poly1->exp);
            poly1 = poly1->next;
        } else if (poly1->exp < poly2->exp) {
            addTerm(&result, poly2->coeff, poly2->exp);
            poly2 = poly2->next;
        } else {
            addTerm(&result, poly1->coeff + poly2->coeff, poly1->exp);
            poly1 = poly1->next;
            poly2 = poly2->next;
        }
    }

    // Add remaining terms of poly1
    while (poly1 != NULL) {
        addTerm(&result, poly1->coeff, poly1->exp);
        poly1 = poly1->next;
    }

    // Add remaining terms of poly2
    while (poly2 != NULL) {
        addTerm(&result, poly2->coeff, poly2->exp);
        poly2 = poly2->next;
    }

    return result;
}

// Function to subtract two polynomials
struct Term* subtractPolynomials(struct Term* poly1, struct Term* poly2) {
    struct Term* result = NULL;

    while (poly1 != NULL && poly2 != NULL) {
        if (poly1->exp > poly2->exp) {
            addTerm(&result, poly1->coeff, poly1->exp);
            poly1 = poly1->next;
        } else if (poly1->exp < poly2->exp) {
            addTerm(&result, -poly2->coeff, poly2->exp);
            poly2 = poly2->next;
        } else {
            addTerm(&result, poly1->coeff - poly2->coeff, poly1->exp);
            poly1 = poly1->next;
            poly2 = poly2->next;
        }
    }

    // Add remaining terms of poly1
    while (poly1 != NULL) {
        addTerm(&result, poly1->coeff, poly1->exp);
        poly1 = poly1->next;
    }

    // Add remaining terms of poly2 (negated for subtraction)
    while (poly2 != NULL) {
        addTerm(&result, -poly2->coeff, poly2->exp);
        poly2 = poly2->next;
    }

    return result;
}

int main() {
    struct Term* poly1 = NULL;
    struct Term* poly2 = NULL;
    
    // Creating first polynomial: 3x^2 + 5x + 6
    addTerm(&poly1, 3, 2);
    addTerm(&poly1, 5, 1);
    addTerm(&poly1, 6, 0);
    
    // Creating second polynomial: 4x^3 + 2x^2 + 1
    addTerm(&poly2, 4, 3);
    addTerm(&poly2, 2, 2);
    addTerm(&poly2, 1, 0);
    
    // Print the polynomials
    printf("First Polynomial: ");
    printPolynomial(poly1);
    
    printf("Second Polynomial: ");
    printPolynomial(poly2);
    
    // Adding the two polynomials
    struct Term* sum = addPolynomials(poly1, poly2);
    printf("Sum of Polynomials: ");
    printPolynomial(sum);
    
    // Subtracting the two polynomials
    struct Term* difference = subtractPolynomials(poly1, poly2);
    printf("Difference of Polynomials: ");
    printPolynomial(difference);
    
    return 0;
}
