#from Tkinter import *   # Package de Python 2.7
from tkinter import *    # Package de Python 3.7

#from BancoAD import BancoAD
from UniversidadADjdbc import UniversidadADjdbc

class CursoGUI2:
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
        self.lbClave      = Label(self.frame, text="CLAVE:")
        self.tfClave      = Entry(self.frame, width=20)
        
        self.lbNombre     = Label(self.frame, text="NOMBRE")
        self.tfNombre     = Entry(self.frame, width=20)
        
        self.lbSemestre   = Label(self.frame, text="SEMESTRE:")
        self.tfSemestre   = Entry(self.frame, width=20);

                
        self.bCapturar    = Button(self.frame, text="Capturar Curso",command=self.bCapturarEvent)
        self.bConsultar   = Button(self.frame, text="Consultar Datos",command=self.bConsultarEvent)
       #self.bConsultarM = Button(self.frame, text="Consultar Matrícula",command=self.bConsultarMEvent)
        self.bConsultarC = Button(self.frame, text="Consultar Curso",command=self.bConsultarCEvent)
   
        self.taDatos      = Text(self.frame, width=40, height=10)        
        
        # 3. Colocar los objetos de los atributos en un Layout
        self.lbClave.grid(row=0, column=0)
        self.tfClave.grid(row=0, column=1)
        
        self.lbNombre.grid(row=1, column=0)
        self.tfNombre.grid(row=1, column=1)
        
        self.lbSemestre.grid(row=2, column=0)
        self.tfSemestre.grid(row=2, column=1)
        

        
        self.bCapturar.grid(row=3, column=0)
        self.bConsultar.grid(row=3, column=1)
       #self.bConsultarM.grid(row=7, column=0)
        self.bConsultarC.grid(row=4, column=1)
        self.taDatos.grid(row=5, column=0)

        # Hacer visible al frame
        self.frame.mainloop()
    
    # Metodos de la class ClienteGUI
    def obtenerDatos(self):
        cla  = self.tfClave.get()
        nom  = self.tfNombre.get()
        sem  = self.tfSemestre.get()

        
        if cla == "" or nom == "" or sem == "":
            datos = "VACIO"
        else:
            #try:
                #valor = float(saldo)
                #datos = cve+'_'+nom+'_'+tipo+'_'+saldo # Concatenacion correcta
            datos = cla+"_"+nom+"_"+sem
            #print (datos)
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
    
##    def bConsultarMEvent(self):
##        self.taDatos.delete("1.0",END)
##        
##        mat = self.tfMatricula.get()
##        datos = self.universidad.consultarMatricula(mat)
##        self.taDatos.insert(END,datos)

    def bConsultarCEvent(self):
        self.taDatos.delete("1.0",END)
        
        cla = self.tfClave.get()
        datos = self.universidad.consultarClave(cla)
        self.taDatos.insert(END,datos)

# CREACCION DEL OBJETO cliente de la class ClienteGUI (main() de C y Java)
alu = CursoGUI2()


