//
//  main.cpp
//  segundaMano
//
//  Created by Roberta Medina on 4/24/19.
//  Copyright © 2019 Roberta Medina. All rights reserved.
//
//  Fundamentos de Ing. de Software Gpo 2
//  Ing. Jakeline Marcos Abed
//  Documento de Especificación de Requerimientos
//      CASO: Segundamano "Para Vender y Comprar"
//
//  Alexis Garibay Dávila A00819574
//  Juventino Gutierrez Romo A01250658
//  Roberta Medina Alva A00822344


#include <iostream>
#include <string>
using namespace std;

//                  CLASE PRODUCTO
class Producto{
protected:
    string sNombreP, sUbicacionP;
    int iCategoriaP;
public:
    Producto();
    void PublicarProducto(); //vendedor
    void BuscarProducto();   //cliente
    void ComentarProducto();
    void GuardarProducto();
    friend class Cliente;
    friend class Vendedor;
};


//                  CLASE USUARIO
class Usuario{
protected:
    string sNombre, sApellido, sCorreo, sContra, sUbicacion, sTelefono;
public:
    Usuario();
    void CreaUsuario();
    void AccedeCuenta();
    void CierraSesion();
    
};

//                  CLASE CLIENTE
class Cliente : protected Usuario{
protected:
    string sProducto;
public:
    Cliente();
    void BuscaProducto();
    void ContactaVendedor();
    friend class Producto;
    
};

//                  CLASE VENDEDOR
class Vendedor : protected Usuario{
protected:
    string sProducto;
public:
    Vendedor();
    void PublicaProducto();
    void ContactaCliente();
    friend class Producto;
};

void Usuario::CreaUsuario(){
    cout << "Bienvenido a Segundamano" << endl;
    cout << "A continuación, ingrese su primer nombre:" << endl;
    cin >> sNombre;
    cout << "Ingrese su apellido: " << endl;
    cin >> sApellido;
    cout << "Ingrese el correo electrónico que desea usar:" << endl;
    cin >> sCorreo;
    cout << "Ingrese su numero de telefono: " << endl;
    cin >> sTelefono;
    cout << "Ingrese estado al que pertenece: " << endl;
    cin >> sUbicacion;
    cout << "Ingrese la contrseña deseada: " << endl;
    cin >> sContra;
    
    cout << "¡Felicidades! La creación de su cuenta se ha realizado con éxito" << endl;
    cout << "¡Bienvenido " << sNombre << " " << sApellido << " ! " << endl;
    cout << endl;
}

void Usuario :: AccedeCuenta(){
    cout << "Bienvenido a Segundamano" << endl;
    cout << "Ingrese su correo electrónico:" << endl;
    cin >> sCorreo;
    cout << "Ingrese su contraseña:" << endl;
    cin >> sContra;
    cout << "El inicio de sesión se ha realizado con éxito." << endl;
    cout << "Bienvenido " << sNombre << " " << sApellido << " a Segundamano" << endl;
    cout << endl;
}

void Usuario::CierraSesion(){
    string sDes;
    cout << "¿Desea cerrar sesión?" << endl;
    cout << "[si]  [no]" << endl;
    cin >> sDes;
    if (sDes == "si"){
        cout << "CERRANDO SESIÓN" << endl;
        cout << " ... " << endl;
        cout << " ... " << endl;
        cout << "-- CIERRE DE SESIÓN REALIZADO CON ÉXITO --" << endl;
        
    }
    cout << endl;
}


void Cliente::BuscaProducto(){
    Producto bp;         //creación de objeto p de la clase producto
    bp.BuscarProducto(); // acceder a buscar producto
}


void Cliente ::ContactaVendedor(){
    string sDes, sMensaje, sDes2;
    int cont = 0;
    do {
        cout << "Ingrese la forma en la que desea contactar al vendedor: " << endl;
        cout << "[mensaje] [email] [llamada]" << endl;
        cin >> sDes;
        if (sDes == "mensaje"){
            do{
            cout << "Ingrese el mensaje que desea mandar:" << endl;
            cin >> sMensaje;
            cout << "El mensaje a publicar es el siguiente:" << endl;
            cout <<  " -- " << sMensaje << " -- ";
            cout << "¿Es esto correcto? [si] [no]" << endl;
            cin >> sDes2;
        } while (sDes2 == "no" || sDes2 == "NO");
            
            cout << "..." << endl;
            cout << "..." << endl;
            cout << "¡El mensaje se ha enviado con éxito!" << endl;
            cout << endl;
            cont++;
            
        }else if (sDes == "email" || sDes == "EMAIL"){
                do{
                    cout << "Ingrese el mensaje que desea enviar como correo electrónico:" << endl;
                    cin >> sMensaje;
                    cout << "El mensaje a enviar es el siguiente:" << endl;
                    cout <<  " -- " << sMensaje << " -- ";
                    cout << "¿Es esto correcto? [si] [no]" << endl;
                    cin >> sDes2;
                } while (sDes2 == "no" || sDes2 == "NO");
                        cout << "..." << endl;
                        cout << "..." << endl;
                        cout << "¡El mensaje se ha enviado con éxito!" << endl;
                        cout << endl;
            cont++;
            }else if (sDes == "llamada" || sDes == "llamada"){
                    cout << "Espere un momento en lo que establecemos la llamada" << endl;
                        cout << "..." << endl;
                        cout << "..." << endl;
                        cout << "..." << endl;
                        cout << "Lamentamos informarle que el usuario al que desea contactar, no se encuenta dispoible por medio de llamada." << endl;
                        cout << "Le sugerimos que intente contactarlo por otro medio." << endl;
                cout << endl;
                cont++;
                }
    }while (cont == 1);
    cout << endl;
}



