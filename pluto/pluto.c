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

module_init(init_module);
module_exit(cleanup_module);


