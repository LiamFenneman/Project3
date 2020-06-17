#include "robot.hpp"

int isWhite(int row, int col) {
	int pix = get_pixel(cameraView, row, col, 3);
	int isWhite;
	
	if (pix > 250)	{ isWhite = 1; }
	else 			{ isWhite = 0; }
	
	return isWhite;
}

int findFirstWhiteCol() {
	int row = cameraView.height/2;
	for (int col = 0; col < cameraView.width; col++) {
		if (isWhite(row, col)) {
			return col;
		}
	}
}

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

int main() {
	if (initClientRobot() !=0){
		std::cout<<" Error initializing robot"<<std::endl;
	}
	
	double speed = 5.0;
	double ratio = 1.75;
	
	double vLeft = speed;
	double vRight = speed;
	
	while(1) {
		takePicture();
		int midCol = cameraView.width/2;
		
		int firstCol = findFirstWhiteCol();
		int diff = firstCol - midCol;
		
		std::cout<<" diff="<<diff<<std::endl;
		
		// move to the right
		if (diff > 0) {
			vLeft = ratio * speed;
			vRight = speed;
		}
		// move to the left
		else if (diff < 0) {
			vLeft = speed;
			vRight = ratio * speed;
		}
		
		if (isFlag()) {
			vLeft = 0;
			vRight = 0;
		}

		setMotors(vLeft,vRight);   
		std::cout<<" vLeft="<<vLeft<<"  vRight="<<vRight<<std::endl;
		usleep(5000);
	}
}

/*

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
			closest = col;
		}
	}
	
	return closest;
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
	double speed = 10.0;
	double ratio = 1.5;
	
	while(1) {
		takePicture();
		
		int diff = 0;
		int dir = 0;
		
		int firstCol = findFirstWhiteCol(); // first column that is white in the middle row
		int closeRed = findClosestRedCol();
		
		if (std::abs(firstCol) > 0) {
			diff = firstCol - midCol;	// the distance between the middle column and first white pixel
			dir = (diff > 0);			// the direction which the robot should move to correct itself
										//  - move right when the line is to the right of the robot
		}
		else if (std::abs(closeRed) > 0) {
			diff = closeRed - midCol;   // the distance between the middle column and first white pixel
			dir = (diff < 0);			// the direction which the robot should move to correct itself
		}
		else {
			dir = 1; // turn right by default
		}
		
		// move the robot
		if (dir) { // turn right
			vLeft = ratio * speed;
			vRight = speed;
		}
		else { // turn left
			vLeft = speed;
			vRight = ratio * speed;
		}
		
		if (isFlag()) { // stop on flag
			vLeft = 0;
			vRight = 0;
		}
		

		setMotors(vLeft,vRight);
		std::cout<<" vLeft="<<vLeft<<"  vRight="<<vRight<<"  dir="<<dir<<std::endl;
		usleep(5000);
	} //while

} // main

*/
