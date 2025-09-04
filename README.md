! Компилировал только под Linux, на Windows не пробовал, но никаких специфичных для линукса вещей вроде не использовалось

Комиляция:
1) Конфигурация:<br>
* У програмки есть зависимость от [JKQTPlotter](https://github.com/jkriege2/JKQtPlotter). Поэтому есть 2 варианта конфигурации:

1. Вариант 1: Скачать JKQTPlotter в build директорию:<br>
Через терминал:<br>
  ```cmake -B build -DDOWNLOAD_LOCAL_JKQTPlotter=ON -DCMAKE_POLICY_VERSION_MINIMUM=3.5 -DJKQtPlotter_ENABLED_CXX20=ON "-DCMAKE_PREFIX_PATH=<path_to_your_qt_sources>"```<br><br>
Или через qtcreator:<br>
  Нужно добавить флаги для конфигурации:<br>
  
      * DOWNLOAD_LOCAL_JKQTPlotter ON (BOOL)
      * JKQtPlotter_ENABLED_CXX20 ON (BOOL)
      * CMAKE_POLICY_VERSION_MINIMUM 3.5 (STR)

2. Вариант 2: Использовать уже установленный JKQTPlotter.<br> В проекте(без весомых причин) используются некоторые вещи из C++ 20.<br>
Для JKQTPlotter поддержки C++20 по дефолту нету, поэтому JKQTPlotter должен быть сконфигурирован с флагом<br>
```-DJKQtPlotter_ENABLED_CXX20=ON.```<br> (Подробнее [тут](https://github.com/jkriege2/JKQtPlotter/issues/138))<br>
```cmake -B build```

2) Компиляция:
```cmake --build build # -jxx количество xx можно узнать nproc```

<img width="809" height="635" alt="Screenshot from 2025-08-05 06-23-13" src="https://github.com/user-attachments/assets/a0bdf05f-8e3d-4e12-a72d-4e9c26106176" />
<img width="809" height="635" alt="Screenshot from 2025-08-05 06-24-04" src="https://github.com/user-attachments/assets/2d01b489-46ee-448e-9f1c-980d262b1b72" />
<img width="809" height="635" alt="Screenshot from 2025-08-05 06-24-29" src="https://github.com/user-attachments/assets/33f2f77c-aabd-4216-bdd5-5aeff960e7c1" />
<img width="1043" height="624" alt="Screenshot from 2025-08-05 06-25-03" src="https://github.com/user-attachments/assets/d4ea07ae-834f-42f5-91f9-00373c92a407" />
<img width="1043" height="624" alt="Screenshot from 2025-08-05 06-25-10" src="https://github.com/user-attachments/assets/a71e7591-65e4-4432-af5f-40f19b7bf58c" />
<img width="1043" height="624" alt="Screenshot from 2025-08-05 06-25-14" src="https://github.com/user-attachments/assets/25a2f53c-7184-4130-b671-17f8b7f3d438" />
