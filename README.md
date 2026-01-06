Tested only on Linux(Arch, Debian). Probably easily portable for Windows.

How to compile:<br>
  ```cmake -B build -DDOWNLOAD_LOCAL_JKQTPlotter=ON -DCMAKE_POLICY_VERSION_MINIMUM=3.5 -DJKQtPlotter_ENABLED_CXX20=ON "-DCMAKE_PREFIX_PATH=<path_to_your_qt_sources>"```<br><br>
```cmake --build build # -jxx where xx is number of threads. You can use nproc to check how much you have```

Additional info on compilation:<br>
If you want to compile via qtcreator, you need to add configuration options::<br>
  
      * DOWNLOAD_LOCAL_JKQTPlotter ON (BOOL)
      * JKQtPlotter_ENABLED_CXX20 ON (BOOL)
      * CMAKE_POLICY_VERSION_MINIMUM 3.5 (STR)
      
You can compile with your own version of JKQTPlotter, but it(JKQTPlotter) should be compiled with this flag<br>
```-DJKQtPlotter_ENABLED_CXX20=ON.```<br> (More info on it [here](https://github.com/jkriege2/JKQtPlotter/issues/138))<br>


<img width="1026" height="589" alt="Screenshot_20251124_142622" src="https://github.com/user-attachments/assets/d2e5a0a8-981e-492f-baac-decfb5ddc805" />
<img width="1026" height="589" alt="Screenshot_20251124_142614" src="https://github.com/user-attachments/assets/f836386f-35a2-4df9-b985-8d6d528b67ff" />
<img width="1026" height="589" alt="Screenshot_20251124_142602" src="https://github.com/user-attachments/assets/3e4fa2db-d894-441b-86bf-a0b12a6acf87" />
<img width="797" height="623" alt="Screenshot_20251124_142521" src="https://github.com/user-attachments/assets/cd417ea4-5243-4aa0-821b-488d7eb89a5d" />
<img width="797" height="622" alt="Screenshot_20251124_142423" src="https://github.com/user-attachments/assets/573e1e9f-809d-41db-a048-b4d40111382d" />
<img width="797" height="622" alt="Screenshot_20251124_142349" src="https://github.com/user-attachments/assets/4303f546-20ec-4782-b7ae-bc585a1f6a8b" />
