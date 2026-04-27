// SPDX-License-Identifier: GPL-2.0
/*
 * LKSS Lab 1 - Exercise 6: Platform driver reading DT properties
 *
 * Skeleton driver that binds to the 'my-sensor' device tree node on the
 * lkss-bus and reads its custom properties in probe().
 */

#include <linux/module.h>
#include <linux/platform_device.h>
#include <linux/of.h>

static int sensor_probe(struct platform_device *pdev)
{
	dev_info(&pdev->dev, "sensor probed!\n");

	/* TODO 6.2a: declare a 'const char *label' variable, then use
	 * of_property_read_string(pdev->dev.of_node, "label", &label) to read
	 * the "label" property; on success print it with dev_info() */

	/* TODO 6.2b: declare a 'u32 rate' variable, then use
	 * of_property_read_u32(pdev->dev.of_node, "sample-rate-hz", &rate) to
	 * read the property; on success print it with dev_info() */

	/* TODO 6.2c: declare a 'u32 max_temp' variable, then use
	 * of_property_read_u32(pdev->dev.of_node, "max-temp-celsius", &max_temp)
	 * to read the property; on success print it with dev_info() */

	/* TODO 6.6: add "num-channels = <4>" to the DT node and read
	 * it here with of_property_read_u32(), then print it */

	return 0;
}

static void sensor_remove(struct platform_device *pdev)
{
	/* TODO 6.2d: log "sensor removed" using dev_info() */
}

static const struct of_device_id sensor_dt_ids[] = {
	{ .compatible = "lkss,lab1-sensor" },
	{ /* sentinel */ },
};
MODULE_DEVICE_TABLE(of, sensor_dt_ids);

static struct platform_driver sensor_driver = {
	.probe  = sensor_probe,
	.remove = sensor_remove,
	.driver = {
		.name           = "lkss_sensor",
		.of_match_table = sensor_dt_ids,
	},
};

module_platform_driver(sensor_driver);
MODULE_LICENSE("GPL");
MODULE_AUTHOR("NXP Linux Kernel Summer School");
MODULE_DESCRIPTION("Platform driver reading DT properties");
