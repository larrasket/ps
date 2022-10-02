// source:
// https://github.com/athultr1997/OS/blob/master/os_concepts_abraham_silberschatz/chapter_2/programming_projects/linux_kernel_modules/simple.c
#include <linux/init.h>
#include <linux/kernel.h>
#include <linux/list.h> // for list data structure
#include <linux/module.h>
#include <linux/slab.h>  // for kmalloc
#include <linux/types.h> // for list_head

struct birthday {
  int day;
  int month;
  int year;
  struct list_head list;
};

static LIST_HEAD(birthday_list);

/* This function is called when the module is loaded. */
int simple_init(void) {
  printk(KERN_INFO "Loading Module\n");

  struct birthday *person1;
  person1 = kmalloc(sizeof(*person1), GFP_KERNEL);
  person1->day = 2;
  person1->month = 6;
  person1->year = 1989;
  INIT_LIST_HEAD(&person1->list);
  list_add_tail(&person1->list, &birthday_list);

  struct birthday *person2;
  person2 = kmalloc(sizeof(*person2), GFP_KERNEL);
  person2->day = 4;
  person2->month = 8;
  person2->year = 1978;
  INIT_LIST_HEAD(&person2->list);
  list_add_tail(&person2->list, &birthday_list);

  struct birthday *person3;
  person3 = kmalloc(sizeof(*person3), GFP_KERNEL);
  person3->day = 15;
  person3->month = 2;
  person3->year = 1964;
  INIT_LIST_HEAD(&person3->list);
  list_add_tail(&person3->list, &birthday_list);

  struct birthday *ptr;
  int count = 1;
  list_for_each_entry(ptr, &birthday_list, list) {
    printk(KERN_INFO "birthday %d : day = %d; month = %d; year = %d\n", count,
           ptr->day, ptr->month, ptr->year);
    ++count;
  }

  return 0;
}

/* This function is called when the module is removed. */
void simple_exit(void) {
  printk(KERN_INFO "Removing Module\n");

  struct birthday *ptr, *next;

  int count = 1;
  list_for_each_entry_safe(ptr, next, &birthday_list, list) {
    printk(
        KERN_INFO
        "birthday %d : day = %d; month = %d; year = %d is being removed...\n",
        count, ptr->day, ptr->month, ptr->year);
    list_del(&ptr->list);
    kfree(ptr);
    ++count;
  }
}

/* Macros for registering module entry and exit points. */
module_init(simple_init);
module_exit(simple_exit);

MODULE_LICENSE("GPL");
MODULE_DESCRIPTION("Simple Module");
MODULE_AUTHOR("Athul T R");
