/** Venus module
 *
 * Author: Zex Li <top_zlynch AT yahoo.com>
 */
#include <linux/module.h>
#include <linux/init.h>
#include <linux/proc_fs.h>
#include <linux/fs.h>
#include <linux/kernel.h>
#include <linux/seq_file.h>
#include <linux/relay.h>
#include <linux/debugfs.h>

MODULE_LICENSE("Dual MIT/GPL");
MODULE_AUTHOR("Zex Li");
MODULE_DESCRIPTION("The venus module");
MODULE_INFO(venusinfo, "DEADBEEF");
MODULE_ALIAS("VENUS");
MODULE_ALIAS("venus_module");

#define VENUS_PREF "[Venus]"

static char *rchan_name = "venusrchan";
module_param(rchan_name, charp, S_IRWXU|S_IRGRP);
MODULE_PARM_DESC(rchan_name, "Name of relay channel in userspace");

static int subbuf_size = 512;
module_param(subbuf_size, byte, S_IRWXU|S_IRGRP);
MODULE_PARM_DESC(subbuf_size, "Subbuffer size of relay channel");

static int subbuf_nr = 8;
module_param(subbuf_nr, byte, S_IRWXU|S_IRGRP);
MODULE_PARM_DESC(subbuf_nr, "Number of subbuffer");

static const struct file_operations venus_fops;

#ifdef CONFIG_PROC_FS
static const struct file_operations venus_proc_fops;
#endif

#ifdef CONFIG_RELAY
static struct rchan *venus_rchan = NULL;
static const struct file_operations venus_relay_fops;

static ssize_t venus_relay_read(struct file *file, char __user *buf,
			size_t count, loff_t *ppos)
{
    printk(KERN_INFO VENUS_PREF" reading ...\n");
    return 0;
}

static ssize_t venus_relay_write (struct file *file, const char __user *buf, size_t count, loff_t *ppos)
{
    printk(KERN_INFO VENUS_PREF" writing ...\n");
    return 0;
}

static unsigned int venus_relay_poll(struct file *file, poll_table *wait)
{
    printk(KERN_INFO VENUS_PREF" polling ...\n");
    return 0;
}

static int venus_relay_release(struct inode *inode, struct file *file)
{
    printk(KERN_INFO VENUS_PREF" releasing ...\n");
    return 0;
}

static int venus_relay_fasync(int fd, struct file *filp, int on)
{
    printk(KERN_INFO VENUS_PREF" fasync ...\n");
    return 0;
}

static long venus_relay_ioctl(struct file *file, unsigned int cmd, unsigned long arg)
{
    unsigned long buffer_kern = 0;

    printk(KERN_INFO VENUS_PREF" relay ioctl ...\n");

    if (copy_from_user(&buffer_kern, &arg, sizeof(arg)))
    {
        printk(KERN_ERR VENUS_PREF" copy_from_user failed\n");
    }
    else
    {
        printk(KERN_INFO VENUS_PREF" copy_from_user done\n");
    }

    return 0;
}

static int venus_relay_open(struct inode *inode, struct file *file)
{
    printk(KERN_INFO VENUS_PREF" open ...\n");
    return 0;
}

static const struct file_operations venus_relay_fops = {
	.owner		= THIS_MODULE,
	.llseek		= no_llseek,
	.read		= venus_relay_read,
	.write		= venus_relay_write,
	.poll		= venus_relay_poll,
	.unlocked_ioctl	= venus_relay_ioctl,
	.open		= venus_relay_open,
	.release	= venus_relay_release,
	.fasync		= venus_relay_fasync,
};

struct dentry* venus_create_buf_file (const char *filename,
	  struct dentry *parent, umode_t mode,
	  struct rchan_buf *buf, int *is_global)
{
    printk(KERN_INFO VENUS_PREF" create buf file\n");

    return debugfs_create_file(filename, mode, NULL, NULL,
            &venus_relay_fops);
}

static int venus_remove_buf_file(struct dentry *dentry)
{
    printk(KERN_INFO VENUS_PREF" remove buf file\n");

    debugfs_remove(dentry);
    return 0;
}

