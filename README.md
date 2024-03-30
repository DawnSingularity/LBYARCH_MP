


debug mode 
--------------
Size: 20
Average execution time (C): 0.003400 seconds
Average execution time (Assembly): 0.003467 seconds

Analysis: since the values are quite short they won't have any significant differences with their execution time.


Size: 24
Average execution time (C): 0.054233 seconds
Average execution time (Assembly): 0.053833 seconds

Analysis: with the significantly larger value compared to the previous one we are still in the margin of error of their execution time but assembly being a bit more faster compared to C



Size: 28
Average execution time (C): 0.935133 seconds
Average execution time (Assembly): 0.910233 seconds


Analysis: As the size increases, the C implementation may become less efficient due to memory access patterns, while the assembly implementation's fine-grained control may lead to more stable and potentially faster performance.



![App Screenshot](https://github.com/DawnSingularity/LBYARCH_MP/blob/main/screenshot/Screenshot%20correctness%20debug%20mode.png)


----------------------------------------------------------------------




release mode 
--------------
size 20
Average execution time (C): 0.000767 seconds
Average execution time (Assembly): 0.001933 seconds
Analysis: Both implementations show improved performance compared to debug mode.
	   Assembly execution time is notably slower than in debug mode, possibly due to different optimizations in release mode.


size 24
Average execution time (C): 0.013400 seconds
Average execution time (Assembly): 0.025533 seconds
Analysis: Performance improves in both implementations compared to debug mode.
	  Assembly execution time is noticeably faster than C, but the gap is not as significant as in debug mode.


size 28
Average execution time (C): 0.226233 seconds
Average execution time (Assembly): 0.454467 seconds
Analysis: The differences in execution times become even more pronounced in release mode, with Assembly significantly slower than C. This unexpected result could indicate that the Assembly implementation may not be fully optimized for this size, or there could be other factors at play, such as memory access patterns or compiler optimizations.





![App Screenshot](https://github.com/DawnSingularity/LBYARCH_MP/blob/main/screenshot/screenshot%20correctness%20release%20mode.png)
