#include <stdio.h>
#include <iostream>
using namespace std;

char facelet[54];

void rotateUp(){
	char temp[9];
	for(int i = 0; i < 9; i++){
		temp[i] = facelet[44 - i];
	}
	for(int i = 0; i < 9; i++){
		facelet[44 - i] = facelet[i + 9];
	}
	for(int i = 0; i < 9; i++){
		temp[i + 9] = facelet[53 - i];
	}
	for(int i = 0; i < 9; i++){
		temp[53 - i] = facelet[i + 27];
	}
	for(int i = 0; i < 9; i++){
		facelet[i + 27] = temp[i];
	}
}

int main(){
	return 0;
}