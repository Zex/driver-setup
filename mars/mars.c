/** Mars module
 *
 * Author: Zex Li <top_zlynch AT yahoo.com>
 */
#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/platform_device.h>

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Zex Li");
MODULE_DESCRIPTION("Mars moddule");
MODULE_ALIAS("Mars");
MODULE_ALIAS("mars_typing");

#define DRIVER_NAME "mars_typing"

static int mars_probe(struct platform_device *pdev)
{
    printk(KERN_INFO "MARS probe\n");
    return  0;
}

static int mars_remove(struct platform_device *pdev)
{
    printk(KERN_INFO "MARS remove\n");
    return 0;
}

static int mars_suspend(struct platform_device *dev, pm_message_t state)
{
    printk(KERN_INFO "MARS suspend\n");
    return 0;
}

static int mars_resume(struct platform_device *pdev)
{
    printk(KERN_INFO "MARS resume\n");
    return 0;
}

static const struct platform_device_id mars_id_table[] = {
    {"mars-mod", (kernel_ulong_t)0}, //mars_struct_type},
};

static struct platform_driver mars_driver = {
	.probe		= mars_probe,
	.remove		= mars_remove,
	.suspend	= mars_suspend,
	.resume		= mars_resume,
    .id_table   = mars_id_table,
	.driver		= {
		.name	= DRIVER_NAME,//"mars-typing",
        .owner  = THIS_MODULE,
	},
};
module_platform_driver(mars_driver);

//static struct platform_driver* devices [] = {
//    &mars_driver,
//};
//
//static int mars_init(void)
//{
//    printk(KERN_INFO "MARS init\n");
//    return platform_driver_register(&mars_driver);
//}
//
//static void mars_cleanup(void)
//{
//    printk(KERN_INFO "MARS cleanup\n");
//    platform_driver_unregister(&mars_driver);
//}

