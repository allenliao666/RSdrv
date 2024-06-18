#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/rslib.h>


MODULE_LICENSE("GPL");
MODULE_AUTHOR("allenliao666");
MODULE_DESCRIPTION("A Reed-Solomon Test module");

static int __init rsdrv_init(void)
{
    struct rs_control *rs;
    unsigned char data[255];
    unsigned char parity[32];
    int eras_pos[32];
    int i;

    //initialize a rs_control structure
    rs = init_rs(8, 0x11d, 0, 1, 32);
    if(!rs) {
        printk(KERN_ERR "failed to initializw rs_control structure\n");
	return -ENOMEM;
    }    
    printk(KERN_INFO "rscode test module initialize\n");
    return 0;
}

static void __exit rsdrv_exit(void)
{
    printk(KERN_INFO "rscode test module exit\n");
    return;
}

module_init(rsdrv_init);
module_exit(rsdrv_exit);
