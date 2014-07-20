#ifndef SCULL_H
#define SCULL_H

#include <linux/fs.h>
#include <linux/cdev.h>

const char* scull_name = "scull";		//decive name
const int    scull_nr_devs = 10;		//device count

dev_t dev; //device region
int scull_major = 0; //major device region
int scull_minor = 0; //minor device region

//define dirver's file operations 
struct file_operations my_fops  = 
{
	.owner = THIS_MODULE,
	.llseek = scull_llseek,
	.read = scull_read,
	.write = scull_write,
	.ioctl = scull_ioctl,
	.open = scull_open,
	.release =scull_release,
};

struct cdev *my_dev;  //this char device

//get the device region
int GetDeviceRegion(void);

//release device region
void ReleaseDeviceRegion(void);

//init this char device struce
void InitializeCdev(void);

#endif
