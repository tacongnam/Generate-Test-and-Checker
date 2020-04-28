# Tool generate test (ver 20.04.28.1 Beta)
- Lưu ý: 
    - Chương trình sử dụng hàm system(). Một số chương trình anti-virus có thể nhận diện nó như là virus. Xem thêm tại: http://www.cplusplus.com/articles/j3wTURfi/ . Lỗi này sẽ được fix tại các phiên bản sau.

    - Chương trình sử dụng testlib.h. Xem đầy đủ source code tại: https://github.com/MikeMirzayanov/testlib/blob/master/testlib.h. Xem thêm hướng dẫn về testlib.h tại https://codeforces.com/testlib.
    
    - Chương trình sử dụng chương trình nén thư mục Rar.exe của winRaR(R). Xem thêm về winRaR(R) tại: https://www.win-rar.com/ 
    
    - Chương trình sử dụng dụng MinGW để chạy các file .cpp, .c.

    - Đây là bản Beta. Nếu bạn muốn tải bản ổn định cũ hơn, vui lòng vào: https://github.com/tacongnam/Generate-Test-and-Checker/tree/master/old%20version
    
------------------

### Có gì mới? (20.04.28.1 Beta)
- Cho phép chạy sinh test trực tiếp với các file .cpp, .c (qua MinGW) thay vì qua file .exe như cũ.
- Xoá các file thừa (file inp, file out) trong thư mục sau khi sinh test xong.

### Có gì mới? (20.04.26.2)
- Cho phép sử dụng validator (sử dụng thư viện testlib.h)
- Đặt thời gian time limit cho solution
- Sau khi sinh test xong sẽ tự động tạo file rar chứa thư mục test.

### Có gì mới? (20.04.26.1)
- Bản đầu tiên

### Mục đích
Chương trình generate test được tạo ra với mục đích giúp mọi người có thể tạo ra một bộ test đơn giản để:
- Tạo test cho các kỳ thi
- Debug. Việc tạo test giúp chúng ta debug dễ dàng hơn.
- Kiểm tra code. Tạo một bộ test từ code chính xác và chạy code của bạn với bộ test cũng là một cách để phát hiện lỗi sai trong code.

### Hướng dẫn cài đặt
- Bước 1: Truy cập https://github.com/tacongnam/Generate-Test-and-Checker

- Bước 2: Chọn Clone or Download -> Download ZIP

- Bước 3: Giải nén file Generate-Test-and-Checker-master.zip

- Bước 4: Cài đặt MinGW. Bạn có thể cài bằng cách tải từ Internet, hoặc chạy file tdm-gcc-9.2.0.exe trong thư mục generate-test. Vui lòng để địa chỉ cài đặt là C:\...., phần tên ..... sẽ phụ thuộc tuỳ theo phần mềm bạn tải.


### Hướng dẫn sử dụng

- Bước 1: Tại thư mục 20.04.28.1.Beta, bạn sẽ thấy 5 file (giới thiệu tại phần dưới đây). Copy toàn bộ 5 file này vào nơi bạn muốn tạo thư mục chứa test.

- Bước 2: Copy file generator (sinh test), file solution (code chuẩn), file validator (kiểm tra input - nếu có) vào cùng thư mục đó.

- Bước 3: Tại file maketest.txt, bạn hãy nhập các dữ liệu về các file (xem tại phần dưới)

- Bước 4: Click đúp vào file Generate Test.exe để chạy chương trình sinh test. Nhập FILE (để sinh test với chương trình .exe - khuyên dùng) hoặc CMD (sinh test trực tiếp với file cpp, c) rồi nhấn Enter.

- Bước 5: Sau khi chạy, test sẽ được sinh ra. Mở file logs.txt. Nếu file này không có gì hoặc "OK!" thì bạn đã sinh test thành công. Nếu không, bạn đã gặp vấn đề (sẽ được nêu trong file log).

### 5 file trong thư mục
##### 1. File maketest.txt
File này sử dụng để nhập dữ liệu. Các dữ liệu cụ thể tương ứng với lệnh nhập vào của chương trình như sau (mỗi dòng 1 dữ liệu)

    filegen;   /// Chương trình tạo input. VD: gen.exe (FILE) hoặc gen.cpp (CMD)
    filerun;   /// Chương trình tạo output (code của các bạn). VD: WATER.exe (FILE) hoặc (CMD)
    filebai;   /// Tên bài làm. VD: WATER. Đây sẽ là tên thư mục chứa các test
    fileinp;   /// Tên file input: VD: WATER.inp. Tên file này cần trùng với file dữ liệu đầu vào của code của bạn.
    fileout;   /// Tên file output: VD: WATER.out. Tên file này cần trùng với file dữ liệu đầu ra của code của bạn.
    from;      /// Test bắt đầu từ: VD: 59
    numoftest; /// Số test. VD: 100
    timelimit; /// Thời gian chạy cho mỗi test (số thực, đơn vị: giây). VD: 0.5
    novalid;   /// Sử dụng validator (dùng testlib.h của Codeforces. 1 có nghĩa là sử dụng, 0 có nghĩa là không sử dụng)
    
VD1: (đối với FILE)

    gen.exe
    1258.exe
    1258
    1258.inp
    1258.out
    12
    30
    10
    1

File trên có nghĩa: 

Tạo thư mục mới chứa test có tên là 1258. 

Các test này được đánh số từ 12 -> 41. 

