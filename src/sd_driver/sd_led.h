#ifndef SD_LED_H
#define SD_LED_H

#if defined(CALYX_STATUS_LED) && CALYX_STATUS_LED
#  ifdef __cplusplus
     extern "C" {
#  endif
     void calyx_led_activity_on(void);
#  ifdef __cplusplus
     }
#  endif
#  define LED_INIT()
#  define LED_PULSE() calyx_led_activity_on()
#elif !defined(NO_PICO_LED) && defined(USE_LED) && USE_LED && defined(PICO_DEFAULT_LED_PIN)
#  include "pico/stdlib.h"
#  define LED_INIT()                     \
    {                                    \
        gpio_init(PICO_DEFAULT_LED_PIN); \
        gpio_set_dir(PICO_DEFAULT_LED_PIN, GPIO_OUT); \
    }
#  define LED_PULSE() gpio_put(PICO_DEFAULT_LED_PIN, 1)
#else
#  define LED_INIT()
#  define LED_PULSE()
#endif

#endif
