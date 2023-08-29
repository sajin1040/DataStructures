#include <stdio.h>
#include <stdlib.h>

struct Node 
{
    int key;
    struct Node* left;
    struct Node* right;
    int height;
};

int max(int a, int b) 
{
    return (a > b) ? a : b;
}

int height(struct Node* node) 
{
    if (node == NULL)
        return 0;
    return node->height;
}

int getBalance(struct Node* node) 
{
    if (node == NULL)
        return 0;
    return height(node->left) - height(node->right);
}

struct Node* newNode(int key) 
{
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->key = key;
    node->left = NULL;
    node->right = NULL;
    node->height = 1;
    return node;
}

struct Node* rightRotate(struct Node* y) 
{
    struct Node* x = y->left;
    struct Node* T2 = x->right;

    x->right = y;
    y->left = T2;

    y->height = max(height(y->left), height(y->right)) + 1;
    x->height = max(height(x->left), height(x->right)) + 1;

    return x;
}

struct Node* leftRotate(struct Node* x) 
{
    struct Node* y = x->right;
    struct Node* T2 = y->left;

    y->left = x;
    x->right = T2;

    x->height = max(height(x->left), height(x->right)) + 1;
    y->height = max(height(y->left), height(y->right)) + 1;

    return y;
}

struct Node* insert(struct Node* node, int key)
{
    if (node == NULL)
        return newNode(key);

    if (key < node->key)
        node->left = insert(node->left, key);
    else if (key > node->key)
        node->right = insert(node->right, key);
    else
        return node; 

    node->height = 1 + max(height(node->left), height(node->right));

    int balance = getBalance(node);

   
    if (balance > 1) 
	{
        if (key < node->left->key)
		{
            return rightRotate(node);
        } 
		else 
		{
            node->left = leftRotate(node->left);
            return rightRotate(node);
        }
    }
    if (balance < -1) 
	{
        if (key > node->right->key) 
		{
            return leftRotate(node);
        } 
		else 
		{
            node->right = rightRotate(node->right);
            return leftRotate(node);
        }
    }

    return node;
}

struct Node* minValueNode(struct Node* node) 
{
    struct Node* current = node;
    while (current->left != NULL)
        current = current->left;
    return current;
}

struct Node* deleteNode(struct Node* root, int key) 
{
    if (root == NULL)
        return root;

    if (key < root->key)
        root->left = deleteNode(root->left, key);
    else if (key > root->key)
        root->right = deleteNode(root->right, key);
    else 
	{
        if ((root->left == NULL) || (root->right == NULL)) 
		{
            struct Node* temp = root->left ? root->left : root->right;
            if (temp == NULL) 
			{
                temp = root;
                root = NULL;
            } 
			else
                *root = *temp;
            free(temp);
        } 
		else 
		{
            struct Node* temp = minValueNode(root->right);
            root->key = temp->key;
            root->right = deleteNode(root->right, temp->key);
        }
    }

    if (root == NULL)
        return root;

    root->height = 1 + max(height(root->left), height(root->right));

    int balance = getBalance(root);

    if (balance > 1) 
	{
        if (getBalance(root->left) >= 0)
            return rightRotate(root);
        else 
		{
            root->left = leftRotate(root->left);
            return rightRotate(root);
        }
    }
    if (balance < -1) 
	{
        if (getBalance(root->right) <= 0)
            return leftRotate(root);
        else 
		{
            root->right = rightRotate(root->right);
            return leftRotate(root);
        }
    }

    return root;
}

struct Node* search(struct Node* root, int key) 
{
    if (root == NULL || root->key == key)
        return root;

    if (key < root->key)
        return search(root->left, key);

    return search(root->right, key);
}

void inOrder(struct Node* root) 
{
    if (root != NULL) 
	{
        inOrder(root->left);
        printf("%d ", root->key);
        inOrder(root->right);
    }
}

int main() 
{
    struct Node* root = NULL;
    int choice, key;

    while (1) 
	{
        printf("\nAVL Tree Operations:\n");
        printf("1. Insert\n");
        printf("2. Delete\n");
        printf("3. Search\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) 
		{
            case 1:
                printf("Enter key to insert: ");
                scanf("%d", &key);
                root = insert(root, key);
                printf("Key %d inserted into the tree.\n", key);
                break;
            case 2:
                printf("Enter key to delete: ");
                scanf("%d", &key);
                root = deleteNode(root, key);
                printf("Key %d deleted from the tree.\n", key);
                break;
            case 3:
                printf("Enter key to search: ");
                scanf("%d", &key);
                struct Node* result = search(root, key);
                if (result != NULL)
                    printf("Key %d found in the tree.\n", key);
                else
                    printf("Key %d not found in the tree.\n", key);
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice! Please enter a valid option.\n");
        }

        printf("Updated AVL Tree (in-order traversal): ");
        inOrder(root);
        printf("\n");
    }

    return 0;
}

