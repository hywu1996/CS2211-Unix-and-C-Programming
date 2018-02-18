//graph.c

/*
 * Name: Harry Wu
 * Student Number: 250797407
 * Date: 11/14/2017
 */

#include <stdio.h>

/*Print the vertices by going from 0 to N-1. These are the vertices we have in the array.*/
void printVertices(int N, int G[][N]) {
    printf("The graph has vertices: \n");

    int i;

    for(i = 0; i < N; i++){
		printf("Vertex %d \n", i);
    }
}


/*Print the edges of the graph by using an embedded for loop to search for edges (1) in the 2D array.*/
void printEdges(int N, int G[][N]) {
    printf("\nThe graph has edges: \n");

    int i, j;

    for(i = 0; i < N; i++){
            for(j = 0; j < N; j++){
                    if(G[i][j] == 1){
                            printf("[%d, %d] \n", i, j);
                    }
            }
    }

}

/*Check if there is a path between two vertices by searching the index with address of [v1][v2]. If there is a 1 at that location, a path exists.*/
void isThereAPath(int N, int G[][N], int v1, int v2) {
	if (v1>=N || v2>=N || v1<0 || v2<0) {
		printf("\nERROR: Invalid vertex\n");
	}
	else if(G[v1][v2] == 1) {
		printf("\nYes, there is a path between Vertex %d and Vertex %d.\n", v1, v2);
	}
	else {
		printf("\nNo, there is no path between Vertex %d and Vertex %d.\n", v1, v2);
	}
}

#define N 5

int main() {

	int Graph[N][N] = { 	{0,1,0,0,1},
							{1,0,0,0,1},
							{0,0,0,1,0},
							{0,0,1,0,0},
							{1,1,0,0,0}
					};

	printVertices(N, Graph);
	printEdges(N, Graph);
	isThereAPath(N, Graph, 0, 1);
	isThereAPath(N, Graph, 0, 3);

	return 0;

}
