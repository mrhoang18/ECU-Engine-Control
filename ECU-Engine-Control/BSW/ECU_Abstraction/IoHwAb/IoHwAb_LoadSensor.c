/******************************************************************************
 * @file    IoHwAb_LoadSensor.c
 * @brief   Triển khai các API phần cứng trừu tượng cho cảm biến tải trọng
 *
 * @details File này chứa các hàm để khởi tạo và đọc giá trị từ cảm biến tải trọng.
 *          Các API trong file này cung cấp giao diện phần cứng trừu tượng để
 *          tương tác với cảm biến tải trọng thông qua MCAL. Bao gồm hàm khởi tạo
 *          cấu hình cảm biến và hàm đọc giá trị tải trọng từ ADC, đồng thời chuyển
 *          đổi giá trị ADC thành giá trị tải trọng thực tế (kg).
 *
 * @version 1.0
 * @date    2024-10-25 
 * @author  
 *          HALA Academy
 *          Tong Xuan Hoang
 ******************************************************************************/
#include "IoHwAb_LoadSensor.h"
#include "MCAL/Adc.h"    // Gọi API từ MCAL để đọc giá trị từ ADC
#include <stdio.h>

/******************************************************************************
 * @brief   Biến cấu hình hiện tại của cảm biến tải trọng
 *
 * @details Biến toàn cục này lưu trữ cấu hình hiện tại của cảm biến tải trọng,
 *          bao gồm kênh ADC được sử dụng để đọc dữ liệu và giá trị tải trọng
 *          tối đa mà cảm biến có thể đo được. Biến này được khởi tạo trong hàm
 *          `IoHwAb_LoadSensor_Init` và được sử dụng trong các hàm khác để truy
 *          cập cấu hình của cảm biến, hỗ trợ quá trình đo lường tải trọng chính xác.
 ******************************************************************************/static LoadSensor_ConfigType LoadSensor_CurrentConfig;

/******************************************************************************
 * @brief   Hàm khởi tạo cảm biến tải trọng với cấu hình
 *
 * @details Hàm này nhận vào một cấu trúc cấu hình cho cảm biến tải trọng và thiết
 *          lập cảm biến dựa trên các thông số cấu hình được cung cấp. Cấu hình
 *          sẽ được lưu vào biến toàn cục `LoadSensor_CurrentConfig`, bao gồm kênh
 *          ADC và giá trị tải trọng tối đa. Sau đó, hàm sẽ khởi tạo kênh ADC 
 *          thông qua API MCAL để chuẩn bị cho quá trình đo lường.
 *
 * @param   ConfigPtr - Con trỏ tới cấu trúc `LoadSensor_ConfigType` chứa cấu hình của cảm biến
 * @return  Std_ReturnType - Trả về E_OK nếu khởi tạo thành công, E_NOT_OK nếu có lỗi
 ******************************************************************************/
Std_ReturnType IoHwAb_LoadSensor_Init(const LoadSensor_ConfigType* ConfigPtr) {
    if (ConfigPtr == NULL) {
        printf("Error: Null configuration pointer passed to IoHwAb_LoadSensor_Init.\n");
        return E_NOT_OK;
    }

    // Lưu cấu hình cảm biến tải trọng vào biến toàn cục
    LoadSensor_CurrentConfig.LoadSensor_Channel = ConfigPtr->LoadSensor_Channel;
    LoadSensor_CurrentConfig.LoadSensor_MaxValue = ConfigPtr->LoadSensor_MaxValue;

    // Gọi API từ MCAL để khởi tạo ADC
    Adc_ConfigType adcConfig;
    adcConfig.Adc_Channel = ConfigPtr->LoadSensor_Channel;
    Adc_Init(&adcConfig);

    // In ra thông tin cấu hình cảm biến tải trọng
    printf("Load Sensor Initialized with Configuration:\n");
    printf(" - ADC Channel: %d\n", LoadSensor_CurrentConfig.LoadSensor_Channel);
    printf(" - Max Load Value: %d kg\n", LoadSensor_CurrentConfig.LoadSensor_MaxValue);
    return E_OK;
}

/******************************************************************************
 * @brief   Hàm đọc giá trị từ cảm biến tải trọng
 *
 * @details Hàm này đọc giá trị thô từ ADC của cảm biến tải trọng và chuyển đổi nó
 *          thành giá trị tải trọng thực tế (đơn vị: kg) dựa trên cấu hình đã thiết lập.
 *          Giá trị đọc được sẽ được lưu vào biến con trỏ đầu vào `LoadValue`.
 *          Nếu quá trình đọc gặp lỗi hoặc con trỏ NULL, hàm sẽ trả về trạng thái lỗi.
 *
 * @param   LoadValue - Con trỏ lưu trữ giá trị tải trọng đọc được từ cảm biến (đơn vị: kg)
 * @return  Std_ReturnType - Trả về E_OK nếu đọc thành công, E_NOT_OK nếu có lỗi
 ******************************************************************************/
Std_ReturnType IoHwAb_LoadSensor_Read(float* LoadValue) {
    if (LoadValue == NULL) {
        return E_NOT_OK;  // Kiểm tra con trỏ NULL
    }

    // Đọc giá trị ADC từ MCAL
    uint16_t adcValue = 0;
    if (Adc_ReadChannel(LoadSensor_CurrentConfig.LoadSensor_Channel, &adcValue) != E_OK) {
        printf("Error: Failed to read ADC value.\n");
        return E_NOT_OK;
    }

    // Chuyển đổi giá trị ADC sang giá trị tải trọng (kg)
    *LoadValue = ((float)adcValue / 1023.0f) * LoadSensor_CurrentConfig.LoadSensor_MaxValue;

    // In ra giá trị tải trọng
    printf("Load Sensor (ADC Channel %d): Load = %.2f kg\n",
            LoadSensor_CurrentConfig.LoadSensor_Channel, *LoadValue);

    return E_OK;
}
