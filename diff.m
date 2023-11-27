output_parallel
output_serial

diff = max(mpi(2,:) - serial(2, :))
result = [diff serial_sec parallel_sec]
save result.txt result

clear all
close all
