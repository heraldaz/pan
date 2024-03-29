; -- pan.iss --

[Setup]

AppName=Pan
AppVerName=Pan 0.139
AppPublisher=Charles Kerr
AppPublisherURL=http://pan.rebelbase.com/
AppCopyright=Copyright (C) 2003 Charles Kerr
AppSupportURL=http://pan.rebelbase.com/
AppUpdatesURL=http://pan.rebelbase.com/download/

OutputBaseFilename=Pan-0.139-setup
OutputDir=c:\

LicenseFile=c:\msys\1.0\home\shk\pan\COPYING
InfoBeforeFile=c:\msys\1.0\\home\shk\pan\README.windows

DefaultDirName={pf}\Pan
DefaultGroupName=Pan
Compression=bzip/9
AllowNoIcons=yes

; what a bunch of nervous default settings...
DisableStartupPrompt=yes
DisableDirPage=yes
AlwaysRestart=no


[Tasks]

Name: "desktopicon"; Description: "Create a &desktop icon"; GroupDescription: "Additional icons:"; Flags: unchecked
Name: "quicklaunchicon"; Description: "Create a &Quick Launch icon"; GroupDescription: "Additional icons:"; Flags: unchecked

[Types]

Name: "type_english"; Description: "English-Language Only";
Name: "type_i18n"; Description: "All Languages"

[Components]

Name: "component_app"; Description: "Application Files"; Types: type_english type_i18n; Flags: fixed
Name: "component_i18n"; Description: "Language Translations"; Types: type_i18n

[Run]

;Filename: "{app}\Pan.exe"; Description: "Launch Pan"; Flags: waituntilidle postinstall

[Registry]
; This adds the GTK+ libraries to Pan.exe's path
Root: HKLM; Subkey: "Software\Microsoft\Windows\CurrentVersion\App Paths\Pan.exe"; Flags: uninsdeletekeyifempty
Root: HKLM; Subkey: "Software\Microsoft\Windows\CurrentVersion\App Paths\Pan.exe"; ValueType: string; ValueData: "{app}\Pan.exe"; Flags: uninsdeletevalue
Root: HKLM; Subkey: "Software\Microsoft\Windows\CurrentVersion\App Paths\Pan.exe"; ValueType: string; ValueName: "Path"; ValueData: "{app};{code:GetGtkPath}\lib;{code:GetGtkPath}\bin"; Flags: uninsdeletevalue

[Files]

