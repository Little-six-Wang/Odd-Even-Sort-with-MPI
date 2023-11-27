# Odd-Even-Sort-with-MPI
利用MPI实现奇偶排序算法
# 运行
在第一个目录（即只有一个makefile文件的目录）运行`make run`

在该目录下打开`octave`，然后运行`diff`，如果想绘制图像，可以在`octave`中运行`plotTime`,`plotSpeedUpRatio`,`plotEfficiency`。
# 修改参数
你可以通过修改`include`目录中的`parameters.h`中的`N`的值来改变问题的规模，可以通过修改第一个目录中的`makefile`中的`THREAD`来改变线程的数量
# 输出说明
`output_serial.m`:`version`为程序的版本，矩阵的第一行为排序前的数，第二行为排序后的数，`serial_sec`为串行程序排序消耗的时间，单位是ms；
`output_parallel.m`同`output_serial.m`，但该版本为mpi版本的输出。
`result.txt`：第一个数为串行程序和并行程序排序结果的差的绝对值的最大值，该值用来观察并行程序结果是否正确从而判断该程序是否正确；第二个数为串行程序排序消耗的时间，单位为ms；第三个数为并行程序排序消耗的时间，单位为ms。
# 绘图
`plotTime.m`,`plotSpeedUpRatio.m`,`plotEfficiency.m`这三个程序是用来分析该并行程序的时间、加速比和效率随问题规模以及线程数的变化而变化，程序中的`x`,`y`是我实验获得的数据，可自行修改。
