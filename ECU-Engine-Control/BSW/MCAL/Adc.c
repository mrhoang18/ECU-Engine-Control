/******************************************************************************
 * @file    Adc.c
 * @brief   Triển khai các API cho bộ chuyển đổi ADC
 *
 * @details File này chứa các hàm để khởi tạo và đọc giá trị từ các kênh ADC của vi điều khiển.
 *          Các API trong file này bao gồm khởi tạo cấu hình ADC, đọc giá trị ADC từ kênh
 *          cụ thể, và một hàm tạo độ trễ (delay) phục vụ cho việc điều chỉnh tần số lấy mẫu.
 *          Các API cho phép ứng dụng dễ dàng cấu hình và truy xuất dữ liệu từ các kênh ADC.
 *
 * @version 1.0
 * @date    2024-10-25
 * @author  
 *          HALA Academy
 *          Tong Xuan Hoang
 ******************************************************************************/

#include "Adc.h"

/******************************************************************************
 * @brief   Biến cấu hình hiện tại của bộ chuyển đổi ADC
 *
 * @details Biến toàn cục này lưu trữ cấu hình hiện tại của bộ chuyển đổi ADC,
 *          bao gồm thông tin kênh ADC, tần số lấy mẫu và độ phân giải. Biến này
 *          được khởi tạo và cập nhật thông qua hàm `Adc_Init` dựa trên thông số
 *          cấu hình được cung cấp bởi ứng dụng. `Adc_CurrentConfig` đóng vai trò
 *          làm dữ liệu tham chiếu cho các hàm khác để truy cập và điều chỉnh hoạt
 *          động của ADC theo các yêu cầu cụ thể về tần số và độ phân giải.
 ******************************************************************************/
static Adc_ConfigType Adc_CurrentConfig;  // Lưu trữ cấu hình hiện tại của ADC

/******************************************************************************
 * @brief   Hàm khởi tạo bộ chuyển đổi ADC với cấu hình
 *
 * @details Hàm này nhận vào một cấu trúc cấu hình `Adc_ConfigType` và thiết lập
 *          ADC dựa trên các thông số cấu hình được cung cấp, bao gồm kênh ADC,
 *          tần số lấy mẫu, và độ phân giải. Cấu hình được lưu vào biến toàn cục
 *          `Adc_CurrentConfig` để tham chiếu trong các thao tác ADC khác. Hàm 
 *          cũng khởi tạo seed cho việc sinh số ngẫu nhiên, nhằm mô phỏng dữ liệu
 *          đầu vào của ADC.
 *
 * @param   ConfigPtr - Con trỏ tới cấu trúc `Adc_ConfigType` chứa cấu hình của ADC
 * @return  void
 ******************************************************************************/
void Adc_Init(const Adc_ConfigType* ConfigPtr) {
    if (ConfigPtr == NULL) {
        printf("Error: Null configuration pointer passed to Adc_Init.\n");
        return;
    }

    // Lưu cấu hình ADC từ ConfigPtr vào biến toàn cục
    Adc_CurrentConfig.Adc_Channel = ConfigPtr->Adc_Channel;
    Adc_CurrentConfig.Adc_SamplingRate = ConfigPtr->Adc_SamplingRate;
    Adc_CurrentConfig.Adc_Resolution = ConfigPtr->Adc_Resolution;

    // Khởi tạo seed cho việc sinh số ngẫu nhiên để mô phỏng ADC
    srand(time(0));

    // In ra thông tin cấu hình ADC
    printf("ADC Initialized with Configuration:\n");
    printf(" - Channel: %d\n", Adc_CurrentConfig.Adc_Channel);
    printf(" - Sampling Rate: %d Hz\n", Adc_CurrentConfig.Adc_SamplingRate);
    printf(" - Resolution: %d-bit\n", Adc_CurrentConfig.Adc_Resolution);
}

/******************************************************************************
 * @brief   Đọc giá trị từ một kênh ADC cụ thể (sử dụng giá trị ngẫu nhiên)
 *
 * @details Hàm này đọc giá trị từ một kênh ADC đã chỉ định và trả về giá trị 
 *          ngẫu nhiên để mô phỏng tín hiệu ADC. Độ trễ 500ms được sử dụng 
 *          để mô phỏng thời gian lấy mẫu thực tế. Giá trị ADC ngẫu nhiên 
 *          được sinh từ 0 đến 1023, giả lập độ phân giải 10-bit của ADC.
 *
 * @param   channel - Kênh ADC cần đọc giá trị
 * @return  int - Giá trị ADC đọc được (0-1023)
 ******************************************************************************/
int Adc_ReadChannel(int channel) {
    int adc_value = 0;

    // Gọi hàm delay để mô phỏng thời gian đọc ADC
    Delay(500);  // Tạo độ trễ 500ms để mô phỏng

    // Giả lập giá trị ngẫu nhiên từ 0 đến 1023 (giá trị ADC 10-bit)
    adc_value = rand() % 1024;

    // In giá trị đọc được từ kênh ADC
    printf("Reading ADC Channel %d: Value = %d\n", channel, adc_value);

    return adc_value;
}

/******************************************************************************
 * @brief   Hàm tạo độ trễ mô phỏng (tính theo mili giây)
 *
 * @details Hàm này tạo ra một khoảng thời gian trễ dựa trên tham số đầu vào, 
 *          giúp mô phỏng thời gian chờ hoặc thời gian lấy mẫu của ADC.
 *          Hàm sử dụng `usleep`, trong đó tham số được nhân với 1000 để 
 *          chuyển đổi từ mili giây sang micro giây, đơn vị cần thiết cho `usleep`.
 *
 * @param   milliseconds - Thời gian trễ, tính theo mili giây
 * @return  void
 ******************************************************************************/
void Delay(int milliseconds) {
    usleep(milliseconds * 1000); // Hàm usleep tính theo micro giây, nhân với 1000 để thành mili giây
}
