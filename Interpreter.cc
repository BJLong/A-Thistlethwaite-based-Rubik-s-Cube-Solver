#include <stdio.h>
#include <iostream>
using namespace std;
//corner 0-5 edge 6-12, mi
char rotateUpArray[54] = {
	2,5,8,1,4,7,0,3,6, //rotate about 4
	53,52,51,50,49,48,47,46,45,
	24,21,18,25,22,19,26,23,20,
	36,37,38,39,40,41,42,43,44,
	17,16,15,14,13,12,11,10,9,
	27,28,29,30,31,32,33,34,35,
};
char facelet[54];

void rotateUp(){
	temp = facelet;
	for(int i = 0; i < 54; i++){
		facelet[i] = temp[rotateUpArray[i]];
	}
}

// ignore for now
void rotateLeft(){
	char temp[9];
	for(int i = 0; i < 9; i++){
		temp[i] = facelet[i];
	}
	for(int i = 0; i < 9; i++){
		temp[i] = facelet[i+9];
	}
	for(int i = 0; i < 9; i++){
		temp[i+9] = facelet[i+18];
	}
	for(int i = 0; i < 9; i++){
		temp[i+18] = facelet[i+27];
	}
	for(int i = 0; i < 9; i++){
		facelet[i+27] = temp[i];
	}

}

int main(){
	return 0;
}