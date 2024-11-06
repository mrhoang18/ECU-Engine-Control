/******************************************************************************
 * @file    Adc.h
 * @brief   Header file cho cấu hình và API của bộ chuyển đổi ADC
 *
 * @details File này định nghĩa cấu hình và các hàm cần thiết để khởi tạo và đọc giá trị
 *          từ các kênh ADC của vi điều khiển. Các API cho phép thiết lập cấu hình 
 *          cho ADC, đọc giá trị từ kênh ADC cụ thể, và hỗ trợ hàm tạo độ trễ (delay) 
 *          phục vụ cho quá trình lấy mẫu ADC.
 * 
 * @version 1.0
 * @date    2024-10-25
 * @author  
 *          HALA Academy
 *          Tong Xuan Hoang
 ******************************************************************************/

#ifndef ADC_H
#define ADC_H

#include <stdio.h>
#include <stdlib.h>  // Thư viện hỗ trợ tạo giá trị ngẫu nhiên
#include <time.h>    // Thư viện hỗ trợ thời gian (sử dụng cho random)
#include <unistd.h>  // Thư viện hỗ trợ hàm sleep (sử dụng cho delay)
#include "Std_Types.h"

/******************************************************************************
 * @brief   Cấu trúc chứa thông tin cấu hình của ADC
 *
 * @details Cấu trúc `Adc_ConfigType` chứa các thành phần để thiết lập cấu hình cho ADC,
 *          bao gồm kênh ADC, tần số lấy mẫu, và độ phân giải. Cấu hình này giúp thiết lập 
 *          hoạt động của ADC theo yêu cầu của ứng dụng.
 ******************************************************************************/
typedef struct {
    uint8_t Adc_Channel;       /**< Kênh ADC cần khởi tạo */
    uint32_t Adc_SamplingRate; /**< Tần số lấy mẫu */
    uint8_t Adc_Resolution;    /**< Độ phân giải ADC (ví dụ: 8, 10, 12 bit) */
} Adc_ConfigType;

/******************************************************************************
 * @brief   Hàm khởi tạo ADC
 *
 * @details Hàm này nhận vào một cấu trúc cấu hình và thiết lập ADC theo các thông số 
 *          cấu hình được cung cấp, bao gồm kênh, tần số lấy mẫu, và độ phân giải.
 *
 * @param   ConfigPtr - Con trỏ tới cấu trúc `Adc_ConfigType` chứa cấu hình của ADC
 * @return  void
 ******************************************************************************/
void Adc_Init(const Adc_ConfigType* ConfigPtr);

/******************************************************************************
 * @brief   Đọc giá trị từ kênh ADC cụ thể
 *
 * @details Hàm này đọc giá trị từ kênh ADC được chỉ định và trả về kết quả. 
 *          Giá trị đọc được là một số nguyên đại diện cho tín hiệu analog.
 *
 * @param   channel - Kênh ADC cần đọc giá trị
 * @return  int - Giá trị đọc từ kênh ADC
 ******************************************************************************/
int Adc_ReadChannel(int channel);

/******************************************************************************
 * @brief   Hàm tạo độ trễ (delay)
 *
 * @details Hàm này tạo ra một độ trễ trong khoảng thời gian xác định, giúp hỗ trợ
 *          cho quá trình lấy mẫu ADC và các tác vụ yêu cầu thời gian khác.
 *
 * @param   milliseconds - Thời gian tạo độ trễ, tính bằng mili giây
 * @return  void
 ******************************************************************************/
void Delay(int milliseconds);

#endif // ADC_H
