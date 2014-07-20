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

void InitializeCdev()
{
	if (NULL == my_cdev)
	{
		my_cdev = cdev_alloc();
		my_cdev->owner = THIS_MODULE;
		my_cdev->fops = &my_fops;

		//add this char device to system
		int rtnCode = cdev_add(my_cdev, dev, 1);
		if (rtnCode < 0)
		{
			printk(KERN_ALERT "fail: %d = cdev_add()", rtnCode);
		}
		else
		{
			printk(KERN_ALERT "Succeed : %d = cdev_add()", rtnCode);
		}
	}
}
