/*
 * Copyright (c) 2020 Nordic Semiconductor ASA
 *
 * SPDX-License-Identifier: LicenseRef-BSD-5-Clause-Nordic
 */

/**
 * @file mpsl_fem_config_simple_gpio.h
 *
 * @defgroup mpsl_fem_simple_gpio MPSL Simple GPIO Front End Module Module Conifguration
 * @ingroup  mpsl_fem
 *
 * The MPSL Simple GPIO Front End Module Module Conifguration defines the configuration of the Simple GPIO Front End Module Module.
 * @{
 */

#ifndef MPSL_FEM_CONFIG_SIMPLE_GPIO_H__
#define MPSL_FEM_CONFIG_SIMPLE_GPIO_H__

#include <stdint.h>
#include <stdbool.h>
#include "mpsl_fem_config_common.h"

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief Configuration parameters for the Front End Module Simple GPIO variant.
 */
typedef struct
{
    struct
    {
        uint32_t pa_time_gap_us;                  /**< Time between the activation of the PA pin and the start of the radio transmission. */
        uint32_t lna_time_gap_us;                 /**< Time between the activation of the LNA pin and the start of the radio reception. */
        int8_t   pa_gain_db;                      /**< Configurable PA gain. Ignored if the amplifier is not supporting this feature. */
        int8_t   lna_gain_db;                     /**< Configurable LNA gain. Ignored if the amplifier is not supporting this feature. */
    }                            fem_config;      /**< Configration structure of the Simple GPIO Front End Module. */

    mpsl_fem_gpiote_pin_config_t pa_pin_config;   /**< Power Amplifier pin configuration. */
    mpsl_fem_gpiote_pin_config_t lna_pin_config;  /**< Low Noise Amplifier pin configuration. */

    uint8_t                      ppi_channels[2]; /**< Array of PPI which need to be provided to Front End Module to operate. */
} mpsl_fem_simple_gpio_interface_config_t;

/**
 * @brief Configures the PA and LNA device interface.
 *
 * This function sets device interface parameters for the PA/LNA module.
 * The module can then be used to control a power amplifier or a low noise amplifier (or both) through the given interface and resources.
 *
 * The function also sets the PPI and GPIOTE channels to be configured for the PA/LNA interface.
 *
 * @param[in] p_config Pointer to the interface parameters for the PA/LNA device.
 *
 * @retval   0             PA/LNA control successfully configured.
 * @retval   -NRF_EPERM    PA/LNA is not available.
 *
 */
int32_t mpsl_fem_simple_gpio_interface_config_set(mpsl_fem_simple_gpio_interface_config_t const * const p_config);

/**
 * @section simple_gpio_timings "Simple GPIO Front End Module Timings."
 */

/** Time in microseconds when PA GPIO is activated before the radio is ready for transmission. */
#define MPSL_FEM_SIMPLE_GPIO_PA_TIME_IN_ADVANCE_US  23

/** Time in microseconds when LNA GPIO is activated before the radio is ready for reception. */
#define MPSL_FEM_SIMPLE_GPIO_LNA_TIME_IN_ADVANCE_US 5

/**
 * @section simple_gpio_gains "Simple GPIO Front End Module Gains."
 */

/** Gain of the PA in dB. */
#define MPSL_FEM_SIMPLE_GPIO_PA_GAIN_DB   22

/** Gain of the LNA in dB. */
#define MPSL_FEM_SIMPLE_GPIO_LNA_GAIN_DB  11

#ifdef __cplusplus
}
#endif

#endif // MPSL_FEM_CONFIG_SIMPLE_GPIO_H__

/**@} */
