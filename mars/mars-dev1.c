/** Mars module
 *
 * Author: Zex Li <top_zlynch AT yahoo.com>
 */
#include <linux/module.h>
#include <linux/fs.h>
#include <linux/cdev.h>
#include <linux/kernel.h>
#include <linux/platform_device.h>
#include <linux/slab.h>

#define ARRAY_AND_SIZE(x)	(x), ARRAY_SIZE(x)
#define DRIVER_NAME "mars_core"
#define MARSDEV1_PREF "MARS-DEV1"

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Zex Li");
MODULE_DESCRIPTION("Mars dev1");
MODULE_ALIAS("Mars");
MODULE_ALIAS("mars_dev");

static struct file_operations mars_dev_ops;
static struct cdev *mars_cdev = NULL;
static dev_t mars_dev_nr;

static struct resource mars_dev1_res[] = {
    //ioport_resource,
    {
        .name   = "mars dev1 res",
        .start  = 0xFF223300,
        .end    = 0xFF2233FF,
        .flags  = IORESOURCE_MEM,
    },
};

static void mars_device_release(struct device *dev)
{
	struct platform_device *pa = container_of(dev, struct platform_device, dev);
    
    printk(KERN_INFO MARSDEV1_PREF" device release\n");

    //if (pa->dev.platform_data)
	    kfree(pa->dev.platform_data);
    //if (pa->resource)
	    kfree(pa->resource);
	
    kfree(pa);
}

/**
 * struct platform_device {
 * const char *name;
 * u32        id;
 * struct device dev;
 * u32          num_resources;
 * struct resource *resource;
 * }
 */
static struct platform_device mars_dev1 = {
    .name   = DRIVER_NAME,
    .id     = 0,
    .num_resources  = ARRAY_SIZE(mars_dev1_res),
    .resource       = mars_dev1_res,
	.dev.release    = mars_device_release,
};

static struct platform_device* mars_devices[] = {
    &mars_dev1,
};

static int marsdev_init(void)
{
    int ret;

    printk(KERN_INFO MARSDEV1_PREF" init\n");
//    struct platform_device *platform_device_alloc(const char *name, int id)
    platform_add_devices(ARRAY_AND_SIZE(mars_devices));

    ret = 1;//alloc_chrdev_region(&mars_dev_nr, 1, 1, "mars-dev");

    if (0 > ret)
    {
        printk(KERN_ERR MARSDEV1_PREF" alloc cdev failed\n");
    }
    else
    {
        //register_chrdev_region(mars_dev_nr, 1, "mars-dev");
        //mars_cdev = cdev_alloc();
        //cdev_init(mars_cdev, &mars_dev_ops);
        mars_dev_nr = __register_chrdev(0, 1, 1, "mars-dev", &mars_dev_ops);
    }

    return 0;
}

static void marsdev_cleanup(void)
{
    int i;
	int dev_sz = ARRAY_SIZE(mars_devices);

    printk(KERN_INFO MARSDEV1_PREF" cleanup\n");

	for (i = 0; i < dev_sz; i++) {
	    platform_device_unregister(mars_devices[i]);
    }

    //if (mars_cdev)
    //    cdev_del(mars_cdev);
    //
    //unregister_chrdev_region(mars_dev_nr, 1);
    __unregister_chrdev(mars_dev_nr, 1, 1, "mars-dev");
}

module_init(marsdev_init);
module_exit(marsdev_cleanup);

static int mars_open (struct inode *node, struct file *fd)
{
    printk(KERN_INFO MARSDEV1_PREF" open\n");
    return 0;
}

static ssize_t mars_read (struct file *fd, char __user *user, size_t sz, loff_t *offs)
{
    printk(KERN_INFO MARSDEV1_PREF" read\n");
    return 0;
}

static ssize_t mars_write (struct file *fd, const char __user *user, size_t sz, loff_t *offs)
{
    printk(KERN_INFO MARSDEV1_PREF" write\n");
    return 0;
}

static int mars_release (struct inode *node, struct file *fd)
{
    printk(KERN_INFO MARSDEV1_PREF" release\n");
    return 0;
}

static struct file_operations mars_dev_ops = {
    .owner      = THIS_MODULE,
    .open       = mars_open,
    .read       = mars_read,
    .write      = mars_write,
    .release    = mars_release,
    .llseek     = no_llseek,
};
//EXPORT_SYMBOL_GPL(mars_dev_ops);

//static struct miscdevice mars_dev1 = {
//    .minor      = MISCS_DYNAMIC_MINOR,
//    .name       = "mars-dev1",
//    .fops       = &mars_dev_ops,
//};

