# Sample script to install Python and pip under Windows
# Authors: Olivier Grisel and Kyle Kastner
# License: CC0 1.0 Universal: http://creativecommons.org/publicdomain/zero/1.0/

$BASE_URL = "https://www.python.org/ftp/python/"
$GET_PIP_URL = "https://bootstrap.pypa.io/get-pip.py"
$GET_PIP_PATH = "C:\get-pip.py"
$MPIR_GITHUB = "https://github.com/Legrandin/mpir-windows-builds/raw/master/"

function DownloadPython ($python_version, $platform_suffix) {
    $webclient = New-Object System.Net.WebClient
    $filename = "python-" + $python_version + $platform_suffix + ".msi"
    $url = $BASE_URL + $python_version + "/" + $filename

    $basedir = $pwd.Path + "\"
    $filepath = $basedir + $filename
    if (Test-Path $filename) {
        Write-Host "Reusing" $filepath
        return $filepath
    }

    # Download and retry up to 5 times in case of network transient errors.
    Write-Host "Downloading" $filename "from" $url
    $retry_attempts = 3
    for($i=0; $i -lt $retry_attempts; $i++){
        try {
            $webclient.DownloadFile($url, $filepath)
            break
        }
        Catch [Exception]{
            Start-Sleep 1
        }
   }
   Write-Host "File saved at" $filepath
   return $filepath
}


function InstallPython ($python_version, $architecture, $python_home) {
    Write-Host "Installing Python" $python_version "for" $architecture "bit architecture to" $python_home
    if (Test-Path $python_home) {
        Write-Host $python_home "already exists, skipping."
        return $false
    }
    if ($architecture -eq "32") {
        $platform_suffix = ""
    } else {
        $platform_suffix = ".amd64"
    }
    $filepath = DownloadPython $python_version $platform_suffix
    Write-Host "Installing" $filepath "to" $python_home
    $args = "/qn /i $filepath TARGETDIR=$python_home"
    Write-Host "msiexec.exe" $args
    Start-Process -FilePath "msiexec.exe" -ArgumentList $args -Wait -Passthru
    Write-Host "Python $python_version ($architecture) installation complete"
    return $true
}


function InstallPip ($python_home) {
    $pip_path = $python_home + "/Scripts/pip.exe"
    $python_path = $python_home + "/python.exe"
    if (-not(Test-Path $pip_path)) {
        Write-Host "Installing pip..."
        $webclient = New-Object System.Net.WebClient
        $webclient.DownloadFile($GET_PIP_URL, $GET_PIP_PATH)
        Write-Host "Executing:" $python_path $GET_PIP_PATH
        Start-Process -FilePath "$python_path" -ArgumentList "$GET_PIP_PATH" -Wait -Passthru
    } else {
        Write-Host "pip already installed."
    }
}

function InstallPackage ($python_home, $pkg) {
    $pip_path = $python_home + "/Scripts/pip.exe"
    & $pip_path install $pkg
}

function InstallMPIR ($python_version, $architecture, $target_dir) {
    $pyver = $python_version.split(".")
    if ($pyver[0] -gt 2) {
	  if ($pyver[1] -gt 4 ) {
		$vs = "VS2015"
      } else {
		$vs = "VS2010"
	  }
    } else {
      $vs = "VS2008"
    }
    $download_uri = $MPIR_GITHUB + "mpir-2.6.0_" + $vs + "_" + $architecture + "/mpir.dll"
    Write-Host "Downloading MPIR from " $download_uri
    $webclient = New-Object System.Net.WebClient
    $webclient.DownloadFile($download_uri, $target_dir + "\mpir.dll")
}

function main () {
    InstallPython $env:PYTHON_VERSION $env:PYTHON_ARCH $env:PYTHON
    InstallPip $env:PYTHON
    InstallPackage $env:PYTHON wheel

    New-Item -ItemType directory "C:\mpir"
    InstallMPIR $env:PYTHON_VERSION $env:PYTHON_ARCH "C:\mpir"
}

main
