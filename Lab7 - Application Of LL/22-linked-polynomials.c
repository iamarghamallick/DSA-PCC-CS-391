// // Write a C program for linked representation of polynomials and also perform addition, subtraction of two polynomials

// #include <stdio.h>
// #include <stdlib.h>

// struct Node
// {
//     int coef;
//     int expo;
//     struct Node *next;
// };

// struct Node *createNode(int coef, int expo)
// {
//     struct Node *nn = (struct Node *)malloc(sizeof(struct Node));
//     nn->coef = coef;
//     nn->expo = expo;
//     nn->next = NULL;
//     return nn;
// }

// void createExp(struct Node **head, int coef, int expo)
// {
//     struct Node *nn = createNode(coef, expo);
//     if ((*head) == NULL)
//     {
//         *head = nn;
//     }
//     else
//     {
//         struct Node *temp = *head;
//         while (temp->next != NULL)
//         {
//             temp = temp->next;
//         }
//         temp->next = nn;
//     }
// }

// void display(struct Node *head)
// {
//     struct Node *temp = head;
//     while (temp != NULL)
//     {
//         printf("(%dx^%d) + ", temp->coef, temp->expo);
//         temp = temp->next;
//     }
//     printf("NULL\n");
// }

// int main()
// {
//     struct Node *poly1Head = NULL;
//     struct Node *poly2Head = NULL;
//     createExp(&poly1Head, -1, 1);
//     createExp(&poly1Head, 2, 2);
//     createExp(&poly1Head, 3, 3);
//     display(poly1Head);
//     return 0;
// }

#include <stdio.h>
#include <stdlib.h>

struct Term
{
    int coefficient;
    int exponent;
    struct Term *next;
};

struct Term *createTerm(int coefficient, int exponent)
{
    struct Term *newTerm = (struct Term *)malloc(sizeof(struct Term));
    if (newTerm == NULL)
    {
        printf("Memory allocation failed.\n");
        exit(1);
    }
    newTerm->coefficient = coefficient;
    newTerm->exponent = exponent;
    newTerm->next = NULL;
    return newTerm;
}

void insertTerm(struct Term **poly, int coefficient, int exponent)
{
    struct Term *newTerm = createTerm(coefficient, exponent);
    if (*poly == NULL)
    {
        *poly = newTerm;
    }
    else
    {
        struct Term *current = *poly;
        while (current->next != NULL)
        {
            current = current->next;
        }
        current->next = newTerm;
    }
}

void printPolynomial(struct Term *poly)
{
    if (poly == NULL)
    {
        printf("0\n");
        return;
    }
    while (poly != NULL)
    {
        printf("%dx^%d", poly->coefficient, poly->exponent);
        poly = poly->next;
        if (poly != NULL)
        {
            printf(" + ");
        }
    }
    printf("\n");
}

struct Term *addPolynomials(struct Term *poly1, struct Term *poly2)
{
    struct Term *result = NULL;
    while (poly1 != NULL && poly2 != NULL)
    {
        if (poly1->exponent > poly2->exponent)
        {
            insertTerm(&result, poly1->coefficient, poly1->exponent);
            poly1 = poly1->next;
        }
        else if (poly1->exponent < poly2->exponent)
        {
            insertTerm(&result, poly2->coefficient, poly2->exponent);
            poly2 = poly2->next;
        }
        else
        {
            int sum_coeff = poly1->coefficient + poly2->coefficient;
            if (sum_coeff != 0)
            {
                insertTerm(&result, sum_coeff, poly1->exponent);
            }
            poly1 = poly1->next;
            poly2 = poly2->next;
        }
    }
    while (poly1 != NULL)
    {
        insertTerm(&result, poly1->coefficient, poly1->exponent);
        poly1 = poly1->next;
    }
    while (poly2 != NULL)
    {
        insertTerm(&result, poly2->coefficient, poly2->exponent);
        poly2 = poly2->next;
    }
    return result;
}

struct Term *subtractPolynomials(struct Term *poly1, struct Term *poly2)
{
    struct Term *result = NULL;
    while (poly1 != NULL && poly2 != NULL)
    {
        if (poly1->exponent > poly2->exponent)
        {
            insertTerm(&result, poly1->coefficient, poly1->exponent);
            poly1 = poly1->next;
        }
        else if (poly1->exponent < poly2->exponent)
        {
            insertTerm(&result, -poly2->coefficient, poly2->exponent);
            poly2 = poly2->next;
        }
        else
        {
            int diff_coeff = poly1->coefficient - poly2->coefficient;
            if (diff_coeff != 0)
            {
                insertTerm(&result, diff_coeff, poly1->exponent);
            }
            poly1 = poly1->next;
            poly2 = poly2->next;
        }
    }
    while (poly1 != NULL)
    {
        insertTerm(&result, poly1->coefficient, poly1->exponent);
        poly1 = poly1->next;
    }
    while (poly2 != NULL)
    {
        insertTerm(&result, -poly2->coefficient, poly2->exponent);
        poly2 = poly2->next;
    }
    return result;
}

void freePolynomial(struct Term *poly)
{
    while (poly != NULL)
    {
        struct Term *temp = poly;
        poly = poly->next;
        free(temp);
    }
}

int main()
{
    struct Term *poly1 = NULL;
    struct Term *poly2 = NULL;
    struct Term *sum = NULL;
    struct Term *difference = NULL;
    int n, coefficient, exponent;
    printf("Enter the number of terms in the first polynomial: ");
    scanf("%d", &n);
    printf("Enter the terms of the first polynomial (coefficient and exponent):\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d %d", &coefficient, &exponent);
        insertTerm(&poly1, coefficient, exponent);
    }
    printf("Enter the number of terms in the second polynomial: ");
    scanf("%d", &n);
    printf("Enter the terms of the second polynomial (coefficient and exponent):\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d %d", &coefficient, &exponent);
        insertTerm(&poly2, coefficient, exponent);
    }
    printf("First Polynomial: ");
    printPolynomial(poly1);
    printf("Second Polynomial: ");
    printPolynomial(poly2);
    sum = addPolynomials(poly1, poly2);
    printf("Sum of Polynomials: ");
    printPolynomial(sum);
    difference = subtractPolynomials(poly1, poly2);
    printf("Difference of Polynomials: ");
    printPolynomial(difference);
    freePolynomial(poly1);
    freePolynomial(poly2);
    freePolynomial(sum);
    freePolynomial(difference);
    return 0;
}
