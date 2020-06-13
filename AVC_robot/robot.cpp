#include "robot.hpp"

// returns 1 when a pixel is white and 0 otherwise
int isWhite(int row, int col) {
	int pix = get_pixel(cameraView, row, col, 3);
	int isWhite;
	
	if (pix > 250)	{ isWhite = 1; }
	else 			{ isWhite = 0; }
	
	return isWhite;
}

// checks to see if the flag is present on the camera
//  -	used to stop the robot upon reaching the finish line
int isFlag() {
	int count = 0;
	for (int row = 0; row < cameraView.height; row++) {
		for (int col = 0; col < cameraView.width; col++) {
			int pix = get_pixel(cameraView, row, col, 3);
			
			if (pix < 10) { count++; }
		}
	}
	
	return count > 1000;
}

// find the first column that contains a white pixel
// 	-	using the middle of the camera view
int findFirstWhiteCol() {
	int col = 0;
	while(1) {
		if (col >= cameraView.width) { break; }
		if (isWhite(cameraView.height/2, col)) {
			return col;
		}
		col++;
	}
}


int main() {
	if (initClientRobot() !=0){
		std::cout<<" Error initializing robot"<<std::endl;
	}
	
	double vLeft = 3.0;
	double vRight = 3.0;
	
		
	// move the robot based on direction
	//  -	speed:	 how fast the robot will move
	//  -   ratio:	 the ratio between left and right wheel when moving
	double speed = 10.0;
	double ratio = 1.5;
	
	while(1) {
		int midCol = cameraView.width/2;
		takePicture();
		
		int firstCol = findFirstWhiteCol();
		int diff = firstCol - midCol;
		int dir = (diff > 0);
		
		if (isFlag()) { // stop on flag
			vLeft = 0;
			vRight = 0;
		}
		else if (dir) { // turn right
			vLeft = ratio * speed;
			vRight = speed;
		}
		else { // turn left
			vLeft = speed;
			vRight = ratio * speed;
		}

		setMotors(vLeft,vRight);
		std::cout<<" vLeft="<<vLeft<<"  vRight="<<vRight<<"  dir="<<dir<<std::endl;
		usleep(5000);
	} //while

} // main
