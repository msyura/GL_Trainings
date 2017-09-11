#include <linux/init.h>
#include <linux/module.h>
#include <linux/printk.h>
#include "hello1.h"

MODULE_AUTHOR("Yuriy Mysan <yuramysan@gmail.com");
MODULE_DESCRIPTION("Hello, world in Linux Kernel Training");
MODULE_LICENSE("Dual BSD/GPL");

extern void print_hello(void);

void print_goodbye(void) 
{
    printk(KERN_EMERG "Good bye!\n");
}

static int __init hello_init(void)
{    
    print_hello();
    return 0;
}

static void __exit hello_exit(void)
{
    print_goodbye();
}

module_init(hello_init);
module_exit(hello_exit);
