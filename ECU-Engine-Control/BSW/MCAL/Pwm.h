/******************************************************************************
 * @file    Pwm.h
 * @brief   Header file cho cấu hình và API của giao diện PWM (Pulse Width Modulation)
 *
 * @details File này định nghĩa các cấu trúc và API cần thiết để khởi tạo và điều chỉnh
 *          kênh PWM. API cung cấp khả năng thiết lập cấu hình PWM, bao gồm kênh, chu kỳ,
 *          và tỷ lệ nhiệm vụ (duty cycle). Tỷ lệ nhiệm vụ có thể được thay đổi bằng cách
 *          sử dụng hàm `Pwm_SetDutyCycle` để điều chỉnh đầu ra PWM theo nhu cầu của ứng dụng.
 * 
 * @version 1.0
 * @date    2024-10-25
 * @author  
 *          HALA Academy
 *          Tong Xuan Hoang
 ******************************************************************************/

#ifndef PWM_H
#define PWM_H

#include "Std_Types.h"

/******************************************************************************
 * @brief   Cấu trúc cấu hình cho PWM
 *
 * @details Cấu trúc `Pwm_ConfigType` chứa các thành phần cần thiết để thiết lập cấu hình
 *          cho một kênh PWM, bao gồm thông số kênh, chu kỳ PWM, và tỷ lệ nhiệm vụ (duty cycle).
 ******************************************************************************/
typedef struct {
    uint8_t Pwm_Channel;       /**< Kênh PWM */
    uint16_t Pwm_Period;       /**< Chu kỳ PWM */
    uint16_t Pwm_DutyCycle;    /**< Tỷ lệ nhiệm vụ (duty cycle) của PWM */
} Pwm_ConfigType;

/******************************************************************************
 * @brief   Khởi tạo kênh PWM
 *
 * @details Hàm này nhận vào cấu trúc `Pwm_ConfigType` và thiết lập kênh PWM với các thông số 
 *          cấu hình được cung cấp, bao gồm kênh, chu kỳ, và tỷ lệ nhiệm vụ. Chuẩn bị PWM
 *          để sử dụng cho các thao tác điều khiển tín hiệu.
 *
 * @param   ConfigPtr - Con trỏ tới cấu trúc `Pwm_ConfigType` chứa cấu hình của kênh PWM
 * @return  void
 ******************************************************************************/
void Pwm_Init(const Pwm_ConfigType* ConfigPtr);

/******************************************************************************
 * @brief   Cài đặt tỷ lệ nhiệm vụ (duty cycle) cho kênh PWM
 *
 * @details Hàm này cho phép điều chỉnh tỷ lệ nhiệm vụ của một kênh PWM cụ thể.
 *          Tham số `DutyCycle` được sử dụng để thiết lập phần trăm tỷ lệ nhiệm vụ,
 *          thay đổi đầu ra PWM theo yêu cầu của ứng dụng.
 *
 * @param   Channel - Kênh PWM cần cài đặt tỷ lệ nhiệm vụ
 * @param   DutyCycle - Tỷ lệ nhiệm vụ mới cho kênh PWM (tính bằng phần trăm)
 * @return  void
 ******************************************************************************/
void Pwm_SetDutyCycle(uint8_t Channel, uint16_t DutyCycle);

#endif /* PWM_H */
