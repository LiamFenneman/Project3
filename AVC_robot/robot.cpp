#include "robot.hpp"

// find the first column that contains a white pixel
// 	-	using the middle of the camera view
int findFirstWhiteCol() {
	int row = cameraView.height/2; // middle row
	// loop through all the pixels on the middle row
	for (int col = 0; col < cameraView.width; col++) {
		int pix = get_pixel(cameraView, row, col, 3); // get the pixel
		
		// if the pixel is white -> return the column no.
		if (pix > 250) { return col; }
	}
	return 0;
}

int findClosestRedCol() {
	int closest = 0;
	
	int row = cameraView.height-1; // middle row
	int midCol = cameraView.width/2; // middle col
	
	for (int col = 0; col < cameraView.width; col++) {
		int pix = get_pixel(cameraView, row, col, 0); // get the pixel
		
		if (pix > 250) {
			if (std::abs(col) > std::abs(closest))
			closest = col; //stores the closest red column 
		}
	}
	
	return closest; //returns the closest red column
}

// checks to see if the flag is present on the camera
//  -	used to stop the robot upon reaching the finish line
int isFlag() {
	int count = 0;
	// loop through all pixels (all rows / columns) in the camera view
	for (int row = 0; row < cameraView.height; row++) {
		for (int col = 0; col < cameraView.width; col++) {
			int pix = get_pixel(cameraView, row, col, 3); // get the pixel
			
			// if the pixel is black -> add one to the counter
			if (pix < 10) { count++; }
		}
	}
	
	// if there are more than 1000 black pixels we can safely assume the flag is present
	return count > 1000;
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
	double speed = 15.0;
	double ratio = 1.5;
	
	while(1) {
		takePicture();
		
		int midCol = cameraView.width/2;	// middle column
		
		int diff = 0;
		int dir = 0;
		
		int firstCol = findFirstWhiteCol(); // first column that is white in the middle row
		if (std::abs(firstCol) > 0) {
			diff = firstCol - midCol;	// the distance between the middle column and first white pixel
			dir = (diff > 0);			// the direction which the robot should move to correct itself
										//  - move right when the line is to the right of the robot
		}
		else {
			diff = firstCol - midCol; // the distance between the middle column and first white pixel
			dir = (diff < 0);				     // the direction which the robot should move to correct itself
		}
		
		// move the robot
		if (isFlag()) { // stop on flag
			vLeft = 0;
			vRight = 0;
		}
		
		if (dir) { // turn right
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
