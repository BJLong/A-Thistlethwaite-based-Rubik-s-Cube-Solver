#include <stdio.h>
#include <iostream>
#include <math.h>

using namespace std;

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
	{0,1,2,3},		//white
	{1,0,7,6},		//blue
	{2,1,6,5},		//red
	{3,2,5,4},		//green
	{0,3,4,7},		//orange
	{4,5,6,7}		//yellow
};

void twistClockwise(int face) {
	//twist corrosponding edges clockwise
	char temp = edge[0][edgeMoves[face][0]];
	edge[0][edgeMoves[face][0]] = edge[0][edgeMoves[face][3]];
	edge[0][edgeMoves[face][3]] = edge[0][edgeMoves[face][2]];
	edge[0][edgeMoves[face][2]] = edge[0][edgeMoves[face][1]];
	edge[0][edgeMoves[face][1]] = temp;

	//twist corrosponding corners clockwise
	temp = corner[0][cornerMoves[face][0]];
	corner[0][cornerMoves[face][0]] = corner[0][cornerMoves[face][3]];
	corner[0][cornerMoves[face][3]] = corner[0][cornerMoves[face][2]];
	corner[0][cornerMoves[face][2]] = corner[0][cornerMoves[face][1]];
	corner[0][cornerMoves[face][1]] = temp;

	//edge orientation
	if(face == 2 || face == 4){
		edge[1][edgeMoves[face][0]] = (edge[1][edgeMoves[face][0]] + 1) % 2;
		edge[1][edgeMoves[face][1]] = (edge[1][edgeMoves[face][1]] + 1) % 2;
		edge[1][edgeMoves[face][2]] = (edge[1][edgeMoves[face][2]] + 1) % 2;
		edge[1][edgeMoves[face][3]] = (edge[1][edgeMoves[face][3]] + 1) % 2;
	}

	//corner orientation
	if(face != 0 && face != 5){
		corner[1][cornerMoves[face][0]] = (corner[1][cornerMoves[face][0]] + 2) % 3;
		corner[1][cornerMoves[face][1]] = (corner[1][cornerMoves[face][1]] + 1) % 3;
		corner[1][cornerMoves[face][2]] = (corner[1][cornerMoves[face][2]] + 2) % 3;
		corner[1][cornerMoves[face][3]] = (corner[1][cornerMoves[face][3]] + 1) % 3;
	}

	//move orientations
	temp = edge[1][edgeMoves[face][0]];
	edge[1][edgeMoves[face][0]] = edge[1][edgeMoves[face][3]];
	edge[1][edgeMoves[face][3]] = edge[1][edgeMoves[face][2]];
	edge[1][edgeMoves[face][2]] = edge[1][edgeMoves[face][1]];
	edge[1][edgeMoves[face][1]] = temp;

	//twist corrosponding corners clockwise
	temp = corner[1][cornerMoves[face][0]];
	corner[1][cornerMoves[face][0]] = corner[1][cornerMoves[face][3]];
	corner[1][cornerMoves[face][3]] = corner[1][cornerMoves[face][2]];
	corner[1][cornerMoves[face][2]] = corner[1][cornerMoves[face][1]];
	corner[1][cornerMoves[face][1]] = temp;

}

