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
        Me.Grp_Controles_1 = New System.Windows.Forms.GroupBox
        Me.SerialPort_Cnx = New System.IO.Ports.SerialPort(Me.components)
        Me.C_Log = New System.Windows.Forms.TextBox
        Me.Grp_Controles_2 = New System.Windows.Forms.GroupBox
        Me.Grp_Video = New System.Windows.Forms.GroupBox
        Me.SuspendLayout()
        '
        'Grp_Controles_1
        '
        Me.Grp_Controles_1.BackColor = System.Drawing.Color.Teal
        Me.Grp_Controles_1.Font = New System.Drawing.Font("Arial", 9.0!, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, CType(0, Byte))
        Me.Grp_Controles_1.ForeColor = System.Drawing.Color.White
        Me.Grp_Controles_1.Location = New System.Drawing.Point(5, 10)
        Me.Grp_Controles_1.Name = "Grp_Controles_1"
        Me.Grp_Controles_1.Size = New System.Drawing.Size(170, 620)
        Me.Grp_Controles_1.TabIndex = 0
        Me.Grp_Controles_1.TabStop = False
        '
        'C_Log
        '
        Me.C_Log.BackColor = System.Drawing.Color.Teal
        Me.C_Log.Font = New System.Drawing.Font("Arial", 8.25!, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, CType(0, Byte))
        Me.C_Log.ForeColor = System.Drawing.Color.MediumTurquoise
        Me.C_Log.Location = New System.Drawing.Point(185, 505)
        Me.C_Log.Multiline = True
        Me.C_Log.Name = "C_Log"
        Me.C_Log.ReadOnly = True
        Me.C_Log.ScrollBars = System.Windows.Forms.ScrollBars.Vertical
        Me.C_Log.Size = New System.Drawing.Size(650, 125)
        Me.C_Log.TabIndex = 1
        '
        'Grp_Controles_2
        '
        Me.Grp_Controles_2.BackColor = System.Drawing.Color.Teal
        Me.Grp_Controles_2.Font = New System.Drawing.Font("Arial", 9.0!, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, CType(0, Byte))
        Me.Grp_Controles_2.ForeColor = System.Drawing.Color.White
        Me.Grp_Controles_2.Location = New System.Drawing.Point(840, 10)
        Me.Grp_Controles_2.Name = "Grp_Controles_2"
        Me.Grp_Controles_2.Size = New System.Drawing.Size(170, 620)
        Me.Grp_Controles_2.TabIndex = 5
        Me.Grp_Controles_2.TabStop = False
        '
        'Grp_Video
        '
        Me.Grp_Video.BackColor = System.Drawing.Color.Teal
        Me.Grp_Video.Font = New System.Drawing.Font("Arial", 9.0!, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, CType(0, Byte))
        Me.Grp_Video.ForeColor = System.Drawing.Color.White
        Me.Grp_Video.Location = New System.Drawing.Point(185, 10)
        Me.Grp_Video.Name = "Grp_Video"
        Me.Grp_Video.Size = New System.Drawing.Size(650, 490)
        Me.Grp_Video.TabIndex = 6
        Me.Grp_Video.TabStop = False
        '
        'FormPrincipal
        '
        Me.AutoScaleDimensions = New System.Drawing.SizeF(6.0!, 13.0!)
        Me.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font
        Me.BackColor = System.Drawing.Color.DarkSlateGray
        Me.ClientSize = New System.Drawing.Size(1018, 740)
        Me.Controls.Add(Me.Grp_Video)
        Me.Controls.Add(Me.Grp_Controles_2)
        Me.Controls.Add(Me.C_Log)
        Me.Controls.Add(Me.Grp_Controles_1)
        Me.FormBorderStyle = System.Windows.Forms.FormBorderStyle.FixedSingle
        Me.MaximizeBox = False
        Me.Name = "FormPrincipal"
        Me.StartPosition = System.Windows.Forms.FormStartPosition.CenterScreen
        Me.Text = "iROB EA"
        Me.ResumeLayout(False)
        Me.PerformLayout()

    End Sub
    Friend WithEvents Grp_Controles_1 As System.Windows.Forms.GroupBox
    Friend WithEvents SerialPort_Cnx As System.IO.Ports.SerialPort
    Friend WithEvents C_Log As System.Windows.Forms.TextBox
    Friend WithEvents Grp_Controles_2 As System.Windows.Forms.GroupBox
    Friend WithEvents Grp_Video As System.Windows.Forms.GroupBox

End Class
