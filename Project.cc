#include <stdio.h>
#include <iostream>

using namespace std;

void int main (){
	//edge orientation is either flipped [1] or not flipped [0]
	char edge[12][2];
	char solvedEdges[12][2] = {
		{0,1,2,3,4,5,6,7,8,9,10,11}
		{0,0,0,0,0,0,0,0,0,0,0,0}
	}
	//corner orientation goes 0,1,2
	char corner[8][2];
	char solvedCorners[8][2] = {
		{0,1,2,3,4,5,6,7}
		{0,0,0,0,0,0,0,0}
	}
	//corner[0][0] is the corner in the first corner position
	//corner[0][1] is the orientation of first corner
	//the correct value for the fifth corner would be corner[4][0] == 4 and corner[4][1] == 0

	colorOfCorners(solvedCorners);
}
/*
indexes start at top back left and go clockwise
face 0 would be corner index 2,3,6,7
	edge index 2,6,7,10
	it would look like the following:
		[2][2][3]
		[6][0][7]
		[6][10][7]

	faces:
	0:white
	1:blue
	2:orange
	3:green
	4:red
	5:yellow
*/

void twistClockwise(char* corners, char* edges,int face) {
	if(face == 0){
		char temp = corners[1][0];
		corner[1][0] = corner[5][0];
		corner[5][0] = corner[6][0];
		corner[6][0] = corner[2][0];
		corner[2][0] = temp;
		temp = edge[1][0];
		edge[1][0] = edge[5][0];
		edge[5][0] = edge[9][0];
		edge[9][0] = edge[6][0];
		edge[6][0] = temp;
	}

void colorOfCorners(char corners[][]){
	for(int i = 0; i < 7;i++){
		switch(corner[i][0]){
			case 0: 
				printf("Corner %d has colors white, green, orange\n", i);
				break;
			case 1: 
				printf("Corner %d has colors white, blue, orange\n", i);
				break;
			case 2: 
				printf("Corner %d has colors white, red, blue\n", i);
				break;
			case 3: 
				printf("Corner %d has colors white, red, green\n", i);
				break;
			case 4: 
				printf("Corner %d has colors yellow, green, orange\n", i);
				break;
			case 5: 
				printf("Corner %d has colors yellow, blue, orange\n", i);
				break;
			case 6: 
				printf("Corner %d has colors yellow, red, blue\n", i);
				break;
			case 7: 
				printf("Corner %d has colors yellow, red, green\n", i);
				break;
		}
	}
}

void colorOfEdge(char edges[][]){
	for(int i = 0; i < 11; i++){
		switch(edges[i][0]){
			case 0:
				printf("Edge %d has colors white, orange\n", i);
				break;
			case 1:
				printf("Edge %d has colors white, blue\n", i);
				break;
			case 2:
				printf("Edge %d has colors white, red\n", i);
				break;
			case 3:
				printf("Edge %d has colors white, green\n", i);
				break;
			case 4:
				printf("Edge %d has colors green, orange\n", i);
				break;
			case 5:
				printf("Edge %d has colors orange, blue\n", i);
				break;
			case 6:
				printf("Edge %d has colors blue, red\n", i);
				break;
			case 7:
				printf("Edge %d has colors red, green\n", i);
				break;
			case 8:
				printf("Edge %d has colors yellow, orange\n", i);
				break;
			case 9:
				printf("Edge %d has colors yellow, blue\n", i);
				break;
			case 10:
				printf("Edge %d has colors yellow, red\n", i);
				break;
			case 11:
				printf("Edge %d has colors yellow, green\n", i);
				break;

		}
	}

}
/*
	corners:
	0: white, green, orange
	1: white, blue, orange
	2: white, red, blue
	3: white, red, green
	4: yellow, green, orange
	5: yellow, blue, orange
	6: yellow, red, blue
	7: yellow, red, green

	edges:
	0: white, orange
	1: white, blue
	2: white, red
	3: white, green
	4: green, orange
	5: orange, blue
	6: blue, red
	7: red, green
	8: yellow, orange
	9: yellow, blue
	10: yellow, red
	11: yellow, green

*/

/*
	-----pseudo stuff-----
	if face = 0 //top face
	temp = corner 2
	corner 2 = corner 6
	corner 6 = corner 7
	corner 7 = corner 3
	corner 3 = temp
	temp     = edge 2
	edge 2   = edge 6
	edge 6   = edge 10
	edge 10  = edge 7
	edge 7   = temp

	edge/corner orientation unaffected
	edges move

	if face = 2 or 4
	edges flip orientation
*/
	
}