Source: "c:\msys\1.0\home\shk\pan\pan\Pan.exe"; DestDir: "{app}"; Components: component_app; Flags: ignoreversion
Source: "c:\msys\1.0\home\shk\pan\Pan.ico"; DestDir: "{app}"; Components: component_app; Flags: ignoreversion
Source: "c:\msys\1.0\home\shk\pan\Changelog"; DestDir: "{app}"; Components: component_app; Flags: ignoreversion
Source: "c:\msys\1.0\home\shk\pan\COPYING"; DestDir: "{app}"; Components: component_app; Flags: ignoreversion
Source: "c:\msys\1.0\home\shk\pan\CREDITS"; DestDir: "{app}"; Components: component_app; Flags: ignoreversion
Source: "c:\msys\1.0\home\shk\pan\README.windows"; DestDir: "{app}"; DestName: "README.txt"; Components: component_app; Flags: ignoreversion
Source: "c:\msys\1.0\opt\pcre\bin\pcre.dll"; DestDir: "{sys}"; Components: component_app; Flags: onlyifdoesntexist
Source: "c:\msys\1.0\home\shk\pan\po\ca.mo"; DestDir: "{reg:HKLM\SOFTWARE\GTK\2.0,Path|{app}}\share\locale\ca\LC_MESSAGES\"; DestName: "pan.mo"; Components: component_i18n; Flags: ignoreversion
Source: "c:\msys\1.0\home\shk\pan\po\cs.mo"; DestDir: "{reg:HKLM\SOFTWARE\GTK\2.0,Path|{app}}\share\locale\cs\LC_MESSAGES\"; DestName: "pan.mo"; Components: component_i18n; Flags: ignoreversion
Source: "c:\msys\1.0\home\shk\pan\po\da.mo"; DestDir: "{reg:HKLM\SOFTWARE\GTK\2.0,Path|{app}}\share\locale\da\LC_MESSAGES\"; DestName: "pan.mo"; Components: component_i18n; Flags: ignoreversion
Source: "c:\msys\1.0\home\shk\pan\po\de.mo"; DestDir: "{reg:HKLM\SOFTWARE\GTK\2.0,Path|{app}}\share\locale\de\LC_MESSAGES\"; DestName: "pan.mo"; Components: component_i18n; Flags: ignoreversion
Source: "c:\msys\1.0\home\shk\pan\po\el.mo"; DestDir: "{reg:HKLM\SOFTWARE\GTK\2.0,Path|{app}}\share\locale\el\LC_MESSAGES\"; DestName: "pan.mo"; Components: component_i18n; Flags: ignoreversion
Source: "c:\msys\1.0\home\shk\pan\po\en_GB.mo"; DestDir: "{reg:HKLM\SOFTWARE\GTK\2.0,Path|{app}}\share\locale\en_GB\LC_MESSAGES\"; DestName: "pan.mo"; Components: component_i18n; Flags: ignoreversion
Source: "c:\msys\1.0\home\shk\pan\po\es.mo"; DestDir: "{reg:HKLM\SOFTWARE\GTK\2.0,Path|{app}}\share\locale\es\LC_MESSAGES\"; DestName: "pan.mo"; Components: component_i18n; Flags: ignoreversion
Source: "c:\msys\1.0\home\shk\pan\po\et.mo"; DestDir: "{reg:HKLM\SOFTWARE\GTK\2.0,Path|{app}}\share\locale\et\LC_MESSAGES\"; DestName: "pan.mo"; Components: component_i18n; Flags: ignoreversion
Source: "c:\msys\1.0\home\shk\pan\po\fi.mo"; DestDir: "{reg:HKLM\SOFTWARE\GTK\2.0,Path|{app}}\share\locale\fi\LC_MESSAGES\"; DestName: "pan.mo"; Components: component_i18n; Flags: ignoreversion
Source: "c:\msys\1.0\home\shk\pan\po\fr.mo"; DestDir: "{reg:HKLM\SOFTWARE\GTK\2.0,Path|{app}}\share\locale\fr\LC_MESSAGES\"; DestName: "pan.mo"; Components: component_i18n; Flags: ignoreversion
Source: "c:\msys\1.0\home\shk\pan\po\ga.mo"; DestDir: "{reg:HKLM\SOFTWARE\GTK\2.0,Path|{app}}\share\locale\ga\LC_MESSAGES\"; DestName: "pan.mo"; Components: component_i18n; Flags: ignoreversion
Source: "c:\msys\1.0\home\shk\pan\po\gl.mo"; DestDir: "{reg:HKLM\SOFTWARE\GTK\2.0,Path|{app}}\share\locale\gl\LC_MESSAGES\"; DestName: "pan.mo"; Components: component_i18n; Flags: ignoreversion
Source: "c:\msys\1.0\home\shk\pan\po\hu.mo"; DestDir: "{reg:HKLM\SOFTWARE\GTK\2.0,Path|{app}}\share\locale\hu\LC_MESSAGES\"; DestName: "pan.mo"; Components: component_i18n; Flags: ignoreversion
Source: "c:\msys\1.0\home\shk\pan\po\it.mo"; DestDir: "{reg:HKLM\SOFTWARE\GTK\2.0,Path|{app}}\share\locale\it\LC_MESSAGES\"; DestName: "pan.mo"; Components: component_i18n; Flags: ignoreversion
Source: "c:\msys\1.0\home\shk\pan\po\ja.mo"; DestDir: "{reg:HKLM\SOFTWARE\GTK\2.0,Path|{app}}\share\locale\ja\LC_MESSAGES\"; DestName: "pan.mo"; Components: component_i18n; Flags: ignoreversion
Source: "c:\msys\1.0\home\shk\pan\po\ko.mo"; DestDir: "{reg:HKLM\SOFTWARE\GTK\2.0,Path|{app}}\share\locale\ko\LC_MESSAGES\"; DestName: "pan.mo"; Components: component_i18n; Flags: ignoreversion
Source: "c:\msys\1.0\home\shk\pan\po\lt.mo"; DestDir: "{reg:HKLM\SOFTWARE\GTK\2.0,Path|{app}}\share\locale\lt\LC_MESSAGES\"; DestName: "pan.mo"; Components: component_i18n; Flags: ignoreversion
Source: "c:\msys\1.0\home\shk\pan\po\nl.mo"; DestDir: "{reg:HKLM\SOFTWARE\GTK\2.0,Path|{app}}\share\locale\nl\LC_MESSAGES\"; DestName: "pan.mo"; Components: component_i18n; Flags: ignoreversion
Source: "c:\msys\1.0\home\shk\pan\po\no.mo"; DestDir: "{reg:HKLM\SOFTWARE\GTK\2.0,Path|{app}}\share\locale\no\LC_MESSAGES\"; DestName: "pan.mo"; Components: component_i18n; Flags: ignoreversion
Source: "c:\msys\1.0\home\shk\pan\po\pl.mo"; DestDir: "{reg:HKLM\SOFTWARE\GTK\2.0,Path|{app}}\share\locale\pl\LC_MESSAGES\"; DestName: "pan.mo"; Components: component_i18n; Flags: ignoreversion
Source: "c:\msys\1.0\home\shk\pan\po\pt.mo"; DestDir: "{reg:HKLM\SOFTWARE\GTK\2.0,Path|{app}}\share\locale\pt\LC_MESSAGES\"; DestName: "pan.mo"; Components: component_i18n; Flags: ignoreversion
Source: "c:\msys\1.0\home\shk\pan\po\pt_BR.mo"; DestDir: "{reg:HKLM\SOFTWARE\GTK\2.0,Path|{app}}\share\locale\pt_BR\LC_MESSAGES\"; DestName: "pan.mo"; Components: component_i18n; Flags: ignoreversion
Source: "c:\msys\1.0\home\shk\pan\po\ru.mo"; DestDir: "{reg:HKLM\SOFTWARE\GTK\2.0,Path|{app}}\share\locale\ru\LC_MESSAGES\"; DestName: "pan.mo"; Components: component_i18n; Flags: ignoreversion
Source: "c:\msys\1.0\home\shk\pan\po\sk.mo"; DestDir: "{reg:HKLM\SOFTWARE\GTK\2.0,Path|{app}}\share\locale\sk\LC_MESSAGES\"; DestName: "pan.mo"; Components: component_i18n; Flags: ignoreversion
Source: "c:\msys\1.0\home\shk\pan\po\sl.mo"; DestDir: "{reg:HKLM\SOFTWARE\GTK\2.0,Path|{app}}\share\locale\sl\LC_MESSAGES\"; DestName: "pan.mo"; Components: component_i18n; Flags: ignoreversion
Source: "c:\msys\1.0\home\shk\pan\po\sr.mo"; DestDir: "{reg:HKLM\SOFTWARE\GTK\2.0,Path|{app}}\share\locale\sr\LC_MESSAGES\"; DestName: "pan.mo"; Components: component_i18n; Flags: ignoreversion
Source: "c:\msys\1.0\home\shk\pan\po\sv.mo"; DestDir: "{reg:HKLM\SOFTWARE\GTK\2.0,Path|{app}}\share\locale\sv\LC_MESSAGES\"; DestName: "pan.mo"; Components: component_i18n; Flags: ignoreversion
Source: "c:\msys\1.0\home\shk\pan\po\tr.mo"; DestDir: "{reg:HKLM\SOFTWARE\GTK\2.0,Path|{app}}\share\locale\tr\LC_MESSAGES\"; DestName: "pan.mo"; Components: component_i18n; Flags: ignoreversion
Source: "c:\msys\1.0\home\shk\pan\po\uk.mo"; DestDir: "{reg:HKLM\SOFTWARE\GTK\2.0,Path|{app}}\share\locale\uk\LC_MESSAGES\"; DestName: "pan.mo"; Components: component_i18n; Flags: ignoreversion
Source: "c:\msys\1.0\home\shk\pan\po\vi.mo"; DestDir: "{reg:HKLM\SOFTWARE\GTK\2.0,Path|{app}}\share\locale\vi\LC_MESSAGES\"; DestName: "pan.mo"; Components: component_i18n; Flags: ignoreversion
Source: "c:\msys\1.0\home\shk\pan\po\zh_CN.mo"; DestDir: "{reg:HKLM\SOFTWARE\GTK\2.0,Path|{app}}\share\locale\zh_CN\LC_MESSAGES\"; DestName: "pan.mo"; Components: component_i18n; Flags: ignoreversion