void Vendedor::PublicaProducto(){
    Producto pp;
    pp.PublicarProducto();
}


void Vendedor::ContactaCliente(){
    string sDes, sMensaje, sDes2;
    int cont = 0;
    do {
        cout << "Ingrese la forma en la que desea contactar al cliente: " << endl;
        cout << "[mensaje] [email] [llamada]" << endl;
        cin >> sDes;
        if (sDes == "mensaje" || sDes == "MENSAJE"){
            do{
            cout << "Ingrese el mensaje que desea mandar:" << endl;
            cin >> sMensaje;
            cout << "El mensaje a publicar es el siguiente:" << endl;
            cout <<  " -- " << sMensaje << " -- ";
            cout << "¿Es esto correcto? [si] [no]" << endl;
                cin >> sDes2;
        } while (sDes2 == "no" || sDes2 == "NO");
            cout << "..." << endl;
            cout << "..." << endl;
            cout << "¡El mensaje se ha enviado con éxito!" << endl;
            cout << endl;
            cont++;
            
        }else if (sDes == "email" || sDes == "EMAIL"){
                do{
                cout << "Ingrese el mensaje que desea enviar como correo electrónico:" << endl;
                cin >> sMensaje;
                cout << "El mensaje a publicar es el siguiente:" << endl;
                cout <<  " -- " << sMensaje << " -- ";
                cout << "¿Es esto correcto? [si] [no]" << endl;
                cin >> sDes2;
            } while (sDes2 == "no" || sDes2 == "NO");
            cout << "..." << endl;
            cout << "..." << endl;
            cout << "¡El mensaje ha enviado con éxito!" << endl;
            cout << endl;
            cont++;
            
            }else if (sDes == "llamada" || sDes == "LLAMADA"){
                    cout << "Espere un momento en lo que establecemos la llamada" << endl;
                    cout << "..." << endl;
                    cout << "..." << endl;
                    cout << "..." << endl;
                    cout << "Lamentamos informarle que el usuario al que desea contactar, no se encuenta dispoible por medio de llamada." << endl;
                    cout << "Le sugerimos que intente contactarlo por otro medio." << endl;
                cout << endl;
                cont++;
                }
    }while (cont == 1);
    cout << endl;
}


void Producto::PublicarProducto(){
    string sDes, sCategoriaP;
    
    do{
        cout << "Seleccione la categoria en la que desea publicar el producto: \n"
        << " --------------------------------------------------------------------------------------------\n"
        << " |       1. INMUEBLES                                                                        |\n"
        << " |       2. EMPLEO Y EDUACIÓN                                                                |\n"
        << " |       3. VEHÍCULOS                                                                        |\n"
        << " |       4. TIEMPO LIBRE                                                                     |\n"
        << " |       5. COMPUTACIÓN Y ELECTRÓNICA                                                        |\n"
        << " |       6. SERVICIOS                                                                        |\n"
        << " |       7. TU HOGAR Y TÚ                                                                    |\n"
        << " |       8. NEGOCIOS E INDUSTRIA                                                             |\n"
        << " --------------------------------------------------------------------------------------------\n";
        cin >> iCategoriaP;
        switch (iCategoriaP) {
            case 1:
                sCategoriaP = "INMUEBLES";
                break;
            case 2:
                sCategoriaP = "EMPLEO Y EDUCACIÓN";
                break;
                
            case 3:
                sCategoriaP = "VEHÍCULOS";
                break;
                
            case 4:
                sCategoriaP = "TIEMPO LIBRE";
                break;
                
            case 5:
                sCategoriaP = "COMPUTACIÓN Y ELECTRÓNICA";
                break;
                
            case 6:
                sCategoriaP = "SERVICIOS";
                break;
                
            case 7:
                sCategoriaP = "TU HOGAR Y TU";
                break;
                
            case 8:
                sCategoriaP = "NEGOCIOS E INDUSTRIA";
                break;
                
            default:
                cout << "Categoria inexistente" << endl;
                break;
        }
        cout << "Ingrese nombre del producto a publicar:" << endl;
        cin >> sNombreP;
        cout << " El producto con nombre -" << sNombreP << "- será publicado en la categoria " << sCategoriaP << endl;
        cout << "¿Es esto correcto? [si] [no]" << endl;
        cin >> sDes;
    } while (sDes == "no" || sDes == "NO");
    cout << "..." << endl;
    cout << "..." << endl;
    cout << "¡El producto -" << sNombreP << "- ha sido publicado con éxito en la categoria " << sCategoriaP << endl;
    cout << endl;
}


