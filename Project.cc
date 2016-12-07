#include <stdio.h>
#include <iostream>
#include <queue>
#include <vector>
#include <list>
#include <fstream>
#include <algorithm>
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
		int phaseThreeCornerEncoding(int);
		int phaseThreeEdgeEncoding();
		int phaseThreeEncoding();
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
}

int choose(int n,int k){
	if(k == 0){ return 1;}
	if(n == 0){ return 0;}
	return ((n * choose(n - 1, k - 1)) / k);
}

int cube::phaseTwoEncode(){
	int result = 0;
	int cornerEncode = 0;
	int e = 0;
	int eighthCorner=0;
	//corner encoding
	for(int i = 0; i < 7; i++){
		cornerEncode *= 3;
		cornerEncode += corner[1][i];
		eighthCorner += corner[1][i];
	}
	eighthCorner = eighthCorner % 3;
	// cout << "cornerEncode: " << cornerEncode << endl;

	//edge encoding;
	int edgeEncode = 0;
	vector<char> edgeIndex;
	for(int i = 0; i < 12; i++){
		switch(edge[0][i]){
			case 4:
				edgeIndex.push_back(i);
				break;
			case 5:
				edgeIndex.push_back(i);
				break;
			case 6:
				edgeIndex.push_back(i);
				break;
			case 7:
				edgeIndex.push_back(i);
				break;
			default:
				break;
		}
	}
	if(!edgeIndex.empty()){
		edgeEncode += choose(edgeIndex.back(),4);
		edgeIndex.pop_back();
		edgeEncode += choose(edgeIndex.back(),3);
		edgeIndex.pop_back();
		edgeEncode += choose(edgeIndex.back(),2);
		edgeIndex.pop_back();
		edgeEncode += choose(edgeIndex.back(),1);
		edgeIndex.pop_back();
	}else{cout << "wrong" << endl;}
	// cout << "edgeEncode: " << edgeEncode << endl;
	return cornerEncode * 495 + edgeEncode;
}

int listTwo[1082565][2]; //needed to be a global because of size

void generateListTwo(){
	//cannot use moves twistCW twistCCW slice antisliceCW antisliceCCW on red/orange
	cube c;
	cube current;
	c.resetCube();
	for(int i = 0; i < 1082565; i++){
		listTwo[i][0] = 33;
		listTwo[i][1] = 33;
	}
	int count = 0;
	int prevEncoding = 0;
	int encoding = 0;
	queue <cube> cubes;
	cubes.push(c); //the root cube
	while(!cubes.empty()){
		current = cubes.front();
		cubes.pop();
		for(int i = 0; i < 33; i++){
			if(i != 2 && i != 4 &&i != 8 && i != 10 && i != 20 && i != 22 && i != 29 && i != 32){
				prevEncoding = current.phaseTwoEncode();
				current.moveCaller(i);
				encoding = current.phaseTwoEncode();
				if(listTwo[encoding][0] == 33){
					cubes.push(current);
					listTwo[encoding][1] = prevEncoding;
					listTwo[encoding][0] = current.oppositeOf(i);
					count++;
					cout << "current encoded: " << count << endl;
				}
				current.moveCaller(current.oppositeOf(i));
			}
		}
		cubes.pop();
	}
	ofstream fout("phase2.txt"); 
	if(fout.is_open()){
		int y;
		for(y = 0; y < 1082565; y++){
			fout << "encode num: " << y << "     move to next:";
			fout << " " << listTwo[y][0];
			fout << " destination: " << listTwo[y][1];
			fout << endl;
		}
	}else{
		cout << "File could not be opened." << endl;
	}
}

int factorial(int n){
	if(n == 0){
		return 0;
	}
	if (n == 1){
		return 1;
	}else{
		return n * factorial(n-1);
	}
}

int cube::phaseThreeCornerEncoding(int i){
	if(i > 0){
		int num = 0;
		for(int j = i-1; j >= 0; j--){
			if(corner[0][i] < corner[0][j]){
				// cout << "corner[0][i]: " << corner[0][i] << "corner[0][j]: " << corner[0][j] << endl;
				num++;
			}
		}
		int x = num * factorial(num);
		// cout << "num: " << x << endl;
		return (x + phaseThreeCornerEncoding(i - 1));
	}else {return 0;}
}

int badEdge(int x){
	if(x == 0 || x ++ 2 || x == 9 || x == 11){

	}
}

int cube::phaseThreeEdgeEncoding(){
	int edgeEncode = 0;
	vector<char> edgeIndex;
	vector<int> whiteRed;
	vector<int> yellowGreen;
	int badEdges = 0;
	int x[4] = {-1,-1,-1,-1};
	//grab edges in positions 1,3,8,10
	x[0] = edge[0][1];
	x[1] = edge[0][3];
	x[2] = edge[0][8];
	x[3] = edge[0][10];
	for(int i = 0; i < 4; i++){
		if(x[i] == 0 || x[i] == 2 || x[i] == 9 || x[i] == 11){
			badEdges++;
			whiteRed.push_back(1);
		}else{ whiteRed.push_back(0); }
	}

	x[0] = edge[0][0];
	x[1] = edge[0][2];
	x[2] = edge[0][9];
	x[3] = edge[0][11];
	for(int i = 0; i < 4; i++){
		if(x[i] == 1 || x[i] == 3 || x[i] == 8 || x[i] == 10){
			yellowGreen.push_back(1);
		}else{ yellowGreen.push_back(0); }
	}
	if(badEdges == 4){
		return edgeEncode = 69;
	}else{
		for(int i = badEdges; i > 0; i--){
			edgeEncode += choose(edgeIndex.back(),i);
			edgeIndex.pop_back();
		}
	}
}

int cube::phaseThreeEncoding(){
	return this->phaseThreeEdgeEncoding() * this->phaseThreeCornerEncoding(7);
}

int main (){
	//generateListOne();
	//generateListTwo();

	cube b;
	b.resetCube();
	// b.moveCaller(4);
	cout << "Edge encoding: " << b.phaseThreeEdgeEncoding() << endl;
	cout << "Corner encoding: " << b.phaseThreeCornerEncoding(7) << endl;
	cout << "Phase 3 encoding: " << b.phaseThreeEncoding() << endl;
	return 0;
}
