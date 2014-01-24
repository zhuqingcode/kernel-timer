#include <linux/module.h>
#include <linux/errno.h>
#include <linux/miscdevice.h>
#include <linux/fcntl.h>
#include <linux/semaphore.h>
#include <linux/init.h>
#include <linux/delay.h>
#include <linux/proc_fs.h>
#include <linux/workqueue.h>
#include <linux/timer.h> // for timer_list API
#include <linux/param.h> // for HZ 
#include <linux/jiffies.h> // for jiffies
#include <asm/uaccess.h>
#include <asm/system.h>
#include <asm/io.h>

static struct timer_list ext_wdt_timer;

static void ext_wdt_handler(unsigned long time) {
	//printk("ext_wdt works well\n");
	mod_timer(&ext_wdt_timer, jiffies + msecs_to_jiffies(1000));
	return;
}	

static void ext_wdt_timer_setup(unsigned char ntime) {
	/*** Initialize the timer structure***/
	init_timer(&ext_wdt_timer) ;
	ext_wdt_timer.function = ext_wdt_handler;
	ext_wdt_timer.expires = jiffies + HZ * ntime; //HZ = 100
	add_timer(&ext_wdt_timer);
	/***Initialisation ends***/
	return;
}


static int __init ext_wdt_init(void) {
	unsigned char ntime;

	ntime = 1;//1s
	ext_wdt_timer_setup(ntime);
	printk("init ext_wdt ok\n");
	return 0;         
}


static void __exit ext_wdt_exit(void) {
    del_timer_sync(&ext_wdt_timer);
}

module_init(ext_wdt_init);
module_exit(ext_wdt_exit);

MODULE_AUTHOR("zhuqing@njtalent.cn");
MODULE_LICENSE("GPL");
MODULE_DESCRIPTION("extend wdt for hi3520d");




