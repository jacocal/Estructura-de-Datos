#ifndef Sgal_token_h
#define Sgal_token_h

class Token 
{
    std::string signal;
    int local = 0;
    int emisor;
    int receptor;
    bool recibido = false;
     
public:

    Token() { }
    
    int getlocal()
    {
        return local;
    }
    
    int getReceptor() 
    {
        return receptor;
    }
    
    int getEmisor() 
    {
        return emisor;
    }
    
    void setlocal(int value) 
    {
        local = value;
    }
    
    void setRecibido(bool value) 
    {
        recibido = value;
    }
    
    void enviar(int rec, std::string texto);
    void confirmar();
};

#endif
