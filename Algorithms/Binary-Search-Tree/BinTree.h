#ifndef ___BinTree
#define ___BinTree

#include "Member.h"

typedef struct __bnode {
  Member data;
  struct __bnode *left;
  struct __bnode *right;
} BinNode;

/* 검색 */
BinNode *Search(BinNode *p, const Member *x);

/* 노드 삽입 */
BinNode *Add(BinNode *p, const Member *x);

/* 노드 삭제 */
int Remove(BinNode **root, const Member *x);

/* 모든 노드를 출력 */
void PrintTree(const BinNode *p);

/* 모든 노드를 삭제 */
void FreeTree(BinNode *p);

#endif
