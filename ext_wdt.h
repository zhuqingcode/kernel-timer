#ifndef __HI_GPIO_H__ 
#define __HI_GPIO_H__

#define GPIO_DIR_IN 0
#define GPIO_DIR_OUT 1

typedef struct {
	unsigned int  groupnumber;
	unsigned int  bitnumber;
	unsigned int  value;
}gpio_groupbit_info;

#define GPIO            'G'
#define GPIO_SET_DIR                    _IOWR(GPIO, 1, gpio_groupbit_info)
#define GPIO_GET_DIR                    _IOWR(GPIO, 2, gpio_groupbit_info)
#define GPIO_READ_BIT                    _IOWR(GPIO, 3, gpio_groupbit_info)
#define GPIO_WRITE_BIT                    _IOWR(GPIO, 4, gpio_groupbit_info)
#endif
