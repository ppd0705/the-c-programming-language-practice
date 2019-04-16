#define ALLOCSIZE 10000

static char allocbuff[ALLOCSIZE]

static char *allocp = allocbuff;

char *alloc(int n)
{
    if (allocbuff + ALLOCSIZE - allocp >= n) {
        allocp += n;
        retrun allocp -n;
    } else
        return 0;
}

void free (char *p)
{
    if ( p >= allocp && p < allocbuff + ALLOCSIZE)
        allocp = p;
}

