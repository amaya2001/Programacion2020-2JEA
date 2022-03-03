#ifndef BINARYTREE
#define BINARYTREE
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct TreeNode TreeNode;
typedef struct Tree Tree;
   int s;
struct TreeNode{
   char item;
   TreeNode * left;
   TreeNode * right;
};
struct Tree{
   TreeNode * root;
   void (*makeTree) ( Tree *, int, Tree *, Tree * );
   void (*preorder) ( TreeNode * );
   void (*inorder) ( TreeNode * );
   void (*postorder) ( TreeNode * );
   void (*levelorder) ( TreeNode * );
   int (*empty) ( TreeNode * );
   int (*size) ( TreeNode * );
   int (*height) ( TreeNode * );
   void (*sumaF) ( TreeNode * );
   int (*suma) ( TreeNode * );
   int (*checkFull) ( TreeNode * );
   int (*checkComplete) ( TreeNode * );
   void (*mirror) ( TreeNode * );
   void (*preorderName) ( TreeNode * );
   void (*inorderName) ( TreeNode * );
   void (*postorderName) ( TreeNode * );
   void (*levelorderName) ( TreeNode * );
};

   void makeTree( Tree * x, int e, Tree * l, Tree * r ){
   x->root = malloc( sizeof( TreeNode ) );
   x->root->item = e;
   x->root->left = l->root;
   x->root->right = r->root;
   l->root = r->root = NULL;
   return;
}

void preorder( TreeNode * p ){
    if( p ){
   printf( "%d ", p->item );
   preorder( p->left );
   preorder( p->right );
   }
}

void inorder( TreeNode * p ){
   if( p ){
      inorder( p->left );
      printf( "%d ", p->item );
      inorder( p->right );
   }
}

void postorder( TreeNode * p ){
   if( p ){
      postorder( p->left );
      postorder( p->right );
      printf( "%d ", p->item );
   }
}

void givenLevel( TreeNode * p, int level ){
   if( !p )
      return;
   if( level == 1 )
      printf( "%d ", p->item );
   else if( level > 1 ){
      givenLevel( p->left, level - 1 );
      givenLevel( p->right, level - 1 );
   }
}

int height( TreeNode * p ){
   int hl, hr;
   if( p ){
      hl = height( p->left );
      hr = height( p->right );
   if( hl > hr ) return ++hl;
   else return ++hr;
 }
   else
   return 0;
}

void levelorder( TreeNode * p ){
   int h = height( p );
   int i;

   for( i = 1; i <= h; i++)
   givenLevel( p, i );
}

int empty( TreeNode * p ){
   return p == NULL;
}

int size( TreeNode * p ){
   if( p )
   return 1 + size( p -> left ) + size( p -> right );
   else
   return 0;
}

void sumaF( TreeNode * p ){
   if( p ){
      s += p -> item;
      sumaF( p -> left );
      sumaF( p -> right );
   }
}

int suma( TreeNode * p ){
   s = 0;
   sumaF( p );
   return s;
}

int checkFull( TreeNode * p ){

   return size( p ) == pow( 2, height( p ) ) - 1;
}

int checkComplete( TreeNode * p ){
   if( p -> left == NULL && p -> right == NULL ){
   return 0;
}

   if( p -> left )
      checkComplete( p -> left );
   if( p -> right )
      checkComplete( p -> right );

   return 1;
}

void mirror( TreeNode * p ){
   int temporal;

   if( p -> left != NULL && p -> right != NULL ){
      temporal = p -> left -> item;
      p -> left -> item = p -> right -> item;
      p -> right -> item = temporal;
   }
   if( p -> left)
      mirror( p -> left );
   if( p -> right )
      mirror( p -> right );
}

Tree createTree( ){
   Tree t;

   t.root = NULL;
   t.makeTree = &makeTree;
   t.preorder = &preorder;
   t.inorder = &inorder;
   t.postorder = &postorder;
   t.levelorder = &levelorder;
   t.empty = &empty;
   t.size = &size;
   t.height = &height;
   t.sumaF = &sumaF;
   t.suma = &suma;
   t.checkFull = &checkFull;
   t.checkComplete = &checkComplete;
   t.mirror = &mirror;
   return t;
}
#endif