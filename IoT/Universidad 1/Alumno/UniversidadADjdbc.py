
import mysql.connector                    # import A correcta
# from mysql.connector import (connection)  # import B correcta

from AlumnoDP import AlumnoDP

class UniversidadADjdbc:
#-------------------------------#    
    def capturar(self, datos):
        resultado=""
        
        try:
            # 1. Abrir el archivo Clientes.txt
            # archivoOut = open("Clientes.txt", "a")
            conexion = mysql.connector.connect(user='root', database='Universidad')
            print("Conexion exitosa con la BD Universidad...\n")
            
            # Preparar el string insertCliente con el comando SQL INSERT
            alumnodp = AlumnoDP(datos)
            
            insertAlumno = "INSERT INTO Alumno VALUES("+alumnodp.toStringSql()+")"
            
            # 2. Almacenar los datos en el archivo
            # archivoOut.write(datos+"\n")
            statement = conexion.cursor()
            statement.execute(insertAlumno)
            conexion.commit()
            
            # 3. Cerrar el archivo
            # archivoOut.close()
            statement.close()
            conexion.close()
            
            resultado = "Datos capturados: "+datos
            print(insertAlumno+"\n")
        except:
            resultado = "Error en la Captura de Datos del Alumno..."
        
        return resultado

#-------------------------------#
    def consultar(self):
        # 1. Abrir el archivo para leer
        # archivoIn = open("Clientes.txt","r")
        conexion = mysql.connector.connect(user='root',database='Universidad')
        
        # Preparar el query a la BD y ejecutarlo
        query = "SELECT * FROM Alumno"
        # query = "SELECT nocta, nombre, tipo, saldo FROM Cliente"
        statement = conexion.cursor()
        statement.execute(query)
        
        # Procesar los datos de la tabla resultante
        datos=""
        alumnodp = AlumnoDP(datos)
        tupla = statement.fetchone()
        # while tupla is not None:
        while(tupla != None):
            alumnodp.setMatricula(tupla[0])
            alumnodp.setNombre(tupla[1])
            alumnodp.setCarrera(tupla[2])
            alumnodp.setPlan(tupla[3])
            alumnodp.setDireccion(tupla[4])
            alumnodp.setTelefono(tupla[5])
            
            datos = datos + alumnodp.toString() + "\n"
            # print(tupla)
            tupla = statement.fetchone()
        
        # 3. Cerrar el archivo
        # archivoIn.close()
        statement.close()
        conexion.close
        
        print(query+"\n")
        
        return datos

#-------------------------------#
    def consultarMatricula(self,matricula):
        # 1. Abrir el archivo
        #archivoIn = open("Clientes.txt","r")
        conexion = mysql.connector.connect(user="root", database="Universidad")
        
        # Preparar query y ejecutarlo
        query = "SELECT * FROM Alumno WHERE matricula='"+matricula+"'"
        statement = conexion.cursor()
        statement.execute(query)
        
        # 2. Procesar datos del archivo
        datos = ""
        encontrado = False
        
        # cliente = archivoIn.readline()
        alumnodp = AlumnoDP(datos)
        tupla = statement.fetchone()
        # while cliente != "":
        while(tupla != None):
            alumnodp.setMatricula(tupla[0])
            alumnodp.setNombre(tupla[1])
            alumnodp.setCarrera(tupla[2])
            alumnodp.setPlan(tupla[3])
            alumnodp.setDireccion(tupla[4])
            alumnodp.setTelefono(tupla[5])
            
            datos = datos + alumnodp.toString() + "\n"
            encontrado = True
        
            # cliente = archivoIn.readline()
            tupla = statement.fetchone()
        
        # 3. Cerrar el archivo
        # archivoIn.close
        statement.close()
        conexion.close()
        
        print(query)
        
        #if encontrado == False:
        if (not encontrado):
            datos = "No se localizo la matrícula "+matricula

        return datos
#-------------------------------#
    def consultarCar(self,carrera):
        # 1. Abrir el archivo
        # archivoIn = open("Clientes.txt","r")
        conexion = mysql.connector.connect(user="root", database="Universidad")
        
        # Preparar query y ejecutarlo
        query = "SELECT * FROM Alumno WHERE carrera='"+carrera+"'"
        statement = conexion.cursor()
        statement.execute(query)
        
        # 2. Procesar datos del archivo
        datos = ""
        encontrado = False
       
        # cliente = archivoIn.readline()
        alumnodp = AlumnoDP(datos)
        tupla = statement.fetchone()
        # while (cliente != "" and not encontrado):
        if(tupla is not None):
        #if (tupla != None):
            while (tupla != None):
                # st = cliente.split("_")
                alumnodp.setMatricula(tupla[0])
                alumnodp.setNombre(tupla[1])
                alumnodp.setCarrera(tupla[2])
                alumnodp.setPlan(tupla[3])
                alumnodp.setDireccion(tupla[4])
                alumnodp.setTelefono(tupla[5])
                
                datos = datos + alumnodp.toString() + "\n"
                encontrado = True
                
                # cliente = archivoIn.readline()
                tupla = statement.fetchone()
        
        # 3. Cerrar el archivo
        # archivoIn.close
        statement.close()
        conexion.close()
        
        print(query)
        
        #if encontrado == False:
        if (not encontrado):
            datos = "No se localizaron alumnos en "+carrera
        
        return datos

#-------------------------------#
