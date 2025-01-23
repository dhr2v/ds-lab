
@echo off
REM Create 'Output' folder if it doesn't exist
if not exist "Output" (
    mkdir Output
)

REM Compile all .c files using gcc
for %%f in (*.c) do (
    REM Extract filename without extension
    set "filename=%%~nf"
    echo Compiling C file: %%f
    gcc "%%f" -o "Output\%%~nf.exe"
    if errorlevel 1 (
        echo Error compiling C file: %%f
        goto next_c
    )
    REM Run the program, save output to text file
    "Output\%%~nf.exe" > "Output\%%~nf_output.txt"

    REM Convert the output text file to an image using ImageMagick
    convert -background white -fill black -font Courier -pointsize 12 text:"Output\%%~nf_output.txt" "Output\%%~nf_output.png"

    :next_c
)

echo Compilation and output generation complete!
pause
