#include <iostream>
#include <fstream>
#include <sys/stat.h> 
#include <fcntl.h>
#include <unistd.h>
#include <string>
#include <vector>
#include "cube.h"
using namespace std;

char facelet[54] = {
	2,3,4,2,2,3,5,1,4,
	3,2,2,2,1,0,1,5,2,
	3,3,3,2,4,4,0,4,1,
	4,0,3,3,3,1,5,1,4,
	5,5,0,0,0,5,5,4,0,
	2,0,1,5,5,4,1,1,0
};

vector<char> moves;
int lOne[2048][2];
int lTwo[1082565][2];
int lThree[2822400][2];
int lFour[663552][2];

void readLists(){
	// vector <int> y;
	// int x;
	// ifstream pread;
	// pread.open("Phase1.txt");
	// while(pread >> x){
	// 	y.push_back(x);
	// }
	// // y.pop_back();
	// for (int i = 2047; i >= 0; i--)
	// {
	// 	lOne[i][1] = y.back();
	// 	y.pop_back();
	// 	lOne[i][0] = y.back();
	// 	y.pop_back();
	// }
	int pread = open("Phase1.txt", O_RDONLY);
	if(pread != -1){
		read(pread, lOne, 2048*2*sizeof(int));
	}
	close(pread);

	pread = open("Phase2.txt", O_RDONLY);
	if(pread != -1){
	 	read(pread, lTwo, 1082565*2*sizeof(int));
	 }
	 close(pread);

	 pread = open("Phase3.txt", O_RDONLY);
	 if(pread != -1){
	 	read(pread, *lThree, 2822400*2*sizeof(int));
	 }
	 close(pread);

	 pread = open("Phase4.txt", O_RDONLY);
	 if(pread != -1){
	 	read(pread, *lFour, 663552*2*sizeof(int));
	 }
	 close(pread);


}

int main(){
	//with facelet given..
	char facelet[80];
	int i,j;
	for (i=0;i<54;i++) {
	  cin >> j;
	  facelet[i] = j;
	}
	cube c;
	c.orientCube(facelet);
	c.setCube();
	cout << "cube set" << endl;
	readLists();
	c.dumpCubeArrays();
	c.dumpCubeFacelets();
	
	int destination = c.phaseOneEncode();
	while(destination != 0 && destination < 2048){
		moves.push_back(lOne[destination][0]);
		c.moveCaller(moves.back());
		destination = lOne[destination][1];
		cout << destination << '.'; cout.flush();
	}
	moves.push_back(33);
	cout << "//" << endl;

	destination = c.phaseTwoEncode();
	while(destination != 69){
		moves.push_back(lTwo[destination][0]);
		c.moveCaller(moves.back());
		destination = lTwo[destination][1];
		cout << destination << '.'; cout.flush();
	}
	moves.push_back(33);
	cout << "//" << endl;

	destination = c.phaseThreeEncoding();
	while(destination != 0){
		moves.push_back(lThree[destination][0]);
		c.moveCaller(moves.back());
		destination = lThree[destination][1];
		cout << destination << '.'; cout.flush();
	}
		moves.push_back(33);
		cout << "//" << endl;

	destination = c.phaseFourEncoding();
	while(destination != 4032){
		moves.push_back(lFour[destination][0]);
		c.moveCaller(moves.back());
		destination = lFour[destination][1];
		cout << destination << '.'; cout.flush();
	}
	moves.push_back(33);
	cout << "//" << endl;

	ofstream outfile;
	outfile.open("solved.txt");
	string allMoves = "- complete!";
	while(!moves.empty()){
		switch(moves.back()){
			case 0:
				allMoves = "W " + allMoves;
				break;
			case 1:
				allMoves = "B " + allMoves;
				break;
			case 2:
				allMoves = "R " + allMoves;
				break;
			case 3:
				allMoves = "G " + allMoves;
				break;
			case 4:
				allMoves = "O " + allMoves;
				break;
			case 5:
				allMoves = "Y " + allMoves;
				break;
			case 6:
				allMoves = "W\' " + allMoves;
				break;
			case 7:
				allMoves = "B\' " + allMoves;
				break;
			case 8:
				allMoves = "R\' " + allMoves;
				break;
			case 9:
				allMoves = "G\' " + allMoves;
				break;
			case 10:
				allMoves = "O\' " + allMoves;
				break;
			case 11:
				allMoves = "Y\' " + allMoves;
				break;
			case 12:
				allMoves = "W2 " + allMoves;
				break;
			case 13:
				allMoves = "B2 " + allMoves;
				break;
			case 14:
				allMoves = "R2 " + allMoves;
				break;
			case 15:
				allMoves = "G2 " + allMoves;
				break;
			case 16:
				allMoves = "O2 " + allMoves;
				break;
			case 17:
				allMoves = "Y2 " + allMoves;
				break;
			case 18:
				allMoves = "Ws " + allMoves;
				break;
			case 19:
				allMoves = "Bs " + allMoves;
				break;
			case 20:
				allMoves = "Rs " + allMoves;
				break;
			case 21:
				allMoves = "Gs " + allMoves;
				break;
			case 22:
				allMoves = "Os " + allMoves;
				break;
			case 23:
				allMoves = "Ys " + allMoves;
				break;
			case 24:
				allMoves = "W2s " + allMoves;
				break;
			case 25:
				allMoves = "B2s " + allMoves;
				break;
			case 26:
				allMoves = "R2s " + allMoves;
				break;
			case 27:
				allMoves = "Wa " + allMoves;
				break;
			case 28:
				allMoves = "Ba " + allMoves;
				break;
			case 29:
				allMoves = "Ra " + allMoves;
				break;
			case 30:
				allMoves = "W\'a " + allMoves;
				break;
			case 31:
				allMoves = "B\'a " + allMoves;
				break;
			case 32:
				allMoves = "R\'a " + allMoves;
				break;
			case 33:
				allMoves = "// " + allMoves;
				break;
		}
		moves.pop_back();
	}
	outfile << "Solution: \n" << allMoves << "\n";
	outfile.close();
	
	return 0;
}
