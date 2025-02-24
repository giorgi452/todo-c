!define APPNAME "TodoC"
!define APPVERSION "1.0"
!define INSTALLDIR "$PROGRAMFILES\TodoC"

Outfile "TodoC-Installer.exe"
InstallDir "${INSTALLDIR}"

Section "Install"
    SetOutPath $INSTDIR
    File /r "bin\*"
    File /r "assets\*"
    WriteUninstaller "$INSTDIR\Uninstall.exe"
SectionEnd

Section "Uninstall"
    Delete "$INSTDIR\TodoC.exe"
    Delete "$INSTDIR\Uninstall.exe"
    RMDir /r "$INSTDIR"
SectionEnd

