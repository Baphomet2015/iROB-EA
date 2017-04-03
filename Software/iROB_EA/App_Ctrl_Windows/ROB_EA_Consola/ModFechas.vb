Module ModFechas
   

    ' -----------------------------------------------
    '
    ' FN_GetSFechaActual()
    ' Retorna la fecha actual en formato DD/MM/YYYY
    '
    '       fecha actual --> DD/MM/YYYY ( string )
    '
    ' -----------------------------------------------

    Public Function FN_GetSFechaActual() As String

        Dim sFecha As String
        Dim dFecha As Date


        dFecha = Now

        sFecha = FN_CnvDateStrFecha(dFecha)

        FN_GetSFechaActual = sFecha

    End Function

    ' -----------------------------------------------
    '
    ' FN_GetNFechaActual()
    ' Retorna la fecha actual en formato YYYYMMDD
    '
    '       fecha actual --> YYYYMMDD ( long )
    '
    ' -----------------------------------------------

    Public Function FN_GetNFechaActual() As String

        Dim nFecha As Long
        Dim dFecha As Date

        dFecha = Now

        nFecha = FN_CnvDateCodFecha(dFecha)

        FN_GetNFechaActual = nFecha

    End Function

    ' -----------------------------------------------
    '
    ' FN_CnvDateStrFecha(strFecha)
    ' Recibe  un  tipo date y retorna un string con
    ' la fecha que representa en formato "dd/mm/yyyy"
    '
    '            "dd/mm/yyyy" --> YYYYMMDD
    '
    ' -----------------------------------------------

    Public Function FN_CnvDateStrFecha(ByVal fOrg As Date) As String

        Dim fRes As String


        fRes = ""
        fRes = fRes & Format$(fOrg, "dd")
        fRes = fRes & "/" & Format$(fOrg, "mm")
        fRes = fRes & "/" & Format$(fOrg, "yyyy")

        FN_CnvDateStrFecha = fRes

    End Function


    ' -----------------------------------------------
    '
    ' FN_CnvStrFechaCodFecha(strFecha)
    ' Recibe  un  string  que   representa  una fecha
    ' según  el  formato  definido  por   la  función
    ' FN_CnvDateStrFecha   y  retorna   un  long  que
    ' representa dicha fecha.
    '
    '            "dd/mm/yyyy" --> YYYYMMDD
    '
    ' -----------------------------------------------

    Public Function FN_CnvStrFechaCodFecha(ByVal strFecha As String) As Long

        Dim fRes As String


        strFecha = Trim$(strFecha)
        fRes = ""
        fRes = fRes & Mid$(strFecha, 7, 4)
        fRes = fRes & Mid$(strFecha, 4, 2)
        fRes = fRes & Mid$(strFecha, 1, 2)

        FN_CnvStrFechaCodFecha = CLng(fRes)

    End Function


    ' -----------------------------------------------
    '
    ' FN_CnvCodFechaStrFecha(codFecha)
    ' Recibe una fecha en el formato oficial y retorna
    ' un string que representa dicha fecha.
    '
    '         YYYYMMDD --> "dd/mm/yyyy"
    '
    ' -----------------------------------------------

    Public Function FN_CnvCodFechaStrFecha(ByVal codFecha As Long) As String

        Dim fRes As String
        Dim fOrg As String


        fOrg = CStr(codFecha)
        fRes = ""
        fRes = fRes & Mid$(fOrg, 7, 2) & "/"
        fRes = fRes & Mid$(fOrg, 5, 2) & "/"
        fRes = fRes & Mid$(fOrg, 1, 4)

        FN_CnvCodFechaStrFecha = fRes

    End Function


    ' -----------------------------------------------
    '
    ' FN_CnvDateCodFecha(fOrg)
    '
    ' Recibe un  tipo  Date  y   retorna  un long que
    ' representa dicha fecha.
    '             Date --> YYYYMMDD
    '
    ' -----------------------------------------------

    Public Function FN_CnvDateCodFecha(ByVal fOrg As Date) As Long

        Dim strFecha As String
        Dim codFecha As Long


        strFecha = FN_CnvDateStrFecha(fOrg)
        codFecha = FN_CnvStrFechaCodFecha(strFecha)

        FN_CnvDateCodFecha = codFecha

    End Function


    ' -----------------------------------------------
    '
    ' FN_GetStrMes(fecha)
    ' Recibe  una  fecha  en el formato interno de la
    ' base de datos y retorna el nombre del mes.
    '
    '          YYYYMMDD --> "nombre del mes"
    '
    '
    ' -----------------------------------------------

    Public Function FN_GetStrMes(ByVal fecha As Long) As String

        Dim mes As String


        mes = ""

        Select Case (CInt(Mid$(CStr(fecha), 5, 2)))

            Case (1)
                mes = "enero"
            Case (2)
                mes = "febrero"
            Case (3)
                mes = "marzo"
            Case (4)
                mes = "abril"
            Case (5)
                mes = "mayo"
            Case (6)
                mes = "junio"
            Case (7)
                mes = "julio"
            Case (8)
                mes = "agosto"
            Case (9)
                mes = "septiembre"
            Case (10)
                mes = "octubre"
            Case (11)
                mes = "noviembre"
            Case (12)
                mes = "diciembre"
        End Select

        FN_GetStrMes = mes

    End Function


    ' -----------------------------------------------
    '
    ' FN_GetStrDia(nDia)
    ' Recibe el numero de dia y retorna el  nombre.                              '
    '
    '
    ' -----------------------------------------------

    Public Function FN_GetStrDia(ByVal nDia As Integer) As String

        Dim sDia As String


        sDia = ""

        Select Case (nDia)

            Case (1)
                sDia = "Domingo"
            Case (2)
                sDia = "Lunes"
            Case (3)
                sDia = "Martes"
            Case (4)
                sDia = "Miercoles"
            Case (5)
                sDia = "Jueves"
            Case (6)
                sDia = "Viernes"
            Case (7)
                sDia = "Sabado"
        End Select

        FN_GetStrDia = sDia

    End Function


    ' -----------------------------------------------
    '
    ' FN_GetSHoraActual()
    ' Retorna la hora actual en formato "HHMMSS"
    '
    '
    ' -----------------------------------------------

    Function FN_GetSHoraActual() As String

        Dim HCompleta
        Dim sHora
        Dim sMinutos
        Dim sSegundos
        Dim sResultado
        Dim nAux


        HCompleta = Now

        nAux = CInt(Hour(HCompleta))
        If (nAux <= 9) Then
            sHora = "0" & CStr(nAux)
        Else
            sHora = "" & CStr(nAux)
        End If

        nAux = CInt(Minute(HCompleta))
        If (nAux <= 9) Then
            sMinutos = "0" & CStr(nAux)
        Else
            sMinutos = "" & CStr(nAux)
        End If

        nAux = CInt(Second(HCompleta))
        If (nAux <= 9) Then
            sSegundos = "0" & CStr(nAux)
        Else
            sSegundos = "" & CStr(nAux)
        End If

        sResultado = "" & sHora & sMinutos & sSegundos

        FN_GetSHoraActual = sResultado

    End Function


    ' -----------------------------------------------
    '
    ' FN_GetSHoraActual_2()
    ' Retorna la hora actual en formato "HH:MM:SS"
    '
    '
    ' -----------------------------------------------

    Function FN_GetSHoraActual_2() As String

        Dim HCompleta
        Dim sHora
        Dim sMinutos
        Dim sSegundos
        Dim sResultado
        Dim nAux


        HCompleta = Now

        nAux = CInt(Hour(HCompleta))
        If (nAux <= 9) Then
            sHora = "0" & CStr(nAux)
        Else
            sHora = "" & CStr(nAux)
        End If

        nAux = CInt(Minute(HCompleta))
        If (nAux <= 9) Then
            sMinutos = "0" & CStr(nAux)
        Else
            sMinutos = "" & CStr(nAux)
        End If

        nAux = CInt(Second(HCompleta))
        If (nAux <= 9) Then
            sSegundos = "0" & CStr(nAux)
        Else
            sSegundos = "" & CStr(nAux)
        End If

        sResultado = "" & sHora & ":" & sMinutos & ":" & sSegundos

        FN_GetSHoraActual_2 = sResultado

    End Function

    ' -----------------------------------------------
    '
    ' FN_GetNHoraActual()
    ' Retorna la hora actual en formato HHMMSS
    '
    '
    ' -----------------------------------------------

    Public Function FN_GetNHoraActual() As Long

        FN_GetNHoraActual = CLng(FN_GetSHoraActual())

    End Function

    ' -----------------------------------------------
    '
    ' FN_GetValDia(codFecha)
    ' YYYYMMDD -->DD
    '
    ' -----------------------------------------------

    Public Function FN_GetValDia(ByVal codFecha As Long) As Integer

        Dim nDia As Integer
        Dim sDia As String


        sDia = CStr(codFecha)
        nDia = CInt(Mid$(sDia, 7, 2))

        FN_GetValDia = nDia

    End Function

    ' -----------------------------------------------
    '
    ' FN_GetValMes(codFecha)
    ' YYYYMMDD -->MM
    '
    ' -----------------------------------------------

    Public Function FN_GetValMes(ByVal codFecha As Long) As Integer

        Dim nMes As Integer
        Dim sMes As String


        sMes = CStr(codFecha)
        nMes = CInt(Mid$(sMes, 5, 2))

        FN_GetValMes = nMes

    End Function

    ' -----------------------------------------------
    '
    ' FN_GetValAnno(codFecha)
    ' YYYYMMDD -->YYYY
    '
    ' -----------------------------------------------

    Public Function FN_GetValAnno(ByVal codFecha As Long) As Integer

        Dim nAnno As Integer
        Dim sAnno As String


        sAnno = CStr(codFecha)
        nAnno = CInt(Mid$(sAnno, 1, 4))

        FN_GetValAnno = nAnno

    End Function

    ' -----------------------------------------------
    '
    ' FN_TestStrMes(strTest)
    ' comprueba si el string recibido es el nombre de
    ' un mes.
    ' Retorna:
    ' . True  Sí, lo es
    ' . False No, no lo es
    '
    '
    ' -----------------------------------------------

    Public Function FN_TestStrMes(ByVal strTest As String) As Integer

        Dim resultado As Integer


        resultado = False

        Select Case (Trim(LCase(strTest)))

            Case ("enero")
                resultado = True

            Case ("febrero")
                resultado = True

            Case ("marzo")
                resultado = True

            Case ("abril")
                resultado = True

            Case ("mayo")
                resultado = True

            Case ("junio")
                resultado = True

            Case ("julio")
                resultado = True

            Case ("agosto")
                resultado = True

            Case ("septiembre")
                resultado = True

            Case ("octubre")
                resultado = True

            Case ("noviembre")
                resultado = True

            Case ("diciembre")
                resultado = True
        End Select

        FN_TestStrMes = resultado

    End Function

    ' -----------------------------------------------
    ' FN_GetIdeMes(strMes)
    '
    '
    '
    '
    ' -----------------------------------------------

    Public Function FN_GetIdeMes(ByVal strMes As String) As Integer

        Dim nMes As Integer


        nMes = -1

        Select Case (Trim(LCase(strMes)))

            Case ("enero")
                nMes = 1

            Case ("febrero")
                nMes = 2

            Case ("marzo")
                nMes = 3

            Case ("abril")
                nMes = 4

            Case ("mayo")
                nMes = 5

            Case ("junio")
                nMes = 6

            Case ("julio")
                nMes = 7

            Case ("agosto")
                nMes = 8

            Case ("septiembre")
                nMes = 9

            Case ("octubre")
                nMes = 10

            Case ("noviembre")
                nMes = 11

            Case ("diciembre")
                nMes = 12
        End Select

        FN_GetIdeMes = nMes

    End Function

    ' -----------------------------------------------
    ' FN_TestFecha(fTest As Long)
    ' . True,  Si es correcta.
    ' . False, Es incorrecta
    '
    ' -----------------------------------------------

    Public Function FN_TestFecha(ByVal fTest As Long) As Integer

        Dim resultado As Integer
        Dim strFecha As String


        resultado = False

        strFecha = FN_CnvCodFechaStrFecha(fTest)
        If (IsDate(strFecha) = True) Then
            resultado = True
        End If

        FN_TestFecha = resultado

    End Function



End Module
