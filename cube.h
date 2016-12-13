class cube {
	private:
		static const char edgeMoves[6][4];
		static const char cornerMoves[6][4];
		static const char rotateUpArray[54];
		static const char rotateLeftArray[54];
		static const char cornerMap[8];
		static const char cornerFacelets[8][3];
		static const char edgeMap[12];
		static const char edgeFacelets[12][2];
		char facelet[54];
		char edge[2][12];
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
		int phaseThreeCornerEncoding(int, int[]);
		int phaseThreeEdgeEncoding();
		int phaseThreeEncoding();
		int phaseFourCornerEncoding();
		int phaseFourEdgeEncoding();
		int phaseFourEncoding();
		void rotateUp();
		void rotateLeft();
		void orientCube(char[]);
		void setCube();
void dumpCubeArrays();
void dumpCubeFacelets();
};

void generateListOne(void);
void generateListTwo(void);
void generateListThree(void);
void generateListFour(void);

