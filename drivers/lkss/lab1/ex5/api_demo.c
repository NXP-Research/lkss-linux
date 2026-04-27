// SPDX-License-Identifier: GPL-2.0
/*
 * LKSS Lab 1 - Exercise 5: Kernel API demo
 *
 * Skeleton module demonstrating kmalloc, kernel timers, and spinlocks.
 * A periodic timer increments a shared counter protected by a spinlock.
 */

#include <linux/module.h>
#include <linux/init.h>
#include <linux/slab.h>
#include <linux/timer.h>
#include <linux/spinlock.h>

struct api_demo {
	u32 count;
	struct timer_list timer;
};

static struct api_demo *g_demo;
static DEFINE_SPINLOCK(counter_lock);

static void tick_callback(struct timer_list *t)
{
	/* TODO 5.4a: acquire counter_lock with spin_lock_irqsave();
	 * save IRQ state in a local 'unsigned long flags' variable */

	/* TODO 5.4b: increment g_demo->count */

	/* TODO 5.4c: release counter_lock with spin_unlock_irqrestore() */

	/* TODO 5.4d: print the current value of g_demo->count with pr_info() */

	/* TODO 5.4e: re-arm the timer for one second from now using mod_timer() */
}

static int __init api_demo_init(void)
{
	/* TODO 5.2: allocate sizeof(*g_demo) bytes with kmalloc() using
	 * the GFP flag suitable for a module init function; store the result in
	 * g_demo; return -ENOMEM if the allocation fails.
	 * Then print the allocated size with pr_info(). */

	/* TODO 5.3: call timer_setup() to initialise g_demo->timer and
	 * bind it to tick_callback(); then call mod_timer() to schedule the first
	 * tick one second from now (jiffies + HZ). */

	return 0;
}

static void __exit api_demo_exit(void)
{
	/* TODO 5.5a: call del_timer_sync() to stop the timer */

	/* TODO 5.5b: free g_demo with kfree() */
}

module_init(api_demo_init);
module_exit(api_demo_exit);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("NXP Linux Kernel Summer School");
MODULE_DESCRIPTION("Kernel API demo: kmalloc, timer, spinlock");
