/******************************************************************************
 * @file    IoHwAb_LoadSensor.h
 * @brief   Header file cho cấu hình và API của cảm biến tải trọng
 *
 * @details Định nghĩa cấu hình và các hàm cần thiết để khởi tạo và đọc giá trị
 *          từ cảm biến tải trọng (Load Sensor) trong hệ thống. Cung cấp giao diện
 *          phần cứng trừu tượng để tương tác với cảm biến tải trọng thông qua MCAL.
 * 
 * @version 1.0
 * @date    2024-10-25
 * @author  
 *          HALA Academy
 *          Tong Xuan Hoang
 ******************************************************************************/

#ifndef IOHWAB_LOADSENSOR_H
#define IOHWAB_LOADSENSOR_H

#include "Std_Types.h"

/******************************************************************************
 * @brief   Cấu hình cho cảm biến tải trọng
 *
 * @details Cấu trúc `LoadSensor_ConfigType` chứa các thành phần cần thiết để 
 *          thiết lập cấu hình cho cảm biến tải trọng, bao gồm kênh ADC và giá trị 
 *          tải trọng tối đa mà cảm biến có thể đo được.
 ******************************************************************************/
typedef struct {
    uint8_t LoadSensor_Channel;   /**< Kênh ADC để đọc giá trị từ cảm biến */
    uint16_t LoadSensor_MaxValue; /**< Giá trị tải trọng tối đa mà cảm biến có thể đọc */
} LoadSensor_ConfigType;

/******************************************************************************
 * @brief   Hàm khởi tạo cảm biến tải trọng
 *
 * @details Hàm này nhận vào cấu trúc cấu hình và thiết lập cảm biến tải trọng
 *          theo các giá trị cấu hình. Đảm bảo cảm biến sẵn sàng để đọc dữ liệu.
 *
 * @param   ConfigPtr - Con trỏ tới cấu trúc cấu hình `LoadSensor_ConfigType`
 * @return  Std_ReturnType - Trả về E_OK nếu khởi tạo thành công, E_NOT_OK nếu có lỗi
 ******************************************************************************/
Std_ReturnType IoHwAb_LoadSensor_Init(const LoadSensor_ConfigType* ConfigPtr);

/******************************************************************************
 * @brief   Hàm đọc giá trị từ cảm biến tải trọng
 *
 * @details Đọc giá trị tải trọng hiện tại từ cảm biến và lưu vào biến con trỏ đầu vào.
 *
 * @param   LoadValue - Con trỏ lưu trữ giá trị tải trọng đọc được từ cảm biến
 * @return  Std_ReturnType - Trả về E_OK nếu đọc thành công, E_NOT_OK nếu có lỗi
 ******************************************************************************/
Std_ReturnType IoHwAb_LoadSensor_Read(float* LoadValue);

#endif /* IOHWAB_LOADSENSOR_H */