static int venus_subbuf_start(struct rchan_buf *buf,
    void *subbuf, void *prev_subbuf, size_t prev_padding)
{
    printk(KERN_INFO VENUS_PREF" subbuf start\n");
    return 0;
}

static struct rchan_callbacks venus_relay_cb = {
    .create_buf_file = venus_create_buf_file,
    .remove_buf_file = venus_remove_buf_file,
    .subbuf_start = venus_subbuf_start,
};
#endif

int venus_init(void)
{
    printk(KERN_INFO VENUS_PREF" entering ...\n");

    if (rchan_name)
    {
        printk(VENUS_PREF" relay channel=%s\n", rchan_name);
    }

#ifdef CONFIG_RELAY
    if (!(venus_rchan = relay_open(rchan_name, NULL,
        subbuf_size, subbuf_nr, &venus_relay_cb, NULL))) 
    {
        printk(KERN_ERR VENUS_PREF" relay open failed\n");
    }

#else
    printk(VENUS_PREF" relay channel not supported\n");
#endif    

    return 0;
}

void venus_cleanup(void)
{
    printk(KERN_INFO VENUS_PREF" leaving ...\n");

#ifdef CONFIG_RELAY
    relay_flush(venus_rchan);
    relay_close(venus_rchan);
#endif
}

static ssize_t venus_read(struct file *file, char __user *buf,
			size_t count, loff_t *ppos)
{
    printk(KERN_INFO VENUS_PREF" reading ...\n");
    return 0;
}

static ssize_t venus_write (struct file *file, const char __user *buf, size_t count, loff_t *ppos)
{
    printk(KERN_INFO VENUS_PREF" writing ...\n");
    return 0;
}

static unsigned int venus_poll(struct file *file, poll_table *wait)
{
    printk(KERN_INFO VENUS_PREF" polling ...\n");
    return 0;
}

static int venus_release(struct inode *inode, struct file *file)
{
    printk(KERN_INFO VENUS_PREF" releasing ...\n");
    return 0;
}

static int venus_fasync(int fd, struct file *filp, int on)
{
    printk(KERN_INFO VENUS_PREF" fasync ...\n");
    return 0;
}

static long venus_ioctl(struct file *file, unsigned int cmd, unsigned long arg)
{
    unsigned long buffer_kern = 0;

    printk(KERN_INFO VENUS_PREF" ioctl ...\n");

    printk(KERN_INFO VENUS_PREF" ioctl now: cmd:%u arg:%lu\n", 
             cmd, arg);


    if (copy_from_user(&buffer_kern, &arg, sizeof(arg)))
    {
        printk(KERN_ERR VENUS_PREF" copy_from_user failed\n");
    }
    else
    {
        printk(KERN_INFO VENUS_PREF" copy_from_user done\n");
    }

    return 0;
}

static int venus_open(struct inode *inode, struct file *file)
{
    printk(KERN_INFO VENUS_PREF" open ...\n");
    return 0;
}

#ifdef CONFIG_PROC_FS
static int venus_proc_open (struct inode *inode, struct file *file)
{
    printk(KERN_INFO VENUS_PREF" proc open ...\n");
    return 0;
}

static ssize_t venus_proc_read(struct file *file, char __user *buf,
			size_t count, loff_t *ppos)
{
    printk(KERN_INFO VENUS_PREF" proc reading ...\n");
    return 0;
}

static int venus_proc_release(struct inode *inode, struct file *file)
{
    printk(KERN_INFO VENUS_PREF" proc releasing ...\n");
    return 0;
}
#endif

static const struct file_operations venus_fops = {
	.owner		= THIS_MODULE,
	.llseek		= no_llseek,
	.read		= venus_read,
	.write		= venus_write,
	.poll		= venus_poll,
	.unlocked_ioctl	= venus_ioctl,
	.open		= venus_open,
	.release	= venus_release,
	.fasync		= venus_fasync,
};

#ifdef CONFIG_PROC_FS
static const struct file_operations venus_proc_fops = {
	.owner		= THIS_MODULE,
	.open		= venus_proc_open,
	.read		= venus_proc_read,//seq_read,
	.llseek		= no_llseek,//seq_lseek,
	.release	= venus_proc_release,//single_release,
};
#endif

module_init(venus_init);
module_exit(venus_cleanup);


