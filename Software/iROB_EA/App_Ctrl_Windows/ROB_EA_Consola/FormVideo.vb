
Imports System.Runtime.InteropServices

Public Class FormVideo

    ' --------------------------------------------
    '
    '
    '
    ' --------------------------------------------
    Const WM_CAP As Short = &H400S
    Const WM_CAP_DRIVER_CONNECT As Integer = WM_CAP + 10
    Const WM_CAP_DRIVER_DISCONNECT As Integer = WM_CAP + 11
    Const WM_CAP_EDIT_COPY As Integer = WM_CAP + 30
    Const WM_CAP_GET_STATUS As Integer = WM_CAP + 54
    Const WM_CAP_DLG_VIDEOFORMAT As Integer = WM_CAP + 41
    Const WM_CAP_SET_PREVIEW As Integer = WM_CAP + 50
    Const WM_CAP_SET_PREVIEWRATE As Integer = WM_CAP + 52
    Const WM_CAP_SET_SCALE As Integer = WM_CAP + 53
    Const WS_CHILD As Integer = &H40000000
    Const WS_VISIBLE As Integer = &H10000000
    Const SWP_NOMOVE As Short = &H2S
    Const SWP_NOSIZE As Short = 1
    Const SWP_NOZORDER As Short = &H4S
    Const HWND_BOTTOM As Short = 1

    Private DeviceID As Integer = 0 ' Current device ID
    Private hHwnd As Integer ' Handle to preview window

    Declare Function SendMessage Lib "user32" Alias "SendMessageA" (ByVal hwnd As Integer, ByVal wMsg As Integer, ByVal wParam As Integer, ByRef lParam As CAPSTATUS) As Boolean
    Declare Function SendMessage Lib "user32" Alias "SendMessageA" (ByVal hwnd As Integer, ByVal wMsg As Integer, ByVal wParam As Boolean, ByRef lParam As Integer) As Boolean
    Declare Function SetWindowPos Lib "user32" Alias "SetWindowPos" (ByVal hwnd As Integer, ByVal hWndInsertAfter As Integer, ByVal x As Integer, ByVal y As Integer, ByVal cx As Integer, ByVal cy As Integer, ByVal wFlags As Integer) As Integer
    Declare Function DestroyWindow Lib "user32" (ByVal hndw As Integer) As Boolean
    Declare Function capCreateCaptureWindowA Lib "avicap32.dll" (ByVal lpszWindowName As String, ByVal dwStyle As Integer, ByVal x As Integer, ByVal y As Integer, ByVal nWidth As Integer, ByVal nHeight As Short, ByVal hWndParent As Integer, ByVal nID As Integer) As Integer
    Declare Function capGetDriverDescriptionA Lib "avicap32.dll" (ByVal wDriver As Short, ByVal lpszName As String, ByVal cbName As Integer, ByVal lpszVer As String, ByVal cbVer As Integer) As Boolean

    Structure POINTAPI
        Dim x As Integer
        Dim y As Integer
    End Structure

    Structure CAPSTATUS
        Dim uiImageWidth As Integer                    '// Width of the image
        Dim uiImageHeight As Integer                   '// Height of the image
        Dim fLiveWindow As Integer                     '// Now Previewing video?
        Dim fOverlayWindow As Integer                  '// Now Overlaying video?
        Dim fScale As Integer                          '// Scale image to client?
        Dim ptScroll As POINTAPI                    '// Scroll position
        Dim fUsingDefaultPalette As Integer            '// Using default driver palette?
        Dim fAudioHardware As Integer                  '// Audio hardware present?
        Dim fCapFileExists As Integer                  '// Does capture file exist?
        Dim dwCurrentVideoFrame As Integer             '// # of video frames cap'td
        Dim dwCurrentVideoFramesDropped As Integer     '// # of video frames dropped
        Dim dwCurrentWaveSamples As Integer            '// # of wave samples cap'td
        Dim dwCurrentTimeElapsedMS As Integer          '// Elapsed capture duration
        Dim hPalCurrent As Integer                     '// Current palette in use
        Dim fCapturingNow As Integer                   '// Capture in progress?
        Dim dwReturn As Integer                        '// Error value after any operation
        Dim wNumVideoAllocated As Integer              '// Actual number of video buffers
        Dim wNumAudioAllocated As Integer              '// Actual number of audio buffers
    End Structure

    ' --------------------------------------------
    '
    '
    '
    ' --------------------------------------------
    Private Sub FormVideo_Load(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles MyBase.Load

        LoadDeviceList()

        If lstDevices.Items.Count > 0 Then
            btnStart.Enabled = True
            lstDevices.SelectedIndex = 0
            btnStart.Enabled = True
        Else
            lstDevices.Items.Add("No Capture Device")
            btnStart.Enabled = False
        End If

        Me.AutoScrollMinSize = New Size(100, 100)
        btnStop.Enabled = False
        btnSave.Enabled = False
        btnInfo.Enabled = False
        picCapture.SizeMode = PictureBoxSizeMode.StretchImage

    End Sub

    ' --------------------------------------------
    '
    '
    '
    ' --------------------------------------------
    Private Sub LoadDeviceList()

        Dim strName As String = Space(100)
        Dim strVer As String = Space(100)
        Dim bReturn As Boolean
        Dim x As Short = 0
        ' 
        ' Load name of all avialable devices into the lstDevices
        '
        Do
            '
            '   Get Driver name and version
            '
            bReturn = capGetDriverDescriptionA(x, strName, 100, strVer, 100)
            '
            ' If there was a device add device name to the list
            '
            If bReturn Then lstDevices.Items.Add(strName.Trim)
            x += CType(1, Short)
        Loop Until bReturn = False

    End Sub

    ' --------------------------------------------
    '
    '
    '
    ' --------------------------------------------
    Private Sub OpenPreviewWindow()
        'Dim iHeight As Integer = picCapture.Height
        'Dim iWidth As Integer = picCapture.Width
        '
        ' Open Preview window in picturebox
        '
        hHwnd = capCreateCaptureWindowA(DeviceID.ToString, WS_VISIBLE Or WS_CHILD, 0, 0, 1280, _
            1024, picCapture.Handle.ToInt32, 0)
        '
        ' Connect to device
        '
        If SendMessage(hHwnd, WM_CAP_DRIVER_CONNECT, DeviceID, 0) Then
            '
            'Set the preview scale
            '
            SendMessage(hHwnd, WM_CAP_SET_SCALE, True, 0)

            '
            'Set the preview rate in milliseconds
            '
            SendMessage(hHwnd, WM_CAP_SET_PREVIEWRATE, 66, 0)

            '
            'Start previewing the image from the camera
            '
            SendMessage(hHwnd, WM_CAP_SET_PREVIEW, True, 0)

            '
            ' Resize window to fit in picturebox
            '
            SetWindowPos(hHwnd, HWND_BOTTOM, 0, 0, picCapture.Width, picCapture.Height, _
                    SWP_NOMOVE Or SWP_NOZORDER)

            btnSave.Enabled = True
            btnStop.Enabled = True
            btnStart.Enabled = False
            btnInfo.Enabled = True
        Else
            '
            ' Error connecting to device close window
            ' 
            DestroyWindow(hHwnd)
            btnSave.Enabled = False
        End If
    End Sub

    ' --------------------------------------------
    '
    '
    '
    ' --------------------------------------------
    Private Sub btnStart_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles btnStart.Click
        DeviceID = lstDevices.SelectedIndex
        OpenPreviewWindow()
        Dim bReturn As Boolean
        Dim s As CAPSTATUS
        bReturn = SendMessage(hHwnd, WM_CAP_GET_STATUS, Marshal.SizeOf(s), s)
        Debug.WriteLine(String.Format("Video Size {0} x {1}", s.uiImageWidth, s.uiImageHeight))
    End Sub

    ' --------------------------------------------
    '
    '
    '
    ' --------------------------------------------
    Private Sub ClosePreviewWindow()
        '
        ' Disconnect from device
        '
        SendMessage(hHwnd, WM_CAP_DRIVER_DISCONNECT, DeviceID, 0)
        '
        ' close window
        '
        DestroyWindow(hHwnd)
    End Sub

    ' --------------------------------------------
    '
    '
    '
    ' --------------------------------------------
    Private Sub btnStop_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles btnStop.Click
        ClosePreviewWindow()
        btnSave.Enabled = False
        btnStart.Enabled = True
        btnInfo.Enabled = False
        btnStop.Enabled = False
    End Sub

    ' --------------------------------------------
    '
    '
    '
    ' --------------------------------------------
    Private Sub btnSave_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles btnSave.Click
        Dim data As IDataObject
        Dim bmap As Bitmap

        '
        ' Copy image to clipboard
        '
        SendMessage(hHwnd, WM_CAP_EDIT_COPY, 0, 0)
        '
        ' Get image from clipboard and convert it to a bitmap
        '
        data = Clipboard.GetDataObject()
        If data.GetDataPresent(GetType(System.Drawing.Bitmap)) Then
            bmap = CType(data.GetData(GetType(System.Drawing.Bitmap)), Bitmap)
            picCapture.Image = bmap
            ClosePreviewWindow()
            btnSave.Enabled = False
            btnStop.Enabled = False
            btnStart.Enabled = True
            btnInfo.Enabled = False
            Trace.Assert(Not (bmap Is Nothing))
            If sfdImage.ShowDialog = DialogResult.OK Then
                bmap.Save(sfdImage.FileName, Imaging.ImageFormat.Bmp)
            End If
        End If
    End Sub

    ' --------------------------------------------
    '
    '
    '
    ' --------------------------------------------
    Private Sub Form1_Closing(ByVal sender As Object, ByVal e As System.ComponentModel.CancelEventArgs) Handles MyBase.Closing
        If btnStop.Enabled Then
            ClosePreviewWindow()
        End If
    End Sub

    ' --------------------------------------------
    '
    '
    '
    ' --------------------------------------------
    Private Sub btnInfo_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles btnInfo.Click
        SendMessage(hHwnd, WM_CAP_DLG_VIDEOFORMAT, 0, 0)
    End Sub

End Class

