#include "scull.h"
#include <linux/init.h>
#include <linux/module.h>

MODULE_LICENSE("Dual BSD/GPL");

static int scull_init(void)
{
	int result = 0;

	printk(KERN_ALERT "entry scull device, hello you guys");
	result = GetDeviceRegion();
	if (result)
	{
		printk(KERN_ALERT "Fail to get device region");
	}

	return 0;
}

static void scull_exit(void)
{
	ReleaseDeviceRegion();

	//delete the device from the system
	if (NULL != my_cdev)
	{
		cdev_del(my_cdev);
	}

	printk(KERN_ALERT "Bye guys, exit the scull");
	return;
}

module_init(scull_init);
module_exit(scull_exit);
