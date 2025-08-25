#include <stdio.h>

struct Term {
    int coeff;
    int expo;
};

void addPolynomials(struct Term poly1[], int n1, struct Term poly2[], int n2, struct Term polyResult[], int *nResult) {
    int i = 0, j = 0, k = 0;

    while (i < n1 && j < n2) {
        if (poly1[i].expo == poly2[j].expo) {
            polyResult[k].coeff = poly1[i].coeff + poly2[j].coeff;
            polyResult[k].expo = poly1[i].expo;
            i++;
            j++;
            k++;
        }
        else if (poly1[i].expo > poly2[j].expo) {
            polyResult[k] = poly1[i];
            i++;
            k++;
        }
        else {
            polyResult[k] = poly2[j];
            j++;
            k++;
        }
    }

    // Copy remaining terms of poly1
    while (i < n1) {
        polyResult[k] = poly1[i];
        i++;
        k++;
    }

    // Copy remaining terms of poly2
    while (j < n2) {
        polyResult[k] = poly2[j];
        j++;
        k++;
    }

    *nResult = k; // Total number of terms in result
}

void displayPolynomial(struct Term poly[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%dx^%d", poly[i].coeff, poly[i].expo);
        if (i != n - 1) {
            printf(" + ");
        }
    }
    printf("\n");
}

int main() {
    struct Term poly1[] = { {5, 3}, {4, 2}, {2, 0} };
    struct Term poly2[] = { {5, 2}, {5, 1}, {5, 0} };
    struct Term polyResult[20];
    int nResult;

    int n1 = 3; // Number of terms in poly1
    int n2 = 3; // Number of terms in poly2

    printf("First Polynomial: ");
    displayPolynomial(poly1, n1);

    printf("Second Polynomial: ");
    displayPolynomial(poly2, n2);

    addPolynomials(poly1, n1, poly2, n2, polyResult, &nResult);

    printf("Sum of Polynomials: ");
    displayPolynomial(polyResult, nResult);

    return 0;
}
