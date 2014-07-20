#ifndef SCULL_H
#define SCULL_H

#include <linux/fs.h>

const char* scull_name = "scull";		//decive name
const int    scull_nr_devs = 10;		//device count

dev_t dev; //device region
int scull_major = 0; //major device region
int scull_minor = 0; //minor device region

//get the device region
int GetDeviceRegion(void);

//release device region
void ReleaseDeviceRegion(void);

#endif