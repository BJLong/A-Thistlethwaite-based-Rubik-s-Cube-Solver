#include stuff;

using namespace std;

void int main (){
	//edge orientation is either flipped [1] or not flipped [0]
	char edgesOrientation[] = [0,0,0,0,0,0,0,0,0,0,0,0];
	char edgePosition[] = [0,0,0,0,0,0,0,0,0,0,0,0];
	//corner orientation goes 0,1,2
	char cornerOrientation[] = [0,0,0,0,0,0,0,0];
	char cornerPosition[] = [0,0,0,0,0,0,0,0];

	//using multidimensional array 6 columns(faces) 8 rows(corners/edges)?
	char mArray[6][8];
	
}
/*
indexes start at top back left and go clockwise
face 0 would be corner index 2,3,6,7
	edge index 2,6,7,10
	it would look like the following:
		[2][2][3]
		[6][ ][7]
		[6][10][7]


	faces:
	0:white
	1:blue
	2:orange
	3:green
	4:red
	5:yellow
*/



void twistClockwise(char* array[],char face) {
	if face = 0 //top face
	temp = corner 2
	corner 2 = corner6
	corner 6 = corner 7
	corner 7 = corner 3
	corner 3 = temp
	temp = edge 2
	edge 2 = edge 6
	edge 6 = edge 10
	edge 10 = edge 7
	edge 7 = temp

	edge/corner orientation unaffected
	edges move

	if face = 2 or 4
	edges flip orientation
	
	
}
