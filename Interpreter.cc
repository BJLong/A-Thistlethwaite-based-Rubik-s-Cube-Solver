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
	int pread = open("Phase1.txt", O_RDONLY);
	if(pread != -1){
		read(pread, *lOne, 2048*2*sizeof(int));
	}
	close(pread);

	pread = open("Phase2.txt", O_RDONLY);
	if(pread != -1){
		read(pread, *lTwo, 1082565*2*sizeof(int));
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
	cube c;
	c.orientCube(facelet);
	c.setCube();
	int destination = c.phaseOneEncoding();
	while(destination != -1){
		moves.push_back(lOne[destination][0]);
		c.moveCaller(moves.back());
		destination = lOne[destination][1];
	}

	destination = c.phaseTwoEncoding();
	while(destination != -1){
		moves.push_back(lTwo[destination][0]);
		c.moveCaller(moves.back());
		destination = lTwo[destination][1];
	}

	destination = c.phaseThreeEncoding();
	while(destination != -1){
		moves.push_back(lThree[destination][0]);
		c.moveCaller(moves.back());
		destination = lThree[destination][1];
	}

	destination = c.phaseFourEncoding();
	while(destination != -1){
		moves.push_back(lFour[destination][0]);
		c.moveCaller(moves.back());
		destination = lFour[destination][1];
	}
	return 0;
}