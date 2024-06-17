#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/reed_solomon.h>


MODULE_LICENSE("GPL");
MODULE_AUTHOR("allenliao666");
MODULE_DESCRIPTION("A Reed-Solomon Test module");

static int __init rsdrv_init(void)
{
    printk(KERN_INFO "rscode test module init\n");
    return 0;
}

static void __exit rsdrv_exit(void)
{
    printk(KERN_INFO "rscode test module exit\n");
    return;
}

module_init(chrdev_init);
module_exit(chrdev_exit);
