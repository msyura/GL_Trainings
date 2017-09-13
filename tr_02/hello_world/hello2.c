#include <linux/init.h>
#include <linux/module.h>
#include <linux/moduleparam.h>
#include <linux/printk.h>
#include <linux/types.h>
#include <linux/slab.h>
#include "hello1.h"

MODULE_AUTHOR("Yuriy Mysan <yuramysan@gmail.com");
MODULE_DESCRIPTION("Hello, world in Linux Kernel Training");
MODULE_LICENSE("Dual BSD/GPL");

extern void print_hello(void);

static uint nr_print = 1;
module_param(nr_print, uint, S_IRUSR | S_IWUSR);
MODULE_PARM_DESC(nr_print, "Print hello number");


void print_goodbye(void)
{
	pr_emerg("Good bye!\n");
}

static int __init hello_init(void)
{
	BUG_ON(nr_print > 10);
	WARN_ON(nr_print == 0);
	if (nr_print == 5) {
		return -EINVAL;
	} else {
		if (nr_print > 0 && nr_print < 10) {
			uint i = 0;

			for (i = 0; i < nr_print; i++)
				print_hello();
		}
	}

	if (nr_print == 2)
		try_module_get(THIS_MODULE);

	return 0;
}

static void __exit hello_exit(void)
{
	if (nr_print == 3) {
		u8 *pU8 = __kmalloc(1, GFP_KERNEL);
		*pU8 = 0x90;
	}
	print_goodbye();
}

module_init(hello_init);
module_exit(hello_exit);
