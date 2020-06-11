#include "robot.hpp"

// returns 1 when a pixel is white and 0 otherwise
int isWhite(int row, int col) {
	int pix = get_pixel(cameraView, row, col, 3);
	int isWhite;
	
	if (pix > 250)	{ isWhite = 1; }
	else 			{ isWhite = 0; }
	
	return isWhite;
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
	
	double speed = 3.0;
	
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

		setMotors(vLeft,vRight);   
		std::cout<<" vLeft="<<vLeft<<"  vRight="<<vRight<<std::endl;
		usleep(10000);
	} //while

} // main
