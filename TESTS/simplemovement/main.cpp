#include <iostream>
#include <string>
#include <stdio.h>
#include <thread>
#include <cmath>
#include <iomanip>
#include <unistd.h>
#include <sys/time.h>
#include "/home/chazz/HEX/LIB_HEXAPOD/hexapod.h"

using namespace std;

#define SIZE 128

double getTime()
{
	double ret;
	struct timeval tv;
	gettimeofday(&tv, NULL);
	ret = (tv.tv_sec) + tv.tv_usec*1e-6;
	return ret;
}

int main(void)
{
	int ii, ij, ik, ix, iy, size, ind;
	int cx, cy, attempts;
	
	hexapod hex;
	
	int dsize, psize;
	double time, lasttime, dt, lastdata, inittime;
	bool cont, quit;

	
	inittime = getTime();
	cout<<inittime<<"\n";
	
	// we received data from the Arbotix-M, it's good to continue
	cout << "System Ready." << endl;
	for (ii=0; ii<18; ii++)
	{
	
		hex.servoangle[ii] = 90.0;
	}
	hex.setAngles();
	


	cout << "Angles read." << endl;
	

	// max useable speed is 2.0 -> 1 foot per second
	hex.speed = 0.0; // in cycles per second
	hex.turning = 0.0; // [-1,1], rotation in z-axis

	
	// hex.debug = true;
	cout << "Begin IK" << endl;
	// IK test
	time = 0.0;
	lasttime = getTime();
	hex.safeStand();
	while (hex.ssrunning)
	{
		dt = (getTime() - lasttime);
		lasttime = getTime();
		hex.step(dt);
		// cout<<"time:"<<dt<<"\n";
		// package positions
		cout<<"Hexapod{servoAngle=[";
		for (ii=0; ii<18; ii++)
		{
		 	cout<< hex.servoangle[ii]<<",";
		}

		cout<<"]}\n";
		
		usleep(20*1000);

	}
	
	cout << "walking.." << endl;

	lasttime = getTime();
	lastdata = lasttime;
	usleep(20*1000);

	hex.speed = 4.0;
	
	quit = false;
	while (!quit)
	{
		dt = (getTime() - lasttime);
		time += dt;
		lasttime = getTime();
		hex.step(dt);
		
		
		cout<<"Hexapod{servoAngle=[";
		for (ii=0; ii<18; ii++)
		{
		 	cout<< hex.servoangle[ii]<<",";
		}

		cout<<"]}\n";
usleep(20*1000);
	}
		
		
	
}
