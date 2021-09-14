
class CursoDP:

    # Constructores
    def __init__(this):
        this.clave      = ""
        this.nombre     = ""
        this.semestre   = ""


    def __init__(this, datos):
        if(datos == ""):
            this.clave      = ""
            this.nombre     = ""
            this.semestre   = ""
        else:
            st = datos.split("_")
            
            this.clave      = st[0]
            this.nombre     = st[1]
            this.semestre   = st[2]


    # Accesors (geters)
    def getClave(this):
        return this.clave

    def getNombre(this):
        return this.nombre

    def getSemestre(this):
        return this.semestre


    
    # Mutators (seters)
    def setClave(this,cla):
        this.clave = cla

    def setNombre(this,nom):
        this.nombre    = nom

    def setSemestre(this,sem):
        this.semestre  = sem

##    def setPlan(this,pln):
##        this.plan      = pln
##    
##    def setDireccion(this,drc):
##        this.direccion = drc
##
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
        return this.clave+"_"+this.nombre+"_"+str(this.semestre)

    def toStringSql(this):
        return "'"+this.clave+"','"+this.nombre+"','"+this.semestre+"'"
