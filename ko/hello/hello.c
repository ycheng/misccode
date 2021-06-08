// #include  /* pr_info 所需 include 檔案*/
// #include 
// #include  /* 所有 module 需要檔案*/
// #include 

#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/init.h>
#include <linux/pci.h>

MODULE_DESCRIPTION("Hello World !!");
MODULE_AUTHOR("Bo-Yi Wu ");
MODULE_LICENSE("GPL");

static int __init hello_init(void){
    printk(KERN_INFO "This is hello_module, welcome to Linux kernel \n");
    // pr_info("The process is \"%s\" (pid %i)\n", current->comm, current->pid);
    return 0; 
}

static void __exit hello_exit(void){
    printk(KERN_INFO "see you next time!\n"); 
}


struct pci_device_id nv_pci_table[] = {
    {
        .vendor      = PCI_VENDOR_ID_NVIDIA,
        .device      = PCI_ANY_ID,
        .subvendor   = PCI_ANY_ID,
        .subdevice   = PCI_ANY_ID,
        .class       = (PCI_CLASS_DISPLAY_VGA << 8),
        .class_mask  = ~0
    },
    { }
};

module_init(hello_init);
module_exit(hello_exit);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Mr Q");
MODULE_DESCRIPTION("hello kernel module");

// alias: define directly
// MODULE_ALIAS("hello"); 

// alias: define by macro
MODULE_DEVICE_TABLE(pci, nv_pci_table); 

// static int __init hello_init(void)
// {
//     pr_info("Hello, world\n");
//     pr_info("The process is \"%s\" (pid %i)\n", current->comm, current->pid);
//     return 0;
// }
