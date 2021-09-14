
class CursaDP:

    # Constructores
    def __init__(this):
        this.matricula  = ""
        this.cveCurso   = ""
        this.grupo      = ""
        this.salon      = ""
        this.hora       = ""

    def __init__(this, datos):
        if(datos == ""):
            this.matricula  = ""
            this.cveCurso   = ""
            this.grupo      = ""
            this.salon      = ""
            this.hora       = ""
        
        else:
            st = datos.split("_")
            
            this.matricula  = st[0]
            this.cveCurso   = st[1]
            this.grupo      = st[2]
            this.salon      = st[3]
            this.hora       = st[4]

    # Accesors (geters)
    def getMatricula(this):
        return this.matricula

    def getcveCurso(this):
        return this.cveCurso

    def getGrupo(this):
        return this.grupo

    def getSalon(this):
        return this.salon
    
    def getHora(this):
        return this.hora

    
    # Mutators (seters)
    def setMatricula(this,mat):
        this.matricula = mat

    def setcveCurso(this,cc):
        this.cveCurso    = cc

    def setGrupo(this,gru):
        this.grupo   = gru

    def setSalon(this,sal):
        this.salon      = sal
    
    def setHora(this,io):
        this.hora = io

##    def setTelefono(this,tel):
##        this.telefono  = tel

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
        return this.matricula+"_"+this.cveCurso+"_"+this.grupo+"_"+this.salon+"_"+this.hora

    def toStringSql(this):
        return "'"+this.matricula+"','"+this.cveCurso+"','"+this.grupo+"','"+this.salon+"','"+this.hora+"'"
