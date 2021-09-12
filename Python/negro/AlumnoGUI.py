#from Tkinter import *   # Package de Python 2.7
from tkinter import *    # Package de Python 3.7

# from BancoAD import BancoAD
from UniversidadADjdbc import UniversidadADjdbc

class AlumnoGUI:
    frame = Tk()
    
    # banco = BancoAD()
    universidad = UniversidadADjdbc()
    
    # Constructor
    def __init__(self):
        # 1. Definicion y creacion del objeto frame (Tk) (JFrame)
        #self.frame = Tk()
        self.frame.title("Universidad: Gestion de Alumnos")
        self.frame.geometry("600x400")

        # 2. Definicion y creacion de los atributos del frame
        self.lbMatricula  = Label(self.frame, text="Matrícula:")
        self.tfMatricula  = Entry(self.frame, width=20)
        
        self.lbNombre = Label(self.frame, text="NOMBRE:")
        self.tfNombre = Entry(self.frame, width=20)
        
        self.lbCarrera = Label(self.frame, text="CARRERA:")
        self.tfCarrera = Entry(self.frame, width=20);
        
        self.lbPlan = Label(self.frame, text="PLAN:")
        self.tfPlan = Entry(self.frame, width=20)

        self.lbDireccion = Label(self.frame, text="DIRECCION:")
        self.tfDireccion = Entry(self.frame, width=20)

        self.lbTelefono = Label(self.frame, text="TELEFONO:")
        self.tfTelefono = Entry(self.frame, width=20)
        
        self.bCapturar    = Button(self.frame, text="Capturar Datos",command=self.bCapturarEvent)
        self.bConsultar   = Button(self.frame, text="Consultar Alumnos",command=self.bConsultarEvent)
        self.bConsultarC = Button(self.frame, text="Consultar Carrera",command=self.bConsultarCEvent)
        self.bConsultarM = Button(self.frame, text="Consultar Matricula",command=self.bConsultarMEvent)
   
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
        self.bConsultarC.grid(row=7, column=0)
        self.bConsultarM.grid(row=7, column=1)
        self.taDatos.grid(row=8, column=0)

        # Hacer visible al frame
        self.frame.mainloop()
    
    # Metodos de la class ClienteGUI
    def obtenerDatos(self):
        mat  = self.tfMatricula.get()
        nom  = self.tfNombre.get()
        carr = self.tfCarrera.get()
        plan = self.tfPlan.get()
        dire = self.tfDireccion.get()
        tele = self.tfTelefono.get()
        
        if mat == "" or nom == "" or carr == "" or plan == "" or dire == "" or tele == "":
            datos = "VACIO"
        else:
           # try:
                #valor = float(saldo)
                #datos = cve+'_'+nom+'_'+tipo+'_'+saldo # Concatenacion correcta
            datos = mat+"_"+nom+"_"+carr+"_"+plan+"_"+dire+"_"+tele  # Concatenacion correcta
            # except:
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
        
        matricula = self.tfMatricula.get()
        datos = self.universidad.consultarMatricula(matricula)
        self.taDatos.insert(END,datos)

    def bConsultarCEvent(self):
        self.taDatos.delete("1.0",END)
        
        carrera = self.tfCarrera.get()
        datos = self.universidad.consultarCarrera(carrera)
        self.taDatos.insert(END,datos)

# CREACCION DEL OBJETO cliente de la class ClienteGUI (main() de C y Java)
alumno = AlumnoGUI()


