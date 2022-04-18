#include <linux/module.h>

#define MODULE_DES "Bai 3 Do Tuan Anh"
int width = 0;
module_param(width, int, S_IRUGO | S_IWUSR);

int heigh = 0;
module_param(heigh, int, S_IRUGO | S_IWUSR);

int matrix[1000];
module_param_array(matrix, int, NULL, S_IRUGO | S_IWUSR);

void TONG(void)
{
    int i, j, s = 0;
    for (i = 0; i < heigh; i++)
    {
        for (j = 0; j < width; j++)
        {
            s += matrix[i * width + j];
        }
    }
    printk("TOng: %d\n", s);
}

void FILLTER(void)
{
    int N = 0, P = 0, i, j;
    for (i = 0; i < heigh; i++)
    {
        for (j = 0; j < width; j++)
        {
            if (matrix[i * width + j] > 0)
            {
                P++;
            }
            if (matrix[i * width + j] < 0)
            {
                N++;
            }
        }
    }
    printk("DUONG: %d\n", P);
    printk("AM: %d\n", N);
}

void DUONGCHEO(void)
{
    int min = matrix[0], max = matrix[0], i, diagonal;
    diagonal = (width < heigh) ? width : heigh;
    for (i = 0; i < diagonal; i++)
    {
        if (min > matrix[i * width + i])
        {
            min = matrix[i * width + i];
        }
        if (max < matrix[i * width + i])
        {
            max = matrix[i * width + i];
        }
    }
    printk("NHO NHAT CHINH: %d\n", min);
    printk("LON NHAT CHINH: %d\n", max);

    min = matrix[width - 1];
    max = matrix[width - 1];
    for (i = 0; i < diagonal; i++)
    {
        if (min > matrix[i * width + width - i - 1])
        {
            min = matrix[i * width + width - i - 1];
        }
        if (max < matrix[i * width + width - i - 1])
        {
            max = matrix[i * width + width - i - 1];
        }
    }
    printk("NHO NHAT PHU: %d\n", min);
    printk("LON NHAT PHU: %d\n", max);
}

void CHANLE(void)
{
    int ood = 0, even = 0, i, j;
    for (i = 0; i < heigh; i++)
    {
        for (j = 0; j < width; j++)
        {
            if (matrix[i * width + j] % 2 == 0)
            {
                ood += matrix[i * width + j];
            }
            else
            {
                even += matrix[i * width + j];
            }
        }
    }
    printk("CHAN: %d\n", ood);
    printk("LE: %d\n", even);
}

static int md_init(void)
{
    printk("init module\n");
    TONG();
    FILLTER();
    DUONGCHEO();
    CHANLE();
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
