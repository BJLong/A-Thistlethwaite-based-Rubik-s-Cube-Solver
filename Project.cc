#include <stdio.h>
#include <iostream>
#include <queue>
#include <vector>
#include <list>
#include <fstream>
using namespace std;

class cube {
	private:
		static const char edgeMoves[6][4];
		static const char cornerMoves[6][4];
		char edge[2][12];;
		char corner[2][8];
	public:
		void twistClockwise(int);
		void twistCounterClockwise(int);
		void halfTwist(int);
		void slice(int);
		void halfSlice(int);
		void antiSlice(int);
		void antiSliceCounterClockwise(int);
		int phaseOneEncode();
		void resetCube();
		void moveCaller(int);
		int oppositeOf(int);
		int phaseTwoEncode();
};

const char cube::edgeMoves[6][4] = {
	{0,1,2,3},
	{0,4,11,5},
	{1,5,10,6},
	{2,6,9,7},
	{3,7,8,0},
	{8,9,10,11}
};
const char cube::cornerMoves[6][4] = {
	{0,1,2,3},		//white
	{1,0,7,6},		//blue
	{2,1,6,5},		//red
	{3,2,5,4},		//green
	{0,3,4,7},		//orange
	{4,5,6,7}		//yellow
};

void cube::twistClockwise(int face) {
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

void cube::twistCounterClockwise(int face) {
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

void cube::halfTwist(int face) {
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

void cube::slice(int face) {
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

void cube::halfSlice(int face) {
	halfTwist(face);
	switch(face){
		case 0:
			halfTwist(5);
			break;
		case 1:
			halfTwist(3);
			break;
		case 2:
			halfTwist(4);
			break;
		case 3:
			halfTwist(1);
			break;
		case 4:
			halfTwist(2);
			break;
		case 5:
			halfTwist(0);
			break;
	}
}

void cube::antiSlice(int face) {
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

void cube::antiSliceCounterClockwise(int face) {
	twistCounterClockwise(face);
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

int cube::phaseOneEncode(){
	int result = 0;
	for(int i = 0; i < 11; i++){
		result = result << 1;
		if(edge[1][i] == 1){
			result++;
		}
	}
	return result;
}

void cube::resetCube(){
	for(int j = 0; j < 8; j++){
		corner[0][j] = j;
		corner[1][j] = 0;
	}
	for(int i = 0; i < 12; i++){
		edge[0][i] = i;
		edge[1][i] = 0;
	}
}

void cube::moveCaller(int num){
	int white = 0;
	int blue = 1;
	int red = 2;
	int green = 3;
	int orange = 4;
	int yellow = 5;

	switch(num){
		case 0:
			twistClockwise(white);
			break;
		case 1:
			twistClockwise(blue);
			break;
		case 2:
			twistClockwise(red);
			break;
		case 3:
			twistClockwise(green);
			break;
		case 4:
			twistClockwise(orange);
			break;
		case 5:
			twistClockwise(yellow);
			break;
		case 6:
			twistCounterClockwise(white);
			break;
		case 7:
			twistCounterClockwise(blue);
			break;
		case 8:
			twistCounterClockwise(red);
			break;
		case 9:
			twistCounterClockwise(green);
			break;
		case 10:
			twistCounterClockwise(orange);
			break;
		case 11:
			twistCounterClockwise(yellow);
			break;
		case 12:
			halfTwist(white);
			break;
		case 13:
			halfTwist(blue);
			break;
		case 14:
			halfTwist(red);
			break;
		case 15:
			halfTwist(green);
			break;
		case 16:
			halfTwist(orange);
			break;
		case 17:
			halfTwist(yellow);
			break;
		case 18:
			slice(white);
			break;
		case 19:
			slice(blue);
			break;
		case 20:
			slice(red);
			break;
		case 21:
			slice(green);
			break;
		case 22:
			slice(orange);
			break;
		case 23:
			slice(yellow);
			break;
		case 24:
			halfSlice(white);
			break;
		case 25:
			halfSlice(blue);
			break;
		case 26:
			halfSlice(red);
			break;
		case 27:
			antiSlice(white);
			break;
		case 28:
			antiSlice(blue);
			break;
		case 29:
			antiSlice(red);
			break;
		case 30:
			antiSliceCounterClockwise(white);
			break;
		case 31:
			antiSliceCounterClockwise(blue);
			break;
		case 32:
			antiSliceCounterClockwise(red);
			break;
	}
}

int cube::oppositeOf(int num){
	int white = 0;
	int blue = 1;
	int red = 2;
	int green = 3;
	int orange = 4;
	int yellow = 5;

	switch(num){
		case 0:
			return 6;
		case 1:
			return 7;
		case 2:
			return 8;
		case 3:
			return 9;
		case 4:
			return 10;
		case 5:
			return 11;
		case 6:
			return 0;
		case 7:
			return 1;
		case 8:
			return 2;
		case 9:
			return 3;
		case 10:
			return 4;
		case 11:
			return 5;
		case 12:
			return 12;
		case 13:
			return 13;
		case 14:
			return 14;
		case 15:
			return 15;
		case 16:
			return 16;
		case 17:
			return 17;
		case 18:
			return 23;
		case 19:
			return 21;
		case 20:
			return 22;
		case 21:
			return 19;
		case 22:
			return 20;
		case 23:
			return 18;
		case 24:
			return 24;
		case 25:
			return 25;
		case 26:
			return 26;
		case 27:
			return 30;
		case 28:
			return 31;
		case 29:
			return 32;
		case 30:
			return 27;
		case 31:
			return 28;
		case 32:
			return 29;
	}
}
/*
void generateList(){
	int list[2048][7];
	for(int i = 0; i < 2048;i++){
		for (int j = 0; j < 7; j++)
		{
			list[i][j] = 33;
		}
	}
	int count = 0;
	for(int a = 0; a < 33; a++){
		moveCaller(a);
		for (int b = 0; b < 33; b++){
			moveCaller(b);
			for (int c = 0; c < 33; c++){
				moveCaller(c);
				for (int d = 0; d < 33; d++){
					moveCaller(d);
					for (int e = 0; e < 33; e++){
						moveCaller(e);
						for (int f = 0; f < 33; f++){
							moveCaller(f);
							for (int g = 0; g < 33; g++){
								moveCaller(g);
								int next = phaseOneEncode(edge);
								if(list[next][0] == 33){
									list[next][0] = a;
									list[next][1] = b;
									list[next][2] = c;
									list[next][3] = d;
									list[next][4] = e;
									list[next][5] = f;
									list[next][6] = g;
									//cout << next << " " << a << " " << b << " " << c << " " << d << " " << e << " " << e << " " << f << " " << g << endl;
									cout << "current num: " << count << endl;
									count++;
								}
								oppositeOf(g);
								
							}
							oppositeOf(f);
						}
						oppositeOf(e);
					}
					oppositeOf(d);
				}
				oppositeOf(c);
			}
			oppositeOf(b);
		}
		oppositeOf(a);
	}
	for (int i = 0; i < 2048; i++){
		for (int j = 0; j < 7; j++){
			cout << list[i][j] << " ";
		}
		cout << endl;
	}
}
*/
void generateListOne(){
	cube c;
	cube current;
	c.resetCube();
	int list[2048][2];
	for(int i = 0; i < 2048;i++){
		list[i][0] = 33;
		list[i][1] = 33;
	}
	int count = 0;
	int prevEncoding = 0;
	int encoding = 0;
	queue <cube> cubes;
	cubes.push(c); //the root cube
	//while(count < 2048){
	while(!cubes.empty()){
		current = cubes.front();
		cubes.pop();
		for(int i = 0; i < 33; i++){
			prevEncoding = current.phaseOneEncode();
			current.moveCaller(i);
			encoding = current.phaseOneEncode();
			if(list[encoding][0] == 33){
				cubes.push(current);
				list[encoding][1] = prevEncoding;
				list[encoding][0] = current.oppositeOf(i);
				count++;
				cout << "current encoded: " << count << endl;
			}
			current.moveCaller(current.oppositeOf(i));
		}
		cubes.pop();
	}
	ofstream fout("test.txt"); 
	if(fout.is_open()){
		int y;
		for(y = 0; y < 2048; y++){
			fout << "encode num: " << y << "     move to next:";
			fout << " " << list[y][0];
			fout << " destination: " << list[y][1];
			fout << endl;
		}
	}else{
		cout << "File could not be opened." << endl;
	}
}

int cube::phaseTwoEncode(){
	int result = 0;
	int c = 0;
	int e = 0;
	int eighthCorner=0;
	//corner encoding
	for(int i = 0; i < 7; i++){
		c *= 3;
		c += corner[1][i];
		eighthCorner += corner[1][i];
	}
	eighthCorner = eighthCorner % 3;

	//edge encoding;
	
	return result;
}

void generateListTwo(){

}

int main (){
	//edge orientation is either flipped [1] or not flipped [0]
	//char edge[2][12];
	//corner orientation goes 0,1,2
	//char corner[2][8];
	//corner[0][0] is the corner in the first corner position
	//corner[0][1] is the orientation of first corner
	//the correct value for the fifth corner would be corner[0][4] == 4 and corner[4][1] == 0

	generateListOne();
	


	return 0;
}


/*
	faces:
	0:white
	1:blue
	2:red
	3:green
	4:orange
	5:yellow

	moves:
	0:white cw
	1:blue cw
	2:red cw
	3:green cw
	4:orange cw
	5:yellow cw
	6:white ccw
	7:blue ccw
	8:red ccw
	9:green ccw
	10:orange ccw
	11:yellow ccw
	12:white half
	13:blue half
	14:red half
	15:green half
	16:orange half
	17:yellow half
	18:white slice
	19:blue slice
	20:red slice
	21:green slice
	22:orange slice
	23:yellow slice
	24:white/yellow halfslice
	25:blue/green halfslice
	26:red/orange halfslice
	27:white/yellow antislice
	28:blue/green antislice
	29:red/orange antislice
	30:white/yellow antislice ccw
	31:blue/green antislice ccw
	32:red/orange antislice ccw
*/
