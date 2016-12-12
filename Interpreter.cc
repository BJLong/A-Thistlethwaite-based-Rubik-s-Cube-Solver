#include <stdio.h>
#include <iostream>
#include <sys/stat.h> 
#include <fcntl.h>
#include <unistd.h>
#include "Project.cc"
using namespace std;

char facelet[54];
vector<char> moves;
int lOne[2048][2];
int lTwo[1082565][2];
int lThree[2822400][2];
int lFour[663552][2];
void readLists(){
	ifstream inFile;
	inFile.open("Phase1.txt");
	for (int i = 0; i < 2048; i++){
		inFile.seekg(i * 8);
		inFile.read(reinterpret_cast<char *>(&lOne[i][0]), sizeof(int));
		inFile.seekg((i * 8) + 4);
		inFile.read(reinterpret_cast<char *>(&lOne[i][1]), sizeof(int));
	}
}

void phaseOne(){
	ifstream inFile;
	int a = 0;
	// get current state encoding
	int location = phaseOneEncoding;
	inFile.open("Phase1.txt");
	if(inFile.is_open()){
		/*
		while(distination != -1):
			location = encoding * 8
			next_move = read(location, sizeof(int))
			encoding = read(location+4, sizeof(int))
			moves.push_back(next_move)
		*/
		inFile.seekg(location);
		inFile.read(reinterpret_cast<char *>(&a), sizeof(a));
		destination = a;
		inFile.seekg(location + 4);
		inFile.read(reinterpret_cast<char *>(&a), sizeof(a));
		moves.push_back(a);
	// }
}

int main(){
	//with facelet given..
	cube c;
	c.orientCube(facelet);
	c.setCube();


	return 0;
}