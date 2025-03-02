import numpy as np
import time
import sys


def main():
    with open("timepython.txt", "w") as output:
        for test in range(1, 11):
            filename = f"test{test}.txt"

            try:
                # Đọc dữ liệu từ file
                data = np.loadtxt(filename, dtype=np.float64)

                # Ghi nhận thời gian bắt đầu
                start_time = time.perf_counter()

                # Sắp xếp dữ liệu
                sorted_data = np.sort(data)  # Dùng NumPy để tối ưu tốc độ

                # Ghi nhận thời gian kết thúc
                duration = (time.perf_counter() - start_time) * 1000  # Đổi sang milliseconds

                # Ghi kết quả vào file
                output.write(f"Test {test}: {round(duration)} ms\n")
                # In ra stderr như trong C++
                print(-1, file=sys.stderr)

            except Exception as e:
                print(f"Lỗi khi đọc file {filename}: {e}", file=sys.stderr)


if __name__ == "__main__":
    main()