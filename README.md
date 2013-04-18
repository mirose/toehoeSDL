/******* PROJECT TOEHOE ***********/

/****( insert toehoe ascii art here )*****/


Setting up visual studio with SDL note:

1) make new empty project

2) config properties > vc++ dir > include dir > choose SDL include path

3) config properties > vc++ dir > lib dir > choose SDL lib dir

4) config properties > linker > input > additional dep. > add .lib files

5) config properties > linker > system > subsystem > windows

6) add .cpp file > config properties > c/c++ code gen > runtime lib > multi thread dll /md

