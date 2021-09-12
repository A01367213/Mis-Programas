#from Tkinter import *   # Package de Python 2.7
from tkinter import *    # Package de Python 3.7

#from BancoAD import BancoAD
from UniversidadADjdbc import UniversidadADjdbc

class AlumnoGUI2:
    frame = Tk()
    
    #banco = BancoAD()
    universidad = UniversidadADjdbc()
    
    # Constructor
    def __init__(self):
        # 1. Definicion y creacion del objeto frame (Tk) (JFrame)
        #self.frame = Tk()
        self.frame.title("Gestor de Alumnos")
        self.frame.geometry("600x400")

        # 2. Definicion y creacion de los atributos del frame
        self.lbMatricula  = Label(self.frame, text="MATRICULA:")
        self.tfMatricula  = Entry(self.frame, width=20)
        
        self.lbNombre     = Label(self.frame, text="NOMBRE")
        self.tfNombre     = Entry(self.frame, width=20)
        
        self.lbCarrera    = Label(self.frame, text="CARRERA:")
        self.tfCarrera    = Entry(self.frame, width=20);
        
        self.lbPlan       = Label(self.frame, text="PLAN:")
        self.tfPlan       = Entry(self.frame, width=20)

        self.lbDireccion  = Label(self.frame, text="DIRECCIÓN:")
        self.tfDireccion  = Entry(self.frame, width=20)

        self.lbTelefono   = Label(self.frame, text="TELÉFONO:")
        self.tfTelefono   = Entry(self.frame, width=20)
        
        self.bCapturar    = Button(self.frame, text="Capturar Alumno",command=self.bCapturarEvent)
        self.bConsultar   = Button(self.frame, text="Consultar Alumnos",command=self.bConsultarEvent)
        self.bConsultarM = Button(self.frame, text="Consultar Matrícula",command=self.bConsultarMEvent)
        self.bConsultarC = Button(self.frame, text="Consultar Carrera",command=self.bConsultarCEvent)
   
        self.taDatos      = Text(self.frame, width=40, height=10)        
        
        # 3. Colocar los objetos de los atributos en un Layout
        self.lbMatricula.grid(row=0, column=0)
        self.tfMatricula.grid(row=0, column=1)
        
        self.lbNombre.grid(row=1, column=0)
        self.tfNombre.grid(row=1, column=1)
        
        self.lbCarrera.grid(row=2, column=0)
        self.tfCarrera.grid(row=2, column=1)
        
        self.lbPlan.grid(row=3, column=0)
        self.tfPlan.grid(row=3, column=1)

        self.lbDireccion.grid(row=4, column=0)
        self.tfDireccion.grid(row=4, column=1)

        self.lbTelefono.grid(row=5, column=0)
        self.tfTelefono.grid(row=5, column=1)

        
        self.bCapturar.grid(row=6, column=0)
        self.bConsultar.grid(row=6, column=1)
        self.bConsultarM.grid(row=7, column=0)
        self.bConsultarC.grid(row=7, column=1)
        self.taDatos.grid(row=8, column=0)

        # Hacer visible al frame
        self.frame.mainloop()
    
    # Metodos de la class ClienteGUI
    def obtenerDatos(self):
        mat  = self.tfMatricula.get()
        nom  = self.tfNombre.get()
        car = self.tfCarrera.get()
        pln = self.tfPlan.get()
        drx = self.tfDireccion.get()
        tel = self.tfTelefono.get()
        
        if mat == "" or nom == "" or car == "" or pln == "" or drx == "" or tel == "":
            datos = "VACIO"
        else:
            #try:
                #valor = float(saldo)
                #datos = cve+'_'+nom+'_'+tipo+'_'+saldo # Concatenacion correcta
            datos = mat+"_"+nom+"_"+car+"_"+pln+"_"+drx+"_"+tel
            #print(datos)# Concatenacion correcta
            #except:
                #datos = "NO_NUMERICO"
        
        return datos
    
    def bCapturarEvent(self):
        datos = self.obtenerDatos()
        
        self.taDatos.delete("1.0",END)
        
        if datos == "VACIO":
            self.taDatos.insert(END,"Algun campo esta vacio...")
        else:
            if datos == "NO_NUMERICO":
                self.taDatos.insert(END,"Saldo debe ser numerico...")
            else:
                resultado = self.universidad.capturar(datos)
                self.taDatos.insert(END,resultado)
    
    def bConsultarEvent(self):
        self.taDatos.delete("1.0",END)
        
        datos = self.universidad.consultar()
        self.taDatos.insert(END,datos)
    
    def bConsultarMEvent(self):
        self.taDatos.delete("1.0",END)
        
        mat = self.tfMatricula.get()
        datos = self.universidad.consultarMatricula(mat)
        self.taDatos.insert(END,datos)

    def bConsultarCEvent(self):
        self.taDatos.delete("1.0",END)
        
        car = self.tfCarrera.get()
        datos = self.universidad.consultarCar(car)
        self.taDatos.insert(END,datos)

# CREACCION DEL OBJETO cliente de la class ClienteGUI (main() de C y Java)
alu = AlumnoGUI2()


