/******************************************************************************
 * @file    IoHwAb_MotorDriver.c
 * @brief   Triển khai các API phần cứng trừu tượng cho bộ điều khiển mô-tơ
 *
 * @details File này chứa các hàm để khởi tạo và điều chỉnh mô-men xoắn của mô-tơ.
 *          Các API trong file này cung cấp giao diện phần cứng trừu tượng cho
 *          bộ điều khiển mô-tơ, giúp phần mềm điều khiển mô-men xoắn thông qua
 *          các API của MCAL PWM. Bao gồm hàm khởi tạo cấu hình mô-tơ và hàm
 *          thiết lập mô-men xoắn dựa trên duty cycle PWM.
 *
 * @version 1.0
 * @date    2024-10-25
 * 
 * @author  
 *          HALA Academy
 *          Tong Xuan Hoang
 ******************************************************************************/

#include "IoHwAb_MotorDriver.h"
#include "Pwm.h"  // Gọi API PWM từ MCAL
#include <stdio.h>
#include <stdlib.h>

/******************************************************************************
 * @brief   Biến cấu hình hiện tại của bộ điều khiển mô-tơ
 *
 * @details Biến toàn cục này lưu trữ cấu hình hiện tại của bộ điều khiển mô-tơ,
 *          bao gồm kênh PWM và mô-men xoắn tối đa mà mô-tơ có thể tạo ra. Biến này
 *          được khởi tạo trong hàm `IoHwAb_MotorDriver_Init` và được sử dụng trong
 *          các hàm khác để truy cập cấu hình mô-tơ, hỗ trợ quá trình điều chỉnh
 *          mô-men xoắn theo yêu cầu.
 ******************************************************************************/
static MotorDriver_ConfigType MotorDriver_CurrentConfig;

/******************************************************************************
 * @brief   Hàm khởi tạo bộ điều khiển mô-tơ với cấu hình
 *
 * @details Hàm này nhận vào một cấu trúc cấu hình cho bộ điều khiển mô-tơ và
 *          thiết lập mô-tơ dựa trên các thông số cấu hình được cung cấp. Cấu hình
 *          sẽ được lưu vào biến toàn cục `MotorDriver_CurrentConfig`, bao gồm kênh PWM
 *          và mô-men xoắn tối đa. Sau đó, hàm sẽ khởi tạo kênh PWM thông qua API MCAL
 *          với các thông số ban đầu như chu kỳ và tỷ lệ nhiệm vụ (duty cycle).
 *
 * @param   ConfigPtr - Con trỏ tới cấu trúc `MotorDriver_ConfigType` chứa cấu hình của mô-tơ
 * @return  Std_ReturnType - Trả về E_OK nếu khởi tạo thành công, E_NOT_OK nếu có lỗi
 ******************************************************************************/
Std_ReturnType IoHwAb_MotorDriver_Init(const MotorDriver_ConfigType* ConfigPtr) {
    if (ConfigPtr == NULL) {
        printf("Error: Null configuration pointer passed to IoHwAb_MotorDriver_Init.\n");
        return E_NOT_OK;
    }

    // Lưu cấu hình MotorDriver
    MotorDriver_CurrentConfig.Motor_Channel = ConfigPtr->Motor_Channel;
    MotorDriver_CurrentConfig.Motor_MaxTorque = ConfigPtr->Motor_MaxTorque;

    // Gọi API từ MCAL để khởi tạo PWM
    Pwm_ConfigType pwmConfig = {
        .Pwm_Channel = MotorDriver_CurrentConfig.Motor_Channel,
        .Pwm_Period = 1000, // 1 giây (1000ms)
        .Pwm_DutyCycle = 0  // Khởi tạo với duty cycle = 0%
    };
    Pwm_Init(&pwmConfig);

    // In ra thông tin cấu hình MotorDriver
    printf("Motor Driver Initialized with Configuration:\n");
    printf(" - Motor Channel: %d\n", MotorDriver_CurrentConfig.Motor_Channel);
    printf(" - Max Torque: %d Nm\n", MotorDriver_CurrentConfig.Motor_MaxTorque);

    return E_OK;
}

/******************************************************************************
 * @brief   Hàm điều chỉnh mô-men xoắn của mô-tơ
 *
 * @details Hàm này điều chỉnh mô-men xoắn của mô-tơ dựa trên giá trị yêu cầu.
 *          Trước tiên, hàm sẽ kiểm tra xem giá trị mô-men xoắn có nằm trong phạm
 *          vi cho phép (từ 0 đến mô-men xoắn tối đa của cấu hình hiện tại). Nếu hợp lệ,
 *          hàm sẽ tính toán duty cycle (tỷ lệ nhiệm vụ) dựa trên giá trị mô-men xoắn 
 *          và thiết lập duty cycle này cho PWM của mô-tơ thông qua API MCAL.
 *
 * @param   TorqueValue - Giá trị mô-men xoắn yêu cầu (Nm)
 * @return  Std_ReturnType - Trả về E_OK nếu thiết lập thành công, E_NOT_OK nếu có lỗi
 ******************************************************************************/
Std_ReturnType IoHwAb_MotorDriver_SetTorque(float TorqueValue) {
    // Kiểm tra giá trị mô-men xoắn hợp lệ
    if (TorqueValue < 0.0f || TorqueValue > MotorDriver_CurrentConfig.Motor_MaxTorque) {
        printf("Error: Torque value %.2f Nm out of range (Max: %d Nm).\n", TorqueValue, MotorDriver_CurrentConfig.Motor_MaxTorque);
        return E_NOT_OK;
    }

    // Tính toán tỷ lệ nhiệm vụ (duty cycle) dựa trên mô-men xoắn
    uint16_t dutyCycle = (uint16_t)((TorqueValue / MotorDriver_CurrentConfig.Motor_MaxTorque) * 100);

    // Gọi API từ MCAL để cài đặt duty cycle của PWM
    Pwm_SetDutyCycle(MotorDriver_CurrentConfig.Motor_Channel, dutyCycle);

    // In ra giá trị mô-men xoắn đã đặt
    printf("Setting Motor Torque to %.2f Nm on Channel %d\n", TorqueValue, MotorDriver_CurrentConfig.Motor_Channel);

    return E_OK;
}
