/******************************************************************************
 * @file    Std_Types.h
 * @brief   Định nghĩa các kiểu dữ liệu tiêu chuẩn và mã trạng thái cho hệ thống
 *
 * @details File này chứa các định nghĩa và kiểu dữ liệu tiêu chuẩn được sử dụng 
 *          rộng rãi trong các module của hệ thống, bao gồm kiểu boolean, mã trạng thái, 
 *          và các thông tin về phiên bản phần mềm. Các định nghĩa trong file này
 *          giúp đảm bảo tính nhất quán và đơn giản hóa việc xử lý các giá trị boolean,
 *          các mã lỗi, và các con trỏ NULL trong ứng dụng.
 * 
 * @version 1.0
 * @date    2024-10-25
 * @author  
 *          HALA Academy
 *          Tong Xuan Hoang
 ******************************************************************************/

#ifndef STD_TYPES_H
#define STD_TYPES_H

#include <stdint.h>

/* Boolean Data Types */
#ifndef TRUE
/******************************************************************************
 * @brief   Định nghĩa giá trị TRUE cho kiểu dữ liệu boolean
 *
 * @details TRUE được định nghĩa là 1 và được sử dụng để biểu thị trạng thái
 *          đúng hoặc tích cực trong các biểu thức boolean.
 ******************************************************************************/
#define TRUE 1
#endif

#ifndef FALSE
/******************************************************************************
 * @brief   Định nghĩa giá trị FALSE cho kiểu dữ liệu boolean
 *
 * @details FALSE được định nghĩa là 0 và được sử dụng để biểu thị trạng thái
 *          sai hoặc tiêu cực trong các biểu thức boolean.
 ******************************************************************************/
#define FALSE 0
#endif

/* Standard Return Type */
typedef uint8_t Std_ReturnType;

/******************************************************************************
 * @brief   Mã trạng thái thành công
 *
 * @details E_OK được định nghĩa là 0x00U, biểu thị rằng một thao tác đã được thực hiện
 *          thành công mà không gặp lỗi.
 ******************************************************************************/
#define E_OK        0x00U  /* Operation successful */

/******************************************************************************
 * @brief   Mã trạng thái thất bại
 *
 * @details E_NOT_OK được định nghĩa là 0x01U, biểu thị rằng một thao tác đã không thành công
 *          hoặc đã gặp lỗi trong quá trình thực hiện.
 ******************************************************************************/
#define E_NOT_OK    0x01U  /* Operation not successful */

/* Null Pointer Definition */
/******************************************************************************
 * @brief   Định nghĩa con trỏ NULL
 *
 * @details NULL_PTR được định nghĩa là một con trỏ NULL, dùng để biểu thị rằng một
 *          con trỏ không trỏ đến bất kỳ đối tượng hợp lệ nào trong bộ nhớ.
 ******************************************************************************/
#define NULL_PTR    ((void*)0)
