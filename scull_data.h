#ifndef SCULL_DATA_H
#define SCULL_DATA_H

include <linux/fs.h>
#include <linux/semaphore.h>

struct scull_dev
{
	struct scull_qset *data; //thie pointer to the first quotes
	int quantum;		//current quant count
	int qset;		//current array size
	unsigned long size;	//total data count
	unsigned int access_key;  //used by sculluid and scullpriv
	struct semaphore sem;    //semaphore
	struct cdev cdev;         //char device
};

#endif
