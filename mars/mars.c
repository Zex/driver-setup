/** Mars module
 *
 * Author: Zex Li <top_zlynch AT yahoo.com>
 */
#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/platform_device.h>

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Zex Li");
MODULE_DESCRIPTION("Mars core");
MODULE_ALIAS("Mars");
MODULE_ALIAS("mars_core");

#define DRIVER_NAME "mars_core"
#define MARSCORE_PREF "MARS-CORE"

static int mars_probe(struct platform_device *pdev)
{
    printk(KERN_INFO MARSCORE_PREF" probe\n");
    return  0;
}

static int mars_remove(struct platform_device *pdev)
{
    printk(KERN_INFO MARSCORE_PREF" remove\n");
    return 0;
}

static int mars_suspend(struct platform_device *dev, pm_message_t state)
{
    printk(KERN_INFO MARSCORE_PREF" suspend\n");
    return 0;
}

static int mars_resume(struct platform_device *pdev)
{
    printk(KERN_INFO MARSCORE_PREF" resume\n");
    return 0;
}

static const struct platform_device_id mars_id_table[] = {
    {"mars-mod", (kernel_ulong_t)0}, //mars_struct_type},
};

/**                                           name
 * platform_driver -> device -> device_driver/
 * platform_device -> device_driver\
 *                                  name
 */
static struct platform_driver mars_driver = {
	.probe		= mars_probe,
	.remove		= mars_remove,
	.suspend	= mars_suspend,
	.resume		= mars_resume,
    .id_table   = mars_id_table,
	.driver		= {
		.name	= DRIVER_NAME,
        .owner  = THIS_MODULE,
	},
};
//module_platform_driver(mars_driver);

//static struct platform_driver* devices [] = {
//    &mars_driver,
//};
//
static int mars_init(void)
{
    printk(KERN_INFO MARSCORE_PREF" init\n");
    return platform_driver_register(&mars_driver);
}

static void mars_cleanup(void)
{
    printk(KERN_INFO MARSCORE_PREF" cleanup\n");
    platform_driver_unregister(&mars_driver);
}

device_initcall(mars_init);
module_exit(mars_cleanup);

