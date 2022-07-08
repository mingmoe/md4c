
try{
    Write-Host "build for EightLeggedEssay..."

    if(-not(Test-Path "build" -PathType Container)){
        New-Item -Type Directory build
    }
    if(-not(Test-Path "output" -PathType Container)){
        New-Item -Type Directory output
    }

    Set-Location build

    &cmake -S .. -B . -DCMAKE_BUILD_TYPE=Release -DBUILD_SHARED_LIBS=OFF

    &cmake --build . --config Release

}
finally{
    Set-Location $PSScriptRoot
}