
Imports System.Runtime.InteropServices

Module ModJoystick

    ' ------------------------------------------------------
    '
    ' Funciones relaciondas con el manejo del Joystick
    ' http://www.lawebdelprogramador.com/temas/joystick.php
    '
    ' Estos DOS son los que hay que utilizar:
    ' https://social.msdn.microsoft.com/Forums/vstudio/en-US/af28b35b-d756-4d87-94c6-ced882ab20a5/reading-input-data-from-joystick-in-visual-basic?forum=vbgeneral
    ' http://settorezero.blogspot.com.es/2010/11/using-joysticks-from-vbnet.html
    '
    ' ------------------------------------------------------

    Declare Function joyGetPosEx Lib "winmm.dll" (ByVal uJoyID As Integer, ByRef pji As JOYINFOEX) As Integer

    <StructLayout(LayoutKind.Sequential)> _
    Public Structure JOYINFOEX
        Public dwSize As Integer
        Public dwFlags As Integer
        Public dwXpos As Integer
        Public dwYpos As Integer
        Public dwZpos As Integer
        Public dwRpos As Integer
        Public dwUpos As Integer
        Public dwVpos As Integer
        Public dwButtons As Integer
        Public dwButtonNumber As Integer
        Public dwPOV As Integer
        Public dwReserved1 As Integer
        Public dwReserved2 As Integer
    End Structure




    ' ------------------------------------------------------
    '
    ' FN_GetJoystick()
    '
    ' ------------------------------------------------------

    Public Function FN_GetJoystick() As Integer

        Stop
        Dim myjoyEX As JOYINFOEX


        Call joyGetPosEx(0, myjoyEX)


        FN_GetJoystick = 4

    End Function






End Module