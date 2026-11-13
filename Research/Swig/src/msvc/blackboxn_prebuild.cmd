@echo off

cd ..\blackbox_net
mkdir swig
if "%SWIG%" EQU "" (
	set SWIG=W:\f8\swigwin\swig.exe
)
set SWIG_INCLUDE=..\..\include
set SWIG_CXX_OUTPUT=blackboxn_wrap
set SWIG_INPUT=blackboxn.i
set SWIG_OPTIONS=-c++ -cpperraswarn -csharp -namespace blackbox_net -outdir swig -I%SWIG_INCLUDE% -o %SWIG_CXX_OUTPUT%.cpp 
set SWIG_CMD=%SWIG% %SWIG_OPTIONS% %SWIG_INPUT%

set Configuration=%2
set Platform=%3
set OutDir=%4

set lost=0
for %%i in (%SWIG_CXX_OUTPUT%.cpp 
			%SWIG_CXX_OUTPUT%.h 
			swig\blackboxn.cs
			swig\blackboxnPINVOKE.cs) do (
		if not exist %%i (
			set lost=1  
			echo %%i   NOT exist   
		) else (
			echo %%i   exist
		)
)

set needBuild=0
set needClean=0

echo going to do [%1]

if %1 EQU clean (
	set needClean=1
	set needBuild=0
)

if %1 EQU rebuild (
	set needClean=1
	set needBuild=1
)

if %1 EQU build (
	if %lost% == 1 (
		set needClean=1
		set needBuild=1
	)
)

if %needClean% == 1 (

	echo ************going to clean************
	for %%i in (%SWIG_CXX_OUTPUT%.cpp 
			%SWIG_CXX_OUTPUT%.h 
			swig\blackboxn.cs
			swig\blackboxnPINVOKE.cs) do (
		if exist %%i (			
			echo going to del %%i
			del %%i
		) 
	)
	echo ************  clean end  ************
)

if %needBuild% == 1 (

echo ************going to generate************

		%SWIG_CMD%

echo ************  generate done  ************

)
