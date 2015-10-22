/** Saturn module
 *
 * Author: Zex Li <top_zlynch AT yahoo.com>
 */
#include <linux/module.h>
#include <linux/poll.h>
#include <linux/init.h>
#include <linux/fs.h>
#include <linux/slab.h>
#include <linux/kernel.h>
#include <linux/dmi.h>

MODULE_LICENSE("Dual MIT/GPL");
MODULE_AUTHOR("Zex Li");
MODULE_DESCRIPTION("The saturn module");
MODULE_ALIAS("SATURN");
MODULE_ALIAS("saturn_module");

#define SATURN_PREF "[Saturn]"

static const struct file_operations saturn_fops;

int saturn_init(void)
{
    printk(KERN_INFO SATURN_PREF" entering ...\n");
    printk(KERN_INFO SATURN_PREF" BIOS VENDOR\n", dmi_get_system_info(DMI_BIOS_VENDOR));
    return 0;
}

void saturn_cleanup(void)
{
    printk(KERN_INFO SATURN_PREF" leaving ...\n");
}

static ssize_t saturn_read(struct file *file, char __user *buf,
			size_t count, loff_t *ppos)
{
    printk(KERN_INFO SATURN_PREF" reading ...\n");
    return 0;
}

static ssize_t saturn_write (struct file *file, const char __user *buf, size_t count, loff_t *ppos)
{
    printk(KERN_INFO SATURN_PREF" writing ...\n");
    return 0;
}

static unsigned int saturn_poll(struct file *file, poll_table *wait)
{
    printk(KERN_INFO SATURN_PREF" polling ...\n");
    return 0;
}

static int saturn_release(struct inode *inode, struct file *file)
{
    printk(KERN_INFO SATURN_PREF" releasing ...\n");
    return 0;
}

static int saturn_fasync(int fd, struct file *filp, int on)
{
    printk(KERN_INFO SATURN_PREF" fasync ...\n");
    return 0;
}

static long saturn_ioctl(struct file *file, unsigned int cmd, unsigned long arg)
{
    unsigned long buffer_kern = 0;

    printk(KERN_INFO SATURN_PREF" ioctl ...\n");

    printk(KERN_INFO SATURN_PREF" ioctl now: cmd:%u arg:%lu\n", 
             cmd, arg);


    if (copy_from_user(&buffer_kern, &arg, sizeof(arg)))
    {
        printk(KERN_ERR SATURN_PREF" copy_from_user failed\n");
    }
    else
    {
        printk(KERN_INFO SATURN_PREF" copy_from_user done\n");
    }

    return 0;
}

static int saturn_open(struct inode *inode, struct file *file)
{
    printk(KERN_INFO SATURN_PREF" open ...\n");
    return 0;
}

module_init(saturn_init);
module_exit(saturn_cleanup);


