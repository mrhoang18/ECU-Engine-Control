/******************************************************************************
 * @file    IoHwAb_SpeedSensor.h
 * @brief   Header file cho cấu hình và API của cảm biến tốc độ
 *
 * @details Định nghĩa cấu hình và các hàm cần thiết để khởi tạo và đọc giá trị
 *          từ cảm biến tốc độ trong hệ thống. Cung cấp giao diện phần cứng trừu
 *          tượng để tương tác với cảm biến tốc độ thông qua MCAL.
 * 
 * @version 1.0
 * @date    2024-10-25
 * @author  
 *          HALA Academy
 *          Tong Xuan Hoang
 ******************************************************************************/

#ifndef IOHWAB_SPEEDSENSOR_H
#define IOHWAB_SPEEDSENSOR_H

#include "Std_Types.h"

/******************************************************************************
 * @brief   Cấu hình cho cảm biến tốc độ
 *
 * @details Cấu trúc `SpeedSensor_ConfigType` chứa các thành phần cần thiết để 
 *          thiết lập cấu hình cho cảm biến tốc độ, như kênh ADC và giá trị 
 *          tốc độ tối đa mà cảm biến có thể đọc.
 ******************************************************************************/
typedef struct {
    uint8_t SpeedSensor_Channel;   /**< Kênh ADC để đọc giá trị từ cảm biến tốc độ */
    uint16_t SpeedSensor_MaxValue; /**< Giá trị tốc độ tối đa mà cảm biến có thể đọc (km/h) */
} SpeedSensor_ConfigType;

/******************************************************************************
 * @brief   Hàm khởi tạo cảm biến tốc độ
 *
 * @details Hàm này nhận vào cấu trúc cấu hình và thiết lập cảm biến tốc độ 
 *          theo các giá trị cấu hình. Đảm bảo cảm biến sẵn sàng để đọc dữ liệu.
 *
 * @param   ConfigPtr - Con trỏ tới cấu trúc cấu hình `SpeedSensor_ConfigType`
 * @return  Std_ReturnType - Trả về E_OK nếu khởi tạo thành công, E_NOT_OK nếu có lỗi
 ******************************************************************************/
Std_ReturnType IoHwAb_SpeedSensor_Init(const SpeedSensor_ConfigType* ConfigPtr);

/******************************************************************************
 * @brief   Hàm đọc giá trị từ cảm biến tốc độ
 *
 * @details Đọc giá trị tốc độ hiện tại từ cảm biến và lưu vào biến con trỏ đầu vào.
 *
 * @param   SpeedValue - Con trỏ lưu trữ giá trị tốc độ đọc được từ cảm biến (km/h)
 * @return  Std_ReturnType - Trả về E_OK nếu đọc thành công, E_NOT_OK nếu có lỗi
 ******************************************************************************/
Std_ReturnType IoHwAb_SpeedSensor_Read(float* SpeedValue);

#endif /* IOHWAB_SPEEDSENSOR_H */
