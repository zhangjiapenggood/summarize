#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef struct Node {
	int data;
	struct Node *next;
}ListNode;

ListNode* createList()
{
	printf("function _name %s\n", __FUNCTION__);
	ListNode *node = (ListNode *)malloc(sizeof(ListNode));
	assert(node);
	node->data = 0;
	node->next = NULL;
	return node;
}

int insertListNode(ListNode *node, int site, int value)
{
	printf("function _name %s\n", __FUNCTION__);
	if (!node) {
		return -1;
	}

	int i = 0;
	while (i < site && node->next) {
		node = node->next;
		i++;
	}
	if (i != site) {
		printf("Please check where the data is inserted\n"); //避免数据插入是出现指针异常
		return -1;
	}
	ListNode *tmpNode = (ListNode *)malloc(sizeof(ListNode));
	assert(tmpNode);
	tmpNode->data = value;
	tmpNode->next = node->next;
	node->next = tmpNode;
	return 0;
}

int deleteListNode(ListNode *node, int site)
{
	printf("function _name %s\n", __FUNCTION__);
	if (!node) {
		return -1;
	}

	int i = 0;
	while (i < site  && node->next) {
		node = node->next;
		i++;
	}
	ListNode *tmp = node->next;
	node->next = tmp->next;
	free(tmp);
	return 0;
}

int appendListNode(ListNode *node, int value)
{
	printf("function _name %s\n", __FUNCTION__);
	if (!node) {
		return -1;
	}

	while (node->next != NULL) {
		node = node->next;
	}
	ListNode *tmpNode1 = (ListNode *)malloc(sizeof(ListNode));
	assert(tmpNode1);
	tmpNode1->data = value;
	tmpNode1->next = NULL;
	node->next = tmpNode1;
	return 0;
}

int getListNodeValue(ListNode *node, int site)
{
	printf("function _name %s\n", __FUNCTION__);
	if (!node) {
		return -1;
	}

	int i = 0;
	while (i < site && node->next) {
		node = node->next;
		i++;
	}
	return node->data;
}

int main()
{
	ListNode *node = createList();
	appendListNode(node, 1);
	appendListNode(node, 2);
	insertListNode(node, 20, 3);
	insertListNode(node, 1, 3);
	appendListNode(node, 4);
	printf("getListNode1 = %d\n", getListNodeValue(node, 1));
	printf("getListNode2 = %d\n", getListNodeValue(node, 2));
	printf("getListNode3 = %d\n", getListNodeValue(node, 3));
	printf("getListNode4 = %d\n", getListNodeValue(node, 4));
	deleteListNode(node, 1);
	appendListNode(node, 5);
	printf("getListNode2 = %d\n", getListNodeValue(node, 2));
	return 0;
}
