#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<math.h>

/*
Author: John Cody
Date created: 1/21/2018
Program Description: The program takes in the distance and the force with which an object will fall, 
and then it calculates the time it will take to fall and the velocity it will be falling with when it hits the ground. 
Input(s): distance and force
Output(s): time and velocity
brief description or relationship between inputs and outputs: distance and force are used to calculate the time, 
and then the time and the force are used to calculate the velocity. 
*/

int main(void) {

	float distance;                                                //Create variables to take in the distance and the force from the user. 
	float force;

	printf("Enter the distance that the object will travel (meters)");   //Get the distance from the user.
	scanf("%f", &distance);

	printf("\nEnter the constant acceleration caused by the gravitation field (meters/s^2)");  //Get the force that will be exerted from the user.
	scanf("%f", &force);

	float time = powf((2 * distance) / force, 0.5);                          //I use the powf statement to raise the float formula to the 1/2.
	printf("\nThe object will travel %.2f meters in %.2f seconds\n", distance, time);

	float velocity = force * time;                                           //Calculating the velocity :)
	printf("After falling for %.2f seconds the object will be traveling %.2f meters/second\n", time, velocity);

	return 0;
}