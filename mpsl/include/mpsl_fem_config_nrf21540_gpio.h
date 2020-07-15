/*
 * Copyright (c) 2020 Nordic Semiconductor ASA
 *
 * SPDX-License-Identifier: LicenseRef-BSD-5-Clause-Nordic
 */

/**
 * @file mpsl_fem_config_nrf21540_gpio.h
 *
 * @defgroup mpsl_fem_nrf21540_gpio MPSL nRF21540 GPIO Front End Module Module Conifguration
 * @ingroup  mpsl_fem
 *
 * The MPSL nRF21540 GPIO Front End Module Module Conifguration defines the configuration of the nRF21540 GPIO Front End Module Module.
 * @{
 */

#ifndef MPSL_FEM_CONFIG_NRF21540_GPIO_H__
#define MPSL_FEM_CONFIG_NRF21540_GPIO_H__

#include <stdint.h>
#include <stdbool.h>
#include "mpsl_fem_config_common.h"

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief Configuration parameters for the PA/LNA interface in the "3-pin gpio" variant
 */
typedef struct
{
    struct
    {
        uint32_t pa_time_gap_us;                  /**< Time between the activation of the PA pin and the start of the radio transmission. */
        uint32_t lna_time_gap_us;                 /**< Time between the activation of the LNA pin and the start of the radio reception. */
        uint32_t pdn_settle_us;                   /**< The time between activating the PDN and asserting the PA/LNA pin. */
        uint32_t trx_hold_us;                     /**< The time between deasserting the PA/LNA pin and deactivating PDN. */
        int8_t   pa_gain_db;                      /**< Configurable PA gain. Ignored if the amplifier is not supporting this feature. */
        int8_t   lna_gain_db;                     /**< Configurable LNA gain. Ignored if the amplifier is not supporting this feature. */
    }                            fem_config;      /**< Configuration structure of the nRF21540 GPIO. */

    mpsl_fem_gpiote_pin_config_t pa_pin_config;   /**< Power Amplifier pin configuration. */
    mpsl_fem_gpiote_pin_config_t lna_pin_config;  /**< Low Noise Amplifier pin configuration. */
    mpsl_fem_gpiote_pin_config_t pdn_pin_config;  /**< Power Down pin configuration. */

    uint8_t                      ppi_channels[3]; /**< Array of PPI which need to be provided to Front End Module to operate. */

} mpsl_fem_nrf21540_gpio_interface_config_t;

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
 * @retval   0                 PA/LNA control successfully configured.
 * @retval   -NRF_EPERM     PA/LNA is not available.
 *
 */
int32_t mpsl_fem_nrf21540_gpio_interface_config_set(mpsl_fem_nrf21540_gpio_interface_config_t const * const p_config);

/**
 * @section nrf21540_gpio_timings "nRF21540 GPIO Front End Module Timings."
 */

/** Time in microseconds when PA GPIO is activated before the radio is ready for transmission. */
#define MPSL_FEM_NRF21540_GPIO_PA_TIME_IN_ADVANCE_US  13

/** Time in microseconds when LNA GPIO is activated before the radio is ready for reception. */
#define MPSL_FEM_NRF21540_GPIO_LNA_TIME_IN_ADVANCE_US 13

/** The time between activating the PDN and asserting the RX_EN/TX_EN. */
#define MPSL_FEM_NRF21540_GPIO_PDN_SETTLE_US          18

/** The time between deasserting the RX_EN/TX_EN and deactivating PDN. */
#define MPSL_FEM_NRF21540_GPIO_TRX_HOLD_US            5

/**
 * @section nrf21540_gpio_gains "nRF21540 GPIO Front End Module Gains."
 */

/** Gain of the PA in dB. */
#define MPSL_FEM_NRF21540_GPIO_PA_GAIN_DB   20

/** Gain of the LNA in dB. */
#define MPSL_FEM_NRF21540_GPIO_LNA_GAIN_DB  20

#ifdef __cplusplus
}
#endif

#endif // MPSL_FEM_CONFIG_NRF21540_GPIO_H__

/**@} */
