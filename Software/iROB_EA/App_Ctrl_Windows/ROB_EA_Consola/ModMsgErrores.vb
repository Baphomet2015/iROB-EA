Module ModMsgErrores

    Public Function MsgErr_AccDatos() As Integer

        Dim strMsg As String

        strMsg = ""
        strMsg = strMsg & "Se ha producido un error al acceder a los datos de la Aplicación."
        MsgErr_AccDatos = MsgBox(strMsg, 16, "Error accediendo a datos ")

    End Function

    Public Function MsgErr_MaxComandosRespuesta() As Integer

        Dim strMsg As String

        strMsg = ""
        strMsg = strMsg & "Hay demasiados comandos de respuesta definidos en la Base de Datos, no se reconocerán todos"
        MsgErr_MaxComandosRespuesta = MsgBox(strMsg, 16, "Error accediendo a datos ")

    End Function

    Public Function MsgErr_AccDatosEx(ByVal sMsg As String) As Integer

        Dim strMsg As String

        strMsg = ""
        strMsg = strMsg & "Excepción: " & sMsg
        MsgErr_AccDatosEx = MsgBox(strMsg, 16, "Error accediendo a datos ")

    End Function

    Public Function MsgErr_ChkFichero(ByVal sFichero As String)

        Dim strMsg As String

        strMsg = "El fichero " & vbCrLf & sFichero & vbCrLf & " no ha creado correctamente."
        MsgErr_ChkFichero = MsgBox(strMsg, 64, "Fichero error")

    End Function

    Public Function MsgErr_CargarFichero(ByVal sFichero As String) As Integer

        Dim strMsg As String

        strMsg = ""
        strMsg = strMsg & "Se ha producido un error al cargar el fichero " & vbCrLf & sFichero
        MsgErr_CargarFichero = MsgBox(strMsg, 16, "Error cargando fichero ")

    End Function

    Public Function MsgErr_Ficheros()

        Dim strMsg As String

        strMsg = "Faltan ficheros, no es posible iniciar la aplicación"
        MsgErr_Ficheros = MsgBox(strMsg, 64, "Faltan ficheros")

    End Function

    Public Function MsgErr_BBDD(ByVal sFichero As String)

        Dim strMsg As String

        strMsg = "No se encuentra la base de datos de la Aplicación " & sFichero & ", no es posible iniciar la aplicación"
        MsgErr_BBDD = MsgBox(strMsg, 64, "No se encuentra la Base de Datos")

    End Function

End Module
