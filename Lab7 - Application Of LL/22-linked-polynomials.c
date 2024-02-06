#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int cof;
    int exp;
    struct Node *next;
};

struct Node *createNode(int cof, int exp)
{
    struct Node *nn = (struct Node *)malloc(sizeof(struct Node));
    nn->cof = cof;
    nn->exp = exp;
    nn->next = NULL;
    return nn;
}

void insertNode(struct Node **poly, int cof, int exp)
{
    struct Node *nn = createNode(cof, exp);
    if (*poly == NULL)
    {
        *poly = nn;
    }
    else
    {
        struct Node *curr = *poly;
        while (curr->next != NULL)
        {
            curr = curr->next;
        }
        curr->next = nn;
    }
}

void printPolynomial(struct Node *poly)
{
    if (poly == NULL)
    {
        printf("0\n");
        return;
    }
    while (poly != NULL)
    {
        printf("%dx^%d", poly->cof, poly->exp);
        poly = poly->next;
        if (poly != NULL)
        {
            printf(" + ");
        }
    }
    printf("\n");
}

struct Node *addPolynomials(struct Node *poly1, struct Node *poly2)
{
    struct Node *result = NULL;
    while (poly1 != NULL && poly2 != NULL)
    {
        if (poly1->exp > poly2->exp)
        {
            insertNode(&result, poly1->cof, poly1->exp);
            poly1 = poly1->next;
        }
        else if (poly1->exp < poly2->exp)
        {
            insertNode(&result, poly2->cof, poly2->exp);
            poly2 = poly2->next;
        }
        else
        {
            int sum_coeff = poly1->cof + poly2->cof;
            if (sum_coeff != 0)
            {
                insertNode(&result, sum_coeff, poly1->exp);
            }
            poly1 = poly1->next;
            poly2 = poly2->next;
        }
    }
    while (poly1 != NULL)
    {
        insertNode(&result, poly1->cof, poly1->exp);
        poly1 = poly1->next;
    }
    while (poly2 != NULL)
    {
        insertNode(&result, poly2->cof, poly2->exp);
        poly2 = poly2->next;
    }
    return result;
}

struct Node *subtractPolynomials(struct Node *poly1, struct Node *poly2)
{
    struct Node *result = NULL;
    while (poly1 != NULL && poly2 != NULL)
    {
        if (poly1->exp > poly2->exp)
        {
            insertNode(&result, poly1->cof, poly1->exp);
            poly1 = poly1->next;
        }
        else if (poly1->exp < poly2->exp)
        {
            insertNode(&result, -poly2->cof, poly2->exp);
            poly2 = poly2->next;
        }
        else
        {
            int diff_coeff = poly1->cof - poly2->cof;
            if (diff_coeff != 0)
            {
                insertNode(&result, diff_coeff, poly1->exp);
            }
            poly1 = poly1->next;
            poly2 = poly2->next;
        }
    }
    while (poly1 != NULL)
    {
        insertNode(&result, poly1->cof, poly1->exp);
        poly1 = poly1->next;
    }
    while (poly2 != NULL)
    {
        insertNode(&result, -poly2->cof, poly2->exp);
        poly2 = poly2->next;
    }
    return result;
}

void freePolynomial(struct Node *poly)
{
    while (poly != NULL)
    {
        struct Node *temp = poly;
        poly = poly->next;
        free(temp);
    }
}

int main()
{
    struct Node *poly1 = NULL;
    struct Node *poly2 = NULL;
    struct Node *sum = NULL;
    struct Node *difference = NULL;
    int n, cof, exp;
    printf("Enter the number of Nodes in the first polynomial: ");
    scanf("%d", &n);
    printf("Enter the Nodes of the first polynomial (cof and exp):\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d %d", &cof, &exp);
        insertNode(&poly1, cof, exp);
    }
    printf("Enter the number of Nodes in the second polynomial: ");
    scanf("%d", &n);
    printf("Enter the Nodes of the second polynomial (cof and exp):\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d %d", &cof, &exp);
        insertNode(&poly2, cof, exp);
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