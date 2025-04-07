"C:\Program Files (x86)\Microsoft Visual Studio\2022\BuildTools\MSBuild\Current\Bin\msbuild.exe" KAP.vcxproj /p:Configuration=Release /p:Platform=win32
copy Release\KAP.dll .
rd /s /q KAP Release