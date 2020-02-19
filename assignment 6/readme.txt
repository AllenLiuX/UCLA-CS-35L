===Things to Notice===
1. First, I met a problem of transforming 1D array into 3D array. However, I used the pointer to pointer to solve this problem, which I declared as 'float*** FINAL_COLOR'.

2. When processing shared data, we can use global variables that different threads can access it in parallel. Since the color and the number of thread and the scene is processed with multithreads, we can declare it at the beginning with:
float*** FINAL_COLOR;
int nthreads=1;
scene_t scene;

3. I forgot to free the memory of the pointer and hence has the wrong output. Therefore, remember to free the memory of all the allocated after processing the threads:
free_scene( &scene );
    for(m=0;m<width;m++)
    {
        for(n=0;n<height;n++)
        {
            free(FINAL_COLOR[m][n]);
        }
        free(FINAL_COLOR[m]);
    }
    free(FINAL_COLOR);



===Conclusion===
The performance of the SRT with different numbers of threads is as followed:
time ./srt 1-test.ppm >1-test.ppm.tmp

real	0m43.090s
user	0m43.083s
sys	0m0.001s
mv 1-test.ppm.tmp 1-test.ppm
time ./srt 2-test.ppm >2-test.ppm.tmp

real	0m21.528s
user	0m42.801s
sys	0m0.010s
mv 2-test.ppm.tmp 2-test.ppm
time ./srt 4-test.ppm >4-test.ppm.tmp

real	0m11.403s
user	0m44.794s
sys	0m0.002s
mv 4-test.ppm.tmp 4-test.ppm
time ./srt 8-test.ppm >8-test.ppm.tmp

real	0m5.788s
user	0m44.650s
sys	0m0.016s

It shows that the real time is greatly shortened as the number of threads increases. 
Comparing the performance of ones with 8 threads and 1 thread, one thread takes about 8 times more real time than 1 thread.
It is because more threads can process the data simultaneously and increase the efficiency.
Therefore, the more the threads are, the better the performance is.

