// #include  /* pr_info 所需 include 檔案*/
// #include 
// #include  /* 所有 module 需要檔案*/
// #include 

#include <linux/module.h>
#include <linux/kernel.h>
// #include <linux/init.h>

MODULE_DESCRIPTION("Hello World !!");
MODULE_AUTHOR("Bo-Yi Wu ");
MODULE_LICENSE("GPL");

static int __init hello_init(void){
    printk("This is hello_module, welcome to Linux kernel \n");
    // pr_info("The process is \"%s\" (pid %i)\n", current->comm, current->pid);
    return 0; 
}

static void __exit hello_exit(void){
    printk("see you next time!\n"); 
}

module_init(hello_init);
module_exit(hello_exit);
MODULE_LICENSE("GPL");
MODULE_AUTHOR("Mr Q");
MODULE_DESCRIPTION("hello kernel module");
MODULE_ALIAS("hello");




// static int __init hello_init(void)
// {
//     pr_info("Hello, world\n");
//     pr_info("The process is \"%s\" (pid %i)\n", current->comm, current->pid);
//     return 0;
// }

// static void __exit hello_exit(void)
// {
//     printk(KERN_INFO "Goodbye\n");
// }

// module_init(hello_init);
// module_exit(hello_exit);
