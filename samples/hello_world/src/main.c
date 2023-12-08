/*
 * Copyright (c) 2012-2014 Wind River Systems, Inc.
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#include <zephyr/sys/util.h>
#include <zephyr/devicetree.h>
#include <stdio.h>

#define NODE_ID DT_NODELABEL(uart2)

#define PATH_AND_COMMA(node_id) DT_NODE_PATH(node_id),

int main(void)
{
	printf("%d %d\n", DT_NODE_HAS_COMPAT(NODE_ID, ti_stellaris_uart), DT_NODE_HAS_COMPAT(NODE_ID, ti_stellaris_gpio));

        const char *gpio_paths[] = {
                DT_FOREACH_STATUS_OKAY(ti_stellaris_gpio, PATH_AND_COMMA)
        };
        printf("gpios:\n");
        for (int i = 0; i < ARRAY_SIZE(gpio_paths); i++) {
                printf("%s\n", gpio_paths[i]);
        }

        const char *uart_paths[] = {
                DT_FOREACH_STATUS_OKAY(ti_stellaris_uart, PATH_AND_COMMA)
        };
        printf("uarts:\n");
        for (int i = 0; i < ARRAY_SIZE(uart_paths); i++) {
                printf("%s\n", uart_paths[i]);
        }

	return 0;
}
