#include "robot.hpp"

// returns 1 when a pixel is white and 0 otherwise
int isWhite(int row, int col) {
	int pix = get_pixel(cameraView, row, col, 3);
	int isWhite;
	
	if (pix > 250)	{ isWhite = 1; }
	else 			{ isWhite = 0; }
	
	return isWhite;
}

// gets the number of pixels that are white down the middle of the camera view
int countWhitePixelsInRow() {
	int count = 0;
	for (int row = 0; row < cameraView.height; row++) {
		if (isWhite(row, (float)cameraView.width/2.0)) {
			count += 1;
		}
	}
	return count;
}

int main(){
	if (initClientRobot() !=0){
		std::cout<<" Error initializing robot"<<std::endl;
	}
	double vLeft = 3.0;
	double vRight = 3.0;
	std::string filename = "i0.ppm";
	//takePicture();
	//SavePPMFile(filename,cameraView);
	int whitePixelCount = countWhitePixelsInRow();
	int whitePixels [whitePixelCount];
	while(1) {
		takePicture();
		
		// find the row for each white pixel and add them to the whitePixels array
		for (int row = 0; row < cameraView.height; row++) {
			if (isWhite(row, (float)cameraView.width/2.0)) {
				whitePixels[row] = row;
			}
		}
		
		// find the row in the middle of the white pixels
		int midIndex = whitePixelCount/2;
		int midRow = whitePixels[midIndex];
		
		// go towards the mid row
		
		std::cout<<middleRow<<std::endl;

		setMotors(vLeft,vRight);   
		//std::cout<<" vLeft="<<vLeft<<"  vRight="<<vRight<<std::endl;
		usleep(10000);
	} //while

} // main
