/******************************************************************************
 * @file    Mcal_Config.h
 * @brief   Header file cho cấu hình và khởi tạo các mô-đun trong MCAL (Microcontroller Abstraction Layer)
 *
 * @details File này cung cấp các prototype cho các hàm khởi tạo và cấu hình các mô-đun
 *          trong MCAL, bao gồm ADC, DIO, PWM, và CAN. Các hàm này được sử dụng để thiết lập
 *          các mô-đun MCAL với cấu hình cơ bản, nhằm chuẩn bị hệ thống cho các tác vụ
 *          điều khiển và truyền thông cần thiết.
 * 
 * @version 1.0
 * @date    2024-10-25
 * @author  
 *          HALA Academy
 *          Tong Xuan Hoang
 ******************************************************************************/

#ifndef MCAL_CONFIG_H
#define MCAL_CONFIG_H

#include "Adc.h"
#include "Dio.h"
#include "Pwm.h"
#include "Can.h"

/******************************************************************************
 * @brief   Cấu hình và khởi tạo toàn bộ MCAL
 *
 * @details Hàm này thực hiện khởi tạo và cấu hình cho tất cả các mô-đun trong MCAL.
 *          Mỗi mô-đun sẽ được khởi tạo với cấu hình mặc định thông qua các hàm
 *          cấu hình tương ứng.
 *
 * @param   void
 * @return  void
 ******************************************************************************/
void Mcal_ConfigInit(void);

/******************************************************************************
 * @brief   Cấu hình và khởi tạo ADC
 *
 * @details Khởi tạo mô-đun ADC để chuẩn bị cho các thao tác đọc tín hiệu analog
 *          trong hệ thống.
 *
 * @param   void
 * @return  void
 ******************************************************************************/
void Adc_ConfigInit(void);

/******************************************************************************
 * @brief   Cấu hình và khởi tạo DIO
 *
 * @details Khởi tạo mô-đun DIO để chuẩn bị cho các thao tác đầu vào và đầu ra số
 *          trong hệ thống.
 *
 * @param   void
 * @return  void
 ******************************************************************************/
void Dio_ConfigInit(void);

/******************************************************************************
 * @brief   Cấu hình và khởi tạo PWM
 *
 * @details Khởi tạo mô-đun PWM để chuẩn bị cho các thao tác điều khiển xung độ rộng
 *          trong hệ thống.
 *
 * @param   void
 * @return  void
 ******************************************************************************/
void Pwm_ConfigInit(void);

/******************************************************************************
 * @brief   Cấu hình và khởi tạo CAN
 *
 * @details Khởi tạo mô-đun CAN để chuẩn bị cho các thao tác truyền thông CAN
 *          trong hệ thống.
 *
 * @param   void
 * @return  void
 ******************************************************************************/
void Can_ConfigInit(void);

#endif /* MCAL_CONFIG_H */
