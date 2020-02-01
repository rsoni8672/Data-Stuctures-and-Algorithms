#include <stdio.h>
#include <stdlib.h>

#define MAX 4
#define MIN 2

typedef struct node {
int val[MAX + 1], count;
struct node *link[MAX + 1];
}node;

node *root;
node * createNode(int , node *);
void addValToNode(int, int, node *, node *);
void splitNode (int, int *, int , node *,node *, node **);
int setValueInNode(int, int *,node *, node **);
void insertion(int val);
void traversal(node *);

void main() {
int val, ch;
while (1) {
printf("1. Insertion\t2. Traversal\n");
printf("3. Exit\nEnter your choice:");
scanf("%d", &ch);

switch (ch) {

case 1:
printf("Enter your input:");
scanf("%d", &val);
insertion(val);
break;

case 2:
traversal(root);
break;

case 3:
exit(0);

default:
printf("Invalid option!!\n");
break;
}
printf("\n");
}
}

node * createNode(int val, node *child) {
node *newNode;
newNode = (node *)malloc(sizeof(node));
newNode->val[1] = val;
newNode->count = 1;
newNode->link[0] = root;
newNode->link[1] = child;
return newNode;
}

void splitNode (int val, int *pval, int pos, node *head,node *child, node **newNode) {
int median, j;

if (pos > MIN)
median = MIN + 1;
else
median = MIN;

*newNode = (node *)malloc(sizeof(node));
j = median + 1;
while (j <= MAX) {
(*newNode)->val[j - median] = head->val[j];
(*newNode)->link[j - median] = head->link[j];
j++;
}
head->count = median;
(*newNode)->count = MAX - median;

if (pos <= MIN) {
addValToNode(val, pos, head, child);
} else {
addValToNode(val, pos - median, *newNode, child);
}
*pval = head->val[head->count];
(*newNode)->link[0] = head->link[head->count];
head->count--;
}


void insertion(int val) {
int flag, i;
node *child;

flag = setValueInNode(val, &i, root, &child);
if (flag)
root = createNode(i, child);
}


int setValueInNode(int val, int *pval,node *head, node **child) {

int pos;
if (!head) {
*pval = val;
*child = NULL;
return 1;
}

if (val < head->val[1]) {
pos = 0;
} else {
for (pos = head->count;
(val < head->val[pos] && pos > 1); pos--);
if (val == head->val[pos]) {
printf("Duplicates not allowed\n");
return 0;
}
}
if (setValueInNode(val, pval, head->link[pos], child)) {
if (head->count < MAX) {
addValToNode(*pval, pos, head, *child);
} else {
splitNode(*pval, pval, pos, head, *child, child);
return 1;
}
}
return 0;
}

void addValToNode(int val, int pos, node *head,node *child) {
int j = head->count;
while (j > pos) {
head->val[j + 1] = head->val[j];
head->link[j + 1] = head->link[j];
j--;
}
head->val[j + 1] = val;
head->link[j + 1] = child;
head->count++;
}


void traversal(node *myNode) {
int i;
if (myNode) {
for (i = 0; i < myNode->count; i++) {
traversal(myNode->link[i]);
printf("%d ", myNode->val[i + 1]);
}
traversal(myNode->link[i]);
}
}
