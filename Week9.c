#include <stdio.h>
#include <malloc.h>

typedef struct BST {
    int data;
    struct BST *left;
    struct BST *right;
} node;

node *create() {
    node *temp;
    printf("Enter data: ");
    temp = (node *)malloc(sizeof(node));
    scanf("%d", &temp->data);
    temp->left = temp->right = NULL;
    return temp;
}

void insert(node *root, node *temp) {
    if (temp->data < root->data) {
        if (root->left != NULL)
            insert(root->left, temp);
        else
            root->left = temp;
    } else if (temp->data > root->data) {
        if (root->right != NULL)
            insert(root->right, temp);
        else
            root->right = temp;
    }
}

void preorder(node *root) {
    if (root != NULL) {
        printf("%d ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

void inorder(node *root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

void postorder(node *root) {
    if (root != NULL) {
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->data);
    }
}

int main() {
    char ch;
    node *root = NULL, *temp;

    printf("Do you want to enter data? ");
    printf("\Y/N:");
    scanf("%c", &ch);  // Initial check to start the loop

    while (ch == 'y' || ch == 'Y') {
        temp = create();
        if (root == NULL)
            root = temp;
        else
            insert(root, temp);

        printf("\nEnter more data?\nY/N:");
        getchar(); // To consume the newline character left by scanf
        scanf("%c", &ch);  // Read the user's input
    }

    printf("\nPreorder Traversal: ");
    preorder(root);
    printf("\nInorder Traversal: ");
    inorder(root);
    printf("\nPostorder Traversal: ");
    postorder(root);

    return 0;
}

OUPUT:
Do you want to enter data? Y/N:y
Enter data: 5

Enter more data?
Y/N:y
Enter data: 3

Enter more data?
Y/N:y
Enter data: 7

Enter more data?
Y/N:y
Enter data: 2

Enter more data?
Y/N:y
Enter data: 4

Enter more data?
Y/N:n

Preorder Traversal: 5 3 2 4 7
Inorder Traversal: 2 3 4 5 7
Postorder Traversal: 2 4 3 7 5
Process returned 0 (0x0)   execution time : 25.126 s
Press any key to continue.

#include <stdio.h>

void bfs(int adj[10][10], int n, int source){
    int que[10];
    int front=0,rear=-1;
    int visited[10]={0};
    int node;
    printf("The nodes visited from %d: ", source);
    que[++rear]=source;
    visited[source]=1;
    printf("%d",source);
    while(front<=rear){
        int u= que[front++];
        for(int v=0; v<n; v++){
            if(adj[u][v]==1){
                if(visited[v]==0){
                    printf("%d",v);
                    visited[v]=1;
                    que[++rear]=v;
                }
            }
        }
    }
    printf("\n");
}

int main() {
    int n;
    int adj[10][10];
    int source;
    printf("enter number of nodes \n");
    scanf("%d",&n);
    printf("Enter Adjacency Matrix \n");
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            scanf("%d",&adj[i][j]);
        }
    }
    for(source=0; source<n; source++){
        bfs(adj,n,source);
    }

    return 0;
}
OUPUT:
enter number of nodes
4
Enter Adjacency Matrix
0 1 1 0
1 0 1 1
1 1 0 1
0 1 1 0
The nodes visited from 0: 0123
The nodes visited from 1: 1023
The nodes visited from 2: 2013
The nodes visited from 3: 3120

Process returned 0 (0x0)   execution time : 51.967 s
Press any key to continue.

LEETCODE:
bool hasPathSum(struct TreeNode* root, int targetSum) {
    if (root == NULL) {
        return false;
    }
    
    targetSum -= root->val;
    
    if (root->left == NULL && root->right == NULL) {
        return targetSum == 0;
    }
    
    return hasPathSum(root->left, targetSum) || hasPathSum(root->right, targetSum);
}
