#ifndef _MAX32620SDT_H_
#define _MAX32620SDT_H_

#include "mbed.h"

#define MAX32620SDT_NO_ERROR    0
#define MAX32620SDT_ERROR       -1

class MAX32620SDT {

public:
    typedef enum {
        VIO_1V8 = 0x00,
        VIO_3V3 = 0x01
    } vio_t;

    MAX32620SDT();

    ~MAX32620SDT();

    int init();

    int set_vddioh(PinName pin, vio_t vio);
};

#endif /* _MAX32620SDT_H_ */
