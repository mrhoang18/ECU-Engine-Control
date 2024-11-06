/******************************************************************************
 * @file    Pwm.c
 * @brief   Triển khai các API cho giao diện PWM (Pulse Width Modulation)
 *
 * @details File này chứa các hàm khởi tạo và điều chỉnh tỷ lệ nhiệm vụ cho kênh PWM.
 *          Các hàm mô phỏng việc khởi tạo cấu hình PWM, bao gồm thiết lập kênh, 
 *          chu kỳ, và tỷ lệ nhiệm vụ (duty cycle), cùng với việc điều chỉnh duty cycle 
 *          của kênh PWM đã khởi tạo. Mục đích của file này là để hỗ trợ kiểm thử và 
 *          phát triển ứng dụng điều khiển PWM mà không cần phần cứng thực tế.
 *
 * @version 1.0
 * @date    2024-10-25
 * @author  
 *          HALA Academy
 *          Tong Xuan Hoang
 ******************************************************************************/
#include "Pwm.h"
#include <stdio.h>

/******************************************************************************
 * @brief   Khởi tạo kênh PWM với cấu hình
 *
 * @details Hàm này nhận vào một cấu trúc cấu hình `Pwm_ConfigType` và thực hiện
 *          khởi tạo kênh PWM theo các thông số trong cấu hình đó. Cấu hình bao gồm
 *          kênh PWM, chu kỳ và tỷ lệ nhiệm vụ (duty cycle). Sau khi khởi tạo, 
 *          hàm in ra thông tin cấu hình của kênh PWM để xác nhận rằng PWM đã được
 *          khởi tạo với thông số mong muốn.
 *
 * @param   ConfigPtr - Con trỏ tới cấu trúc `Pwm_ConfigType` chứa cấu hình của kênh PWM
 * @return  void
 ******************************************************************************/
void Pwm_Init(const Pwm_ConfigType* ConfigPtr) {
    printf("PWM Initialized for Channel %d with Period %d ms and Duty Cycle %d%%\n", 
           ConfigPtr->Pwm_Channel, ConfigPtr->Pwm_Period, ConfigPtr->Pwm_DutyCycle);
}

/******************************************************************************
 * @brief   Cài đặt tỷ lệ nhiệm vụ (duty cycle) cho kênh PWM
 *
 * @details Hàm này cho phép điều chỉnh tỷ lệ nhiệm vụ (duty cycle) của một kênh PWM cụ thể.
 *          Giá trị `DutyCycle` được cung cấp trong tham số sẽ xác định tỷ lệ phần trăm 
 *          của chu kỳ mà kênh PWM này sẽ ở mức cao. Sau khi cài đặt, hàm in ra thông tin 
 *          của kênh PWM cùng với tỷ lệ nhiệm vụ mới để xác nhận thay đổi.
 *
 * @param   Channel - Kênh PWM cần cài đặt tỷ lệ nhiệm vụ
 * @param   DutyCycle - Tỷ lệ nhiệm vụ mới cho kênh PWM (tính bằng phần trăm)
 * @return  void
 ******************************************************************************/
void Pwm_SetDutyCycle(uint8_t Channel, uint16_t DutyCycle) {
    printf("PWM Channel %d set to Duty Cycle: %d%%\n", Channel, DutyCycle);
}
