#include <Keyboard.h>
#define ASPAS_DUPLA 126


//O layout padrão para a biblioteca Keyboard.h é o layout do teclado americano (US).

// C:\Users\marce\OneDrive\Documentos\Arduino\libraries\
// C:\Program Files (x86)\Arduino\libraries\

//     0x38|SHIFT,    // ?   US
//     0x2d|SHIFT,    // ?   BR
/*
 * http://www.lilygo.cn/prod_view.aspx?TypeId=50033&Id=1179&FId=t3:50033:3  =>  LILYGO T-Dongle-S3
 * https://www.youtube.com/watch?v=xJClVZAs0wQ&t=201s (recuperar bootloader)
 * Placa MEGA32UA  (Placa Arduino Leonardo)
 * Pinos: 1 +5v 
 *        2 GND
 *        3 RST
 * 
 * https://www.arduino.cc/reference/pt/language/functions/usb/keyboard/
 * https://www.arduino.cc/reference/pt/language/functions/usb/keyboard/keyboardmodifiers/
 * https://docs.microsoft.com/pt-br/powershell/scripting/samples/collecting-information-about-computers?view=powershell-7.2
 * https://techexpert.tips/pt-br/powershell-pt-br/powershell-exibir-uma-mensagem-pop-up/
 * https://forum.arduino.cc/t/keyboard-layout-automatically/906762/7
 
PS C:\Users\marce> $url="https://drive.google.com/uc?export=download&id=1IUQDIyQm4KciW-GVqtKiTgTK33lwQxFA"
PS C:\Users\marce> $output="C:/tmp/arquivo.zip"
PS C:\Users\marce> $username="betobatera16@gmail.com"
PS C:\Users\marce> $password="@wolverine13"
PS C:\Users\marce> Invoke-WebRequest -Uri $url -OutFile $output -Headers @{"Authorization"="Basic"+[System.Convert]::ToBase64String([System.Text.Encoding]::ASCII.GetBytes($username+":"+$password))}
PS C:\Users\marce>
 
 */

// Init function
void setup()
{
  // Begining the stream

  Keyboard.begin();
  //Keyboard.setKeyboardLayout(KEYBR);
      
      // Espera 3 segundos por garantia da execução
      delay(3000);

      //Keyboard.setKeyboardLayout(0x02); // Define o layout do teclado como o padrão dos EUA
      
            
      // Abre o PowerShell pressionando as teclas Win + R e digitando "powershell" na janela Executar
      Keyboard.press(KEY_LEFT_GUI);
      Keyboard.press('r');
      Keyboard.releaseAll();
      delay(500);
      // Start-Process powershell.exe -ArgumentList "-WindowStyle Minimized", "-File", "C:\caminho\para\seu\script.ps1"
      // Start-Process powershell.exe -ArgumentList "-WindowStyle Minimized", "-File", "C:\caminho\para\seu\script.ps1"
      Keyboard.print("powershell -ArgumentList -WindowStyle Minimized");
      //Keyboard.print("powershell -Verb runAs");      
      Keyboard.press(KEY_RETURN);
      Keyboard.releaseAll();
      delay(2000);


      //Inicia a execução do script no PowerShell      
      //Escreva a linha de comando que deseja e ajuste caso algum caractere não possa ser reconhecido.
      //Usar sempre a barra invertida para path. C:\ => C:/

      /*O ID do arquivo é o valor que vem após o "id=" na URL.
        Por exemplo, se o link compartilhável for: https://drive.google.com/file/d/1ABCDEFG12345678/view, o ID do arquivo é "1ABCDEFG12345678". */
            
      
      convertchar("$url=");   
      Keyboard.write(ASPAS_DUPLA);  
      convertchar("https://drive.google.com/uc?export=download&id=1IUQDIyQm4KciW-GVqtKiTgTK33lwQxFA");
      Keyboard.write(ASPAS_DUPLA);  
      typeKey(KEY_RETURN);

      //# Define o caminho e nome do arquivo a ser salvo
      convertchar("mkdir C:/lilygo -ErrorAction SilentlyContinue");
      typeKey(KEY_RETURN);
      convertchar("$output=");
      Keyboard.write(ASPAS_DUPLA);
      convertchar("C:/lilygo/arquivo.zip");
      //convertchar("C:/Users/marce/Downloads/arquivo.zip");  
      Keyboard.write(ASPAS_DUPLA);
      typeKey(KEY_RETURN); 

      //# Define as credenciais da sua conta Google
      convertchar("$username=");
      Keyboard.write(ASPAS_DUPLA);
      convertchar("betobatera16@gmail.com");
      Keyboard.write(ASPAS_DUPLA);
      typeKey(KEY_RETURN);
      convertchar("$password=");
      Keyboard.write(ASPAS_DUPLA);
      convertchar("@wolverine13");
      Keyboard.write(ASPAS_DUPLA);
      typeKey(KEY_RETURN);

      //# Faz o download do arquivo usando o comando "wget"  (arquivo texto)
      convertchar("Invoke-WebRequest -Uri $url -OutFile $output -Headers @{");
      Keyboard.write(ASPAS_DUPLA);
      convertchar("Authorization");
      Keyboard.write(ASPAS_DUPLA);
      convertchar("=");
      Keyboard.write(ASPAS_DUPLA);
      convertchar("Basic");
      Keyboard.write(ASPAS_DUPLA);
      convertchar("+[System.Convert]::ToBase64String([System.Text.Encoding]::ASCII.GetBytes($username+");
      Keyboard.write(ASPAS_DUPLA);
      convertchar(":");
      Keyboard.write(ASPAS_DUPLA);
      convertchar("+$password))}");
      typeKey(KEY_RETURN);

      /*
      convertchar("Start-Process");
      Keyboard.write(ASPAS_DUPLA);
      convertchar"C:/tmp/modelagem-desenho-processos_compressed-64.pdf");
      Keyboard.write(ASPAS_DUPLA);
      typeKey(KEY_RETURN);
      */
        
  Keyboard.end();
}

