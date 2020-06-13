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
	std::string filename = "i0.ppm";
	//takePicture();
	//SavePPMFile(filename,cameraView);
	
	double speed = 6.0;
	
	while(1) {
		takePicture();
		int midCol = cameraView.width/2;
		
		int firstCol = findFirstWhiteCol();
		int diff = firstCol - midCol;
		
		std::cout<<" diff="<<diff<<std::endl;
		
		// move to the right
		if (diff > 0) {
			vLeft = 2 * speed;
			vRight = speed;
		}
		// move to the left
		else if (diff < 0) {
			vLeft = speed;
			vRight = 2 * speed;
		}
		
		if (isFlag()) {
			vLeft = 0;
			vRight = 0;
		}

		setMotors(vLeft,vRight);   
		std::cout<<" vLeft="<<vLeft<<"  vRight="<<vRight<<std::endl;
		usleep(300);
	} //while

} // main
