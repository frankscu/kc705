%module(directors="1") daq
%{
#include <string>
#include <map>
#include <vector>

#include "daqTest.hh"
#include "JadeRegCtrl.hh"

#include "JadeSystem.hh"
%}

%import "std_string.i"
%import "std_map.i"
%import "std_pair.i"
%import "std_vector.i"
%import "stdint.i"

%include "typemaps.i"

%include "daqTest.hh"
%include "JadeRegCtrl.hh"


#define  DLLEXPORT
%include <windows.i>
%include "JadeSystem.hh"

