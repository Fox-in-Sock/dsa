#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Node creation function
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (!newNode) {
        printf("Memory error\n");
        return NULL;
    }
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Insert node into BST
struct Node* insertNode(struct Node* root, int data) {
    if (root == NULL) {
        root = createNode(data);
    } else if (data < root->data) {
        root->left = insertNode(root->left, data);
    } else if (data > root->data) {
        root->right = insertNode(root->right, data);
    } else {
        printf("Duplicate data not allowed\n");
    }
    return root;
}

// Search for node in BST
int searchNode(struct Node* root, int data) {
    if (root == NULL) return 0;
    if (data < root->data) return searchNode(root->left, data);
    if (data > root->data) return searchNode(root->right, data);
    return 1;
}

// Find minimum value node in BST
struct Node* findMin(struct Node* root) {
    while (root->left != NULL) {
        root = root->left;
    }
    return root;
}

// Delete node from BST
struct Node* deleteNode(struct Node* root, int data) {
    if (root == NULL) return root;

    if (data < root->data) {
        root->left = deleteNode(root->left, data);
    } else if (data > root->data) {
        root->right = deleteNode(root->right, data);
    } else {
        // Case 1: No children
        if (root->left == NULL && root->right == NULL) {
            free(root);
            root = NULL;
        }
        // Case 2: One child (right)
        else if (root->left == NULL) {
            struct Node* temp = root;
            root = root->right;
            free(temp);
        }
        // Case 3: One child (left)
        else if (root->right == NULL) {
            struct Node* temp = root;
            root = root->left;
            free(temp);
        }
        // Case 4: Two children
        else {
            struct Node* temp = findMin(root->right);
            root->data = temp->data;
            root->right = deleteNode(root->right, temp->data);
        }
    }
    return root;
}

// Inorder traversal
void inorderTraversal(struct Node* root) {
    if (root != NULL) {
        inorderTraversal(root->left);
        printf("%d ", root->data);
        inorderTraversal(root->right);
    }
}

// Preorder traversal
void preorderTraversal(struct Node* root) {
    if (root != NULL) {
        printf("%d ", root->data);
        preorderTraversal(root->left);
        preorderTraversal(root->right);
    }
}

// Postorder traversal
void postorderTraversal(struct Node* root) {
    if (root != NULL) {
        postorderTraversal(root->left);
        postorderTraversal(root->right);
        printf("%d ", root->data);
    }
}

int main() {
    struct Node* root = NULL;
    int choice, data;

    while (1) {
        printf("\nBinary Search Tree Operations Menu\n");
        printf("1. Insert Node\n");
        printf("2. Search Node\n");
        printf("3. Delete Node\n");
        printf("4. Inorder Traversal\n");
        printf("5. Preorder Traversal\n");
        printf("6. Postorder Traversal\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data to insert: ");
                scanf("%d", &data);
                root = insertNode(root, data);
                break;
            case 2:
                printf("Enter data to search: ");
                scanf("%d", &data);
                if (searchNode(root, data))
                    printf("%d found in the tree\n", data);
                else
                    printf("%d not found in the tree\n", data);
                break;
            case 3:
                printf("Enter data to delete: ");
                scanf("%d", &data);
                root = deleteNode(root, data);
                break;
            case 4:
                printf("Inorder Traversal: ");
                inorderTraversal(root);
                printf("\n");
                break;
            case 5:
                printf("Preorder Traversal: ");
                preorderTraversal(root);
                printf("\n");
                break;
            case 6:
                printf("Postorder Traversal: ");
                postorderTraversal(root);
                printf("\n");
                break;
            case 7:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice. Please choose again.\n");
        }
    }
    return 0;
}
