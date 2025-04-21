#include "labo.h"
long long fibonacci(int n) {
	if (n <= 0) {
		return 0;
	}
	else if (n == 1) {
		return 1;
	}

	long long a = 0, b = 1, c;
	for (int i = 2; i <= n; i++) {
		c = a + b;
		a = b;
		b = c;
	}
	return b;
}

TreeNode* tree_create_node(void* data) {
	TreeNode* newNode = (TreeNode*)malloc(sizeof(TreeNode));
	if (newNode == NULL) {
		printf("Erreur d'allocation de mémoire\n");
		return NULL;
	}
	newNode->data = data;
	newNode->left = NULL;
	newNode->right = NULL;
	return newNode;
}

void tree_add_node(TreeNode* root, TreeNode* node) {
	if (root == NULL || node == NULL) {
		return;
	}
	if (root->left == NULL) {
		root->left = node;
	}
	else if (root->right == NULL) {
		root->right = node;
	}
}

int dfs(TreeNode* root, void* key) {
	if (root == NULL) {
		return 0;
	}
	Stack stack = stack_init(100);
	stack_push(&stack, root);
	while (stack.top != -1) {
		TreeNode* current = (TreeNode*)stack_pop(&stack);
		if (current->data == key) {
			return 1;
		}
		if (current->right != NULL) {
			stack_push(&stack, current->right);
		}
		if (current->left != NULL) {
			stack_push(&stack, current->left);
		}
	}

	return 0;
}

int bfs(TreeNode* root, void* key) {
	if (root == NULL) {
		return 0;
	}
	Queue queue;
	queue_init(&queue);
	queue_push(&queue, root);

	while (queue.count > 0) {
		TreeNode* current = (TreeNode*)queue_pop(&queue);

		if (current->data == key) {
			return 1;
		}
		if (current->left != NULL) {
			queue_push(&queue, current->left);
		}
		if (current->right != NULL) {
			queue_push(&queue, current->right);
		}
	}
	return 0;
}