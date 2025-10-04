#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX 100

// Structure for tree nodes
struct Node {
    char data;
    struct Node *left, *right;
};

// Stack for tree nodes
struct StackNode {
    struct Node* data;
    struct StackNode* next;
};
struct StackNode* topNode = NULL;

// Stack for operators (char)
char opStack[MAX];
int topOp = -1;

// Push/Pop for Node stack
void pushNode(struct Node* treeNode) {
    struct StackNode* temp = (struct StackNode*)malloc(sizeof(struct StackNode));
    temp->data = treeNode;
    temp->next = topNode;
    topNode = temp;
}
struct Node* popNode() {
    if (topNode == NULL) return NULL;
    struct StackNode* temp = topNode;
    struct Node* res = topNode->data;
    topNode = topNode->next;
    free(temp);
    return res;
}

// Create new tree node
struct Node* createNode(char value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Operator precedence function
int precedence(char symbol) {
    switch (symbol) {
        case '^': return 3;
        case '*':
        case '/': return 2;
        case '+':
        case '-': return 1;
        default: return 0;
    }
}
void pushOp(char item) {
    opStack[++topOp] = item;
}
char popOp() {
    return opStack[topOp--];
}
char peekOp() {
    return opStack[topOp];
}

// Infix to postfix conversion
void infixToPostfix(char infix[], char postfix[]) {
    int i = 0, j = 0;
    char symbol;
    pushOp('(');
    strcat(infix, ")");
    while (infix[i] != '\0') {
        symbol = infix[i];
        if (symbol == ' ') { i++; continue; }
        if (symbol == '(') pushOp(symbol);
        else if (isalnum(symbol))
            postfix[j++] = symbol;
        else if (symbol == ')') {
            while (peekOp() != '(')
                postfix[j++] = popOp();
            popOp();
        } else {
            while (precedence(peekOp()) >= precedence(symbol))
                postfix[j++] = popOp();
            pushOp(symbol);
        }
        i++;
    }
    postfix[j] = '\0';
}

// Build expression tree from postfix
struct Node* createExpressionTree(char postfix[]) {
    int i = 0;
    char symbol;
    while ((symbol = postfix[i]) != '\0') {
        if (isalnum(symbol))
            pushNode(createNode(symbol));
        else {
            struct Node* operatorNode = createNode(symbol);
            operatorNode->right = popNode();
            operatorNode->left = popNode();
            pushNode(operatorNode);
        }
        i++;
    }
    return popNode();
}

// Tree traversals
void inorder(struct Node* root) {
    if (root != NULL) {
        if(root->left && root->right) printf("(");
        inorder(root->left);
        printf("%c", root->data);
        inorder(root->right);
        if(root->left && root->right) printf(")");
    }
}
void preorder(struct Node* root) {
    if (root != NULL) {
        printf("%c", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}
void postorder(struct Node* root) {
    if (root != NULL) {
        postorder(root->left);
        postorder(root->right);
        printf("%c", root->data);
    }
}

int main() {
    struct Node* root = NULL;
    int choice;
    char infix[MAX], postfix[MAX];

    do {
        printf("\nMenu\n----\n");
        printf("1. Enter Infix and Create Expression Tree\n");
        printf("2. Inorder Traversal (Infix)\n");
        printf("3. Preorder Traversal (Prefix)\n");
        printf("4. Postorder Traversal (Postfix)\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar();

        switch(choice) {
            case 1:
                topOp = -1; // Reset operator stack
                printf("Enter infix expression: ");
                gets(infix); // replace with fgets for safety in real code
                infixToPostfix(infix, postfix);
                printf("Postfix Expression: %s\n", postfix);
                root = createExpressionTree(postfix);
                printf("Expression Tree Created Successfully.\n");
                break;
            case 2:
                if(root == NULL) printf("Create the tree first!\n");
                else {
                    printf("Inorder Traversal (Infix): ");
                    inorder(root);
                    printf("\n");
                }
                break;
            case 3:
                if(root == NULL) printf("Create the tree first!\n");
                else {
                    printf("Preorder Traversal (Prefix): ");
                    preorder(root);
                    printf("\n");
                }
                break;
            case 4:
                if(root == NULL) printf("Create the tree first!\n");
                else {
                    printf("Postorder Traversal (Postfix): ");
                    postorder(root);
                    printf("\n");
                }
                break;
            case 5:
                printf("Exiting program.\n");
                exit(0);
            default:
                printf("Invalid choice! Try again.\n");
        }
    } while(1);

    return 0;
}