void twistCounterClockwise(int face) {
	//twist corrosponding edges clockwise
	char temp = edge[0][edgeMoves[face][0]];
	edge[0][edgeMoves[face][0]] = edge[0][edgeMoves[face][1]];
	edge[0][edgeMoves[face][1]] = edge[0][edgeMoves[face][2]];
	edge[0][edgeMoves[face][2]] = edge[0][edgeMoves[face][3]];
	edge[0][edgeMoves[face][3]] = temp;
	//twist corrosponding corners clockwise
	temp = corner[0][cornerMoves[face][0]];
	corner[0][cornerMoves[face][0]] = corner[0][cornerMoves[face][1]];
	corner[0][cornerMoves[face][1]] = corner[0][cornerMoves[face][2]];
	corner[0][cornerMoves[face][2]] = corner[0][cornerMoves[face][3]];
	corner[0][cornerMoves[face][3]] = temp;

	//edge orientation
	if(face == 2 || face == 4){
		edge[1][edgeMoves[face][0]] = (edge[1][edgeMoves[face][0]] + 1) % 2;
		edge[1][edgeMoves[face][1]] = (edge[1][edgeMoves[face][1]] + 1) % 2;
		edge[1][edgeMoves[face][2]] = (edge[1][edgeMoves[face][2]] + 1) % 2;
		edge[1][edgeMoves[face][3]] = (edge[1][edgeMoves[face][3]] + 1) % 2;
	}

	//corner orientation
	if(face != 0 && face != 5){
		corner[1][cornerMoves[face][0]] = (corner[1][cornerMoves[face][0]] + 1) % 3;
		corner[1][cornerMoves[face][1]] = (corner[1][cornerMoves[face][1]] + 2) % 3;
		corner[1][cornerMoves[face][2]] = (corner[1][cornerMoves[face][2]] + 1) % 3;
		corner[1][cornerMoves[face][3]] = (corner[1][cornerMoves[face][3]] + 2) % 3;
	}

	//move orientations
	temp = edge[1][edgeMoves[face][0]];
	edge[1][edgeMoves[face][0]] = edge[1][edgeMoves[face][1]];
	edge[1][edgeMoves[face][1]] = edge[1][edgeMoves[face][2]];
	edge[1][edgeMoves[face][2]] = edge[1][edgeMoves[face][3]];
	edge[1][edgeMoves[face][3]] = temp;
	//twist corrosponding corners clockwise
	temp = corner[1][cornerMoves[face][0]];
	corner[1][cornerMoves[face][0]] = corner[1][cornerMoves[face][1]];
	corner[1][cornerMoves[face][1]] = corner[1][cornerMoves[face][2]];
	corner[1][cornerMoves[face][2]] = corner[1][cornerMoves[face][3]];
	corner[1][cornerMoves[face][3]] = temp;
}

void halfTwist(int face) {
	char temp = edge[0][edgeMoves[face][0]];
	edge[0][edgeMoves[face][0]] = edge[0][edgeMoves[face][2]];
	edge[0][edgeMoves[face][2]] = temp;
	temp = edge[0][edgeMoves[face][1]];
	edge[0][edgeMoves[face][1]] = edge[0][edgeMoves[face][3]];
	edge[0][edgeMoves[face][3]] = temp;

	temp = corner[0][cornerMoves[face][0]];
	corner[0][cornerMoves[face][0]] = corner[0][cornerMoves[face][2]];
	corner[0][cornerMoves[face][2]] = temp;
	temp = corner[0][cornerMoves[face][1]];
	corner[0][cornerMoves[face][1]] = corner[0][cornerMoves[face][3]];
	corner[0][cornerMoves[face][3]] = temp;
	//moving orientations
	temp = edge[1][edgeMoves[face][0]];
	edge[1][edgeMoves[face][0]] = edge[1][edgeMoves[face][2]];
	edge[1][edgeMoves[face][2]] = temp;
	temp = edge[1][edgeMoves[face][1]];
	edge[1][edgeMoves[face][1]] = edge[1][edgeMoves[face][3]];
	edge[1][edgeMoves[face][3]] = temp;

	temp = corner[1][cornerMoves[face][0]];
	corner[1][cornerMoves[face][0]] = corner[1][cornerMoves[face][2]];
	corner[1][cornerMoves[face][2]] = temp;
	temp = corner[1][cornerMoves[face][1]];
	corner[1][cornerMoves[face][1]] = corner[1][cornerMoves[face][3]];
	corner[1][cornerMoves[face][3]] = temp;
}

void slice(int face) {
	twistClockwise(face);
	switch(face){
		case 0:
			twistCounterClockwise(5);
			break;
		case 1:
			twistCounterClockwise(3);
			break;
		case 2:
			twistCounterClockwise(4);
			break;
		case 3:
			twistCounterClockwise(1);
			break;
		case 4:
			twistCounterClockwise(2);
			break;
		case 5:
			twistCounterClockwise(0);
			break;
	}
}

void antiSlice(int face) {
	twistClockwise(face);
	switch(face){
		case 0:
			twistClockwise(5);
			break;
		case 1:
			twistClockwise(3);
			break;
		case 2:
			twistClockwise(4);
			break;
		case 3:
			twistClockwise(1);
			break;
		case 4:
			twistClockwise(2);
			break;
		case 5:
			twistClockwise(0);
			break;
	}
}

void phaseOneEncode(char edges[][]){
	int phaseOne = 0;
	for(int i = 0; i < 11; i++){
		phaseOne += edges[1][i] * pow(2,i);
	}
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
	2:red
	3:green
	4:orange
	5:yellow
*/
