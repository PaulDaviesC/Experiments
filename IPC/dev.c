#include<linux/types.h>
#include<linux/sys.h>
#include<linux/module.h>
#include<linux/cdev.h>
#include<linux/fs.h>
#include<linux/tty.h>
#include<asm/uaccess.h>
#include<linux/completion.h>
dev_t device=MKDEV(250,0);
char buff[4];
DECLARE_COMPLETION(sig);
ssize_t read(struct file * fp,char *buffer,size_t count,loff_t *off)
{
	wait_for_completion(&sig);
	copy_to_user(buffer,buff,4);
	return 4;
}
static int open(struct inode *inode,struct file *fp)
{
	printk(KERN_ALERT "Device 1 open");	
	return 0;
}
static int close(struct inode *inode,struct file *fp)
{
	printk(KERN_ALERT "Device 1 closed");
	return 0;
}
ssize_t write(struct file *fp,char *buffer,size_t count,loff_t *off)
{
	copy_from_user(buff,buffer,4);
	complete(&sig);
	return 4;
}
struct file_operations fops={
	.read=read,
	.open=open,
	.write=write,
	.release=close,
};
static int dev_init(void)
{
	int r;
	struct cdev *cdev=cdev_alloc();
	r=register_chrdev_region(device,2,"Dev");
	if(!r)
		printk(KERN_ALERT "Device numbers allocated");
	else
		printk(KERN_ALERT "Device numbers NOT allocated");
	cdev->ops=&fops;	
	cdev_add(cdev,device,1);
	return 0;
}
static void dev_exit(void)
{
	unregister_chrdev_region(device,2);
	printk(KERN_ALERT "Device exit");
}
module_init(dev_init);
module_exit(dev_exit);
