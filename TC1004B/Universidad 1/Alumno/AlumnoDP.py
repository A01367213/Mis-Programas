
class AlumnoDP:

    # Constructores
    def __init__(this):
        this.matricula  = ""
        this.nombre     = ""
        this.carrera    = ""
        this.plan       = ""
        this.direccion  = ""
        this.telefono   = ""

    def __init__(this, datos):
        if(datos == ""):
            this.matricula  = ""
            this.nombre     = ""
            this.carrera    = ""
            this.plan       = ""
            this.direccion  = ""
            this.telefono   = ""
        else:
            st = datos.split("_")
            
            this.matricula  = st[0]
            this.nombre     = st[1]
            this.carrera    = st[2]
            this.plan       = st[3]
            this.direccion  = st[4]
            this.telefono   = st[5]

    # Accesors (geters)
    def getMatricula(this):
        return this.matricula

    def getNombre(this):
        return this.nombre

    def getCarrera(this):
        return this.carrera

    def getPlan(this):
        return this.plan
    
    def getDireccion(this):
        return this.direccion

    def getTelefono(this):
        return this.telefono


    
    # Mutators (seters)
    def setMatricula(this,mat):
        this.matricula = mat

    def setNombre(this,nom):
        this.nombre    = nom

    def setCarrera(this,car):
        this.carrera   = car

    def setPlan(this,pln):
        this.plan      = pln
    
    def setDireccion(this,drc):
        this.direccion = drc

    def setTelefono(this,tel):
        this.telefono  = tel

##    def setNocta(this,ncta):
##        this.nocta = ncta
##
##    def setNombre(this,name):
##        this.nombre = name
##
##    def setTipo(this,tcta):
##        this.tipo = tcta
##
##    def setSaldo(this,cantidad):
##        this.saldo = cantidad

    # Metodos
    def toString(this):
        return this.matricula+"_"+this.nombre+"_"+this.carrera+"_"+this.plan+"_"+this.direccion+"_"+this.telefono

    def toStringSql(this):
        return "'"+this.matricula+"','"+this.nombre+"','"+this.carrera+"','"+this.plan+"','"+this.direccion+"','"+this.telefono+"'"
