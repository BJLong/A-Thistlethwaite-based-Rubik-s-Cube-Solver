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
		temp[53 - i] = facelet[35-i];
	}
	for(int i = 0; i < 9; i++){
		facelet[35-i] = temp[i];
	}
	//rotate about facelet[4]
	temp[0] = facelet[0];
	temp[1] = facelet[1];
	facelet[0] = facelet[2];
	facelet[2] = facelet[8];
	facelet[8] = facelet[6];
	facelet[6] = temp[0];
	facelet[1] = facelet[5];
	facelet[5] = facelet[7];
	facelet[7] = facelet[3];
	facelet[3] = temp[1];
	//rotate about facelet[22]
	temp[0] = facelet[18];
	temp[1] = facelet[19];
	facelet[18] = facelet[24];
	facelet[24] = facelet[26];
	facelet[26] = facelet[20];
	facelet[20] = temp[0];
	facelet[19] = facelet[21];
	facelet[21] = facelet[25];
	facelet[25] = facelet[23];
	facelet[23] = temp[1];

}

/*ignore for now
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
*/
int main(){
	return 0;
}