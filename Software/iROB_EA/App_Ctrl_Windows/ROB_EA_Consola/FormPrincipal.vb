Imports System
Imports System.IO.Ports
Imports System.Media
Imports System.Windows.Forms
Imports System.Data.SqlClient
Imports System.Data.Common
Imports System.Runtime.InteropServices

Public Class FormPrincipal

    ' ----------------------------------------------
    '
    ' Constantes y variables de la Clase
    '
    ' ----------------------------------------------

    Private GLB_Ob_Cnx As OleDb.OleDbConnection
    Private autoenvioModo As Integer
    Private Dt_TeclasFuncion As New DataTable
    Private funcionDirecta_Key As String
    Private funcionDirecta_Idx As Integer
    Private dirApp As String

    ' --------------------------------------
    ' Variables y definiciones relacionadas 
    ' con el procesado de respuestas
    ' --------------------------------------
    Private Const IDE_MAX_CMD_RESPUESTAS = 50                             ' Numero máximo de comandos de respuesta que maneja esta aplicacion
    Private tabRespuestas_Cmd(IDE_MAX_CMD_RESPUESTAS - 1, 3) As String    ' Array  de comandos de respuesta. ( si hay mas cambiar el define anterior, que dimensiona este array )
    Private tabRespuestas_Num As Integer                                  ' Numero de comandos de respuesta almacenados en el array tabRespuestas_Cmd
    Private tabRespuestas_ind As Integer                                  ' Indice de comandos de respuesta dentro de tabRespuestas_Cmd
    Private sDestino As String                                            ' Nombre del destino de respuesta procesado en todo momento  
    Private sOrigen As String                                             ' Nombre del origen  de respuesta procesado en todo momento  
    Private sComando As String                                            ' Nombre del comando de respuesta procesado en todo momento  
    Private sParam01 As String                                            ' Valor del parametro 1 del comando de respuesta procesado en todo momento
    Private sParam02 As String                                            ' Valor del parametro 2 del comando de respuesta procesado en todo momento  



    Private Const IDE_BBDD = "gescom_02.mdb"
    Private Const AUTOENVIO_ON = 1
    Private Const AUTOENVIO_OFF = 0

    ' ---------------------------------------------------------
    ' ATENCIÓN:
    ' Estos tres defines deben ser iguales en el sw del Robot , 
    ' del Game PAD y en el del PC
    ' ---------------------------------------------------------
    Private Const IDE_PC_ID = "PC0"                                      ' Identificador del PC
    Private Const IDE_GAME_PAD_ID = "PAD"                                ' Identificador del Game PAD
    Private Const IDE_ROBOT_ID = "ROB"                                   ' Identificador del Robot   

    Private Const IDE_CABECERA_STRING = "#####"                          ' String completo de cabecera de comando (formado por caracters como IDE_CABECERA_CARACTER )
    Private Const IDE_CABECERA_CARACTER = "#"                            ' La cabecera de un comando consta de n caracteres ( IDE_CAB_MAX ) seguidos como este ( # )

    Private Const IDE_PAUSA_TRX = 500

    Private Const IDE_CAB_MAX_LEN = 5                ' Longitud del identificador de inicio de comando
    Private Const IDE_DES_MAX_LEN = 3                ' Longitud de un identificador de origen
    Private Const IDE_ORG_MAX_LEN = 3                ' Longitud de un identificador de destino
    Private Const IDE_COM_MAX_LEN = 6                ' Longitud de un identificador de comando o  respuesta
    Private Const IDE_PAR_MAX_LEN = 3                ' Longitud de un parametro de un comando

    Private Const IDE_COMANDO_MAX_LEN = CInt(IDE_DES_MAX_LEN + IDE_ORG_MAX_LEN + IDE_COM_MAX_LEN + IDE_PAR_MAX_LEN + IDE_PAR_MAX_LEN)
    Private Const IDE_RESPUESTA_MAX_LEN = CInt(IDE_DES_MAX_LEN + IDE_ORG_MAX_LEN + IDE_COM_MAX_LEN + IDE_PAR_MAX_LEN + IDE_PAR_MAX_LEN)

    Private Const IDE_TECLA_FUNCION_DIRECTA_F1 = "F1"
    Private Const IDE_TECLA_FUNCION_DIRECTA_F2 = "F2"
    Private Const IDE_TECLA_FUNCION_DIRECTA_F3 = "F3"
    Private Const IDE_TECLA_FUNCION_DIRECTA_F4 = "F4"
    Private Const IDE_TECLA_FUNCION_DIRECTA_F5 = "F5"
    Private Const IDE_TECLA_FUNCION_DIRECTA_F6 = "F6"
    Private Const IDE_TECLA_FUNCION_DIRECTA_F7 = "F7"
    Private Const IDE_TECLA_FUNCION_DIRECTA_F8 = "F8"
    Private Const IDE_TECLA_FUNCION_DIRECTA_F9 = "F9"
    Private Const IDE_TECLA_FUNCION_DIRECTA_F10 = "F10"
    Private Const IDE_TECLA_FUNCION_DIRECTA_UP = "UP"
    Private Const IDE_TECLA_FUNCION_DIRECTA_DOWN = "DOWN"
    Private Const IDE_TECLA_FUNCION_DIRECTA_LEFT = "LEFT"
    Private Const IDE_TECLA_FUNCION_DIRECTA_RIGHT = "RIGHT"
    Private Const IDE_TECLA_FUNCION_DIRECTA_STOP = "CLEAR"


    ' ----------------------------------------------
    '
    ' FormPrincipal_FormClosing( ByVal sender As Object,
    '                            ByVal e      As System.Windows.Forms.FormClosingEventArgs
    '                          ) Handles Me.FormClosing
    '
    ' ----------------------------------------------

    Private Sub FormPrincipal_FormClosing(ByVal sender As Object, ByVal e As System.Windows.Forms.FormClosingEventArgs) Handles Me.FormClosing

      

    End Sub

    ' ----------------------------------------------
    '
    ' iniApp
    '
    ' ----------------------------------------------

    Private Sub iniApp(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles MyBase.Load

        Dim sBBDD As String

        Stop
        Dim x As Integer
        x = FN_GetJoystick()


        dirApp = "" & Application.StartupPath
        sBBDD = "" & dirApp & "\" & IDE_BBDD

        If (FN_TestFichero(sBBDD) = True) Then
            ' -------------------------------------
            '
            ' -------------------------------------
            If (crearConexion(sBBDD) = True) Then

                ' -------------------------------------
                '
                ' -------------------------------------
                getListaPuertos()

                ' -------------------------------------
                '
                ' -------------------------------------
                setListaFamilias()
                setListaComandos()
                setTablaCmdRespuestas()

                Me.Campo_Lst_RX.Text = ""
                Me.Campo_Act_RX.Text = ""
                Me.Campo_TX.Text = ""

                iniCamposTelemetria()

                Me.CampoListaComandosDesc.Text = ""
                
                Me.KeyPreview = True

                autoenvioModo = AUTOENVIO_ON
                funcionDirecta_Key = ""
                funcionDirecta_Idx = 0


                Me.AutoScrollMinSize = New Size(100, 100)

            Else
                Application.Exit()
            End If

        Else
            MsgErr_BBDD(sBBDD)
            Application.Exit()
        End If

    End Sub

    ' ----------------------------------------------
    '
    ' iniCamposTelemetria()
    '
    ' ----------------------------------------------

    Private Sub iniCamposTelemetria()

        Me.CampoBrujula_01.Text = ""
        Me.CampoBrujula_02.Text = ""
        Me.CampoInclinacion.Text = ""
        Me.CampoDistancia_PING.Text = ""
        Me.CampoTemperatura.Text = ""
        Me.CampoHumedad.Text = ""
        Me.CampoNivelBateria.Text = ""
        Me.CampoImgBateria_00.Visible = False
        Me.CampoImgBateria_01.Visible = False
        Me.CampoImgBateria_02.Visible = False
        Me.CampoImgBateria_03.Visible = False
        Me.CampoImgBateria_04.Visible = False
        Me.CampoImgBateria_05.Visible = False
        Me.CampoNivelXBEE_01.Text = ""
        Me.CampoNivelXBEE_02.Text = ""

    End Sub

    ' ----------------------------------------------
    '
    ' iniPSerie()
    ' As Integer
    '
    ' ----------------------------------------------
    Private Function iniPSerie() As Integer

        Dim resultado As Integer

        Me.SerialPort_01.BaudRate = 9600
        Me.SerialPort_01.PortName = Me.CampoListaPuertos.SelectedItem
        Me.SerialPort_01.Parity = IO.Ports.Parity.None
        Me.SerialPort_01.DataBits = 8
        Me.SerialPort_01.StopBits = IO.Ports.StopBits.One

        Try
            Me.SerialPort_01.Open()
            resultado = True
        Catch
            resultado = False
        End Try

        If (resultado = True) Then
            Me.Icono_TRX.Visible = True
            Me.Texto_TRX.Visible = True
        Else
            Me.Icono_TRX.Visible = False
            Me.Texto_TRX.Visible = False
        End If

        iniPSerie = resultado

    End Function

    ' ----------------------------------------------
    '
    ' getListaPuertos()
    ' As Integer
    '
    ' ----------------------------------------------

    Private Function getListaPuertos() As Integer

        Dim numPorts As Integer


        Me.Icono_TRX.Visible = False
        Me.Texto_TRX.Visible = False

        numPorts = Me.CampoListaPuertos.Items.Count

        Try
            Do
                If (numPorts > 0) Then
                    Me.CampoListaPuertos.Items.RemoveAt(numPorts - 1)
                    numPorts = numPorts - 1
                Else
                    Exit Do
                End If
            Loop
        Catch ex1 As Exception

        End Try


        Try
            numPorts = My.Computer.Ports.SerialPortNames.Count
            Me.CampoListaPuertos.Text = ""

            If (numPorts > 0) Then
                For Each s As String In My.Computer.Ports.SerialPortNames
                    Me.CampoListaPuertos.Items.Add(s)
                Next
                Me.CampoListaPuertos.Text = Me.CampoListaPuertos.Items(0)
            End If

        Catch ex As Exception

        End Try

        getListaPuertos = True

    End Function

    ' ----------------------------------------------
    '
    ' BotonSelPuerto_Click
    '
    ' ----------------------------------------------

    Private Sub BotonSelPuerto_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles BotonSelPuerto.Click

        Dim resultado As Integer

        If (Me.BotonSelPuerto.Text = "CERRAR") Then
            ' ----------------------------------------------
            ' Cerrar puerto
            ' ----------------------------------------------
            Try
                Me.BotonSelPuerto.Text = "ABRIR"
                Me.SerialPort_01.Close()
                Me.Icono_TRX.Visible = False
                Me.Texto_TRX.Visible = False
            Catch
            End Try
        Else
            ' ----------------------------------------------
            ' Abrir puerto
            ' ----------------------------------------------
            resultado = iniPSerie()
            Me.BotonSelPuerto.Text = "CERRAR"
            If (resultado = False) Then
                MsgBox("Se ha producido un error al abrir el puerto")
            End If
        End If


    End Sub

    ' ----------------------------------------------
    '
    ' CampoListaPuertos_SelectedIndexChanged
    '
    ' ----------------------------------------------

    Private Sub CampoListaPuertos_SelectedIndexChanged(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles CampoListaPuertos.SelectedIndexChanged

        If (Me.SerialPort_01.IsOpen = True) Then
            Me.SerialPort_01.Close()
            Me.BotonSelPuerto.Text = "ABRIR"
        End If

    End Sub

    ' ----------------------------------------------
    '
    ' procesa_RX
    '
    ' ----------------------------------------------

    Private Sub procesa_RX(ByVal sender As System.Object, ByVal e As System.IO.Ports.SerialDataReceivedEventArgs) Handles SerialPort_01.DataReceived

        ' Dim cCar As String
        Dim sBuff As String
        Dim cBuff As Integer
        Dim sComando As String
        Dim cComando As Integer
        Dim iniComando_A As Integer
        Dim iniComando_B As Integer
        Dim bucleActivo As Integer


        bucleActivo = True

        While (bucleActivo = True)

            Try
                ' ----------------------------------------------
                ' Bucle de procesado
                ' ----------------------------------------------
                ' Stop
                sBuff = SerialPort_01.ReadLine()
                cBuff = Len(sBuff)
                cComando = CInt(IDE_DES_MAX_LEN + IDE_ORG_MAX_LEN + IDE_COM_MAX_LEN + IDE_PAR_MAX_LEN + IDE_PAR_MAX_LEN)

                iniComando_A = 1
                iniComando_B = 0
                Do
                    iniComando_A = InStr(iniComando_A, sBuff, IDE_CABECERA_STRING)
                    If (iniComando_A > 0) Then
                        iniComando_A = iniComando_A + IDE_CAB_MAX_LEN
                        iniComando_B = InStr(iniComando_A, sBuff, IDE_CABECERA_STRING)
                        If (iniComando_B = 0) Then
                            ' ---------------------------------------
                            ' Procesa primer/ultimo comando
                            ' ---------------------------------------
                            If (((cBuff - iniComando_A) + 1) >= cComando) Then
                                sComando = Mid(sBuff, iniComando_A)
                                procesaRespuesta(sComando)
                            End If
                        Else
                            ' ---------------------------------------
                            ' Procesa comando
                            ' ---------------------------------------
                            sComando = Mid(sBuff, iniComando_A, (iniComando_B - iniComando_A))
                            procesaRespuesta(sComando)
                            iniComando_A = iniComando_B
                        End If
                    Else
                        Exit Do
                    End If
                Loop


            Catch ex As Exception
                ' ----------------------------------------------
                ' NO hay caracteres
                ' ----------------------------------------------
                bucleActivo = False
            End Try

        End While
        

    End Sub

    ' ----------------------------------------------
    '
    ' setBrujula
    '
    ' ----------------------------------------------

    Private Delegate Sub SetBrujula_CallBack(ByVal [xx] As String)

    Private Sub SetBrujula(ByVal sValor As String)

        Dim cAux As Integer
        Dim n As Integer
        Dim s As String


        If Me.CampoBrujula_02.InvokeRequired Then
            Dim d As New SetBrujula_CallBack(AddressOf SetBrujula)
            Me.Invoke(d, New Object() {[sValor]})
        Else
            ' --------------------------------------
            '
            ' --------------------------------------
            cAux = CInt(sValor)
            n = cAux
            s = ""
            While n > 0
                If n Mod Val(2) = 1 Then
                    s = s.Insert(0, "1")
                Else
                    s = s.Insert(0, "0")
                End If
                n = Int(n / 2)
            End While

            Me.CampoBrujula_01.Text = s
            Me.CampoBrujula_02.Text = ""

            ' --------------------------------------
            '
            ' --------------------------------------
            Select Case (cAux)
                Case (1)
                    Me.CampoBrujula_02.Text = "NORTE"
                Case (3)
                    Me.CampoBrujula_02.Text = "NORESTE"
                Case (2)
                    Me.CampoBrujula_02.Text = "ESTE"
                Case (6)
                    Me.CampoBrujula_02.Text = "SURESTE"
                Case (4)
                    Me.CampoBrujula_02.Text = "SUR"
                Case (12)
                    Me.CampoBrujula_02.Text = "SUROESTE"
                Case (8)
                    Me.CampoBrujula_02.Text = "OESTE"
                Case (9)
                    Me.CampoBrujula_02.Text = "NOROESTE"
            End Select

            Me.CampoBrujula_01.Refresh()
            Me.CampoBrujula_02.Refresh()

        End If

    End Sub

    ' ----------------------------------------------
    '
    ' setInclinacion
    '
    ' ----------------------------------------------

    Private Delegate Sub SetInclinacion_CallBack(ByVal [xx] As String)

    Private Sub SetInclinacion(ByVal sValor As String)

        Dim cAux As Integer

        If Me.CampoInclinacion.InvokeRequired Then
            Dim d As New SetInclinacion_CallBack(AddressOf SetInclinacion)
            Me.Invoke(d, New Object() {[sValor]})
        Else
            cAux = CInt(sValor)
            Me.CampoInclinacion.Text = cAux

            If (cAux = 0) Then
                Me.ImgInclinacion.Visible = False
            Else
                Me.ImgInclinacion.Visible = True
            End If

            Me.CampoInclinacion.Refresh()
            Me.ImgInclinacion.Refresh()

        End If

    End Sub

    ' ----------------------------------------------
    '
    ' setNivelBateria
    '
    ' ----------------------------------------------

    Private Delegate Sub SetNivelBateria_CallBack(ByVal [xx] As String)

    Private Sub SetNivelBateria(ByVal sValor As String)

        Dim cAux As Double


        If Me.CampoNivelBateria.InvokeRequired Then
            Dim d As New SetNivelBateria_CallBack(AddressOf SetNivelBateria)
            Me.Invoke(d, New Object() {[sValor]})
        Else
            cAux = CDbl(sValor)

            ' ----------------------------------------------
            '
            ' 255 Equivale a un nivel de +7,2 voltios de bateria 
            ' Se calcula con una regla de tres a que equivale
            ' el valor recibido
            '
            ' ----------------------------------------------
            cAux = CDbl(cAux * CDbl(7.2)) / 255

            Me.CampoImgBateria_00.Visible = False
            Me.CampoImgBateria_01.Visible = False
            Me.CampoImgBateria_02.Visible = False
            Me.CampoImgBateria_03.Visible = False
            Me.CampoImgBateria_04.Visible = False
            Me.CampoImgBateria_05.Visible = False

            If (cAux <> 0) Then
                ' ----------------------------------------------
                '
                ' ----------------------------------------------
                If ((cAux >= 7.2) And (cAux >= 7)) Then
                    Me.CampoImgBateria_00.Visible = True

                ElseIf ((cAux >= 6.9) And (cAux >= 6.5)) Then
                    Me.CampoImgBateria_01.Visible = True

                ElseIf ((cAux >= 6.4) And (cAux >= 6)) Then
                    Me.CampoImgBateria_02.Visible = True

                ElseIf ((cAux >= 5.9) And (cAux >= 5.6)) Then
                    Me.CampoImgBateria_03.Visible = True
                Else
                    Me.CampoImgBateria_04.Visible = True
                End If

                Me.CampoNivelBateria.Text = Format(cAux, "0.0")
                Me.CampoNivelBateria.Refresh()
            Else
                Me.CampoImgBateria_05.Visible = True
                Me.CampoNivelBateria.Text = ""
                Me.CampoNivelBateria.Refresh()
            End If

        End If

    End Sub

    ' ----------------------------------------------
    '
    ' setDistancia_PING
    '
    ' ----------------------------------------------

    Private Delegate Sub setDistancia_PING_CallBack(ByVal [xx] As String)

    Private Sub setDistancia_PING(ByVal sValor As String)

        Dim cAux As Double

        If Me.CampoDistancia_PING.InvokeRequired Then
            Dim d As New setDistancia_PING_CallBack(AddressOf setDistancia_PING)
            Me.Invoke(d, New Object() {[sValor]})
        Else

            cAux = CDbl(sValor)
            Me.CampoDistancia_PING.Text = cAux
            Me.CampoDistancia_PING.Refresh()
        End If

    End Sub

    ' ----------------------------------------------
    '
    ' setTemperatura
    '
    ' ----------------------------------------------

    Private Delegate Sub setTemperatura_CallBack(ByVal [xx] As String)

    Private Sub setTemperatura(ByVal sValor As String)

        Dim cAux As Double

        If Me.CampoTemperatura.InvokeRequired Then
            Dim d As New setTemperatura_CallBack(AddressOf setTemperatura)
            Me.Invoke(d, New Object() {[sValor]})
        Else
            cAux = CDbl(sValor)
            Me.CampoTemperatura.Text = cAux
            Me.CampoTemperatura.Refresh()
        End If

    End Sub

    ' ----------------------------------------------
    '
    ' setHumedad
    '
    ' ----------------------------------------------

    Private Delegate Sub setHumedad_CallBack(ByVal [xx] As String)

    Private Sub setHumedad(ByVal sValor As String)

        Dim cAux As Double

        If Me.CampoHumedad.InvokeRequired Then
            Dim d As New setHumedad_CallBack(AddressOf setHumedad)
            Me.Invoke(d, New Object() {[sValor]})
        Else
            cAux = CDbl(sValor)
            Me.CampoHumedad.Text = cAux
            Me.CampoHumedad.Refresh()
        End If

    End Sub

    ' ----------------------------------------------
    '
    ' displayLstRX
    '
    ' ----------------------------------------------

    Private Delegate Sub displayLstRX_CallBack(ByVal [xx] As String)

    Private Sub displayLstRX(ByVal sValor As String)

        If Me.Campo_Lst_RX.InvokeRequired Then
            Dim d As New displayLstRX_CallBack(AddressOf displayLstRX)
            Me.Invoke(d, New Object() {[sValor]})

        Else
            Me.Campo_Lst_RX.Text = Me.Campo_Lst_RX.Text & sValor & vbCrLf
            Me.Campo_Lst_RX.Refresh()
        End If

    End Sub

    ' ----------------------------------------------
    '
    ' displayActRX
    '
    ' ----------------------------------------------

    Private Delegate Sub displayActRX_CallBack(ByVal [xx] As String)

    Private Sub displayActRX(ByVal sValor As String)

        If Me.Campo_Act_RX.InvokeRequired Then
            Dim d As New displayActRX_CallBack(AddressOf displayActRX)
            Me.Invoke(d, New Object() {[sValor]})

        Else
            Me.Campo_Act_RX.Text = sValor
            Me.Campo_Act_RX.Refresh()
        End If

    End Sub

    ' ----------------------------------------------
    '
    ' displayClsRX
    '
    ' ----------------------------------------------

    Private Delegate Sub displayClsRX_CallBack(ByVal [xx] As String)

    Private Sub displayClsRX(ByVal sValor As String)

        If Me.Campo_Lst_RX.InvokeRequired Then
            Dim d As New displayClsRX_CallBack(AddressOf displayClsRX)
            Me.Invoke(d, New Object() {[sValor]})

        Else
            Me.Campo_Lst_RX.Text = ""
            Me.Campo_Lst_RX.Refresh()
            Me.Campo_Act_RX.Text = ""
            Me.Campo_Act_RX.Refresh()
        End If

    End Sub

    ' ----------------------------------------------
    '
    ' displayClsTX
    '
    ' ----------------------------------------------

    Private Delegate Sub displayClsTX_CallBack(ByVal [xx] As String)

    Private Sub displayClsTX(ByVal sValor As String)

        If Me.Campo_TX.InvokeRequired Then
            Dim d As New displayClsTX_CallBack(AddressOf displayClsTX)
            Me.Invoke(d, New Object() {[sValor]})

        Else
            Me.Campo_TX.Text = ""
            Me.Campo_TX.Refresh()
        End If

    End Sub

    ' ----------------------------------------------
    '
    ' Boton_TX_Enter
    '
    ' ----------------------------------------------

    Private Sub Boton_TX_Enter(ByVal sender As System.Object, ByVal e As KeyPressEventArgs) Handles Campo_TX.KeyPress

        If e.KeyChar = ControlChars.Cr Then
            e.Handled = True

            Stop
            'enviarComando()
        End If

    End Sub

    ' ----------------------------------------------
    '
    ' Boton_TX_Enter
    '
    ' ----------------------------------------------

    Private Sub Boton_TX_BEnter(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles Campo_TX.MouseDoubleClick

        displayClsTX("")

    End Sub

    ' ----------------------------------------------
    '
    ' Boton_TX_Click
    '
    ' ----------------------------------------------

    Private Sub Boton_TX_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles Boton_TX.Click

        Stop
        'enviarComando()

    End Sub

    ' ----------------------------------------------
    '
    ' Boton_Cls_RX_Click
    '
    ' ----------------------------------------------

    Private Sub Boton_Cls_RX_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles Boton_Cls_RX.Click

        displayClsRX("")

    End Sub

    Private Delegate Sub fn_respuesta(ByVal [xx] As String)

    ' ----------------------------------------------
    '
    ' procesaRespuesta(ByVal srespuesta As String)
    '
    ' ----------------------------------------------
    Private Function procesaRespuesta(ByVal sRespuesta As String) As Integer

        Dim resultado As Integer
        Dim cOrg As Integer


        cOrg = 1
        sDestino = Mid(sRespuesta, cOrg, IDE_DES_MAX_LEN)
        cOrg = cOrg + IDE_DES_MAX_LEN
        sOrigen = Mid(sRespuesta, cOrg, IDE_ORG_MAX_LEN)
        cOrg = cOrg + IDE_ORG_MAX_LEN
        sComando = Mid(sRespuesta, cOrg, IDE_COM_MAX_LEN)
        cOrg = cOrg + IDE_COM_MAX_LEN
        sParam01 = Mid(sRespuesta, cOrg, IDE_PAR_MAX_LEN)
        cOrg = cOrg + IDE_PAR_MAX_LEN
        sParam02 = Mid(sRespuesta, cOrg)

        resultado = True

        If (sDestino = IDE_PC_ID) Then
            ' ----------------------------------------------
            '
            ' ----------------------------------------------

            ' Stop
            tabRespuestas_ind = 0

            While (tabRespuestas_ind < tabRespuestas_Num)
                If ((tabRespuestas_Cmd(tabRespuestas_ind, 0) = sComando) And (tabRespuestas_Cmd(tabRespuestas_ind, 1) = sParam01)) Then
                    ' ----------------------------------------------
                    '
                    ' ----------------------------------------------
                    Try
                        CallByName(Me, tabRespuestas_Cmd(tabRespuestas_ind, 3), vbMethod)
                    Catch ex As Exception

                    End Try

                    Exit While
                End If
                tabRespuestas_ind = tabRespuestas_ind + 1
            End While


        End If

        procesaRespuesta = resultado

    End Function

    ' ----------------------------------------------
    '
    ' pausaSincronismo()
    '
    ' ----------------------------------------------
    Private Sub pausaSincronismo()

        Dim sw As New Stopwatch

        sw.Start()
        Do While sw.ElapsedMilliseconds < CInt(IDE_PAUSA_TRX)
            Application.DoEvents()
        Loop
        sw.Stop()

    End Sub

    ' ----------------------------------------------
    '
    ' enviarComando
    '
    ' ----------------------------------------------
    Private Function enviarComando(ByVal sComando As String) As String

        Dim strTX As String

        strTX = ""

        If (Me.SerialPort_01.IsOpen() = True) Then
            ' ----------------------------------------------
            '
            ' ----------------------------------------------

            strTX = IDE_CABECERA_STRING & IDE_ROBOT_ID & IDE_PC_ID & Trim(sComando)

            If (strTX.Length > 0) Then
                Try
                    strTX = strTX & vbCr
                    Me.SerialPort_01.Write(strTX)
                Catch
                    MsgBox("Se ha producido un error al enviar el comando...")
                End Try
            End If
        End If

        enviarComando = strTX

    End Function

    ' ----------------------------------------------
    '
    ' setListaFamilias()
    '
    ' ----------------------------------------------
    Private Sub setListaFamilias()
        Dim sSql As String
        Dim resultado As Integer
        Dim Ob_Data As OleDb.OleDbDataAdapter

        resultado = True

        Try
            ' -------------------------------------------------
            ' Inicializar el SqlDataAdapter 
            ' -------------------------------------------------

            sSql = ""
            sSql = sSql & " SELECT "
            sSql = sSql & " Tbl_Familia.GESCOM_FAMILIA_IDX    As ID    , "
            sSql = sSql & " Tbl_Familia.GESCOM_FAMILIA_NOMBRE As Nombre  "
            sSql = sSql & " FROM Tbl_Familia"
            sSql = sSql & " WHERE   (Tbl_Familia.GESCOM_FAMILIA_FEBAJA = 0) "
            sSql = sSql & " ORDER BY Tbl_Familia.GESCOM_FAMILIA_NOMBRE; "

            Ob_Data = New OleDb.OleDbDataAdapter(sSql, GLB_Ob_Cnx)
            Dim oledbSqlCommandBuilder As New OleDb.OleDbCommandBuilder(Ob_Data)

            ' -------------------------------------------------
            ' Llenar el DataTable   
            ' -------------------------------------------------
            Dim dt As New DataTable
            Ob_Data.Fill(dt)

            ' -------------------------------------------------
            '
            ' -------------------------------------------------
            Me.CampoListaFamilias.DisplayMember = "Nombre"
            Me.CampoListaFamilias.ValueMember = "ID"
            Me.CampoListaFamilias.DataSource = dt

            dt = Nothing
            Ob_Data = Nothing

        Catch exSql As SqlException
            MsgErr_AccDatos()
            resultado = False
        Catch ex As Exception
            MsgErr_AccDatos()
            resultado = False
        End Try

    End Sub

    ' ----------------------------------------------
    '
    ' setListaComandos()
    '
    ' ----------------------------------------------
    Private Sub setListaComandos()

        Dim sSql As String
        Dim resultado As Integer
        Dim Ob_Data As OleDb.OleDbDataAdapter
        Dim familiaID As Integer


        resultado = True

        Try
            ' -------------------------------------------------
            ' Inicializar el SqlDataAdapter 
            ' -------------------------------------------------
            familiaID = Me.CampoListaFamilias.SelectedValue

            sSql = ""
            sSql = sSql & " SELECT "
            sSql = sSql & " Tbl_Comandos.GESCOM_IDX         As ID          , "
            sSql = sSql & " Tbl_Comandos.GESCOM_CMD         As CMD         , "
            sSql = sSql & " Tbl_Comandos.GESCOM_DESCRIPCION As DESCRIPCION   "
            sSql = sSql & " FROM Tbl_Comandos"
            sSql = sSql & " WHERE ( (Tbl_Comandos.GESCOM_FEBAJA     = 0) AND "
            sSql = sSql & "         (Tbl_Comandos.GESCOM_FAMILIA_ID = " & familiaID & " ) "
            sSql = sSql & "       ) "
            sSql = sSql & " ORDER BY Tbl_Comandos.GESCOM_ORDEN; "

            Ob_Data = New OleDb.OleDbDataAdapter(sSql, GLB_Ob_Cnx)
            Dim oledbSqlCommandBuilder As New OleDb.OleDbCommandBuilder(Ob_Data)

            ' -------------------------------------------------
            ' Llenar el DataTable   
            ' -------------------------------------------------
            Dim dt As New DataTable
            Ob_Data.Fill(dt)

            ' -------------------------------------------------
            '
            ' -------------------------------------------------
            Me.CampoListaComandos.DisplayMember = "DESCRIPCION"
            Me.CampoListaComandos.ValueMember = "ID"
            Me.CampoListaComandos.DataSource = dt

            dt = Nothing
            Ob_Data = Nothing

        Catch exSql As SqlException
            MsgErr_AccDatos()
            resultado = False
        Catch ex As Exception
            MsgErr_AccDatos()
            resultado = False
        End Try

    End Sub

    ' ----------------------------------------------
    '
    ' setTablaCmdRespuestas()
    '
    ' ----------------------------------------------
    Private Sub setTablaCmdRespuestas()

        Dim sSql As String
        Dim resultado As Integer
        Dim Ob_Data As OleDb.OleDbDataAdapter
        Dim xx As Integer


        resultado = True

        Try
            ' -------------------------------------------------
            ' Inicializar el SqlDataAdapter 
            ' -------------------------------------------------

            sSql = ""
            sSql = sSql & " SELECT "
            sSql = sSql & " Tbl_Comandos.GESCOM_COMANDO    , "
            sSql = sSql & " Tbl_Comandos.GESCOM_PARAM01    , "
            sSql = sSql & " Tbl_Comandos.GESCOM_PARAM02    , "
            sSql = sSql & " Tbl_Comandos.GESCOM_FN_ASOCIADA  "
            sSql = sSql & " FROM Tbl_Comandos"
            sSql = sSql & " WHERE ( (Tbl_Comandos.GESCOM_FEBAJA = 0 ) AND "
            sSql = sSql & "         (Tbl_Comandos.GESCOM_TIPO   = 1 )     "
            sSql = sSql & "       ) "
            sSql = sSql & " ORDER BY Tbl_Comandos.GESCOM_CMD; "

            Ob_Data = New OleDb.OleDbDataAdapter(sSql, GLB_Ob_Cnx)
            Dim oledbSqlCommandBuilder As New OleDb.OleDbCommandBuilder(Ob_Data)

            ' -------------------------------------------------
            ' Llenar el DataTable   
            ' -------------------------------------------------
            Dim dt As New DataTable
            Ob_Data.Fill(dt)

            ' -------------------------------------------------
            ' Crear el array de comando de respuesta
            ' -------------------------------------------------

            tabRespuestas_Num = dt.Rows.Count
            tabRespuestas_Ind = 0

            If (tabRespuestas_Num > IDE_MAX_CMD_RESPUESTAS) Then
                ' -------------------------------------------------
                ' Demasiados comandos de respuesta
                ' -------------------------------------------------
                xx = MsgErr_MaxComandosRespuesta()
                tabRespuestas_Num = IDE_MAX_CMD_RESPUESTAS
            End If

            While (tabRespuestas_ind < tabRespuestas_Num)
                tabRespuestas_Cmd(tabRespuestas_ind, 0) = Trim(dt.Rows(tabRespuestas_ind).Item(0))
                tabRespuestas_Cmd(tabRespuestas_ind, 1) = Trim(dt.Rows(tabRespuestas_ind).Item(1))
                tabRespuestas_Cmd(tabRespuestas_ind, 2) = Trim(dt.Rows(tabRespuestas_ind).Item(2))
                tabRespuestas_Cmd(tabRespuestas_ind, 3) = Trim(dt.Rows(tabRespuestas_ind).Item(3))
                tabRespuestas_ind = tabRespuestas_ind + 1
            End While
 
            dt = Nothing
            Ob_Data = Nothing

        Catch exSql As SqlException
            MsgErr_AccDatos()
            resultado = False
        Catch ex As Exception
            MsgErr_AccDatos()
            resultado = False
        End Try

    End Sub


    ' ---------------------------------------
    '
    ' crearConexion
    '
    ' ---------------------------------------
    Private Function crearConexion(ByVal sBBDD As String) As Integer

        Dim sCnx As String
        Dim resultado As Integer

        ' ----------------------------------------
        ' ----------------------------------------
        sCnx = "Provider=Microsoft.Jet.OLEDB.4.0;Data Source=" & sBBDD & "; Password="

        Try
            GLB_Ob_Cnx = New OleDb.OleDbConnection(sCnx)
            GLB_Ob_Cnx.Open()
            resultado = True

        Catch ex As Exception
            MsgErr_AccDatosEx(ex.Message)
            resultado = False
            GLB_Ob_Cnx = Nothing
        End Try

        crearConexion = resultado
    End Function

    ' ---------------------------------------
    '
    ' cerrarConexion
    '
    ' ---------------------------------------
    Private Sub cerrarConexion()
        If (Not IsNothing(GLB_Ob_Cnx)) Then
            GLB_Ob_Cnx.Close()
        End If
    End Sub

    Private Sub CampoListaFamilias_SelectedIndexChanged(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles CampoListaFamilias.SelectedIndexChanged

        Me.Campo_TX.Text = ""
        setListaComandos()

    End Sub

    Private Sub CampoListaComandos_SelectedIndexChanged(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles CampoListaComandos.SelectedIndexChanged

        Dim sAux As String

        Me.CampoListaComandosDesc.Text = Me.CampoListaComandos.SelectedItem.item("DESCRIPCION").ToString

        If (autoenvioModo = AUTOENVIO_ON) Then
            sAux = Me.CampoListaComandos.SelectedItem.item("CMD").ToString
            Me.Campo_TX.Text = enviarComando(sAux)
        Else
            Me.Campo_TX.Text = ""
        End If

    End Sub

    Private Sub Boton_AutoEnvio_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles Boton_AutoEnvio.Click

        If (autoenvioModo = AUTOENVIO_ON) Then
            autoenvioModo = AUTOENVIO_OFF
            Me.Boton_AutoEnvio.BackColor = Color.Firebrick
            Me.Boton_AutoEnvio.Text = " AUTOENVIO OFF"
            Me.Campo_TX.Text = ""
        Else
            Me.Boton_AutoEnvio.BackColor = Color.DarkGreen
            autoenvioModo = AUTOENVIO_ON
            Me.Boton_AutoEnvio.Text = " AUTOENVIO ON"
        End If


    End Sub

    ' ---------------------------------------
    '
    ' Boton F01
    '
    ' ---------------------------------------

    Private Sub Boton_F01_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles Boton_F01.Click

        exeFuncionDirecta(IDE_TECLA_FUNCION_DIRECTA_F1)

    End Sub

    ' ---------------------------------------
    '
    ' Boton F02
    '
    ' ---------------------------------------

    Private Sub Boton_F02_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles Boton_F02.Click

        exeFuncionDirecta(IDE_TECLA_FUNCION_DIRECTA_F2)

    End Sub

    ' ---------------------------------------
    '
    ' Boton F03
    '
    ' ---------------------------------------

    Private Sub Boton_F03_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles Boton_F03.Click

        exeFuncionDirecta(IDE_TECLA_FUNCION_DIRECTA_F3)

    End Sub

    ' ---------------------------------------
    '
    ' Boton F04
    '
    ' ---------------------------------------

    Private Sub Boton_F04_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles Boton_F04.Click

        exeFuncionDirecta(IDE_TECLA_FUNCION_DIRECTA_F4)

    End Sub

    ' ---------------------------------------
    '
    ' Boton F05
    '
    ' ---------------------------------------

    Private Sub Boton_F05_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles Boton_F05.Click

        Me.CampoBrujula_01.Text = ""
        Me.CampoBrujula_02.Text = ""
        Me.CampoDistancia_PING.Text = ""
        Me.CampoTemperatura.Text = ""
        Me.CampoHumedad.Text = ""
        Me.CampoInclinacion.Text = ""
        Me.CampoNivelBateria.Text = ""

        exeFuncionDirecta(IDE_TECLA_FUNCION_DIRECTA_F5)

    End Sub

    ' ---------------------------------------
    '
    ' Boton F06
    '
    ' ---------------------------------------

    Private Sub Boton_F06_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles Boton_F06.Click

        exeFuncionDirecta(IDE_TECLA_FUNCION_DIRECTA_F6)

    End Sub

    ' ---------------------------------------
    '
    ' Boton F07
    '
    ' ---------------------------------------

    Private Sub Boton_F07_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles Boton_F07.Click

        exeFuncionDirecta(IDE_TECLA_FUNCION_DIRECTA_F7)

    End Sub

    ' ---------------------------------------
    '
    ' Boton F08
    '
    ' ---------------------------------------

    Private Sub Boton_F08_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles Boton_F08.Click

        exeFuncionDirecta(IDE_TECLA_FUNCION_DIRECTA_F8)

    End Sub

    ' ---------------------------------------
    '
    ' Boton F09
    '
    ' ---------------------------------------

    Private Sub Boton_F09_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles Boton_F09.Click

        exeFuncionDirecta(IDE_TECLA_FUNCION_DIRECTA_F9)

    End Sub

    ' ---------------------------------------
    '
    ' Boton F10
    '
    ' ---------------------------------------

    Private Sub Boton_F10_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles Boton_F10.Click

        exeFuncionDirecta(IDE_TECLA_FUNCION_DIRECTA_F10)

    End Sub

    ' ---------------------------------------
    '
    ' Boton UP
    '
    ' ---------------------------------------

    Private Sub Boton_UP_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles Boton_UP.Click

        exeFuncionDirecta(IDE_TECLA_FUNCION_DIRECTA_UP)

    End Sub

    ' ---------------------------------------
    '
    ' Boton DOWN
    '
    ' ---------------------------------------

    Private Sub Boton_DOWN_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles Boton_DOWN.Click

        exeFuncionDirecta(IDE_TECLA_FUNCION_DIRECTA_DOWN)

    End Sub

    ' ---------------------------------------
    '
    ' Boton RIGHT
    '
    ' ---------------------------------------

    Private Sub Boton_RIGHT_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles Boton_RIGHT.Click

        exeFuncionDirecta(IDE_TECLA_FUNCION_DIRECTA_RIGHT)

    End Sub

    ' ---------------------------------------
    '
    ' Boton LEFT
    '
    ' ---------------------------------------

    Private Sub Boton_LEFT_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles Boton_LEFT.Click

        exeFuncionDirecta(IDE_TECLA_FUNCION_DIRECTA_LEFT)

    End Sub

    ' ---------------------------------------
    '
    ' Boton STOP
    '
    ' ---------------------------------------

    Private Sub Boton_STOP_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles Boton_STOP.Click

        exeFuncionDirecta(IDE_TECLA_FUNCION_DIRECTA_STOP)

    End Sub

    ' ---------------------------------------
    '
    ' Form1_KeyDown( ByVal sender As Object,
    '                ByVal e As System.Windows.Forms.KeyEventArgs
    '              ) Handles MyBase.KeyDown
    '
    ' ---------------------------------------

    Private Sub Form1_KeyDown(ByVal sender As Object, ByVal e As System.Windows.Forms.KeyEventArgs) Handles MyBase.KeyDown

        Dim sTecla As String

        sTecla = UCase(e.KeyCode.ToString)


        Select Case (sTecla)
            Case (IDE_TECLA_FUNCION_DIRECTA_F1)
                exeFuncionDirecta(sTecla)
            Case (IDE_TECLA_FUNCION_DIRECTA_F2)
                exeFuncionDirecta(sTecla)
            Case (IDE_TECLA_FUNCION_DIRECTA_F3)
                exeFuncionDirecta(sTecla)
            Case (IDE_TECLA_FUNCION_DIRECTA_F4)
                exeFuncionDirecta(sTecla)
            Case (IDE_TECLA_FUNCION_DIRECTA_F5)
                exeFuncionDirecta(sTecla)
            Case (IDE_TECLA_FUNCION_DIRECTA_F6)
                exeFuncionDirecta(sTecla)
            Case (IDE_TECLA_FUNCION_DIRECTA_F7)
                exeFuncionDirecta(sTecla)
            Case (IDE_TECLA_FUNCION_DIRECTA_F8)
                exeFuncionDirecta(sTecla)
            Case (IDE_TECLA_FUNCION_DIRECTA_F9)
                exeFuncionDirecta(sTecla)
            Case (IDE_TECLA_FUNCION_DIRECTA_UP)
                exeFuncionDirecta(sTecla)
            Case (IDE_TECLA_FUNCION_DIRECTA_DOWN)
                exeFuncionDirecta(sTecla)
            Case (IDE_TECLA_FUNCION_DIRECTA_RIGHT)
                exeFuncionDirecta(sTecla)
            Case (IDE_TECLA_FUNCION_DIRECTA_LEFT)
                exeFuncionDirecta(sTecla)
            Case (IDE_TECLA_FUNCION_DIRECTA_STOP)
                exeFuncionDirecta(sTecla)
        End Select

    End Sub

    ' ---------------------------------------
    '
    '
    ' ---------------------------------------

    Private Function exeFuncionDirecta(ByVal sTecla As String) As Integer

        Dim sSql As String
        Dim resultado As Integer
        Dim sComando As String
        Dim Ob_TeclasFuncion As OleDb.OleDbDataAdapter
        Dim numComandos As Integer


        resultado = True

        ' -------------------------------------------------
        '
        ' Recupera comandos asociados a la tecla
        '
        ' -------------------------------------------------

        If (funcionDirecta_Key <> sTecla) Then

            funcionDirecta_Key = sTecla
            funcionDirecta_Idx = 0

            Try
                ' -------------------------------------------------
                ' Inicializar el SqlDataAdapter 
                ' -------------------------------------------------

                sSql = ""
                sSql = sSql & " SELECT "
                sSql = sSql & " Tbl_Comandos_Botones.GESCOM_BOTONES_IDE  , "
                sSql = sSql & " Tbl_Comandos_Botones.GESCOM_BOTONES_ORDEN, "
                sSql = sSql & " Tbl_Comandos.GESCOM_CMD                    "
                sSql = sSql & " FROM Tbl_Comandos "
                sSql = sSql & " INNER JOIN Tbl_Comandos_Botones "
                sSql = sSql & " ON         Tbl_Comandos.GESCOM_IDX = "
                sSql = sSql & "            Tbl_Comandos_Botones.GESCOM_BOTONES_GESCOM_IDX "
                sSql = sSql & " WHERE ( "
                sSql = sSql & "       (Tbl_Comandos_Botones.GESCOM_BOTONES_FEBAJA = 0) And "
                sSql = sSql & "       (Tbl_Comandos_Botones.GESCOM_BOTONES_IDE    = '" & funcionDirecta_Key & "') And "
                sSql = sSql & "       (Tbl_Comandos.GESCOM_FEBAJA = 0)"
                sSql = sSql & "       ) "
                sSql = sSql & " ORDER BY Tbl_Comandos_Botones.GESCOM_BOTONES_ORDEN;"

                Ob_TeclasFuncion = New OleDb.OleDbDataAdapter(sSql, GLB_Ob_Cnx)

                Dim oledbSqlCommandBuilder As New OleDb.OleDbCommandBuilder(Ob_TeclasFuncion)

                ' -------------------------------------------------
                ' Llenar el DataTable, si esta lleno lo vacia antes
                ' -------------------------------------------------
                If (Dt_TeclasFuncion.Rows.Count > 0) Then
                    Dt_TeclasFuncion.Clear()
                End If

                Ob_TeclasFuncion.Fill(Dt_TeclasFuncion)
                Ob_TeclasFuncion = Nothing

            Catch exSql As SqlException
                MsgErr_AccDatos()
                resultado = False
            Catch ex As Exception
                MsgErr_AccDatos()
                resultado = False
            End Try

        End If

        ' -------------------------------------------------
        '
        ' Ejecuta comandos asociados a la tecla
        '
        ' -------------------------------------------------
        If (resultado = True) Then
            numComandos = Dt_TeclasFuncion.Rows.Count
            If (numComandos > 0) Then
                ' -------------------------------------------------
                ' Hay comando asociados a la tecla
                ' -------------------------------------------------

                If (funcionDirecta_Idx >= numComandos) Then
                    funcionDirecta_Idx = 0
                End If

                sComando = "" & Dt_TeclasFuncion.Rows(funcionDirecta_Idx).Item("GESCOM_CMD")
                Me.Campo_TX.Text = enviarComando(sComando)

                funcionDirecta_Idx = funcionDirecta_Idx + 1

            End If
        End If

        exeFuncionDirecta = resultado

    End Function

    ' ---------------------------------------
    '
    ' setToolTip(ByVal sTecla As String)
    '
    ' ---------------------------------------

    Private Sub setToolTip(ByVal sTecla As String)

        Dim sSql As String
        Dim sToolTip As String
        Dim Ob_Data As OleDb.OleDbDataAdapter


        sTecla = UCase(sTecla)

        sSql = ""
        sSql = sSql & " SELECT "
        sSql = sSql & " Tbl_Comandos_Botones.GESCOM_BOTONES_IDE,    "
        sSql = sSql & " Tbl_Comandos_Botones.GESCOM_BOTONES_TOOLTIP "
        sSql = sSql & " FROM Tbl_Comandos_Botones"
        sSql = sSql & " WHERE ( (Tbl_Comandos_Botones.GESCOM_BOTONES_IDE    = '" & sTecla & "') AND "
        sSql = sSql & "         (Tbl_Comandos_Botones.GESCOM_BOTONES_FEBAJA = 0)"
        sSql = sSql & "       );"

        Ob_Data = New OleDb.OleDbDataAdapter(sSql, GLB_Ob_Cnx)
        Dim oledbSqlCommandBuilder As New OleDb.OleDbCommandBuilder(Ob_Data)
        Dim dt As New DataTable

        Ob_Data.Fill(dt)

        If (dt.Rows.Count > 0) Then
            ' -------------------------------------------------
            ' Recupera el tool tip
            ' -------------------------------------------------
            sToolTip = "" & dt.Rows(0).Item("GESCOM_BOTONES_TOOLTIP")

            Select Case (sTecla)
                Case (IDE_TECLA_FUNCION_DIRECTA_F1)
                    Me.ToolTip_01.SetToolTip(Me.Boton_F01, sToolTip)
                Case (IDE_TECLA_FUNCION_DIRECTA_F2)
                    Me.ToolTip_01.SetToolTip(Me.Boton_F02, sToolTip)
                Case (IDE_TECLA_FUNCION_DIRECTA_F3)
                    Me.ToolTip_01.SetToolTip(Me.Boton_F03, sToolTip)
                Case (IDE_TECLA_FUNCION_DIRECTA_F4)
                    Me.ToolTip_01.SetToolTip(Me.Boton_F04, sToolTip)
                Case (IDE_TECLA_FUNCION_DIRECTA_F5)
                    Me.ToolTip_01.SetToolTip(Me.Boton_F05, sToolTip)
                Case (IDE_TECLA_FUNCION_DIRECTA_F6)
                    Me.ToolTip_01.SetToolTip(Me.Boton_F06, sToolTip)
                Case (IDE_TECLA_FUNCION_DIRECTA_F7)
                    Me.ToolTip_01.SetToolTip(Me.Boton_F07, sToolTip)
                Case (IDE_TECLA_FUNCION_DIRECTA_F8)
                    Me.ToolTip_01.SetToolTip(Me.Boton_F08, sToolTip)
                Case (IDE_TECLA_FUNCION_DIRECTA_F9)
                    Me.ToolTip_01.SetToolTip(Me.Boton_F09, sToolTip)
                Case (IDE_TECLA_FUNCION_DIRECTA_F10)
                    Me.ToolTip_01.SetToolTip(Me.Boton_F10, sToolTip)
                Case (IDE_TECLA_FUNCION_DIRECTA_UP)
                    Me.ToolTip_01.SetToolTip(Me.Boton_UP, sToolTip)
                Case (IDE_TECLA_FUNCION_DIRECTA_DOWN)
                    Me.ToolTip_01.SetToolTip(Me.Boton_DOWN, sToolTip)
                Case (IDE_TECLA_FUNCION_DIRECTA_RIGHT)
                    Me.ToolTip_01.SetToolTip(Me.Boton_RIGHT, sToolTip)
                Case (IDE_TECLA_FUNCION_DIRECTA_LEFT)
                    Me.ToolTip_01.SetToolTip(Me.Boton_LEFT, sToolTip)
                Case (IDE_TECLA_FUNCION_DIRECTA_STOP)
                    Me.ToolTip_01.SetToolTip(Me.Boton_STOP, sToolTip)
            End Select

        End If

        dt = Nothing
        Ob_Data = Nothing

    End Sub

    ' ---------------------------------------
    '
    '
    ' ---------------------------------------

    Protected Overrides Sub Finalize()
        MyBase.Finalize()
    End Sub

    ' ---------------------------------------
    '
    '
    ' ---------------------------------------

    Public Sub New()
        InitializeComponent()
    End Sub

    ' ---------------------------------------
    ' Boton_F01_MouseEnter
    ' ---------------------------------------

    Private Sub Boton_F01_MouseEnter(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles Boton_F01.MouseEnter
        setToolTip(IDE_TECLA_FUNCION_DIRECTA_F1)
    End Sub

    ' ---------------------------------------
    ' Boton_F02_MouseEnter
    ' ---------------------------------------

    Private Sub Boton_F02_MouseEnter(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles Boton_F02.MouseEnter
        setToolTip(IDE_TECLA_FUNCION_DIRECTA_F2)
    End Sub

    ' ---------------------------------------
    ' Boton_F03_MouseEnter
    ' ---------------------------------------

    Private Sub Boton_F03_MouseEnter(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles Boton_F03.MouseEnter
        setToolTip(IDE_TECLA_FUNCION_DIRECTA_F3)
    End Sub

    ' ---------------------------------------
    ' Boton_F04_MouseEnter
    ' ---------------------------------------

    Private Sub Boton_F04_MouseEnter(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles Boton_F04.MouseEnter
        setToolTip(IDE_TECLA_FUNCION_DIRECTA_F4)
    End Sub

    ' ---------------------------------------
    ' Boton_F05_MouseEnter
    ' ---------------------------------------

    Private Sub Boton_F05_MouseEnter(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles Boton_F05.MouseEnter
        setToolTip(IDE_TECLA_FUNCION_DIRECTA_F5)
    End Sub

    ' ---------------------------------------
    ' Boton_F06_MouseEnter
    ' ---------------------------------------

    Private Sub Boton_F06_MouseEnter(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles Boton_F06.MouseEnter
        setToolTip(IDE_TECLA_FUNCION_DIRECTA_F6)
    End Sub

    ' ---------------------------------------
    ' Boton_F07_MouseEnter
    ' ---------------------------------------

    Private Sub Boton_F07_MouseEnter(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles Boton_F07.MouseEnter
        setToolTip(IDE_TECLA_FUNCION_DIRECTA_F7)
    End Sub

    ' ---------------------------------------
    ' Boton_F08_MouseEnter
    ' ---------------------------------------

    Private Sub Boton_F08_MouseEnter(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles Boton_F08.MouseEnter
        setToolTip(IDE_TECLA_FUNCION_DIRECTA_F8)
    End Sub

    ' ---------------------------------------
    ' Boton_F09_MouseEnter
    ' ---------------------------------------

    Private Sub Boton_F09_MouseEnter(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles Boton_F09.MouseEnter
        setToolTip(IDE_TECLA_FUNCION_DIRECTA_F9)
    End Sub

    ' ---------------------------------------
    ' Boton_F10_MouseEnter
    ' ---------------------------------------

    Private Sub Boton_XBEE_MouseEnter(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles Boton_F10.MouseEnter

        setToolTip(IDE_TECLA_FUNCION_DIRECTA_F10)

    End Sub

    ' ---------------------------------------
    ' Boton_UP_MouseEnter
    ' ---------------------------------------

    Private Sub Boton_UP_MouseEnter(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles Boton_UP.MouseEnter
        setToolTip(IDE_TECLA_FUNCION_DIRECTA_UP)
    End Sub

    ' ---------------------------------------
    ' Boton_DOWN_MouseEnter
    ' ---------------------------------------

    Private Sub Boton_DOWN_MouseEnter(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles Boton_DOWN.MouseEnter
        setToolTip(IDE_TECLA_FUNCION_DIRECTA_DOWN)
    End Sub

    ' ---------------------------------------
    ' Boton_RIGHT_MouseEnter
    ' ---------------------------------------

    Private Sub Boton_RIGHT_MouseEnter(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles Boton_RIGHT.MouseEnter
        setToolTip(IDE_TECLA_FUNCION_DIRECTA_RIGHT)
    End Sub

    ' ---------------------------------------
    ' Boton_LEFT_MouseEnter
    ' ---------------------------------------

    Private Sub Boton_LEFT_MouseEnter(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles Boton_LEFT.MouseEnter
        setToolTip(IDE_TECLA_FUNCION_DIRECTA_LEFT)
    End Sub

    ' ---------------------------------------
    ' Boton_STOP_MouseEnter
    ' ---------------------------------------

    Private Sub Boton_STOP_MouseEnter(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles Boton_STOP.MouseEnter
        setToolTip(IDE_TECLA_FUNCION_DIRECTA_STOP)
    End Sub

    ' ---------------------------------------
    ' BotonScanPuerto_MouseClick
    ' ---------------------------------------

    Private Sub BotonScanPuerto_MouseClick(ByVal sender As System.Object, ByVal e As System.Windows.Forms.MouseEventArgs) Handles BotonScanPuerto.MouseClick

        getListaPuertos()

    End Sub

    ' ---------------------------------------
    '
    '  FUNCION ASOCIADA A COMANDOS DE RETORNO
    '
    ' fn_RESULT_00
    '
    ' ---------------------------------------

    Public Sub fn_RESULT_00()

    End Sub

    ' ---------------------------------------
    '
    '  FUNCION ASOCIADA A COMANDOS DE RETORNO
    '
    ' fn_RESULT_01
    '
    ' ---------------------------------------

    Public Sub fn_RESULT_01()


    End Sub

    ' ---------------------------------------
    '
    '  FUNCION ASOCIADA A COMANDOS DE RETORNO
    '
    ' fn_RESULT_02
    '
    ' ---------------------------------------

    Public Sub fn_RESULT_02()


    End Sub

    ' ---------------------------------------
    '
    '  FUNCION ASOCIADA A COMANDOS DE RETORNO
    '
    ' fn_RESULT_03
    '
    ' ---------------------------------------

    Public Sub fn_RESULT_03()

        Dim sMsg As String

        sMsg = sOrigen & " [ " & sComando & " ]: OK"
        displayLstRX(sMsg)

    End Sub

    ' ---------------------------------------
    '
    '  FUNCION ASOCIADA A COMANDOS DE RETORNO
    '
    ' fn_EXETEL_05
    '
    ' ---------------------------------------

    Public Sub fn_EXETEL_05()

        Dim sAux As String
        Dim sDat As String
        Dim cDat As Integer

        ' ----------------------------------------------
        '
        ' . Formato del string de telemetria:
        '
        '          dddxxx-xxx-xxx-xxx.x-xxx.x-xxx.x
        '    
        '       ddd   3 Caracteres, numero de caracteres de datos
        '       xxx   3 Caracteres, valor de la brujula
        '       -     1 Caracter separador
        '       xxx   3 Caracteres, valor sensor volcado
        '       -     1 Caracter separador
        '       xxx   3 Caracteres, valor nivel de bateria
        '       -     1 Caracter separador
        '       xxx.x 5 Caracteres, sensor de distancia ultrasonidos
        '       -     1 Caracter separador
        '       xxx.x 5 Caracteres, valor sensor de temperatura
        '       -     1 Caracter separador
        '       xxx.x 5 Caracteres, valor sensor de humedad
        '
        ' . Longitud del string: 33 Caracteres
        '
        ' . Codigo Arduino en el ROB_EA:
        '   Fichero:    ROB_EA_Sistema.ino
        '   funcion:    void SISTEMA:enviarTelemetria(void)
        '
        ' ----------------------------------------------

        'Stop

        cDat = CInt(Mid(sParam02, 1, 3))
        sDat = Mid(sParam02, 4)

        sAux = Mid$(sDat, 1, 3)
        If (IsNumeric(sAux) = True) Then
            SetBrujula(sAux)
        End If

        sAux = Mid$(sDat, 5, 3)
        If (IsNumeric(sAux) = True) Then
            SetInclinacion(sAux)
        End If

        sAux = Mid$(sDat, 9, 3)
        If (IsNumeric(sAux) = True) Then
            SetNivelBateria(sAux)
        End If

        sAux = Mid$(sDat, 13, 5)
        If (IsNumeric(sAux) = True) Then
            setDistancia_PING(sAux)
        End If

        sAux = Mid$(sDat, 19, 5)
        If (IsNumeric(sAux) = True) Then
            setTemperatura(sAux)
        End If

        sAux = Mid$(sDat, 25, 5)
        If (IsNumeric(sAux) = True) Then
            setHumedad(sAux)
        End If

    End Sub

    ' ---------------------------------------
    '
    '  FUNCION ASOCIADA A COMANDOS DE RETORNO
    '
    ' fn_DATA_00
    '
    ' ---------------------------------------

    Public Sub fn_DATA_00()

        Dim sDat As String
        Dim cDat As Integer


        cDat = CInt(Mid(sParam02, 1, 3))
        sDat = Mid(sParam02, 4)

        sDat = sOrigen & " " & sDat
        displayLstRX(sDat)

    End Sub

    ' ---------------------------------------
    '
    '  FUNCION ASOCIADA A COMANDOS DE RETORNO
    '
    ' fn_DATA_01
    '
    ' ---------------------------------------

    Public Sub fn_DATA_01()




    End Sub

    ' ---------------------------------------
    '
    '  FUNCION ASOCIADA A COMANDOS DE RETORNO
    '
    ' fn_DATA_02
    '
    ' ---------------------------------------

    Public Sub fn_DATA_02()


    End Sub

    ' ---------------------------------------
    '
    '  FUNCION ASOCIADA A COMANDOS DE RETORNO
    '
    ' fn_DATA_03
    '
    ' ---------------------------------------

    Public Sub fn_DATA_03()


    End Sub



End Class
