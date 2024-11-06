/******************************************************************************
 * @file    IoHwAb_MotorDriver.h
 * @brief   Header file cho cấu hình và API của bộ điều khiển mô-tơ
 *
 * @details File này định nghĩa cấu hình và các hàm cần thiết để khởi tạo và điều
 *          chỉnh mô-men xoắn cho mô-tơ. Các hàm cung cấp giao diện phần cứng 
 *          trừu tượng để điều khiển mô-tơ thông qua lớp trừu tượng IoHwAb.
 * 
 * @version 1.0
 * @date    2024-10-25
 * @author  
 *          HALA Academy
 *          Tong Xuan Hoang
 ******************************************************************************/

#ifndef IOHWAB_MOTORDRIVER_H
#define IOHWAB_MOTORDRIVER_H

#include "Std_Types.h"

/******************************************************************************
 * @brief   Cấu hình cho bộ điều khiển mô-tơ
 *
 * @details Cấu trúc `MotorDriver_ConfigType` chứa các thành phần cần thiết để 
 *          thiết lập cấu hình cho mô-tơ, bao gồm kênh PWM và giá trị mô-men 
 *          xoắn tối đa mà mô-tơ có thể tạo ra.
 ******************************************************************************/
typedef struct {
    uint8_t Motor_Channel;      /**< Kênh PWM điều khiển mô-tơ */
    uint16_t Motor_MaxTorque;   /**< Mô-men xoắn tối đa (Nm) */
} MotorDriver_ConfigType;

/******************************************************************************
 * @brief   Hàm khởi tạo bộ điều khiển mô-tơ
 *
 * @details Hàm này nhận vào cấu trúc cấu hình và thiết lập mô-tơ dựa trên các
 *          giá trị cấu hình. Đảm bảo mô-tơ sẵn sàng để điều khiển mô-men xoắn.
 *
 * @param   ConfigPtr - Con trỏ tới cấu trúc cấu hình `MotorDriver_ConfigType`
 * @return  Std_ReturnType - Trả về E_OK nếu khởi tạo thành công, E_NOT_OK nếu có lỗi
 ******************************************************************************/
Std_ReturnType IoHwAb_MotorDriver_Init(const MotorDriver_ConfigType* ConfigPtr);

/******************************************************************************
 * @brief   Hàm điều chỉnh mô-men xoắn của mô-tơ
 *
 * @details Hàm này điều chỉnh mô-men xoắn của mô-tơ theo giá trị yêu cầu.
 *          Mô-men xoắn sẽ được thiết lập dựa trên giá trị TorqueValue đầu vào.
 *
 * @param   TorqueValue - Giá trị mô-men xoắn yêu cầu (Nm)
 * @return  Std_ReturnType - Trả về E_OK nếu thiết lập thành công, E_NOT_OK nếu có lỗi
 ******************************************************************************/
Std_ReturnType IoHwAb_MotorDriver_SetTorque(float TorqueValue);

#endif /* IOHWAB_MOTORDRIVER_H */
