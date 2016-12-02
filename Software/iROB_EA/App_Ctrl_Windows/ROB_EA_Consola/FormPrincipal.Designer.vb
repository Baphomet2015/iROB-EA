<Global.Microsoft.VisualBasic.CompilerServices.DesignerGenerated()> _
Partial Class FormPrincipal
    Inherits System.Windows.Forms.Form

    'Form reemplaza a Dispose para limpiar la lista de componentes.
    <System.Diagnostics.DebuggerNonUserCode()> _
    Protected Overrides Sub Dispose(ByVal disposing As Boolean)
        Try
            If disposing AndAlso components IsNot Nothing Then
                components.Dispose()
            End If
        Finally
            MyBase.Dispose(disposing)
        End Try
    End Sub

    'Requerido por el Diseñador de Windows Forms
    Private components As System.ComponentModel.IContainer

    'NOTA: el Diseñador de Windows Forms necesita el siguiente procedimiento
    'Se puede modificar usando el Diseñador de Windows Forms.  
    'No lo modifique con el editor de código.
    <System.Diagnostics.DebuggerStepThrough()> _
    Private Sub InitializeComponent()
        Me.components = New System.ComponentModel.Container
        Dim resources As System.ComponentModel.ComponentResourceManager = New System.ComponentModel.ComponentResourceManager(GetType(FormPrincipal))
        Me.SerialPort_01 = New System.IO.Ports.SerialPort(Me.components)
        Me.BotonSelPuerto = New System.Windows.Forms.Button
        Me.CampoListaPuertos = New System.Windows.Forms.ComboBox
        Me.GrupoPSerie = New System.Windows.Forms.GroupBox
        Me.Icono_TRX = New System.Windows.Forms.PictureBox
        Me.BotonScanPuerto = New System.Windows.Forms.Button
        Me.Texto_TRX = New System.Windows.Forms.Label
        Me.Campo_Lst_RX = New System.Windows.Forms.TextBox
        Me.Campo_TX = New System.Windows.Forms.TextBox
        Me.Boton_TX = New System.Windows.Forms.Button
        Me.Grupo_TXRX = New System.Windows.Forms.GroupBox
        Me.Boton_AutoEnvio = New System.Windows.Forms.Button
        Me.CampoListaComandosDesc = New System.Windows.Forms.TextBox
        Me.CampoListaComandos = New System.Windows.Forms.ComboBox
        Me.CampoListaFamilias = New System.Windows.Forms.ComboBox
        Me.Texto_Info_TX = New System.Windows.Forms.Label
        Me.Boton_Cls_RX = New System.Windows.Forms.Button
        Me.Campo_Act_RX = New System.Windows.Forms.TextBox
        Me.Texto_TX = New System.Windows.Forms.Label
        Me.Texto_RX = New System.Windows.Forms.Label
        Me.PanelTelemetria = New System.Windows.Forms.Panel
        Me.GrupoTelemetria_1 = New System.Windows.Forms.GroupBox
        Me.Texto_F10 = New System.Windows.Forms.Label
        Me.Boton_F10 = New System.Windows.Forms.Button
        Me.CampoImgBateria_01 = New System.Windows.Forms.PictureBox
        Me.CampoImgBateria_00 = New System.Windows.Forms.PictureBox
        Me.CampoImgBateria_03 = New System.Windows.Forms.PictureBox
        Me.CampoImgBateria_02 = New System.Windows.Forms.PictureBox
        Me.CampoImgBateria_04 = New System.Windows.Forms.PictureBox
        Me.CampoImgBateria_05 = New System.Windows.Forms.PictureBox
        Me.TextoNivelBateria_02 = New System.Windows.Forms.Label
        Me.TextoDistancia_PING_02 = New System.Windows.Forms.Label
        Me.TextoNivelXBEE = New System.Windows.Forms.Label
        Me.CampoNivelXBEE_01 = New System.Windows.Forms.TextBox
        Me.TextoNivelBateria = New System.Windows.Forms.Label
        Me.CampoNivelBateria = New System.Windows.Forms.TextBox
        Me.ImgInclinacion = New System.Windows.Forms.PictureBox
        Me.TextoDistancia_PING = New System.Windows.Forms.Label
        Me.CampoDistancia_PING = New System.Windows.Forms.TextBox
        Me.CampoInclinacion = New System.Windows.Forms.TextBox
        Me.CampoBrujula_02 = New System.Windows.Forms.TextBox
        Me.TextoHumedad_02 = New System.Windows.Forms.Label
        Me.CampoHumedad = New System.Windows.Forms.TextBox
        Me.TextoHumedad = New System.Windows.Forms.Label
        Me.TextoTemperatura_02 = New System.Windows.Forms.Label
        Me.CampoTemperatura = New System.Windows.Forms.TextBox
        Me.TextoTemperatura = New System.Windows.Forms.Label
        Me.CampoBrujula_01 = New System.Windows.Forms.TextBox
        Me.TextoInclinacion = New System.Windows.Forms.Label
        Me.TextoBrujula = New System.Windows.Forms.Label
        Me.PanelPSerie = New System.Windows.Forms.Panel
        Me.PanelBotones = New System.Windows.Forms.Panel
        Me.GrupoBotones_01 = New System.Windows.Forms.GroupBox
        Me.TrackBar_Ver = New System.Windows.Forms.TrackBar
        Me.TrackBar_VerInfo = New System.Windows.Forms.Label
        Me.TrackBar_HorInfo = New System.Windows.Forms.Label
        Me.TrackBar_Hor = New System.Windows.Forms.TrackBar
        Me.Texto_F09 = New System.Windows.Forms.Label
        Me.Texto_F08 = New System.Windows.Forms.Label
        Me.Texto_F07 = New System.Windows.Forms.Label
        Me.texto_F06 = New System.Windows.Forms.Label
        Me.Texto_F05 = New System.Windows.Forms.Label
        Me.Texto_F04 = New System.Windows.Forms.Label
        Me.Texto_F03 = New System.Windows.Forms.Label
        Me.Texto_F02 = New System.Windows.Forms.Label
        Me.Texto_F01 = New System.Windows.Forms.Label
        Me.Boton_STOP = New System.Windows.Forms.Button
        Me.Boton_F08 = New System.Windows.Forms.Button
        Me.Boton_F09 = New System.Windows.Forms.Button
        Me.Boton_F07 = New System.Windows.Forms.Button
        Me.Boton_F06 = New System.Windows.Forms.Button
        Me.Boton_F05 = New System.Windows.Forms.Button
        Me.Boton_LEFT = New System.Windows.Forms.Button
        Me.Boton_RIGHT = New System.Windows.Forms.Button
        Me.Boton_DOWN = New System.Windows.Forms.Button
        Me.Boton_UP = New System.Windows.Forms.Button
        Me.Boton_F04 = New System.Windows.Forms.Button
        Me.Boton_F03 = New System.Windows.Forms.Button
        Me.Boton_F02 = New System.Windows.Forms.Button
        Me.Boton_F01 = New System.Windows.Forms.Button
        Me.Img_ArduinoLogo = New System.Windows.Forms.PictureBox
        Me.PanelAplicaciones = New System.Windows.Forms.Panel
        Me.GroupBotones_02 = New System.Windows.Forms.GroupBox
        Me.ToolTip_01 = New System.Windows.Forms.ToolTip(Me.components)
        Me.Img_Logo_01 = New System.Windows.Forms.PictureBox
        Me.Img_logo_02 = New System.Windows.Forms.PictureBox
        Me.Grupo_Video = New System.Windows.Forms.GroupBox
        Me.lstDevices = New System.Windows.Forms.ListBox
        Me.btnInfo = New System.Windows.Forms.Button
        Me.picCapture = New System.Windows.Forms.PictureBox
        Me.btnStop = New System.Windows.Forms.Button
        Me.btnSave = New System.Windows.Forms.Button
        Me.btnStart = New System.Windows.Forms.Button
        Me.sfdImage = New System.Windows.Forms.SaveFileDialog
        Me.CampoNivelXBEE_02 = New System.Windows.Forms.TextBox
        Me.GrupoPSerie.SuspendLayout()
        CType(Me.Icono_TRX, System.ComponentModel.ISupportInitialize).BeginInit()
        Me.Grupo_TXRX.SuspendLayout()
        Me.PanelTelemetria.SuspendLayout()
        Me.GrupoTelemetria_1.SuspendLayout()
        CType(Me.CampoImgBateria_01, System.ComponentModel.ISupportInitialize).BeginInit()
        CType(Me.CampoImgBateria_00, System.ComponentModel.ISupportInitialize).BeginInit()
        CType(Me.CampoImgBateria_03, System.ComponentModel.ISupportInitialize).BeginInit()
        CType(Me.CampoImgBateria_02, System.ComponentModel.ISupportInitialize).BeginInit()
        CType(Me.CampoImgBateria_04, System.ComponentModel.ISupportInitialize).BeginInit()
        CType(Me.CampoImgBateria_05, System.ComponentModel.ISupportInitialize).BeginInit()
        CType(Me.ImgInclinacion, System.ComponentModel.ISupportInitialize).BeginInit()
        Me.PanelBotones.SuspendLayout()
        Me.GrupoBotones_01.SuspendLayout()
        CType(Me.TrackBar_Ver, System.ComponentModel.ISupportInitialize).BeginInit()
        CType(Me.TrackBar_Hor, System.ComponentModel.ISupportInitialize).BeginInit()
        CType(Me.Img_ArduinoLogo, System.ComponentModel.ISupportInitialize).BeginInit()
        Me.PanelAplicaciones.SuspendLayout()
        CType(Me.Img_Logo_01, System.ComponentModel.ISupportInitialize).BeginInit()
        CType(Me.Img_logo_02, System.ComponentModel.ISupportInitialize).BeginInit()
        Me.Grupo_Video.SuspendLayout()
        CType(Me.picCapture, System.ComponentModel.ISupportInitialize).BeginInit()
        Me.SuspendLayout()
        '
        'SerialPort_01
        '
        '
        'BotonSelPuerto
        '
        Me.BotonSelPuerto.BackColor = System.Drawing.Color.SteelBlue
        Me.BotonSelPuerto.Cursor = System.Windows.Forms.Cursors.Hand
        Me.BotonSelPuerto.FlatStyle = System.Windows.Forms.FlatStyle.Flat
        Me.BotonSelPuerto.Font = New System.Drawing.Font("Arial", 9.75!, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, CType(0, Byte))
        Me.BotonSelPuerto.ForeColor = System.Drawing.Color.White
        Me.BotonSelPuerto.Location = New System.Drawing.Point(117, 18)
        Me.BotonSelPuerto.Name = "BotonSelPuerto"
        Me.BotonSelPuerto.Size = New System.Drawing.Size(75, 25)
        Me.BotonSelPuerto.TabIndex = 3
        Me.BotonSelPuerto.Text = "ABRIR"
        Me.BotonSelPuerto.UseVisualStyleBackColor = False
        '
        'CampoListaPuertos
        '
        Me.CampoListaPuertos.BackColor = System.Drawing.Color.SlateGray
        Me.CampoListaPuertos.FlatStyle = System.Windows.Forms.FlatStyle.Flat
        Me.CampoListaPuertos.Font = New System.Drawing.Font("Arial", 10.0!, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, CType(0, Byte))
        Me.CampoListaPuertos.ForeColor = System.Drawing.Color.White
        Me.CampoListaPuertos.FormattingEnabled = True
        Me.CampoListaPuertos.Location = New System.Drawing.Point(6, 19)
        Me.CampoListaPuertos.Name = "CampoListaPuertos"
        Me.CampoListaPuertos.Size = New System.Drawing.Size(105, 24)
        Me.CampoListaPuertos.TabIndex = 4
        '
        'GrupoPSerie
        '
        Me.GrupoPSerie.BackColor = System.Drawing.Color.Transparent
        Me.GrupoPSerie.Controls.Add(Me.Icono_TRX)
        Me.GrupoPSerie.Controls.Add(Me.BotonScanPuerto)
        Me.GrupoPSerie.Controls.Add(Me.Texto_TRX)
        Me.GrupoPSerie.Controls.Add(Me.CampoListaPuertos)
        Me.GrupoPSerie.Controls.Add(Me.BotonSelPuerto)
        Me.GrupoPSerie.Font = New System.Drawing.Font("Arial", 9.0!, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, CType(0, Byte))
        Me.GrupoPSerie.ForeColor = System.Drawing.Color.DarkBlue
        Me.GrupoPSerie.Location = New System.Drawing.Point(15, 4)
        Me.GrupoPSerie.Name = "GrupoPSerie"
        Me.GrupoPSerie.Size = New System.Drawing.Size(349, 67)
        Me.GrupoPSerie.TabIndex = 9
        Me.GrupoPSerie.TabStop = False
        Me.GrupoPSerie.Text = "PUERTO Serie"
        '
        'Icono_TRX
        '
        Me.Icono_TRX.Image = CType(resources.GetObject("Icono_TRX.Image"), System.Drawing.Image)
        Me.Icono_TRX.Location = New System.Drawing.Point(298, 11)
        Me.Icono_TRX.Name = "Icono_TRX"
        Me.Icono_TRX.Size = New System.Drawing.Size(36, 33)
        Me.Icono_TRX.TabIndex = 5
        Me.Icono_TRX.TabStop = False
        Me.Icono_TRX.Visible = False
        '
        'BotonScanPuerto
        '
        Me.BotonScanPuerto.BackColor = System.Drawing.Color.SteelBlue
        Me.BotonScanPuerto.Cursor = System.Windows.Forms.Cursors.Hand
        Me.BotonScanPuerto.FlatStyle = System.Windows.Forms.FlatStyle.Flat
        Me.BotonScanPuerto.Font = New System.Drawing.Font("Arial", 8.25!, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, CType(0, Byte))
        Me.BotonScanPuerto.ForeColor = System.Drawing.Color.White
        Me.BotonScanPuerto.Location = New System.Drawing.Point(198, 18)
        Me.BotonScanPuerto.Name = "BotonScanPuerto"
        Me.BotonScanPuerto.Size = New System.Drawing.Size(94, 25)
        Me.BotonScanPuerto.TabIndex = 20
        Me.BotonScanPuerto.Text = "REFRESCAR"
        Me.BotonScanPuerto.UseVisualStyleBackColor = False
        '
        'Texto_TRX
        '
        Me.Texto_TRX.AutoSize = True
        Me.Texto_TRX.Font = New System.Drawing.Font("Arial", 12.0!, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, CType(0, Byte))
        Me.Texto_TRX.ForeColor = System.Drawing.Color.OrangeRed
        Me.Texto_TRX.Location = New System.Drawing.Point(238, 42)
        Me.Texto_TRX.Name = "Texto_TRX"
        Me.Texto_TRX.Size = New System.Drawing.Size(105, 19)
        Me.Texto_TRX.TabIndex = 19
        Me.Texto_TRX.Text = "Conectado..."
        Me.Texto_TRX.Visible = False
        '
        'Campo_Lst_RX
        '
        Me.Campo_Lst_RX.BackColor = System.Drawing.Color.LightSteelBlue
        Me.Campo_Lst_RX.BorderStyle = System.Windows.Forms.BorderStyle.FixedSingle
        Me.Campo_Lst_RX.Font = New System.Drawing.Font("Arial", 8.25!, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, CType(0, Byte))
        Me.Campo_Lst_RX.ForeColor = System.Drawing.Color.Navy
        Me.Campo_Lst_RX.Location = New System.Drawing.Point(6, 16)
        Me.Campo_Lst_RX.Multiline = True
        Me.Campo_Lst_RX.Name = "Campo_Lst_RX"
        Me.Campo_Lst_RX.ReadOnly = True
        Me.Campo_Lst_RX.ScrollBars = System.Windows.Forms.ScrollBars.Vertical
        Me.Campo_Lst_RX.Size = New System.Drawing.Size(406, 87)
        Me.Campo_Lst_RX.TabIndex = 11
        '
        'Campo_TX
        '
        Me.Campo_TX.BackColor = System.Drawing.Color.MidnightBlue
        Me.Campo_TX.BorderStyle = System.Windows.Forms.BorderStyle.FixedSingle
        Me.Campo_TX.Font = New System.Drawing.Font("Arial", 9.75!, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, CType(0, Byte))
        Me.Campo_TX.ForeColor = System.Drawing.Color.LimeGreen
        Me.Campo_TX.Location = New System.Drawing.Point(44, 275)
        Me.Campo_TX.Name = "Campo_TX"
        Me.Campo_TX.Size = New System.Drawing.Size(290, 22)
        Me.Campo_TX.TabIndex = 12
        '
        'Boton_TX
        '
        Me.Boton_TX.BackColor = System.Drawing.Color.SteelBlue
        Me.Boton_TX.Cursor = System.Windows.Forms.Cursors.Hand
        Me.Boton_TX.FlatStyle = System.Windows.Forms.FlatStyle.Flat
        Me.Boton_TX.Font = New System.Drawing.Font("Arial", 9.75!, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, CType(0, Byte))
        Me.Boton_TX.ForeColor = System.Drawing.Color.White
        Me.Boton_TX.Location = New System.Drawing.Point(340, 273)
        Me.Boton_TX.Name = "Boton_TX"
        Me.Boton_TX.Size = New System.Drawing.Size(72, 24)
        Me.Boton_TX.TabIndex = 13
        Me.Boton_TX.Text = "ENVIAR"
        Me.Boton_TX.UseVisualStyleBackColor = False
        '
        'Grupo_TXRX
        '
        Me.Grupo_TXRX.BackColor = System.Drawing.Color.Transparent
        Me.Grupo_TXRX.Controls.Add(Me.Boton_AutoEnvio)
        Me.Grupo_TXRX.Controls.Add(Me.CampoListaComandosDesc)
        Me.Grupo_TXRX.Controls.Add(Me.CampoListaComandos)
        Me.Grupo_TXRX.Controls.Add(Me.CampoListaFamilias)
        Me.Grupo_TXRX.Controls.Add(Me.Texto_Info_TX)
        Me.Grupo_TXRX.Controls.Add(Me.Boton_Cls_RX)
        Me.Grupo_TXRX.Controls.Add(Me.Campo_Act_RX)
        Me.Grupo_TXRX.Controls.Add(Me.Texto_TX)
        Me.Grupo_TXRX.Controls.Add(Me.Texto_RX)
        Me.Grupo_TXRX.Controls.Add(Me.Campo_Lst_RX)
        Me.Grupo_TXRX.Controls.Add(Me.Boton_TX)
        Me.Grupo_TXRX.Controls.Add(Me.Campo_TX)
        Me.Grupo_TXRX.Font = New System.Drawing.Font("Arial", 9.75!, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, CType(0, Byte))
        Me.Grupo_TXRX.ForeColor = System.Drawing.Color.DarkBlue
        Me.Grupo_TXRX.Location = New System.Drawing.Point(586, 320)
        Me.Grupo_TXRX.Name = "Grupo_TXRX"
        Me.Grupo_TXRX.Size = New System.Drawing.Size(423, 323)
        Me.Grupo_TXRX.TabIndex = 14
        Me.Grupo_TXRX.TabStop = False
        Me.Grupo_TXRX.Text = "TRX"
        '
        'Boton_AutoEnvio
        '
        Me.Boton_AutoEnvio.BackColor = System.Drawing.Color.DarkGreen
        Me.Boton_AutoEnvio.Cursor = System.Windows.Forms.Cursors.Hand
        Me.Boton_AutoEnvio.FlatStyle = System.Windows.Forms.FlatStyle.Flat
        Me.Boton_AutoEnvio.Font = New System.Drawing.Font("Arial", 8.25!, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, CType(0, Byte))
        Me.Boton_AutoEnvio.ForeColor = System.Drawing.Color.White
        Me.Boton_AutoEnvio.Location = New System.Drawing.Point(296, 107)
        Me.Boton_AutoEnvio.Name = "Boton_AutoEnvio"
        Me.Boton_AutoEnvio.Size = New System.Drawing.Size(116, 23)
        Me.Boton_AutoEnvio.TabIndex = 32
        Me.Boton_AutoEnvio.Text = "AUTOENVIO ON"
        Me.Boton_AutoEnvio.UseVisualStyleBackColor = False
        '
        'CampoListaComandosDesc
        '
        Me.CampoListaComandosDesc.BackColor = System.Drawing.Color.MidnightBlue
        Me.CampoListaComandosDesc.BorderStyle = System.Windows.Forms.BorderStyle.FixedSingle
        Me.CampoListaComandosDesc.Font = New System.Drawing.Font("Arial", 9.0!, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, CType(0, Byte))
        Me.CampoListaComandosDesc.ForeColor = System.Drawing.Color.White
        Me.CampoListaComandosDesc.Location = New System.Drawing.Point(6, 168)
        Me.CampoListaComandosDesc.Multiline = True
        Me.CampoListaComandosDesc.Name = "CampoListaComandosDesc"
        Me.CampoListaComandosDesc.ReadOnly = True
        Me.CampoListaComandosDesc.Size = New System.Drawing.Size(406, 56)
        Me.CampoListaComandosDesc.TabIndex = 31
        Me.CampoListaComandosDesc.TextAlign = System.Windows.Forms.HorizontalAlignment.Right
        '
        'CampoListaComandos
        '
        Me.CampoListaComandos.BackColor = System.Drawing.Color.SlateGray
        Me.CampoListaComandos.FlatStyle = System.Windows.Forms.FlatStyle.Flat
        Me.CampoListaComandos.Font = New System.Drawing.Font("Arial", 9.75!, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, CType(0, Byte))
        Me.CampoListaComandos.ForeColor = System.Drawing.Color.Navy
        Me.CampoListaComandos.FormattingEnabled = True
        Me.CampoListaComandos.Location = New System.Drawing.Point(6, 138)
        Me.CampoListaComandos.Name = "CampoListaComandos"
        Me.CampoListaComandos.Size = New System.Drawing.Size(406, 24)
        Me.CampoListaComandos.TabIndex = 20
        '
        'CampoListaFamilias
        '
        Me.CampoListaFamilias.BackColor = System.Drawing.Color.SlateGray
        Me.CampoListaFamilias.FlatStyle = System.Windows.Forms.FlatStyle.Popup
        Me.CampoListaFamilias.Font = New System.Drawing.Font("Arial", 8.25!, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, CType(0, Byte))
        Me.CampoListaFamilias.ForeColor = System.Drawing.Color.Navy
        Me.CampoListaFamilias.FormattingEnabled = True
        Me.CampoListaFamilias.Location = New System.Drawing.Point(6, 107)
        Me.CampoListaFamilias.Name = "CampoListaFamilias"
        Me.CampoListaFamilias.Size = New System.Drawing.Size(221, 22)
        Me.CampoListaFamilias.TabIndex = 19
        '
        'Texto_Info_TX
        '
        Me.Texto_Info_TX.AutoSize = True
        Me.Texto_Info_TX.Font = New System.Drawing.Font("Arial", 8.25!, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, CType(0, Byte))
        Me.Texto_Info_TX.ForeColor = System.Drawing.Color.SaddleBrown
        Me.Texto_Info_TX.Location = New System.Drawing.Point(41, 304)
        Me.Texto_Info_TX.Name = "Texto_Info_TX"
        Me.Texto_Info_TX.Size = New System.Drawing.Size(160, 14)
        Me.Texto_Info_TX.TabIndex = 18
        Me.Texto_Info_TX.Text = "Doble click, borra contenido"
        '
        'Boton_Cls_RX
        '
        Me.Boton_Cls_RX.BackColor = System.Drawing.Color.SteelBlue
        Me.Boton_Cls_RX.Cursor = System.Windows.Forms.Cursors.Hand
        Me.Boton_Cls_RX.FlatStyle = System.Windows.Forms.FlatStyle.Flat
        Me.Boton_Cls_RX.Font = New System.Drawing.Font("Arial", 9.0!, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, CType(0, Byte))
        Me.Boton_Cls_RX.ForeColor = System.Drawing.Color.White
        Me.Boton_Cls_RX.Location = New System.Drawing.Point(242, 107)
        Me.Boton_Cls_RX.Name = "Boton_Cls_RX"
        Me.Boton_Cls_RX.Size = New System.Drawing.Size(48, 23)
        Me.Boton_Cls_RX.TabIndex = 17
        Me.Boton_Cls_RX.Text = "CLS"
        Me.Boton_Cls_RX.UseVisualStyleBackColor = False
        '
        'Campo_Act_RX
        '
        Me.Campo_Act_RX.BackColor = System.Drawing.Color.MidnightBlue
        Me.Campo_Act_RX.BorderStyle = System.Windows.Forms.BorderStyle.FixedSingle
        Me.Campo_Act_RX.Font = New System.Drawing.Font("Arial", 9.75!, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, CType(0, Byte))
        Me.Campo_Act_RX.ForeColor = System.Drawing.Color.LimeGreen
        Me.Campo_Act_RX.Location = New System.Drawing.Point(44, 239)
        Me.Campo_Act_RX.Name = "Campo_Act_RX"
        Me.Campo_Act_RX.ReadOnly = True
        Me.Campo_Act_RX.Size = New System.Drawing.Size(368, 22)
        Me.Campo_Act_RX.TabIndex = 16
        '
        'Texto_TX
        '
        Me.Texto_TX.AutoSize = True
        Me.Texto_TX.Font = New System.Drawing.Font("Arial", 12.0!, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, CType(0, Byte))
        Me.Texto_TX.Location = New System.Drawing.Point(8, 278)
        Me.Texto_TX.Name = "Texto_TX"
        Me.Texto_TX.Size = New System.Drawing.Size(30, 19)
        Me.Texto_TX.TabIndex = 15
        Me.Texto_TX.Text = "TX"
        '
        'Texto_RX
        '
        Me.Texto_RX.AutoSize = True
        Me.Texto_RX.Font = New System.Drawing.Font("Arial", 12.0!, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, CType(0, Byte))
        Me.Texto_RX.Location = New System.Drawing.Point(6, 239)
        Me.Texto_RX.Name = "Texto_RX"
        Me.Texto_RX.Size = New System.Drawing.Size(32, 19)
        Me.Texto_RX.TabIndex = 14
        Me.Texto_RX.Text = "RX"
        '
        'PanelTelemetria
        '
        Me.PanelTelemetria.BackColor = System.Drawing.Color.Transparent
        Me.PanelTelemetria.BorderStyle = System.Windows.Forms.BorderStyle.FixedSingle
        Me.PanelTelemetria.Controls.Add(Me.GrupoTelemetria_1)
        Me.PanelTelemetria.ForeColor = System.Drawing.Color.DimGray
        Me.PanelTelemetria.Location = New System.Drawing.Point(12, 74)
        Me.PanelTelemetria.Name = "PanelTelemetria"
        Me.PanelTelemetria.Size = New System.Drawing.Size(352, 210)
        Me.PanelTelemetria.TabIndex = 16
        '
        'GrupoTelemetria_1
        '
        Me.GrupoTelemetria_1.BackColor = System.Drawing.Color.White
        Me.GrupoTelemetria_1.Controls.Add(Me.CampoNivelXBEE_02)
        Me.GrupoTelemetria_1.Controls.Add(Me.CampoImgBateria_01)
        Me.GrupoTelemetria_1.Controls.Add(Me.CampoImgBateria_00)
        Me.GrupoTelemetria_1.Controls.Add(Me.CampoImgBateria_03)
        Me.GrupoTelemetria_1.Controls.Add(Me.CampoImgBateria_02)
        Me.GrupoTelemetria_1.Controls.Add(Me.CampoImgBateria_04)
        Me.GrupoTelemetria_1.Controls.Add(Me.CampoImgBateria_05)
        Me.GrupoTelemetria_1.Controls.Add(Me.TextoNivelBateria_02)
        Me.GrupoTelemetria_1.Controls.Add(Me.TextoDistancia_PING_02)
        Me.GrupoTelemetria_1.Controls.Add(Me.TextoNivelXBEE)
        Me.GrupoTelemetria_1.Controls.Add(Me.CampoNivelXBEE_01)
        Me.GrupoTelemetria_1.Controls.Add(Me.TextoNivelBateria)
        Me.GrupoTelemetria_1.Controls.Add(Me.CampoNivelBateria)
        Me.GrupoTelemetria_1.Controls.Add(Me.ImgInclinacion)
        Me.GrupoTelemetria_1.Controls.Add(Me.TextoDistancia_PING)
        Me.GrupoTelemetria_1.Controls.Add(Me.CampoDistancia_PING)
        Me.GrupoTelemetria_1.Controls.Add(Me.CampoInclinacion)
        Me.GrupoTelemetria_1.Controls.Add(Me.CampoBrujula_02)
        Me.GrupoTelemetria_1.Controls.Add(Me.TextoHumedad_02)
        Me.GrupoTelemetria_1.Controls.Add(Me.CampoHumedad)
        Me.GrupoTelemetria_1.Controls.Add(Me.TextoHumedad)
        Me.GrupoTelemetria_1.Controls.Add(Me.TextoTemperatura_02)
        Me.GrupoTelemetria_1.Controls.Add(Me.CampoTemperatura)
        Me.GrupoTelemetria_1.Controls.Add(Me.TextoTemperatura)
        Me.GrupoTelemetria_1.Controls.Add(Me.CampoBrujula_01)
        Me.GrupoTelemetria_1.Controls.Add(Me.TextoInclinacion)
        Me.GrupoTelemetria_1.Controls.Add(Me.TextoBrujula)
        Me.GrupoTelemetria_1.Font = New System.Drawing.Font("Arial", 8.25!, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, CType(0, Byte))
        Me.GrupoTelemetria_1.ForeColor = System.Drawing.Color.DarkBlue
        Me.GrupoTelemetria_1.Location = New System.Drawing.Point(5, 3)
        Me.GrupoTelemetria_1.Name = "GrupoTelemetria_1"
        Me.GrupoTelemetria_1.Size = New System.Drawing.Size(344, 204)
        Me.GrupoTelemetria_1.TabIndex = 5
        Me.GrupoTelemetria_1.TabStop = False
        Me.GrupoTelemetria_1.Text = "TELEMETRÍA Sensores"
        '
        'Texto_F10
        '
        Me.Texto_F10.AutoEllipsis = True
        Me.Texto_F10.BackColor = System.Drawing.Color.OrangeRed
        Me.Texto_F10.Font = New System.Drawing.Font("Arial", 8.25!, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, CType(0, Byte))
        Me.Texto_F10.ForeColor = System.Drawing.Color.White
        Me.Texto_F10.Location = New System.Drawing.Point(260, 202)
        Me.Texto_F10.Name = "Texto_F10"
        Me.Texto_F10.Size = New System.Drawing.Size(25, 16)
        Me.Texto_F10.TabIndex = 48
        Me.Texto_F10.Text = "F10"
        Me.Texto_F10.TextAlign = System.Drawing.ContentAlignment.MiddleCenter
        '
        'Boton_F10
        '
        Me.Boton_F10.AutoEllipsis = True
        Me.Boton_F10.BackgroundImageLayout = System.Windows.Forms.ImageLayout.None
        Me.Boton_F10.Cursor = System.Windows.Forms.Cursors.Hand
        Me.Boton_F10.FlatAppearance.BorderSize = 0
        Me.Boton_F10.FlatAppearance.MouseDownBackColor = System.Drawing.Color.Gold
        Me.Boton_F10.FlatAppearance.MouseOverBackColor = System.Drawing.Color.Transparent
        Me.Boton_F10.FlatStyle = System.Windows.Forms.FlatStyle.Flat
        Me.Boton_F10.ForeColor = System.Drawing.Color.Transparent
        Me.Boton_F10.Image = Global.iROB_EA_V1_Consola.My.Resources.Resources.ic_menu_signal
        Me.Boton_F10.Location = New System.Drawing.Point(260, 200)
        Me.Boton_F10.Name = "Boton_F10"
        Me.Boton_F10.Size = New System.Drawing.Size(77, 84)
        Me.Boton_F10.TabIndex = 34
        Me.Boton_F10.UseVisualStyleBackColor = True
        '
        'CampoImgBateria_01
        '
        Me.CampoImgBateria_01.Image = Global.iROB_EA_V1_Consola.My.Resources.Resources.bateria_01
        Me.CampoImgBateria_01.Location = New System.Drawing.Point(288, 82)
        Me.CampoImgBateria_01.Name = "CampoImgBateria_01"
        Me.CampoImgBateria_01.Size = New System.Drawing.Size(43, 92)
        Me.CampoImgBateria_01.TabIndex = 47
        Me.CampoImgBateria_01.TabStop = False
        Me.CampoImgBateria_01.Visible = False
        '
        'CampoImgBateria_00
        '
        Me.CampoImgBateria_00.Image = Global.iROB_EA_V1_Consola.My.Resources.Resources.bateria_00
        Me.CampoImgBateria_00.Location = New System.Drawing.Point(288, 82)
        Me.CampoImgBateria_00.Name = "CampoImgBateria_00"
        Me.CampoImgBateria_00.Size = New System.Drawing.Size(43, 92)
        Me.CampoImgBateria_00.TabIndex = 40
        Me.CampoImgBateria_00.TabStop = False
        Me.CampoImgBateria_00.Visible = False
        '
        'CampoImgBateria_03
        '
        Me.CampoImgBateria_03.Image = Global.iROB_EA_V1_Consola.My.Resources.Resources.bateria_03
        Me.CampoImgBateria_03.Location = New System.Drawing.Point(288, 82)
        Me.CampoImgBateria_03.Name = "CampoImgBateria_03"
        Me.CampoImgBateria_03.Size = New System.Drawing.Size(43, 92)
        Me.CampoImgBateria_03.TabIndex = 46
        Me.CampoImgBateria_03.TabStop = False
        Me.CampoImgBateria_03.Visible = False
        '
        'CampoImgBateria_02
        '
        Me.CampoImgBateria_02.Image = Global.iROB_EA_V1_Consola.My.Resources.Resources.bateria_02
        Me.CampoImgBateria_02.Location = New System.Drawing.Point(288, 82)
        Me.CampoImgBateria_02.Name = "CampoImgBateria_02"
        Me.CampoImgBateria_02.Size = New System.Drawing.Size(43, 92)
        Me.CampoImgBateria_02.TabIndex = 45
        Me.CampoImgBateria_02.TabStop = False
        Me.CampoImgBateria_02.Visible = False
        '
        'CampoImgBateria_04
        '
        Me.CampoImgBateria_04.Image = Global.iROB_EA_V1_Consola.My.Resources.Resources.bateria_04
        Me.CampoImgBateria_04.Location = New System.Drawing.Point(288, 82)
        Me.CampoImgBateria_04.Name = "CampoImgBateria_04"
        Me.CampoImgBateria_04.Size = New System.Drawing.Size(43, 92)
        Me.CampoImgBateria_04.TabIndex = 44
        Me.CampoImgBateria_04.TabStop = False
        Me.CampoImgBateria_04.Visible = False
        '
        'CampoImgBateria_05
        '
        Me.CampoImgBateria_05.Image = Global.iROB_EA_V1_Consola.My.Resources.Resources.bateria_05
        Me.CampoImgBateria_05.Location = New System.Drawing.Point(288, 82)
        Me.CampoImgBateria_05.Name = "CampoImgBateria_05"
        Me.CampoImgBateria_05.Size = New System.Drawing.Size(43, 92)
        Me.CampoImgBateria_05.TabIndex = 43
        Me.CampoImgBateria_05.TabStop = False
        Me.CampoImgBateria_05.Visible = False
        '
        'TextoNivelBateria_02
        '
        Me.TextoNivelBateria_02.AutoSize = True
        Me.TextoNivelBateria_02.Font = New System.Drawing.Font("Arial", 12.0!, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, CType(0, Byte))
        Me.TextoNivelBateria_02.ForeColor = System.Drawing.Color.DarkGreen
        Me.TextoNivelBateria_02.Location = New System.Drawing.Point(156, 155)
        Me.TextoNivelBateria_02.Name = "TextoNivelBateria_02"
        Me.TextoNivelBateria_02.Size = New System.Drawing.Size(20, 19)
        Me.TextoNivelBateria_02.TabIndex = 42
        Me.TextoNivelBateria_02.Text = "V"
        '
        'TextoDistancia_PING_02
        '
        Me.TextoDistancia_PING_02.AutoSize = True
        Me.TextoDistancia_PING_02.Font = New System.Drawing.Font("Arial", 12.0!, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, CType(0, Byte))
        Me.TextoDistancia_PING_02.ForeColor = System.Drawing.Color.DarkGreen
        Me.TextoDistancia_PING_02.Location = New System.Drawing.Point(152, 45)
        Me.TextoDistancia_PING_02.Name = "TextoDistancia_PING_02"
        Me.TextoDistancia_PING_02.Size = New System.Drawing.Size(32, 19)
        Me.TextoDistancia_PING_02.TabIndex = 41
        Me.TextoDistancia_PING_02.Text = "cm"
        '
        'TextoNivelXBEE
        '
        Me.TextoNivelXBEE.AutoSize = True
        Me.TextoNivelXBEE.Font = New System.Drawing.Font("Arial", 9.75!, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, CType(0, Byte))
        Me.TextoNivelXBEE.ForeColor = System.Drawing.Color.DarkGreen
        Me.TextoNivelXBEE.Location = New System.Drawing.Point(35, 177)
        Me.TextoNivelXBEE.Name = "TextoNivelXBEE"
        Me.TextoNivelXBEE.Size = New System.Drawing.Size(42, 16)
        Me.TextoNivelXBEE.TabIndex = 39
        Me.TextoNivelXBEE.Text = "XBEE"
        '
        'CampoNivelXBEE_01
        '
        Me.CampoNivelXBEE_01.BackColor = System.Drawing.Color.SlateGray
        Me.CampoNivelXBEE_01.BorderStyle = System.Windows.Forms.BorderStyle.None
        Me.CampoNivelXBEE_01.Font = New System.Drawing.Font("Arial", 12.0!, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, CType(0, Byte))
        Me.CampoNivelXBEE_01.ForeColor = System.Drawing.Color.White
        Me.CampoNivelXBEE_01.Location = New System.Drawing.Point(83, 177)
        Me.CampoNivelXBEE_01.Multiline = True
        Me.CampoNivelXBEE_01.Name = "CampoNivelXBEE_01"
        Me.CampoNivelXBEE_01.ReadOnly = True
        Me.CampoNivelXBEE_01.Size = New System.Drawing.Size(67, 21)
        Me.CampoNivelXBEE_01.TabIndex = 38
        Me.CampoNivelXBEE_01.TextAlign = System.Windows.Forms.HorizontalAlignment.Center
        '
        'TextoNivelBateria
        '
        Me.TextoNivelBateria.AutoSize = True
        Me.TextoNivelBateria.Font = New System.Drawing.Font("Arial", 9.75!, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, CType(0, Byte))
        Me.TextoNivelBateria.ForeColor = System.Drawing.Color.DarkGreen
        Me.TextoNivelBateria.Location = New System.Drawing.Point(15, 154)
        Me.TextoNivelBateria.Name = "TextoNivelBateria"
        Me.TextoNivelBateria.Size = New System.Drawing.Size(64, 16)
        Me.TextoNivelBateria.TabIndex = 37
        Me.TextoNivelBateria.Text = "BATERIA"
        '
        'CampoNivelBateria
        '
        Me.CampoNivelBateria.BackColor = System.Drawing.Color.SlateGray
        Me.CampoNivelBateria.BorderStyle = System.Windows.Forms.BorderStyle.None
        Me.CampoNivelBateria.Font = New System.Drawing.Font("Arial", 12.0!, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, CType(0, Byte))
        Me.CampoNivelBateria.ForeColor = System.Drawing.Color.White
        Me.CampoNivelBateria.Location = New System.Drawing.Point(83, 152)
        Me.CampoNivelBateria.Multiline = True
        Me.CampoNivelBateria.Name = "CampoNivelBateria"
        Me.CampoNivelBateria.ReadOnly = True
        Me.CampoNivelBateria.Size = New System.Drawing.Size(67, 22)
        Me.CampoNivelBateria.TabIndex = 36
        Me.CampoNivelBateria.TextAlign = System.Windows.Forms.HorizontalAlignment.Center
        '
        'ImgInclinacion
        '
        Me.ImgInclinacion.Image = Global.iROB_EA_V1_Consola.My.Resources.Resources.volcado
        Me.ImgInclinacion.Location = New System.Drawing.Point(156, 119)
        Me.ImgInclinacion.Name = "ImgInclinacion"
        Me.ImgInclinacion.Size = New System.Drawing.Size(33, 33)
        Me.ImgInclinacion.TabIndex = 35
        Me.ImgInclinacion.TabStop = False
        Me.ImgInclinacion.Visible = False
        '
        'TextoDistancia_PING
        '
        Me.TextoDistancia_PING.AutoSize = True
        Me.TextoDistancia_PING.Font = New System.Drawing.Font("Arial", 9.75!, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, CType(0, Byte))
        Me.TextoDistancia_PING.ForeColor = System.Drawing.Color.DarkGreen
        Me.TextoDistancia_PING.Location = New System.Drawing.Point(37, 47)
        Me.TextoDistancia_PING.Name = "TextoDistancia_PING"
        Me.TextoDistancia_PING.Size = New System.Drawing.Size(40, 16)
        Me.TextoDistancia_PING.TabIndex = 34
        Me.TextoDistancia_PING.Text = "PING"
        '
        'CampoDistancia_PING
        '
        Me.CampoDistancia_PING.BackColor = System.Drawing.Color.SlateGray
        Me.CampoDistancia_PING.BorderStyle = System.Windows.Forms.BorderStyle.None
        Me.CampoDistancia_PING.Font = New System.Drawing.Font("Arial", 12.0!, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, CType(0, Byte))
        Me.CampoDistancia_PING.ForeColor = System.Drawing.Color.White
        Me.CampoDistancia_PING.Location = New System.Drawing.Point(83, 44)
        Me.CampoDistancia_PING.Multiline = True
        Me.CampoDistancia_PING.Name = "CampoDistancia_PING"
        Me.CampoDistancia_PING.ReadOnly = True
        Me.CampoDistancia_PING.Size = New System.Drawing.Size(67, 22)
        Me.CampoDistancia_PING.TabIndex = 33
        Me.CampoDistancia_PING.TextAlign = System.Windows.Forms.HorizontalAlignment.Center
        '
        'CampoInclinacion
        '
        Me.CampoInclinacion.BackColor = System.Drawing.Color.SlateGray
        Me.CampoInclinacion.BorderStyle = System.Windows.Forms.BorderStyle.None
        Me.CampoInclinacion.Font = New System.Drawing.Font("Arial", 12.0!, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, CType(0, Byte))
        Me.CampoInclinacion.ForeColor = System.Drawing.Color.White
        Me.CampoInclinacion.Location = New System.Drawing.Point(83, 125)
        Me.CampoInclinacion.Multiline = True
        Me.CampoInclinacion.Name = "CampoInclinacion"
        Me.CampoInclinacion.ReadOnly = True
        Me.CampoInclinacion.Size = New System.Drawing.Size(67, 22)
        Me.CampoInclinacion.TabIndex = 32
        Me.CampoInclinacion.TextAlign = System.Windows.Forms.HorizontalAlignment.Center
        '
        'CampoBrujula_02
        '
        Me.CampoBrujula_02.BackColor = System.Drawing.Color.SlateGray
        Me.CampoBrujula_02.BorderStyle = System.Windows.Forms.BorderStyle.None
        Me.CampoBrujula_02.Font = New System.Drawing.Font("Arial", 9.75!, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, CType(0, Byte))
        Me.CampoBrujula_02.ForeColor = System.Drawing.Color.White
        Me.CampoBrujula_02.Location = New System.Drawing.Point(156, 17)
        Me.CampoBrujula_02.Multiline = True
        Me.CampoBrujula_02.Name = "CampoBrujula_02"
        Me.CampoBrujula_02.ReadOnly = True
        Me.CampoBrujula_02.Size = New System.Drawing.Size(175, 22)
        Me.CampoBrujula_02.TabIndex = 31
        Me.CampoBrujula_02.TextAlign = System.Windows.Forms.HorizontalAlignment.Center
        '
        'TextoHumedad_02
        '
        Me.TextoHumedad_02.AutoSize = True
        Me.TextoHumedad_02.Font = New System.Drawing.Font("Arial", 12.0!, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, CType(0, Byte))
        Me.TextoHumedad_02.ForeColor = System.Drawing.Color.DarkGreen
        Me.TextoHumedad_02.Location = New System.Drawing.Point(152, 97)
        Me.TextoHumedad_02.Name = "TextoHumedad_02"
        Me.TextoHumedad_02.Size = New System.Drawing.Size(25, 19)
        Me.TextoHumedad_02.TabIndex = 30
        Me.TextoHumedad_02.Text = "%"
        '
        'CampoHumedad
        '
        Me.CampoHumedad.BackColor = System.Drawing.Color.SlateGray
        Me.CampoHumedad.BorderStyle = System.Windows.Forms.BorderStyle.None
        Me.CampoHumedad.Font = New System.Drawing.Font("Arial", 12.0!, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, CType(0, Byte))
        Me.CampoHumedad.ForeColor = System.Drawing.Color.White
        Me.CampoHumedad.Location = New System.Drawing.Point(83, 97)
        Me.CampoHumedad.Multiline = True
        Me.CampoHumedad.Name = "CampoHumedad"
        Me.CampoHumedad.ReadOnly = True
        Me.CampoHumedad.Size = New System.Drawing.Size(67, 22)
        Me.CampoHumedad.TabIndex = 29
        Me.CampoHumedad.TextAlign = System.Windows.Forms.HorizontalAlignment.Center
        '
        'TextoHumedad
        '
        Me.TextoHumedad.AutoSize = True
        Me.TextoHumedad.Font = New System.Drawing.Font("Arial", 9.75!, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, CType(0, Byte))
        Me.TextoHumedad.ForeColor = System.Drawing.Color.DarkGreen
        Me.TextoHumedad.Location = New System.Drawing.Point(7, 99)
        Me.TextoHumedad.Name = "TextoHumedad"
        Me.TextoHumedad.Size = New System.Drawing.Size(72, 16)
        Me.TextoHumedad.TabIndex = 28
        Me.TextoHumedad.Text = "HUMEDAD"
        '
        'TextoTemperatura_02
        '
        Me.TextoTemperatura_02.AutoSize = True
        Me.TextoTemperatura_02.Font = New System.Drawing.Font("Arial", 12.0!, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, CType(0, Byte))
        Me.TextoTemperatura_02.ForeColor = System.Drawing.Color.DarkGreen
        Me.TextoTemperatura_02.Location = New System.Drawing.Point(152, 70)
        Me.TextoTemperatura_02.Name = "TextoTemperatura_02"
        Me.TextoTemperatura_02.Size = New System.Drawing.Size(27, 19)
        Me.TextoTemperatura_02.TabIndex = 21
        Me.TextoTemperatura_02.Text = "ºC"
        '
        'CampoTemperatura
        '
        Me.CampoTemperatura.BackColor = System.Drawing.Color.SlateGray
        Me.CampoTemperatura.BorderStyle = System.Windows.Forms.BorderStyle.None
        Me.CampoTemperatura.Font = New System.Drawing.Font("Arial", 12.0!, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, CType(0, Byte))
        Me.CampoTemperatura.ForeColor = System.Drawing.Color.White
        Me.CampoTemperatura.Location = New System.Drawing.Point(83, 69)
        Me.CampoTemperatura.Multiline = True
        Me.CampoTemperatura.Name = "CampoTemperatura"
        Me.CampoTemperatura.ReadOnly = True
        Me.CampoTemperatura.Size = New System.Drawing.Size(67, 22)
        Me.CampoTemperatura.TabIndex = 19
        Me.CampoTemperatura.TextAlign = System.Windows.Forms.HorizontalAlignment.Center
        '
        'TextoTemperatura
        '
        Me.TextoTemperatura.AutoSize = True
        Me.TextoTemperatura.Font = New System.Drawing.Font("Arial", 9.75!, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, CType(0, Byte))
        Me.TextoTemperatura.ForeColor = System.Drawing.Color.DarkGreen
        Me.TextoTemperatura.Location = New System.Drawing.Point(35, 72)
        Me.TextoTemperatura.Name = "TextoTemperatura"
        Me.TextoTemperatura.Size = New System.Drawing.Size(44, 16)
        Me.TextoTemperatura.TabIndex = 20
        Me.TextoTemperatura.Text = "TEMP"
        '
        'CampoBrujula_01
        '
        Me.CampoBrujula_01.BackColor = System.Drawing.Color.SlateGray
        Me.CampoBrujula_01.BorderStyle = System.Windows.Forms.BorderStyle.None
        Me.CampoBrujula_01.Font = New System.Drawing.Font("Arial", 12.0!, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, CType(0, Byte))
        Me.CampoBrujula_01.ForeColor = System.Drawing.Color.White
        Me.CampoBrujula_01.Location = New System.Drawing.Point(83, 17)
        Me.CampoBrujula_01.Multiline = True
        Me.CampoBrujula_01.Name = "CampoBrujula_01"
        Me.CampoBrujula_01.ReadOnly = True
        Me.CampoBrujula_01.Size = New System.Drawing.Size(67, 22)
        Me.CampoBrujula_01.TabIndex = 11
        Me.CampoBrujula_01.TextAlign = System.Windows.Forms.HorizontalAlignment.Center
        '
        'TextoInclinacion
        '
        Me.TextoInclinacion.AutoSize = True
        Me.TextoInclinacion.Font = New System.Drawing.Font("Arial", 9.75!, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, CType(0, Byte))
        Me.TextoInclinacion.ForeColor = System.Drawing.Color.DarkGreen
        Me.TextoInclinacion.Location = New System.Drawing.Point(18, 125)
        Me.TextoInclinacion.Name = "TextoInclinacion"
        Me.TextoInclinacion.Size = New System.Drawing.Size(61, 16)
        Me.TextoInclinacion.TabIndex = 5
        Me.TextoInclinacion.Text = "VUELCO"
        '
        'TextoBrujula
        '
        Me.TextoBrujula.AutoSize = True
        Me.TextoBrujula.Font = New System.Drawing.Font("Arial", 9.75!, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, CType(0, Byte))
        Me.TextoBrujula.ForeColor = System.Drawing.Color.DarkGreen
        Me.TextoBrujula.Location = New System.Drawing.Point(11, 19)
        Me.TextoBrujula.Name = "TextoBrujula"
        Me.TextoBrujula.Size = New System.Drawing.Size(68, 16)
        Me.TextoBrujula.TabIndex = 2
        Me.TextoBrujula.Text = "BRUJULA"
        '
        'PanelPSerie
        '
        Me.PanelPSerie.BackColor = System.Drawing.Color.Transparent
        Me.PanelPSerie.ForeColor = System.Drawing.SystemColors.ControlText
        Me.PanelPSerie.Location = New System.Drawing.Point(12, 12)
        Me.PanelPSerie.Name = "PanelPSerie"
        Me.PanelPSerie.Size = New System.Drawing.Size(352, 59)
        Me.PanelPSerie.TabIndex = 17
        '
        'PanelBotones
        '
        Me.PanelBotones.BackColor = System.Drawing.Color.Transparent
        Me.PanelBotones.Controls.Add(Me.GrupoBotones_01)
        Me.PanelBotones.Location = New System.Drawing.Point(12, 290)
        Me.PanelBotones.Name = "PanelBotones"
        Me.PanelBotones.Size = New System.Drawing.Size(568, 353)
        Me.PanelBotones.TabIndex = 18
        '
        'GrupoBotones_01
        '
        Me.GrupoBotones_01.Controls.Add(Me.Texto_F10)
        Me.GrupoBotones_01.Controls.Add(Me.TrackBar_Ver)
        Me.GrupoBotones_01.Controls.Add(Me.Boton_F10)
        Me.GrupoBotones_01.Controls.Add(Me.TrackBar_VerInfo)
        Me.GrupoBotones_01.Controls.Add(Me.TrackBar_HorInfo)
        Me.GrupoBotones_01.Controls.Add(Me.TrackBar_Hor)
        Me.GrupoBotones_01.Controls.Add(Me.Texto_F09)
        Me.GrupoBotones_01.Controls.Add(Me.Texto_F08)
        Me.GrupoBotones_01.Controls.Add(Me.Texto_F07)
        Me.GrupoBotones_01.Controls.Add(Me.texto_F06)
        Me.GrupoBotones_01.Controls.Add(Me.Texto_F05)
        Me.GrupoBotones_01.Controls.Add(Me.Texto_F04)
        Me.GrupoBotones_01.Controls.Add(Me.Texto_F03)
        Me.GrupoBotones_01.Controls.Add(Me.Texto_F02)
        Me.GrupoBotones_01.Controls.Add(Me.Texto_F01)
        Me.GrupoBotones_01.Controls.Add(Me.Boton_STOP)
        Me.GrupoBotones_01.Controls.Add(Me.Boton_F08)
        Me.GrupoBotones_01.Controls.Add(Me.Boton_F09)
        Me.GrupoBotones_01.Controls.Add(Me.Boton_F07)
        Me.GrupoBotones_01.Controls.Add(Me.Boton_F06)
        Me.GrupoBotones_01.Controls.Add(Me.Boton_F05)
        Me.GrupoBotones_01.Controls.Add(Me.Boton_LEFT)
        Me.GrupoBotones_01.Controls.Add(Me.Boton_RIGHT)
        Me.GrupoBotones_01.Controls.Add(Me.Boton_DOWN)
        Me.GrupoBotones_01.Controls.Add(Me.Boton_UP)
        Me.GrupoBotones_01.Controls.Add(Me.Boton_F04)
        Me.GrupoBotones_01.Controls.Add(Me.Boton_F03)
        Me.GrupoBotones_01.Controls.Add(Me.Boton_F02)
        Me.GrupoBotones_01.Controls.Add(Me.Boton_F01)
        Me.GrupoBotones_01.Font = New System.Drawing.Font("Arial", 8.25!, System.Drawing.FontStyle.Bold)
        Me.GrupoBotones_01.ForeColor = System.Drawing.Color.DarkBlue
        Me.GrupoBotones_01.Location = New System.Drawing.Point(3, -2)
        Me.GrupoBotones_01.Name = "GrupoBotones_01"
        Me.GrupoBotones_01.Size = New System.Drawing.Size(562, 352)
        Me.GrupoBotones_01.TabIndex = 8
        Me.GrupoBotones_01.TabStop = False
        Me.GrupoBotones_01.Text = "Funciones Directas"
        '
        'TrackBar_Ver
        '
        Me.TrackBar_Ver.AutoSize = False
        Me.TrackBar_Ver.BackColor = System.Drawing.Color.SteelBlue
        Me.TrackBar_Ver.Location = New System.Drawing.Point(13, 284)
        Me.TrackBar_Ver.Maximum = 180
        Me.TrackBar_Ver.Name = "TrackBar_Ver"
        Me.TrackBar_Ver.Size = New System.Drawing.Size(481, 26)
        Me.TrackBar_Ver.TabIndex = 33
        Me.TrackBar_Ver.TickFrequency = 0
        '
        'TrackBar_VerInfo
        '
        Me.TrackBar_VerInfo.AutoEllipsis = True
        Me.TrackBar_VerInfo.BackColor = System.Drawing.Color.OrangeRed
        Me.TrackBar_VerInfo.Font = New System.Drawing.Font("Arial", 9.75!, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, CType(0, Byte))
        Me.TrackBar_VerInfo.ForeColor = System.Drawing.Color.White
        Me.TrackBar_VerInfo.Location = New System.Drawing.Point(499, 285)
        Me.TrackBar_VerInfo.Name = "TrackBar_VerInfo"
        Me.TrackBar_VerInfo.Size = New System.Drawing.Size(57, 25)
        Me.TrackBar_VerInfo.TabIndex = 32
        Me.TrackBar_VerInfo.Text = "VER"
        Me.TrackBar_VerInfo.TextAlign = System.Drawing.ContentAlignment.MiddleCenter
        '
        'TrackBar_HorInfo
        '
        Me.TrackBar_HorInfo.AutoEllipsis = True
        Me.TrackBar_HorInfo.BackColor = System.Drawing.Color.OrangeRed
        Me.TrackBar_HorInfo.Font = New System.Drawing.Font("Arial", 9.75!, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, CType(0, Byte))
        Me.TrackBar_HorInfo.ForeColor = System.Drawing.Color.White
        Me.TrackBar_HorInfo.Location = New System.Drawing.Point(499, 313)
        Me.TrackBar_HorInfo.Name = "TrackBar_HorInfo"
        Me.TrackBar_HorInfo.Size = New System.Drawing.Size(57, 25)
        Me.TrackBar_HorInfo.TabIndex = 31
        Me.TrackBar_HorInfo.Text = "HOR"
        Me.TrackBar_HorInfo.TextAlign = System.Drawing.ContentAlignment.MiddleCenter
        '
        'TrackBar_Hor
        '
        Me.TrackBar_Hor.AutoSize = False
        Me.TrackBar_Hor.BackColor = System.Drawing.Color.SteelBlue
        Me.TrackBar_Hor.Location = New System.Drawing.Point(12, 313)
        Me.TrackBar_Hor.Maximum = 180
        Me.TrackBar_Hor.Name = "TrackBar_Hor"
        Me.TrackBar_Hor.Size = New System.Drawing.Size(481, 26)
        Me.TrackBar_Hor.TabIndex = 0
        Me.TrackBar_Hor.TickFrequency = 0
        '
        'Texto_F09
        '
        Me.Texto_F09.AutoEllipsis = True
        Me.Texto_F09.BackColor = System.Drawing.Color.OrangeRed
        Me.Texto_F09.Font = New System.Drawing.Font("Arial", 8.25!, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, CType(0, Byte))
        Me.Texto_F09.ForeColor = System.Drawing.Color.White
        Me.Texto_F09.Location = New System.Drawing.Point(177, 198)
        Me.Texto_F09.Name = "Texto_F09"
        Me.Texto_F09.Size = New System.Drawing.Size(21, 16)
        Me.Texto_F09.TabIndex = 30
        Me.Texto_F09.Text = "F9"
        Me.Texto_F09.TextAlign = System.Drawing.ContentAlignment.MiddleCenter
        '
        'Texto_F08
        '
        Me.Texto_F08.AutoEllipsis = True
        Me.Texto_F08.BackColor = System.Drawing.Color.OrangeRed
        Me.Texto_F08.Font = New System.Drawing.Font("Arial", 8.25!, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, CType(0, Byte))
        Me.Texto_F08.ForeColor = System.Drawing.Color.White
        Me.Texto_F08.Location = New System.Drawing.Point(94, 198)
        Me.Texto_F08.Name = "Texto_F08"
        Me.Texto_F08.Size = New System.Drawing.Size(21, 16)
        Me.Texto_F08.TabIndex = 29
        Me.Texto_F08.Text = "F8"
        Me.Texto_F08.TextAlign = System.Drawing.ContentAlignment.MiddleCenter
        '
        'Texto_F07
        '
        Me.Texto_F07.AutoEllipsis = True
        Me.Texto_F07.BackColor = System.Drawing.Color.OrangeRed
        Me.Texto_F07.Font = New System.Drawing.Font("Arial", 8.25!, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, CType(0, Byte))
        Me.Texto_F07.ForeColor = System.Drawing.Color.White
        Me.Texto_F07.Location = New System.Drawing.Point(9, 198)
        Me.Texto_F07.Name = "Texto_F07"
        Me.Texto_F07.Size = New System.Drawing.Size(21, 16)
        Me.Texto_F07.TabIndex = 28
        Me.Texto_F07.Text = "F7"
        Me.Texto_F07.TextAlign = System.Drawing.ContentAlignment.MiddleCenter
        '
        'texto_F06
        '
        Me.texto_F06.AutoEllipsis = True
        Me.texto_F06.BackColor = System.Drawing.Color.OrangeRed
        Me.texto_F06.Font = New System.Drawing.Font("Arial", 8.25!, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, CType(0, Byte))
        Me.texto_F06.ForeColor = System.Drawing.Color.White
        Me.texto_F06.Location = New System.Drawing.Point(177, 110)
        Me.texto_F06.Name = "texto_F06"
        Me.texto_F06.Size = New System.Drawing.Size(21, 16)
        Me.texto_F06.TabIndex = 27
        Me.texto_F06.Text = "F6"
        Me.texto_F06.TextAlign = System.Drawing.ContentAlignment.MiddleCenter
        '
        'Texto_F05
        '
        Me.Texto_F05.AutoEllipsis = True
        Me.Texto_F05.BackColor = System.Drawing.Color.OrangeRed
        Me.Texto_F05.Font = New System.Drawing.Font("Arial", 8.25!, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, CType(0, Byte))
        Me.Texto_F05.ForeColor = System.Drawing.Color.White
        Me.Texto_F05.Location = New System.Drawing.Point(94, 110)
        Me.Texto_F05.Name = "Texto_F05"
        Me.Texto_F05.Size = New System.Drawing.Size(21, 16)
        Me.Texto_F05.TabIndex = 26
        Me.Texto_F05.Text = "F5"
        Me.Texto_F05.TextAlign = System.Drawing.ContentAlignment.MiddleCenter
        '
        'Texto_F04
        '
        Me.Texto_F04.AutoEllipsis = True
        Me.Texto_F04.BackColor = System.Drawing.Color.OrangeRed
        Me.Texto_F04.Font = New System.Drawing.Font("Arial", 8.25!, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, CType(0, Byte))
        Me.Texto_F04.ForeColor = System.Drawing.Color.White
        Me.Texto_F04.Location = New System.Drawing.Point(9, 110)
        Me.Texto_F04.Name = "Texto_F04"
        Me.Texto_F04.Size = New System.Drawing.Size(21, 16)
        Me.Texto_F04.TabIndex = 25
        Me.Texto_F04.Text = "F4"
        Me.Texto_F04.TextAlign = System.Drawing.ContentAlignment.MiddleCenter
        '
        'Texto_F03
        '
        Me.Texto_F03.AutoEllipsis = True
        Me.Texto_F03.BackColor = System.Drawing.Color.OrangeRed
        Me.Texto_F03.Font = New System.Drawing.Font("Arial", 8.25!, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, CType(0, Byte))
        Me.Texto_F03.ForeColor = System.Drawing.Color.White
        Me.Texto_F03.Location = New System.Drawing.Point(177, 16)
        Me.Texto_F03.Name = "Texto_F03"
        Me.Texto_F03.Size = New System.Drawing.Size(21, 16)
        Me.Texto_F03.TabIndex = 24
        Me.Texto_F03.Text = "F3"
        Me.Texto_F03.TextAlign = System.Drawing.ContentAlignment.MiddleCenter
        '
        'Texto_F02
        '
        Me.Texto_F02.AutoEllipsis = True
        Me.Texto_F02.BackColor = System.Drawing.Color.OrangeRed
        Me.Texto_F02.Font = New System.Drawing.Font("Arial", 8.25!, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, CType(0, Byte))
        Me.Texto_F02.ForeColor = System.Drawing.Color.White
        Me.Texto_F02.Location = New System.Drawing.Point(94, 16)
        Me.Texto_F02.Name = "Texto_F02"
        Me.Texto_F02.Size = New System.Drawing.Size(21, 16)
        Me.Texto_F02.TabIndex = 23
        Me.Texto_F02.Text = "F2"
        Me.Texto_F02.TextAlign = System.Drawing.ContentAlignment.MiddleCenter
        '
        'Texto_F01
        '
        Me.Texto_F01.AutoEllipsis = True
        Me.Texto_F01.BackColor = System.Drawing.Color.OrangeRed
        Me.Texto_F01.Font = New System.Drawing.Font("Arial", 8.25!, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, CType(0, Byte))
        Me.Texto_F01.ForeColor = System.Drawing.Color.White
        Me.Texto_F01.Location = New System.Drawing.Point(8, 16)
        Me.Texto_F01.Name = "Texto_F01"
        Me.Texto_F01.Size = New System.Drawing.Size(21, 16)
        Me.Texto_F01.TabIndex = 22
        Me.Texto_F01.Text = "F1"
        Me.Texto_F01.TextAlign = System.Drawing.ContentAlignment.MiddleCenter
        '
        'Boton_STOP
        '
        Me.Boton_STOP.AutoEllipsis = True
        Me.Boton_STOP.BackgroundImageLayout = System.Windows.Forms.ImageLayout.None
        Me.Boton_STOP.Cursor = System.Windows.Forms.Cursors.Hand
        Me.Boton_STOP.FlatAppearance.BorderSize = 0
        Me.Boton_STOP.FlatAppearance.MouseDownBackColor = System.Drawing.Color.Gold
        Me.Boton_STOP.FlatAppearance.MouseOverBackColor = System.Drawing.Color.Transparent
        Me.Boton_STOP.FlatStyle = System.Windows.Forms.FlatStyle.Flat
        Me.Boton_STOP.ForeColor = System.Drawing.Color.Transparent
        Me.Boton_STOP.Image = Global.iROB_EA_V1_Consola.My.Resources.Resources.ic_menu_halt
        Me.Boton_STOP.Location = New System.Drawing.Point(392, 102)
        Me.Boton_STOP.Name = "Boton_STOP"
        Me.Boton_STOP.Size = New System.Drawing.Size(77, 84)
        Me.Boton_STOP.TabIndex = 21
        Me.Boton_STOP.UseVisualStyleBackColor = True
        '
        'Boton_F08
        '
        Me.Boton_F08.AutoEllipsis = True
        Me.Boton_F08.BackgroundImageLayout = System.Windows.Forms.ImageLayout.None
        Me.Boton_F08.Cursor = System.Windows.Forms.Cursors.Hand
        Me.Boton_F08.FlatAppearance.BorderSize = 0
        Me.Boton_F08.FlatAppearance.MouseDownBackColor = System.Drawing.Color.Gold
        Me.Boton_F08.FlatAppearance.MouseOverBackColor = System.Drawing.Color.Transparent
        Me.Boton_F08.FlatStyle = System.Windows.Forms.FlatStyle.Flat
        Me.Boton_F08.ForeColor = System.Drawing.Color.Transparent
        Me.Boton_F08.Image = Global.iROB_EA_V1_Consola.My.Resources.Resources.ic_menu_smalltiles
        Me.Boton_F08.Location = New System.Drawing.Point(94, 198)
        Me.Boton_F08.Name = "Boton_F08"
        Me.Boton_F08.Size = New System.Drawing.Size(77, 84)
        Me.Boton_F08.TabIndex = 20
        Me.Boton_F08.UseVisualStyleBackColor = True
        '
        'Boton_F09
        '
        Me.Boton_F09.AutoEllipsis = True
        Me.Boton_F09.BackgroundImageLayout = System.Windows.Forms.ImageLayout.None
        Me.Boton_F09.Cursor = System.Windows.Forms.Cursors.Hand
        Me.Boton_F09.FlatAppearance.BorderSize = 0
        Me.Boton_F09.FlatAppearance.MouseDownBackColor = System.Drawing.Color.Gold
        Me.Boton_F09.FlatAppearance.MouseOverBackColor = System.Drawing.Color.Transparent
        Me.Boton_F09.FlatStyle = System.Windows.Forms.FlatStyle.Flat
        Me.Boton_F09.ForeColor = System.Drawing.Color.Transparent
        Me.Boton_F09.Image = Global.iROB_EA_V1_Consola.My.Resources.Resources.ic_menu_smalltiles
        Me.Boton_F09.Location = New System.Drawing.Point(177, 198)
        Me.Boton_F09.Name = "Boton_F09"
        Me.Boton_F09.Size = New System.Drawing.Size(77, 84)
        Me.Boton_F09.TabIndex = 19
        Me.Boton_F09.UseVisualStyleBackColor = True
        '
        'Boton_F07
        '
        Me.Boton_F07.AutoEllipsis = True
        Me.Boton_F07.BackgroundImageLayout = System.Windows.Forms.ImageLayout.None
        Me.Boton_F07.Cursor = System.Windows.Forms.Cursors.Hand
        Me.Boton_F07.FlatAppearance.BorderSize = 0
        Me.Boton_F07.FlatAppearance.MouseDownBackColor = System.Drawing.Color.Gold
        Me.Boton_F07.FlatAppearance.MouseOverBackColor = System.Drawing.Color.Transparent
        Me.Boton_F07.FlatStyle = System.Windows.Forms.FlatStyle.Flat
        Me.Boton_F07.ForeColor = System.Drawing.Color.Transparent
        Me.Boton_F07.Image = Global.iROB_EA_V1_Consola.My.Resources.Resources.ic_menu_smalltiles
        Me.Boton_F07.Location = New System.Drawing.Point(11, 198)
        Me.Boton_F07.Name = "Boton_F07"
        Me.Boton_F07.Size = New System.Drawing.Size(77, 84)
        Me.Boton_F07.TabIndex = 18
        Me.Boton_F07.UseVisualStyleBackColor = True
        '
        'Boton_F06
        '
        Me.Boton_F06.AutoEllipsis = True
        Me.Boton_F06.BackgroundImageLayout = System.Windows.Forms.ImageLayout.None
        Me.Boton_F06.Cursor = System.Windows.Forms.Cursors.Hand
        Me.Boton_F06.FlatAppearance.BorderSize = 0
        Me.Boton_F06.FlatAppearance.MouseDownBackColor = System.Drawing.Color.Gold
        Me.Boton_F06.FlatAppearance.MouseOverBackColor = System.Drawing.Color.Transparent
        Me.Boton_F06.FlatStyle = System.Windows.Forms.FlatStyle.Flat
        Me.Boton_F06.ForeColor = System.Drawing.Color.Transparent
        Me.Boton_F06.Image = Global.iROB_EA_V1_Consola.My.Resources.Resources.ic_menu_onoff_rojo
        Me.Boton_F06.Location = New System.Drawing.Point(177, 108)
        Me.Boton_F06.Name = "Boton_F06"
        Me.Boton_F06.Size = New System.Drawing.Size(77, 84)
        Me.Boton_F06.TabIndex = 17
        Me.Boton_F06.UseVisualStyleBackColor = True
        '
        'Boton_F05
        '
        Me.Boton_F05.AutoEllipsis = True
        Me.Boton_F05.BackgroundImageLayout = System.Windows.Forms.ImageLayout.None
        Me.Boton_F05.Cursor = System.Windows.Forms.Cursors.Hand
        Me.Boton_F05.FlatAppearance.BorderSize = 0
        Me.Boton_F05.FlatAppearance.MouseDownBackColor = System.Drawing.Color.Gold
        Me.Boton_F05.FlatAppearance.MouseOverBackColor = System.Drawing.Color.Transparent
        Me.Boton_F05.FlatStyle = System.Windows.Forms.FlatStyle.Flat
        Me.Boton_F05.ForeColor = System.Drawing.Color.Transparent
        Me.Boton_F05.Image = Global.iROB_EA_V1_Consola.My.Resources.Resources.ic_menu_colorpicker
        Me.Boton_F05.Location = New System.Drawing.Point(94, 105)
        Me.Boton_F05.Name = "Boton_F05"
        Me.Boton_F05.Size = New System.Drawing.Size(77, 84)
        Me.Boton_F05.TabIndex = 16
        Me.Boton_F05.UseVisualStyleBackColor = True
        '
        'Boton_LEFT
        '
        Me.Boton_LEFT.AutoEllipsis = True
        Me.Boton_LEFT.BackgroundImageLayout = System.Windows.Forms.ImageLayout.None
        Me.Boton_LEFT.Cursor = System.Windows.Forms.Cursors.Hand
        Me.Boton_LEFT.FlatAppearance.BorderSize = 0
        Me.Boton_LEFT.FlatAppearance.MouseDownBackColor = System.Drawing.Color.Gold
        Me.Boton_LEFT.FlatAppearance.MouseOverBackColor = System.Drawing.Color.Transparent
        Me.Boton_LEFT.FlatStyle = System.Windows.Forms.FlatStyle.Flat
        Me.Boton_LEFT.ForeColor = System.Drawing.Color.Transparent
        Me.Boton_LEFT.Image = Global.iROB_EA_V1_Consola.My.Resources.Resources.ic_menu_left
        Me.Boton_LEFT.Location = New System.Drawing.Point(309, 105)
        Me.Boton_LEFT.Name = "Boton_LEFT"
        Me.Boton_LEFT.Size = New System.Drawing.Size(77, 84)
        Me.Boton_LEFT.TabIndex = 15
        Me.Boton_LEFT.UseVisualStyleBackColor = True
        '
        'Boton_RIGHT
        '
        Me.Boton_RIGHT.AutoEllipsis = True
        Me.Boton_RIGHT.BackgroundImageLayout = System.Windows.Forms.ImageLayout.None
        Me.Boton_RIGHT.Cursor = System.Windows.Forms.Cursors.Hand
        Me.Boton_RIGHT.FlatAppearance.BorderSize = 0
        Me.Boton_RIGHT.FlatAppearance.MouseDownBackColor = System.Drawing.Color.Gold
        Me.Boton_RIGHT.FlatAppearance.MouseOverBackColor = System.Drawing.Color.Transparent
        Me.Boton_RIGHT.FlatStyle = System.Windows.Forms.FlatStyle.Flat
        Me.Boton_RIGHT.ForeColor = System.Drawing.Color.Transparent
        Me.Boton_RIGHT.Image = Global.iROB_EA_V1_Consola.My.Resources.Resources.ic_menu_right
        Me.Boton_RIGHT.Location = New System.Drawing.Point(475, 100)
        Me.Boton_RIGHT.Name = "Boton_RIGHT"
        Me.Boton_RIGHT.Size = New System.Drawing.Size(77, 84)
        Me.Boton_RIGHT.TabIndex = 14
        Me.Boton_RIGHT.UseVisualStyleBackColor = True
        '
        'Boton_DOWN
        '
        Me.Boton_DOWN.AutoEllipsis = True
        Me.Boton_DOWN.BackgroundImageLayout = System.Windows.Forms.ImageLayout.None
        Me.Boton_DOWN.Cursor = System.Windows.Forms.Cursors.Hand
        Me.Boton_DOWN.FlatAppearance.BorderSize = 0
        Me.Boton_DOWN.FlatAppearance.MouseDownBackColor = System.Drawing.Color.Gold
        Me.Boton_DOWN.FlatAppearance.MouseOverBackColor = System.Drawing.Color.Transparent
        Me.Boton_DOWN.FlatStyle = System.Windows.Forms.FlatStyle.Flat
        Me.Boton_DOWN.ForeColor = System.Drawing.Color.Transparent
        Me.Boton_DOWN.Image = Global.iROB_EA_V1_Consola.My.Resources.Resources.ic_menu_down
        Me.Boton_DOWN.Location = New System.Drawing.Point(392, 186)
        Me.Boton_DOWN.Name = "Boton_DOWN"
        Me.Boton_DOWN.Size = New System.Drawing.Size(77, 84)
        Me.Boton_DOWN.TabIndex = 13
        Me.Boton_DOWN.UseVisualStyleBackColor = True
        '
        'Boton_UP
        '
        Me.Boton_UP.AutoEllipsis = True
        Me.Boton_UP.BackgroundImageLayout = System.Windows.Forms.ImageLayout.None
        Me.Boton_UP.Cursor = System.Windows.Forms.Cursors.Hand
        Me.Boton_UP.FlatAppearance.BorderSize = 0
        Me.Boton_UP.FlatAppearance.MouseDownBackColor = System.Drawing.Color.Gold
        Me.Boton_UP.FlatAppearance.MouseOverBackColor = System.Drawing.Color.Transparent
        Me.Boton_UP.FlatStyle = System.Windows.Forms.FlatStyle.Flat
        Me.Boton_UP.ForeColor = System.Drawing.Color.Transparent
        Me.Boton_UP.Image = Global.iROB_EA_V1_Consola.My.Resources.Resources.ic_menu_up
        Me.Boton_UP.Location = New System.Drawing.Point(392, 19)
        Me.Boton_UP.Name = "Boton_UP"
        Me.Boton_UP.Size = New System.Drawing.Size(77, 84)
        Me.Boton_UP.TabIndex = 12
        Me.Boton_UP.UseVisualStyleBackColor = True
        '
        'Boton_F04
        '
        Me.Boton_F04.AutoEllipsis = True
        Me.Boton_F04.BackgroundImageLayout = System.Windows.Forms.ImageLayout.None
        Me.Boton_F04.Cursor = System.Windows.Forms.Cursors.Hand
        Me.Boton_F04.FlatAppearance.BorderSize = 0
        Me.Boton_F04.FlatAppearance.MouseDownBackColor = System.Drawing.Color.Gold
        Me.Boton_F04.FlatAppearance.MouseOverBackColor = System.Drawing.Color.Transparent
        Me.Boton_F04.FlatStyle = System.Windows.Forms.FlatStyle.Flat
        Me.Boton_F04.ForeColor = System.Drawing.Color.Transparent
        Me.Boton_F04.Image = Global.iROB_EA_V1_Consola.My.Resources.Resources.ic_menu_flash
        Me.Boton_F04.Location = New System.Drawing.Point(11, 105)
        Me.Boton_F04.Name = "Boton_F04"
        Me.Boton_F04.Size = New System.Drawing.Size(77, 84)
        Me.Boton_F04.TabIndex = 11
        Me.Boton_F04.UseVisualStyleBackColor = True
        '
        'Boton_F03
        '
        Me.Boton_F03.AutoEllipsis = True
        Me.Boton_F03.BackgroundImageLayout = System.Windows.Forms.ImageLayout.None
        Me.Boton_F03.Cursor = System.Windows.Forms.Cursors.Hand
        Me.Boton_F03.FlatAppearance.BorderSize = 0
        Me.Boton_F03.FlatAppearance.MouseDownBackColor = System.Drawing.Color.Gold
        Me.Boton_F03.FlatAppearance.MouseOverBackColor = System.Drawing.Color.Transparent
        Me.Boton_F03.FlatStyle = System.Windows.Forms.FlatStyle.Flat
        Me.Boton_F03.ForeColor = System.Drawing.Color.Transparent
        Me.Boton_F03.Image = Global.iROB_EA_V1_Consola.My.Resources.Resources.ic_menu_light_rojo
        Me.Boton_F03.Location = New System.Drawing.Point(177, 10)
        Me.Boton_F03.Name = "Boton_F03"
        Me.Boton_F03.Size = New System.Drawing.Size(77, 84)
        Me.Boton_F03.TabIndex = 10
        Me.Boton_F03.UseVisualStyleBackColor = True
        '
        'Boton_F02
        '
        Me.Boton_F02.AutoEllipsis = True
        Me.Boton_F02.BackgroundImageLayout = System.Windows.Forms.ImageLayout.None
        Me.Boton_F02.Cursor = System.Windows.Forms.Cursors.Hand
        Me.Boton_F02.FlatAppearance.BorderSize = 0
        Me.Boton_F02.FlatAppearance.MouseDownBackColor = System.Drawing.Color.Gold
        Me.Boton_F02.FlatAppearance.MouseOverBackColor = System.Drawing.Color.Transparent
        Me.Boton_F02.FlatStyle = System.Windows.Forms.FlatStyle.Flat
        Me.Boton_F02.ForeColor = System.Drawing.Color.Transparent
        Me.Boton_F02.Image = Global.iROB_EA_V1_Consola.My.Resources.Resources.ic_menu_light_blanco
        Me.Boton_F02.Location = New System.Drawing.Point(94, 10)
        Me.Boton_F02.Name = "Boton_F02"
        Me.Boton_F02.Size = New System.Drawing.Size(77, 84)
        Me.Boton_F02.TabIndex = 9
        Me.Boton_F02.UseVisualStyleBackColor = True
        '
        'Boton_F01
        '
        Me.Boton_F01.AutoEllipsis = True
        Me.Boton_F01.BackgroundImageLayout = System.Windows.Forms.ImageLayout.None
        Me.Boton_F01.Cursor = System.Windows.Forms.Cursors.Hand
        Me.Boton_F01.FlatAppearance.BorderSize = 0
        Me.Boton_F01.FlatAppearance.MouseDownBackColor = System.Drawing.Color.Gold
        Me.Boton_F01.FlatAppearance.MouseOverBackColor = System.Drawing.Color.Transparent
        Me.Boton_F01.FlatStyle = System.Windows.Forms.FlatStyle.Flat
        Me.Boton_F01.ForeColor = System.Drawing.Color.Transparent
        Me.Boton_F01.Image = Global.iROB_EA_V1_Consola.My.Resources.Resources.ic_menu_light_azul
        Me.Boton_F01.Location = New System.Drawing.Point(6, 10)
        Me.Boton_F01.Name = "Boton_F01"
        Me.Boton_F01.Size = New System.Drawing.Size(82, 84)
        Me.Boton_F01.TabIndex = 8
        Me.Boton_F01.UseVisualStyleBackColor = True
        '
        'Img_ArduinoLogo
        '
        Me.Img_ArduinoLogo.BackColor = System.Drawing.Color.Transparent
        Me.Img_ArduinoLogo.Image = Global.iROB_EA_V1_Consola.My.Resources.Resources.ArduinoLogo
        Me.Img_ArduinoLogo.Location = New System.Drawing.Point(514, 55)
        Me.Img_ArduinoLogo.Name = "Img_ArduinoLogo"
        Me.Img_ArduinoLogo.Size = New System.Drawing.Size(66, 57)
        Me.Img_ArduinoLogo.SizeMode = System.Windows.Forms.PictureBoxSizeMode.Zoom
        Me.Img_ArduinoLogo.TabIndex = 19
        Me.Img_ArduinoLogo.TabStop = False
        '
        'PanelAplicaciones
        '
        Me.PanelAplicaciones.BackColor = System.Drawing.Color.Transparent
        Me.PanelAplicaciones.BorderStyle = System.Windows.Forms.BorderStyle.FixedSingle
        Me.PanelAplicaciones.Controls.Add(Me.GroupBotones_02)
        Me.PanelAplicaciones.ForeColor = System.Drawing.Color.DimGray
        Me.PanelAplicaciones.Location = New System.Drawing.Point(370, 118)
        Me.PanelAplicaciones.Name = "PanelAplicaciones"
        Me.PanelAplicaciones.Size = New System.Drawing.Size(210, 166)
        Me.PanelAplicaciones.TabIndex = 20
        '
        'GroupBotones_02
        '
        Me.GroupBotones_02.BackColor = System.Drawing.Color.LightSteelBlue
        Me.GroupBotones_02.Font = New System.Drawing.Font("Arial", 8.25!, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, CType(0, Byte))
        Me.GroupBotones_02.ForeColor = System.Drawing.Color.DarkBlue
        Me.GroupBotones_02.Location = New System.Drawing.Point(3, 6)
        Me.GroupBotones_02.Name = "GroupBotones_02"
        Me.GroupBotones_02.Size = New System.Drawing.Size(204, 155)
        Me.GroupBotones_02.TabIndex = 5
        Me.GroupBotones_02.TabStop = False
        Me.GroupBotones_02.Text = "Aplicaciones"
        '
        'Img_Logo_01
        '
        Me.Img_Logo_01.BackColor = System.Drawing.Color.Transparent
        Me.Img_Logo_01.Image = Global.iROB_EA_V1_Consola.My.Resources.Resources.ROB_EA_logo_01
        Me.Img_Logo_01.Location = New System.Drawing.Point(370, 12)
        Me.Img_Logo_01.Name = "Img_Logo_01"
        Me.Img_Logo_01.Size = New System.Drawing.Size(210, 37)
        Me.Img_Logo_01.SizeMode = System.Windows.Forms.PictureBoxSizeMode.StretchImage
        Me.Img_Logo_01.TabIndex = 21
        Me.Img_Logo_01.TabStop = False
        '
        'Img_logo_02
        '
        Me.Img_logo_02.BackColor = System.Drawing.Color.Transparent
        Me.Img_logo_02.Image = Global.iROB_EA_V1_Consola.My.Resources.Resources.ROB_EA_Version_01
        Me.Img_logo_02.Location = New System.Drawing.Point(370, 55)
        Me.Img_logo_02.Name = "Img_logo_02"
        Me.Img_logo_02.Size = New System.Drawing.Size(138, 26)
        Me.Img_logo_02.SizeMode = System.Windows.Forms.PictureBoxSizeMode.StretchImage
        Me.Img_logo_02.TabIndex = 22
        Me.Img_logo_02.TabStop = False
        '
        'Grupo_Video
        '
        Me.Grupo_Video.BackColor = System.Drawing.Color.LightSteelBlue
        Me.Grupo_Video.Controls.Add(Me.lstDevices)
        Me.Grupo_Video.Controls.Add(Me.btnInfo)
        Me.Grupo_Video.Controls.Add(Me.picCapture)
        Me.Grupo_Video.Controls.Add(Me.btnStop)
        Me.Grupo_Video.Controls.Add(Me.btnSave)
        Me.Grupo_Video.Controls.Add(Me.btnStart)
        Me.Grupo_Video.Font = New System.Drawing.Font("Arial", 9.75!, System.Drawing.FontStyle.Bold)
        Me.Grupo_Video.ForeColor = System.Drawing.Color.DarkBlue
        Me.Grupo_Video.Location = New System.Drawing.Point(586, 4)
        Me.Grupo_Video.Name = "Grupo_Video"
        Me.Grupo_Video.Size = New System.Drawing.Size(423, 310)
        Me.Grupo_Video.TabIndex = 23
        Me.Grupo_Video.TabStop = False
        Me.Grupo_Video.Text = "Vídeo"
        '
        'lstDevices
        '
        Me.lstDevices.BackColor = System.Drawing.Color.SlateGray
        Me.lstDevices.BorderStyle = System.Windows.Forms.BorderStyle.FixedSingle
        Me.lstDevices.Font = New System.Drawing.Font("Arial", 8.25!, System.Drawing.FontStyle.Bold)
        Me.lstDevices.ForeColor = System.Drawing.Color.Navy
        Me.lstDevices.FormattingEnabled = True
        Me.lstDevices.ItemHeight = 14
        Me.lstDevices.Location = New System.Drawing.Point(89, 273)
        Me.lstDevices.Name = "lstDevices"
        Me.lstDevices.Size = New System.Drawing.Size(323, 30)
        Me.lstDevices.TabIndex = 11
        '
        'btnInfo
        '
        Me.btnInfo.BackColor = System.Drawing.Color.SlateGray
        Me.btnInfo.ForeColor = System.Drawing.Color.White
        Me.btnInfo.Location = New System.Drawing.Point(14, 106)
        Me.btnInfo.Name = "btnInfo"
        Me.btnInfo.Size = New System.Drawing.Size(70, 34)
        Me.btnInfo.TabIndex = 10
        Me.btnInfo.Text = "INFO"
        Me.btnInfo.UseVisualStyleBackColor = False
        '
        'picCapture
        '
        Me.picCapture.BorderStyle = System.Windows.Forms.BorderStyle.FixedSingle
        Me.picCapture.Location = New System.Drawing.Point(90, 27)
        Me.picCapture.Name = "picCapture"
        Me.picCapture.Size = New System.Drawing.Size(320, 240)
        Me.picCapture.TabIndex = 9
        Me.picCapture.TabStop = False
        '
        'btnStop
        '
        Me.btnStop.BackColor = System.Drawing.Color.SlateGray
        Me.btnStop.ForeColor = System.Drawing.Color.White
        Me.btnStop.Location = New System.Drawing.Point(13, 146)
        Me.btnStop.Name = "btnStop"
        Me.btnStop.Size = New System.Drawing.Size(71, 34)
        Me.btnStop.TabIndex = 8
        Me.btnStop.Text = "STOP"
        Me.btnStop.UseVisualStyleBackColor = False
        '
        'btnSave
        '
        Me.btnSave.BackColor = System.Drawing.Color.SlateGray
        Me.btnSave.ForeColor = System.Drawing.Color.White
        Me.btnSave.Location = New System.Drawing.Point(14, 67)
        Me.btnSave.Name = "btnSave"
        Me.btnSave.Size = New System.Drawing.Size(70, 33)
        Me.btnSave.TabIndex = 7
        Me.btnSave.Text = "SAVE"
        Me.btnSave.UseVisualStyleBackColor = False
        '
        'btnStart
        '
        Me.btnStart.BackColor = System.Drawing.Color.SlateGray
        Me.btnStart.ForeColor = System.Drawing.Color.White
        Me.btnStart.Location = New System.Drawing.Point(14, 28)
        Me.btnStart.Name = "btnStart"
        Me.btnStart.Size = New System.Drawing.Size(70, 33)
        Me.btnStart.TabIndex = 6
        Me.btnStart.Text = "START"
        Me.btnStart.UseVisualStyleBackColor = False
        '
        'CampoNivelXBEE_02
        '
        Me.CampoNivelXBEE_02.BackColor = System.Drawing.Color.SlateGray
        Me.CampoNivelXBEE_02.BorderStyle = System.Windows.Forms.BorderStyle.None
        Me.CampoNivelXBEE_02.Font = New System.Drawing.Font("Arial", 8.25!, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, CType(0, Byte))
        Me.CampoNivelXBEE_02.ForeColor = System.Drawing.Color.White
        Me.CampoNivelXBEE_02.Location = New System.Drawing.Point(156, 177)
        Me.CampoNivelXBEE_02.Multiline = True
        Me.CampoNivelXBEE_02.Name = "CampoNivelXBEE_02"
        Me.CampoNivelXBEE_02.ReadOnly = True
        Me.CampoNivelXBEE_02.Size = New System.Drawing.Size(175, 22)
        Me.CampoNivelXBEE_02.TabIndex = 48
        Me.CampoNivelXBEE_02.TextAlign = System.Windows.Forms.HorizontalAlignment.Center
        '
        'FormPrincipal
        '
        Me.AutoScaleDimensions = New System.Drawing.SizeF(6.0!, 13.0!)
        Me.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font
        Me.BackColor = System.Drawing.Color.Gainsboro
        Me.BackgroundImage = Global.iROB_EA_V1_Consola.My.Resources.Resources.fondo_03
        Me.BackgroundImageLayout = System.Windows.Forms.ImageLayout.None
        Me.ClientSize = New System.Drawing.Size(1018, 655)
        Me.Controls.Add(Me.Grupo_Video)
        Me.Controls.Add(Me.Img_logo_02)
        Me.Controls.Add(Me.Img_Logo_01)
        Me.Controls.Add(Me.PanelAplicaciones)
        Me.Controls.Add(Me.Img_ArduinoLogo)
        Me.Controls.Add(Me.PanelBotones)
        Me.Controls.Add(Me.GrupoPSerie)
        Me.Controls.Add(Me.Grupo_TXRX)
        Me.Controls.Add(Me.PanelTelemetria)
        Me.Controls.Add(Me.PanelPSerie)
        Me.FormBorderStyle = System.Windows.Forms.FormBorderStyle.FixedSingle
        Me.Icon = CType(resources.GetObject("$this.Icon"), System.Drawing.Icon)
        Me.KeyPreview = True
        Me.MaximizeBox = False
        Me.Name = "FormPrincipal"
        Me.StartPosition = System.Windows.Forms.FormStartPosition.CenterScreen
        Me.Text = "ROB EA, Consola de Control"
        Me.GrupoPSerie.ResumeLayout(False)
        Me.GrupoPSerie.PerformLayout()
        CType(Me.Icono_TRX, System.ComponentModel.ISupportInitialize).EndInit()
        Me.Grupo_TXRX.ResumeLayout(False)
        Me.Grupo_TXRX.PerformLayout()
        Me.PanelTelemetria.ResumeLayout(False)
        Me.GrupoTelemetria_1.ResumeLayout(False)
        Me.GrupoTelemetria_1.PerformLayout()
        CType(Me.CampoImgBateria_01, System.ComponentModel.ISupportInitialize).EndInit()
        CType(Me.CampoImgBateria_00, System.ComponentModel.ISupportInitialize).EndInit()
        CType(Me.CampoImgBateria_03, System.ComponentModel.ISupportInitialize).EndInit()
        CType(Me.CampoImgBateria_02, System.ComponentModel.ISupportInitialize).EndInit()
        CType(Me.CampoImgBateria_04, System.ComponentModel.ISupportInitialize).EndInit()
        CType(Me.CampoImgBateria_05, System.ComponentModel.ISupportInitialize).EndInit()
        CType(Me.ImgInclinacion, System.ComponentModel.ISupportInitialize).EndInit()
        Me.PanelBotones.ResumeLayout(False)
        Me.GrupoBotones_01.ResumeLayout(False)
        CType(Me.TrackBar_Ver, System.ComponentModel.ISupportInitialize).EndInit()
        CType(Me.TrackBar_Hor, System.ComponentModel.ISupportInitialize).EndInit()
        CType(Me.Img_ArduinoLogo, System.ComponentModel.ISupportInitialize).EndInit()
        Me.PanelAplicaciones.ResumeLayout(False)
        CType(Me.Img_Logo_01, System.ComponentModel.ISupportInitialize).EndInit()
        CType(Me.Img_logo_02, System.ComponentModel.ISupportInitialize).EndInit()
        Me.Grupo_Video.ResumeLayout(False)
        CType(Me.picCapture, System.ComponentModel.ISupportInitialize).EndInit()
        Me.ResumeLayout(False)

    End Sub
    Friend WithEvents SerialPort_01 As System.IO.Ports.SerialPort
    Friend WithEvents BotonSelPuerto As System.Windows.Forms.Button
    Friend WithEvents CampoListaPuertos As System.Windows.Forms.ComboBox
    Friend WithEvents GrupoPSerie As System.Windows.Forms.GroupBox
    Friend WithEvents Campo_Lst_RX As System.Windows.Forms.TextBox
    Friend WithEvents Campo_TX As System.Windows.Forms.TextBox
    Friend WithEvents Boton_TX As System.Windows.Forms.Button
    Friend WithEvents Grupo_TXRX As System.Windows.Forms.GroupBox
    Friend WithEvents Texto_TX As System.Windows.Forms.Label
    Friend WithEvents Texto_RX As System.Windows.Forms.Label
    Friend WithEvents Campo_Act_RX As System.Windows.Forms.TextBox
    Friend WithEvents Boton_Cls_RX As System.Windows.Forms.Button
    Friend WithEvents Texto_Info_TX As System.Windows.Forms.Label
    Friend WithEvents Icono_TRX As System.Windows.Forms.PictureBox
    Friend WithEvents Texto_TRX As System.Windows.Forms.Label
    Friend WithEvents PanelTelemetria As System.Windows.Forms.Panel
    Friend WithEvents PanelPSerie As System.Windows.Forms.Panel
    Friend WithEvents CampoListaFamilias As System.Windows.Forms.ComboBox
    Friend WithEvents CampoListaComandos As System.Windows.Forms.ComboBox
    Friend WithEvents CampoListaComandosDesc As System.Windows.Forms.TextBox
    Friend WithEvents Boton_AutoEnvio As System.Windows.Forms.Button
    Friend WithEvents PanelBotones As System.Windows.Forms.Panel
    Friend WithEvents GrupoTelemetria_1 As System.Windows.Forms.GroupBox
    Friend WithEvents TextoTemperatura_02 As System.Windows.Forms.Label
    Friend WithEvents CampoTemperatura As System.Windows.Forms.TextBox
    Friend WithEvents TextoTemperatura As System.Windows.Forms.Label
    Friend WithEvents CampoBrujula_01 As System.Windows.Forms.TextBox
    Friend WithEvents TextoInclinacion As System.Windows.Forms.Label
    Friend WithEvents TextoBrujula As System.Windows.Forms.Label
    Friend WithEvents GrupoBotones_01 As System.Windows.Forms.GroupBox
    Friend WithEvents Boton_LEFT As System.Windows.Forms.Button
    Friend WithEvents Boton_RIGHT As System.Windows.Forms.Button
    Friend WithEvents Boton_DOWN As System.Windows.Forms.Button
    Friend WithEvents Boton_UP As System.Windows.Forms.Button
    Friend WithEvents Boton_F04 As System.Windows.Forms.Button
    Friend WithEvents Boton_F03 As System.Windows.Forms.Button
    Friend WithEvents Boton_F02 As System.Windows.Forms.Button
    Friend WithEvents Boton_F01 As System.Windows.Forms.Button
    Friend WithEvents Boton_F05 As System.Windows.Forms.Button
    Friend WithEvents Boton_F08 As System.Windows.Forms.Button
    Friend WithEvents Boton_F09 As System.Windows.Forms.Button
    Friend WithEvents Boton_F07 As System.Windows.Forms.Button
    Friend WithEvents Boton_F06 As System.Windows.Forms.Button
    Friend WithEvents Boton_STOP As System.Windows.Forms.Button
    Friend WithEvents TextoHumedad_02 As System.Windows.Forms.Label
    Friend WithEvents CampoHumedad As System.Windows.Forms.TextBox
    Friend WithEvents TextoHumedad As System.Windows.Forms.Label
    Friend WithEvents Img_ArduinoLogo As System.Windows.Forms.PictureBox
    Friend WithEvents PanelAplicaciones As System.Windows.Forms.Panel
    Friend WithEvents GroupBotones_02 As System.Windows.Forms.GroupBox
    Friend WithEvents ToolTip_01 As System.Windows.Forms.ToolTip
    Friend WithEvents CampoBrujula_02 As System.Windows.Forms.TextBox
    Friend WithEvents CampoInclinacion As System.Windows.Forms.TextBox
    Friend WithEvents CampoDistancia_PING As System.Windows.Forms.TextBox
    Friend WithEvents TextoDistancia_PING As System.Windows.Forms.Label
    Friend WithEvents Texto_F01 As System.Windows.Forms.Label
    Friend WithEvents Texto_F04 As System.Windows.Forms.Label
    Friend WithEvents Texto_F03 As System.Windows.Forms.Label
    Friend WithEvents Texto_F02 As System.Windows.Forms.Label
    Friend WithEvents texto_F06 As System.Windows.Forms.Label
    Friend WithEvents Texto_F05 As System.Windows.Forms.Label
    Friend WithEvents Texto_F09 As System.Windows.Forms.Label
    Friend WithEvents Texto_F08 As System.Windows.Forms.Label
    Friend WithEvents Texto_F07 As System.Windows.Forms.Label
    Friend WithEvents ImgInclinacion As System.Windows.Forms.PictureBox
    Friend WithEvents Img_Logo_01 As System.Windows.Forms.PictureBox
    Friend WithEvents Img_logo_02 As System.Windows.Forms.PictureBox
    Friend WithEvents TrackBar_Hor As System.Windows.Forms.TrackBar
    Friend WithEvents TrackBar_HorInfo As System.Windows.Forms.Label
    Friend WithEvents Grupo_Video As System.Windows.Forms.GroupBox
    Friend WithEvents lstDevices As System.Windows.Forms.ListBox
    Friend WithEvents btnInfo As System.Windows.Forms.Button
    Friend WithEvents picCapture As System.Windows.Forms.PictureBox
    Friend WithEvents btnStop As System.Windows.Forms.Button
    Friend WithEvents btnSave As System.Windows.Forms.Button
    Friend WithEvents btnStart As System.Windows.Forms.Button
    Friend WithEvents sfdImage As System.Windows.Forms.SaveFileDialog
    Friend WithEvents TrackBar_Ver As System.Windows.Forms.TrackBar
    Friend WithEvents TrackBar_VerInfo As System.Windows.Forms.Label
    Friend WithEvents BotonScanPuerto As System.Windows.Forms.Button
    Friend WithEvents TextoNivelBateria As System.Windows.Forms.Label
    Friend WithEvents CampoNivelBateria As System.Windows.Forms.TextBox
    Friend WithEvents TextoNivelXBEE As System.Windows.Forms.Label
    Friend WithEvents CampoNivelXBEE_01 As System.Windows.Forms.TextBox
    Friend WithEvents TextoDistancia_PING_02 As System.Windows.Forms.Label
    Friend WithEvents CampoImgBateria_00 As System.Windows.Forms.PictureBox
    Friend WithEvents TextoNivelBateria_02 As System.Windows.Forms.Label
    Friend WithEvents CampoImgBateria_03 As System.Windows.Forms.PictureBox
    Friend WithEvents CampoImgBateria_02 As System.Windows.Forms.PictureBox
    Friend WithEvents CampoImgBateria_04 As System.Windows.Forms.PictureBox
    Friend WithEvents CampoImgBateria_05 As System.Windows.Forms.PictureBox
    Friend WithEvents CampoImgBateria_01 As System.Windows.Forms.PictureBox
    Friend WithEvents Boton_F10 As System.Windows.Forms.Button
    Friend WithEvents Texto_F10 As System.Windows.Forms.Label
    Friend WithEvents CampoNivelXBEE_02 As System.Windows.Forms.TextBox

End Class
