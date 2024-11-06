/******************************************************************************
 * @file    IoHwAb_ThrottleSensor.h
 * @brief   Header file cho cấu hình và API của cảm biến bàn đạp ga
 *
 * @details Định nghĩa cấu hình và các hàm cần thiết để khởi tạo và đọc giá trị
 *          từ cảm biến bàn đạp ga trong hệ thống. Cung cấp giao diện phần cứng
 *          trừu tượng giữa phần mềm và cảm biến bàn đạp ga.
 * 
 * @version 1.0
 * @date    2024-10-25
 * @author  
 *          HALA Academy
 *          Tong Xuan Hoang
 ******************************************************************************/

#ifndef IOHWAB_THROTTLESENSOR_H
#define IOHWAB_THROTTLESENSOR_H

#include "Std_Types.h"

/******************************************************************************
 * @brief   Cấu hình cho cảm biến bàn đạp ga
 *
 * @details Cấu trúc `ThrottleSensor_ConfigType` bao gồm thành phần cần thiết để 
 *          thiết lập cấu hình cho cảm biến bàn đạp ga, như kênh ADC.
 ******************************************************************************/
typedef struct {
    uint8_t ThrottleSensor_Channel;  // Kênh ADC để đọc giá trị từ cảm biến bàn đạp ga
} ThrottleSensor_ConfigType;

/******************************************************************************
 * @brief   Prototype cho hàm khởi tạo cảm biến bàn đạp ga
 *
 * @details Hàm này nhận vào cấu trúc cấu hình và thiết lập cảm biến bàn đạp ga
 *          theo các giá trị cấu hình. Đảm bảo cảm biến sẵn sàng để đọc dữ liệu.
 *
 * @param   ConfigPtr - Con trỏ tới cấu trúc cấu hình `ThrottleSensor_ConfigType`
 * @return  Std_ReturnType - Trả về E_OK nếu khởi tạo thành công, E_NOT_OK nếu có lỗi
 ******************************************************************************/
Std_ReturnType IoHwAb_ThrottleSensor_Init(const ThrottleSensor_ConfigType* ConfigPtr);

/******************************************************************************
 * @brief   Prototype cho hàm đọc giá trị từ cảm biến bàn đạp ga
 *
 * @details Đọc giá trị bàn đạp ga hiện tại từ cảm biến và lưu vào biến con trỏ đầu vào.
 *
 * @param   ThrottlePosition - Con trỏ lưu trữ giá trị bàn đạp ga đọc được từ cảm biến
 * @return  Std_ReturnType - Trả về E_OK nếu đọc thành công, E_NOT_OK nếu có lỗi
 ******************************************************************************/
Std_ReturnType IoHwAb_ThrottleSensor_Read(float* ThrottlePosition);

#endif /* IOHWAB_THROTTLESENSOR_H */
