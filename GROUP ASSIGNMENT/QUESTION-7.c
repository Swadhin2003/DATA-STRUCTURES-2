//Write a program to check that the left sub-tree of an binary tree is a mirror image of its right sub-tree.
#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *left, *right;
};
struct node *createNode(int val)
{
  struct node *newNode = malloc(sizeof(struct node));
  newNode->data = val;
  newNode->left = NULL;
  newNode->right = NULL;
  return newNode;
}
void inorder(struct node *root) 
{
  if (root == NULL)
  return;
  inorder(root->left);
  printf("%d->", root->data);
  inorder(root->right);
}
int mirror(struct node *root)
{
    if(root==NULL)
    return 1;
    else
    {
        while(root->left!=NULL && root->right!=NULL)
        {
            if(root->left->data==root->right->data)
            {
                mirror(root->left);
                mirror(root->right);
                return 1;
            }
            else
            return 0;
        }
    }
}
int main()
{
    struct node *root= createNode(35);
    root->left=createNode(20);
    root->right=createNode(20);
    root->left->left=createNode(15);
    root->left->right=createNode(33);
    root->right->left=createNode(33);
    root->right->right=createNode(15);
    printf("The tree is:");
    inorder(root);
    int x= mirror(root);
    if (x)
    printf("\nYes, mirror images");
    else
    printf("\nNot mirror images");
    return 0;
}
