# SecondFLTK
Expanding FLTK-First-Simple with Slider. Experimenting

In order to build this, in Visual Studio:
it needs fltk libraries to be set under 'project properties'  -->Configuration Properties--> Include Directories
                                                              -->Configuration Properties--> Library Directories
and other settings:
//
// In Project Properties add the following:
// Configuration Properties/ VC++ Directories/Include Directories:
// C:\...\fltk-1.3.3
// Configuration Properties/ VC++ Directories/Library Directories:
// C:\...\fltk-1.3.3\lib
//
// Linker/Input/Additional Dependencies:
//fltkd.lib
//wsock32.lib
//comctl32.lib
//fltkjpegd.lib
//fltkimagesd.lib
//
// In the above - 'd' stands for debug. So fltkd.lib is debug version. release version without the 'd'
//