File input được sinh ra có tên: 1258.inp, file output được sinh ra có tên 1258.out. 

File input được sinh bởi gen.exe. File output được tạo ra bởi 1258.exe. File input được kiểm tra bởi validator.exe

Thời gian chạy cho mỗi test tối đa là 10 giây.

VD2: (đối với CMD)

    gen.cpp
    1258.cpp
    1258
    1258.inp
    1258.out
    12
    30
    10
    1

File trên có nghĩa: 

Tạo thư mục mới chứa test có tên là 1258. 

Các test này được đánh số từ 12 -> 41. 

File input được sinh ra có tên: 1258.inp, file output được sinh ra có tên 1258.out. 

File input được sinh bởi gen.cpp. File output được tạo ra bởi 1258.cpp. File input được kiểm tra bởi validator.cpp

Thời gian chạy cho mỗi test tối đa là 10 giây.

*Chú ý: (Áp dụng cho Code::Blocks, các phần mềm khác làm tương tự.)

- Để lấy được filegen, filerun, validator, bạn sẽ chạy chương trình đó (F9, đảm bảo không có bug). Tại thư mục Project tương ứng, vào bin/Debug/, bạn sẽ thấy một file .exe. Đổi tên file này thành tên tương ứng (VD: gen, validator,...) rồi copy file này vào nơi sinh test (cùng với 5 file có sẵn).

- File validator bắt buộc phải để là validator.exe (đối với FILE) và validator.cpp (đối với CMD). Nếu bạn không biết cách tạo ra file này, xem thêm tại https://codeforces.com/blog/entry/18426 hoặc nhập 0 tại dòng novalid (dòng cuối của maketest.txt, không kiểm tra input nữa).

- fileinp, fileout cần trùng với file dữ liệu đầu vào và đầu ra được ghi trong code của bạn.
 
- Khi chạy file Generate Test.exe, console sẽ hiển thị đầy đủ thông tin trong vòng 5s ban đầu. Nếu gặp lỗi, bạn có thể tắt console ngay lập tức rồi sửa lại file maketest.txt

##### 2. File testlib.h
Đây là thư viện testlib.h được sử dụng với rất nhiều các tính năng đặc biệt. Xem đầy đủ source code tại: https://github.com/MikeMirzayanov/testlib/blob/master/testlib.h. Xem thêm hướng dẫn về testlib.h tại https://codeforces.com/testlib.
Nếu lỡ xoá file này, bạn có thể vào link github trên để tải lại testlib.h rồi đưa file vào thư mục như cũ.

##### 3. File Rar.exe
Đây là chương trình nén file lấy từ WinRaR. Nếu lỡ xoá file này, bạn hãy vào thư mục WinRaR được cài đặt trong máy tính bạn (mặc định: C:\Program Files\WinRAR\) rồi copy file Rar.exe rồi paste file vào thư mục như cũ)

##### 4. File GenerateTest.exe
Chương trình sinh test. Để sinh test, click đúp chuột vào chương trình này, nhập FILE, nếu muốn sử dụng cái file .exe (như gen.exe, validator.exe,...) để sinh test (khuyên dùng), hoặc .cpp (như gen.cpp, validator.cpp,...) để sinh test.

Lệnh biên dịch file CPP: g++ -std=c++14 filegen -pipe -O2 -s -static -lm -x c++ -o genfile
                         g++ -std=c++14 filerun -pipe -O2 -s -static -lm -x c++ -o runfile

Với filegen, filerun là code bạn nhập vào để sinh input và chạy để tạo output. genfile, runfile là hai file exe tương ứng được tạo ra từ filegen, filerun, có cấu tạo là một xâu bất kỳ có 32 kí tự + đuôi ".exe"

Vui lòng nhập đúng 'CMD' hoặc 'FILE', nếu không chương trình sẽ báo lỗi.

##### 5. File logs.txt
File ghi lại lỗi nếu gặp lỗi trong lúc sinh test. Các lỗi sẽ gặp là:
- Something are error. It can be your generator. Fix them and try again.
  
  Error code: -1
  
  -> Generator bị lỗi (file sinh test)

- Something are error. It can be your input or your validator. Fix them and try again.

  Error code: 1
  
  -> Validator hoặc input bị lỗi.
  
- Something are error. Your solution doesn't return 0. Fix it and try again.

  Error code: 2
  
  -> Code solution không trả về 0 (return 0;) khi kết thúc chương trình.
  
- Something are error. Your code has TLE verdict. Fix it and try again.

  Error code: 3
  
  -> Code solution bị quá timelimit.
  
### Kết quả file chạy:
Sau khi chạy, một thư mục mới có dạng như sau được tạo ra (giả sử tạo 10 test, from = 1)

        filebai
            Test1
                fileinp
                fileout
            Test2
                fileinp
                fileout
            ...
            Test10
               fileinp
               fileout
           
Một tệp rar tương ứng chứa toàn bộ thư mục trên cũng sẽ được tạo ra.

*Chú ý: 

- Thư mục filebai phải:
    + Chưa tồn tại tại nơi sinh test (cùng với 5 file có sẵn), hoặc:
    + Đã tồn tại, nhưng các test bạn muốn sinh phải không trùng với các test có sẵn trong thư mục.
  
  Nếu không, thư mục chứa các test trùng sẽ không nằm trong thư mục filebai như dạng trên!
  
--------------------
2020 - tacongnam
