//tree.c

/*
 * Name: Harry Wu
 * Student Number: 250797407
 * Date: 11/14/2017
 */

#include <stdio.h>

// INPUT: 	'bt', a binary tree.
// 			'node', a node in the tree.
// OUTPUT: 	the index of given value in the tree.
int getIndex(int *bt, int node){
/* Search the array for the node using linear search starting from element 1. Return it's index when found or -1 if it's not in the tree.*/
	int len=bt[0], counter=1;
	for (; counter <= len; counter++) {
		if (bt[counter]==node) {
			return counter;
		}
	}
	return -1;
}

// INPUT: 	'bt', a binary tree.
// 			'node ', a node in the tree.
// OUPUT: 	print the parent node of 'node'.
void printParentNode (int *bt, int node){
/*Print the parent node of a given node.*/
	int index = getIndex(bt,node);

	if (index>bt[0] || index<0) {
		printf("ERROR: Invalid node index value.\n\n");
	}

	else if (index==1) {
	/*First check if the node is the parent.*/
		printf("Node %d is the root and has no parent.\n\n", node);
	}
	else if (index%2==0) {
	/*If the index is even, then we divide it by two to find the parent index.*/
		printf("The parent of %d is %d\n\n", node, bt[index/2]);
	}
	else {
	/*If the index is odd, then we subtract one and divide by two to find the parent index.*/
		printf("The parent of %d is %d\n\n", node,bt[(index-1)/2]);
	}
}

// INPUT: 	'bt', a binary tree
// 			'node', a node in the tree.
// OUPUT: 	print the left child of 'node'.
void printLeftChildNode (int *bt, int node){
/*Find the left child by multiplying the current index by two.*/
	int index = getIndex(bt, node);

	if (index<0) {
		printf("ERROR: Invalid node index value.\n\n");
		return;
	}

	index *= 2;

	if (index > bt[0]) {
	/*Check if this index is still within the bounds of the array. If not, there is no child.*/
		printf("Node %d has no left child.\n\n", node);
	}
	else {
		printf("The left child node of %d is %d.\n\n", node, bt[index]);
	}
}

// INPUT: 	'bt', a binary tree
// 			'node', a node in the tree.
// OUPUT: 	print the right child of 'node'
void printRightChildNode (int *bt, int node){
/*Find the right child by multiplying the current index by two and adding one.*/
	int index = getIndex(bt, node);

	if (index<0) {
		printf("ERROR: Invalid node index value.\n\n");
		return;
	}

	index = (index*2) + 1;
	if (index > bt[0]) {
	/*Check if this index is still within the bounds of the array. If not, there is no child.*/
		printf("Node %d has no right child.\n\n", node);
	}
	else {
		printf("The right child node of %d is %d.\n\n", node, bt[index]);
	}
}

// INPUT: 	'bt', a binary tree
// 			'node1', a node in the tree.
// 			'node2', a node in the tree.
// OUPUT: 	print the nearest ancestor of 'node1' and 'node2'.
void printNearestCommonAncestor(int *bt, int node1, int node2){
/*Obtain the current index for the two nodes. First check if the two nodes are equal.
An embedded for loop will take node1 and it's ancestors and compare each of those to node2 and it's ancestors until a match is found.*/
	int index1=getIndex(bt, node1), index2=getIndex(bt, node2);

	if (index1>bt[0] || index1<0 || index2>bt[0] || index2<0 ) {
		printf("ERROR: Invalid node index value.\n\n");
	}

	else if (node1==node2) {
		printf("The two nodes are the same. Common ancestor is %d.\n\n", node1);
	}

	else {
		int val1, val2;
		while (index1>=1) {
			val1=bt[index1];

			while (index2>=1) {
				val2=bt[index2];
				if (val1==val2) {
					printf("The nearest common ancestor of Node %d and Node %d is Node %d.\n\n", node1, node2, val1);
					index1=0;
					index2=0;
				}
				else {
					if (index2%2==0) {
						index2 = index2/2;
					}
					else {
						index2 = (index2-1)/2;
					}
				}
			}

			index2=getIndex(bt, node2);

			if (index1%2==0) {
				index1 = index1/2;
			}
			else {
				index1 = (index1-1)/2;
			}
		}

	}

}


/* binaryTree is an array to encode a binary tree.
The first element of this array is used to encode the number of nodes. */

int main() {

	int binaryTree[11] = {10, 16, 14, 10, 8, 7, 9, 3, 2, 4, 1};

	printParentNode(binaryTree, 16);
	printParentNode(binaryTree, 3);

	printLeftChildNode(binaryTree, 7);
	printLeftChildNode(binaryTree, 9);

	printRightChildNode(binaryTree, 7);
	printRightChildNode(binaryTree, 10);

	printNearestCommonAncestor(binaryTree, 8, 1);
	printNearestCommonAncestor(binaryTree, 8, 9);

	return 0;
}
