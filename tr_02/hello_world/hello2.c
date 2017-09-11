#include <linux/init.h>
#include <linux/module.h>
#include <linux/moduleparam.h>
#include <linux/printk.h>
#include <linux/types.h>
#include "hello1.h"

MODULE_AUTHOR("Yuriy Mysan <yuramysan@gmail.com");
MODULE_DESCRIPTION("Hello, world in Linux Kernel Training");
MODULE_LICENSE("Dual BSD/GPL");

extern void print_hello(void);

static uint counter = 1;
module_param(counter, uint, S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP);
MODULE_PARM_DESC(counter, "uint counter");


void print_goodbye(void) 
{
    printk(KERN_EMERG "Good bye!\n");
}

static int __init hello_init(void)
{   
    BUG_ON(counter > 10);
    WARN_ON(counter == 0);

    if (counter == 5) 
    {
	return -EINVAL;
    }
    else if (counter > 0 && counter < 10) 
    {
        uint i = 0;
        for (i = 0; i < counter; i++)
        {
            print_hello();
        }
    }
    return 0;
}

static void __exit hello_exit(void)
{
    print_goodbye();
}

module_init(hello_init);
module_exit(hello_exit);
