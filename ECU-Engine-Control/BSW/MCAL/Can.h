/******************************************************************************
 * @file    Can.h
 * @brief   Header file cho cấu hình và API của giao tiếp CAN (Controller Area Network)
 *
 * @details File này định nghĩa cấu trúc thông điệp CAN và các hàm cần thiết để khởi tạo, 
 *          gửi, và nhận thông điệp CAN trong hệ thống. Các API mô phỏng giao tiếp CAN 
 *          qua việc truyền và nhận thông điệp với cấu trúc dữ liệu bao gồm ID, dữ liệu, 
 *          và độ dài thông điệp.
 * 
 * @version 1.0
 * @date    2024-10-25
 * @author  
 *          HALA Academy
 *          Tong Xuan Hoang
 ******************************************************************************/

#ifndef CAN_H
#define CAN_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>  // Thư viện hỗ trợ hàm sleep (sử dụng cho delay)

/******************************************************************************
 * @brief   Cấu trúc mô phỏng một thông điệp CAN
 *
 * @details Cấu trúc `Can_MessageType` chứa các thành phần của một thông điệp CAN,
 *          bao gồm ID của thông điệp, mảng dữ liệu có kích thước tối đa 8 byte, 
 *          và độ dài của dữ liệu.
 ******************************************************************************/
typedef struct {
    int id;             /**< ID của thông điệp CAN */
    int data[8];        /**< Dữ liệu CAN (tối đa 8 byte) */
    int length;         /**< Độ dài dữ liệu (tối đa 8 byte) */
} Can_MessageType;

/******************************************************************************
 * @brief   Hàm khởi tạo giao tiếp CAN
 *
 * @details Khởi tạo các thành phần cần thiết cho giao tiếp CAN, chuẩn bị hệ thống 
 *          để gửi và nhận thông điệp CAN.
 *
 * @param   void
 * @return  void
 ******************************************************************************/
void Can_Init(void);

/******************************************************************************
 * @brief   Gửi một thông điệp CAN
 *
 * @details Hàm này nhận vào một thông điệp CAN và thực hiện gửi thông điệp đó
 *          thông qua giao tiếp CAN.
 *
 * @param   message - Con trỏ tới cấu trúc `Can_MessageType` chứa thông điệp cần gửi
 * @return  void
 ******************************************************************************/
void Can_SendMessage(Can_MessageType* message);

/******************************************************************************
 * @brief   Nhận một thông điệp CAN (giả lập nhận ngẫu nhiên)
 *
 * @details Hàm này thực hiện nhận một thông điệp CAN. Trong mô phỏng, dữ liệu nhận
 *          được tạo ngẫu nhiên để giả lập quá trình nhận dữ liệu thực tế.
 *
 * @param   void
 * @return  Can_MessageType - Trả về cấu trúc chứa thông điệp CAN nhận được
 ******************************************************************************/
Can_MessageType Can_ReceiveMessage(void);

/******************************************************************************
 * @brief   Hàm tạo độ trễ (delay)
 *
 * @details Hàm này tạo ra một độ trễ với khoảng thời gian nhất định, hỗ trợ cho 
 *          việc mô phỏng thời gian trễ trong giao tiếp CAN.
 *
 * @param   milliseconds - Thời gian tạo độ trễ, tính bằng mili giây
 * @return  void
 ******************************************************************************/
void Can_Delay(int milliseconds);

#endif // CAN_H
