#include <linux/module.h>
#include <linux/moduleparam.h>

#define MODULE_DES "Bai 2 Do Tuan Anh"
int arr[1000];
int arr_length = 0;
module_param_array(arr, int, &arr_length, S_IRUGO | S_IWUSR);

void MIN_MAX(void)
{
    int i, min = arr[0], max = arr[0];
    for (i = 0; i < arr_length; i++)
    {
        if (min > arr[i])
        {
            min = arr[i];
        }
        if (max < arr[i])
        {
            max = arr[i];
        }
    }
    printk("MIN: %d\nMAX: %d\n", min, max);
}

void AVG(void)
{
    int s = 0, i;
    for (i = 0; i < arr_length; i++)
    {
        s += arr[i];
    }
    printk("trung binh cong la: %d\n", s / arr_length);
}

static int md_init(void)
{
    printk("init module\n");
    MIN_MAX();
    AVG();
    return 0;
}

static void md_exit(void)
{
    printk("exit module\n");
}

module_init(md_init);
module_exit(md_exit);

MODULE_LICENSE("GPL");
MODULE_DESCRIPTION(MODULE_DES);