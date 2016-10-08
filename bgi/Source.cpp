/*	Author: Ben Xerri
	Pesky Tourist Assignment, midterm project 1


*/

//You can find the BGI documentation at https://www.cs.colorado.edu/~main/bgi/doc/

#include "graphics.h" 
#include <stdio.h>
#include <iostream>
using namespace std;

/* sortInfo:: Pre-Condition, Take in an array of 9 unsorted integers
	The function does not return anything because all arrays are pass by reference
	So the Post-Condition, is an array of sorted elements
*/
void sortInfo(int arr[9]);

/* loadImage:: Pre-Condition, Take in an integer representing the image number
		Post-condition, Reads the image as a 200 by 225 image, use this to load each image that you will manipulate
*/
void loadImage(int imageNumber);

int main()
{

	//I used the first window as a place to load the images and get their pixel values
	//Then I replace the image at the end with the picture without the tourist,
	//this way you get a nice vanishing of the tourist, as if he was taken away by aliens for ruining your picture
	int firstWindow = initwindow(200, 225, "picture 1"); //notice these window values are ints
	

	int arrOfImages[9][200][225]; //create your 3d array, to go through 200x 225y and 9 pictures
	setcurrentwindow(firstWindow);
	
	for (int i = 0; i < 9; i++) { //looping through all the images and storing pixel values in the 3d array
		loadImage(i); //load your current image , starting with the first image
		
		for (int x = 0; x < 200; x++) {
			
			for (int y = 0; y < 225; y++) {
				arrOfImages[i][x][y] = getpixel(x, y); //so you have the pixel at value 0, 0
			}
		}
	} //at the end of this loop, your 3d array is full of pixel values
	
	//make another loop to compare all RGB values for each image, and get the medium, then store the medium in the final 
	//image at x,y,i

	 int redValue[9];  //make 3 arrays of 9 to hold the pixel value for each Red, Green, and Blue value
	 int greenValue[9];
	 int blueValue[9];
	 
	
		
		for (int x = 0; x < 200; x++) {
			
			for (int y = 0; y < 225; y++) { //go into each section of array and get the red,green,blue value

				for (int i = 0; i < 9; i++) { //looping through all the images and storing pixel values in the 3d array
				redValue[i] = RED_VALUE(arrOfImages[i][x][y]);
				greenValue[i] = GREEN_VALUE(arrOfImages[i][x][y]);
				blueValue[i]= BLUE_VALUE(arrOfImages[i][x][y]);
			}//if you reach here, this array of 9 is full of 9 arrays of the RGB values for each pixel 
				//now we can call our sort value for all 3 arrays representing RGB
				sortInfo(redValue);
				sortInfo(greenValue);
				sortInfo(blueValue);
				putpixel(x, y, COLOR(redValue[4], greenValue[4], blueValue[4])); //put our pixel at the current x and y value , with the medium of our RGB arrays
																				//the medium value is the middle of the array of 9, so the 4th value
			} //then we move onto the next pixel and repeat for each pixel of the 200 by 225 picture,
			
	} 
	
	outtextxy(0, 0, "Press any key");

	getch(); //pauses the program
}


//all the images are numbered 0 to 8
//this function takes that image number and loads it onto the 
//selected window (I loaded images onto the first window)
void loadImage(int imageNumber)
{
	char str[6];
	sprintf(str, "%i.jpg", imageNumber);
	readimagefile(str, 0, 0, 200, 225); //this is a BGI function that loads the image onto the current window
}

void sortInfo(int arr[9]) { //create an array of 9 to match the size of the arrays of RGB
	int temp; //create a temp value and a second looping variable outside of the 2 loops
	int j;
	for (int i = 1; i < 9; i++) { //go through all 9 slots in the array starting at position  [1]
		temp = arr[i]; // store the first value as temp
		j = i; //match the second incrementer to that number , not the value

		while(j-1 >= 0 && arr[j-1] > temp){ //while the second incrementer-1 is greater than 0 and the value of the array position is greater
			arr[j] = arr[j-1];					//you can enter the while loop and shift the values
			j--;								
		}
		arr[j] = temp; //replace your temp value so you don't lose it
	}

}