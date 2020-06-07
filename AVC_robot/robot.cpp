#include "robot.hpp"

// returns 1 when a pixel is white and 0 otherwise
int isWhite(int row, int col) {
	int pix = get_pixel(cameraView, row, col, 3);
	int isWhite;
	
	if (pix > 250)	{ isWhite = 1; }
	else 			{ isWhite = 0; }
	
	return isWhite;
}

int findFirstWhiteRow() {
	int row = 0;
	int firstWhiteRow = 0;
	while(firstWhiteRow == 0) {
		if (row >= cameraView.height) { break; }
		if (isWhite(row, cameraView.width/2)) {
			firstWhiteRow = row;
		}
		row++;
	}
	return firstWhiteRow;
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
	int midRow;
	int firstWhiteRow = 0;
	
	while(1) {
		takePicture();
		
		// find the row in the middle of the white pixels
		firstWhiteRow = findFirstWhiteRow();
		midRow = cameraView.height/2;
		int diff = firstWhiteRow - midRow;
		
		// move to the right
		if (diff > 0) {
			vLeft = 2.0 * std::abs(diff);
			vRight = 1.0 * std::abs(diff);
		}
		// move to the left
		else if (diff < 0) {
			vLeft = 1.0 * std::abs(diff);
			vRight = 2.0 * std::abs(diff);
		}
		// move straight
		else {
			vLeft = 5.0;
			vRight = 5.0;
		}
		
		
		// go towards the mid row

		setMotors(vLeft,vRight);   
		std::cout<<" vLeft="<<vLeft<<"  vRight="<<vRight<<std::endl;
		usleep(10000);
	} //while

} // main
