#ifndef Sgal_compu_h
#define Sgal_compu_h

class Computadora
{
    int direccion;
    bool enviar = false;
    
public:

    Computadora() {}
    
    Computadora(int direccion) : direccion(direccion) {}
    
    bool getEnviar()
    {
        return enviar;
    }
    
    int getDireccion() 
    {
        return direccion;
    }
    
    void setEnviar(bool value) 
    {
        enviar = value;
    }
    
    
    bool operator!=(Computadora c)
    {
        return (direccion != c.direccion);
    }
};

#endif