void Producto::BuscarProducto(){
    string sDes;
    
    cout << "Ingrese la categoria en la que se encuentra el producto: \n"
    << " --------------------------------------------------------------------------------------------\n"
    << " |       1. INMUEBLES                                                                        |\n"
    << " |       2. EMPLEO Y EDUACIÓN                                                                |\n"
    << " |       3. VEHÍCULOS                                                                        |\n"
    << " |       4. TIEMPO LIBRE                                                                     |\n"
    << " |       5. COMPUTACIÓN Y ELECTRÓNICA                                                        |\n"
    << " |       6. SERVICIOS                                                                        |\n"
    << " |       7. TU HOGAR Y TÚ                                                                    |\n"
    << " |       8. NEGOCIOS E INDUSTRIA                                                             |\n"
    << " --------------------------------------------------------------------------------------------\n";
    cin >> iCategoriaP;
    cout << "Ingrese el producto que desea buscar:" << endl;
    cin >> sNombreP;
    
    switch (iCategoriaP) {
        case 1:
            cout << "El producto -" << sNombreP << "- se encuentra disponible en la categoría INMUEBLES" << endl;
            break;
        case 2:
            cout << "El producto -" << sNombreP << "- se encuentra disponible en la categoría EMPLEO Y EDUCACIÓN" << endl;
            break;
            
        case 3:
            cout << "El producto -" << sNombreP << "- se encuentra disponible en la categoría VEHÍCULOS" << endl;
            break;
            
        case 4:
            cout << "El producto -" << sNombreP << "- se encuentra disponible en la categoría TIEMPO LIBRE" << endl;
            break;
            
        case 5:
            cout << "El producto -" << sNombreP << "- se encuentra disponible en la categoría COMPUTACIÓN Y ELECTRÓNICA" << endl;
            break;
            
        case 6:
            cout << "El producto -" << sNombreP << "- se encuentra disponible en la categoría SERVICIOS" << endl;
            break;
            
        case 7:
            cout << "El producto -" << sNombreP << "- se encuentra disponible en la categoría TU HOGAR Y TU" << endl;
            break;
            
        case 8:
            cout << "El producto -" << sNombreP << "- se encuentra disponible en la categoría NEGOCIOS E INDUSTRIA" << endl;
            break;
            
        default:
            cout << "Categoria iexistente" << endl;
            break;
    }
    
    cout << "Las opciones disponibles son: " << endl;
    cout << " [COMENTAR] [GUARDAR] [CONTACTAR]" << endl;
    cin >> sDes;
    
    if (sDes == "COMENTAR" || sDes == "comentar"){
        ComentarProducto();
    }else if (sDes == "GUARDAR" || sDes == "guardar"){
        GuardarProducto();
    }else if (sDes == "CONTACTAR" || sDes =="contactar"){
        Cliente cl;
        cl.ContactaVendedor();
    }
    cout << endl;
}

void Producto::ComentarProducto(){
    string sComentario, sDes;
    
    do {
        cout << "Escriba el comentario que desea agregar: " << endl;
        cin >> sComentario;
        cout << "El mensaje a publicar es el siguiente:" << endl;
        cout <<  " -- " << sComentario << " -- ";
        cout << "¿Es esto correcto? [si] [no]" << endl;
        cin >> sDes;
    } while (sDes == "no" || sDes == "NO");
    
    cout << "..." << endl;
    cout << "..." << endl;
    cout << "¡El comentario ha sido publicado con éxito!" << endl;
    cout << endl;
}

void Producto::GuardarProducto(){
    string sDes;
    cout << "¿Desea guardar en su lista el producto selecciónado? " << endl;
    cout << "[si] [no]" << endl;
    cin >> sDes;
    if (sDes == "si" || sDes == "SI") {
        cout << "..." << endl;
        cout << "..." << endl;
        cout << sNombreP << "se ha guardado con éxito. " << endl;
        cout << endl;
    }
}

