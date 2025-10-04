#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX 100


struct Node {
    char data;
    struct Node *left, *right;
};


struct StackNode {
    struct Node* data;
    struct StackNode* next;
};
struct StackNode* topNode = NULL;


char opStack[MAX];
int topOp = -1;


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


struct Node* createNode(char value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->left = newNode->right = NULL;
    return newNode;
}

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
    if (topOp == -1) return '\0';
    return opStack[topOp];
}


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
            while (topOp != -1 && precedence(peekOp()) >= precedence(symbol))
                postfix[j++] = popOp();
            pushOp(symbol);
        }
        i++;
    }
    postfix[j] = '\0';
}


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
        printf("1. Enter Infix Expression and Create Expression Tree\n");
        printf("2. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar();

        switch(choice) {
            case 1:
                topOp = -1; 
                printf("Enter infix expression: ");
                fgets(infix, MAX, stdin);
                infix[strcspn(infix, "\n")] = 0; 
                infixToPostfix(infix, postfix);
                printf("Postfix Expression: %s\n", postfix);
                root = createExpressionTree(postfix);
                printf("Inorder Traversal (Infix): ");
                inorder(root);
                printf("\nPrefix Traversal: ");
                preorder(root);
                printf("\nPostfix Traversal: ");
                postorder(root);
                printf("\n");
                break;
            case 2:
                printf("Exiting program.\n");
                exit(0);
            default:
                printf("Invalid choice! Try again.\n");
        }
    } while(1);

    return 0;
}
