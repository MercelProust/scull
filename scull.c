#include "scull.h"

//get the device region
int GetDeviceRegion()
{
	int result = 0;

	if (scull_major)
	{
		dev = MKDEV(scull_major, scull_minor);
		result = register_chrdev_region(dev, scull_nr_devs, scull_name);
	}
	else
	{
		result = alloc_chrdev_region(&dev, scull_minor, scull_nr_devs, scull_name);
		scull_major = MAJOR(dev);
	}

	return result;
}

void ReleaseDeviceRegion()
{
	unregister_chrdev_region(dev, scull_nr_devs);
}