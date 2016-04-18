#define WORD 32
#define SHIFT 5 //移动5个位，左移相当于乘以32,右移除以32
#define MASK 0x1f //16进制下的31
#define N 1000000

int bitmap[1+N/WORD];
/*
 *置位函数用“|”操作符，i&MASK相当于mod操作
 *m mod n运算，当n=2的x次幂时（即除了最高位都为1)
 *m mod n=m&(n-1)
 */
void set(int i)
{
	bitmap[i>>SHIFT] |= (1<<(i&MASK));
}

/*清除位操作，用&~操作符*/
void clear(int i)
{
	bitmap[i>>SHIFT] &= ~(1<<(i&MASK));
}

/*测试位操作用&操作符*/
int test(int i)
{
	return bitmap[i>>SHIFT]&(1<<(i&MASK));
}
