! Компилировал только под Linux, на Windows не пробовал, но никаких специфичных для линукса вещей вроде не использовалось

Комиляция:
1) Конфигурация:<br>
* У програмки есть зависимость от [JKQTPlotter](https://github.com/jkriege2/JKQtPlotter). Поэтому есть 2 варианта конфигурации:

1. Вариант 1: Скачать JKQTPlotter в build директорию автоматически через cmake:<br>
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

<img width="1026" height="589" alt="Screenshot_20251124_142622" src="https://github.com/user-attachments/assets/d2e5a0a8-981e-492f-baac-decfb5ddc805" />
<img width="1026" height="589" alt="Screenshot_20251124_142614" src="https://github.com/user-attachments/assets/f836386f-35a2-4df9-b985-8d6d528b67ff" />
<img width="1026" height="589" alt="Screenshot_20251124_142602" src="https://github.com/user-attachments/assets/3e4fa2db-d894-441b-86bf-a0b12a6acf87" />
<img width="797" height="623" alt="Screenshot_20251124_142521" src="https://github.com/user-attachments/assets/cd417ea4-5243-4aa0-821b-488d7eb89a5d" />
<img width="797" height="622" alt="Screenshot_20251124_142423" src="https://github.com/user-attachments/assets/573e1e9f-809d-41db-a048-b4d40111382d" />
<img width="797" height="622" alt="Screenshot_20251124_142349" src="https://github.com/user-attachments/assets/4303f546-20ec-4782-b7ae-bc585a1f6a8b" />
