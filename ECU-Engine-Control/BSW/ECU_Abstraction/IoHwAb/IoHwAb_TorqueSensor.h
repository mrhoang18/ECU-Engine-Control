/******************************************************************************
 * @file    IoHwAb_TorqueSensor.h
 * @brief   Header file cho cấu hình và API của cảm biến mô-men xoắn
 *
 * @details Định nghĩa cấu hình và các hàm cần thiết để khởi tạo và đọc giá trị 
 *          từ cảm biến mô-men xoắn trong hệ thống.
 * 
 * @version 1.0
 * @date    2024-10-25
 * @author  
 *          HALA Academy
 *          Tong Xuan Hoang
 ******************************************************************************/

#ifndef IOHWAB_TORQUESENSOR_H
#define IOHWAB_TORQUESENSOR_H

#include "Std_Types.h"

/******************************************************************************
 * @brief   Cấu hình cho cảm biến mô-men xoắn
 *
 * @details Cấu trúc `TorqueSensor_ConfigType` bao gồm các thành phần cần thiết
 *          để thiết lập cấu hình cho cảm biến mô-men xoắn, như kênh ADC và giá
 *          trị mô-men xoắn tối đa.
 ******************************************************************************/
typedef struct {
    uint8_t TorqueSensor_Channel;   // Kênh ADC để đọc giá trị từ cảm biến mô-men xoắn
    uint16_t TorqueSensor_MaxValue; //< Giá trị mô-men xoắn tối đa (Nm)
} TorqueSensor_ConfigType;

/******************************************************************************
 * @brief   Hàm khởi tạo cảm biến mô-men xoắn
 *
 * @details Hàm này nhận vào cấu trúc cấu hình và thiết lập cảm biến mô-men xoắn 
 *          theo các giá trị cấu hình. Đảm bảo cảm biến sẵn sàng để đọc dữ liệu.
 *
 * @param   ConfigPtr - Con trỏ tới cấu trúc cấu hình `TorqueSensor_ConfigType`
 * @return  Std_ReturnType - Trả về E_OK nếu khởi tạo thành công, E_NOT_OK nếu có lỗi
 ******************************************************************************/
Std_ReturnType IoHwAb_TorqueSensor_Init(const TorqueSensor_ConfigType* ConfigPtr);

/******************************************************************************
 * @brief   Hàm đọc giá trị từ cảm biến mô-men xoắn
 *
 * @details Đọc giá trị mô-men xoắn hiện tại từ cảm biến và lưu vào biến con trỏ đầu vào.
 *
 * @param   TorqueValue - Con trỏ lưu trữ giá trị mô-men xoắn đọc được từ cảm biến
 * @return  Std_ReturnType - Trả về E_OK nếu đọc thành công, E_NOT_OK nếu có lỗi
 ******************************************************************************/
Std_ReturnType IoHwAb_TorqueSensor_Read(float* TorqueValue);

#endif /* IOHWAB_TORQUESENSOR_H */
