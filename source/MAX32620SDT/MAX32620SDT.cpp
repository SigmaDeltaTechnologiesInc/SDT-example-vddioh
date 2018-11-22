#include "mbed.h"
#include "MAX32620SDT.h"

MAX32620SDT::MAX32620SDT() {

}

MAX32620SDT::~MAX32620SDT() {

}

int MAX32620SDT::init() {
    set_vddioh(P3_0, VIO_3V3);
    set_vddioh(P3_1, VIO_3V3);
    set_vddioh(P4_0, VIO_3V3);

    return MAX32620SDT_NO_ERROR;
}

int MAX32620SDT::set_vddioh(PinName pin, vio_t vio) {
    __IO uint32_t *use_vddioh = &((mxc_ioman_regs_t *)MXC_IOMAN)->use_vddioh_0;

    if (pin == NOT_CONNECTED) {
        return -1;
    }

    use_vddioh += PINNAME_TO_PORT(pin) >> 2;

    if (vio) {
        *use_vddioh |= (1 << (PINNAME_TO_PIN(pin) + ((PINNAME_TO_PORT(pin) & 0x3) << 3)));
    } else {
        *use_vddioh &= ~(1 << (PINNAME_TO_PIN(pin) + ((PINNAME_TO_PORT(pin) & 0x3) << 3)));
    }

    return 0;
}
