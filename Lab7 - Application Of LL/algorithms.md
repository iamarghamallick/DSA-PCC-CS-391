# Reverse a linked list by Iterative Method
    The idea is to use three pointers curr, prev, and next to keep track of nodes to update reverse links.

## Follow the steps below to solve the problem:

    1. Initialize three pointers prev as NULL, curr as head, and next as NULL.
    2. Iterate through the linked list. In a loop, do the following:
        3. Before changing the next of curr, store the next node
            next = curr -> next
        4. Now update the next pointer of curr to the prev
            curr -> next = prev
        5. Update prev as curr and curr as next
            prev = curr
            curr = next
