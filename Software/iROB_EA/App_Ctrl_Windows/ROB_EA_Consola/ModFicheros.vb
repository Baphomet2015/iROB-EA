Module ModFicheros


    Public Function FN_TestFichero(ByVal nombFichero As String) As Integer
        ' -------------------------------------------------- '
        ' Esta  funcion  comprueba si  el  fichero  indicado '
        ' existe.                                            '
        ' Retorna:                                           '
        ' . True  Si, el fichero existe.                     '
        ' . False No, no existe.                             '
        ' -------------------------------------------------- '
        Dim resultado As Integer
        Dim datos As Integer


        Try
            datos = GetAttr(nombFichero)
            resultado = True

        Catch ex As Exception
            resultado = False
        End Try

        FN_TestFichero = resultado

    End Function

    Public Function FN_TestDirectorio(ByVal directorio As String) As Integer
        ' -------------------------------------------------- '
        ' Esta  funcion  comprueba si el directorio indicado '
        ' existe.                                            '
        ' Retorna:                                           '
        ' . True  Si, es un directorio válido                '
        ' . False No, no es válido                           '
        ' -------------------------------------------------- '
        Dim resultado As Integer


        Try
            ChDir(directorio)
            resultado = True
        Catch ex As Exception
            resultado = False
        End Try

        FN_TestDirectorio = resultado

    End Function

    Public Function FN_DeleteFichero(ByVal nombFichero As String) As Integer
        ' -------------------------------------------------- '
        ' Esta  funcion  borra el fichero que se indica.     '
        ' Retorna:                                           '
        ' . True  Si, se eliminó el fichero                  '
        ' . False No, no se eliminó el fichero               '
        ' -------------------------------------------------- '
        Dim resultado As Integer


        Try
            Kill(nombFichero)
            resultado = True
        Catch ex As Exception
            resultado = False
        End Try

        FN_DeleteFichero = resultado

    End Function

    Public Function FN_CrearDirectorio(ByVal directorio As String) As Integer
        ' -------------------------------------------------- '
        ' Esta  funcion  crea el directorio indicado         '
        ' existe.                                            '
        ' Retorna:                                           '
        ' . True  Todo Bien                                  '
        ' . False Todo Mal                                   '
        ' -------------------------------------------------- '
        Dim resultado As Integer


        Try
            MkDir(directorio)
            resultado = True
        Catch ex As Exception
            resultado = False
        End Try

        FN_CrearDirectorio = resultado

    End Function

    Public Function FN_CopiarFichero(ByVal ficheroOrg As String, ByVal ficheroRes As String, ByVal modo As Integer) As Integer
        ' ---------------------------------------- '
        ' Copia un fichero en otro                 '
        ' Retorna:                                 '
        ' . True  Si todo bien                     '
        ' . false Si todo mal                      '
        ' ---------------------------------------- '
        Dim resultado As Integer
        Dim fs


        Try
            fs = CreateObject("Scripting.FileSystemObject")
            fs.copyfile(ficheroOrg, ficheroRes, modo)
            resultado = True
        Catch ex As Exception
            resultado = False
        End Try

        fs = Nothing

        FN_CopiarFichero = resultado

    End Function

End Module