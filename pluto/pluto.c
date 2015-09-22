/** Pluto module
 *
 * Author: Zex Li <top_zlynch AT yahoo.com>
 */
#include <linux/init.h>
#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/miscdevice.h>
#include <linux/fs.h>
#include <linux/poll.h>

MODULE_LICENSE("MIT");
MODULE_AUTHOR("Zex Li");
MODULE_DESCRIPTION("pluto");

static char *home = "UNIVERSE";
module_param(home, charp, true);

static long distance = 9876543;
module_param(distance, long, true);

#define PLUTO_PREF "[Pluto]"

int pluto_init(void)
{
    printk(KERN_INFO PLUTO_PREF" entering ...\n");

    if (home)
    {
        printk(PLUTO_PREF" home=%s", home);
    }

    printk(PLUTO_PREF" distance=%li", distance);

    return 0;
}

void pluto_cleanup(void)
{
    printk(KERN_INFO "[Pluto] leaving ...\n");
}


static ssize_t pluto_read(struct file *file, char __user *buf,
			size_t count, loff_t *ppos)
{
    printk(KERN_INFO "[Pluto] reading ...\n");
    return 0;
}

static ssize_t pluto_write (struct file *file, const char __user *buf, size_t count, loff_t *ppos)
{
    printk(KERN_INFO "[Pluto] writing ...\n");
    return 0;
}

static unsigned int pluto_poll(struct file *file, poll_table *wait)
{
    printk(KERN_INFO "[Pluto] polling ...\n");
    return 0;
}

static int pluto_release(struct inode *inode, struct file *file)
{
    printk(KERN_INFO "[Pluto] releasing ...\n");
    return 0;
}

static int pluto_fasync(int fd, struct file *filp, int on)
{
    printk(KERN_INFO "[Pluto] fasync ...\n");
    return 0;
}

static long pluto_ioctl(struct file *file, unsigned int cmd, unsigned long arg)
{
    printk(KERN_INFO "[Pluto] ioctl ...\n");
    return 0;
}

static int pluto_open(struct inode *inode, struct file *file)
{
    printk(KERN_INFO "[Pluto] open ...\n");
    return 0;
}

static const struct file_operations pluto_fops = {
	.owner		= THIS_MODULE,
	.llseek		= no_llseek,
	.read		= pluto_read,
	.write		= pluto_write,
	.poll		= pluto_poll,
	.unlocked_ioctl	= pluto_ioctl,
	.open		= pluto_open,
	.release	= pluto_release,
	.fasync		= pluto_fasync,
};

static struct miscdevice __attribute__ ((unused)) pluto_dev = {
	.minor		= MISC_DYNAMIC_MINOR,
	.name		= "pluto",
	.fops		= &pluto_fops,
};

module_init(pluto_init);
module_exit(pluto_cleanup);


