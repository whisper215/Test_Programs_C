#include <stdio.h>

#define _IOC_NRBITS 8
#define _IOC_TYPEBITS   8

/*
 * Let any architecture override either of the following before
  * including this file.
   */

#ifndef _IOC_SIZEBITS
# define _IOC_SIZEBITS  14
#endif

#ifndef _IOC_DIRBITS
# define _IOC_DIRBITS   2
#endif

#define _IOC_NRMASK ((1 << _IOC_NRBITS)-1)
#define _IOC_TYPEMASK   ((1 << _IOC_TYPEBITS)-1)
#define _IOC_SIZEMASK   ((1 << _IOC_SIZEBITS)-1)
#define _IOC_DIRMASK    ((1 << _IOC_DIRBITS)-1)

#define _IOC_NRSHIFT    0
#define _IOC_TYPESHIFT  (_IOC_NRSHIFT+_IOC_NRBITS)
#define _IOC_SIZESHIFT  (_IOC_TYPESHIFT+_IOC_TYPEBITS)
#define _IOC_DIRSHIFT   (_IOC_SIZESHIFT+_IOC_SIZEBITS)


#ifndef _IOC_NONE
# define _IOC_NONE  0U
#endif

#ifndef _IOC_WRITE
# define _IOC_WRITE 1U
#endif

#ifndef _IOC_READ
# define _IOC_READ  2U
#endif


#define _IOC(dir,type,nr,size) \
    (((dir)  << _IOC_DIRSHIFT) | \
     ((type) << _IOC_TYPESHIFT) | \
     ((nr)   << _IOC_NRSHIFT) | \
     ((size) << _IOC_SIZESHIFT))

#ifndef __KERNEL__
#define _IOC_TYPECHECK(t) (sizeof(t))
#endif

/* used to create numbers */
#define _IO(type,nr)        _IOC(_IOC_NONE,(type),(nr),0)
#define _IOR(type,nr,size)  _IOC(_IOC_READ,(type),(nr),(_IOC_TYPECHECK(size)))
#define _IOW(type,nr,size)  _IOC(_IOC_WRITE,(type),(nr),(_IOC_TYPECHECK(size)))
#define _IOWR(type,nr,size) _IOC(_IOC_READ|_IOC_WRITE,(type),(nr),(_IOC_TYPECHECK(size)))
#define _IOR_BAD(type,nr,size)  _IOC(_IOC_READ,(type),(nr),sizeof(size))
#define _IOW_BAD(type,nr,size)  _IOC(_IOC_WRITE,(type),(nr),sizeof(size))
#define _IOWR_BAD(type,nr,size) _IOC(_IOC_READ|_IOC_WRITE,(type),(nr),sizeof(size))

/* used to decode ioctl numbers.. */
//#define _IOC_DIR(nr)        (((nr) >> _IOC_DIRSHIFT) & _IOC_DIRMASK)
//#define _IOC_TYPE(nr)       (((nr) >> _IOC_TYPESHIFT) & _IOC_TYPEMASK)
//#define _IOC_NR(nr)     (((nr) >> _IOC_NRSHIFT) & _IOC_NRMASK)
//#define _IOC_SIZE(nr)       (((nr) >> _IOC_SIZESHIFT) & _IOC_SIZEMASK)
//


//#define IOCPARM_MASK    0x1fff      /* parameter length, at most 13 bits */
//#define IOCPARM_LEN(x)  (((x) >> 16) & IOCPARM_MASK)
//#define IOCBASECMD(x)   ((x) & ~IOCPARM_MASK)
//#define IOCGROUP(x) (((x) >> 8) & 0xff)
//
//
//#define IOCPARM_MAX NBPG        /* max size of ioctl, mult. of NBPG */
//#define IOC_VOID    0x20000000  /* no parameters */
//#define IOC_OUT     0x40000000  /* copy out parameters */
//#define IOC_IN      0x80000000  /* copy in parameters */
//#define IOC_INOUT   (IOC_IN|IOC_OUT)
//#define IOC_DIRMASK 0xe0000000  /* mask for IN/OUT/VOID */
//
//#define _IOC(inout,group,num,len) \
//    (inout | ((len & IOCPARM_MASK) << 16) | ((group) << 8) | (num))
//#define _IO(g,n)    _IOC(IOC_VOID,  (g), (n), 0)
//#define _IOR(g,n,t) _IOC(IOC_OUT,   (g), (n), sizeof(t))
//#define _IOW(g,n,t) _IOC(IOC_IN,    (g), (n), sizeof(t))
//    /* this should be _IORW, but stdio got there first */
//#define _IOWR(g,n,t)    _IOC(IOC_INOUT, (g), (n), sizeof(t))

#define MSENSOR                        0x83

#define ECS_IOCTL_WRITE                 _IOW(MSENSOR, 0x0b, char*)
#define ECS_IOCTL_READ                  _IOWR(MSENSOR, 0x0c, char*)
#define ECS_IOCTL_RESET                 _IO(MSENSOR, 0x0d) /* NOT used in AK8975 */
#define ECS_IOCTL_SET_MODE              _IOW(MSENSOR, 0x0e, short)
#define ECS_IOCTL_GETDATA               _IOR(MSENSOR, 0x0f, char[SENSOR_DATA_SIZE])
#define ECS_IOCTL_SET_YPR               _IOW(MSENSOR, 0x10, short[12])
#define ECS_IOCTL_GET_OPEN_STATUS       _IOR(MSENSOR, 0x11, int)
#define ECS_IOCTL_GET_CLOSE_STATUS      _IOR(MSENSOR, 0x12, int)
#define ECS_IOCTL_GET_OSENSOR_STATUS    _IOR(MSENSOR, 0x13, int)
#define ECS_IOCTL_GET_DELAY             _IOR(MSENSOR, 0x14, short)
#define ECS_IOCTL_GET_PROJECT_NAME      _IOR(MSENSOR, 0x15, char[64])
#define ECS_IOCTL_GET_MATRIX            _IOR(MSENSOR, 0x16, short [4][3][3])
#define ECS_IOCTL_GET_LAYOUT            _IOR(MSENSOR, 0x17, int[3])

#define ECS_IOCTL_GET_OUTBIT            _IOR(MSENSOR, 0x23, char)
#define ECS_IOCTL_GET_ACCEL             _IOR(MSENSOR, 0x24, short[3])
#define ECS_IOCTL_GET_ACCEL_TEST        _IOR(MSENSOR, 0x25, short[3])
#define MMC31XX_IOC_RM                  _IO(MSENSOR, 0x25)
#define MMC31XX_IOC_RRM                 _IO(MSENSOR, 0x26)

int main() {
    printf("Test ECS_IOCTL_WRITE = 0x%x\n", ECS_IOCTL_WRITE);
    printf("Test ECS_IOCTL_READ = 0x%x\n", ECS_IOCTL_READ);
    //printf("Test ECS_IOCTL_GET_LAYOUT_09911 = 0x%x\n", ECS_IOCTL_GET_LAYOUT_09911);
    printf("Test ECS_IOCTL_GET_OUTBIT = 0x%x\n", ECS_IOCTL_GET_OUTBIT);
    printf("Test ECS_IOCTL_GET_ACCEL = 0x%x\n", ECS_IOCTL_GET_ACCEL);
    printf("Test ECS_IOCTL_GET_ACCEL_TEST = 0x%x\n", ECS_IOCTL_GET_ACCEL_TEST);
}

