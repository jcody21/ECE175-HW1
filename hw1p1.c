#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<math.h>

/*
Author: John Cody
Date created: 1/20/2018
Program Description: The program helps the user calculate how much the flooring aspect of their home improvement project will cost. 
Input(s): The user inputs the length and width of the room, the length of one side of a square tile, the price of one tile, and the sales tax as a percentage. 
Output(s): The program calculates and outputs the area of the room, the number of whole tiles necessary, and the cost of the tiles before and after tax. 
brief description or relationship between inputs and outputs: The room length and width are used to calculate the area of the room. 
The room width and length are used again along with the tile length to calculate the number of tiles necessary to cover the floor. 
Finally, the number of tiles, price per tile, and sales tax percentage are used to find the cost before and after sales tax. 
*/
int main(void) {
	
	int roomLength;
	int roomWidth;
	int tileLength;
	float pricePerTile;
	float salesTax;                 //These are all of the variables that will be taken as inputs. 

	printf("Enter in the length of the room to be tiled (inches)");              //The program requests the length of the room in inches. 
	scanf("%d", &roomLength);                                                  //The data supplied is read into the variable roomLength. 
	
	printf("\nEnter in the width of the room to be tiled (inches)");               //The program requests the width of the room in inches.
	scanf("%d", &roomWidth);                                                   //The data supplied is read into the variable roomWidth. 

	printf("\nEnter in the length of one side of a single tile (inches)");  //The program requests the length of one side of the tile in inches.
	scanf("%d", &tileLength);                                                  //The data supplied is read into the variable tileLength. 

	printf("\nEnter in the cost of a single square tile (dollars)");      //The program requests the price of each tile.
	scanf("%f", &pricePerTile);                                                //The data supplied is read into the variable pricePerTile. 

	printf("\nEnter in the percent sales tax (percent)");  //The program requests the sales tax percentage.
	scanf("%f", &salesTax);                                                                   //The data supplied is read into salesTax. 


	int roomArea = roomLength * roomWidth;                                     //The roomArea variable is created and set equal to the area of the room.
	printf("\nThe total area to be tiled is %d square inches\n", roomArea);   //The program outputs the area of the room in square inches.
	
	
	float fTileLength = roomLength / (float) tileLength;    //These two variables are created as floats so that they can hold a decimal without  
	float fTileWidth = roomWidth / (float) tileLength;      //it being truncated. They also divide the floor up into how many tiles will fit.

	if (fmodf(fTileLength,1.0) != 0.0) {              //Now the fmodf function gets a remainder if there is one. If there is a remainder not 
		fTileLength = (int)fTileLength + 1.0;         //equal to 0.0, the decimal of fTileLength is truncated, and 1.0 is added. 
	}
	
	if (fmodf(fTileWidth,1.0) != 0.0) {               //This if statement performs the same calculation, except for fTileWidth. 
		fTileWidth = (int)fTileWidth + 1.0;           //These if statements are necessary as they ensure that there is a tile for every spot on the floor.
	}
	
	int numTile = (int)fTileLength * (int)fTileWidth;  //Finally, the program calculates how many tiles will be needed for the whole floor. 
	printf("The total number of tiles to be purchased is %d\n", numTile);

	float cost = numTile * pricePerTile;                               //The program determines how much all of the tiles will cost. 
	printf("The cost of the purchase before tax is $%.2f\n", cost);

	cost = cost * (1 + (salesTax / 100));                              //The program factors in how much sales tax will cost.
	printf("The cost of the purchase including tax is $%.2f\n", cost);

	return 0;
}