[Icons]

Name: "{group}\pan"; Filename: "{app}\Pan.exe"; WorkingDir: "{app}"; IconFilename: "{app}\Pan.ico"
Name: "{group}\Uninstall Pan"; Filename: "{uninstallexe}"
Name: "{userdesktop}\Pan"; Filename: "{app}\Pan.exe"; WorkingDir: "{app}"; IconFilename: "{app}\Pan.ico"; Tasks: desktopicon
Name: "{userappdata}\Microsoft\Internet Explorer\Quick Launch\Pan"; Filename: "{app}\Pan.exe"; WorkingDir: "{app}"; Tasks: quicklaunchicon


[UninstallDelete]

Type: filesandordirs; Name: "{app}\.pan"
Type: dirifempty; Name: "{app}"

[Code]

var
  Exists: Boolean;
  GtkPath: String;

function GetGtkInstalled (): Boolean;
begin
  Exists := RegQueryStringValue (HKLM, 'Software\GTK\2.0', 'Path', GtkPath);
  if not Exists then begin
    Exists := RegQueryStringValue (HKCU, 'Software\GTK\2.0', 'Path', GtkPath);
  end;
   Result := Exists
end;

function GetGtkPath (S: String): String;
begin
    Result := GtkPath;
end;

function InitializeSetup(): Boolean;
begin
  Result := GetGtkInstalled ();
  if not Result then begin
    MsgBox ('Pan requires the GTK+ 2.2 Runtime Environment from http://www.dropline.net/gtk/.', mbError, MB_OK);
  end;
end;

