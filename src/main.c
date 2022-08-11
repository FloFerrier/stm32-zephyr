
#include <zephyr/kernel.h>
#include <zephyr/device.h>
#include <zephyr/drivers/gpio.h>

#define STACKSIZE 1024

#define PRIORITY 7

/* The devicetree node identifier for the "led0" alias. */
#define LED0_NODE DT_ALIAS(led0)

/*
 * A build error on this line means your board is unsupported.
 * See the sample documentation for information on how to fix this.
 */
static const struct gpio_dt_spec green_led = GPIO_DT_SPEC_GET(LED0_NODE, gpios);

static void thread0(void);
static void thread1(void);

K_THREAD_DEFINE(thread0_id, STACKSIZE, thread0, NULL, NULL, NULL,
		PRIORITY, 0, 0);
K_THREAD_DEFINE(thread1_id, STACKSIZE, thread1, NULL, NULL, NULL,
		PRIORITY, 0, 0);

void thread0(void) {
    int counter = 0;
    gpio_pin_configure_dt(&green_led, GPIO_OUTPUT);
	while (1) {
		printk("[Thread0] Counter value: %d\n", counter++);
        gpio_pin_toggle_dt(&green_led);
        k_msleep(1000);
	}
}

void thread1(void) {
    int counter = 0;
	while (1) {
		printk("[Thread1] Counter value: %d\n", counter++);
		k_msleep(1000);
	}
}