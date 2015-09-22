/** Pluto module
 *
 * Author: Zex Li <top_zlynch AT yahoo.com>
 */
#include <linux/module.h>
#include <linux/init.h>
#include <linux/miscdevice.h>
#include <linux/proc_fs.h>
#include <linux/fs.h>
#include <linux/kernel.h>
#include <linux/seq_file.h>
#include <linux/poll.h>

MODULE_LICENSE("MIT");
MODULE_AUTHOR("Zex Li");
MODULE_DESCRIPTION("pluto");
MODULE_INFO(plutoinfo, "DEADBEEF");

static char *home = "UNIVERSE";
module_param(home, charp, true);

static long distance = 9876543;
module_param(distance, long, true);

#define PLUTO_PREF "[Pluto]"

static const struct file_operations pluto_fops;
static struct miscdevice __attribute__ ((unused)) pluto_dev;
#ifdef CONFIG_PROC_FS
static const struct file_operations pluto_proc_fops;
#endif

int pluto_init(void)
{
#ifdef CONFIG_PROC_FS
	struct proc_dir_entry *ent;
#endif
    printk(KERN_INFO PLUTO_PREF" entering ...\n");

    if (home)
    {
        printk(PLUTO_PREF" home=%s\n", home);
    }

    printk(PLUTO_PREF" distance=%li\n", distance);

	if (misc_register(&pluto_dev))
    {
        printk(PLUTO_PREF" misc_register failed\n");
    }

#ifdef CONFIG_PROC_FS
	ent = proc_create("driver/pluto", 0, NULL, &pluto_proc_fops);

	if (!ent)
    {
		printk(KERN_WARNING PLUTO_PREF" Failed to register with procfs.\n");
    }
#endif

    return 0;
}

void pluto_cleanup(void)
{
    printk(KERN_INFO PLUTO_PREF" leaving ...\n");

	remove_proc_entry("driver/pluto", NULL);
	misc_deregister(&pluto_dev);
}


static ssize_t pluto_read(struct file *file, char __user *buf,
			size_t count, loff_t *ppos)
{
    printk(KERN_INFO PLUTO_PREF" reading ...\n");
    return 0;
}

static ssize_t pluto_write (struct file *file, const char __user *buf, size_t count, loff_t *ppos)
{
    printk(KERN_INFO PLUTO_PREF" writing ...\n");
    return 0;
}

static unsigned int pluto_poll(struct file *file, poll_table *wait)
{
    printk(KERN_INFO PLUTO_PREF" polling ...\n");
    return 0;
}

static int pluto_release(struct inode *inode, struct file *file)
{
    printk(KERN_INFO PLUTO_PREF" releasing ...\n");
    return 0;
}

static int pluto_fasync(int fd, struct file *filp, int on)
{
    printk(KERN_INFO PLUTO_PREF" fasync ...\n");
    return 0;
}

static long pluto_ioctl(struct file *file, unsigned int cmd, unsigned long arg)
{
    printk(KERN_INFO PLUTO_PREF" ioctl ...\n");
    return 0;
}

static int pluto_open(struct inode *inode, struct file *file)
{
    printk(KERN_INFO PLUTO_PREF" open ...\n");
    return 0;
}

static int pluto_proc_open (struct inode *inode, struct file *file)
{
    printk(KERN_INFO PLUTO_PREF" proc open ...\n");
    return 0;
}

static ssize_t pluto_proc_read(struct file *file, char __user *buf,
			size_t count, loff_t *ppos)
{
    printk(KERN_INFO PLUTO_PREF" proc reading ...\n");
    return 0;
}

static int pluto_proc_release(struct inode *inode, struct file *file)
{
    printk(KERN_INFO PLUTO_PREF" proc releasing ...\n");
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

static struct miscdevice pluto_dev = {
	.minor		= MISC_DYNAMIC_MINOR,
	.name		= "pluto",
	.fops		= &pluto_fops,
};

#ifdef CONFIG_PROC_FS
static const struct file_operations pluto_proc_fops = {
	.owner		= THIS_MODULE,
	.open		= pluto_proc_open,
	.read		= pluto_proc_read,//seq_read,
	.llseek		= no_llseek,//seq_lseek,
	.release	= pluto_proc_release,//single_release,
};
#endif

module_init(pluto_init);
module_exit(pluto_cleanup);


