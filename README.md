# Odd-Even-Sort-with-MPI
利用MPI实现奇偶排序算法
# 运行
在第一个目录（即只有一个makefile文件的目录）运行`make run`
# 修改参数
你可以通过修改`include`目录中的`parameters.h`中的`N`的值来改变问题的规模，可以通过修改第一个目录中的`makefile`中的`THREAD`来改变线程的数量
# 输出说明
`output_serial.m`:`version`为程序的版本，矩阵的第一行为排序前的数，第二行为排序后的数，`serial_sec`为排序消耗的时间，单位是ms，该版本为串行程序的输出；

`output_parallel.m`同`output_serial.m`，但该版本为mpi版本的输出。
