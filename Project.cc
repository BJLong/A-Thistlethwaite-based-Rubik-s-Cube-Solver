#include <stdio.h>
#include <iostream>

using namespace std;


void twistClockwise(int face) {
	//arrays by moves, clockwise
	char edgeMoves[6][4] = {
		{0,1,2,3},
		{0,2,11,5},
		{2,1,6,5},
		{3,2,5,4},
		{0,3,4,7},
		{4,5,6,7}
	};
	char cornerMoves[6][4] = {
		{0,1,2,3},
		{1,0,7,6},
		{1,5,10,6},
		{2,6,9,7},
		{3,7,8,2},
		{9,10,6,8}
	};
	//twist corrosponding edges clockwise
	char temp = edgeMoves[face][0];
	edge[0][edgeMoves[face][0]] = edge[0][edgeMoves[face][1]];
	edge[0][edgeMoves[face][1]] = edge[0][edgeMoves[face][2]];
	edge[0][edgeMoves[face][2]] = edge[0][edgeMoves[face][3]];
	edge[0][edgeMoves[face][3]] = temp;
	//twist corrosponding corners clockwise
	temp = cornerMoves[face][0];
	corner[0][cornerMoves[face][0]] = corner[0][cornerMoves[face][1]];
	corner[0][cornerMoves[face][1]] = corner[0][cornerMoves[face][2]];
	corner[0][cornerMoves[face][2]] = corner[0][cornerMoves[face][3]];
	corner[0][cornerMoves[face][3]] = temp;
}

void colorOfCorners(char corners[2][8]){
	for(int i = 0; i < 8;i++){
		switch(corners[0][i]){
			case '0': 
				printf("Corner %d has colors white, green, orange\n", i);
				break;
			case '1': 
				printf("Corner %d has colors white, blue, orange\n", i);
				break;
			case '2': 
				printf("Corner %d has colors white, red, blue\n", i);
				break;
			case '3': 
				printf("Corner %d has colors white, red, green\n", i); 
				break;
			case '4': 
				printf("Corner %d has colors yellow, green, orange\n", i);
				break;
			case '5': 
				printf("Corner %d has colors yellow, blue, orange\n", i);
				break;
			case '6': 
				printf("Corner %d has colors yellow, red, blue\n", i);
				break;
			case '7': 
				printf("Corner %d has colors yellow, red, green\n", i);
				break;
		}
	}
}

void colorOfEdges(char edges[2][12]){
	for(int i = 0; i < 12; i++){
		switch(edges[0][i]){
			case '0':
				printf("Edge %d has colors white, orange\n", i);
				break;
			case '1':
				printf("Edge %d has colors white, blue\n", i);
				break;
			case '2':
				printf("Edge %d has colors white, red\n", i);
				break;
			case '3':
				printf("Edge %d has colors white, green\n", i);
				break;
			case '4':
				printf("Edge %d has colors green, orange\n", i);
				break;
			case '5':
				printf("Edge %d has colors orange, blue\n", i);
				break;
			case '6':
				printf("Edge %d has colors blue, red\n", i);
				break;
			case '7':
				printf("Edge %d has colors red, green\n", i);
				break;
			case '8':
				printf("Edge %d has colors yellow, orange\n", i);
				break;
			case '9':
				printf("Edge %d has colors yellow, blue\n", i);
				break;
			case '10':
				printf("Edge %d has colors yellow, red\n", i);
				break;
			case '11':
				printf("Edge %d has colors yellow, green\n", i);
				break;

		}
	}

}

	
int main (){
	//edge orientation is either flipped [1] or not flipped [0]
	char edge[2][12];
	//corner orientation goes 0,1,2
	char corner[2][8];
	//corner[0][0] is the corner in the first corner position
	//corner[0][1] is the orientation of first corner
	//the correct value for the fifth corner would be corner[4][0] == 4 and corner[4][1] == 0
}


/*
	faces:
	0:white
	1:blue
	2:orange
	3:green
	4:red
	5:yellow
*/
