#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/rslib.h>


MODULE_LICENSE("GPL");
MODULE_AUTHOR("allenliao666");
MODULE_DESCRIPTION("A Reed-Solomon Test module");

static int __init rsdrv_init(void)
{
    struct rs_control *rs;
    uint8_t data[223];
    uint16_t parity[32];
    int no_error;
    int i;

    //initialize a rs_control structure
    rs = init_rs(8, 0x11d, 0, 1, 32);
    if(!rs) {
        printk(KERN_ERR "Failed to initialize rs_control structure\n");
	return -ENOMEM;
    }

   //fill data
   for (i = 0; i < 223; i++) {
        data[i] = i+1;
    }
    
    memset(parity, 0, sizeof(parity));
    
    //encode codewords
    encode_rs8(rs, data, 223, parity, 0);
    printk(KERN_INFO "Parity: ");
    for (i = 0; i < 32; i++) {
        printk(KERN_CONT "%02x ", parity[i]);
    }
    printk(KERN_CONT "\n");

    //make some errors
    for (i = 0; i < 16; i++) {
        data[i] = 255;
    }

/*    printk(KERN_INFO "Codewords: ");
    for (i = 0; i < 223; i++) {
        printk(KERN_CONT "%02x ", data[i]);
    }
*/
    //decode codewords 
    no_error = decode_rs8(rs, data, parity, 223, NULL, 0,NULL, 0, NULL);
    if (no_error < 0) {
        printk(KERN_ERR "Failed to decode Reed-Solomon data\n");
    } else {
        printk(KERN_INFO "Number of erroes:%d\n", no_error);
        printk(KERN_INFO "Decode codewords successfully\n");
    }

    //free rs_control structure
    free_rs(rs);
    return 0;
}

static void __exit rsdrv_exit(void)
{
    printk(KERN_INFO "Remove rscode test module \n");
    return;
}

module_init(rsdrv_init);
module_exit(rsdrv_exit);
