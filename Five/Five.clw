; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CFiveDlg
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "Five.h"

ClassCount=4
Class1=CFiveApp
Class2=CFiveDlg
Class3=CAboutDlg

ResourceCount=3
Resource1=IDD_ABOUTBOX
Resource2=IDR_MAINFRAME
Resource3=IDD_FIVE_DIALOG

[CLS:CFiveApp]
Type=0
HeaderFile=Five.h
ImplementationFile=Five.cpp
Filter=N

[CLS:CFiveDlg]
Type=0
HeaderFile=FiveDlg.h
ImplementationFile=FiveDlg.cpp
Filter=D
BaseClass=CDialog
VirtualFilter=dWC

[CLS:CAboutDlg]
Type=0
HeaderFile=FiveDlg.h
ImplementationFile=FiveDlg.cpp
Filter=D

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

[DLG:IDD_FIVE_DIALOG]
Type=1
Class=CFiveDlg
ControlCount=1
Control1=IDC_START,button,1342242816