//constructores
Usuario::Usuario (){
}
Cliente::Cliente(){
}
Vendedor::Vendedor(){
}
Producto::Producto(){
}

//menu de opciones
void menu(){
    /*
    cout <<
    "    /$$$$$$  /$$$$$$$$  /$$$$$$  /$$   /$$ /$$   /$$ /$$$$$$$   /$$$$$$        /$$      /$$  /$$$$$$  /$$   /$$  /$$$$$$ \n"
    "   /$$__  $$| $$_____/ /$$__  $$| $$  | $$| $$$ | $$| $$__  $$ /$$__  $$      | $$$    /$$$ /$$__  $$| $$$ | $$ /$$__  $$\n"
    "  | $$  //_/| $$      | $$  \\_/|  $$  | $$| $$$$| $$| $$  \\ $$| $$  \\ $$      | $$$$  /$$$$| $$  \\ $$| $$$$| $$| $$  \\ $$\n"
    "  |  $$$$$$ | $$$$$   | $$ /$$$$| $$  | $$| $$ $$ $$| $$  | $$| $$$$$$$$      | $$ $$/$$ $$| $$$$$$$$| $$ $$ $$| $$  | $$\n"
    "   \\____  $$| $$__/   | $$|_  $$| $$  | $$| $$  $$$$| $$  | $$| $$__  $$      | $$  $$$| $$| $$__  $$| $$  $$$$| $$  | $$\n"
    "   /$$  //$$| $$      | $$  \\$$|  $$  | $$| $$\\  $$$| $$  | $$| $$  | $$      | $$\\  $ | $$| $$  | $$| $$\\  $$$| $$  | $$\n"
    "  |  $$$$$$/| $$$$$$$$|  $$$$$$/|  $$$$$$/| $$ \\  $$| $$$$$$$/| $$  | $$      | $$\\/   | $$| $$  | $$| $$ \\  $$|  $$$$$$/\n"
    "   \\_______/|________/ \\_____/  \\_______/ |__/  \\__/|_______/ |__/  |__/      |__/     |__/|__/  |__/|__/  \\_/ \\_____/ \n";
    */
    
    cout
    << " --------------------------------------------------------------------------------------------\n"
    << " |            B I E N V E N I D O       A       S E G U N D A   M A N O                      |\n"
    << " |                                                                                           |\n"
    << " |           - MENÚ DE OPCIONES -                                                            |\n"
    << " |                                                                                           |\n"
    << " |   C L I E N T E                                                                           |\n"
    << " |      1. CREAR USUARIO                                                                     |\n"
    << " |      2. ACCEDER A CUENTA                                                                  |\n"
    << " |      3. BUSCAR PRODUCTO                                                                   |\n"
    << " |      4. CONTACTAR VENDEDOR                                                                |\n"
    << " |      5. CERRAR SESIÓN                                                                     |\n"
    << " |                                                                                           |\n"
    << " | V E N D E D O R                                                                           |\n"
    << " |      6. CREAR USUARIO                                                                     |\n"
    << " |      7. ACCEDER A CUENTA                                                                  |\n"
    << " |      8. PUBLICA PRODUCTO                                                                  |\n"
    << " |      9. CONTACTAR CLIENTE                                                                 |\n"
    << " |      10. CERRAR SESIÓN                                                                    |\n"
    << " |   0. SALIR DE SEGUNDAMANO                                                                 |\n"
    << " --------------------------------------------------------------------------------------------\n";
    
}
int main() {
    
    Usuario miUsuario;
    Cliente miCliente;
    Vendedor miVendedor;
    Producto miProducto;
    
    //declaración de variables
    int iMenu;
    
    //desplegar menu
    do {
        menu();
        cin >> iMenu;
        
        
        switch (iMenu){
            case 0:
                cout << "¡Gracias por usar Segundamano, vuelva a visitarnos pronto!" << endl;
                return 0;
                break;
                
            case 1:
                miUsuario.CreaUsuario();
                break;
                
            case 2:
                miUsuario.AccedeCuenta();
                break;
                
            case 3:
                miProducto.BuscarProducto();
                break;
                
            case 4:
                miCliente.ContactaVendedor();
                break;
                
            case 5:
                miUsuario.CierraSesion();
                break;
                
            case 6:
                miUsuario.CreaUsuario();
                break;
                
            case 7:
                miUsuario.AccedeCuenta();
                break;
                
            case 8:
                miProducto.PublicarProducto();
                break;
                
            case 9:
                miVendedor.ContactaCliente();
                break;
                
            case 10:
                miUsuario.CierraSesion();
                break;
                
            default:
                cout << "Opción Incorrecta" << endl;
                return 0;
        }
        
    }while (iMenu != 0);
    return 0;
}
