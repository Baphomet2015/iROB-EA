
"""App:         PC_ON.py 
   Version:     1.0, Noviembre 2021
   Descripcion: Programa para comunicar el inicio del PC al Modulo Arduino.
                Envia al arduino a traves del puerto serie que los comunica
                el comando que indica que el PC se ha activado correctamente
                para que el modulo Arduino finalice el inicio del PC.
"""

# --------------------------------------------------
# Imports
# --------------------------------------------------
import datetime
import serial
import time
import sys
import os

# --------------------------------------------------
# Constantes del programa
# --------------------------------------------------
IDE_PUERTO_COM       = "COM3"
IDE_PUERTO_VELOCIDAD = 9600
IDE_FICHERO_LOG      = "irob-ea-log.txt"

# --------------------------------------------------
# Comandos intercambiados con Arduino, definidos en
# la documantacion de iROB-EA_VS2021, ver documento
# info_Comandos_Completos.pdf
# --------------------------------------------------

IDE_STR_CMD_PC_ON = "#####1001070000E0001"


# --------------------------------------------------
# def storeResultado(sMsg):
# --------------------------------------------------

def storeResultado(sMsg):

  sResultado     = time.strftime("%Y%m%d-%H:%M:%S -> ") + sMsg
  absFilePath    = os.path.abspath(__file__)
  path, filename = os.path.split(absFilePath)

  try:
    file = open(path + "\\" + IDE_FICHERO_LOG, "a")
    file.write(os.linesep + sResultado)
    file.close()

  except BaseException:    
     print("ERROR, no se puede acceder al fichero de LOG" + os.linesep)





# --------------------------------------------------
# 
#
#
# --------------------------------------------------

try:
    pCom = serial.Serial(IDE_PUERTO_COM,IDE_PUERTO_VELOCIDAD) # Abre el puerto serie indicado
    time.sleep(2)                                             # Espera 2 segundos para que se estabilice 
    pCom.write(IDE_STR_CMD_PC_ON.encode())                    # Envia el string de comando
    time.sleep(5)                                             # Espera 5 segundo las respuesta

    buffRX = []                                               # Recupera la respuesta
    
    while pCom.inWaiting():
          for c in pCom.read():
            buffRX.append(chr(c)) 
                        
    pCom.close()                                              # Cierra el puerto serie
    
    if len(buffRX)==len(IDE_STR_CMD_PC_ON)+1:
      # --------------------------------------
      # Recoge el ultimo caracter recibido que
      # sera el resultado de la ejecucion  del
      # comando   
      # --------------------------------------
      c = buffRX[-1]                                                             
      
      if ( c=='1'):
         sMsg = "Comando ejecutado correctamente"
      else:
         sMsg = "Comando NO ejecutado"

    else:
      sMsg = "Respuesta recibida incorrecta o nula"


except serial.SerialException as e:
    sMsg = "NO se ha podido acceder al puerto " + IDE_PUERTO_COM


storeResultado(sMsg)
sys.exit()



