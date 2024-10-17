#include <stdio.h>
#include <stdlib.h>
struct Node {
    int coeff;  // Coefficient of the term
    int exp;    // Exponent of the term
    struct Node* next;
};

// Function to create a new node
struct Node* createNode(int coeff, int exp) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->coeff = coeff;
    newNode->exp = exp;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a term at the end of the list
void insertEnd(struct Node** head, int coeff, int exp) {
    struct Node* newNode = createNode(coeff, exp);
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    struct Node* temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}

// Function to display the polynomial
void display(struct Node* head) {
    if (head == NULL) {
        printf("0");
        return;
    }
    while (head != NULL) {
        printf("%d*x^%d", head->coeff, head->exp);
        if (head->next != NULL) {
            printf(" + ");
        }
        head = head->next;
    }
    printf("\n");
}

// Function to add two polynomials
struct Node* addPolynomials(struct Node* poly1, struct Node* poly2) {
    struct Node* result = NULL;
    while (poly1 != NULL && poly2 != NULL) {
        if (poly1->exp > poly2->exp) {
            insertEnd(&result, poly1->coeff, poly1->exp);
            poly1 = poly1->next;
        } else if (poly1->exp < poly2->exp) {
            insertEnd(&result, poly2->coeff, poly2->exp);
            poly2 = poly2->next;
        } else {
            insertEnd(&result, poly1->coeff + poly2->coeff, poly1->exp);
            poly1 = poly1->next;
            poly2 = poly2->next;
        }
    }
    // Add remaining terms from poly1 or poly2
    while (poly1 != NULL) {
        insertEnd(&result, poly1->coeff, poly1->exp);
        poly1 = poly1->next;
    }
    while (poly2 != NULL) {
        insertEnd(&result, poly2->coeff, poly2->exp);
        poly2 = poly2->next;
    }
    return result;
}

// Function to multiply two polynomials
struct Node* multiplyPolynomials(struct Node* poly1, struct Node* poly2) {
    struct Node* result = NULL;

    // Multiply each term of poly1 with every term of poly2
    for (struct Node* i = poly1; i != NULL; i = i->next) {
        for (struct Node* j = poly2; j != NULL; j = j->next) {
            int coeff = i->coeff * j->coeff;
            int exp = i->exp + j->exp;

            // Add the product to the result
            struct Node* temp = result;
            struct Node* prev = NULL;
            while (temp != NULL && temp->exp > exp) {
                prev = temp;
                temp = temp->next;
            }
            if (temp != NULL && temp->exp == exp) {
                temp->coeff += coeff;
            } else {
                struct Node* newNode = createNode(coeff, exp);
                if (prev == NULL) {  // Insert at the beginning
                    newNode->next = result;
                    result = newNode;
                } else {  // Insert in the middle or end
                    newNode->next = temp;
                    prev->next = newNode;
                }
            }
        }
    }
    return result;
}

// Main function to test the operations
int main() {
    struct Node *poly1 = NULL, *poly2 = NULL;

    // Create first polynomial: 3x^2 + 5x^1 + 6
    insertEnd(&poly1, 3, 2);
    insertEnd(&poly1, 5, 1);
    insertEnd(&poly1, 6, 0);

    // Create second polynomial: 6x^1 + 2
    insertEnd(&poly2, 6, 1);
    insertEnd(&poly2, 2, 0);

    printf("Polynomial 1: ");
    display(poly1);

    printf("Polynomial 2: ");
    display(poly2);

    struct Node* sum = addPolynomials(poly1, poly2);
    printf("Sum: ");
    display(sum);

    struct Node* product = multiplyPolynomials(poly1, poly2);
    printf("Product: ");
    display(product);

    return 0;
}