//=====================================================================================================
//a function to send Ctrl + Alt + key
//template<typename T>
void printPIPE(){

  Keyboard.write(64);  //Teste   
  delay(50);
  Keyboard.releaseAll();

}

template<typename T>
void printAlt(T key){
  Keyboard.press(KEY_LEFT_ALT);
  Keyboard.write(key);
  delay(50);
  Keyboard.releaseAll();  
}
template<typename T>
void printCtrlAlt(T key){
  Keyboard.press(KEY_LEFT_CTRL);
  Keyboard.press(KEY_LEFT_ALT);
  Keyboard.write(key);
  Keyboard.release(KEY_LEFT_CTRL);
  Keyboard.release(KEY_LEFT_ALT);
}
//a function to send Ctrl + Shift + key
template<typename T>
void printCtrlShift(T key){
  Keyboard.press(KEY_LEFT_CTRL);
  Keyboard.press(KEY_LEFT_SHIFT);
  Keyboard.write(key);
  Keyboard.release(KEY_LEFT_CTRL);
  Keyboard.release(KEY_LEFT_SHIFT);
}

void typeKey(int key)
{
  Keyboard.press(key);
  delay(50);
  Keyboard.release(key);
}
// Unused
void loop() {}


//=========================================================================================================================================================================================
void convertchar(const char string[]){

  for (int c = 0; c < strlen(string); c++){
    char toPrint;

    //Se for letra guardo na tostring
    if(string[c] >= 65 && string[c] <= 90 ) toPrint = string[c];
    else if(string[c] >= 97 && string[c] <= 122 ) toPrint = string[c];
    //Se for numero guardo na tostring
    else if(string[c] >= 48 && string[c] <= 57 ) toPrint = string[c];

    //Se for caracter especial substituo pelo codigo, se não imprimo
    
         if(string[c] == '#') Keyboard.write('\\');//Teste
    else if(string[c] == ' ') Keyboard.write(32);  //ok
    else if(string[c] == '$') Keyboard.write(36);  //ok  
    else if(string[c] == '%') Keyboard.write(37);  //Teste  
    else if(string[c] == '&') Keyboard.write(38);  //ok
    else if(string[c] == '(') Keyboard.write(40);  //Teste    
    else if(string[c] == ')') Keyboard.write(41);  //Teste    
    else if(string[c] == '*') Keyboard.write(42);  //Teste  
    else if(string[c] == '+') Keyboard.write(43);  //ok      
    else if(string[c] == ',') Keyboard.write(44);  //Teste    
    else if(string[c] == '.') Keyboard.write(46);
    else if(string[c] == ';') Keyboard.write(47);  //Teste
    else if(string[c] == '<') Keyboard.write(60);
    else if(string[c] == '=') Keyboard.write(61);
    else if(string[c] == '>') Keyboard.write(62);
    else if(string[c] == ':') Keyboard.write(63);
    else if(string[c] == '?') printCtrlAlt(119);   //ok
    else if(string[c] == '@') Keyboard.write(64);  //ok    
    else if(string[c] == ']') Keyboard.write(92);
    else if(string[c] == '[') Keyboard.write(93);
    else if(string[c] == '_') Keyboard.write(95);
    else if(string[c] == '}') Keyboard.write(124);
    else if(string[c] == '{') Keyboard.write(125);
    //else if(string[c] == '"') Keyboard.write(ASPAS_DUPLA);  //Não entra só funciona por fora.
    else if(string[c] == '-') Keyboard.write('-');
    else if(string[c] == '/') printCtrlAlt(113);
    else if(string[c] == '|') printPIPE();       //Teste
    else if(strlen(toPrint) < 1) Keyboard.write(string[c]);
    else Keyboard.write(toPrint);
    
    delay(15);
  }
}

