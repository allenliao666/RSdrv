#include <linux/module.h>
#include <linux/kernel.h>

MODULE_LICENSE("GPL");
MODULE_AUTHOR("allenliao666");

static int __init chrdev_init(void)
{
	printk(KERN_INFO "rscode test module init\n");
	return 0;
}

static void __exit chrdev_exit(void)
{
	printk(KERN_INFO "escode test module exit\n");
	return;
}

module_init(chrdev_init);
module_exit(chrdev_exit);
