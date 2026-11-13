%module(directors="1") blackboxn
%{
/* Includes the header in the wrapper code */
#include "blackbox/blackbox.hpp"
%}

%feature("director") SimplifiedMessageHandler;
%include "std_string.i"
%include "typemaps.i"

//uint&
//%typemap(cstype, out="$csclassname") unsigned int *OUTPUT2, unsigned int &OUTPUT2 "out uint"
//%typemap(csin) unsigned int *OUTPUT2, unsigned int &OUTPUT2 "out $csinput"
//%typemap(ctype, out="unsigned int *") unsigned int *OUTPUT2, unsigned int &OUTPUT2 "unsigned int *"
//%typemap(imtype, out="global::System.IntPtr") unsigned int *OUTPUT2, unsigned int &OUTPUT2 "out uint"

/* Parse the header file to generate wrappers */
#define BBAPI 
%include "blackbox/blackbox.hpp"
