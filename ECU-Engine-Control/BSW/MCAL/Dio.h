/******************************************************************************
 * @file    Dio.h
 * @brief   Header file cho cấu hình và API của giao diện DIO (Digital Input/Output)
 *
 * @details File này định nghĩa các API cần thiết để khởi tạo, đọc, và ghi các chân DIO
 *          trên vi điều khiển. API cung cấp các hàm mô phỏng cho việc điều khiển các
 *          tín hiệu số, bao gồm thiết lập trạng thái cao (HIGH) hoặc thấp (LOW).
 *          Ngoài ra, file cũng cung cấp hàm tạo độ trễ để mô phỏng thời gian chờ 
 *          khi thực hiện các thao tác DIO.
 * 
 * @version 1.0
 * @date    2024-10-25
 * @author  
 *          HALA Academy
 *          Tong Xuan Hoang
 ******************************************************************************/

#ifndef DIO_H
#define DIO_H

#include <stdio.h>
#include <stdlib.h>  // Thư viện hỗ trợ tạo giá trị ngẫu nhiên
#include <time.h>    // Thư viện hỗ trợ thời gian (sử dụng cho random)
#include <unistd.h>  // Thư viện hỗ trợ hàm sleep (sử dụng cho delay)

/******************************************************************************
 * @brief   Các trạng thái của DIO
 *
 * @details Enum `Dio_LevelType` xác định các trạng thái của chân DIO, bao gồm 
 *          trạng thái thấp (0V) và trạng thái cao (5V).
 ******************************************************************************/
typedef enum {
    DIO_LOW = 0,    /**< Trạng thái thấp (0V) */
    DIO_HIGH = 1    /**< Trạng thái cao (5V) */
} Dio_LevelType;

/******************************************************************************
 * @brief   Khởi tạo DIO
 *
 * @details Hàm này thực hiện khởi tạo các chân DIO, chuẩn bị hệ thống để thực hiện
 *          các thao tác đọc và ghi trên các chân DIO.
 *
 * @param   void
 * @return  void
 ******************************************************************************/
void Dio_Init(void);

/******************************************************************************
 * @brief   Đọc giá trị từ chân DIO
 *
 * @details Hàm này đọc và trả về giá trị hiện tại của một chân DIO cụ thể, cho biết
 *          trạng thái của chân đó là cao (HIGH) hay thấp (LOW).
 *
 * @param   channel - Số kênh DIO cần đọc giá trị
 * @return  Dio_LevelType - Trả về trạng thái của chân DIO (DIO_HIGH hoặc DIO_LOW)
 ******************************************************************************/
Dio_LevelType Dio_ReadChannel(int channel);

/******************************************************************************
 * @brief   Ghi giá trị cho chân DIO
 *
 * @details Hàm này thiết lập giá trị của một chân DIO cụ thể, cho phép đặt chân đó
 *          vào trạng thái cao (HIGH) hoặc thấp (LOW).
 *
 * @param   channel - Số kênh DIO cần thiết lập giá trị
 * @param   level - Trạng thái mong muốn của chân DIO (DIO_HIGH hoặc DIO_LOW)
 * @return  void
 ******************************************************************************/
void Dio_WriteChannel(int channel, Dio_LevelType level);

/******************************************************************************
 * @brief   Hàm tạo độ trễ (delay)
 *
 * @details Hàm này tạo ra một độ trễ trong khoảng thời gian xác định, hỗ trợ cho 
 *          việc mô phỏng thời gian chờ trong các thao tác DIO.
 *
 * @param   milliseconds - Thời gian tạo độ trễ, tính bằng mili giây
 * @return  void
 ******************************************************************************/
void Dio_Delay(int milliseconds);

#endif // DIO_H
