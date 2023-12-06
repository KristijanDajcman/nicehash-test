# Test 2

Run with `./Test2-Win10 [number of threads] [path to data] `
For example `./Test2-Win10.exe 1 Test2.txt`

## System information
- OS: Arch Linux<br> 
- IDE: Visual Studio<br> 
- Compiler: MSVC

## Execution time difference

**5 Experiments per thread.**
| Threads |  1st  |  2nd  |  3rd  |  4th  |  5th  |  Average  |
|:-------:|:-----:|:-----:|:-----:|:-----:|:-----:|:---------:|
|    1    |  1650 |  1658 |  1812 |  1710 |  1782 |   1722,4  |
|    2    |  1649 |  2421 |  2255 |  2387 |  2168 |   2176,0  |
|    3    |  2327 |  2511 |  2658 |  2796 |  2323 |   2523,0  |
|    4    |  2672 |  2943 |  2719 |  2885 |  2399 |   2723,6  |
