#from Tkinter import *   # Package de Python 2.7
from tkinter import *    # Package de Python 3.7

#from BancoAD import BancoAD
from UniversidadADjdbc import UniversidadADjdbc

class CursaGUI2:
    frame = Tk()
    
    #banco = BancoAD()
    universidad = UniversidadADjdbc()
    
    # Constructor
    def __init__(self):
        # 1. Definicion y creacion del objeto frame (Tk) (JFrame)
        #self.frame = Tk()
        self.frame.title("Gestor Cursos de Alumnos")
        self.frame.geometry("600x400")

        # 2. Definicion y creacion de los atributos del frame
        self.lbMatricula  = Label(self.frame, text="MATRICULA:")
        self.tfMatricula  = Entry(self.frame, width=20)
        
        self.lbcveCurso   = Label(self.frame, text="CURSO")
        self.tfcveCurso   = Entry(self.frame, width=20)
        
        self.lbGrupo      = Label(self.frame, text="GRUPO:")
        self.tfGrupo      = Entry(self.frame, width=20);
        
        self.lbSalon      = Label(self.frame, text="SALON:")
        self.tfSalon      = Entry(self.frame, width=20)

        self.lbHora       = Label(self.frame, text="HORA:")
        self.tfHora       = Entry(self.frame, width=20)

        
        self.bCapturar    = Button(self.frame, text="Capturar Datos",command=self.bCapturarEvent)
        self.bConsultar   = Button(self.frame, text="Consultar Información",command=self.bConsultarEvent)
        #self.bConsultarM = Button(self.frame, text="Consultar Curso",command=self.bConsultarMEvent)
        self.bConsultarC = Button(self.frame, text="Consultar Curso",command=self.bConsultarCCEvent)
   
        self.taDatos      = Text(self.frame, width=40, height=10)        
        
        # 3. Colocar los objetos de los atributos en un Layout
        self.lbMatricula.grid(row=0, column=0)
        self.tfMatricula.grid(row=0, column=1)
        
        self.lbcveCurso.grid(row=1, column=0)
        self.tfcveCurso.grid(row=1, column=1)
        
        self.lbGrupo.grid(row=2, column=0)
        self.tfGrupo.grid(row=2, column=1)
        
        self.lbSalon.grid(row=3, column=0)
        self.tfSalon.grid(row=3, column=1)

        self.lbHora.grid(row=4, column=0)
        self.tfHora.grid(row=4, column=1)


        
        self.bCapturar.grid(row=5, column=0)
        self.bConsultar.grid(row=5, column=1)
        #self.bConsultarM.grid(row=6, column=0)
        self.bConsultarC.grid(row=6, column=0)
        self.taDatos.grid(row=7, column=0)

        # Hacer visible al frame
        self.frame.mainloop()
    
    # Metodos de la class ClienteGUI
    def obtenerDatos(self):
        mat  = self.tfMatricula.get()
        cc  = self.tfcveCurso.get()
        gru = self.tfGrupo.get()
        sal = self.tfSalon.get()
        io = self.tfHora.get()
        
        if mat == "" or cc == "" or gru == "" or sal == "" or io == "":
            datos = "VACIO"
        else:
            #try:
                #valor = float(saldo)
                #datos = cve+'_'+nom+'_'+tipo+'_'+saldo # Concatenacion correcta
            datos = mat+"_"+cc+"_"+gru+"_"+sal+"_"+io
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

    def bConsultarCCEvent(self):
        self.taDatos.delete("1.0",END)
        
        cc = self.tfcveCurso.get()
        datos = self.universidad.consultarCC(cc)
        self.taDatos.insert(END,datos)

# CREACCION DEL OBJETO cliente de la class ClienteGUI (main() de C y Java)
alu = CursaGUI2()


