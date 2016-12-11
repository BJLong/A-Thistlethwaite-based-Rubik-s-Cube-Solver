#include <stdio.h>
#include <iostream>
#include "Project.cc"
using namespace std;

char facelet[54];
int encoding;
char rotateUpArray[54] = {
	2, 5, 8,  1, 4, 7,  0, 3, 6,
	53,52,51, 50,49,48, 47,46,45,
	24,21,18, 25,22,19, 26,23,20,
	36,37,38, 39,40,41, 42,43,44,
	17,16,15, 14,13,12, 11,10,9,
	27,28,29, 30,31,32, 33,34,35,
};

char rotateLeftArray[54] = {
	9,10,11,  12,13,14, 15,16,17,
	18,19,20, 21,22,23, 24,25,26,
	27,28,29, 30,31,32, 33,34,35,
	0, 1, 2,  3, 4, 5,  6, 7, 8,
	42,39,36, 43,40,37, 44,41,38,
	47,50,53, 46,49,52, 45,48,51
};

char cornerMap[8] = {
	19, 7, 11, 25, 56, 44, 38, 50
};

char cornerColors[8][3] = {
	{36, 18, 11},
	{38, 9, 2},
	{44, 0, 29},
	{42, 27, 20},
	{45, 26, 33},
	{47, 35, 6},
	{53, 8, 15},
	{51, 17, 24}
};

void rotateUp(){
	char temp[54];
	for(int i = 0; i < 54; i++){
	temp[i] = facelet[i];
	}
	for(int i = 0; i < 54; i++){
		facelet[i] = temp[rotateUpArray[i]];
	}
}

void rotateLeft(){
	char temp[54];
	for(int i = 0; i < 54; i++){
	temp[i] = facelet[i];
	}
	for(int i = 0; i < 54; i++){
		facelet[i] = temp[rotateLeftArray[i]];
	}	
}

void orientCube(){
	if(facelet[49] == 0){
		rotateUp();
	}
	if(facelet[40] != 0){
		while(facelet[13] != 0){
			rotateLeft();
		}
		rotateUp();
	
}	while(facelet[13] != 1){
		rotateLeft();
	}
}

void makeCube(cube c){
	//need a way to get positions and orientations from facelets
	encoding = c.phaseOneEncoding();
}

vector<char> moves;

void phaseOne(){
	ifstream inFile;
	int a = 0;
	//get current state encoding
	// int location = phaseOneEncoding;
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
	}
}

int main(){
	// generateListOne();
	return 0;
}