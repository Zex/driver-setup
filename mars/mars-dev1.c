/** Mars module
 *
 * Author: Zex Li <top_zlynch AT yahoo.com>
 */
#include <linux/module.h>
//#include <linux/init.h>
#include <linux/kernel.h>
#include <linux/platform_device.h>

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Zex Li");
MODULE_DESCRIPTION("Mars moddule");
MODULE_ALIAS("Mars");
MODULE_ALIAS("mars_typing");

#define ARRAY_AND_SIZE(x)	(x), ARRAY_SIZE(x)
#define DRIVER_NAME "mars_typing"

static struct resource mars_dev1_res[] = {
    //ioport_resource,
    {
        .name = "mars dev1 res",
        .start = 0xFF223300,
        .end = 0xFF2233FF,
        .flags = IORESOURCE_MEM,
    },
};

static struct platform_device mars_dev1 = {
    .name   = DRIVER_NAME,
    .id     = 0,
    .num_resources  = ARRAY_SIZE(mars_dev1_res),
    .resource       = mars_dev1_res,
};

static struct platform_device* mars_devices[] = {
    &mars_dev1,
};

static int marsdev_init(void)
{
    printk(KERN_INFO "MARS dev init\n");
    platform_add_devices(ARRAY_AND_SIZE(mars_devices));
    return 0;
}

static void marsdev_cleanup(void)
{
    int i;
	int dev_sz = ARRAY_SIZE(mars_devices);

    printk(KERN_INFO "MARS dev cleanup\n");

	for (i = 0; i < dev_sz; i++) {
	    platform_device_unregister(mars_devices[i]);
    }
}

module_init(marsdev_init);
module_exit(marsdev_cleanup);