/*
 * 
 * ASCII Table ~ Character Map
    !, dec: 33, hex: 21, oct: 41, bin: 100001
    ", dec: 34, hex: 22, oct: 42, bin: 100010
    #, dec: 35, hex: 23, oct: 43, bin: 100011
    $, dec: 36, hex: 24, oct: 44, bin: 100100
    %, dec: 37, hex: 25, oct: 45, bin: 100101
    &, dec: 38, hex: 26, oct: 46, bin: 100110
    ', dec: 39, hex: 27, oct: 47, bin: 100111
    (, dec: 40, hex: 28, oct: 50, bin: 101000
    ), dec: 41, hex: 29, oct: 51, bin: 101001
    *, dec: 42, hex: 2A, oct: 52, bin: 101010
    +, dec: 43, hex: 2B, oct: 53, bin: 101011
    ,, dec: 44, hex: 2C, oct: 54, bin: 101100
    -, dec: 45, hex: 2D, oct: 55, bin: 101101
    ., dec: 46, hex: 2E, oct: 56, bin: 101110
    /, dec: 47, hex: 2F, oct: 57, bin: 101111
    0, dec: 48, hex: 30, oct: 60, bin: 110000
    1, dec: 49, hex: 31, oct: 61, bin: 110001
    2, dec: 50, hex: 32, oct: 62, bin: 110010
    3, dec: 51, hex: 33, oct: 63, bin: 110011
    4, dec: 52, hex: 34, oct: 64, bin: 110100
    5, dec: 53, hex: 35, oct: 65, bin: 110101
    6, dec: 54, hex: 36, oct: 66, bin: 110110
    7, dec: 55, hex: 37, oct: 67, bin: 110111
    8, dec: 56, hex: 38, oct: 70, bin: 111000
    9, dec: 57, hex: 39, oct: 71, bin: 111001
    :, dec: 58, hex: 3A, oct: 72, bin: 111010
    ;, dec: 59, hex: 3B, oct: 73, bin: 111011
    <, dec: 60, hex: 3C, oct: 74, bin: 111100
    =, dec: 61, hex: 3D, oct: 75, bin: 111101
    >, dec: 62, hex: 3E, oct: 76, bin: 111110
    ?, dec: 63, hex: 3F, oct: 77, bin: 111111
    @, dec: 64, hex: 40, oct: 100, bin: 1000000
    A, dec: 65, hex: 41, oct: 101, bin: 1000001
    B, dec: 66, hex: 42, oct: 102, bin: 1000010
    C, dec: 67, hex: 43, oct: 103, bin: 1000011
    D, dec: 68, hex: 44, oct: 104, bin: 1000100
    E, dec: 69, hex: 45, oct: 105, bin: 1000101
    F, dec: 70, hex: 46, oct: 106, bin: 1000110
    G, dec: 71, hex: 47, oct: 107, bin: 1000111
    H, dec: 72, hex: 48, oct: 110, bin: 1001000
    I, dec: 73, hex: 49, oct: 111, bin: 1001001
    J, dec: 74, hex: 4A, oct: 112, bin: 1001010
    K, dec: 75, hex: 4B, oct: 113, bin: 1001011
    L, dec: 76, hex: 4C, oct: 114, bin: 1001100
    M, dec: 77, hex: 4D, oct: 115, bin: 1001101
    N, dec: 78, hex: 4E, oct: 116, bin: 1001110
    O, dec: 79, hex: 4F, oct: 117, bin: 1001111
    P, dec: 80, hex: 50, oct: 120, bin: 1010000
    Q, dec: 81, hex: 51, oct: 121, bin: 1010001
    R, dec: 82, hex: 52, oct: 122, bin: 1010010
    S, dec: 83, hex: 53, oct: 123, bin: 1010011
    T, dec: 84, hex: 54, oct: 124, bin: 1010100
    U, dec: 85, hex: 55, oct: 125, bin: 1010101
    V, dec: 86, hex: 56, oct: 126, bin: 1010110
    W, dec: 87, hex: 57, oct: 127, bin: 1010111
    X, dec: 88, hex: 58, oct: 130, bin: 1011000
    Y, dec: 89, hex: 59, oct: 131, bin: 1011001
    Z, dec: 90, hex: 5A, oct: 132, bin: 1011010
    [, dec: 91, hex: 5B, oct: 133, bin: 1011011
    \, dec: 92, hex: 5C, oct: 134, bin: 1011100
    ], dec: 93, hex: 5D, oct: 135, bin: 1011101
    ^, dec: 94, hex: 5E, oct: 136, bin: 1011110
    _, dec: 95, hex: 5F, oct: 137, bin: 1011111
    `, dec: 96, hex: 60, oct: 140, bin: 1100000
    a, dec: 97, hex: 61, oct: 141, bin: 1100001
    b, dec: 98, hex: 62, oct: 142, bin: 1100010
    c, dec: 99, hex: 63, oct: 143, bin: 1100011
    d, dec: 100, hex: 64, oct: 144, bin: 1100100
    e, dec: 101, hex: 65, oct: 145, bin: 1100101
    f, dec: 102, hex: 66, oct: 146, bin: 1100110
    g, dec: 103, hex: 67, oct: 147, bin: 1100111
    h, dec: 104, hex: 68, oct: 150, bin: 1101000
    i, dec: 105, hex: 69, oct: 151, bin: 1101001
    j, dec: 106, hex: 6A, oct: 152, bin: 1101010
    k, dec: 107, hex: 6B, oct: 153, bin: 1101011
    l, dec: 108, hex: 6C, oct: 154, bin: 1101100
    m, dec: 109, hex: 6D, oct: 155, bin: 1101101
    n, dec: 110, hex: 6E, oct: 156, bin: 1101110
    o, dec: 111, hex: 6F, oct: 157, bin: 1101111
    p, dec: 112, hex: 70, oct: 160, bin: 1110000
    q, dec: 113, hex: 71, oct: 161, bin: 1110001  // '/'
    r, dec: 114, hex: 72, oct: 162, bin: 1110010
    s, dec: 115, hex: 73, oct: 163, bin: 1110011
    t, dec: 116, hex: 74, oct: 164, bin: 1110100
    u, dec: 117, hex: 75, oct: 165, bin: 1110101
    v, dec: 118, hex: 76, oct: 166, bin: 1110110
    w, dec: 119, hex: 77, oct: 167, bin: 1110111  // '?'
    x, dec: 120, hex: 78, oct: 170, bin: 1111000
    y, dec: 121, hex: 79, oct: 171, bin: 1111001
    z, dec: 122, hex: 7A, oct: 172, bin: 1111010
    {, dec: 123, hex: 7B, oct: 173, bin: 1111011
    |, dec: 124, hex: 7C, oct: 174, bin: 1111100
    }, dec: 125, hex: 7D, oct: 175, bin: 1111101
    ~, dec: 126, hex: 7E, oct: 176, bin: 1111110 ASPAS_DUPLA

 * 
 */
