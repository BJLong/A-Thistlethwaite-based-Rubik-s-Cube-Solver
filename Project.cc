//#include stuff;
using namespace std;

void int main (){
	//edge orientation is either flipped [1] or not flipped [0]
	char edge[12][2];
	//corner orientation goes 0,1,2
	char corner[8][2];
	//corner[0][0] is the corner in the first corner position
	//corner[0][1] is the orientation of first corner
	//the correct value for the fifth corner would be corner[4][0] == 4 and corner[4][1] == 0

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
