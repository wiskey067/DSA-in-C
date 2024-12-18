#include <stdio.h>

void inputPolynomial(int poly[], int degree) {
    for (int i = 0; i <= degree; i++) {
        printf("Enter the coefficient for x^%d: ", i);
        scanf("%d", &poly[i]);
    }
}


void addPolynomials(int poly1[], int poly2[], int result[], int degree) {
    for (int i = 0; i <= degree; i++) {
        result[i] = poly1[i] + poly2[i];
    }
}


void displayPolynomial(int poly[], int degree) {
    for (int i = degree; i >= 0; i--) {
        if (poly[i] != 0) {
            printf("%d", poly[i]);
            if (i > 0) {
                printf("x^%d", i);
            }
            if (i > 0 && i < degree) {
                printf(" + ");
            }
        }
    }
    printf("\n");
}

int main() {
    int degree;

    printf("Enter the degree of the polynomials: ");
    scanf("%d", &degree);

    int poly1[degree + 1];
    int poly2[degree + 1];
    int result[degree + 1];

    printf("Enter coefficients for the first polynomial:\n");
    inputPolynomial(poly1, degree);

    printf("Enter coefficients for the second polynomial:\n");
    inputPolynomial(poly2, degree);

    addPolynomials(poly1, poly2, result, degree);

    printf("Result of addition: ");
    displayPolynomial(result, degree);

    return 0;
}
