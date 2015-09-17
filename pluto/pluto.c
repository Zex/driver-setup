/** Pluto module
 *
 * Author: Zex Li <top_zlynch AT yahoo.com>
 */
#include <linux/kernel.h>
#include <linux/modules.h>

int init_module(void)
{
    printk(KERN_INFO "[Pluto] entering ...\n");
}

void cleanup_module(void)
{
    printk(KERN_INFO "[Pluto] leaving ...\n");
}

