/******************************************************************************
 * @file    IoHwAb_TorqueSensor.c
 * @brief   Triển khai các API phần cứng trừu tượng cho cảm biến mô-men xoắn
 *
 * @details File này chứa các hàm để khởi tạo và đọc giá trị từ cảm biến mô-men xoắn.
 *          Các API trong file này cung cấp giao diện phần cứng trừu tượng để tương
 *          tác với cảm biến mô-men xoắn thông qua MCAL. Các hàm bao gồm khởi tạo 
 *          cấu hình cảm biến và đọc giá trị mô-men xoắn từ ADC.
 *
 * @version 1.0
 * @date    2024-10-25
  * @author  
 *          HALA Academy
 *          Tong Xuan Hoang
 ******************************************************************************/

#include "IoHwAb_TorqueSensor.h"
#include "MCAL/Adc.h"   // Gọi API từ MCAL để đọc giá trị từ ADC
#include <stdio.h>
#include <stdlib.h>

/******************************************************************************
 * @brief   Biến cấu hình hiện tại của cảm biến mô-men xoắn
 *
 * @details Biến toàn cục này lưu trữ cấu hình hiện tại của cảm biến mô-men xoắn,
 *          bao gồm kênh ADC và giá trị mô-men xoắn tối đa. Biến này được khởi tạo 
 *          trong hàm `IoHwAb_TorqueSensor_Init` và được sử dụng trong các hàm khác
 *          để truy xuất cấu hình của cảm biến.
 ******************************************************************************/
// Giả lập cấu hình của cảm biến mô-men xoắn
static TorqueSensor_ConfigType TorqueSensor_CurrentConfig;

/******************************************************************************
 * @brief   Hàm khởi tạo cảm biến mô-men xoắn với cấu hình
 *
 * @details Hàm này nhận vào cấu trúc cấu hình cảm biến mô-men xoắn và thiết lập 
 *          cấu hình cho cảm biến, bao gồm việc lưu cấu hình vào biến toàn cục 
 *          và khởi tạo kênh ADC qua API MCAL.
 *
 * @param   ConfigPtr - Con trỏ tới cấu trúc `TorqueSensor_ConfigType` chứa cấu hình cảm biến
 * @return  Std_ReturnType - Trả về E_OK nếu khởi tạo thành công, E_NOT_OK nếu có lỗi
 ******************************************************************************/
Std_ReturnType IoHwAb_TorqueSensor_Init(const TorqueSensor_ConfigType* ConfigPtr) {
    if (ConfigPtr == NULL) {
        printf("Error: Null configuration pointer passed to IoHwAb_TorqueSensor_Init.\n");
        return E_NOT_OK;
    }

    // Lưu cấu hình cảm biến mô-men xoắn vào biến toàn cục
    TorqueSensor_CurrentConfig.TorqueSensor_Channel = ConfigPtr->TorqueSensor_Channel;
    TorqueSensor_CurrentConfig.TorqueSensor_MaxValue = ConfigPtr->TorqueSensor_MaxValue;

    // Gọi API từ MCAL để khởi tạo ADC
    Adc_ConfigType adcConfig;
    adcConfig.Adc_Channel = TorqueSensor_CurrentConfig.TorqueSensor_Channel;
    Adc_Init(&adcConfig);

    // In ra thông tin cấu hình của cảm biến mô-men xoắn
    printf("Torque Sensor Initialized with Configuration:\n");
    printf(" - ADC Channel: %d\n", TorqueSensor_CurrentConfig.TorqueSensor_Channel);
    printf(" - Max Torque Value: %d Nm\n", TorqueSensor_CurrentConfig.TorqueSensor_MaxValue);

    return E_OK;
}

/******************************************************************************
 * @brief   Hàm đọc giá trị từ cảm biến mô-men xoắn
 *
 * @details Đọc giá trị ADC từ kênh cảm biến mô-men xoắn, sau đó chuyển đổi 
 *          giá trị ADC sang mô-men xoắn thực tế và lưu vào biến con trỏ đầu vào.
 *
 * @param   TorqueValue - Con trỏ lưu trữ giá trị mô-men xoắn thực tế đọc được
 * @return  Std_ReturnType - Trả về E_OK nếu đọc thành công, E_NOT_OK nếu có lỗi
 ******************************************************************************/
Std_ReturnType IoHwAb_TorqueSensor_Read(float* TorqueValue) {
    if (TorqueValue == NULL) {
        return E_NOT_OK;  // Kiểm tra con trỏ NULL
    }

    // Đọc giá trị ADC từ MCAL
    uint16_t adcValue = 0;
    if (Adc_ReadChannel(TorqueSensor_CurrentConfig.TorqueSensor_Channel, &adcValue) != E_OK) {
        printf("Error: Failed to read ADC value.\n");
        return E_NOT_OK;
    }

    // Chuyển đổi giá trị ADC sang mô-men xoắn (giả lập)
    *TorqueValue = ((float)adcValue / 1023.0f) * TorqueSensor_CurrentConfig.TorqueSensor_MaxValue;

    // In ra giá trị mô-men xoắn
    printf("Reading Torque Sensor (ADC Channel %d): Torque = %.2f Nm\n",
           TorqueSensor_CurrentConfig.TorqueSensor_Channel, *TorqueValue);

    return E_OK;
}
