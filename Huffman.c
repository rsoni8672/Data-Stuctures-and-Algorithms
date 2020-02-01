#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct HuffmanNode {
	char data;
	int freq;
	struct HuffmanNode *next, *left, *right;
}huff;

typedef struct LinkedList {
	char data;
	int f;
	char *code;
	struct LinkedList *next;
}list;

list *finishedLetters = NULL;
huff *head = NULL;

list *getNode(char data, int f) {
	list *l = (list *) malloc(sizeof(list));
	l->data = data;
	l->f = f;
	l->next = NULL;
	l->code = NULL;
	return l;
}

void addToList(char data, int f) {
	if (!finishedLetters) finishedLetters = getNode(data, f);
	else {
    	list *node = getNode(data, f);
    	node->next = finishedLetters;
    	finishedLetters = node;
	}
}

int isPresent(char data) {
	if (!head) return 0;
	int flag = 0;
	for (huff *t = head; t; t = t->next) {
    	if (t->data == data) {
        	flag = 1;
        	break;
    	}
	}
	return flag;
}

void insertCode(char data, int *a, int size) {
	list *temp;
	for (temp = finishedLetters;data != temp->data; temp = temp->next);
	temp->code = malloc((size + 1) * sizeof(char));
	for (int i = 0; i < size; ++i) {
    	temp->code[i] = (char) (a[i] ? '1' : '0');
	}
	temp->code[size] = '\0';
}

void dispList() {
	for (list *t = finishedLetters; t; t = t->next) printf("'%c' - %d - %s\n", t->data, t->f, t->code);
}

huff *getPriorityQNode(char data, int rep) {
	huff *node = (huff *) malloc(sizeof(huff));
	node->data = data;
	node->freq = rep;
	node->next = node->left = node->right = NULL;
	return node;
}

void nQ(char data, int freq) {
	huff *node = getPriorityQNode(data, freq);
	if (!head) head = node;
	else if (freq <= head->freq) {
    	node->next = head;
    	head = node;
	} else {
    	huff *temp, *beforeTemp = head;
    	for (temp = head->next;temp && freq > temp->freq; temp = temp->next) beforeTemp = beforeTemp->next;
    	beforeTemp->next = node;
    	node->next = temp;
	}
}

void nQNode(huff *node) {
	if (!head) head = node;
	else if (node->freq <= head->freq) {
    	node->next = head;
    	head = node;
	} else {
    	huff *temp, *beforeTemp = head;
    	for (temp = head->next;temp && node->freq >= temp->freq; temp = temp->next) beforeTemp = beforeTemp->next;
    	beforeTemp->next = node;
    	node->next = temp;
	}
}

huff *dQ() {
	huff *data;
	if (!head) return NULL;
	else {
    	data = head;
    	head = head->next;
	}
	return data;
}


void dispQ() {
	for (huff *t = head; t; t = t->next) printf("(%c, %d) ", t->data, t->freq);
	printf("\n");
}

huff *getTreeNode(int freq) {
	huff *node = (huff *) malloc(sizeof(huff));
	node->data = '~';
	node->freq = freq;
	node->next = node->left = node->right = NULL;
	return node;
}

int getCountQ() {
	int count = 0;
	for (huff *t = head; t; t = t->next) count++;
	return count;
}

void dispTree(huff *root, int *a, int level) {
	if (root) {
    	if (root->left) {
        	a[level] = 0;
        	dispTree(root->left, a, level + 1);
    	}
    	if (root->right) {
        	a[level] = 1;
        	dispTree(root->right, a, level + 1);
    	}
    	if (!root->left && !root->right) {
        	insertCode(root->data, a, level);
    	}

	}
}

int getHeight(huff *root) {
	if (!root) return 0;
	int lh = getHeight(root->left);
	int rh = getHeight(root->right);
	return (lh > rh ? lh + 1 : rh + 1);
}

void makeTree() {
	if (!head || !head->next) return;
	while (getCountQ() > 1) {
    	huff *leftChild = dQ();
    	huff *rightChild = dQ();
    	huff *node = getTreeNode(leftChild->freq + rightChild->freq);
    	node->left = leftChild;
    	node->right = rightChild;
    	nQNode(node);
	}
}

void getFreq(char *line) {
	int count = 0;
	for (int i = 0; i < strlen(line); i++) {
    	count = 0;
    	if (!isPresent(line[i])) {
        	for (int j = i; j < strlen(line); j++) if (line[i] == line[j]) count++;
        	addToList(line[i], count);
        	nQ(line[i], count);
    	}
	}
}

int getNewByteCount() {
	int count = 0;
	for (list *t = finishedLetters; t; t = t->next) count += (strlen(t->code) * t->f);
	return count;
}

int main() {
	char *line = "SE Computer is very good class.";
	int lineLen = strlen(line);

	getFreq(line);

	makeTree();

	int a[getHeight(head) - 1];
	dispTree(head, a, 0);
	printf("Frequency of letters with their corresponding code :\n");
	printf("Given string : %s\n", line);
	dispList();
	double percent = ((lineLen * 8 - getNewByteCount() * 1.0) / (lineLen * 8)) * 100;
	printf("\nPercent saving : %.4lf\n", percent);
return 0;
}


