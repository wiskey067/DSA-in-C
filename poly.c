#include <stdio.h>

// Function to add two polynomials
void addPolynomials(int coeff1[], int exp1[], int n1, int coeff2[], int exp2[], int n2, int resultCoeff[], int resultExp[], int *nResult) {
    int i = 0, j = 0, k = 0;

    // Traverse both input polynomials
    while (i < n1 && j < n2) {
        if (exp1[i] > exp2[j]) {
            resultCoeff[k] = coeff1[i];
            resultExp[k] = exp1[i];
            i++;
        } else if (exp1[i] < exp2[j]) {
            resultCoeff[k] = coeff2[j];
            resultExp[k] = exp2[j];
            j++;
        } else {
            resultCoeff[k] = coeff1[i] + coeff2[j];
            resultExp[k] = exp1[i];
            i++;
            j++;
        }
        k++;
    }

    // Copy any remaining terms from the first polynomial
    while (i < n1) {
        resultCoeff[k] = coeff1[i];
        resultExp[k] = exp1[i];
        i++;
        k++;
    }

    // Copy any remaining terms from the second polynomial
    while (j < n2) {
        resultCoeff[k] = coeff2[j];
        resultExp[k] = exp2[j];
        j++;
        k++;
    }

    *nResult = k; // Update the size of the result polynomial
}

int main() {
    int n1, n2, nResult;
    printf("Enter the number of terms in the first polynomial: ");
    scanf("%d", &n1);

    int coeff1[n1], exp1[n1];
    printf("Enter the coefficients and exponents of the first polynomial (in descending order of exponents):\n");
    for (int i = 0; i < n1; i++) {
        scanf("%d %d", &coeff1[i], &exp1[i]);
    }

    printf("Enter the number of terms in the second polynomial: ");
    scanf("%d", &n2);

    int coeff2[n2], exp2[n2];
    printf("Enter the coefficients and exponents of the second polynomial (in descending order of exponents):\n");
    for (int i = 0; i < n2; i++) {
        scanf("%d %d", &coeff2[i], &exp2[i]);
    }

    // Initialize arrays for the result polynomial
    int resultCoeff[n1 + n2], resultExp[n1 + n2];

    // Call the addPolynomials function
    addPolynomials(coeff1, exp1, n1, coeff2, exp2, n2, resultCoeff, resultExp, &nResult);

    // Display the result polynomial
    printf("Resultant polynomial in polynomial form:\n");
    for (int i = 0; i < nResult; i++) {
        printf("%d", resultCoeff[i]);
        if (resultExp[i] != 0) {
            printf("x^%d", resultExp[i]);
        }
        if (i < nResult - 1) {
            printf(" + ");
        }
    }
    printf("\n");

    return 0;
}
