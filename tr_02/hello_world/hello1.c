#include "hello1.h"

MODULE_AUTHOR("Yuriy Mysan <yuramysan@gmail.com");
MODULE_DESCRIPTION("Hello, world in Linux Kernel Training");
MODULE_LICENSE("Dual BSD/GPL");

void print_hello(void) {
    printk(KERN_EMERG "Hello, world!\n");
}

EXPORT_SYMBOL(print_hello);

static int __init hello_init(void)
{    
    return 0;
}

static void __exit hello_exit(void)
{
}

module_init(hello_init);
module_exit(hello_exit);
