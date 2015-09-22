/** Pluto module
 *
 * Author: Zex Li <top_zlynch AT yahoo.com>
 */
#include <linux/kernel.h>
#include <linux/modules.h>

MODULE_LICENSE("MIT");
MODULE_AUTHOR("Zex Li");
MODULE_DESCRIPTION("pluto.c");

static char *whom = "UNIVERSE";
module_param(whom, charp, 0);

static int howmany = 3;
module_param(howmany, int, 0);

int init_module(void)
{
    printk(KERN_INFO "[Pluto] entering ...\n");
}

void cleanup_module(void)
{
    printk(KERN_INFO "[Pluto] leaving ...\n");
}


static ssize_t pluto_read(struct file *file, char __user *buf,
			size_t count, loff_t *ppos);
{
    printk(KERN_INFO "[Pluto] reading ...\n");
    return 0;
}

static ssize_t pluto_write(struct file *file, char __user *buf,
			size_t count, loff_t *ppos);
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

static long pluto_ioctl(struct file *file, unsigned int cmd, unsigned long arg);
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
	.poll		= pluto_poll,
	.unlocked_ioctl	= pluto_ioctl,
	.open		= pluto_open,
	.release	= pluto_release,
	.fasync		= pluto_fasync,
};

static struct miscdevice rtc_dev = {
	.minor		= RTC_MINOR,
	.name		= "pluto",
	.fops		= &pluto_fops,
};

module_init(init_module);
module_exit(cleanup_module);


