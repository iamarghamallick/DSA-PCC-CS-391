# Tower of Hanoi using Recursion:
## The idea is to use the helper node to reach the destination using recursion. Below is the pattern for this problem:

- Shift ‘N-1’ disks from ‘A’ to ‘B’, using C.
- Shift last disk from ‘A’ to ‘C’.
- Shift ‘N-1’ disks from ‘B’ to ‘C’, using A.

## Follow the steps below to solve the problem:

    1. Create a function towerOfHanoi where pass the N (current number of disk), from_rod, to_rod, aux_rod.
    2. Make a function call for N – 1 th disk.
    3. Then print the current the disk along with from_rod and to_rod
    4. Again make a function call for N – 1 th disk.


# Infix expression to a Postfix expression
- To convert infix expression to postfix expression, use the stack data structure. Scan the infix expression from left to right. Whenever we get an operand, add it to the postfix expression and if we get an operator or parenthesis add it to the stack by maintaining their precedence.

## Below are the steps to implement the above idea:

    1. Scan the infix expression from left to right.
    2. If the scanned character is an operand, put it in the postfix expression.
    3. Otherwise, do the following
        - If the precedence and associativity of the scanned operator are greater than the precedence and associativity of the operator in the stack [or the stack is empty or the stack contains a ‘(‘ ], then push it in the stack. [‘^‘ operator is right associative and other operators like ‘+‘,’–‘,’*‘ and ‘/‘ are left-associative].
            - Check especially for a condition when the operator at the top of the stack and the scanned operator both are ‘^‘. In this condition, the precedence of the scanned operator is higher due to its right associativity. So it will be pushed into the operator stack.
            - In all the other cases when the top of the operator stack is the same as the scanned operator, then pop the operator from the stack because of left associativity due to which the scanned operator has less precedence.
        - Else, Pop all the operators from the stack which are greater than or equal to in precedence than that of the scanned operator.
            - After doing that Push the scanned operator to the stack. (If you encounter parenthesis while popping then stop there and push the scanned operator in the stack.)
    4. If the scanned character is a ‘(‘, push it to the stack.
    5. If the scanned character is a ‘)’, pop the stack and output it until a ‘(‘ is encountered, and discard both the parenthesis.
    6. Repeat steps 2-5 until the infix expression is scanned.
    7. Once the scanning is over, Pop the stack and add the operators in the postfix expression until it is not empty.
    8. Finally, print the postfix expression.


# Evaluation of Postfix Expression using Stack
    To evaluate a postfix expression we can use a stack.

- Iterate the expression from left to right and keep on storing the operands into a stack. Once an operator is received, pop the two topmost elements and evaluate them and push the result in the stack again.

## Follow the steps mentioned below to evaluate postfix expression using stack:

    1. Create a stack to store operands (or values).
    2. Scan the given expression from left to right and do the following for every scanned element.
        - If the element is a number, push it into the stack.
        - If the element is an operator, pop operands for the operator from the stack. Evaluate the operator and push the result back to the stack.
    3. When the expression is ended, the number in the stack is the final answer.
